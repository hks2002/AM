#ifndef WARRANTYINITTASKOBJECT_H
#define WARRANTYINITTASKOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT WarrantyInitTaskObject : public TSqlObject, public QSharedData
{
public:
    int warranty_init_id {0};
    int sched_id {0};
    bool main_bool;
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        WarrantyInitId = 0,
        SchedId,
        MainBool,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

public slots:
    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<WarrantyInitId<<SchedId; }
    int autoValueIndex() const override { return -1; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList<<SchedId<<WarrantyInitId; }
    QString tableName() const override { return QLatin1String("warranty_init_task"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int warranty_init_id READ getwarranty_init_id WRITE setwarranty_init_id)
    T_DEFINE_PROPERTY(int, warranty_init_id)
    Q_PROPERTY(int sched_id READ getsched_id WRITE setsched_id)
    T_DEFINE_PROPERTY(int, sched_id)
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


#endif // WARRANTYINITTASKOBJECT_H
