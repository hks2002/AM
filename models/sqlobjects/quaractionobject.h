#ifndef QUARACTIONOBJECT_H
#define QUARACTIONOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT QuarActionObject : public TSqlObject, public QSharedData
{
public:
    int quar_action_id {0};
    int quar_id {0};
    QString action_desc;
    QString action_note;
    bool quar_action_open_bool;
    QString discrepancy_desc;
    int quar_action_seq {0};
    int user_id {0};
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        QuarActionId = 0,
        QuarId,
        ActionDesc,
        ActionNote,
        QuarActionOpenBool,
        DiscrepancyDesc,
        QuarActionSeq,
        UserId,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<QuarActionId; }
    int autoValueIndex() const override { return QuarActionId; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList<<UserId<<QuarId; }
    QString tableName() const override { return QLatin1String("quar_action"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int quar_action_id READ getquar_action_id WRITE setquar_action_id)
    T_DEFINE_PROPERTY(int, quar_action_id)
    Q_PROPERTY(int quar_id READ getquar_id WRITE setquar_id)
    T_DEFINE_PROPERTY(int, quar_id)
    Q_PROPERTY(QString action_desc READ getaction_desc WRITE setaction_desc)
    T_DEFINE_PROPERTY(QString, action_desc)
    Q_PROPERTY(QString action_note READ getaction_note WRITE setaction_note)
    T_DEFINE_PROPERTY(QString, action_note)
    Q_PROPERTY(bool quar_action_open_bool READ getquar_action_open_bool WRITE setquar_action_open_bool)
    T_DEFINE_PROPERTY(bool, quar_action_open_bool)
    Q_PROPERTY(QString discrepancy_desc READ getdiscrepancy_desc WRITE setdiscrepancy_desc)
    T_DEFINE_PROPERTY(QString, discrepancy_desc)
    Q_PROPERTY(int quar_action_seq READ getquar_action_seq WRITE setquar_action_seq)
    T_DEFINE_PROPERTY(int, quar_action_seq)
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

#endif // QUARACTIONOBJECT_H
