#ifndef OWNERAPPOBJECT_H
#define OWNERAPPOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT OwnerAppObject : public TSqlObject, public QSharedData
{
public:
    int owner_id {0};
    QString owner_type_cd;
    int org_id {0};
    int vendor_id {0};
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        OwnerId = 0,
        OwnerTypeCd,
        OrgId,
        VendorId,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<OwnerId; }
    int autoValueIndex() const override { return OwnerId; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList<<VendorId<<OrgId<<OwnerTypeCd; }
    QString tableName() const override { return QLatin1String("owner_app"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int owner_id READ getowner_id WRITE setowner_id)
    T_DEFINE_PROPERTY(int, owner_id)
    Q_PROPERTY(QString owner_type_cd READ getowner_type_cd WRITE setowner_type_cd)
    T_DEFINE_PROPERTY(QString, owner_type_cd)
    Q_PROPERTY(int org_id READ getorg_id WRITE setorg_id)
    T_DEFINE_PROPERTY(int, org_id)
    Q_PROPERTY(int vendor_id READ getvendor_id WRITE setvendor_id)
    T_DEFINE_PROPERTY(int, vendor_id)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};

#endif // OWNERAPPOBJECT_H
