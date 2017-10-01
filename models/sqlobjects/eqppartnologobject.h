#ifndef EQPPARTNOLOGOBJECT_H
#define EQPPARTNOLOGOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT EqpPartNoLogObject : public TSqlObject, public QSharedData
{
public:
    int part_no_log_id {0};
    int part_no_id {0};
    QString log_action_cd;
    QString user_note;
    QString system_note;
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        PartNoLogId = 0,
        PartNoId,
        LogActionCd,
        UserNote,
        SystemNote,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<PartNoLogId; }
    int autoValueIndex() const override { return PartNoLogId; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList<<LogActionCd<<PartNoId; }
    QString tableName() const override { return QLatin1String("eqp_part_no_log"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int part_no_log_id READ getpart_no_log_id WRITE setpart_no_log_id)
    T_DEFINE_PROPERTY(int, part_no_log_id)
    Q_PROPERTY(int part_no_id READ getpart_no_id WRITE setpart_no_id)
    T_DEFINE_PROPERTY(int, part_no_id)
    Q_PROPERTY(QString log_action_cd READ getlog_action_cd WRITE setlog_action_cd)
    T_DEFINE_PROPERTY(QString, log_action_cd)
    Q_PROPERTY(QString user_note READ getuser_note WRITE setuser_note)
    T_DEFINE_PROPERTY(QString, user_note)
    Q_PROPERTY(QString system_note READ getsystem_note WRITE setsystem_note)
    T_DEFINE_PROPERTY(QString, system_note)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};

#endif // EQPPARTNOLOGOBJECT_H
