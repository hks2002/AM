#ifndef WARRANTYINITINVOBJECT_H
#define WARRANTYINITINVOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT WarrantyInitInvObject : public TSqlObject, public QSharedData
{
public:
    int warranty_init_id {0};
    int inv_no_id {0};
    bool main_bool;
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        WarrantyInitId = 0,
        InvNoId,
        MainBool,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<WarrantyInitId<<InvNoId; }
    int autoValueIndex() const override { return -1; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList<<InvNoId<<WarrantyInitId; }
    QString tableName() const override { return QLatin1String("warranty_init_inv"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int warranty_init_id READ getwarranty_init_id WRITE setwarranty_init_id)
    T_DEFINE_PROPERTY(int, warranty_init_id)
    Q_PROPERTY(int inv_no_id READ getinv_no_id WRITE setinv_no_id)
    T_DEFINE_PROPERTY(int, inv_no_id)
    Q_PROPERTY(bool main_bool READ getmain_bool WRITE setmain_bool)
    T_DEFINE_PROPERTY(bool, main_bool)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};

#endif // WARRANTYINITINVOBJECT_H
