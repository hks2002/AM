#ifndef LOCDOCKSETTINGOBJECT_H
#define LOCDOCKSETTINGOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT LocDockSettingObject : public TSqlObject, public QSharedData
{
public:
    int loc_id {0};
    bool default_dock_bool;
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        LocId = 0,
        DefaultDockBool,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<LocId; }
    int autoValueIndex() const override { return -1; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList<<LocId; }
    QString tableName() const override { return QLatin1String("loc_dock_setting"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int loc_id READ getloc_id WRITE setloc_id)
    T_DEFINE_PROPERTY(int, loc_id)
    Q_PROPERTY(bool default_dock_bool READ getdefault_dock_bool WRITE setdefault_dock_bool)
    T_DEFINE_PROPERTY(bool, default_dock_bool)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};

#endif // LOCDOCKSETTINGOBJECT_H
