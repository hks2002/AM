#ifndef LOCWORKTYPECAPABILITYOBJECT_H
#define LOCWORKTYPECAPABILITYOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT LocWorkTypeCapabilityObject : public TSqlObject, public QSharedData
{
public:
    int loc_id {0};
    int assmbl_id {0};
    int work_type_id {0};
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        LocId = 0,
        AssmblId,
        WorkTypeId,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

public slots:
    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<LocId<<AssmblId<<WorkTypeId; }
    int autoValueIndex() const override { return -1; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList<<WorkTypeId<<AssmblId<<LocId; }
    QString tableName() const override { return QLatin1String("loc_work_type_capability"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int loc_id READ getloc_id WRITE setloc_id)
    T_DEFINE_PROPERTY(int, loc_id)
    Q_PROPERTY(int assmbl_id READ getassmbl_id WRITE setassmbl_id)
    T_DEFINE_PROPERTY(int, assmbl_id)
    Q_PROPERTY(int work_type_id READ getwork_type_id WRITE setwork_type_id)
    T_DEFINE_PROPERTY(int, work_type_id)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};


#endif // LOCWORKTYPECAPABILITYOBJECT_H
