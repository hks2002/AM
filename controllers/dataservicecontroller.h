#ifndef DATASERVICECONTROLLER_H
#define DATASERVICECONTROLLER_H
#include <TActionController>
#include <TAbstractModel>
#include <TCriteriaConverter>
#include <TCriteria>
#include <TModelUtil>
#include "applicationhelper.h"
#include "applicationcontroller.h"


class T_CONTROLLER_EXPORT DataServiceController : public  ApplicationController
{
    Q_OBJECT
public:
    DataServiceController() :  ApplicationController() { }
    /////////////////////////////////////////////////////////////////////////
    //these bellow methods is used as friend method of ApplicationController
    template <class M, class V>
    static void createRecord(ApplicationController *ctl)
    {
        if (ctl->httpRequest().method() != Tf::Post) {
            ctl->XrenderErrorResponse(Tf::Forbidden);
            return;
        }

        auto varMaps = ctl->httpRequest().formItems();
        QString err = mapValidate<V>(varMaps);

        if (!err.isEmpty()) {
            ctl->XrenderJson(jsonObj(false, err));
            return;
        }

        M model = M::create(varMaps);

        model.isNull()
        ? ctl->XrenderJson(jsonObj(false, UI("Create Failed.")))
        : ctl->XrenderJson(jsonObj(true, UI("Created Successfully.")));
    }

    template <class M, class O>
    static void deleteRecord(ApplicationController *ctl, const QStringList &pklist)
    {
        if (ctl->httpRequest().method() != Tf::Post) {
            ctl->XrenderErrorResponse(Tf::NotFound);
            return;
        }

        QString key  = ctl->httpRequest().formItemValue("key");
        tDebug() << "key:" << key;
        QJsonParseError jsonError;
        QJsonDocument jsonDoc = QJsonDocument::fromJson(key.toLatin1(), &jsonError);

        if (jsonError.error != QJsonParseError::NoError) {
            ctl->XrenderJson(jsonObj(false, UI("Key Error.")));
            return;
        }

        if (jsonDoc.isArray()) {
            tDebug() << "key is array";
            QJsonArray array = jsonDoc.array();

            for (QJsonValue jsonValue : array) {
                tDebug() << "object in array";
                QJsonObject obj = jsonValue.toObject();
                QVariantList varlist;

                for (auto &x : pklist) {
                    varlist << hmacVal(obj.value(x).toString());
                }

                TSqlORMapper<O> mapper;
                auto model = M(mapper.findByPrimaryKey(varlist));

                if (model.isNull()) {
                    ctl->XrenderJson(jsonObj(false, UI("Original data may have been updated/removed by another user.")));
                    ctl->XrollbackTransaction();
                    return;
                }

                if (model.remove()) {} else {
                    ctl->XrenderJson(jsonObj(false, UI("Delete Failed.")));
                    ctl->XrollbackTransaction();
                    return;
                }
            }

            ctl->XrenderJson(jsonObj(true, UI("Deleted Successfully.")));
        } else if (jsonDoc.isObject()) {
            tDebug() << "key is object";
            QJsonObject obj = jsonDoc.object();
            QVariantList varlist;

            for (auto &x : pklist) {
                varlist << hmacVal(obj.value(x).toString());
            }

            TSqlORMapper<O> mapper;
            auto model = M(mapper.findByPrimaryKey(varlist));

            if (model.isNull()) {
                ctl->XrenderJson(jsonObj(false, UI("Original data may have been updated/removed by another user.")));
                return;
            }

            model.remove()
            ? ctl->XrenderJson(jsonObj(true, UI("Deleted Successfully.")))
            : ctl->XrenderJson(jsonObj(false, UI("Delete Failed.")));
        }
    }

