#ifndef TASKASSEMBLBOMOBJECT_H
#define TASKASSEMBLBOMOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT TaskAssemblBomObject : public TSqlObject, public QSharedData
{
public:
    int task_id {0};
    int assmbl_bom_id {0};
    int assmbl_id {0};
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        TaskId = 0,
        AssmblBomId,
        AssmblId,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<TaskId<<AssmblBomId<<AssmblId; }
    int autoValueIndex() const override { return -1; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList<<AssmblId<<AssmblBomId<<TaskId; }
    QString tableName() const override { return QLatin1String("task_assembl_bom"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int task_id READ gettask_id WRITE settask_id)
    T_DEFINE_PROPERTY(int, task_id)
    Q_PROPERTY(int assmbl_bom_id READ getassmbl_bom_id WRITE setassmbl_bom_id)
    T_DEFINE_PROPERTY(int, assmbl_bom_id)
    Q_PROPERTY(int assmbl_id READ getassmbl_id WRITE setassmbl_id)
    T_DEFINE_PROPERTY(int, assmbl_id)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};

#endif // TASKASSEMBLBOMOBJECT_H
