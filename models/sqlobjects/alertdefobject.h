#ifndef ALERTDEFOBJECT_H
#define ALERTDEFOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT AlertDefObject : public TSqlObject, public QSharedData
{
public:
    int alert_def_id {0};
    QString alert_name;
    QString alert_desc;
    bool active_bool;
    QString category;
    QString notify_cd;
    int priority {0};
    QString msg_title;
    QString message;
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        AlertDefId = 0,
        AlertName,
        AlertDesc,
        ActiveBool,
        Category,
        NotifyCd,
        Priority,
        MsgTitle,
        Message,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<AlertDefId; }
    int autoValueIndex() const override { return AlertDefId; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList; }
    QString tableName() const override { return QLatin1String("alert_def"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int alert_def_id READ getalert_def_id WRITE setalert_def_id)
    T_DEFINE_PROPERTY(int, alert_def_id)
    Q_PROPERTY(QString alert_name READ getalert_name WRITE setalert_name)
    T_DEFINE_PROPERTY(QString, alert_name)
    Q_PROPERTY(QString alert_desc READ getalert_desc WRITE setalert_desc)
    T_DEFINE_PROPERTY(QString, alert_desc)
    Q_PROPERTY(bool active_bool READ getactive_bool WRITE setactive_bool)
    T_DEFINE_PROPERTY(bool, active_bool)
    Q_PROPERTY(QString category READ getcategory WRITE setcategory)
    T_DEFINE_PROPERTY(QString, category)
    Q_PROPERTY(QString notify_cd READ getnotify_cd WRITE setnotify_cd)
    T_DEFINE_PROPERTY(QString, notify_cd)
    Q_PROPERTY(int priority READ getpriority WRITE setpriority)
    T_DEFINE_PROPERTY(int, priority)
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

#endif // ALERTDEFOBJECT_H
