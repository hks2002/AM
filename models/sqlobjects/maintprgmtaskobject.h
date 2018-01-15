#ifndef MAINTPRGMTASKOBJECT_H
#define MAINTPRGMTASKOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT MaintPrgmTaskObject : public TSqlObject, public QSharedData
{
public:
    int maint_prgm_id {0};
    int task_defn_id {0};
    int task_id {0};
    int block_defn_id {0};
    int block_id {0};
    QString block_note;
    int issue_ord {0};
    QString group_cd;
    bool unassign_bool;
    bool on_condition_bool;
    QDateTime action_dt;
    QString action_note;
    int action_by {0};
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        MaintPrgmId = 0,
        TaskDefnId,
        TaskId,
        BlockDefnId,
        BlockId,
        BlockNote,
        IssueOrd,
        GroupCd,
        UnassignBool,
        OnConditionBool,
        ActionDt,
        ActionNote,
        ActionBy,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

public slots:
    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<MaintPrgmId<<TaskDefnId<<TaskId<<BlockDefnId<<BlockId; }
    int autoValueIndex() const override { return -1; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList<<ActionBy<<BlockId<<BlockDefnId<<TaskId<<TaskDefnId<<MaintPrgmId; }
    QString tableName() const override { return QLatin1String("maint_prgm_task"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int maint_prgm_id READ getmaint_prgm_id WRITE setmaint_prgm_id)
    T_DEFINE_PROPERTY(int, maint_prgm_id)
    Q_PROPERTY(int task_defn_id READ gettask_defn_id WRITE settask_defn_id)
    T_DEFINE_PROPERTY(int, task_defn_id)
    Q_PROPERTY(int task_id READ gettask_id WRITE settask_id)
    T_DEFINE_PROPERTY(int, task_id)
    Q_PROPERTY(int block_defn_id READ getblock_defn_id WRITE setblock_defn_id)
    T_DEFINE_PROPERTY(int, block_defn_id)
    Q_PROPERTY(int block_id READ getblock_id WRITE setblock_id)
    T_DEFINE_PROPERTY(int, block_id)
    Q_PROPERTY(QString block_note READ getblock_note WRITE setblock_note)
    T_DEFINE_PROPERTY(QString, block_note)
    Q_PROPERTY(int issue_ord READ getissue_ord WRITE setissue_ord)
    T_DEFINE_PROPERTY(int, issue_ord)
    Q_PROPERTY(QString group_cd READ getgroup_cd WRITE setgroup_cd)
    T_DEFINE_PROPERTY(QString, group_cd)
    Q_PROPERTY(bool unassign_bool READ getunassign_bool WRITE setunassign_bool)
    T_DEFINE_PROPERTY(bool, unassign_bool)
    Q_PROPERTY(bool on_condition_bool READ geton_condition_bool WRITE seton_condition_bool)
    T_DEFINE_PROPERTY(bool, on_condition_bool)
    Q_PROPERTY(QDateTime action_dt READ getaction_dt WRITE setaction_dt)
    T_DEFINE_PROPERTY(QDateTime, action_dt)
    Q_PROPERTY(QString action_note READ getaction_note WRITE setaction_note)
    T_DEFINE_PROPERTY(QString, action_note)
    Q_PROPERTY(int action_by READ getaction_by WRITE setaction_by)
    T_DEFINE_PROPERTY(int, action_by)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};


#endif // MAINTPRGMTASKOBJECT_H
