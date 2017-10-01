#ifndef TAGTASKDEFNOBJECT_H
#define TAGTASKDEFNOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT TagTaskDefnObject : public TSqlObject, public QSharedData
{
public:
    int tag_id {0};
    int task_defn_id {0};
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        TagId = 0,
        TaskDefnId,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<TagId<<TaskDefnId; }
    int autoValueIndex() const override { return -1; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList<<TaskDefnId<<TagId; }
    QString tableName() const override { return QLatin1String("tag_task_defn"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int tag_id READ gettag_id WRITE settag_id)
    T_DEFINE_PROPERTY(int, tag_id)
    Q_PROPERTY(int task_defn_id READ gettask_defn_id WRITE settask_defn_id)
    T_DEFINE_PROPERTY(int, task_defn_id)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};

#endif // TAGTASKDEFNOBJECT_H