    template <class M>
    static void assignRecord(ApplicationController *ctl, const QStringList &pklist)
    {
        if (ctl->httpRequest().method() != Tf::Post) {
            ctl->XrenderErrorResponse(Tf::NotFound);
            return;
        }

        QString key  = ctl->httpRequest().formItemValue("key");
        tDebug() << "key:" << key;
        QJsonParseError jsonError;
        QJsonDocument jsonDoc = QJsonDocument::fromJson(key.toLatin1(), &jsonError);

        if (jsonError.error != QJsonParseError::NoError) {
            ctl->XrenderJson(jsonObj(false, UI("Key Error.")));
            return;
        }

        if (jsonDoc.isArray()) {
            tDebug() << "key is array";
            QJsonArray array = jsonDoc.array();

            for (QJsonValue jsonValue : array) {
                tDebug() << "object in array";
                QJsonObject obj = jsonValue.toObject();
                QVariantMap varMaps;

                for (auto &x : pklist) {
                    varMaps.insert(x, hmacVal(obj.value(x).toString()));
                }

                auto model = M::create(varMaps);

                if (model.isNull()) {
                    ctl->XrenderJson(jsonObj(false, UI("Assign Failed.")));
                    ctl->XrollbackTransaction();
                    return;
                }
            }

            ctl->XrenderJson(jsonObj(true, UI("Assigned Successfully.")));
        } else if (jsonDoc.isObject()) {
            tDebug() << "key is object";
            QJsonObject obj = jsonDoc.object();
            QVariantMap varMaps;

            for (auto &x : pklist) {
                varMaps.insert(x, hmacVal(obj.value(x).toString()));
            }

            auto model = M::create(varMaps);

            model.isNull()
            ? ctl->XrenderJson(jsonObj(false, UI("Assign Failed.")))
            : ctl->XrenderJson(jsonObj(true, UI("Assigned Successfully.")));

        }
    }

    template <class M, class O>
    static void unassignRecord(ApplicationController *ctl, const QStringList &pklist)
    {

        if (ctl->httpRequest().method() != Tf::Post) {
            ctl->XrenderErrorResponse(Tf::NotFound);
            return;
        }

        QString key  = ctl->httpRequest().formItemValue("key");
        tDebug() << "key:" << key;
        QJsonParseError jsonError;
        QJsonDocument jsonDoc = QJsonDocument::fromJson(key.toLatin1(), &jsonError);

        if (jsonError.error != QJsonParseError::NoError) {
            ctl->XrenderJson(jsonObj(false, UI("Key Error.")));
            return;
        }

        if (jsonDoc.isArray()) {
            tDebug() << "key is array";
            QJsonArray array = jsonDoc.array();

            for (QJsonValue jsonValue : array) {
                tDebug() << "object in array";
                QJsonObject obj = jsonValue.toObject();
                QVariantList varlist;

                for (auto &x : pklist) {
                    varlist << hmacVal(obj.value(x).toString());
                }

                TSqlORMapper<O> mapper;
                auto model = M(mapper.findByPrimaryKey(varlist));

                if (model.isNull()) {
                    ctl->XrenderJson(jsonObj(false, UI("Original data may have been updated/removed by another user.")));
                    ctl->XrollbackTransaction();
                    return;
                }

                if (model.remove()) {} else {
                    ctl->XrenderJson(jsonObj(false, UI("Unassign Failed.")));
                    ctl->XrollbackTransaction();
                    return;
                }
            }

            ctl->XrenderJson(jsonObj(true, UI("Unassigned Successfully.")));
        } else if (jsonDoc.isObject()) {
            tDebug() << "key is object";
            QJsonObject obj = jsonDoc.object();
            QVariantList varlist;

            for (auto &x : pklist) {
                varlist << hmacVal(obj.value(x).toString());
            }

            TSqlORMapper<O> mapper;
            auto model = M(mapper.findByPrimaryKey(varlist));

            if (model.isNull()) {
                ctl->XrenderJson(jsonObj(false, UI("Original data may have been updated/removed by another user.")));
                return;
            }

            model.remove()
            ? ctl->XrenderJson(jsonObj(true, UI("Unassigned Successfully.")))
            : ctl->XrenderJson(jsonObj(false, UI("Unassign Failed.")));
        }
    }

