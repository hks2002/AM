#ifndef REFTASKDEPACTIONOBJECT_H
#define REFTASKDEPACTIONOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT RefTaskDepActionObject : public TSqlObject, public QSharedData
{
public:
    QString task_dep_action_cd;
    QString task_dep_action_name_en;
    QString task_dep_action_name_zh;
    QString task_dep_action_desc;
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        TaskDepActionCd = 0,
        TaskDepActionNameEn,
        TaskDepActionNameZh,
        TaskDepActionDesc,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<TaskDepActionCd; }
    int autoValueIndex() const override { return -1; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList; }
    QString tableName() const override { return QLatin1String("ref_task_dep_action"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(QString task_dep_action_cd READ gettask_dep_action_cd WRITE settask_dep_action_cd)
    T_DEFINE_PROPERTY(QString, task_dep_action_cd)
    Q_PROPERTY(QString task_dep_action_name_en READ gettask_dep_action_name_en WRITE settask_dep_action_name_en)
    T_DEFINE_PROPERTY(QString, task_dep_action_name_en)
    Q_PROPERTY(QString task_dep_action_name_zh READ gettask_dep_action_name_zh WRITE settask_dep_action_name_zh)
    T_DEFINE_PROPERTY(QString, task_dep_action_name_zh)
    Q_PROPERTY(QString task_dep_action_desc READ gettask_dep_action_desc WRITE settask_dep_action_desc)
    T_DEFINE_PROPERTY(QString, task_dep_action_desc)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};

#endif // REFTASKDEPACTIONOBJECT_H
