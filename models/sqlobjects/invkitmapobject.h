#ifndef INVKITMAPOBJECT_H
#define INVKITMAPOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT InvKitMapObject : public TSqlObject, public QSharedData
{
public:
    int inv_kit_map_id {0};
    int kit_inv_no_id {0};
    int inv_no_id {0};
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        InvKitMapId = 0,
        KitInvNoId,
        InvNoId,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

public slots:
    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<InvKitMapId; }
    int autoValueIndex() const override { return InvKitMapId; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList<<InvNoId<<KitInvNoId; }
    QString tableName() const override { return QLatin1String("inv_kit_map"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int inv_kit_map_id READ getinv_kit_map_id WRITE setinv_kit_map_id)
    T_DEFINE_PROPERTY(int, inv_kit_map_id)
    Q_PROPERTY(int kit_inv_no_id READ getkit_inv_no_id WRITE setkit_inv_no_id)
    T_DEFINE_PROPERTY(int, kit_inv_no_id)
    Q_PROPERTY(int inv_no_id READ getinv_no_id WRITE setinv_no_id)
    T_DEFINE_PROPERTY(int, inv_no_id)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};


#endif // INVKITMAPOBJECT_H
