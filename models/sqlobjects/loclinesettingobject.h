#ifndef LOCLINESETTINGOBJECT_H
#define LOCLINESETTINGOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT LocLineSettingObject : public TSqlObject, public QSharedData
{
public:
    int loc_id {0};
    QString min_ground_time_qt;
    int duration_buffer_qt {0};
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        LocId = 0,
        MinGroundTimeQt,
        DurationBufferQt,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<LocId; }
    int autoValueIndex() const override { return -1; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList<<LocId; }
    QString tableName() const override { return QLatin1String("loc_line_setting"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int loc_id READ getloc_id WRITE setloc_id)
    T_DEFINE_PROPERTY(int, loc_id)
    Q_PROPERTY(QString min_ground_time_qt READ getmin_ground_time_qt WRITE setmin_ground_time_qt)
    T_DEFINE_PROPERTY(QString, min_ground_time_qt)
    Q_PROPERTY(int duration_buffer_qt READ getduration_buffer_qt WRITE setduration_buffer_qt)
    T_DEFINE_PROPERTY(int, duration_buffer_qt)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};

#endif // LOCLINESETTINGOBJECT_H
