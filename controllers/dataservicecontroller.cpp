#include "dataservicecontroller.h"
#include <TSqlQuery>
#include <TAbstractModel>
#include "dscriteria.h"
#include "dscriteriaconverter.h"

void DataServiceController::getHttpRequestPara()
{
    switch (httpRequest().method()) {
        case Tf::Get:
            renderErrorResponse(Tf::Forbidden);
            break;

        case Tf::Post:
            key         = httpRequest().formItemValue("key");
            relationKey = httpRequest().formItemValue("relationKey");
            pageIndex   = httpRequest().formItemValue("pageIndex", "0").toInt();
            pageSize    = httpRequest().formItemValue("pageSize", "100").toInt();

            sortFields  = httpRequest().formItemValue("sortFields");
            sortField   = httpRequest().formItemValue("sortField");
            sortOrder   = httpRequest().formItemValue("sortOrder");
            searchMode  = httpRequest().queryItemValue("searchMode");
            relation    = httpRequest().queryItemValue("relation");

            break;

        default:
            renderErrorResponse(Tf::Forbidden);
            break;
    }
}

void DataServiceController::getSqlQueryPara(const QString &sqlTarget)
{
    tSystemTrace("getting sqlquery para");
    TSqlQuery query;
    query.load(sqlTarget);

    QString querystmt = query.lastQuery();
    query.prepare(querystmt + " limit 0");

    query.exec();

    QSqlRecord fields = query.record();

    for (int i = 0; i < fields.count(); ++i) {
        QString fieldName = fields.fieldName(i);
        QVariant::Type fieldType = fields.field(i).type();
        tTrace("get fieldName: %s", fieldName.toLatin1().data());

        //start with hash_ or Hash_, will use hmac() function to the fieldValue
        //such as tab_id as hash_tab_id, tab_id as "hash_tab_id", tab_id as "HASH_tab_id"

        if (fieldName.startsWith("hash_") || fieldName.startsWith("HASH_")) {
            hashFieldList << fieldName.mid(5);
            fieldNameMap.insert(fieldName.mid(5), TAbstractModel::fieldNameToVariableName(fieldName.mid(5)));
        } else {
            fieldNameMap.insert(fieldName, TAbstractModel::fieldNameToVariableName(fieldName));
        }

        fieldTypeMap.insert(fieldName, fieldType);
    }

    sortFields.isEmpty() ? getSingleSort(sortField, sortOrder) : getMultiSort(sortFields);

    getBoundValue(relationKey);
    getWhereClause(key);

}

void DataServiceController::getSingleSort(const QString &sortField, const QString &sortOrder)
{
    tSystemTrace("getting singsort");
    QString order = sortOrder.toLower();

    if (!fieldNameMap.values().contains(sortField)) {
        tError("singleSort field not found:%s", sortField.toLatin1().data());
        return ;
    }

    if (order.isEmpty()) {
        order = "asc";
    }

    if (order != "asc" &&
            sortOrder != "desc" &&
            sortOrder != "ascend" &&
            sortOrder != "descend") {
        tError("singleSort order Error!");
        order = "asc";
    }

    sortColumnsOrders += " order by \"" + fieldNameMap.key(sortField) + "\" " + order;

    if (httpRequest().cookie("lang") == "zh") {
        sortColumnsOrders + " collate \"zh_CN.utf8\"";
    }

    tTrace("setSingleSort:%s", sortColumnsOrders.toLatin1().data());
}

void DataServiceController::getMultiSort(const QString &sortFields)
{
    tSystemTrace("getting mutisort");

    if (sortFields.isEmpty()) {
        tTrace("sortFields is empty!");
        return;
    }

    QJsonParseError jsonError;
    QJsonDocument document = QJsonDocument::fromJson(sortFields.toLatin1(), &jsonError);

    if (jsonError.error == QJsonParseError::NoError) {
        if (document.isArray()) {
            QJsonArray array = document.array();

            for (QJsonValue jsonValue : array) {
                QJsonObject obj = jsonValue.toObject();
                QString field = obj.value("field").toString();
                QString dir = obj.value("dir").toString().toLower();

                if (dir.isEmpty()) { dir = "asc";}

                if (!fieldNameMap.values().contains(field)) {
                    tError("multiSort field not found:%s", field.toLatin1().data());
                    continue;
                }

                if (dir != "asc" &&
                        dir != "desc" &&
                        dir != "ascend" &&
                        dir != "descend") {
                    tError("multiSort order Error!");
                    dir = "asc";
                }

                sortColumnsOrders += "\"" + fieldNameMap.key(field) + "\" " + dir + ',';
            }

            if (array.size() > 0) {
                sortColumnsOrders.prepend(" order by ");
                sortColumnsOrders.chop(1);
            }
        } else {
            tError(QString("sortFields should be an array!").toLatin1().data());
        }
    } else {
        tError(QString("sortFields parse error:").append(jsonError.errorString()).toLatin1().data());
    }

    if (httpRequest().cookie("lang") == "zh") {
        sortColumnsOrders + " collate \"zh_CN.utf8\"";
    }

    tTrace(QString(sortColumnsOrders).prepend("setMultiSort:").toLatin1().data());
}

