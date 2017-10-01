#ifndef QUARACTIONASSIGNMENTOBJECT_H
#define QUARACTIONASSIGNMENTOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT QuarActionAssignmentObject : public TSqlObject, public QSharedData
{
public:
    int quar_action_id {0};
    int quar_id {0};
    bool assigned_bool;
    QDateTime assigned_dt;
    int user_id {0};
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        QuarActionId = 0,
        QuarId,
        AssignedBool,
        AssignedDt,
        UserId,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<QuarActionId<<QuarId; }
    int autoValueIndex() const override { return -1; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList<<UserId<<QuarId<<QuarActionId; }
    QString tableName() const override { return QLatin1String("quar_action_assignment"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int quar_action_id READ getquar_action_id WRITE setquar_action_id)
    T_DEFINE_PROPERTY(int, quar_action_id)
    Q_PROPERTY(int quar_id READ getquar_id WRITE setquar_id)
    T_DEFINE_PROPERTY(int, quar_id)
    Q_PROPERTY(bool assigned_bool READ getassigned_bool WRITE setassigned_bool)
    T_DEFINE_PROPERTY(bool, assigned_bool)
    Q_PROPERTY(QDateTime assigned_dt READ getassigned_dt WRITE setassigned_dt)
    T_DEFINE_PROPERTY(QDateTime, assigned_dt)
    Q_PROPERTY(int user_id READ getuser_id WRITE setuser_id)
    T_DEFINE_PROPERTY(int, user_id)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};

#endif // QUARACTIONASSIGNMENTOBJECT_H