    template<class M, class O, class V>
    static void updateRecord(ApplicationController *ctl, const QStringList &pklist, const QStringList &fieldlist = QStringList())
    {
        if (ctl->httpRequest().method() != Tf::Post) {
            ctl->XrenderErrorResponse(Tf::NotFound);
            return;
        }

        //without key, treat it as form edit request
        if (!ctl->httpRequest().hasFormItem("key")) {
            auto varMaps = ctl->httpRequest().formItems();
            QVariantList varlist;

            for (auto &x : pklist) {
                varlist << hmacVal(varMaps.value(x).toString());
            }

            TSqlORMapper<O> mapper;
            auto model = M(mapper.findByPrimaryKey(varlist));

            if (model.isNull()) {
                ctl->XrenderJson(jsonObj(false, UI("Original data may have been updated/removed by another user.")));
                return;
            }

            V validator;

            if (!validator.validate(varMaps)) {
                QStringList errs = validator.errorMessages();
                QString err;

                for (auto &s : errs) {
                    err += UI(s).append("\n");
                }

                ctl->XrenderJson(jsonObj(false, err));
                return;
            }

            model.setProperties(varMaps);

            model.save()
            ? ctl->XrenderJson(jsonObj(true, UI("Updated Successfully.")))
            : ctl->XrenderJson(jsonObj(false, UI("Update Failed.")));

            return;
        }

        //with key, treat it as not form edit request
        QString key  = ctl->httpRequest().formItemValue("key");
        tDebug() << "key:" << key;
        QJsonParseError jsonError;
        QJsonDocument jsonDoc = QJsonDocument::fromJson(key.toLatin1(), &jsonError);

        if (jsonError.error != QJsonParseError::NoError) {
            tDebug() << "key error:" << jsonError.errorString().toLatin1().data();
            ctl->XrenderJson(jsonObj(false, UI("Keys Error.")));
            return;
        }

        if (jsonDoc.isArray()) {
            QJsonArray array = jsonDoc.array();

            for (QJsonValue jsonValue : array) {
                QJsonObject obj = jsonValue.toObject();
                QVariantList varlist;

                for (auto &x : pklist) {
                    varlist << hmacVal(obj.value(x).toString());
                }

                TSqlORMapper<O> mapper;
                auto model = M(mapper.findByPrimaryKey(varlist));

                if (model.isNull()) {
                    ctl->XrenderJson(jsonObj(false, UI("Original data may have been updated/removed by another user.")));
                    ctl->XrollbackTransaction();
                    return;
                }

                QVariantMap varMap;

                for (auto &x : fieldlist) {
                    varMap.insert(x, obj.value(x));
                }

                model.setProperties(varMap);

                if (model.save()) {}
                else {
                    ctl->XrenderJson(jsonObj(false, UI("Update Failed.")));
                    ctl->XrollbackTransaction();
                    return;
                }
            }

            ctl->XrenderJson(jsonObj(true, UI("Updated Successfully.")));

        } else if (jsonDoc.isObject()) {
            QJsonObject obj = jsonDoc.object();
            QVariantList varlist;

            for (auto &x : pklist) {
                varlist << hmacVal(obj.value(x).toString());
            }

            TSqlORMapper<O> mapper;
            auto model = M(mapper.findByPrimaryKey(varlist));

            if (model.isNull()) {
                ctl->XrenderJson(jsonObj(false, UI("Original data may have been updated/removed by another user.")));
                return;
            }

            QVariantMap varMap;

            for (auto &x : fieldlist) {
                varMap.insert(x, obj.value(x));
            }

            model.setProperties(varMap);

            model.save()
            ? ctl->XrenderJson(jsonObj(true, UI("Updated Successfully.")))
            : ctl->XrenderJson(jsonObj(false, UI("Update Failed.")));
        }
    }

