#ifndef ADVSRYPARTOBJECT_H
#define ADVSRYPARTOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT AdvsryPartObject : public TSqlObject, public QSharedData
{
public:
    int advsry_id {0};
    int manufact_id {0};
    int part_no_id {0};
    QString lot_no_range;
    QString serial_no_range;
    bool active_bool;
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        AdvsryId = 0,
        ManufactId,
        PartNoId,
        LotNoRange,
        SerialNoRange,
        ActiveBool,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<AdvsryId<<ManufactId<<PartNoId; }
    int autoValueIndex() const override { return -1; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList<<PartNoId<<ManufactId<<AdvsryId; }
    QString tableName() const override { return QLatin1String("advsry_part"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int advsry_id READ getadvsry_id WRITE setadvsry_id)
    T_DEFINE_PROPERTY(int, advsry_id)
    Q_PROPERTY(int manufact_id READ getmanufact_id WRITE setmanufact_id)
    T_DEFINE_PROPERTY(int, manufact_id)
    Q_PROPERTY(int part_no_id READ getpart_no_id WRITE setpart_no_id)
    T_DEFINE_PROPERTY(int, part_no_id)
    Q_PROPERTY(QString lot_no_range READ getlot_no_range WRITE setlot_no_range)
    T_DEFINE_PROPERTY(QString, lot_no_range)
    Q_PROPERTY(QString serial_no_range READ getserial_no_range WRITE setserial_no_range)
    T_DEFINE_PROPERTY(QString, serial_no_range)
    Q_PROPERTY(bool active_bool READ getactive_bool WRITE setactive_bool)
    T_DEFINE_PROPERTY(bool, active_bool)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};

#endif // ADVSRYPARTOBJECT_H