void DataServiceController::getWhereClause(const QString &key)
{
    tSystemTrace("getting where clause");

    if (key.isEmpty()) {
        tTrace("key is Empty:");
        return;
    }

    QJsonParseError jsonError;
    QJsonDocument document = QJsonDocument::fromJson(key.toLatin1(), &jsonError);

    if (jsonError.error == QJsonParseError::NoError) {
        if (document.isArray()) {
            QJsonArray array = document.array();
            DSCriteria cri;

            for (QJsonValue jsonValue : array) {
                QJsonObject obj = jsonValue.toObject();
                QString field = obj.value("field").toString();
                QString vals = obj.value("vals").toString();
                int op = obj.value("op").isDouble() ? obj.value("op").toInt() : obj.value("op").toString().toInt();
                tDebug("field:%s", field.toLatin1().data());
                tDebug("vals:%s", vals.toLatin1().data());
                tDebug("opStr:%s", obj.value("op").toString().toLatin1().data());
                tDebug("op:%d", op);


                if (fieldNameMap.values().contains(field)) {
                    QString dbFieldName = fieldNameMap.key(field);
                    QVariant::Type fieldType = fieldTypeMap.value(dbFieldName);
                    bool hmacFlag = false;

                    if (hashFieldList.contains(dbFieldName)) {
                        hmacFlag = true;
                    }

                    switch (op) {
                        case TSql::IsNull:
                        case TSql::IsNotNull:
                        case TSql::IsEmpty:
                        case TSql::IsNotEmpty: {
                                tDebug("op in isNull/IsNotNull/IsEmpty/IsNotEmpty");
                                cri.add(dbFieldName, fieldType, (TSql::ComparisonOperator)op);

                                break;
                            }

                        case TSql::In: {
                                tDebug("op in In");

                                if (vals.isEmpty()) {
                                    cri.add(dbFieldName, fieldType, TSql::IsNull);
                                    cri.add(dbFieldName, fieldType, TSql::IsNotNull);
                                    break;
                                }
                            }

                        case TSql::NotIn: {
                                tDebug("op in NotIn");

                                if (vals.isEmpty()) { break; }

                                QStringList vallist;
                                vallist = vals.split(QRegularExpression("\\W+"), QString::SkipEmptyParts);

                                QList<QVariant> vlist;

                                for (QString &s : vallist) {
                                    hmacFlag ? vlist << hmacVal(s) : vlist << s;
                                }

                                cri.add(dbFieldName, fieldType, (TSql::ComparisonOperator)op, vlist);

                                break;
                            }

                        case TSql::Like:
                        case TSql::NotLike: {
                                tDebug("op in Like/NotLike");

                                if (vals.isEmpty()) {
                                    cri.add(dbFieldName, fieldType, TSql::IsNull);
                                    cri.add(dbFieldName, fieldType, TSql::IsNotNull);
                                    break;
                                }

                                cri.add(dbFieldName, fieldType, (TSql::ComparisonOperator)op, vals);
                                break;
                            }

                        case TSql::LikeEscape:
                        case TSql::NotLikeEscape:
                        case TSql::ILikeEscape:
                        case TSql::NotILikeEscape: {
                                tDebug("op in LikeEscape/NotLikeEscape/ILikeEscape/NotIlikeEscape");
                                QStringList vallist;
                                vallist = vals.split(QRegularExpression("\\W+"), QString::SkipEmptyParts);

                                if (vallist.length() != 2) {
                                    renderText(UI("Need Like Parttern and Escape Character!"));
                                }

                                cri.add(dbFieldName, fieldType, (TSql::ComparisonOperator)op, vallist.first(), vallist.last());
                                break;
                            }

                        case TSql::Between:
                        case TSql::NotBetween: {
                                tDebug("op in Between/NotBetween");
                                QStringList vallist;
                                vallist = vals.split(QRegularExpression("\\W+"), QString::SkipEmptyParts);

                                if (vallist.length() != 2) {
                                    renderText(UI("Need Only&Must Two Value!"));
                                }

                                hmacFlag
                                ? cri.add(dbFieldName, fieldType, (TSql::ComparisonOperator)op,  hmacVal(vallist.first()), hmacVal(vallist.last()))
                                : cri.add(dbFieldName, fieldType, (TSql::ComparisonOperator)op, vallist.first(), vallist.last());

                                break;
                            }

                        default:
                            tDebug("op in default");
                            hmacFlag
                            ? cri.add(dbFieldName, fieldType, (TSql::ComparisonOperator)op, hmacVal(vals))
                            : cri.add(dbFieldName, fieldType, (TSql::ComparisonOperator)op, vals);

                    }
                }
            }

            DSCriteriaConverter conv(cri, Tf::currentSqlDatabase(0));
            where = conv.toString();

            if (!where.isEmpty()) { where.prepend("where ");}
        } else {
            tError("where key should be an array!");
        }
    } else {
        tError("where key parse error:%s", jsonError.errorString().toLatin1().data());
    }

    tTrace(QString(where).prepend("where:").toLatin1().data());

}

