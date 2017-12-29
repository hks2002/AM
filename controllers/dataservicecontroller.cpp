#include <TSqlQuery>
#include "dataservicecontroller.h"
#include "sqlobjects/allsqlobjects.h"

void DataServiceController::getHttpRequestPara()
{
    switch (httpRequest().method()) {
        case Tf::Get:
            renderErrorResponse(Tf::Forbidden);
            break;

        case Tf::Post:
            fields     = httpRequest().formItemValue("fields");
            key        = httpRequest().formItemValue("key");
            pageIndex  = httpRequest().formItemValue("pageIndex", "0").toInt();
            pageSize   = httpRequest().formItemValue("pageSize", "100").toInt();

            sortFields = httpRequest().formItemValue("sortFields");
            sortField  = httpRequest().formItemValue("sortField");
            sortOrder  = httpRequest().formItemValue("sortOrder");
            searchMode = httpRequest().queryItemValue("searchMode");
            hashMode   = httpRequest().queryItemValue("hashMode");

            tDebug() << "fields:" << fields;
            tDebug() << "key:" << key;
            tDebug() << "sortFields:" << sortFields;
            tDebug() << "sortField:" << sortField;
            tDebug() << "sortOrder:" << sortOrder;
            break;

        default:
            renderErrorResponse(Tf::NotFound);
            break;
    }
}

QString DataServiceController::vTof(const QString &variableName)
{
    tTrace(QString(variableName).append(" v->f ").append(
               fieldNameMap.value(variableName)).toLatin1().data());
    return fieldNameMap.value(variableName, ""); //if not found, return QString()
}

QString DataServiceController::selectAsFields(const QStringList &fieldList)
{
    QString selectAsField;

    for (auto &x : fieldList) {
        selectAsField += fieldNameMap.value(x) + " as \"" + x + "\",";
    }

    selectAsField.chop(1);
    tTrace(QString(selectAsField).prepend("selectField:").toLatin1().data());
    return selectAsField;
}

QString DataServiceController::tableAllAsFields()
{
    QString allAsFields;
    QMap<QString, QString>::Iterator  it;

    for (it = fieldNameMap.begin(); it != fieldNameMap.end(); ++it) {
        QString lowerFieldName = it.value().toLower();

        if (lowerFieldName != "created_at" &&
                lowerFieldName != "created_by" &&
                lowerFieldName != "updated_at" &&
                lowerFieldName != "updated_by" &&
                lowerFieldName != "modified_at" &&
                lowerFieldName != "modified_by"
           ) {
            allAsFields += it.value() + " as \"" + it.key() + "\",";
        }
    }

    allAsFields.chop(1);
    tTrace(QString(allAsFields).prepend("tableAllField:").toLatin1().data());
    return allAsFields;
}

QString DataServiceController::singleSort(const QString &sortField, const QString &sortOrder)
{
    QString sortColumnsOrder;
    QString field = vTof(sortField);

    if (!field.isEmpty()) {
        sortColumnsOrder = QString(" order by ") + field + ' ' + sortOrder;
        tTrace(QString(sortColumnsOrder).prepend("setSingleSort:").toLatin1().data());
    }

    return sortColumnsOrder;
}

QString DataServiceController::multiSort(const QString &sortFields)
{
    QString sortColumnsOrders;

    if (sortFields.isEmpty()) {
        tDebug(QString("sortFields is empty!").toLatin1().data());
        return sortColumnsOrders;
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

                QString sortfield = vTof(field);

                if (!sortfield.isEmpty()) {
                    sortColumnsOrders +=  sortfield + ' ' + dir + ',';
                }
            }

            if (array.size() > 0) { sortColumnsOrders.chop(1); }
        } else {
            tDebug(QString("sortFields should be an array!").toLatin1().data());
        }
    } else {
        tDebug(QString("sortFields parse error:").append(jsonError.errorString()).toLatin1().data());
    }

    tTrace(QString(sortColumnsOrders).prepend("setMultiSort:").toLatin1().data());
    return sortColumnsOrders;
}

QString DataServiceController::GetPageNoHash(const QString &tableName,
        const QString &selectField,
        const QString &sortColumnsOrders,
        const QString &where,
        const int pageIndex,
        const int pageSize)
{

    QString sql = QString("\
    select row_to_json(t) from\
    (select count(1) as total, %7 %8\
            (select array_to_json(array_agg(row_to_json(t1)))\
             from (select %2 from %1 %3 %4 %5 %6) as t1 ) as data \
      from %1 \
    ) as t");

    int offset = pageIndex * pageSize;
    sql = sql.arg(tableName,
                  selectField.isEmpty() ? "*" : selectField,
                  where.isEmpty() ? "" : where,
                  sortColumnsOrders.isEmpty() ? "" : sortColumnsOrders,
                  offset < 0 ? "" : QString(" offset ") + QString::number(offset),
                  pageSize <= 0 ? "" : QString(" limit ") + QString::number(pageSize),
                  pageIndex < 0 ? "" : QString::number(pageIndex) + " as \"pageIndex\",",
                  pageSize <= 0 ? "" : QString::number(pageSize) + " as \"pageSize\",");

    tDebug() << "sql:" << sql;

    TSqlQuery query;
    query.prepare(sql);

    query.exec();

    while (query.next()) {
        tDebug() << "ajax page no hash query result:" << query.value(0).toString();
        return query.value(0).toString();
    }

    return QString();
}

QString DataServiceController::GetAllNoHash(const QString &tableName,
        const QString &selectField,
        const QString &sortColumnsOrders,
        const QString &where)
{

    QString sql = QString("\
     select array_to_json(array_agg(row_to_json(t1)))\
             from (select %2 from %1 %3 %4 ) as t1 ");

    sql = sql.arg(tableName,
                  selectField.isEmpty() ? "*" : selectField,
                  where.isEmpty() ? "" : where,
                  sortColumnsOrders.isEmpty() ? "" : sortColumnsOrders
                 );

    tDebug() << "sql:" << sql;

    TSqlQuery query;
    query.prepare(sql);

    query.exec();

    while (query.next()) {
        tDebug() << "ajax no hash query result:" << query.value(0).toString();
        return query.value(0).toString();
    }

    return QString();
}


QString DataServiceController::GetOneNoHash(const QString &tableName,
        const QString &selectField,
        const QString &where)
{

    QString sql = QString("\
     select row_to_json(t1)\
             from (select %2 from %1 %3 limit 1) as t1 ");

    sql = sql.arg(tableName,
                  selectField.isEmpty() ? "*" : selectField,
                  where.isEmpty() ? "" : where);

    tDebug() << "sql:" << sql;

    TSqlQuery query;
    query.prepare(sql);

    query.exec();

    while (query.next()) {
        tDebug() << "ajax no hash query result:" << query.value(0).toString();
        return query.value(0).toString();
    }

    return QString();
}

QString DataServiceController::GetPage(const QString &tableName,
                                       const QString &selectField,
                                       const QString &sortColumnsOrders,
                                       const QString &where,
                                       const int pageIndex,
                                       const int pageSize,
                                       const QStringList &pkFieldList,
                                       const QStringList &fkFieldList)
{

    QString sql = QString("select %2 from %1 %3 %4 %5 %6");
    //{total:100,pageIndex:1,pageSize:100,data:[{},{}]}

    QString sqlforcount;
    int totalcount = 0;
    sqlforcount = sql.arg(tableName, "Count (1)", where.isEmpty() ? "" : where, "", "", "");
    TSqlQuery queryforcount;
    queryforcount.prepare(sqlforcount);
    queryforcount.exec();

    while (queryforcount.next()) {
        QSqlRecord record = queryforcount.record();
        totalcount = record.value(0).toInt();
    }

    int offset = pageIndex * pageSize;
    sql = sql.arg(tableName,
                  selectField.isEmpty() ? "*" : selectField,
                  where.isEmpty() ? "" : where,
                  sortColumnsOrders.isEmpty() ? "" : sortColumnsOrders,
                  offset < 0 ? "" : QString(" offset ") + QString::number(offset),
                  pageSize <= 0 ? "" : QString(" limit ") + QString::number(pageSize));

    tDebug() << "sql:" << sql;

    TSqlQuery query;
    query.prepare(sql);
    query.exec();

    QString result;

    while (query.next()) {
        QSqlRecord record = query.record();
        QString recordResult;

        for (int i = 0; i < record.count(); ++i) {
            QString fieldName = record.fieldName(i);
            QString fieldValue = record.value(i).toString();

            if ((pkFieldList.contains(fieldName) || fkFieldList.contains(fieldName))
                    && !fieldName.startsWith("ref") && !fieldName.endsWith("Cd")) {
                QString hash = hmac(fieldValue);
                fieldValue = hash;
            }

            recordResult += '"';
            recordResult += fieldName;
            recordResult += "\":\"";
            recordResult += fieldValue;
            recordResult += "\",";
        }

        recordResult.chop(1);//if have record, must have field
        result += recordResult.prepend('{').append("},");
    }

    if (!result.isEmpty()) {
        result.chop(1);
    }

    result = result.prepend("\"data\":[").append(']');
    QString  sumary = "\"total\":" + QString::number(totalcount) + ",\"pageIndex\":" + QString::number(offset) + ",\"pageSize\":" + QString::number(pageSize);
    result = result.prepend(",").prepend(sumary);
    result = result.prepend('{').append('}');
    tDebug() << "ajax page hash query result:" << result;

    return result;
}

QString DataServiceController::GetAll(const QString &tableName,
                                      const QString &selectField,
                                      const QString &sortColumnsOrders,
                                      const QString &where,
                                      const QStringList &pkFieldList,
                                      const QStringList &fkFieldList)
{

    QString sql = QString("select %2 from %1 %3 %4 ");

    sql = sql.arg(tableName,
                  selectField.isEmpty() ? "*" : selectField,
                  where.isEmpty() ? "" : where,
                  sortColumnsOrders.isEmpty() ? "" : sortColumnsOrders
                 );

    tDebug() << "sql:" << sql;

    TSqlQuery query;
    query.prepare(sql);
    query.exec();

    QString result;

    while (query.next()) {
        QSqlRecord record = query.record();
        QString recordResult;

        for (int i = 0; i < record.count(); ++i) {
            QString fieldName = record.fieldName(i);
            QString fieldValue = record.value(i).toString();

            if ((pkFieldList.contains(fieldName) || fkFieldList.contains(fieldName))
                    && !fieldName.startsWith("ref") && !fieldName.endsWith("Cd")) {
                QString hash = hmac(fieldValue);
                fieldValue = hash;
            }

            recordResult += '"';
            recordResult += fieldName;
            recordResult += "\":\"";
            recordResult += fieldValue;
            recordResult += "\",";
        }

        recordResult.chop(1);//if have record, must have field
        result += recordResult.prepend('{').append("},");
    }

    if (!result.isEmpty()) {
        result.chop(1);
    }

    result = result.prepend('[').append(']');
    tDebug() << "ajax hash query result:" << result;
    return result;
}

QString DataServiceController::GetOne(const QString &tableName,
                                      const QString &selectField,
                                      const QString &where,
                                      const QStringList &pkFieldList,
                                      const QStringList &fkFieldList)
{

    QString sql = QString("select %2 from %1 %3  limit 1");

    sql = sql.arg(tableName,
                  selectField.isEmpty() ? "*" : selectField,
                  where.isEmpty() ? "" : where);

    tDebug() << "sql:" << sql;

    TSqlQuery query;
    query.prepare(sql);
    query.exec();

    QString result;

    while (query.next()) {
        QSqlRecord record = query.record();

        for (int i = 0; i < record.count(); ++i) {
            QString fieldName = record.fieldName(i);
            QString fieldValue = record.value(i).toString();

            if ((pkFieldList.contains(fieldName) || fkFieldList.contains(fieldName))
                    && !fieldName.startsWith("ref") && !fieldName.endsWith("Cd")) {
                QString hash = hmac(fieldValue);
                fieldValue = hash;
            }

            result += '"';
            result += fieldName;
            result += "\":\"";
            result += fieldValue;
            result += "\",";
        }

        result.chop(1);//if have record, must have field
    }

    result = result.prepend('{').append('}');
    tDebug() << "ajax hash query result:" << result;
    return result;
}

void DataServiceController::Search(const QString &entity, const QString &relationEntiry, const QString &relation)
{
    relation.toLower() == "unassigned" ? isRelationIn = false : isRelationIn = true;
    Search(entity, relationEntiry);
}