    template<class O>
    QString JsonData(const QString &fields,
                     const QString &key,
                     const QString searchMode,
                     int pageIndex = 0,
                     int pageSize = 100,
                     const QString &sortField = "",
                     const QString sortOrder = "",
                     const QString sortFields = "",
                     QString hashMode = ""
                    )
    {
        fields = fields;
        sortFields = sortFields;
        sortField = sortField;
        sortOrder = sortOrder;
        key = key;
        pageIndex = pageIndex;
        pageSize = pageSize;
        searchMode = searchMode;
        hashMode = hashMode;

        getFieldNameMap<O>();
        QString selectFields;
        QString fieldsSorts;
        selectFields = fields.isEmpty() ? tableAllAsFields() : selectAsFields(fields.split(QRegularExpression("\\W+"), QString::SkipEmptyParts));
        fieldsSorts  = sortFields.isEmpty() ? singleSort(sortField, sortOrder) : multiSort(sortFields);

        if (hashMode.toLower() == "nohash") {
            if (searchMode.toLower() == "all") {
                return GetAllNoHash(tableName<O>(), selectFields, fieldsSorts, where<O>(key));
            } else if (searchMode.toLower() == "page") {
                return GetPageNoHash(tableName<O>(), selectFields, fieldsSorts, where<O>(key), pageIndex, pageSize);
            } else if (searchMode.toLower() == "one") {
                return GetOneNoHash(tableName<O>(), selectFields, where<O>(key));
            } else {
                return "";
            }
        } else {
            if (searchMode.toLower() == "all") {
                return GetAll(tableName<O>(), selectFields, fieldsSorts, where<O>(key), pkFieldList<O>(), fkFieldList<O>());
            } else if (searchMode.toLower() == "page") {
                return GetPage(tableName<O>(), selectFields, fieldsSorts, where<O>(key), pageIndex, pageSize, pkFieldList<O>(), fkFieldList<O>());
            } else if (searchMode.toLower() == "one") {
                return GetOne(tableName<O>(), selectFields,  where<O>(key), pkFieldList<O>(), fkFieldList<O>());
            } else {
                return "";
            }
        }

    }

public slots:
    void Search(const QString &entity);
    void Search(const QString &entity, const QString &relationEntity);
    void Search(const QString &entity, const QString &relationEntity, const QString &relation);

private:
    QString fields;
    QString sortFields;
    QString sortField;
    QString sortOrder;
    QString key;
    int pageIndex = 0;
    int pageSize = 100;
    QString searchMode;
    QString hashMode;

    QMap<QString, QString> fieldNameMap;

    bool isRelationSearch = false;
    bool isRelationIn = true;
    QString relationkey;

    void getHttpRequestPara();
    QString vTof(const QString &variableName);
    QString selectAsFields(const QStringList &fieldList);
    QString tableAllAsFields();
    QString singleSort(const QString &sortField, const QString &sortOrder = "asc");
    QString multiSort(const QString &sortFields);

    template<class O>
    void getFieldNameMap()
    {
        O obj;
        fieldNameMap.empty();
        const QMetaObject *metaObj = obj.metaObject();

        for (int i = metaObj->propertyOffset(); i < metaObj->propertyCount(); ++i) {
            const char *propName = metaObj->property(i).name();
            QString varName = TAbstractModel::fieldNameToVariableName(propName);
            tTrace() << varName.toLatin1().data() << "->" << propName;
            fieldNameMap.insert(varName, propName);
        }
    }

    template<class O>
    QString tableName()
    {
        O obj;
        tTrace(obj.tableName().prepend("tableName:").toLatin1().data());
        return obj.tableName();
    }

    template<class O>
    QStringList pkFieldList()
    {
        O obj;
        QStringList list;

        //default metaObject propertyoffset is 1, meanwhill sqlobj first index is 0
        for (int index : obj.primaryKeyIndexList()) {
            tTrace() << "PK index:" << index;
            tTrace() << "PK field name:" << obj.metaObject()->property(obj.metaObject()->propertyOffset() + index).name();
            list << TAbstractModel::fieldNameToVariableName(obj.metaObject()->property(obj.metaObject()->propertyOffset() + index).name());
        }

        return list;
    }