void DataServiceController::getBoundValue(const QString &relationKey)
{
    tSystemTrace("getting bound value");

    if (relationKey.isEmpty()) {
        tTrace("relationKey is Empty");
        return;
    }

    QJsonParseError jsonError;
    QJsonDocument document = QJsonDocument::fromJson(relationKey.toLatin1(), &jsonError);

    if (jsonError.error == QJsonParseError::NoError) {
        if (document.isObject()) {
            QJsonObject::Iterator it;

            for (it = document.object().begin(); it != document.object().end(); it++) {
                if (hashFieldList.contains(fieldNameMap.key(it.key()))) {
                    boundValues.insert(it.key(), hmacVal(it.value().toString()));
                    tTrace("getBoundValue hmacValue->value");
                    tTrace("hashField:%s", it.key().toLatin1().data());
                } else {
                    boundValues.insert(it.key(), it.value().toString());
                    tTrace("getBoundValue value");
                }

            }
        } else {
            tError("relation key should be an object");
        }
    } else {
        tError("relation key parse error:%s", jsonError.errorString().toLatin1().data());
    }
}

void DataServiceController::Search(const QString &searchTarget)
{
    getHttpRequestPara();
    getSqlQueryPara(QString(searchTarget) + ".sql");

    if (searchMode.toLower() == "all" || searchMode.toLower() == "page") {
        Render(QString(searchTarget) + ".sql");
    } else {
        renderText("Need para: searchMode!");
    }

}

void DataServiceController::Render(const QString &sqlTarget)
{
    TSqlQuery query;
    query.load(sqlTarget);

    int totalcount = 0, offset = 0;
    offset = pageIndex * pageSize;
    TSqlQuery queryforcount;

    queryforcount.prepare(QString("select Count (1) from (%1 %2) t").arg(query.lastQuery()).arg(where));
    QVariantMap::iterator it;

    for (it = boundValues.begin(); it != boundValues.end(); ++it) {
        queryforcount.bind(QString(it.key()).prepend(':'), it.value());
    }

    queryforcount.exec();

    while (queryforcount.next()) {
        QSqlRecord record = queryforcount.record();
        totalcount = record.value(0).toInt();
    }


    if (searchMode.toLower() == "all") {
        // if where,orderby not change, only changed page, database only compliance sql statement once.

        QString querystmt = "%1 %2 %3 ";
        query.prepare(querystmt.arg(query.lastQuery()).arg(where).arg(sortColumnsOrders));

    } else if (searchMode.toLower() == "page") {
        // if where,orderby not change, only changed page, database only compliance sql statement once.

        QString querystmt = "%1 %2 %3 offset :offset limit :limit ";
        query.prepare(querystmt.arg(query.lastQuery()).arg(where).arg(sortColumnsOrders));
        query.bind(":offset", offset);
        query.bind(":limit", pageSize);
    }

    for (it = boundValues.begin(); it != boundValues.end(); ++it) {
        query.bind(QString(it.key()).prepend(':'), it.value());
    }

    query.exec();

    QString result;

    while (query.next()) {
        QSqlRecord record = query.record();
        QString recordResult;

        for (int i = 0; i < record.count(); ++i) {
            QString fieldName = record.fieldName(i);
            QString fieldValue = record.value(i).toString();

            if (fieldName.startsWith("hash_") || fieldName.startsWith("HASH_")) {
                fieldName = fieldName.mid(5);
                fieldValue =  hmac(fieldValue);
            }

            recordResult += '"';
            recordResult += fieldNameMap.value(fieldName);

            if (fieldTypeMap.value(fieldName) == QVariant::Bool ||
                    fieldTypeMap.value(fieldName) == QVariant::Int ||
                    fieldTypeMap.value(fieldName) == QVariant::UInt ||
                    fieldTypeMap.value(fieldName) == QVariant::LongLong ||
                    fieldTypeMap.value(fieldName) == QVariant::ULongLong ||
                    fieldTypeMap.value(fieldName) == QVariant::Double) {
                recordResult += "\":";
                recordResult += fieldValue;
                recordResult += ",";
            } else {
                recordResult += "\":\"";
                recordResult += fieldValue;
                recordResult += "\",";
            }
        }

        recordResult.chop(1);//if have record, must have field
        result += recordResult.prepend('{').append("},");
    }

    if (!result.isEmpty()) {
        result.chop(1);
    }

    if (searchMode.toLower() == "all") {
        result = result.prepend('[').append(']');
        tTrace() << "ajax page hash query result:" << result;
    } else if (searchMode.toLower() == "page") {
        result = result.prepend("\"data\":[").append(']');
        QString  sumary = "\"total\":" + QString::number(totalcount) + ",\"pageIndex\":" + QString::number(offset) + ",\"pageSize\":" + QString::number(pageSize);
        result = result.prepend(",").prepend(sumary);
        result = result.prepend('{').append('}');
        tTrace("ajax page hash query result:%s", result.toLatin1().data());
    }

    renderText(result);
}

// Don't remove below this line
T_DEFINE_CONTROLLER(DataServiceController)