void DataServiceController::Search(const QString &entity, const QString &relationEntiry)
{
    //isRelationIn setted or user default true
    isRelationSearch = true;

    if (entity == "UserApp" && relationEntiry == "UserAttachment") { relationKey<class UserAppObject, class UserAttachmentObject>();}
    else if (entity == "RefFileSave" && relationEntiry == "UserAttachment") { relationKey<class RefFileSaveObject, class UserAttachmentObject>();}
    else if (entity == "UserApp" && relationEntiry == "UserPswdHis") { relationKey<class UserAppObject, class UserPswdHisObject>();}
    else if (entity == "UserApp" && relationEntiry == "UserLoginHis") { relationKey<class UserAppObject, class UserLoginHisObject>();}
    else if (entity == "RoleApp" && relationEntiry == "RoleUser") { relationKey<class RoleAppObject, class RoleUserObject>();}
    else if (entity == "UserApp" && relationEntiry == "RoleUser") { relationKey<class UserAppObject, class RoleUserObject>();}
    else if (entity == "Country" && relationEntiry == "CountryProvince") { relationKey<class CountryObject, class CountryProvinceObject>();}
    else if (entity == "Province" && relationEntiry == "CountryProvince") { relationKey<class ProvinceObject, class CountryProvinceObject>();}
    else if (entity == "Province" && relationEntiry == "ProvinceCity") { relationKey<class ProvinceObject, class ProvinceCityObject>();}
    else if (entity == "City" && relationEntiry == "ProvinceCity") { relationKey<class CityObject, class ProvinceCityObject>();}
    else if (entity == "City" && relationEntiry == "Address") { relationKey<class CityObject, class AddressObject>();}
    else if (entity == "Country" && relationEntiry == "Address") { relationKey<class CountryObject, class AddressObject>();}
    else if (entity == "Province" && relationEntiry == "Address") { relationKey<class ProvinceObject, class AddressObject>();}
    else if (entity == "Dept" && relationEntiry == "DeptSubdept") { relationKey<class DeptObject, class DeptSubdeptObject>();}
    else if (entity == "Dept" && relationEntiry == "DeptUser") { relationKey<class DeptObject, class DeptUserObject>();}
    else if (entity == "UserApp" && relationEntiry == "DeptUser") { relationKey<class UserAppObject, class DeptUserObject>();}
    else if (entity == "Org" && relationEntiry == "OrgAddress") { relationKey<class OrgObject, class OrgAddressObject>();}
    else if (entity == "Address" && relationEntiry == "OrgAddress") { relationKey<class AddressObject, class OrgAddressObject>();}
    else if (entity == "Org" && relationEntiry == "OrgContact") { relationKey<class OrgObject, class OrgContactObject>();}
    else if (entity == "Contact" && relationEntiry == "OrgContact") { relationKey<class ContactObject, class OrgContactObject>();}
    else if (entity == "Org" && relationEntiry == "OrgSuborg") { relationKey<class OrgObject, class OrgSuborgObject>();}
    else if (entity == "Dept" && relationEntiry == "OrgDept") { relationKey<class DeptObject, class OrgDeptObject>();}
    else if (entity == "Org" && relationEntiry == "OrgDept") { relationKey<class OrgObject, class OrgDeptObject>();}
    else if (entity == "UserApp" && relationEntiry == "ActionUser") { relationKey<class UserAppObject, class ActionUserObject>();}
    else if (entity == "ActionApp" && relationEntiry == "ActionUser") { relationKey<class ActionAppObject, class ActionUserObject>();}
    else if (entity == "ActionApp" && relationEntiry == "ActionRole") { relationKey<class ActionAppObject, class ActionRoleObject>();}
    else if (entity == "RoleApp" && relationEntiry == "ActionRole") { relationKey<class RoleAppObject, class ActionRoleObject>();}
    else if (entity == "TodoList" && relationEntiry == "TodoListButton") { relationKey<class TodoListObject, class TodoListButtonObject>();}
    else if (entity == "Button" && relationEntiry == "TodoListButton") { relationKey<class ButtonObject, class TodoListButtonObject>();}
    else if (entity == "TodoList" && relationEntiry == "TodoListTab") { relationKey<class TodoListObject, class TodoListTabObject>();}
    else if (entity == "Tab" && relationEntiry == "TodoListTab") { relationKey<class TabObject, class TodoListTabObject>();}
    else if (entity == "TodoList" && relationEntiry == "TodoListUser") { relationKey<class TodoListObject, class TodoListUserObject>();}
    else if (entity == "UserApp" && relationEntiry == "TodoListUser") { relationKey<class UserAppObject, class TodoListUserObject>();}
    else if (entity == "TodoList" && relationEntiry == "TodoListRole") { relationKey<class TodoListObject, class TodoListRoleObject>();}
    else if (entity == "RoleApp" && relationEntiry == "TodoListRole") { relationKey<class RoleAppObject, class TodoListRoleObject>();}
    else if (entity == "MenusGroup" && relationEntiry == "MenusGroupMenu") { relationKey<class MenusGroupObject, class MenusGroupMenuObject>();}
    else if (entity == "Menu" && relationEntiry == "MenusGroupMenu") { relationKey<class MenuObject, class MenusGroupMenuObject>();}
    else if (entity == "MenusGroup" && relationEntiry == "MenusGroupUser") { relationKey<class MenusGroupObject, class MenusGroupUserObject>();}
    else if (entity == "UserApp" && relationEntiry == "MenusGroupUser") { relationKey<class UserAppObject, class MenusGroupUserObject>();}
    else if (entity == "MenusGroup" && relationEntiry == "MenusGroupRole") { relationKey<class MenusGroupObject, class MenusGroupRoleObject>();}
    else if (entity == "RoleApp" && relationEntiry == "MenusGroupRole") { relationKey<class RoleAppObject, class MenusGroupRoleObject>();}
    else if (entity == "RefFailSev" && relationEntiry == "RefFailSevDefer") { relationKey<class RefFailSevObject, class RefFailSevDeferObject>();}
    else if (entity == "RefFailDefer" && relationEntiry == "RefFailSevDefer") { relationKey<class RefFailDeferObject, class RefFailSevDeferObject>();}
    else if (entity == "RefLocType" && relationEntiry == "Loc") { relationKey<class RefLocTypeObject, class LocObject>();}
    else if (entity == "Loc" && relationEntiry == "LocSubloc") { relationKey<class LocObject, class LocSublocObject>();}
    else if (entity == "Loc" && relationEntiry == "LocAddress") { relationKey<class LocObject, class LocAddressObject>();}
    else if (entity == "Address" && relationEntiry == "LocAddress") { relationKey<class AddressObject, class LocAddressObject>();}
    else if (entity == "Loc" && relationEntiry == "LocContact") { relationKey<class LocObject, class LocContactObject>();}
    else if (entity == "Contact" && relationEntiry == "LocContact") { relationKey<class ContactObject, class LocContactObject>();}
    else if (entity == "Loc" && relationEntiry == "LocAirportSetting") { relationKey<class LocObject, class LocAirportSettingObject>();}
    else if (entity == "Loc" && relationEntiry == "LocLineSetting") { relationKey<class LocObject, class LocLineSettingObject>();}
    else if (entity == "Loc" && relationEntiry == "LocDockSetting") { relationKey<class LocObject, class LocDockSettingObject>();}
    else if (entity == "Loc" && relationEntiry == "LocWorkTypeCapability") { relationKey<class LocObject, class LocWorkTypeCapabilityObject>();}
    else if (entity == "EqpAssmbl" && relationEntiry == "LocWorkTypeCapability") { relationKey<class EqpAssmblObject, class LocWorkTypeCapabilityObject>();}
    else if (entity == "WorkType" && relationEntiry == "LocWorkTypeCapability") { relationKey<class WorkTypeObject, class LocWorkTypeCapabilityObject>();}
    else if (entity == "Loc" && relationEntiry == "LocLabourCapacity") { relationKey<class LocObject, class LocLabourCapacityObject>();}
    else if (entity == "LabourSkill" && relationEntiry == "LocLabourCapacity") { relationKey<class LabourSkillObject, class LocLabourCapacityObject>();}
    else if (entity == "Loc" && relationEntiry == "LocBinLevel") { relationKey<class LocObject, class LocBinLevelObject>();}
    else if (entity == "EqpPartNo" && relationEntiry == "LocBinLevel") { relationKey<class EqpPartNoObject, class LocBinLevelObject>();}
    else if (entity == "OwnerApp" && relationEntiry == "LocBinLevel") { relationKey<class OwnerAppObject, class LocBinLevelObject>();}
    else if (entity == "Loc" && relationEntiry == "LocPartCount") { relationKey<class LocObject, class LocPartCountObject>();}
    else if (entity == "EqpPartNo" && relationEntiry == "LocPartCount") { relationKey<class EqpPartNoObject, class LocPartCountObject>();}
    else if (entity == "UserApp" && relationEntiry == "LocPartCount") { relationKey<class UserAppObject, class LocPartCountObject>();}
    else if (entity == "Loc" && relationEntiry == "LocInvRecount") { relationKey<class LocObject, class LocInvRecountObject>();}
    else if (entity == "EqpPartNo" && relationEntiry == "LocInvRecount") { relationKey<class EqpPartNoObject, class LocInvRecountObject>();}
    else if (entity == "LocPartCount" && relationEntiry == "LocInvRecount") { relationKey<class LocPartCountObject, class LocInvRecountObject>();}
    else if (entity == "UserApp" && relationEntiry == "LocInvRecount") { relationKey<class UserAppObject, class LocInvRecountObject>();}
    else if (entity == "InvInv" && relationEntiry == "LocInvRecount") { relationKey<class InvInvObject, class LocInvRecountObject>();}
    else if (entity == "Loc" && relationEntiry == "LocShopRepair") { relationKey<class LocObject, class LocShopRepairObject>();}
    else if (entity == "EqpPartNo" && relationEntiry == "LocShopRepair") { relationKey<class EqpPartNoObject, class LocShopRepairObject>();}
    else if (entity == "Org" && relationEntiry == "OrgCode") { relationKey<class OrgObject, class OrgCodeObject>();}
    else if (entity == "Org" && relationEntiry == "OrgVendorApproval") { relationKey<class OrgObject, class OrgVendorApprovalObject>();}
    else if (entity == "Vendor" && relationEntiry == "OrgVendorApproval") { relationKey<class VendorObject, class OrgVendorApprovalObject>();}
    else if (entity == "RefVendorType" && relationEntiry == "OrgVendorApproval") { relationKey<class RefVendorTypeObject, class OrgVendorApprovalObject>();}
    else if (entity == "UserApp" && relationEntiry == "UserSkill") { relationKey<class UserAppObject, class UserSkillObject>();}
    else if (entity == "LabourSkill" && relationEntiry == "UserSkill") { relationKey<class LabourSkillObject, class UserSkillObject>();}
    else if (entity == "RefLicenseStatus" && relationEntiry == "License") { relationKey<class RefLicenseStatusObject, class LicenseObject>();}
    else if (entity == "LabourSkill" && relationEntiry == "LicensePrerequisite") { relationKey<class LabourSkillObject, class LicensePrerequisiteObject>();}
    else if (entity == "UserApp" && relationEntiry == "UserLicense") { relationKey<class UserAppObject, class UserLicenseObject>();}
    else if (entity == "License" && relationEntiry == "UserLicense") { relationKey<class LicenseObject, class UserLicenseObject>();}
    else if (entity == "UserApp" && relationEntiry == "UserAuthority") { relationKey<class UserAppObject, class UserAuthorityObject>();}
    else if (entity == "Authority" && relationEntiry == "UserAuthority") { relationKey<class AuthorityObject, class UserAuthorityObject>();}
    else if (entity == "UserApp" && relationEntiry == "UserElecCert") { relationKey<class UserAppObject, class UserElecCertObject>();}
    else if (entity == "UserApp" && relationEntiry == "UserPoAuthLvl") { relationKey<class UserAppObject, class UserPoAuthLvlObject>();}
    else if (entity == "Currency" && relationEntiry == "UserPoAuthLvl") { relationKey<class CurrencyObject, class UserPoAuthLvlObject>();}
    else if (entity == "Currency" && relationEntiry == "Vendor") { relationKey<class CurrencyObject, class VendorObject>();}
    else if (entity == "RefVendorStatus" && relationEntiry == "Vendor") { relationKey<class RefVendorStatusObject, class VendorObject>();}
    else if (entity == "Vendor" && relationEntiry == "VendorAccount") { relationKey<class VendorObject, class VendorAccountObject>();}
    else if (entity == "FncAccount" && relationEntiry == "VendorAccount") { relationKey<class FncAccountObject, class VendorAccountObject>();}
    else if (entity == "Vendor" && relationEntiry == "VendorAttachment") { relationKey<class VendorObject, class VendorAttachmentObject>();}
    else if (entity == "RefFileSave" && relationEntiry == "VendorAttachment") { relationKey<class RefFileSaveObject, class VendorAttachmentObject>();}
    else if (entity == "Manufact" && relationEntiry == "ManufactAttachment") { relationKey<class ManufactObject, class ManufactAttachmentObject>();}
    else if (entity == "RefFileSave" && relationEntiry == "ManufactAttachment") { relationKey<class RefFileSaveObject, class ManufactAttachmentObject>();}
    else if (entity == "RefOwnerType" && relationEntiry == "OwnerApp") { relationKey<class RefOwnerTypeObject, class OwnerAppObject>();}
    else if (entity == "Org" && relationEntiry == "OwnerApp") { relationKey<class OrgObject, class OwnerAppObject>();}
    else if (entity == "Vendor" && relationEntiry == "OwnerApp") { relationKey<class VendorObject, class OwnerAppObject>();}
    else if (entity == "FncAccount" && relationEntiry == "Charge") { relationKey<class FncAccountObject, class ChargeObject>();}
    else if (entity == "FncAccount" && relationEntiry == "Tax") { relationKey<class FncAccountObject, class TaxObject>();}
    else if (entity == "RefEngUnit" && relationEntiry == "DataType") { relationKey<class RefEngUnitObject, class DataTypeObject>();}
    else if (entity == "RefMesurType" && relationEntiry == "MesurTypeUnit") { relationKey<class RefMesurTypeObject, class MesurTypeUnitObject>();}
    else if (entity == "MesurUnit" && relationEntiry == "MesurTypeUnit") { relationKey<class MesurUnitObject, class MesurTypeUnitObject>();}
    else if (entity == "AlertDef" && relationEntiry == "AlertDefRole") { relationKey<class AlertDefObject, class AlertDefRoleObject>();}
    else if (entity == "RoleApp" && relationEntiry == "AlertDefRole") { relationKey<class RoleAppObject, class AlertDefRoleObject>();}
    else if (entity == "AlertDef" && relationEntiry == "AlertDefDept") { relationKey<class AlertDefObject, class AlertDefDeptObject>();}
    else if (entity == "Dept" && relationEntiry == "AlertDefDept") { relationKey<class DeptObject, class AlertDefDeptObject>();}
    else if (entity == "AlertDef" && relationEntiry == "AlertDefUser") { relationKey<class AlertDefObject, class AlertDefUserObject>();}
    else if (entity == "UserApp" && relationEntiry == "AlertDefUser") { relationKey<class UserAppObject, class AlertDefUserObject>();}
    else if (entity == "AlertDef" && relationEntiry == "Alert") { relationKey<class AlertDefObject, class AlertObject>();}
    else if (entity == "RefAlertStatus" && relationEntiry == "Alert") { relationKey<class RefAlertStatusObject, class AlertObject>();}
    else if (entity == "Alert" && relationEntiry == "AlertUserLog") { relationKey<class AlertObject, class AlertUserLogObject>();}
    else if (entity == "UserApp" && relationEntiry == "AlertUserLog") { relationKey<class UserAppObject, class AlertUserLogObject>();}
    else if (entity == "RefAlertStatus" && relationEntiry == "AlertUserLog") { relationKey<class RefAlertStatusObject, class AlertUserLogObject>();}
    else if (entity == "RefAssmblClass" && relationEntiry == "EqpAssmbl") { relationKey<class RefAssmblClassObject, class EqpAssmblObject>();}
    else if (entity == "EqpAssmbl" && relationEntiry == "EqpAssmblDataType") { relationKey<class EqpAssmblObject, class EqpAssmblDataTypeObject>();}
    else if (entity == "DataType" && relationEntiry == "EqpAssmblDataType") { relationKey<class DataTypeObject, class EqpAssmblDataTypeObject>();}
    else if (entity == "EqpAssmblDataType" && relationEntiry == "EqpAssmblOil") { relationKey<class EqpAssmblDataTypeObject, class EqpAssmblOilObject>();}
    else if (entity == "MesurUnit" && relationEntiry == "EqpAssmblOil") { relationKey<class MesurUnitObject, class EqpAssmblOilObject>();}
    else if (entity == "EqpAssmbl" && relationEntiry == "EqpAssmblBom") { relationKey<class EqpAssmblObject, class EqpAssmblBomObject>();}
    else if (entity == "RefBomClass" && relationEntiry == "EqpAssmblBom") { relationKey<class RefBomClassObject, class EqpAssmblBomObject>();}
    else if (entity == "EqpAssmblBom" && relationEntiry == "EqpAssmblBomCapability") { relationKey<class EqpAssmblBomObject, class EqpAssmblBomCapabilityObject>();}
    else if (entity == "OperationCapability" && relationEntiry == "EqpAssmblBomCapability") { relationKey<class OperationCapabilityObject, class EqpAssmblBomCapabilityObject>();}
    else if (entity == "EqpAssmblBom" && relationEntiry == "EqpAssmblBomPos") { relationKey<class EqpAssmblBomObject, class EqpAssmblBomPosObject>();}
    else if (entity == "EqpAssmblBom" && relationEntiry == "EqpAssmblBomThreshold") { relationKey<class EqpAssmblBomObject, class EqpAssmblBomThresholdObject>();}
    else if (entity == "RefThresholdMode" && relationEntiry == "EqpAssmblBomThreshold") { relationKey<class RefThresholdModeObject, class EqpAssmblBomThresholdObject>();}
    else if (entity == "EqpAssmblBom" && relationEntiry == "EqpAssmblBomTree") { relationKey<class EqpAssmblBomObject, class EqpAssmblBomTreeObject>();}
    else if (entity == "EqpAssmblBom" && relationEntiry == "EqpAssmblBomPart") { relationKey<class EqpAssmblBomObject, class EqpAssmblBomPartObject>();}
    else if (entity == "EqpPartNo" && relationEntiry == "EqpAssmblBomPart") { relationKey<class EqpPartNoObject, class EqpAssmblBomPartObject>();}
    else if (entity == "EqpAssmblBom" && relationEntiry == "EqpAssmblBomDataType") { relationKey<class EqpAssmblBomObject, class EqpAssmblBomDataTypeObject>();}
    else if (entity == "DataType" && relationEntiry == "EqpAssmblBomDataType") { relationKey<class DataTypeObject, class EqpAssmblBomDataTypeObject>();}
    else if (entity == "EqpAssmbl" && relationEntiry == "EqpAssmblBomLog") { relationKey<class EqpAssmblObject, class EqpAssmblBomLogObject>();}
    else if (entity == "EqpAssmblBom" && relationEntiry == "EqpAssmblBomLog") { relationKey<class EqpAssmblBomObject, class EqpAssmblBomLogObject>();}
    else if (entity == "RefLogAction" && relationEntiry == "EqpAssmblBomLog") { relationKey<class RefLogActionObject, class EqpAssmblBomLogObject>();}
    else if (entity == "Manufact" && relationEntiry == "EqpPartNo") { relationKey<class ManufactObject, class EqpPartNoObject>();}
    else if (entity == "RefPartStatus" && relationEntiry == "EqpPartNo") { relationKey<class RefPartStatusObject, class EqpPartNoObject>();}
    else if (entity == "RefInvClass" && relationEntiry == "EqpPartNo") { relationKey<class RefInvClassObject, class EqpPartNoObject>();}
    else if (entity == "FncAccount" && relationEntiry == "EqpPartNo") { relationKey<class FncAccountObject, class EqpPartNoObject>();}
    else if (entity == "QtyUnit" && relationEntiry == "EqpPartNo") { relationKey<class QtyUnitObject, class EqpPartNoObject>();}
    else if (entity == "RefPartUse" && relationEntiry == "EqpPartNo") { relationKey<class RefPartUseObject, class EqpPartNoObject>();}
    else if (entity == "RefPartType" && relationEntiry == "EqpPartNo") { relationKey<class RefPartTypeObject, class EqpPartNoObject>();}
    else if (entity == "EqpPartNo" && relationEntiry == "EqpPartNoAltUnit") { relationKey<class EqpPartNoObject, class EqpPartNoAltUnitObject>();}
    else if (entity == "QtyUnit" && relationEntiry == "EqpPartNoAltUnit") { relationKey<class QtyUnitObject, class EqpPartNoAltUnitObject>();}
    else if (entity == "EqpPartNo" && relationEntiry == "EqpPartNoCapability") { relationKey<class EqpPartNoObject, class EqpPartNoCapabilityObject>();}
    else if (entity == "OperationCapability" && relationEntiry == "EqpPartNoCapability") { relationKey<class OperationCapabilityObject, class EqpPartNoCapabilityObject>();}
    else if (entity == "EqpPartNo" && relationEntiry == "EqpKitPartNo") { relationKey<class EqpPartNoObject, class EqpKitPartNoObject>();}
    else if (entity == "EqpPartNo" && relationEntiry == "EqpPartNoControl") { relationKey<class EqpPartNoObject, class EqpPartNoControlObject>();}
    else if (entity == "EqpPartNo" && relationEntiry == "EqpPartNoTechData") { relationKey<class EqpPartNoObject, class EqpPartNoTechDataObject>();}
    else if (entity == "MesurUnit" && relationEntiry == "EqpPartNoTechData") { relationKey<class MesurUnitObject, class EqpPartNoTechDataObject>();}
    else if (entity == "RefMesurType" && relationEntiry == "EqpPartNoTechData") { relationKey<class RefMesurTypeObject, class EqpPartNoTechDataObject>();}
    else if (entity == "EqpPartNo" && relationEntiry == "EqpPartNoReliab") { relationKey<class EqpPartNoObject, class EqpPartNoReliabObject>();}
    else if (entity == "RefEngUnit" && relationEntiry == "EqpPartNoReliab") { relationKey<class RefEngUnitObject, class EqpPartNoReliabObject>();}
    else if (entity == "EqpPartNo" && relationEntiry == "EqpPartNoShipStoragePackage") { relationKey<class EqpPartNoObject, class EqpPartNoShipStoragePackageObject>();}
    else if (entity == "EqpPartNo" && relationEntiry == "EqpPartNoVendorPur") { relationKey<class EqpPartNoObject, class EqpPartNoVendorPurObject>();}
    else if (entity == "Vendor" && relationEntiry == "EqpPartNoVendorPur") { relationKey<class VendorObject, class EqpPartNoVendorPurObject>();}
    else if (entity == "EqpPartNo" && relationEntiry == "EqpPartNoVendorRep") { relationKey<class EqpPartNoObject, class EqpPartNoVendorRepObject>();}
    else if (entity == "Vendor" && relationEntiry == "EqpPartNoVendorRep") { relationKey<class VendorObject, class EqpPartNoVendorRepObject>();}
    else if (entity == "EqpPartNo" && relationEntiry == "EqpPartNoVendorExchg") { relationKey<class EqpPartNoObject, class EqpPartNoVendorExchgObject>();}
    else if (entity == "Vendor" && relationEntiry == "EqpPartNoVendorExchg") { relationKey<class VendorObject, class EqpPartNoVendorExchgObject>();}
    else if (entity == "Vendor" && relationEntiry == "EqpPartNoVendorPrice") { relationKey<class VendorObject, class EqpPartNoVendorPriceObject>();}
    else if (entity == "EqpPartNo" && relationEntiry == "EqpPartNoVendorPrice") { relationKey<class EqpPartNoObject, class EqpPartNoVendorPriceObject>();}
    else if (entity == "RefPriceType" && relationEntiry == "EqpPartNoVendorPrice") { relationKey<class RefPriceTypeObject, class EqpPartNoVendorPriceObject>();}
    else if (entity == "QtyUnit" && relationEntiry == "EqpPartNoVendorPrice") { relationKey<class QtyUnitObject, class EqpPartNoVendorPriceObject>();}
    else if (entity == "EqpAssmbl" && relationEntiry == "EqpPartNoCompatDef") { relationKey<class EqpAssmblObject, class EqpPartNoCompatDefObject>();}
    else if (entity == "EqpPartNo" && relationEntiry == "EqpPartNoCompatDef") { relationKey<class EqpPartNoObject, class EqpPartNoCompatDefObject>();}
    else if (entity == "EqpAssmbl" && relationEntiry == "EqpPartNoCompatTask") { relationKey<class EqpAssmblObject, class EqpPartNoCompatTaskObject>();}
    else if (entity == "EqpPartNo" && relationEntiry == "EqpPartNoCompatTask") { relationKey<class EqpPartNoObject, class EqpPartNoCompatTaskObject>();}
    else if (entity == "TaskDefn" && relationEntiry == "EqpPartNoCompatTask") { relationKey<class TaskDefnObject, class EqpPartNoCompatTaskObject>();}
    else if (entity == "EqpPartNo" && relationEntiry == "EqpPartNoLog") { relationKey<class EqpPartNoObject, class EqpPartNoLogObject>();}
    else if (entity == "RefLogAction" && relationEntiry == "EqpPartNoLog") { relationKey<class RefLogActionObject, class EqpPartNoLogObject>();}
    else if (entity == "QtyUnit" && relationEntiry == "EqpStock") { relationKey<class QtyUnitObject, class EqpStockObject>();}
    else if (entity == "EqpStock" && relationEntiry == "EqpStockPartNo") { relationKey<class EqpStockObject, class EqpStockPartNoObject>();}
    else if (entity == "EqpPartNo" && relationEntiry == "EqpStockPartNo") { relationKey<class EqpPartNoObject, class EqpStockPartNoObject>();}
    else if (entity == "EqpStock" && relationEntiry == "EqpStockLevel") { relationKey<class EqpStockObject, class EqpStockLevelObject>();}
    else if (entity == "Loc" && relationEntiry == "EqpStockLevel") { relationKey<class LocObject, class EqpStockLevelObject>();}
    else if (entity == "OwnerApp" && relationEntiry == "EqpStockLevel") { relationKey<class OwnerAppObject, class EqpStockLevelObject>();}
    else if (entity == "RefStockLowActn" && relationEntiry == "EqpStockLevel") { relationKey<class RefStockLowActnObject, class EqpStockLevelObject>();}
    else if (entity == "EqpAssmbl" && relationEntiry == "EqpZone") { relationKey<class EqpAssmblObject, class EqpZoneObject>();}
    else if (entity == "EqpAssmbl" && relationEntiry == "EqpPanel") { relationKey<class EqpAssmblObject, class EqpPanelObject>();}
    else if (entity == "EqpAssmbl" && relationEntiry == "EqpZonePanel") { relationKey<class EqpAssmblObject, class EqpZonePanelObject>();}
    else if (entity == "EqpZone" && relationEntiry == "EqpZonePanel") { relationKey<class EqpZoneObject, class EqpZonePanelObject>();}
    else if (entity == "EqpPanel" && relationEntiry == "EqpZonePanel") { relationKey<class EqpPanelObject, class EqpZonePanelObject>();}
    else if (entity == "TaskDefn" && relationEntiry == "TaskTask") { relationKey<class TaskDefnObject, class TaskTaskObject>();}
    else if (entity == "RefTaskDefStatus" && relationEntiry == "TaskTask") { relationKey<class RefTaskDefStatusObject, class TaskTaskObject>();}
    else if (entity == "TaskOriginator" && relationEntiry == "TaskTask") { relationKey<class TaskOriginatorObject, class TaskTaskObject>();}
    else if (entity == "RefTaskClass" && relationEntiry == "TaskTask") { relationKey<class RefTaskClassObject, class TaskTaskObject>();}
    else if (entity == "TaskSubclass" && relationEntiry == "TaskTask") { relationKey<class TaskSubclassObject, class TaskTaskObject>();}
    else if (entity == "RefFirstSchedFrom" && relationEntiry == "TaskTask") { relationKey<class RefFirstSchedFromObject, class TaskTaskObject>();}
    else if (entity == "RefReschedFrom" && relationEntiry == "TaskTask") { relationKey<class RefReschedFromObject, class TaskTaskObject>();}
    else if (entity == "RefCreateWhen" && relationEntiry == "TaskTask") { relationKey<class RefCreateWhenObject, class TaskTaskObject>();}
    else if (entity == "RefCancelWhen" && relationEntiry == "TaskTask") { relationKey<class RefCancelWhenObject, class TaskTaskObject>();}
    else if (entity == "UserApp" && relationEntiry == "TaskTask") { relationKey<class UserAppObject, class TaskTaskObject>();}
    else if (entity == "TaskTask" && relationEntiry == "TaskAssemblBom") { relationKey<class TaskTaskObject, class TaskAssemblBomObject>();}
    else if (entity == "EqpAssmblBom" && relationEntiry == "TaskAssemblBom") { relationKey<class EqpAssmblBomObject, class TaskAssemblBomObject>();}
    else if (entity == "EqpAssmbl" && relationEntiry == "TaskAssemblBom") { relationKey<class EqpAssmblObject, class TaskAssemblBomObject>();}
    else if (entity == "TaskTask" && relationEntiry == "TaskPartNo") { relationKey<class TaskTaskObject, class TaskPartNoObject>();}
    else if (entity == "EqpPartNo" && relationEntiry == "TaskPartNo") { relationKey<class EqpPartNoObject, class TaskPartNoObject>();}
    else if (entity == "Manufact" && relationEntiry == "TaskPartNo") { relationKey<class ManufactObject, class TaskPartNoObject>();}
    else if (entity == "TaskTask" && relationEntiry == "TaskAttachment") { relationKey<class TaskTaskObject, class TaskAttachmentObject>();}
    else if (entity == "RefFileSave" && relationEntiry == "TaskAttachment") { relationKey<class RefFileSaveObject, class TaskAttachmentObject>();}
    else if (entity == "TaskTask" && relationEntiry == "TaskFlags") { relationKey<class TaskTaskObject, class TaskFlagsObject>();}
    else if (entity == "TaskTask" && relationEntiry == "TaskNrEst") { relationKey<class TaskTaskObject, class TaskNrEstObject>();}
    else if (entity == "LabourSkill" && relationEntiry == "TaskNrEst") { relationKey<class LabourSkillObject, class TaskNrEstObject>();}
    else if (entity == "TaskTask" && relationEntiry == "TaskSchedRuleDef") { relationKey<class TaskTaskObject, class TaskSchedRuleDefObject>();}
    else if (entity == "DataType" && relationEntiry == "TaskSchedRuleDef") { relationKey<class DataTypeObject, class TaskSchedRuleDefObject>();}
    else if (entity == "TaskTask" && relationEntiry == "TaskSchedRulePart") { relationKey<class TaskTaskObject, class TaskSchedRulePartObject>();}
    else if (entity == "DataType" && relationEntiry == "TaskSchedRulePart") { relationKey<class DataTypeObject, class TaskSchedRulePartObject>();}
    else if (entity == "EqpPartNo" && relationEntiry == "TaskSchedRulePart") { relationKey<class EqpPartNoObject, class TaskSchedRulePartObject>();}
    else if (entity == "TaskTask" && relationEntiry == "TaskSchedRuleAc") { relationKey<class TaskTaskObject, class TaskSchedRuleAcObject>();}
    else if (entity == "DataType" && relationEntiry == "TaskSchedRuleAc") { relationKey<class DataTypeObject, class TaskSchedRuleAcObject>();}
    else if (entity == "InvInv" && relationEntiry == "TaskSchedRuleAc") { relationKey<class InvInvObject, class TaskSchedRuleAcObject>();}
    else if (entity == "TaskTask" && relationEntiry == "TaskSchedRuleMesur") { relationKey<class TaskTaskObject, class TaskSchedRuleMesurObject>();}
    else if (entity == "DataType" && relationEntiry == "TaskSchedRuleMesur") { relationKey<class DataTypeObject, class TaskSchedRuleMesurObject>();}
    else if (entity == "MesurUnit" && relationEntiry == "TaskSchedRuleMesur") { relationKey<class MesurUnitObject, class TaskSchedRuleMesurObject>();}
    else if (entity == "TaskTask" && relationEntiry == "TaskMesur") { relationKey<class TaskTaskObject, class TaskMesurObject>();}
    else if (entity == "MesurUnit" && relationEntiry == "TaskMesur") { relationKey<class MesurUnitObject, class TaskMesurObject>();}
    else if (entity == "TaskTask" && relationEntiry == "TaskZone") { relationKey<class TaskTaskObject, class TaskZoneObject>();}
    else if (entity == "EqpZone" && relationEntiry == "TaskZone") { relationKey<class EqpZoneObject, class TaskZoneObject>();}
    else if (entity == "TaskTask" && relationEntiry == "TaskPanel") { relationKey<class TaskTaskObject, class TaskPanelObject>();}
    else if (entity == "EqpPanel" && relationEntiry == "TaskPanel") { relationKey<class EqpPanelObject, class TaskPanelObject>();}
    else if (entity == "TaskTask" && relationEntiry == "TaskPartReq") { relationKey<class TaskTaskObject, class TaskPartReqObject>();}
    else if (entity == "EqpAssmbl" && relationEntiry == "TaskPartReq") { relationKey<class EqpAssmblObject, class TaskPartReqObject>();}
    else if (entity == "EqpAssmblBom" && relationEntiry == "TaskPartReq") { relationKey<class EqpAssmblBomObject, class TaskPartReqObject>();}
    else if (entity == "EqpAssmblBomPos" && relationEntiry == "TaskPartReq") { relationKey<class EqpAssmblBomPosObject, class TaskPartReqObject>();}
    else if (entity == "EqpPartNo" && relationEntiry == "TaskPartReq") { relationKey<class EqpPartNoObject, class TaskPartReqObject>();}
    else if (entity == "RefReqAction" && relationEntiry == "TaskPartReq") { relationKey<class RefReqActionObject, class TaskPartReqObject>();}
    else if (entity == "QtyUnit" && relationEntiry == "TaskPartReq") { relationKey<class QtyUnitObject, class TaskPartReqObject>();}
    else if (entity == "RefRemoveReason" && relationEntiry == "TaskPartReq") { relationKey<class RefRemoveReasonObject, class TaskPartReqObject>();}
    else if (entity == "RefReqPriority" && relationEntiry == "TaskPartReq") { relationKey<class RefReqPriorityObject, class TaskPartReqObject>();}
    else if (entity == "TaskTask" && relationEntiry == "TaskToolReq") { relationKey<class TaskTaskObject, class TaskToolReqObject>();}
    else if (entity == "EqpAssmbl" && relationEntiry == "TaskToolReq") { relationKey<class EqpAssmblObject, class TaskToolReqObject>();}
    else if (entity == "EqpAssmblBom" && relationEntiry == "TaskToolReq") { relationKey<class EqpAssmblBomObject, class TaskToolReqObject>();}
    else if (entity == "EqpPartNo" && relationEntiry == "TaskToolReq") { relationKey<class EqpPartNoObject, class TaskToolReqObject>();}
    else if (entity == "TaskTask" && relationEntiry == "TaskLabourReq") { relationKey<class TaskTaskObject, class TaskLabourReqObject>();}
    else if (entity == "LabourSkill" && relationEntiry == "TaskLabourReq") { relationKey<class LabourSkillObject, class TaskLabourReqObject>();}
    else if (entity == "License" && relationEntiry == "TaskLabourReq") { relationKey<class LicenseObject, class TaskLabourReqObject>();}
    else if (entity == "TaskTask" && relationEntiry == "TaskPartTransform") { relationKey<class TaskTaskObject, class TaskPartTransformObject>();}
    else if (entity == "EqpPartNo" && relationEntiry == "TaskPartTransform") { relationKey<class EqpPartNoObject, class TaskPartTransformObject>();}
    else if (entity == "TaskTask" && relationEntiry == "TaskRefDoc") { relationKey<class TaskTaskObject, class TaskRefDocObject>();}
    else if (entity == "Org" && relationEntiry == "TaskRefDoc") { relationKey<class OrgObject, class TaskRefDocObject>();}
    else if (entity == "RefDocIssueBy" && relationEntiry == "TaskRefDoc") { relationKey<class RefDocIssueByObject, class TaskRefDocObject>();}
    else if (entity == "RegBody" && relationEntiry == "TaskRefDoc") { relationKey<class RegBodyObject, class TaskRefDocObject>();}
    else if (entity == "Manufact" && relationEntiry == "TaskRefDoc") { relationKey<class ManufactObject, class TaskRefDocObject>();}
    else if (entity == "UserApp" && relationEntiry == "TaskRefDoc") { relationKey<class UserAppObject, class TaskRefDocObject>();}
    else if (entity == "RefDocDisposition" && relationEntiry == "TaskRefDoc") { relationKey<class RefDocDispositionObject, class TaskRefDocObject>();}
    else if (entity == "TaskTask" && relationEntiry == "TaskStep") { relationKey<class TaskTaskObject, class TaskStepObject>();}
    else if (entity == "TaskTask" && relationEntiry == "TaskFigure") { relationKey<class TaskTaskObject, class TaskFigureObject>();}
    else if (entity == "TaskTask" && relationEntiry == "TaskCompliance") { relationKey<class TaskTaskObject, class TaskComplianceObject>();}
    else if (entity == "TaskDefn" && relationEntiry == "TaskCompliance") { relationKey<class TaskDefnObject, class TaskComplianceObject>();}
    else if (entity == "TaskTask" && relationEntiry == "TaskTaskDep") { relationKey<class TaskTaskObject, class TaskTaskDepObject>();}
    else if (entity == "TaskDefn" && relationEntiry == "TaskTaskDep") { relationKey<class TaskDefnObject, class TaskTaskDepObject>();}
    else if (entity == "RefTaskDepAction" && relationEntiry == "TaskTaskDep") { relationKey<class RefTaskDepActionObject, class TaskTaskDepObject>();}
    else if (entity == "TaskTask" && relationEntiry == "TaskImpact") { relationKey<class TaskTaskObject, class TaskImpactObject>();}
    else if (entity == "MesurUnit" && relationEntiry == "TaskImpact") { relationKey<class MesurUnitObject, class TaskImpactObject>();}
    else if (entity == "RefMesurType" && relationEntiry == "TaskImpact") { relationKey<class RefMesurTypeObject, class TaskImpactObject>();}
    else if (entity == "TagTag" && relationEntiry == "TagTaskDefn") { relationKey<class TagTagObject, class TagTaskDefnObject>();}
    else if (entity == "TaskDefn" && relationEntiry == "TagTaskDefn") { relationKey<class TaskDefnObject, class TagTaskDefnObject>();}
    else if (entity == "TaskTask" && relationEntiry == "TaskJicReqMap") { relationKey<class TaskTaskObject, class TaskJicReqMapObject>();}
    else if (entity == "TaskDefn" && relationEntiry == "TaskJicReqMap") { relationKey<class TaskDefnObject, class TaskJicReqMapObject>();}
    else if (entity == "TaskTask" && relationEntiry == "TaskBlockReqMap") { relationKey<class TaskTaskObject, class TaskBlockReqMapObject>();}
    else if (entity == "TaskDefn" && relationEntiry == "TaskBlockReqMap") { relationKey<class TaskDefnObject, class TaskBlockReqMapObject>();}
    else if (entity == "RefAdvsryType" && relationEntiry == "Advsry") { relationKey<class RefAdvsryTypeObject, class AdvsryObject>();}
    else if (entity == "Advsry" && relationEntiry == "AdvsryAttachment") { relationKey<class AdvsryObject, class AdvsryAttachmentObject>();}
    else if (entity == "RefFileSave" && relationEntiry == "AdvsryAttachment") { relationKey<class RefFileSaveObject, class AdvsryAttachmentObject>();}
    else if (entity == "Advsry" && relationEntiry == "AdvsryPart") { relationKey<class AdvsryObject, class AdvsryPartObject>();}
    else if (entity == "Manufact" && relationEntiry == "AdvsryPart") { relationKey<class ManufactObject, class AdvsryPartObject>();}
    else if (entity == "EqpPartNo" && relationEntiry == "AdvsryPart") { relationKey<class EqpPartNoObject, class AdvsryPartObject>();}
    else if (entity == "Advsry" && relationEntiry == "AdvsryVendor") { relationKey<class AdvsryObject, class AdvsryVendorObject>();}
    else if (entity == "Vendor" && relationEntiry == "AdvsryVendor") { relationKey<class VendorObject, class AdvsryVendorObject>();}
    else if (entity == "Advsry" && relationEntiry == "AdvsryTask") { relationKey<class AdvsryObject, class AdvsryTaskObject>();}
    else if (entity == "TaskTask" && relationEntiry == "AdvsryTask") { relationKey<class TaskTaskObject, class AdvsryTaskObject>();}
    else if (entity == "AdvsryTask" && relationEntiry == "AdvsryTaskUser") { relationKey<class AdvsryTaskObject, class AdvsryTaskUserObject>();}
    else if (entity == "UserApp" && relationEntiry == "AdvsryTaskUser") { relationKey<class UserAppObject, class AdvsryTaskUserObject>();}
    else if (entity == "AdvsryTask" && relationEntiry == "AdvsryTaskRole") { relationKey<class AdvsryTaskObject, class AdvsryTaskRoleObject>();}
    else if (entity == "RoleApp" && relationEntiry == "AdvsryTaskRole") { relationKey<class RoleAppObject, class AdvsryTaskRoleObject>();}
    else if (entity == "AdvsryTask" && relationEntiry == "AdvsryTaskDept") { relationKey<class AdvsryTaskObject, class AdvsryTaskDeptObject>();}
    else if (entity == "Dept" && relationEntiry == "AdvsryTaskDept") { relationKey<class DeptObject, class AdvsryTaskDeptObject>();}
    else if (entity == "TaskTask" && relationEntiry == "TaskTaskLog") { relationKey<class TaskTaskObject, class TaskTaskLogObject>();}
    else if (entity == "RefLogAction" && relationEntiry == "TaskTaskLog") { relationKey<class RefLogActionObject, class TaskTaskLogObject>();}
    else if (entity == "TaskTask" && relationEntiry == "TaskLabourSummary") { relationKey<class TaskTaskObject, class TaskLabourSummaryObject>();}
    else if (entity == "TaskDefn" && relationEntiry == "TaskLabourSummary") { relationKey<class TaskDefnObject, class TaskLabourSummaryObject>();}
    else if (entity == "SchedStask" && relationEntiry == "TaskLabourSummary") { relationKey<class SchedStaskObject, class TaskLabourSummaryObject>();}
    else if (entity == "LabourSkill" && relationEntiry == "TaskLabourSummary") { relationKey<class LabourSkillObject, class TaskLabourSummaryObject>();}
    else if (entity == "MaintPrgmDefn" && relationEntiry == "MaintPrgm") { relationKey<class MaintPrgmDefnObject, class MaintPrgmObject>();}
    else if (entity == "RefMaintPrgmStatus" && relationEntiry == "MaintPrgm") { relationKey<class RefMaintPrgmStatusObject, class MaintPrgmObject>();}
    else if (entity == "UserApp" && relationEntiry == "MaintPrgm") { relationKey<class UserAppObject, class MaintPrgmObject>();}
    else if (entity == "MaintPrgm" && relationEntiry == "MaintPrgmTask") { relationKey<class MaintPrgmObject, class MaintPrgmTaskObject>();}
    else if (entity == "TaskDefn" && relationEntiry == "MaintPrgmTask") { relationKey<class TaskDefnObject, class MaintPrgmTaskObject>();}
    else if (entity == "TaskTask" && relationEntiry == "MaintPrgmTask") { relationKey<class TaskTaskObject, class MaintPrgmTaskObject>();}
    else if (entity == "UserApp" && relationEntiry == "MaintPrgmTask") { relationKey<class UserAppObject, class MaintPrgmTaskObject>();}
    else if (entity == "MaintPrgm" && relationEntiry == "MaintPrgmCarrierMap") { relationKey<class MaintPrgmObject, class MaintPrgmCarrierMapObject>();}
    else if (entity == "Carrier" && relationEntiry == "MaintPrgmCarrierMap") { relationKey<class CarrierObject, class MaintPrgmCarrierMapObject>();}
    else if (entity == "MaintPrgmDefn" && relationEntiry == "MaintPrgmCarrierTempTask") { relationKey<class MaintPrgmDefnObject, class MaintPrgmCarrierTempTaskObject>();}
    else if (entity == "TaskDefn" && relationEntiry == "MaintPrgmCarrierTempTask") { relationKey<class TaskDefnObject, class MaintPrgmCarrierTempTaskObject>();}
    else if (entity == "TaskTask" && relationEntiry == "MaintPrgmCarrierTempTask") { relationKey<class TaskTaskObject, class MaintPrgmCarrierTempTaskObject>();}
    else if (entity == "Carrier" && relationEntiry == "MaintPrgmCarrierTempTask") { relationKey<class CarrierObject, class MaintPrgmCarrierTempTaskObject>();}
    else if (entity == "MaintPrgm" && relationEntiry == "MaintPrgmTaskTempIssueLog") { relationKey<class MaintPrgmObject, class MaintPrgmTaskTempIssueLogObject>();}
    else if (entity == "TaskTask" && relationEntiry == "MaintPrgmTaskTempIssueLog") { relationKey<class TaskTaskObject, class MaintPrgmTaskTempIssueLogObject>();}
    else if (entity == "UserApp" && relationEntiry == "MaintPrgmTaskTempIssueLog") { relationKey<class UserAppObject, class MaintPrgmTaskTempIssueLogObject>();}
    else if (entity == "MaintPrgm" && relationEntiry == "MaintPrgmLog") { relationKey<class MaintPrgmObject, class MaintPrgmLogObject>();}
    else if (entity == "RefLogAction" && relationEntiry == "MaintPrgmLog") { relationKey<class RefLogActionObject, class MaintPrgmLogObject>();}
    else if (entity == "RefWorkpackageType" && relationEntiry == "WorkpackageBuilder") { relationKey<class RefWorkpackageTypeObject, class WorkpackageBuilderObject>();}
    else if (entity == "TaskTask" && relationEntiry == "WorkpackageBuilder") { relationKey<class TaskTaskObject, class WorkpackageBuilderObject>();}
    else if (entity == "EqpAssmbl" && relationEntiry == "WorkpackageBuilder") { relationKey<class EqpAssmblObject, class WorkpackageBuilderObject>();}
    else if (entity == "EqpPartNo" && relationEntiry == "WorkpackageBuilder") { relationKey<class EqpPartNoObject, class WorkpackageBuilderObject>();}
    else if (entity == "SchedStask" && relationEntiry == "SchedStask") { relationKey<class SchedStaskObject, class SchedStaskObject>();}
    else if (entity == "TaskTask" && relationEntiry == "SchedStask") { relationKey<class TaskTaskObject, class SchedStaskObject>();}
    else if (entity == "EqpPartNo" && relationEntiry == "SchedStask") { relationKey<class EqpPartNoObject, class SchedStaskObject>();}
    else if (entity == "RefTaskClass" && relationEntiry == "SchedStask") { relationKey<class RefTaskClassObject, class SchedStaskObject>();}
    else if (entity == "TaskSubclass" && relationEntiry == "SchedStask") { relationKey<class TaskSubclassObject, class SchedStaskObject>();}
    else if (entity == "TaskOriginator" && relationEntiry == "SchedStask") { relationKey<class TaskOriginatorObject, class SchedStaskObject>();}
    else if (entity == "InvInv" && relationEntiry == "SchedStask") { relationKey<class InvInvObject, class SchedStaskObject>();}
    else if (entity == "RefFirstSchedFrom" && relationEntiry == "SchedStask") { relationKey<class RefFirstSchedFromObject, class SchedStaskObject>();}
    else if (entity == "RefCancelWhen" && relationEntiry == "SchedStask") { relationKey<class RefCancelWhenObject, class SchedStaskObject>();}
    else if (entity == "RefReschedFrom" && relationEntiry == "SchedStask") { relationKey<class RefReschedFromObject, class SchedStaskObject>();}
    else if (entity == "FncAccount" && relationEntiry == "SchedStask") { relationKey<class FncAccountObject, class SchedStaskObject>();}
    else if (entity == "SchedStask" && relationEntiry == "SchedStaskFlags") { relationKey<class SchedStaskObject, class SchedStaskFlagsObject>();}
    else if (entity == "SchedStask" && relationEntiry == "SchedTaskDeadlineExt") { relationKey<class SchedStaskObject, class SchedTaskDeadlineExtObject>();}
    else if (entity == "DataType" && relationEntiry == "SchedTaskDeadlineExt") { relationKey<class DataTypeObject, class SchedTaskDeadlineExtObject>();}
    else if (entity == "SchedStask" && relationEntiry == "SchedImpact") { relationKey<class SchedStaskObject, class SchedImpactObject>();}
    else if (entity == "RefMesurType" && relationEntiry == "SchedImpact") { relationKey<class RefMesurTypeObject, class SchedImpactObject>();}
    else if (entity == "MesurUnit" && relationEntiry == "SchedImpact") { relationKey<class MesurUnitObject, class SchedImpactObject>();}
    else if (entity == "SchedStask" && relationEntiry == "SchedZone") { relationKey<class SchedStaskObject, class SchedZoneObject>();}
    else if (entity == "EqpAssmbl" && relationEntiry == "SchedZone") { relationKey<class EqpAssmblObject, class SchedZoneObject>();}
    else if (entity == "EqpZone" && relationEntiry == "SchedZone") { relationKey<class EqpZoneObject, class SchedZoneObject>();}
    else if (entity == "SchedStask" && relationEntiry == "SchedPanel") { relationKey<class SchedStaskObject, class SchedPanelObject>();}
    else if (entity == "EqpAssmbl" && relationEntiry == "SchedPanel") { relationKey<class EqpAssmblObject, class SchedPanelObject>();}
    else if (entity == "EqpPanel" && relationEntiry == "SchedPanel") { relationKey<class EqpPanelObject, class SchedPanelObject>();}
    else if (entity == "SchedStask" && relationEntiry == "SchedPart") { relationKey<class SchedStaskObject, class SchedPartObject>();}
    else if (entity == "EqpAssmbl" && relationEntiry == "SchedPart") { relationKey<class EqpAssmblObject, class SchedPartObject>();}
    else if (entity == "EqpAssmblBom" && relationEntiry == "SchedPart") { relationKey<class EqpAssmblBomObject, class SchedPartObject>();}
    else if (entity == "EqpPartNo" && relationEntiry == "SchedPart") { relationKey<class EqpPartNoObject, class SchedPartObject>();}
    else if (entity == "EqpAssmblBomPos" && relationEntiry == "SchedPart") { relationKey<class EqpAssmblBomPosObject, class SchedPartObject>();}
    else if (entity == "RefReqAction" && relationEntiry == "SchedPart") { relationKey<class RefReqActionObject, class SchedPartObject>();}
    else if (entity == "RefPartStatus" && relationEntiry == "SchedPart") { relationKey<class RefPartStatusObject, class SchedPartObject>();}
    else if (entity == "SchedPart" && relationEntiry == "SchedRmvdPart") { relationKey<class SchedPartObject, class SchedRmvdPartObject>();}
    else if (entity == "InvInv" && relationEntiry == "SchedRmvdPart") { relationKey<class InvInvObject, class SchedRmvdPartObject>();}
    else if (entity == "EqpPartNo" && relationEntiry == "SchedRmvdPart") { relationKey<class EqpPartNoObject, class SchedRmvdPartObject>();}
    else if (entity == "RefRemoveReason" && relationEntiry == "SchedRmvdPart") { relationKey<class RefRemoveReasonObject, class SchedRmvdPartObject>();}
    else if (entity == "UserApp" && relationEntiry == "SchedRmvdPart") { relationKey<class UserAppObject, class SchedRmvdPartObject>();}
    else if (entity == "SchedPart" && relationEntiry == "SchedInstPart") { relationKey<class SchedPartObject, class SchedInstPartObject>();}
    else if (entity == "InvInv" && relationEntiry == "SchedInstPart") { relationKey<class InvInvObject, class SchedInstPartObject>();}
    else if (entity == "EqpPartNo" && relationEntiry == "SchedInstPart") { relationKey<class EqpPartNoObject, class SchedInstPartObject>();}
    else if (entity == "UserApp" && relationEntiry == "SchedInstPart") { relationKey<class UserAppObject, class SchedInstPartObject>();}
    else if (entity == "SchedStask" && relationEntiry == "SchedTool") { relationKey<class SchedStaskObject, class SchedToolObject>();}
    else if (entity == "EqpAssmbl" && relationEntiry == "SchedTool") { relationKey<class EqpAssmblObject, class SchedToolObject>();}
    else if (entity == "EqpAssmblBom" && relationEntiry == "SchedTool") { relationKey<class EqpAssmblBomObject, class SchedToolObject>();}
    else if (entity == "EqpPartNo" && relationEntiry == "SchedTool") { relationKey<class EqpPartNoObject, class SchedToolObject>();}
    else if (entity == "UserApp" && relationEntiry == "SchedTool") { relationKey<class UserAppObject, class SchedToolObject>();}
    else if (entity == "SchedStask" && relationEntiry == "SchedLabour") { relationKey<class SchedStaskObject, class SchedLabourObject>();}
    else if (entity == "LabourSkill" && relationEntiry == "SchedLabour") { relationKey<class LabourSkillObject, class SchedLabourObject>();}
    else if (entity == "RefLabourStage" && relationEntiry == "SchedLabour") { relationKey<class RefLabourStageObject, class SchedLabourObject>();}
    else if (entity == "SchedLabour" && relationEntiry == "SchedLabourSched") { relationKey<class SchedLabourObject, class SchedLabourSchedObject>();}
    else if (entity == "RefLabourRoleType" && relationEntiry == "SchedLabourSched") { relationKey<class RefLabourRoleTypeObject, class SchedLabourSchedObject>();}
    else if (entity == "UserApp" && relationEntiry == "SchedLabourSched") { relationKey<class UserAppObject, class SchedLabourSchedObject>();}
    else if (entity == "RefLabourRoleStatus" && relationEntiry == "SchedLabourSched") { relationKey<class RefLabourRoleStatusObject, class SchedLabourSchedObject>();}
    else if (entity == "SchedLabour" && relationEntiry == "SchedLabourActual") { relationKey<class SchedLabourObject, class SchedLabourActualObject>();}
    else if (entity == "RefLabourRoleType" && relationEntiry == "SchedLabourActual") { relationKey<class RefLabourRoleTypeObject, class SchedLabourActualObject>();}
    else if (entity == "UserApp" && relationEntiry == "SchedLabourActual") { relationKey<class UserAppObject, class SchedLabourActualObject>();}
    else if (entity == "SchedStask" && relationEntiry == "SchedStep") { relationKey<class SchedStaskObject, class SchedStepObject>();}
    else if (entity == "TaskStep" && relationEntiry == "SchedStep") { relationKey<class TaskStepObject, class SchedStepObject>();}
    else if (entity == "SchedStep" && relationEntiry == "SchedStepLabour") { relationKey<class SchedStepObject, class SchedStepLabourObject>();}
    else if (entity == "RefLabourRoleType" && relationEntiry == "SchedStepLabour") { relationKey<class RefLabourRoleTypeObject, class SchedStepLabourObject>();}
    else if (entity == "UserApp" && relationEntiry == "SchedStepLabour") { relationKey<class UserAppObject, class SchedStepLabourObject>();}
    else if (entity == "SchedStask" && relationEntiry == "SchedFigure") { relationKey<class SchedStaskObject, class SchedFigureObject>();}
    else if (entity == "TaskFigure" && relationEntiry == "SchedFigure") { relationKey<class TaskFigureObject, class SchedFigureObject>();}
    else if (entity == "SchedStask" && relationEntiry == "SchedWp") { relationKey<class SchedStaskObject, class SchedWpObject>();}
    else if (entity == "RefReceiveCond" && relationEntiry == "SchedWp") { relationKey<class RefReceiveCondObject, class SchedWpObject>();}
    else if (entity == "UserApp" && relationEntiry == "SchedWp") { relationKey<class UserAppObject, class SchedWpObject>();}
    else if (entity == "SchedWp" && relationEntiry == "SchedWpWorkType") { relationKey<class SchedWpObject, class SchedWpWorkTypeObject>();}
    else if (entity == "WorkType" && relationEntiry == "SchedWpWorkType") { relationKey<class WorkTypeObject, class SchedWpWorkTypeObject>();}
    else if (entity == "SchedWp" && relationEntiry == "SchedWpMpc") { relationKey<class SchedWpObject, class SchedWpMpcObject>();}
    else if (entity == "TaskTask" && relationEntiry == "SchedWpMpc") { relationKey<class TaskTaskObject, class SchedWpMpcObject>();}
    else if (entity == "SchedWp" && relationEntiry == "SchedWpLine") { relationKey<class SchedWpObject, class SchedWpLineObject>();}
    else if (entity == "SchedStask" && relationEntiry == "SchedWpLine") { relationKey<class SchedStaskObject, class SchedWpLineObject>();}
    else if (entity == "UserApp" && relationEntiry == "SchedWpLine") { relationKey<class UserAppObject, class SchedWpLineObject>();}
    else if (entity == "SchedWp" && relationEntiry == "SchedWpSign") { relationKey<class SchedWpObject, class SchedWpSignObject>();}
    else if (entity == "UserApp" && relationEntiry == "SchedWpSign") { relationKey<class UserAppObject, class SchedWpSignObject>();}
    else if (entity == "SchedStask" && relationEntiry == "SchedAttachment") { relationKey<class SchedStaskObject, class SchedAttachmentObject>();}
    else if (entity == "RefFileSave" && relationEntiry == "SchedAttachment") { relationKey<class RefFileSaveObject, class SchedAttachmentObject>();}
    else if (entity == "SchedWp" && relationEntiry == "SchedWpCostLineItem") { relationKey<class SchedWpObject, class SchedWpCostLineItemObject>();}
    else if (entity == "RefCostLineItemType" && relationEntiry == "SchedWpCostLineItem") { relationKey<class RefCostLineItemTypeObject, class SchedWpCostLineItemObject>();}
    else if (entity == "Currency" && relationEntiry == "SchedWpCostLineItem") { relationKey<class CurrencyObject, class SchedWpCostLineItemObject>();}
    else if (entity == "PoInvoice" && relationEntiry == "SchedWpCostLineItem") { relationKey<class PoInvoiceObject, class SchedWpCostLineItemObject>();}
    else if (entity == "RefPoType" && relationEntiry == "PoHeader") { relationKey<class RefPoTypeObject, class PoHeaderObject>();}
    else if (entity == "RefReqPriority" && relationEntiry == "PoHeader") { relationKey<class RefReqPriorityObject, class PoHeaderObject>();}
    else if (entity == "RefReqType" && relationEntiry == "PoHeader") { relationKey<class RefReqTypeObject, class PoHeaderObject>();}
    else if (entity == "Vendor" && relationEntiry == "PoHeader") { relationKey<class VendorObject, class PoHeaderObject>();}
    else if (entity == "FncAccount" && relationEntiry == "PoHeader") { relationKey<class FncAccountObject, class PoHeaderObject>();}
    else if (entity == "Currency" && relationEntiry == "PoHeader") { relationKey<class CurrencyObject, class PoHeaderObject>();}
    else if (entity == "RefBorrowRate" && relationEntiry == "PoHeader") { relationKey<class RefBorrowRateObject, class PoHeaderObject>();}
    else if (entity == "RefPaymentTerms" && relationEntiry == "PoHeader") { relationKey<class RefPaymentTermsObject, class PoHeaderObject>();}
    else if (entity == "RefTradeTerms" && relationEntiry == "PoHeader") { relationKey<class RefTradeTermsObject, class PoHeaderObject>();}
    else if (entity == "Loc" && relationEntiry == "PoHeader") { relationKey<class LocObject, class PoHeaderObject>();}
    else if (entity == "Transportor" && relationEntiry == "PoHeader") { relationKey<class TransportorObject, class PoHeaderObject>();}
    else if (entity == "Org" && relationEntiry == "PoHeader") { relationKey<class OrgObject, class PoHeaderObject>();}
    else if (entity == "UserApp" && relationEntiry == "PoHeader") { relationKey<class UserAppObject, class PoHeaderObject>();}
    else if (entity == "PoHeader" && relationEntiry == "PoAttachment") { relationKey<class PoHeaderObject, class PoAttachmentObject>();}
    else if (entity == "RefFileSave" && relationEntiry == "PoAttachment") { relationKey<class RefFileSaveObject, class PoAttachmentObject>();}
    else if (entity == "PoHeader" && relationEntiry == "PoLine") { relationKey<class PoHeaderObject, class PoLineObject>();}
    else if (entity == "EqpPartNo" && relationEntiry == "PoLine") { relationKey<class EqpPartNoObject, class PoLineObject>();}
    else if (entity == "RefPoLineType" && relationEntiry == "PoLine") { relationKey<class RefPoLineTypeObject, class PoLineObject>();}
    else if (entity == "QtyUnit" && relationEntiry == "PoLine") { relationKey<class QtyUnitObject, class PoLineObject>();}
    else if (entity == "RefPriceType" && relationEntiry == "PoLine") { relationKey<class RefPriceTypeObject, class PoLineObject>();}
    else if (entity == "OwnerApp" && relationEntiry == "PoLine") { relationKey<class OwnerAppObject, class PoLineObject>();}
    else if (entity == "SchedStask" && relationEntiry == "PoLine") { relationKey<class SchedStaskObject, class PoLineObject>();}
    else if (entity == "ShipShipment" && relationEntiry == "PoLine") { relationKey<class ShipShipmentObject, class PoLineObject>();}
    else if (entity == "PoLine" && relationEntiry == "PoLineDoc") { relationKey<class PoLineObject, class PoLineDocObject>();}
    else if (entity == "RegBodyDoc" && relationEntiry == "PoLineDoc") { relationKey<class RegBodyDocObject, class PoLineDocObject>();}
    else if (entity == "PoLine" && relationEntiry == "PoLineKitLine") { relationKey<class PoLineObject, class PoLineKitLineObject>();}
    else if (entity == "EqpKitPartNo" && relationEntiry == "PoLineKitLine") { relationKey<class EqpKitPartNoObject, class PoLineKitLineObject>();}
    else if (entity == "PoLine" && relationEntiry == "PoLineReturnMap") { relationKey<class PoLineObject, class PoLineReturnMapObject>();}
    else if (entity == "InvInv" && relationEntiry == "PoLineReturnMap") { relationKey<class InvInvObject, class PoLineReturnMapObject>();}
    else if (entity == "PoLine" && relationEntiry == "PoLineCharge") { relationKey<class PoLineObject, class PoLineChargeObject>();}
    else if (entity == "Charge" && relationEntiry == "PoLineCharge") { relationKey<class ChargeObject, class PoLineChargeObject>();}
    else if (entity == "PoLine" && relationEntiry == "PoLineTax") { relationKey<class PoLineObject, class PoLineTaxObject>();}
    else if (entity == "Tax" && relationEntiry == "PoLineTax") { relationKey<class TaxObject, class PoLineTaxObject>();}
    else if (entity == "PoLine" && relationEntiry == "PoLineWarranty") { relationKey<class PoLineObject, class PoLineWarrantyObject>();}
    else if (entity == "WarrantyDefn" && relationEntiry == "PoLineWarranty") { relationKey<class WarrantyDefnObject, class PoLineWarrantyObject>();}
    else if (entity == "PoHeader" && relationEntiry == "PoAuth") { relationKey<class PoHeaderObject, class PoAuthObject>();}
    else if (entity == "UserApp" && relationEntiry == "PoAuth") { relationKey<class UserAppObject, class PoAuthObject>();}
    else if (entity == "Vendor" && relationEntiry == "PoInvoice") { relationKey<class VendorObject, class PoInvoiceObject>();}
    else if (entity == "FncAccount" && relationEntiry == "PoInvoice") { relationKey<class FncAccountObject, class PoInvoiceObject>();}
    else if (entity == "Currency" && relationEntiry == "PoInvoice") { relationKey<class CurrencyObject, class PoInvoiceObject>();}
    else if (entity == "RefPaymentTerms" && relationEntiry == "PoInvoice") { relationKey<class RefPaymentTermsObject, class PoInvoiceObject>();}
    else if (entity == "UserApp" && relationEntiry == "PoInvoice") { relationKey<class UserAppObject, class PoInvoiceObject>();}
    else if (entity == "PoInvoice" && relationEntiry == "PoInvoiceAttachment") { relationKey<class PoInvoiceObject, class PoInvoiceAttachmentObject>();}
    else if (entity == "RefFileSave" && relationEntiry == "PoInvoiceAttachment") { relationKey<class RefFileSaveObject, class PoInvoiceAttachmentObject>();}
    else if (entity == "PoInvoice" && relationEntiry == "PoInvoiceLine") { relationKey<class PoInvoiceObject, class PoInvoiceLineObject>();}
    else if (entity == "EqpPartNo" && relationEntiry == "PoInvoiceLine") { relationKey<class EqpPartNoObject, class PoInvoiceLineObject>();}
    else if (entity == "QtyUnit" && relationEntiry == "PoInvoiceLine") { relationKey<class QtyUnitObject, class PoInvoiceLineObject>();}
    else if (entity == "FncAccount" && relationEntiry == "PoInvoiceLine") { relationKey<class FncAccountObject, class PoInvoiceLineObject>();}
    else if (entity == "PoInvoiceLine" && relationEntiry == "PoInvoiceLineCharge") { relationKey<class PoInvoiceLineObject, class PoInvoiceLineChargeObject>();}
    else if (entity == "Charge" && relationEntiry == "PoInvoiceLineCharge") { relationKey<class ChargeObject, class PoInvoiceLineChargeObject>();}
    else if (entity == "PoInvoiceLine" && relationEntiry == "PoInvoiceLineTax") { relationKey<class PoInvoiceLineObject, class PoInvoiceLineTaxObject>();}
    else if (entity == "Tax" && relationEntiry == "PoInvoiceLineTax") { relationKey<class TaxObject, class PoInvoiceLineTaxObject>();}
    else if (entity == "PoHeader" && relationEntiry == "PoInvoiceLineMap") { relationKey<class PoHeaderObject, class PoInvoiceLineMapObject>();}
    else if (entity == "PoLine" && relationEntiry == "PoInvoiceLineMap") { relationKey<class PoLineObject, class PoInvoiceLineMapObject>();}
    else if (entity == "PoInvoice" && relationEntiry == "PoInvoiceLineMap") { relationKey<class PoInvoiceObject, class PoInvoiceLineMapObject>();}
    else if (entity == "PoInvoiceLine" && relationEntiry == "PoInvoiceLineMap") { relationKey<class PoInvoiceLineObject, class PoInvoiceLineMapObject>();}
    else if (entity == "RefShipmentType" && relationEntiry == "ShipShipment") { relationKey<class RefShipmentTypeObject, class ShipShipmentObject>();}
    else if (entity == "Transportor" && relationEntiry == "ShipShipment") { relationKey<class TransportorObject, class ShipShipmentObject>();}
    else if (entity == "Org" && relationEntiry == "ShipShipment") { relationKey<class OrgObject, class ShipShipmentObject>();}
    else if (entity == "MesurUnit" && relationEntiry == "ShipShipment") { relationKey<class MesurUnitObject, class ShipShipmentObject>();}
    else if (entity == "PoHeader" && relationEntiry == "ShipShipment") { relationKey<class PoHeaderObject, class ShipShipmentObject>();}
    else if (entity == "SchedStask" && relationEntiry == "ShipShipment") { relationKey<class SchedStaskObject, class ShipShipmentObject>();}
    else if (entity == "FncAccount" && relationEntiry == "ShipShipment") { relationKey<class FncAccountObject, class ShipShipmentObject>();}
    else if (entity == "ShipShipment" && relationEntiry == "ShipShipmentLine") { relationKey<class ShipShipmentObject, class ShipShipmentLineObject>();}
    else if (entity == "PoHeader" && relationEntiry == "ShipShipmentLine") { relationKey<class PoHeaderObject, class ShipShipmentLineObject>();}
    else if (entity == "PoLine" && relationEntiry == "ShipShipmentLine") { relationKey<class PoLineObject, class ShipShipmentLineObject>();}
    else if (entity == "EqpPartNo" && relationEntiry == "ShipShipmentLine") { relationKey<class EqpPartNoObject, class ShipShipmentLineObject>();}
    else if (entity == "RefInvCond" && relationEntiry == "ShipShipmentLine") { relationKey<class RefInvCondObject, class ShipShipmentLineObject>();}
    else if (entity == "InvInv" && relationEntiry == "ShipShipmentLine") { relationKey<class InvInvObject, class ShipShipmentLineObject>();}
    else if (entity == "RefReceivePriority" && relationEntiry == "ShipShipmentLine") { relationKey<class RefReceivePriorityObject, class ShipShipmentLineObject>();}
    else if (entity == "ShipShipmentLine" && relationEntiry == "ShipShipmentLineDoc") { relationKey<class ShipShipmentLineObject, class ShipShipmentLineDocObject>();}
    else if (entity == "RegBodyDoc" && relationEntiry == "ShipShipmentLineDoc") { relationKey<class RegBodyDocObject, class ShipShipmentLineDocObject>();}
    else if (entity == "ShipShipment" && relationEntiry == "ShipSegment") { relationKey<class ShipShipmentObject, class ShipSegmentObject>();}
    else if (entity == "RefSegmentStatus" && relationEntiry == "ShipSegment") { relationKey<class RefSegmentStatusObject, class ShipSegmentObject>();}
    else if (entity == "Loc" && relationEntiry == "ShipSegment") { relationKey<class LocObject, class ShipSegmentObject>();}
    else if (entity == "UserApp" && relationEntiry == "ShipSegment") { relationKey<class UserAppObject, class ShipSegmentObject>();}
    else if (entity == "UserApp" && relationEntiry == "RfqHeader") { relationKey<class UserAppObject, class RfqHeaderObject>();}
    else if (entity == "RfqHeader" && relationEntiry == "RfqAttachment") { relationKey<class RfqHeaderObject, class RfqAttachmentObject>();}
    else if (entity == "RefFileSave" && relationEntiry == "RfqAttachment") { relationKey<class RefFileSaveObject, class RfqAttachmentObject>();}
    else if (entity == "RfqHeader" && relationEntiry == "RfqLine") { relationKey<class RfqHeaderObject, class RfqLineObject>();}
    else if (entity == "QtyUnit" && relationEntiry == "RfqLine") { relationKey<class QtyUnitObject, class RfqLineObject>();}
    else if (entity == "Loc" && relationEntiry == "RfqLine") { relationKey<class LocObject, class RfqLineObject>();}
    else if (entity == "EqpPartNo" && relationEntiry == "RfqLine") { relationKey<class EqpPartNoObject, class RfqLineObject>();}
    else if (entity == "RefReqPriority" && relationEntiry == "RfqLine") { relationKey<class RefReqPriorityObject, class RfqLineObject>();}
    else if (entity == "PoHeader" && relationEntiry == "RfqLine") { relationKey<class PoHeaderObject, class RfqLineObject>();}
    else if (entity == "PoLine" && relationEntiry == "RfqLine") { relationKey<class PoLineObject, class RfqLineObject>();}
    else if (entity == "RfqHeader" && relationEntiry == "RfqVendor") { relationKey<class RfqHeaderObject, class RfqVendorObject>();}
    else if (entity == "Vendor" && relationEntiry == "RfqVendor") { relationKey<class VendorObject, class RfqVendorObject>();}
    else if (entity == "Currency" && relationEntiry == "RfqVendor") { relationKey<class CurrencyObject, class RfqVendorObject>();}
    else if (entity == "Transportor" && relationEntiry == "RfqVendor") { relationKey<class TransportorObject, class RfqVendorObject>();}
    else if (entity == "RefPaymentTerms" && relationEntiry == "RfqVendor") { relationKey<class RefPaymentTermsObject, class RfqVendorObject>();}
    else if (entity == "RefTradeTerms" && relationEntiry == "RfqVendor") { relationKey<class RefTradeTermsObject, class RfqVendorObject>();}
    else if (entity == "RfqVendor" && relationEntiry == "RfqLineVendor") { relationKey<class RfqVendorObject, class RfqLineVendorObject>();}
    else if (entity == "RfqLine" && relationEntiry == "RfqLineVendor") { relationKey<class RfqLineObject, class RfqLineVendorObject>();}
    else if (entity == "EqpPartNo" && relationEntiry == "RfqLineVendor") { relationKey<class EqpPartNoObject, class RfqLineVendorObject>();}
    else if (entity == "RefReceiveCond" && relationEntiry == "RfqLineVendor") { relationKey<class RefReceiveCondObject, class RfqLineVendorObject>();}
    else if (entity == "QtyUnit" && relationEntiry == "RfqLineVendor") { relationKey<class QtyUnitObject, class RfqLineVendorObject>();}
    else if (entity == "RfqLineVendor" && relationEntiry == "RfqLineVendorCharge") { relationKey<class RfqLineVendorObject, class RfqLineVendorChargeObject>();}
    else if (entity == "Charge" && relationEntiry == "RfqLineVendorCharge") { relationKey<class ChargeObject, class RfqLineVendorChargeObject>();}
    else if (entity == "RfqLineVendor" && relationEntiry == "RfqLineVendorTax") { relationKey<class RfqLineVendorObject, class RfqLineVendorTaxObject>();}
    else if (entity == "Tax" && relationEntiry == "RfqLineVendorTax") { relationKey<class TaxObject, class RfqLineVendorTaxObject>();}
    else if (entity == "RefReqType" && relationEntiry == "ReqPart") { relationKey<class RefReqTypeObject, class ReqPartObject>();}
    else if (entity == "RefReqPriority" && relationEntiry == "ReqPart") { relationKey<class RefReqPriorityObject, class ReqPartObject>();}
    else if (entity == "EqpPartNo" && relationEntiry == "ReqPart") { relationKey<class EqpPartNoObject, class ReqPartObject>();}
    else if (entity == "EqpAssmbl" && relationEntiry == "ReqPart") { relationKey<class EqpAssmblObject, class ReqPartObject>();}
    else if (entity == "EqpAssmblBom" && relationEntiry == "ReqPart") { relationKey<class EqpAssmblBomObject, class ReqPartObject>();}
    else if (entity == "EqpStock" && relationEntiry == "ReqPart") { relationKey<class EqpStockObject, class ReqPartObject>();}
    else if (entity == "Loc" && relationEntiry == "ReqPart") { relationKey<class LocObject, class ReqPartObject>();}
    else if (entity == "InvInv" && relationEntiry == "ReqPart") { relationKey<class InvInvObject, class ReqPartObject>();}
    else if (entity == "RefPartProviderType" && relationEntiry == "ReqPart") { relationKey<class RefPartProviderTypeObject, class ReqPartObject>();}
    else if (entity == "FncAccount" && relationEntiry == "ReqPart") { relationKey<class FncAccountObject, class ReqPartObject>();}
    else if (entity == "SchedStask" && relationEntiry == "ReqPart") { relationKey<class SchedStaskObject, class ReqPartObject>();}
    else if (entity == "SchedInstPart" && relationEntiry == "ReqPart") { relationKey<class SchedInstPartObject, class ReqPartObject>();}
    else if (entity == "SchedPart" && relationEntiry == "ReqPart") { relationKey<class SchedPartObject, class ReqPartObject>();}
    else if (entity == "ShipShipmentLine" && relationEntiry == "ReqPart") { relationKey<class ShipShipmentLineObject, class ReqPartObject>();}
    else if (entity == "PoHeader" && relationEntiry == "ReqPart") { relationKey<class PoHeaderObject, class ReqPartObject>();}
    else if (entity == "PoLine" && relationEntiry == "ReqPart") { relationKey<class PoLineObject, class ReqPartObject>();}
    else if (entity == "Vendor" && relationEntiry == "ReqPart") { relationKey<class VendorObject, class ReqPartObject>();}
    else if (entity == "UserApp" && relationEntiry == "ReqPart") { relationKey<class UserAppObject, class ReqPartObject>();}
    else if (entity == "UserApp" && relationEntiry == "QuarQuar") { relationKey<class UserAppObject, class QuarQuarObject>();}
    else if (entity == "InvInv" && relationEntiry == "QuarQuar") { relationKey<class InvInvObject, class QuarQuarObject>();}
    else if (entity == "Loc" && relationEntiry == "QuarQuar") { relationKey<class LocObject, class QuarQuarObject>();}
    else if (entity == "QuarQuar" && relationEntiry == "QuarAction") { relationKey<class QuarQuarObject, class QuarActionObject>();}
    else if (entity == "UserApp" && relationEntiry == "QuarAction") { relationKey<class UserAppObject, class QuarActionObject>();}
    else if (entity == "QuarAction" && relationEntiry == "QuarActionAssignment") { relationKey<class QuarActionObject, class QuarActionAssignmentObject>();}
    else if (entity == "QuarQuar" && relationEntiry == "QuarActionAssignment") { relationKey<class QuarQuarObject, class QuarActionAssignmentObject>();}
    else if (entity == "UserApp" && relationEntiry == "QuarActionAssignment") { relationKey<class UserAppObject, class QuarActionAssignmentObject>();}
    else if (entity == "RefInvClass" && relationEntiry == "InvInv") { relationKey<class RefInvClassObject, class InvInvObject>();}
    else if (entity == "EqpAssmbl" && relationEntiry == "InvInv") { relationKey<class EqpAssmblObject, class InvInvObject>();}
    else if (entity == "EqpAssmblBom" && relationEntiry == "InvInv") { relationKey<class EqpAssmblBomObject, class InvInvObject>();}
    else if (entity == "EqpAssmblBomPos" && relationEntiry == "InvInv") { relationKey<class EqpAssmblBomPosObject, class InvInvObject>();}
    else if (entity == "EqpPartNo" && relationEntiry == "InvInv") { relationKey<class EqpPartNoObject, class InvInvObject>();}
    else if (entity == "Loc" && relationEntiry == "InvInv") { relationKey<class LocObject, class InvInvObject>();}
    else if (entity == "Authority" && relationEntiry == "InvInv") { relationKey<class AuthorityObject, class InvInvObject>();}
    else if (entity == "InvInv" && relationEntiry == "InvInv") { relationKey<class InvInvObject, class InvInvObject>();}
    else if (entity == "Vendor" && relationEntiry == "InvInv") { relationKey<class VendorObject, class InvInvObject>();}
    else if (entity == "RefInvCond" && relationEntiry == "InvInv") { relationKey<class RefInvCondObject, class InvInvObject>();}
    else if (entity == "RefReceiveCond" && relationEntiry == "InvInv") { relationKey<class RefReceiveCondObject, class InvInvObject>();}
    else if (entity == "OwnerApp" && relationEntiry == "InvInv") { relationKey<class OwnerAppObject, class InvInvObject>();}
    else if (entity == "RefOwnBy" && relationEntiry == "InvInv") { relationKey<class RefOwnByObject, class InvInvObject>();}
    else if (entity == "PoHeader" && relationEntiry == "InvInv") { relationKey<class PoHeaderObject, class InvInvObject>();}
    else if (entity == "PoLine" && relationEntiry == "InvInv") { relationKey<class PoLineObject, class InvInvObject>();}
    else if (entity == "FncAccount" && relationEntiry == "InvInv") { relationKey<class FncAccountObject, class InvInvObject>();}
    else if (entity == "InvInv" && relationEntiry == "InvAttachment") { relationKey<class InvInvObject, class InvAttachmentObject>();}
    else if (entity == "RefFileSave" && relationEntiry == "InvAttachment") { relationKey<class RefFileSaveObject, class InvAttachmentObject>();}
    else if (entity == "InvInv" && relationEntiry == "InvAcReg") { relationKey<class InvInvObject, class InvAcRegObject>();}
    else if (entity == "Org" && relationEntiry == "InvAcReg") { relationKey<class OrgObject, class InvAcRegObject>();}
    else if (entity == "RegBody" && relationEntiry == "InvAcReg") { relationKey<class RegBodyObject, class InvAcRegObject>();}
    else if (entity == "Country" && relationEntiry == "InvAcReg") { relationKey<class CountryObject, class InvAcRegObject>();}
    else if (entity == "FcModel" && relationEntiry == "InvAcReg") { relationKey<class FcModelObject, class InvAcRegObject>();}
    else if (entity == "InvInv" && relationEntiry == "InvCurrUsage") { relationKey<class InvInvObject, class InvCurrUsageObject>();}
    else if (entity == "RefEngUnit" && relationEntiry == "InvCurrUsage") { relationKey<class RefEngUnitObject, class InvCurrUsageObject>();}
    else if (entity == "InvInv" && relationEntiry == "InvCapability") { relationKey<class InvInvObject, class InvCapabilityObject>();}
    else if (entity == "OperationCapability" && relationEntiry == "InvCapability") { relationKey<class OperationCapabilityObject, class InvCapabilityObject>();}
    else if (entity == "InvInv" && relationEntiry == "InvKit") { relationKey<class InvInvObject, class InvKitObject>();}
    else if (entity == "InvKit" && relationEntiry == "InvKitMap") { relationKey<class InvKitObject, class InvKitMapObject>();}
    else if (entity == "InvInv" && relationEntiry == "InvKitMap") { relationKey<class InvInvObject, class InvKitMapObject>();}
    else if (entity == "PoHeader" && relationEntiry == "InvCsgnXchg") { relationKey<class PoHeaderObject, class InvCsgnXchgObject>();}
    else if (entity == "InvInv" && relationEntiry == "InvCsgnXchg") { relationKey<class InvInvObject, class InvCsgnXchgObject>();}
    else if (entity == "InvInv" && relationEntiry == "InvXfer") { relationKey<class InvInvObject, class InvXferObject>();}
    else if (entity == "EvtEvent" && relationEntiry == "InvXfer") { relationKey<class EvtEventObject, class InvXferObject>();}
    else if (entity == "RefXferType" && relationEntiry == "InvXfer") { relationKey<class RefXferTypeObject, class InvXferObject>();}
    else if (entity == "UserApp" && relationEntiry == "InvXfer") { relationKey<class UserAppObject, class InvXferObject>();}
    else if (entity == "EvtEvent" && relationEntiry == "InvAdjust") { relationKey<class EvtEventObject, class InvAdjustObject>();}
    else if (entity == "InvInv" && relationEntiry == "InvAdjust") { relationKey<class InvInvObject, class InvAdjustObject>();}
    else if (entity == "EqpPartNo" && relationEntiry == "InvAdjust") { relationKey<class EqpPartNoObject, class InvAdjustObject>();}
    else if (entity == "PoHeader" && relationEntiry == "InvAdjust") { relationKey<class PoHeaderObject, class InvAdjustObject>();}
    else if (entity == "PoLine" && relationEntiry == "InvAdjust") { relationKey<class PoLineObject, class InvAdjustObject>();}
    else if (entity == "RefXactionType" && relationEntiry == "InvAdjust") { relationKey<class RefXactionTypeObject, class InvAdjustObject>();}
    else if (entity == "UserApp" && relationEntiry == "InvAdjust") { relationKey<class UserAppObject, class InvAdjustObject>();}
    else if (entity == "RefWarrantyStatus" && relationEntiry == "WarrantyDefn") { relationKey<class RefWarrantyStatusObject, class WarrantyDefnObject>();}
    else if (entity == "RefWarrantyPriority" && relationEntiry == "WarrantyDefn") { relationKey<class RefWarrantyPriorityObject, class WarrantyDefnObject>();}
    else if (entity == "Vendor" && relationEntiry == "WarrantyDefn") { relationKey<class VendorObject, class WarrantyDefnObject>();}
    else if (entity == "WarrantyDefn" && relationEntiry == "WarrantyDefnAttachment") { relationKey<class WarrantyDefnObject, class WarrantyDefnAttachmentObject>();}
    else if (entity == "RefFileSave" && relationEntiry == "WarrantyDefnAttachment") { relationKey<class RefFileSaveObject, class WarrantyDefnAttachmentObject>();}
    else if (entity == "WarrantyDefn" && relationEntiry == "WarrantyDefnType") { relationKey<class WarrantyDefnObject, class WarrantyDefnTypeObject>();}
    else if (entity == "RefWarrantyType" && relationEntiry == "WarrantyDefnType") { relationKey<class RefWarrantyTypeObject, class WarrantyDefnTypeObject>();}
    else if (entity == "WarrantyDefn" && relationEntiry == "WarrantyDefnSubtype") { relationKey<class WarrantyDefnObject, class WarrantyDefnSubtypeObject>();}
    else if (entity == "RefWarrantySubtype" && relationEntiry == "WarrantyDefnSubtype") { relationKey<class RefWarrantySubtypeObject, class WarrantyDefnSubtypeObject>();}
    else if (entity == "WarrantyDefn" && relationEntiry == "WarrantyDefnTask") { relationKey<class WarrantyDefnObject, class WarrantyDefnTaskObject>();}
    else if (entity == "TaskTask" && relationEntiry == "WarrantyDefnTask") { relationKey<class TaskTaskObject, class WarrantyDefnTaskObject>();}
    else if (entity == "WarrantyDefn" && relationEntiry == "WarrantyDefnPart") { relationKey<class WarrantyDefnObject, class WarrantyDefnPartObject>();}
    else if (entity == "EqpPartNo" && relationEntiry == "WarrantyDefnPart") { relationKey<class EqpPartNoObject, class WarrantyDefnPartObject>();}
    else if (entity == "WarrantyDefn" && relationEntiry == "WarrantyDefnAssmbl") { relationKey<class WarrantyDefnObject, class WarrantyDefnAssmblObject>();}
    else if (entity == "EqpAssmbl" && relationEntiry == "WarrantyDefnAssmbl") { relationKey<class EqpAssmblObject, class WarrantyDefnAssmblObject>();}
    else if (entity == "WarrantyDefn" && relationEntiry == "WarrantyInit") { relationKey<class WarrantyDefnObject, class WarrantyInitObject>();}
    else if (entity == "RefWarrantyPriority" && relationEntiry == "WarrantyInit") { relationKey<class RefWarrantyPriorityObject, class WarrantyInitObject>();}
    else if (entity == "WarrantyInit" && relationEntiry == "WarrantyInitInv") { relationKey<class WarrantyInitObject, class WarrantyInitInvObject>();}
    else if (entity == "InvInv" && relationEntiry == "WarrantyInitInv") { relationKey<class InvInvObject, class WarrantyInitInvObject>();}
    else if (entity == "WarrantyInit" && relationEntiry == "WarrantyInitTask") { relationKey<class WarrantyInitObject, class WarrantyInitTaskObject>();}
    else if (entity == "SchedStask" && relationEntiry == "WarrantyInitTask") { relationKey<class SchedStaskObject, class WarrantyInitTaskObject>();}
    else if (entity == "WarrantyInit" && relationEntiry == "WarrantyEval") { relationKey<class WarrantyInitObject, class WarrantyEvalObject>();}
    else if (entity == "RefWarrantyEvalStatus" && relationEntiry == "WarrantyEval") { relationKey<class RefWarrantyEvalStatusObject, class WarrantyEvalObject>();}
    else if (entity == "UserApp" && relationEntiry == "WarrantyEval") { relationKey<class UserAppObject, class WarrantyEvalObject>();}
    else if (entity == "WarrantyEval" && relationEntiry == "WarrantyEvalTask") { relationKey<class WarrantyEvalObject, class WarrantyEvalTaskObject>();}
    else if (entity == "SchedStask" && relationEntiry == "WarrantyEvalTask") { relationKey<class SchedStaskObject, class WarrantyEvalTaskObject>();}
    else if (entity == "WarrantyEvalTask" && relationEntiry == "WarrantyEvalLabour") { relationKey<class WarrantyEvalTaskObject, class WarrantyEvalLabourObject>();}
    else if (entity == "SchedLabour" && relationEntiry == "WarrantyEvalLabour") { relationKey<class SchedLabourObject, class WarrantyEvalLabourObject>();}
    else if (entity == "WarrantyEvalTask" && relationEntiry == "WarrantyEvalPart") { relationKey<class WarrantyEvalTaskObject, class WarrantyEvalPartObject>();}
    else if (entity == "SchedRmvdPart" && relationEntiry == "WarrantyEvalPart") { relationKey<class SchedRmvdPartObject, class WarrantyEvalPartObject>();}
    else if (entity == "RefClaimTo" && relationEntiry == "Claim") { relationKey<class RefClaimToObject, class ClaimObject>();}
    else if (entity == "Transportor" && relationEntiry == "Claim") { relationKey<class TransportorObject, class ClaimObject>();}
    else if (entity == "WarrantyEval" && relationEntiry == "Claim") { relationKey<class WarrantyEvalObject, class ClaimObject>();}
    else if (entity == "Vendor" && relationEntiry == "Claim") { relationKey<class VendorObject, class ClaimObject>();}
    else if (entity == "InvInv" && relationEntiry == "Claim") { relationKey<class InvInvObject, class ClaimObject>();}
    else if (entity == "UserApp" && relationEntiry == "Claim") { relationKey<class UserAppObject, class ClaimObject>();}
    else if (entity == "Claim" && relationEntiry == "ClaimAttachment") { relationKey<class ClaimObject, class ClaimAttachmentObject>();}
    else if (entity == "RefFileSave" && relationEntiry == "ClaimAttachment") { relationKey<class RefFileSaveObject, class ClaimAttachmentObject>();}
    else if (entity == "Claim" && relationEntiry == "ClaimLabourLine") { relationKey<class ClaimObject, class ClaimLabourLineObject>();}
    else if (entity == "WarrantyEvalLabour" && relationEntiry == "ClaimLabourLine") { relationKey<class WarrantyEvalLabourObject, class ClaimLabourLineObject>();}
    else if (entity == "Claim" && relationEntiry == "ClaimPartLine") { relationKey<class ClaimObject, class ClaimPartLineObject>();}
    else if (entity == "WarrantyEvalPart" && relationEntiry == "ClaimPartLine") { relationKey<class WarrantyEvalPartObject, class ClaimPartLineObject>();}
    else if (entity == "InvInv" && relationEntiry == "ClaimPartLine") { relationKey<class InvInvObject, class ClaimPartLineObject>();}
    else if (entity == "Authority" && relationEntiry == "FcModel") { relationKey<class AuthorityObject, class FcModelObject>();}
    else if (entity == "FcModel" && relationEntiry == "FcRange") { relationKey<class FcModelObject, class FcRangeObject>();}
    else if (entity == "FcModel" && relationEntiry == "FcRate") { relationKey<class FcModelObject, class FcRateObject>();}
    else if (entity == "FcRange" && relationEntiry == "FcRate") { relationKey<class FcRangeObject, class FcRateObject>();}
    else if (entity == "DataType" && relationEntiry == "FcRate") { relationKey<class DataTypeObject, class FcRateObject>();}
    else if (entity == "RefAccountType" && relationEntiry == "FncAccount") { relationKey<class RefAccountTypeObject, class FncAccountObject>();}
    else if (entity == "FncTcode" && relationEntiry == "FncAccount") { relationKey<class FncTcodeObject, class FncAccountObject>();}
    else if (entity == "RefXactionType" && relationEntiry == "FncXactionLog") { relationKey<class RefXactionTypeObject, class FncXactionLogObject>();}
    else if (entity == "PoHeader" && relationEntiry == "FncXactionLog") { relationKey<class PoHeaderObject, class FncXactionLogObject>();}
    else if (entity == "PoLine" && relationEntiry == "FncXactionLog") { relationKey<class PoLineObject, class FncXactionLogObject>();}
    else if (entity == "PoInvoice" && relationEntiry == "FncXactionLog") { relationKey<class PoInvoiceObject, class FncXactionLogObject>();}
    else if (entity == "PoInvoiceLine" && relationEntiry == "FncXactionLog") { relationKey<class PoInvoiceLineObject, class FncXactionLogObject>();}
    else if (entity == "EqpPartNo" && relationEntiry == "FncXactionLog") { relationKey<class EqpPartNoObject, class FncXactionLogObject>();}
    else if (entity == "InvInv" && relationEntiry == "FncXactionLog") { relationKey<class InvInvObject, class FncXactionLogObject>();}
    else if (entity == "Currency" && relationEntiry == "FncXactionLog") { relationKey<class CurrencyObject, class FncXactionLogObject>();}
    else if (entity == "FncXactionLog" && relationEntiry == "FncXactionLogAccount") { relationKey<class FncXactionLogObject, class FncXactionLogAccountObject>();}
    else if (entity == "FncAccount" && relationEntiry == "FncXactionLogAccount") { relationKey<class FncAccountObject, class FncXactionLogAccountObject>();}
    else if (entity == "RefFailDefer" && relationEntiry == "FailDeferRef") { relationKey<class RefFailDeferObject, class FailDeferRefObject>();}
    else if (entity == "RefFailSev" && relationEntiry == "FailDeferRef") { relationKey<class RefFailSevObject, class FailDeferRefObject>();}
    else if (entity == "RefFlightLegStatus" && relationEntiry == "FlightLeg") { relationKey<class RefFlightLegStatusObject, class FlightLegObject>();}
    else if (entity == "Loc" && relationEntiry == "FlightLeg") { relationKey<class LocObject, class FlightLegObject>();}
    else if (entity == "InvAcReg" && relationEntiry == "FlightLeg") { relationKey<class InvAcRegObject, class FlightLegObject>();}
    else if (entity == "FlightLeg" && relationEntiry == "FlightLegNote") { relationKey<class FlightLegObject, class FlightLegNoteObject>();}
    else if (entity == "UserApp" && relationEntiry == "FlightLegNote") { relationKey<class UserAppObject, class FlightLegNoteObject>();}
    else if (entity == "FlightLeg" && relationEntiry == "FlightLegStatusLog") { relationKey<class FlightLegObject, class FlightLegStatusLogObject>();}
    else if (entity == "UserApp" && relationEntiry == "FlightLegStatusLog") { relationKey<class UserAppObject, class FlightLegStatusLogObject>();}
    else if (entity == "RefEventType" && relationEntiry == "EvtEvent") { relationKey<class RefEventTypeObject, class EvtEventObject>();}
    else if (entity == "RefEventReason" && relationEntiry == "EvtEvent") { relationKey<class RefEventReasonObject, class EvtEventObject>();}
    else if (entity == "RefEventStatus" && relationEntiry == "EvtEvent") { relationKey<class RefEventStatusObject, class EvtEventObject>();}
    else if (entity == "EvtEvent" && relationEntiry == "EvtEvent") { relationKey<class EvtEventObject, class EvtEventObject>();}
    else if (entity == "EvtEvent" && relationEntiry == "EvtInv") { relationKey<class EvtEventObject, class EvtInvObject>();}
    else if (entity == "InvInv" && relationEntiry == "EvtInv") { relationKey<class InvInvObject, class EvtInvObject>();}
    else if (entity == "EqpAssmblBom" && relationEntiry == "EvtInv") { relationKey<class EqpAssmblBomObject, class EvtInvObject>();}
    else if (entity == "EqpAssmbl" && relationEntiry == "EvtInv") { relationKey<class EqpAssmblObject, class EvtInvObject>();}
    else if (entity == "EqpAssmblBomPos" && relationEntiry == "EvtInv") { relationKey<class EqpAssmblBomPosObject, class EvtInvObject>();}
    else if (entity == "EqpPartNo" && relationEntiry == "EvtInv") { relationKey<class EqpPartNoObject, class EvtInvObject>();}
    else if (entity == "EvtEvent" && relationEntiry == "EvtInvUsage") { relationKey<class EvtEventObject, class EvtInvUsageObject>();}
    else if (entity == "InvInv" && relationEntiry == "EvtInvUsage") { relationKey<class InvInvObject, class EvtInvUsageObject>();}
    else if (entity == "DataType" && relationEntiry == "EvtInvUsage") { relationKey<class DataTypeObject, class EvtInvUsageObject>();}
    else if (entity == "FlightLeg" && relationEntiry == "EvtInvUsage") { relationKey<class FlightLegObject, class EvtInvUsageObject>();}
    else if (entity == "EvtEvent" && relationEntiry == "EvtSchedDead") { relationKey<class EvtEventObject, class EvtSchedDeadObject>();}
    else if (entity == "DataType" && relationEntiry == "EvtSchedDead") { relationKey<class DataTypeObject, class EvtSchedDeadObject>();}
    else if (entity == "EvtEvent" && relationEntiry == "EvtHr") { relationKey<class EvtEventObject, class EvtHrObject>();}
    else if (entity == "UserApp" && relationEntiry == "EvtHr") { relationKey<class UserAppObject, class EvtHrObject>();}
    else if (entity == "EvtEvent" && relationEntiry == "EvtVendor") { relationKey<class EvtEventObject, class EvtVendorObject>();}
    else if (entity == "Vendor" && relationEntiry == "EvtVendor") { relationKey<class VendorObject, class EvtVendorObject>();}
    else if (entity == "EvtEvent" && relationEntiry == "EvtVendorPoType") { relationKey<class EvtEventObject, class EvtVendorPoTypeObject>();}
    else if (entity == "Vendor" && relationEntiry == "EvtVendorPoType") { relationKey<class VendorObject, class EvtVendorPoTypeObject>();}
    else if (entity == "Org" && relationEntiry == "EvtVendorPoType") { relationKey<class OrgObject, class EvtVendorPoTypeObject>();}
    else if (entity == "RefPoType" && relationEntiry == "EvtVendorPoType") { relationKey<class RefPoTypeObject, class EvtVendorPoTypeObject>();}
    else if (entity == "EvtEvent" && relationEntiry == "EvtLoc") { relationKey<class EvtEventObject, class EvtLocObject>();}
    else if (entity == "Loc" && relationEntiry == "EvtLoc") { relationKey<class LocObject, class EvtLocObject>();}
    else if (entity == "EvtEvent" && relationEntiry == "EvtDept") { relationKey<class EvtEventObject, class EvtDeptObject>();}
    else if (entity == "Dept" && relationEntiry == "EvtDept") { relationKey<class DeptObject, class EvtDeptObject>();}
    else if (entity == "EvtEvent" && relationEntiry == "EvtLicense") { relationKey<class EvtEventObject, class EvtLicenseObject>();}
    else if (entity == "License" && relationEntiry == "EvtLicense") { relationKey<class LicenseObject, class EvtLicenseObject>();}
    else if (entity == "EvtEvent" && relationEntiry == "EvtPartNo") { relationKey<class EvtEventObject, class EvtPartNoObject>();}
    else if (entity == "EqpPartNo" && relationEntiry == "EvtPartNo") { relationKey<class EqpPartNoObject, class EvtPartNoObject>();}
    else if (entity == "EvtEvent" && relationEntiry == "EvtTool") { relationKey<class EvtEventObject, class EvtToolObject>();}
    else if (entity == "SchedTool" && relationEntiry == "EvtTool") { relationKey<class SchedToolObject, class EvtToolObject>();}
    else if (entity == "EqpAssmblBom" && relationEntiry == "EvtTool") { relationKey<class EqpAssmblBomObject, class EvtToolObject>();}
    else if (entity == "EqpPartNo" && relationEntiry == "EvtTool") { relationKey<class EqpPartNoObject, class EvtToolObject>();}
    else if (entity == "InvInv" && relationEntiry == "EvtTool") { relationKey<class InvInvObject, class EvtToolObject>();}
    else if (entity == "TaskTask" && relationEntiry == "EvtTool") { relationKey<class TaskTaskObject, class EvtToolObject>();}
    else if (entity == "TaskToolReq" && relationEntiry == "EvtTool") { relationKey<class TaskToolReqObject, class EvtToolObject>();}
    else if (entity == "EvtEvent" && relationEntiry == "EvtOil") { relationKey<class EvtEventObject, class EvtOilObject>();}
    else if (entity == "MesurUnit" && relationEntiry == "EvtOil") { relationKey<class MesurUnitObject, class EvtOilObject>();}
    else {renderText("No Such Relation."); return;}

    Search(entity);
}