    template<class O>
    QStringList fkFieldList()
    {
        O obj;
        QStringList list;

        //default metaObject propertyoffset is 1, meanwhill sqlobj first index is 0
        for (int index : obj.foreignKeyIndexList()) {
            tTrace() << "FK index:" << index;
            tTrace() << "FK field name:" << obj.metaObject()->property(obj.metaObject()->propertyOffset() + index).name();
            list << TAbstractModel::fieldNameToVariableName(obj.metaObject()->property(obj.metaObject()->propertyOffset() + index).name());
        }

        return list;
    }

    template<class O>
    QString where(const QString &key)
    {
        QString where;

        if (key.isEmpty()) {
            return where;
        }

        QJsonParseError jsonError;
        QJsonDocument document = QJsonDocument::fromJson(key.toLatin1(), &jsonError);

        if (jsonError.error == QJsonParseError::NoError) {
            if (document.isArray()) {
                QJsonArray array = document.array();
                TCriteria cri;
                QStringList pkfieldList = pkFieldList<O>();

                for (QJsonValue jsonValue : array) {
                    QJsonObject obj = jsonValue.toObject();
                    QString field = obj.value("field").toString();
                    QString vals = obj.value("vals").toString();
                    int op = obj.value("op").isDouble() ? obj.value("op").toInt() : obj.value("op").toString().toInt();
                    tDebug() << "field:" << field;
                    tDebug() << "vals:" << vals;
                    tDebug() << "opStr:" << obj.value("op").toString();
                    tDebug() << "op:" << op;

                    QString wherefield = vTof(field);

                    if (!wherefield.isEmpty()) {
                        O sqlobj;
                        int propIndex = sqlobj.metaObject()->indexOfProperty(wherefield.toLatin1().data()) -
                                        sqlobj.metaObject()->propertyOffset();

                        switch (op) {
                            case TSql::IsNull:
                            case TSql::IsNotNull:
                            case TSql::IsEmpty:
                            case TSql::IsNotEmpty: {
                                    tDebug("op in isNull/IsNotNull/IsEmpty/IsNotEmpty");
                                    cri.add(propIndex, (TSql::ComparisonOperator)op);
                                    break;
                                }

                            case TSql::In: {
                                    tDebug("op in In");

                                    if (vals.isEmpty()) {
                                        cri.add(propIndex, TSql::IsNull);
                                        cri.add(propIndex, TSql::IsNotNull);
                                        break;
                                    }
                                }

                            case TSql::NotIn: {
                                    tDebug("op in NotIn");

                                    if (vals.isEmpty()) { break; }

                                    QStringList vallist;
                                    vallist = vals.split(QRegularExpression("\\W+"), QString::SkipEmptyParts);

                                    if (hashMode.toLower() == "nohash") {
                                        cri.add(propIndex, (TSql::ComparisonOperator)op, vallist);
                                    } else {
                                        QList<QVariant> vlist;

                                        for (QString &s : vallist) {
                                            pkfieldList.contains(field) ? vlist << hmacVal(s) : vlist << s;
                                        }

                                        cri.add(propIndex, (TSql::ComparisonOperator)op, vlist);
                                    }

                                    break;
                                }

                            case TSql::Like:
                            case TSql::NotLike: {
                                    tDebug("op in Like/NotLike");

                                    if (vals.isEmpty()) {
                                        cri.add(propIndex, TSql::IsNull);
                                        cri.add(propIndex, TSql::IsNotNull);
                                        break;
                                    }

                                    cri.add(propIndex, (TSql::ComparisonOperator)op, vals);
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

                                    cri.add(propIndex, (TSql::ComparisonOperator)op, vallist.first(), vallist.last());
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

                                    if (hashMode.toLower() == "nohash") {
                                        cri.add(propIndex, (TSql::ComparisonOperator)op, vallist.first(), vallist.last());
                                    } else {
                                        pkfieldList.contains(field)
                                        ? cri.add(propIndex, (TSql::ComparisonOperator)op,  hmacVal(vallist.first()), hmacVal(vallist.last()))
                                        : cri.add(propIndex, (TSql::ComparisonOperator)op, vallist.first(), vallist.last());
                                    }

                                    break;
                                }

                            default:
                                tDebug("op in default");

                                if (hashMode.toLower() == "nohash") {
                                    cri.add(propIndex, (TSql::ComparisonOperator)op, vals);
                                } else {
                                    pkfieldList.contains(field)
                                    ? cri.add(propIndex, (TSql::ComparisonOperator)op, hmacVal(vals))
                                    : cri.add(propIndex, (TSql::ComparisonOperator)op, vals);
                                }
                        }
                    }
                }

                TCriteriaConverter<O> conv(cri, Tf::currentSqlDatabase(O().databaseId()));
                where = conv.toString();

                if (!where.isEmpty()) { where.prepend("where ");}
            } else {
                tDebug("where key should be an array!");
            }
        } else {
            tDebug(QString("where key parse error:").append(jsonError.errorString()).toLatin1().data());
        }

        tDebug(QString(where).prepend("where:").toLatin1().data());
        return where;
    }

