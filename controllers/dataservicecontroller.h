#ifndef DATASERVICECONTROLLER_H
#define DATASERVICECONTROLLER_H
#include <TActionController>
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
        QString err = validateForm<V>(varMaps);

        if (!err.isEmpty()) {
            ctl->XrenderJson(jsonObj(false, err));
            return;
        }

        M model = M::create(varMaps);

        model.isNull()
        ? ctl->XrenderJson(jsonObj(false, UI("Create Failed.")))
        : ctl->XrenderJson(jsonObj(true, UI("Created Successfully.")));
    }

    template <class O>
    static void deleteRecord(ApplicationController *ctl, const QStringList &pklist)
    {
        if (ctl->httpRequest().method() != Tf::Post) {
            ctl->XrenderErrorResponse(Tf::Forbidden);
            return;
        }

        QString key  = ctl->httpRequest().formItemValue("key");
        QJsonArray array = jsonArray(key);

        if (array.isEmpty()) {
            ctl->XrenderJson(jsonObj(false, UI("Error Occurred.")));
            return;
        }

        for (QJsonValue jsonValue : array) {
            QJsonObject obj = jsonValue.toObject();
            QVariantList varlist;

            for (auto &x : pklist) {
                varlist << hmacVal(obj.value(x).toString());
            }

            TSqlORMapper<O> mapper;
            O sqlobj = mapper.findByPrimaryKey(varlist);

            if (sqlobj.isNull()) {
                ctl->XrenderJson(jsonObj(false, UI("Original data may have been updated/removed by another user.")));
                ctl->XrollbackTransaction();
                return;
            }

            if (sqlobj.remove()) {} else {
                ctl->XrenderJson(jsonObj(false, UI("Delete Failed.")));
                ctl->XrollbackTransaction();
                return;
            }
        }

        ctl->XrenderJson(jsonObj(true, UI("Deleted Successfully.")));
    }

    template <class M>
    static void assignRecord(ApplicationController *ctl, const QStringList &pklist)
    {
        if (ctl->httpRequest().method() != Tf::Post) {
            ctl->XrenderErrorResponse(Tf::Forbidden);
            return;
        }

        QString key  = ctl->httpRequest().formItemValue("key");
        QJsonArray array = jsonArray(key);

        if (array.isEmpty()) {
            ctl->XrenderJson(jsonObj(false, UI("Error Occurred.")));
            return;
        }

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
    }

    template <class O>
    static void unassignRecord(ApplicationController *ctl, const QStringList &pklist)
    {

        if (ctl->httpRequest().method() != Tf::Post) {
            ctl->XrenderErrorResponse(Tf::Forbidden);
            return;
        }

        QString key  = ctl->httpRequest().formItemValue("key");
        QJsonArray array = jsonArray(key);

        if (array.isEmpty()) {
            ctl->XrenderJson(jsonObj(false, UI("Error Occurred.")));
            return;
        }

        for (QJsonValue jsonValue : array) {
            tDebug() << "object in array";
            QJsonObject obj = jsonValue.toObject();
            QVariantList varlist;

            for (auto &x : pklist) {
                varlist << hmacVal(obj.value(x).toString());
            }

            TSqlORMapper<O> mapper;
            O sqlobj = mapper.findByPrimaryKey(varlist);

            if (sqlobj.isNull()) {
                ctl->XrenderJson(jsonObj(false, UI("Original data may have been updated/removed by another user.")));
                ctl->XrollbackTransaction();
                return;
            }

            if (sqlobj.remove()) {} else {
                ctl->XrenderJson(jsonObj(false, UI("Unassign Failed.")));
                ctl->XrollbackTransaction();
                return;
            }
        }

        ctl->XrenderJson(jsonObj(true, UI("Unassigned Successfully.")));

    }

    template<class M, class O, class V>
    static void updateRecord(ApplicationController *ctl, const QStringList &pklist, const QStringList &fieldlist = QStringList())
    {
        if (ctl->httpRequest().method() != Tf::Post) {
            ctl->XrenderErrorResponse(Tf::Forbidden);
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

            QString err = validateForm<V>(varMaps);

            if (!err.isEmpty()) {
                ctl->XrenderJson(jsonObj(false, err));
                return;
            }

            model.setProperties(varMaps);

            model.save()
            ? ctl->XrenderJson(jsonObj(true, UI("Updated Successfully.")))
            : ctl->XrenderJson(jsonObj(false, UI("Update Failed.")));

            return;
        } else {

            //with key, treat it as not form edit request
            QString key  = ctl->httpRequest().formItemValue("key");
            QJsonArray array = jsonArray(key);

            if (array.isEmpty()) {
                ctl->XrenderJson(jsonObj(false, UI("Error Occurred.")));
                return;
            }

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

                QVariantMap varMaps;

                for (auto &x : fieldlist) {
                    varMaps.insert(x, obj.value(x));
                }

                QString err = validateForm<V>(varMaps);

                if (!err.isEmpty()) {
                    ctl->XrenderJson(jsonObj(false, err));
                    return;
                }

                model.setProperties(varMaps);

                if (model.save()) {}
                else {
                    ctl->XrenderJson(jsonObj(false, UI("Update Failed.")));
                    ctl->XrollbackTransaction();
                    return;
                }
            }

            ctl->XrenderJson(jsonObj(true, UI("Updated Successfully.")));
        }
    }


public slots:
    void Search(const QString &searchTarget);

private:
    QString sortFields;
    QString sortField;
    QString sortOrder;
    QString key;
    QString relationKey;
    int pageIndex = 0;
    int pageSize = 100;
    QString searchMode;
    QString relation;


    QMap<QString, QString> fieldNameMap;
    QMap<QString, QVariant::Type> fieldTypeMap;
    QStringList hashFieldList;
    QVariantMap boundValues;
    QString sortColumnsOrders;
    QString where;

    void getHttpRequestPara();
    void getSqlQueryPara(const QString &sqlTarget);
    void getSingleSort(const QString &sortField, const QString &sortOrder = "asc");
    void getMultiSort(const QString &sortFields);
    void getWhereClause(const QString &key);
    void getBoundValue(const QString &key);
    void Render(const QString &sqlTarget);

};


#endif // DATASERVICECONTROLLER_H
