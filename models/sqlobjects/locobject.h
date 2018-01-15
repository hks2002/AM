#ifndef LOCOBJECT_H
#define LOCOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT LocObject : public TSqlObject, public QSharedData
{
public:
    int loc_id {0};
    QString loc_cd;
    QString loc_type_cd;
    QString loc_name;
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        LocId = 0,
        LocCd,
        LocTypeCd,
        LocName,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

public slots:
    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<LocId; }
    int autoValueIndex() const override { return LocId; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList<<LocTypeCd; }
    QString tableName() const override { return QLatin1String("loc"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int loc_id READ getloc_id WRITE setloc_id)
    T_DEFINE_PROPERTY(int, loc_id)
    Q_PROPERTY(QString loc_cd READ getloc_cd WRITE setloc_cd)
    T_DEFINE_PROPERTY(QString, loc_cd)
    Q_PROPERTY(QString loc_type_cd READ getloc_type_cd WRITE setloc_type_cd)
    T_DEFINE_PROPERTY(QString, loc_type_cd)
    Q_PROPERTY(QString loc_name READ getloc_name WRITE setloc_name)
    T_DEFINE_PROPERTY(QString, loc_name)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};


#endif // LOCOBJECT_H
