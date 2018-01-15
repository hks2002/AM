#ifndef EQPPARTNOSHIPSTORAGEPACKAGEOBJECT_H
#define EQPPARTNOSHIPSTORAGEPACKAGEOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT EqpPartNoShipStoragePackageObject : public TSqlObject, public QSharedData
{
public:
    int part_no_id {0};
    QString shipping_desc;
    QString storage_desc;
    QString packing_desc;
    QString hazmat_desc;
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        PartNoId = 0,
        ShippingDesc,
        StorageDesc,
        PackingDesc,
        HazmatDesc,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

public slots:
    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<PartNoId; }
    int autoValueIndex() const override { return -1; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList<<PartNoId; }
    QString tableName() const override { return QLatin1String("eqp_part_no_ship_storage_package"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int part_no_id READ getpart_no_id WRITE setpart_no_id)
    T_DEFINE_PROPERTY(int, part_no_id)
    Q_PROPERTY(QString shipping_desc READ getshipping_desc WRITE setshipping_desc)
    T_DEFINE_PROPERTY(QString, shipping_desc)
    Q_PROPERTY(QString storage_desc READ getstorage_desc WRITE setstorage_desc)
    T_DEFINE_PROPERTY(QString, storage_desc)
    Q_PROPERTY(QString packing_desc READ getpacking_desc WRITE setpacking_desc)
    T_DEFINE_PROPERTY(QString, packing_desc)
    Q_PROPERTY(QString hazmat_desc READ gethazmat_desc WRITE sethazmat_desc)
    T_DEFINE_PROPERTY(QString, hazmat_desc)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};


#endif // EQPPARTNOSHIPSTORAGEPACKAGEOBJECT_H
