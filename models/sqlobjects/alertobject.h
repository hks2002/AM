#ifndef ALERTOBJECT_H
#define ALERTOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT AlertObject : public TSqlObject, public QSharedData
{
public:
    int alert_id {0};
    int alert_def_id {0};
    QString alert_status_cd;
    QString msg_title;
    QString message;
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        AlertId = 0,
        AlertDefId,
        AlertStatusCd,
        MsgTitle,
        Message,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

public slots:
    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<AlertId; }
    int autoValueIndex() const override { return AlertId; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList<<AlertStatusCd<<AlertDefId; }
    QString tableName() const override { return QLatin1String("alert"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int alert_id READ getalert_id WRITE setalert_id)
    T_DEFINE_PROPERTY(int, alert_id)
    Q_PROPERTY(int alert_def_id READ getalert_def_id WRITE setalert_def_id)
    T_DEFINE_PROPERTY(int, alert_def_id)
    Q_PROPERTY(QString alert_status_cd READ getalert_status_cd WRITE setalert_status_cd)
    T_DEFINE_PROPERTY(QString, alert_status_cd)
    Q_PROPERTY(QString msg_title READ getmsg_title WRITE setmsg_title)
    T_DEFINE_PROPERTY(QString, msg_title)
    Q_PROPERTY(QString message READ getmessage WRITE setmessage)
    T_DEFINE_PROPERTY(QString, message)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};


#endif // ALERTOBJECT_H