void DataServiceController::Search(const QString &entity)
{
    if (entity == "ActionApp") {Render<ActionAppObject>();}
    else if (entity == "ActionRole") {Render<ActionRoleObject>();}
    else if (entity == "ActionUser") {Render<ActionUserObject>();}
    else if (entity == "Address") {Render<AddressObject>();}
    else if (entity == "AdvsryAttachment") {Render<AdvsryAttachmentObject>();}
    else if (entity == "AdvsryPart") {Render<AdvsryPartObject>();}
    else if (entity == "Advsry") {Render<AdvsryObject>();}
    else if (entity == "AdvsryTaskDept") {Render<AdvsryTaskDeptObject>();}
    else if (entity == "AdvsryTaskRole") {Render<AdvsryTaskRoleObject>();}
    else if (entity == "AdvsryTask") {Render<AdvsryTaskObject>();}
    else if (entity == "AdvsryTaskUser") {Render<AdvsryTaskUserObject>();}
    else if (entity == "AdvsryVendor") {Render<AdvsryVendorObject>();}
    else if (entity == "AlertDefDept") {Render<AlertDefDeptObject>();}
    else if (entity == "AlertDefRole") {Render<AlertDefRoleObject>();}
    else if (entity == "AlertDef") {Render<AlertDefObject>();}
    else if (entity == "AlertDefUser") {Render<AlertDefUserObject>();}
    else if (entity == "Alert") {Render<AlertObject>();}
    else if (entity == "AlertUserLog") {Render<AlertUserLogObject>();}
    else if (entity == "Authority") {Render<AuthorityObject>();}
    else if (entity == "Button") {Render<ButtonObject>();}
    else if (entity == "Carrier") {Render<CarrierObject>();}
    else if (entity == "Charge") {Render<ChargeObject>();}
    else if (entity == "City") {Render<CityObject>();}
    else if (entity == "ClaimAttachment") {Render<ClaimAttachmentObject>();}
    else if (entity == "ClaimLabourLine") {Render<ClaimLabourLineObject>();}
    else if (entity == "ClaimPartLine") {Render<ClaimPartLineObject>();}
    else if (entity == "Claim") {Render<ClaimObject>();}
    else if (entity == "Contact") {Render<ContactObject>();}
    else if (entity == "CountryProvince") {Render<CountryProvinceObject>();}
    else if (entity == "Country") {Render<CountryObject>();}
    else if (entity == "Currency") {Render<CurrencyObject>();}
    else if (entity == "DataType") {Render<DataTypeObject>();}
    else if (entity == "Dept") {Render<DeptObject>();}
    else if (entity == "DeptSubdept") {Render<DeptSubdeptObject>();}
    else if (entity == "DeptUser") {Render<DeptUserObject>();}
    else if (entity == "EqpAssmblBomCapability") {Render<EqpAssmblBomCapabilityObject>();}
    else if (entity == "EqpAssmblBomDataType") {Render<EqpAssmblBomDataTypeObject>();}
    else if (entity == "EqpAssmblBomLog") {Render<EqpAssmblBomLogObject>();}
    else if (entity == "EqpAssmblBomPart") {Render<EqpAssmblBomPartObject>();}
    else if (entity == "EqpAssmblBomPos") {Render<EqpAssmblBomPosObject>();}
    else if (entity == "EqpAssmblBom") {Render<EqpAssmblBomObject>();}
    else if (entity == "EqpAssmblBomThreshold") {Render<EqpAssmblBomThresholdObject>();}
    else if (entity == "EqpAssmblBomTree") {Render<EqpAssmblBomTreeObject>();}
    else if (entity == "EqpAssmblDataType") {Render<EqpAssmblDataTypeObject>();}
    else if (entity == "EqpAssmblOil") {Render<EqpAssmblOilObject>();}
    else if (entity == "EqpAssmbl") {Render<EqpAssmblObject>();}
    else if (entity == "EqpKitPartNo") {Render<EqpKitPartNoObject>();}
    else if (entity == "EqpPanel") {Render<EqpPanelObject>();}
    else if (entity == "EqpPartNoAltUnit") {Render<EqpPartNoAltUnitObject>();}
    else if (entity == "EqpPartNoCapability") {Render<EqpPartNoCapabilityObject>();}
    else if (entity == "EqpPartNoCompatDef") {Render<EqpPartNoCompatDefObject>();}
    else if (entity == "EqpPartNoCompatTask") {Render<EqpPartNoCompatTaskObject>();}
    else if (entity == "EqpPartNoControl") {Render<EqpPartNoControlObject>();}
    else if (entity == "EqpPartNoLog") {Render<EqpPartNoLogObject>();}
    else if (entity == "EqpPartNoReliab") {Render<EqpPartNoReliabObject>();}
    else if (entity == "EqpPartNo") {Render<EqpPartNoObject>();}
    else if (entity == "EqpPartNoShipStoragePackage") {Render<EqpPartNoShipStoragePackageObject>();}
    else if (entity == "EqpPartNoTechData") {Render<EqpPartNoTechDataObject>();}
    else if (entity == "EqpPartNoVendorExchg") {Render<EqpPartNoVendorExchgObject>();}
    else if (entity == "EqpPartNoVendorPrice") {Render<EqpPartNoVendorPriceObject>();}
    else if (entity == "EqpPartNoVendorPur") {Render<EqpPartNoVendorPurObject>();}
    else if (entity == "EqpPartNoVendorRep") {Render<EqpPartNoVendorRepObject>();}
    else if (entity == "EqpStockLevel") {Render<EqpStockLevelObject>();}
    else if (entity == "EqpStockPartNo") {Render<EqpStockPartNoObject>();}
    else if (entity == "EqpStock") {Render<EqpStockObject>();}
    else if (entity == "EqpZonePanel") {Render<EqpZonePanelObject>();}
    else if (entity == "EqpZone") {Render<EqpZoneObject>();}
    else if (entity == "EvtDept") {Render<EvtDeptObject>();}
    else if (entity == "EvtEvent") {Render<EvtEventObject>();}
    else if (entity == "EvtHr") {Render<EvtHrObject>();}
    else if (entity == "EvtInv") {Render<EvtInvObject>();}
    else if (entity == "EvtInvUsage") {Render<EvtInvUsageObject>();}
    else if (entity == "EvtLicense") {Render<EvtLicenseObject>();}
    else if (entity == "EvtLoc") {Render<EvtLocObject>();}
    else if (entity == "EvtOil") {Render<EvtOilObject>();}
    else if (entity == "EvtPartNo") {Render<EvtPartNoObject>();}
    else if (entity == "EvtSchedDead") {Render<EvtSchedDeadObject>();}
    else if (entity == "EvtTool") {Render<EvtToolObject>();}
    else if (entity == "EvtVendorPoType") {Render<EvtVendorPoTypeObject>();}
    else if (entity == "EvtVendor") {Render<EvtVendorObject>();}
    else if (entity == "FailDeferRef") {Render<FailDeferRefObject>();}
    else if (entity == "FcModel") {Render<FcModelObject>();}
    else if (entity == "FcRange") {Render<FcRangeObject>();}
    else if (entity == "FcRate") {Render<FcRateObject>();}
    else if (entity == "FlightLegNote") {Render<FlightLegNoteObject>();}
    else if (entity == "FlightLeg") {Render<FlightLegObject>();}
    else if (entity == "FlightLegStatusLog") {Render<FlightLegStatusLogObject>();}
    else if (entity == "FncAccount") {Render<FncAccountObject>();}
    else if (entity == "FncTcode") {Render<FncTcodeObject>();}
    else if (entity == "FncXactionLogAccount") {Render<FncXactionLogAccountObject>();}
    else if (entity == "FncXactionLog") {Render<FncXactionLogObject>();}
    else if (entity == "InvAcReg") {Render<InvAcRegObject>();}
    else if (entity == "InvAdjust") {Render<InvAdjustObject>();}
    else if (entity == "InvAttachment") {Render<InvAttachmentObject>();}
    else if (entity == "InvCapability") {Render<InvCapabilityObject>();}
    else if (entity == "InvCsgnXchg") {Render<InvCsgnXchgObject>();}
    else if (entity == "InvCurrUsage") {Render<InvCurrUsageObject>();}
    else if (entity == "InvInv") {Render<InvInvObject>();}
    else if (entity == "InvKitMap") {Render<InvKitMapObject>();}
    else if (entity == "InvKit") {Render<InvKitObject>();}
    else if (entity == "InvXfer") {Render<InvXferObject>();}
    else if (entity == "LabourSkill") {Render<LabourSkillObject>();}
    else if (entity == "LicensePrerequisite") {Render<LicensePrerequisiteObject>();}
    else if (entity == "License") {Render<LicenseObject>();}
    else if (entity == "LocAddress") {Render<LocAddressObject>();}
    else if (entity == "LocAirportSetting") {Render<LocAirportSettingObject>();}
    else if (entity == "LocBinLevel") {Render<LocBinLevelObject>();}
    else if (entity == "LocContact") {Render<LocContactObject>();}
    else if (entity == "LocDockSetting") {Render<LocDockSettingObject>();}
    else if (entity == "LocInvRecount") {Render<LocInvRecountObject>();}
    else if (entity == "LocLabourCapacity") {Render<LocLabourCapacityObject>();}
    else if (entity == "LocLineSetting") {Render<LocLineSettingObject>();}
    else if (entity == "LocPartCount") {Render<LocPartCountObject>();}
    else if (entity == "Loc") {Render<LocObject>();}
    else if (entity == "LocShopRepair") {Render<LocShopRepairObject>();}
    else if (entity == "LocSubloc") {Render<LocSublocObject>();}
    else if (entity == "LocWorkTypeCapability") {Render<LocWorkTypeCapabilityObject>();}
    else if (entity == "MaintPrgmCarrierMap") {Render<MaintPrgmCarrierMapObject>();}
    else if (entity == "MaintPrgmCarrierTempTask") {Render<MaintPrgmCarrierTempTaskObject>();}
    else if (entity == "MaintPrgmDefn") {Render<MaintPrgmDefnObject>();}
    else if (entity == "MaintPrgmLog") {Render<MaintPrgmLogObject>();}
    else if (entity == "MaintPrgm") {Render<MaintPrgmObject>();}
    else if (entity == "MaintPrgmTask") {Render<MaintPrgmTaskObject>();}
    else if (entity == "MaintPrgmTaskTempIssueLog") {Render<MaintPrgmTaskTempIssueLogObject>();}
    else if (entity == "ManufactAttachment") {Render<ManufactAttachmentObject>();}
    else if (entity == "Manufact") {Render<ManufactObject>();}
    else if (entity == "Menu") {Render<MenuObject>();}
    else if (entity == "MenusGroupMenu") {Render<MenusGroupMenuObject>();}
    else if (entity == "MenusGroupRole") {Render<MenusGroupRoleObject>();}
    else if (entity == "MenusGroup") {Render<MenusGroupObject>();}
    else if (entity == "MenusGroupUser") {Render<MenusGroupUserObject>();}
    else if (entity == "MesurTypeUnit") {Render<MesurTypeUnitObject>();}
    else if (entity == "MesurUnit") {Render<MesurUnitObject>();}
    else if (entity == "OperationCapability") {Render<OperationCapabilityObject>();}
    else if (entity == "OrgAddress") {Render<OrgAddressObject>();}
    else if (entity == "OrgCode") {Render<OrgCodeObject>();}
    else if (entity == "OrgContact") {Render<OrgContactObject>();}
    else if (entity == "OrgDept") {Render<OrgDeptObject>();}
    else if (entity == "Org") {Render<OrgObject>();}
    else if (entity == "OrgSuborg") {Render<OrgSuborgObject>();}
    else if (entity == "OrgVendorApproval") {Render<OrgVendorApprovalObject>();}
    else if (entity == "OwnerApp") {Render<OwnerAppObject>();}
    else if (entity == "PoAttachment") {Render<PoAttachmentObject>();}
    else if (entity == "PoAuth") {Render<PoAuthObject>();}
    else if (entity == "PoHeader") {Render<PoHeaderObject>();}
    else if (entity == "PoInvoiceAttachment") {Render<PoInvoiceAttachmentObject>();}
    else if (entity == "PoInvoiceLineCharge") {Render<PoInvoiceLineChargeObject>();}
    else if (entity == "PoInvoiceLineMap") {Render<PoInvoiceLineMapObject>();}
    else if (entity == "PoInvoiceLine") {Render<PoInvoiceLineObject>();}
    else if (entity == "PoInvoiceLineTax") {Render<PoInvoiceLineTaxObject>();}
    else if (entity == "PoInvoice") {Render<PoInvoiceObject>();}
    else if (entity == "PoLineCharge") {Render<PoLineChargeObject>();}
    else if (entity == "PoLineDoc") {Render<PoLineDocObject>();}
    else if (entity == "PoLineKitLine") {Render<PoLineKitLineObject>();}
    else if (entity == "PoLineReturnMap") {Render<PoLineReturnMapObject>();}
    else if (entity == "PoLine") {Render<PoLineObject>();}
    else if (entity == "PoLineTax") {Render<PoLineTaxObject>();}
    else if (entity == "PoLineWarranty") {Render<PoLineWarrantyObject>();}
    else if (entity == "ProvinceCity") {Render<ProvinceCityObject>();}
    else if (entity == "Province") {Render<ProvinceObject>();}
    else if (entity == "QtyUnit") {Render<QtyUnitObject>();}
    else if (entity == "QuarActionAssignment") {Render<QuarActionAssignmentObject>();}
    else if (entity == "QuarAction") {Render<QuarActionObject>();}
    else if (entity == "QuarQuar") {Render<QuarQuarObject>();}
    else if (entity == "RefAccountType") {Render<RefAccountTypeObject>();}
    else if (entity == "RefAdvsryType") {Render<RefAdvsryTypeObject>();}
    else if (entity == "RefAlertStatus") {Render<RefAlertStatusObject>();}
    else if (entity == "RefAssmblClass") {Render<RefAssmblClassObject>();}
    else if (entity == "RefBomClass") {Render<RefBomClassObject>();}
    else if (entity == "RefBorrowRate") {Render<RefBorrowRateObject>();}
    else if (entity == "RefCancelWhen") {Render<RefCancelWhenObject>();}
    else if (entity == "RefClaimTo") {Render<RefClaimToObject>();}
    else if (entity == "RefCostLineItemType") {Render<RefCostLineItemTypeObject>();}
    else if (entity == "RefCreateWhen") {Render<RefCreateWhenObject>();}
    else if (entity == "RefDocDisposition") {Render<RefDocDispositionObject>();}
    else if (entity == "RefDocIssueBy") {Render<RefDocIssueByObject>();}
    else if (entity == "RefEngUnit") {Render<RefEngUnitObject>();}
    else if (entity == "RefEventReason") {Render<RefEventReasonObject>();}
    else if (entity == "RefEventStatus") {Render<RefEventStatusObject>();}
    else if (entity == "RefEventType") {Render<RefEventTypeObject>();}
    else if (entity == "RefFailDefer") {Render<RefFailDeferObject>();}
    else if (entity == "RefFailSevDefer") {Render<RefFailSevDeferObject>();}
    else if (entity == "RefFailSev") {Render<RefFailSevObject>();}
    else if (entity == "RefFileSave") {Render<RefFileSaveObject>();}
    else if (entity == "RefFirstSchedFrom") {Render<RefFirstSchedFromObject>();}
    else if (entity == "RefFlightLegStatus") {Render<RefFlightLegStatusObject>();}
    else if (entity == "RefHazmatDef") {Render<RefHazmatDefObject>();}
    else if (entity == "RefInvClass") {Render<RefInvClassObject>();}
    else if (entity == "RefInvCond") {Render<RefInvCondObject>();}
    else if (entity == "RefLabourRoleStatus") {Render<RefLabourRoleStatusObject>();}
    else if (entity == "RefLabourRoleType") {Render<RefLabourRoleTypeObject>();}
    else if (entity == "RefLabourStage") {Render<RefLabourStageObject>();}
    else if (entity == "RefLicenseStatus") {Render<RefLicenseStatusObject>();}
    else if (entity == "RefLocType") {Render<RefLocTypeObject>();}
    else if (entity == "RefLogAction") {Render<RefLogActionObject>();}
    else if (entity == "RefMaintPrgmStatus") {Render<RefMaintPrgmStatusObject>();}
    else if (entity == "RefMesurType") {Render<RefMesurTypeObject>();}
    else if (entity == "RefOwnBy") {Render<RefOwnByObject>();}
    else if (entity == "RefOwnerType") {Render<RefOwnerTypeObject>();}
    else if (entity == "RefPackingDef") {Render<RefPackingDefObject>();}
    else if (entity == "RefPartProviderType") {Render<RefPartProviderTypeObject>();}
    else if (entity == "RefPartStatus") {Render<RefPartStatusObject>();}
    else if (entity == "RefPartType") {Render<RefPartTypeObject>();}
    else if (entity == "RefPartUse") {Render<RefPartUseObject>();}
    else if (entity == "RefPaymentTerms") {Render<RefPaymentTermsObject>();}
    else if (entity == "RefPoLineType") {Render<RefPoLineTypeObject>();}
    else if (entity == "RefPoType") {Render<RefPoTypeObject>();}
    else if (entity == "RefPriceType") {Render<RefPriceTypeObject>();}
    else if (entity == "RefReceiveCond") {Render<RefReceiveCondObject>();}
    else if (entity == "RefReceivePriority") {Render<RefReceivePriorityObject>();}
    else if (entity == "RefRemoveReason") {Render<RefRemoveReasonObject>();}
    else if (entity == "RefReqAction") {Render<RefReqActionObject>();}
    else if (entity == "RefReqPriority") {Render<RefReqPriorityObject>();}
    else if (entity == "RefReqType") {Render<RefReqTypeObject>();}
    else if (entity == "RefReschedFrom") {Render<RefReschedFromObject>();}
    else if (entity == "RefSchedPartStatus") {Render<RefSchedPartStatusObject>();}
    else if (entity == "RefSegmentStatus") {Render<RefSegmentStatusObject>();}
    else if (entity == "RefShipmentType") {Render<RefShipmentTypeObject>();}
    else if (entity == "RefStockLowActn") {Render<RefStockLowActnObject>();}
    else if (entity == "RefTaskClass") {Render<RefTaskClassObject>();}
    else if (entity == "RefTaskDefStatus") {Render<RefTaskDefStatusObject>();}
    else if (entity == "RefTaskDepAction") {Render<RefTaskDepActionObject>();}
    else if (entity == "RefThresholdMode") {Render<RefThresholdModeObject>();}
    else if (entity == "RefTradeTerms") {Render<RefTradeTermsObject>();}
    else if (entity == "RefVendorStatus") {Render<RefVendorStatusObject>();}
    else if (entity == "RefVendorType") {Render<RefVendorTypeObject>();}
    else if (entity == "RefWarrantyEvalStatus") {Render<RefWarrantyEvalStatusObject>();}
    else if (entity == "RefWarrantyPriority") {Render<RefWarrantyPriorityObject>();}
    else if (entity == "RefWarrantyStatus") {Render<RefWarrantyStatusObject>();}
    else if (entity == "RefWarrantySubtype") {Render<RefWarrantySubtypeObject>();}
    else if (entity == "RefWarrantyType") {Render<RefWarrantyTypeObject>();}
    else if (entity == "RefWarrantyTypeSubtype") {Render<RefWarrantyTypeSubtypeObject>();}
    else if (entity == "RefWorkpackageType") {Render<RefWorkpackageTypeObject>();}
    else if (entity == "RefXactionType") {Render<RefXactionTypeObject>();}
    else if (entity == "RefXferType") {Render<RefXferTypeObject>();}
    else if (entity == "RegBodyDoc") {Render<RegBodyDocObject>();}
    else if (entity == "RegBody") {Render<RegBodyObject>();}
    else if (entity == "ReqPart") {Render<ReqPartObject>();}
    else if (entity == "RfqAttachment") {Render<RfqAttachmentObject>();}
    else if (entity == "RfqHeader") {Render<RfqHeaderObject>();}
    else if (entity == "RfqLine") {Render<RfqLineObject>();}
    else if (entity == "RfqLineVendorCharge") {Render<RfqLineVendorChargeObject>();}
    else if (entity == "RfqLineVendor") {Render<RfqLineVendorObject>();}
    else if (entity == "RfqLineVendorTax") {Render<RfqLineVendorTaxObject>();}
    else if (entity == "RfqVendor") {Render<RfqVendorObject>();}
    else if (entity == "RoleApp") {Render<RoleAppObject>();}
    else if (entity == "RoleUser") {Render<RoleUserObject>();}
    else if (entity == "SchedAttachment") {Render<SchedAttachmentObject>();}
    else if (entity == "SchedFigure") {Render<SchedFigureObject>();}
    else if (entity == "SchedImpact") {Render<SchedImpactObject>();}
    else if (entity == "SchedInstPart") {Render<SchedInstPartObject>();}
    else if (entity == "SchedLabourActual") {Render<SchedLabourActualObject>();}
    else if (entity == "SchedLabourSched") {Render<SchedLabourSchedObject>();}
    else if (entity == "SchedLabour") {Render<SchedLabourObject>();}
    else if (entity == "SchedPanel") {Render<SchedPanelObject>();}
    else if (entity == "SchedPart") {Render<SchedPartObject>();}
    else if (entity == "SchedRmvdPart") {Render<SchedRmvdPartObject>();}
    else if (entity == "SchedStaskFlags") {Render<SchedStaskFlagsObject>();}
    else if (entity == "SchedStask") {Render<SchedStaskObject>();}
    else if (entity == "SchedStepLabour") {Render<SchedStepLabourObject>();}
    else if (entity == "SchedStep") {Render<SchedStepObject>();}
    else if (entity == "SchedTaskDeadlineExt") {Render<SchedTaskDeadlineExtObject>();}
    else if (entity == "SchedTool") {Render<SchedToolObject>();}
    else if (entity == "SchedWpCostLineItem") {Render<SchedWpCostLineItemObject>();}
    else if (entity == "SchedWpLine") {Render<SchedWpLineObject>();}
    else if (entity == "SchedWpMpc") {Render<SchedWpMpcObject>();}
    else if (entity == "SchedWp") {Render<SchedWpObject>();}
    else if (entity == "SchedWpSign") {Render<SchedWpSignObject>();}
    else if (entity == "SchedWpWorkType") {Render<SchedWpWorkTypeObject>();}
    else if (entity == "SchedZone") {Render<SchedZoneObject>();}
    else if (entity == "ShipSegment") {Render<ShipSegmentObject>();}
    else if (entity == "ShipShipmentLineDoc") {Render<ShipShipmentLineDocObject>();}
    else if (entity == "ShipShipmentLine") {Render<ShipShipmentLineObject>();}
    else if (entity == "ShipShipment") {Render<ShipShipmentObject>();}
    else if (entity == "Tab") {Render<TabObject>();}
    else if (entity == "TagTag") {Render<TagTagObject>();}
    else if (entity == "TagTaskDefn") {Render<TagTaskDefnObject>();}
    else if (entity == "TaskAssemblBom") {Render<TaskAssemblBomObject>();}
    else if (entity == "TaskAttachment") {Render<TaskAttachmentObject>();}
    else if (entity == "TaskBlockReqMap") {Render<TaskBlockReqMapObject>();}
    else if (entity == "TaskCompliance") {Render<TaskComplianceObject>();}
    else if (entity == "TaskDefn") {Render<TaskDefnObject>();}
    else if (entity == "TaskFigure") {Render<TaskFigureObject>();}
    else if (entity == "TaskFlags") {Render<TaskFlagsObject>();}
    else if (entity == "TaskImpact") {Render<TaskImpactObject>();}
    else if (entity == "TaskJicReqMap") {Render<TaskJicReqMapObject>();}
    else if (entity == "TaskLabourReq") {Render<TaskLabourReqObject>();}
    else if (entity == "TaskLabourSummary") {Render<TaskLabourSummaryObject>();}
    else if (entity == "TaskMesur") {Render<TaskMesurObject>();}
    else if (entity == "TaskNrEst") {Render<TaskNrEstObject>();}
    else if (entity == "TaskOriginator") {Render<TaskOriginatorObject>();}
    else if (entity == "TaskPanel") {Render<TaskPanelObject>();}
    else if (entity == "TaskPartNo") {Render<TaskPartNoObject>();}
    else if (entity == "TaskPartReq") {Render<TaskPartReqObject>();}
    else if (entity == "TaskPartTransform") {Render<TaskPartTransformObject>();}
    else if (entity == "TaskRefDoc") {Render<TaskRefDocObject>();}
    else if (entity == "TaskSchedRuleAc") {Render<TaskSchedRuleAcObject>();}
    else if (entity == "TaskSchedRuleDef") {Render<TaskSchedRuleDefObject>();}
    else if (entity == "TaskSchedRuleMesur") {Render<TaskSchedRuleMesurObject>();}
    else if (entity == "TaskSchedRulePart") {Render<TaskSchedRulePartObject>();}
    else if (entity == "TaskStep") {Render<TaskStepObject>();}
    else if (entity == "TaskSubclass") {Render<TaskSubclassObject>();}
    else if (entity == "TaskTaskDep") {Render<TaskTaskDepObject>();}
    else if (entity == "TaskTaskLog") {Render<TaskTaskLogObject>();}
    else if (entity == "TaskTask") {Render<TaskTaskObject>();}
    else if (entity == "TaskToolReq") {Render<TaskToolReqObject>();}
    else if (entity == "TaskZone") {Render<TaskZoneObject>();}
    else if (entity == "Tax") {Render<TaxObject>();}
    else if (entity == "TodoListButton") {Render<TodoListButtonObject>();}
    else if (entity == "TodoListRole") {Render<TodoListRoleObject>();}
    else if (entity == "TodoList") {Render<TodoListObject>();}
    else if (entity == "TodoListTab") {Render<TodoListTabObject>();}
    else if (entity == "TodoListUser") {Render<TodoListUserObject>();}
    else if (entity == "Transportor") {Render<TransportorObject>();}
    else if (entity == "UserApp") {Render<UserAppObject>();}
    else if (entity == "UserApp") {Render<UserAppObject>();}
    else if (entity == "UserAttachment") {Render<UserAttachmentObject>();}
    else if (entity == "UserAuthority") {Render<UserAuthorityObject>();}
    else if (entity == "UserElecCert") {Render<UserElecCertObject>();}
    else if (entity == "UserLicense") {Render<UserLicenseObject>();}
    else if (entity == "UserLoginHis") {Render<UserLoginHisObject>();}
    else if (entity == "UserPoAuthLvl") {Render<UserPoAuthLvlObject>();}
    else if (entity == "UserPswdHis") {Render<UserPswdHisObject>();}
    else if (entity == "UserSkill") {Render<UserSkillObject>();}
    else if (entity == "VendorAccount") {Render<VendorAccountObject>();}
    else if (entity == "VendorAttachment") {Render<VendorAttachmentObject>();}
    else if (entity == "Vendor") {Render<VendorObject>();}
    else if (entity == "WarrantyDefnAssmbl") {Render<WarrantyDefnAssmblObject>();}
    else if (entity == "WarrantyDefnAttachment") {Render<WarrantyDefnAttachmentObject>();}
    else if (entity == "WarrantyDefnPart") {Render<WarrantyDefnPartObject>();}
    else if (entity == "WarrantyDefn") {Render<WarrantyDefnObject>();}
    else if (entity == "WarrantyDefnSubtype") {Render<WarrantyDefnSubtypeObject>();}
    else if (entity == "WarrantyDefnTask") {Render<WarrantyDefnTaskObject>();}
    else if (entity == "WarrantyDefnType") {Render<WarrantyDefnTypeObject>();}
    else if (entity == "WarrantyEvalLabour") {Render<WarrantyEvalLabourObject>();}
    else if (entity == "WarrantyEvalPart") {Render<WarrantyEvalPartObject>();}
    else if (entity == "WarrantyEval") {Render<WarrantyEvalObject>();}
    else if (entity == "WarrantyEvalTask") {Render<WarrantyEvalTaskObject>();}
    else if (entity == "WarrantyInitInv") {Render<WarrantyInitInvObject>();}
    else if (entity == "WarrantyInit") {Render<WarrantyInitObject>();}
    else if (entity == "WarrantyInitTask") {Render<WarrantyInitTaskObject>();}
    else if (entity == "WorkpackageBuilder") {Render<WorkpackageBuilderObject>();}
    else if (entity == "WorkType") {Render<WorkTypeObject>();}
    else if (entity == "VMenusGroupMenu") {Render<VMenusGroupMenuObject>();}
    else if (entity == "VTodoListTab") {Render<VTodoListTabObject>();}
    else {renderText("No Such Entity.");}
}

// Don't remove below this line
T_DEFINE_CONTROLLER(DataServiceController)
