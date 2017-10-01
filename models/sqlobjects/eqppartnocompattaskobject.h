#ifndef EQPPARTNOCOMPATTASKOBJECT_H
#define EQPPARTNOCOMPATTASKOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT EqpPartNoCompatTaskObject : public TSqlObject, public QSharedData
{
public:
    int assmbl_id {0};
    int part_no_id {0};
    int task_defn_id {0};
    bool pre_complete_bool;
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        AssmblId = 0,
        PartNoId,
        TaskDefnId,
        PreCompleteBool,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<AssmblId<<PartNoId<<TaskDefnId; }
    int autoValueIndex() const override { return -1; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList<<TaskDefnId<<PartNoId<<AssmblId; }
    QString tableName() const override { return QLatin1String("eqp_part_no_compat_task"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int assmbl_id READ getassmbl_id WRITE setassmbl_id)
    T_DEFINE_PROPERTY(int, assmbl_id)
    Q_PROPERTY(int part_no_id READ getpart_no_id WRITE setpart_no_id)
    T_DEFINE_PROPERTY(int, part_no_id)
    Q_PROPERTY(int task_defn_id READ gettask_defn_id WRITE settask_defn_id)
    T_DEFINE_PROPERTY(int, task_defn_id)
    Q_PROPERTY(bool pre_complete_bool READ getpre_complete_bool WRITE setpre_complete_bool)
    T_DEFINE_PROPERTY(bool, pre_complete_bool)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};

#endif // EQPPARTNOCOMPATTASKOBJECT_H