    template<class T, class R>
    void relationKey()
    {
        QString  origkey = httpRequest().formItemValue("key");
        tDebug("oriKey:%s", origkey.toLatin1().data());
        QJsonParseError jsonError;
        QJsonDocument document = QJsonDocument::fromJson(origkey.toLatin1(), &jsonError);

        if (jsonError.error == QJsonParseError::NoError) {
            if (document.isObject()) {
                QJsonObject jsonobj = document.object();
                QStringList jsonkeys = jsonobj.keys();
                tDebug() << "json keys:" << jsonkeys;

                TCriteria cri;
                R relationobj;
                const QMetaObject *relationmetaObj = relationobj.metaObject();

                for (int i = relationmetaObj->propertyOffset(); i < relationmetaObj->propertyCount(); ++i) {
                    const char *propName = relationmetaObj->property(i).name();
                    tDebug() << "relation propName:" << propName;
                    int propIndex = relationmetaObj->indexOfProperty(propName) - relationmetaObj->propertyOffset();
                    tDebug() << "relation propIndex:" << propIndex;
                    QString varName = TAbstractModel::fieldNameToVariableName(propName);

                    if (jsonkeys.contains(varName)) {
                        tDebug() << "relation cri add json key:" << varName;
                        cri.add(propIndex, hmacVal(jsonobj.value(varName).toString()));
                    }
                }

                TSqlORMapper<R> mapper;
                QVariantMap vals;

                T targetobj;
                const QMetaObject *targetmetaObj = targetobj.metaObject();

                if (mapper.find(cri) > 0) {
                    for (TSqlORMapperIterator<R> r(mapper); r.hasNext();) {
                        R relationobj = r.next();

                        for (int index : targetobj.primaryKeyIndexList()) {
                            const char *propName = targetmetaObj->property(targetmetaObj->propertyOffset() + index).name();
                            QString varName = TAbstractModel::fieldNameToVariableName(propName);

                            tDebug() << "target key add:" << varName;
                            QString tempStr = vals.value(varName).toString() + " " + hmac(relationobj.property(propName).toString());
                            vals.insert(varName, tempStr);
                        }

                    }

                    for (QMapIterator<QString, QVariant> it(vals); it.hasNext();) {
                        it.next();
                        QStringList list = it.value().toString().split(QRegularExpression("\\W+"), QString::SkipEmptyParts);
                        QString str = list.toSet().toList().join(" ");

                        isRelationIn == true
                        ? relationkey += "{\"field\":\"" + it.key() + "\",\"op\":\"" + QString::number(TSql::In) + "\",\"vals\":\"" + str + "\"},"
                                         : relationkey += "{\"field\":\"" + it.key() + "\",\"op\":\"" + QString::number(TSql::NotIn) + "\",\"vals\":\"" + str + "\"},";
                    }

                } else {
                    for (int index : targetobj.primaryKeyIndexList()) {
                        const char *propName = targetmetaObj->property(targetmetaObj->propertyOffset() + index).name();
                        QString varName = TAbstractModel::fieldNameToVariableName(propName);

                        isRelationIn == true
                        ? relationkey += "{\"field\":\"" + varName + "\",\"op\":\"" + QString::number(TSql::In) + "\",\"vals\":\"\"},"
                                         : relationkey += "{\"field\":\"" + varName + "\",\"op\":\"" + QString::number(TSql::NotIn) + "\",\"vals\":\"\"},";
                    }
                }

                relationkey.chop(1);

            } else {
                tDebug("key should be an object!");
            }
        } else {
            tDebug(QString("key parse error:").append(jsonError.errorString()).toLatin1().data());
        }

        relationkey.prepend('[').append(']');
        tDebug() << "relationkey:" << relationkey;
    }

