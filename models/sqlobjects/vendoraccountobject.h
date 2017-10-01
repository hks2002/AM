#ifndef VENDORACCOUNTOBJECT_H
#define VENDORACCOUNTOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT VendorAccountObject : public TSqlObject, public QSharedData
{
public:
    int vendor_id {0};
    int account_id {0};
    bool main_bool;
    bool active_bool;
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        VendorId = 0,
        AccountId,
        MainBool,
        ActiveBool,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<VendorId<<AccountId; }
    int autoValueIndex() const override { return -1; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList<<AccountId<<VendorId; }
    QString tableName() const override { return QLatin1String("vendor_account"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int vendor_id READ getvendor_id WRITE setvendor_id)
    T_DEFINE_PROPERTY(int, vendor_id)
    Q_PROPERTY(int account_id READ getaccount_id WRITE setaccount_id)
    T_DEFINE_PROPERTY(int, account_id)
    Q_PROPERTY(bool main_bool READ getmain_bool WRITE setmain_bool)
    T_DEFINE_PROPERTY(bool, main_bool)
    Q_PROPERTY(bool active_bool READ getactive_bool WRITE setactive_bool)
    T_DEFINE_PROPERTY(bool, active_bool)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};

#endif // VENDORACCOUNTOBJECT_H
