#ifndef LOCLABOURCAPACITYOBJECT_H
#define LOCLABOURCAPACITYOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT LocLabourCapacityObject : public TSqlObject, public QSharedData
{
public:
    int loc_id {0};
    int labour_skill_id {0};
    double hours_per_day_qt {0};
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        LocId = 0,
        LabourSkillId,
        HoursPerDayQt,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<LocId<<LabourSkillId; }
    int autoValueIndex() const override { return -1; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList<<LabourSkillId<<LocId; }
    QString tableName() const override { return QLatin1String("loc_labour_capacity"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int loc_id READ getloc_id WRITE setloc_id)
    T_DEFINE_PROPERTY(int, loc_id)
    Q_PROPERTY(int labour_skill_id READ getlabour_skill_id WRITE setlabour_skill_id)
    T_DEFINE_PROPERTY(int, labour_skill_id)
    Q_PROPERTY(double hours_per_day_qt READ gethours_per_day_qt WRITE sethours_per_day_qt)
    T_DEFINE_PROPERTY(double, hours_per_day_qt)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};

#endif // LOCLABOURCAPACITYOBJECT_H
