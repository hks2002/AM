#ifndef ADVSRYVENDOROBJECT_H
#define ADVSRYVENDOROBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT AdvsryVendorObject : public TSqlObject, public QSharedData
{
public:
    int advsry_id {0};
    int vendor_id {0};
    bool active_bool;
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        AdvsryId = 0,
        VendorId,
        ActiveBool,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

public slots:
    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<AdvsryId<<VendorId; }
    int autoValueIndex() const override { return -1; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList<<VendorId<<AdvsryId; }
    QString tableName() const override { return QLatin1String("advsry_vendor"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int advsry_id READ getadvsry_id WRITE setadvsry_id)
    T_DEFINE_PROPERTY(int, advsry_id)
    Q_PROPERTY(int vendor_id READ getvendor_id WRITE setvendor_id)
    T_DEFINE_PROPERTY(int, vendor_id)
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


#endif // ADVSRYVENDOROBJECT_H
