#ifndef LOCBINLEVELOBJECT_H
#define LOCBINLEVELOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT LocBinLevelObject : public TSqlObject, public QSharedData
{
public:
    int loc_id {0};
    int part_no_id {0};
    int owner_id {0};
    int min_qt {0};
    int max_qt {0};
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        LocId = 0,
        PartNoId,
        OwnerId,
        MinQt,
        MaxQt,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<LocId<<PartNoId<<OwnerId; }
    int autoValueIndex() const override { return -1; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList<<OwnerId<<PartNoId<<LocId; }
    QString tableName() const override { return QLatin1String("loc_bin_level"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int loc_id READ getloc_id WRITE setloc_id)
    T_DEFINE_PROPERTY(int, loc_id)
    Q_PROPERTY(int part_no_id READ getpart_no_id WRITE setpart_no_id)
    T_DEFINE_PROPERTY(int, part_no_id)
    Q_PROPERTY(int owner_id READ getowner_id WRITE setowner_id)
    T_DEFINE_PROPERTY(int, owner_id)
    Q_PROPERTY(int min_qt READ getmin_qt WRITE setmin_qt)
    T_DEFINE_PROPERTY(int, min_qt)
    Q_PROPERTY(int max_qt READ getmax_qt WRITE setmax_qt)
    T_DEFINE_PROPERTY(int, max_qt)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};

#endif // LOCBINLEVELOBJECT_H
