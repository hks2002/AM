#ifndef REFEVENTSTATUSOBJECT_H
#define REFEVENTSTATUSOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT RefEventStatusObject : public TSqlObject, public QSharedData
{
public:
    QString event_status_cd;
    QString event_status_name_en;
    QString event_status_name_zh;
    QString event_status_desc;
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        EventStatusCd = 0,
        EventStatusNameEn,
        EventStatusNameZh,
        EventStatusDesc,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

public slots:
    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<EventStatusCd; }
    int autoValueIndex() const override { return -1; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList; }
    QString tableName() const override { return QLatin1String("ref_event_status"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(QString event_status_cd READ getevent_status_cd WRITE setevent_status_cd)
    T_DEFINE_PROPERTY(QString, event_status_cd)
    Q_PROPERTY(QString event_status_name_en READ getevent_status_name_en WRITE setevent_status_name_en)
    T_DEFINE_PROPERTY(QString, event_status_name_en)
    Q_PROPERTY(QString event_status_name_zh READ getevent_status_name_zh WRITE setevent_status_name_zh)
    T_DEFINE_PROPERTY(QString, event_status_name_zh)
    Q_PROPERTY(QString event_status_desc READ getevent_status_desc WRITE setevent_status_desc)
    T_DEFINE_PROPERTY(QString, event_status_desc)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};


#endif // REFEVENTSTATUSOBJECT_H
