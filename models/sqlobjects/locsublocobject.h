#ifndef LOCSUBLOCOBJECT_H
#define LOCSUBLOCOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT LocSublocObject : public TSqlObject, public QSharedData
{
public:
    int loc_id {0};
    int sub_loc_id {0};
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        LocId = 0,
        SubLocId,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<LocId<<SubLocId; }
    int autoValueIndex() const override { return -1; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList<<SubLocId<<LocId; }
    QString tableName() const override { return QLatin1String("loc_subloc"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int loc_id READ getloc_id WRITE setloc_id)
    T_DEFINE_PROPERTY(int, loc_id)
    Q_PROPERTY(int sub_loc_id READ getsub_loc_id WRITE setsub_loc_id)
    T_DEFINE_PROPERTY(int, sub_loc_id)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};

#endif // LOCSUBLOCOBJECT_H
