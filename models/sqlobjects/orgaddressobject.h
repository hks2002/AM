#ifndef ORGADDRESSOBJECT_H
#define ORGADDRESSOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT OrgAddressObject : public TSqlObject, public QSharedData
{
public:
    int org_id {0};
    int address_id {0};
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        OrgId = 0,
        AddressId,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

public slots:
    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<OrgId; }
    int autoValueIndex() const override { return -1; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList<<AddressId<<OrgId; }
    QString tableName() const override { return QLatin1String("org_address"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int org_id READ getorg_id WRITE setorg_id)
    T_DEFINE_PROPERTY(int, org_id)
    Q_PROPERTY(int address_id READ getaddress_id WRITE setaddress_id)
    T_DEFINE_PROPERTY(int, address_id)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};


#endif // ORGADDRESSOBJECT_H