    template<class O>
    void Render()
    {
        getHttpRequestPara();

        if (isRelationSearch) { //update key
            key = relationkey;
        }

        getFieldNameMap<O>();
        QString selectFields;
        QString fieldsSorts;
        selectFields = fields.isEmpty() ? tableAllAsFields() : selectAsFields(fields.split(QRegularExpression("\\W+"), QString::SkipEmptyParts));
        fieldsSorts  = sortFields.isEmpty() ? singleSort(sortField, sortOrder) : multiSort(sortFields);

        if (hashMode.toLower() == "nohash") {
            if (searchMode.toLower() == "all") {
                renderText(GetAllNoHash(tableName<O>(), selectFields, fieldsSorts, where<O>(key)));
            } else if (searchMode.toLower() == "page") {
                renderText(GetPageNoHash(tableName<O>(), selectFields, fieldsSorts, where<O>(key), pageIndex, pageSize));
            } else if (searchMode.toLower() == "one") {
                renderText(GetOneNoHash(tableName<O>(), selectFields, where<O>(key)));
            } else {
                renderText("Need para: searchMode!");
            }
        } else {
            if (searchMode.toLower() == "all") {
                renderText(GetAll(tableName<O>(), selectFields, fieldsSorts, where<O>(key), pkFieldList<O>(), fkFieldList<O>()));
            } else if (searchMode.toLower() == "page") {
                renderText(GetPage(tableName<O>(), selectFields, fieldsSorts, where<O>(key), pageIndex, pageSize, pkFieldList<O>(), fkFieldList<O>()));
            } else if (searchMode.toLower() == "one") {
                renderText(GetOne(tableName<O>(), selectFields,  where<O>(key), pkFieldList<O>(), fkFieldList<O>()));
            } else {
                renderText("Need para: searchMode!");
            }
        }

    }

    QString GetPageNoHash(const QString &tableName,
                          const QString &selectField = "*",
                          const QString &sortColumnsOrders = "",
                          const QString &where = "",
                          const int pageIndex = 0,
                          const int pageSize = -1);
    QString GetAllNoHash(const QString &tableName,
                         const QString &selectField = "*",
                         const QString &sortColumnsOrders = "",
                         const QString &where = "");
    QString GetOneNoHash(const QString &tableName,
                         const QString &selectField = "*",
                         const QString &where = "");
    QString GetPage(const QString &tableName,
                    const QString &selectField = "*",
                    const QString &sortColumnsOrders = "",
                    const QString &where = "",
                    const int pageIndex = 0,
                    const int pageSize = -1,
                    const QStringList &pkFieldList = QStringList(),
                    const QStringList &fkFieldList = QStringList());
    QString GetAll(const QString &tableName,
                   const QString &selectField = "*",
                   const QString &sortColumnsOrders = "",
                   const QString &where = "",
                   const QStringList &pkFieldList = QStringList(),
                   const QStringList &fkFieldList = QStringList());
    QString GetOne(const QString &tableName,
                   const QString &selectField = "*",
                   const QString &where = "",
                   const QStringList &pkFieldList = QStringList(),
                   const QStringList &fkFieldList = QStringList());

};


#endif // DATASERVICECONTROLLER_H
