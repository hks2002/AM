#ifndef ALERTUSERLOGOBJECT_H
#define ALERTUSERLOGOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT AlertUserLogObject : public TSqlObject, public QSharedData
{
public:
    int alert_id {0};
    int user_id {0};
    QString alert_status_cd;
    QString user_note;
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        AlertId = 0,
        UserId,
        AlertStatusCd,
        UserNote,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<AlertId<<UserId; }
    int autoValueIndex() const override { return -1; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList<<AlertStatusCd<<UserId<<AlertId; }
    QString tableName() const override { return QLatin1String("alert_user_log"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int alert_id READ getalert_id WRITE setalert_id)
    T_DEFINE_PROPERTY(int, alert_id)
    Q_PROPERTY(int user_id READ getuser_id WRITE setuser_id)
    T_DEFINE_PROPERTY(int, user_id)
    Q_PROPERTY(QString alert_status_cd READ getalert_status_cd WRITE setalert_status_cd)
    T_DEFINE_PROPERTY(QString, alert_status_cd)
    Q_PROPERTY(QString user_note READ getuser_note WRITE setuser_note)
    T_DEFINE_PROPERTY(QString, user_note)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};

#endif // ALERTUSERLOGOBJECT_H
