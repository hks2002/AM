#ifndef REFFIRSTSCHEDFROMOBJECT_H
#define REFFIRSTSCHEDFROMOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT RefFirstSchedFromObject : public TSqlObject, public QSharedData
{
public:
    QString first_sched_from_cd;
    QString first_sched_from_name_en;
    QString first_sched_from_name_zh;
    QString first_sched_from_desc;
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        FirstSchedFromCd = 0,
        FirstSchedFromNameEn,
        FirstSchedFromNameZh,
        FirstSchedFromDesc,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<FirstSchedFromCd; }
    int autoValueIndex() const override { return -1; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList; }
    QString tableName() const override { return QLatin1String("ref_first_sched_from"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(QString first_sched_from_cd READ getfirst_sched_from_cd WRITE setfirst_sched_from_cd)
    T_DEFINE_PROPERTY(QString, first_sched_from_cd)
    Q_PROPERTY(QString first_sched_from_name_en READ getfirst_sched_from_name_en WRITE setfirst_sched_from_name_en)
    T_DEFINE_PROPERTY(QString, first_sched_from_name_en)
    Q_PROPERTY(QString first_sched_from_name_zh READ getfirst_sched_from_name_zh WRITE setfirst_sched_from_name_zh)
    T_DEFINE_PROPERTY(QString, first_sched_from_name_zh)
    Q_PROPERTY(QString first_sched_from_desc READ getfirst_sched_from_desc WRITE setfirst_sched_from_desc)
    T_DEFINE_PROPERTY(QString, first_sched_from_desc)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};

#endif // REFFIRSTSCHEDFROMOBJECT_H
