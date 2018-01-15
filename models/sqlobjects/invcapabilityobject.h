#ifndef INVCAPABILITYOBJECT_H
#define INVCAPABILITYOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT InvCapabilityObject : public TSqlObject, public QSharedData
{
public:
    int inv_no_id {0};
    int capability_id {0};
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        InvNoId = 0,
        CapabilityId,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

public slots:
    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<InvNoId<<CapabilityId; }
    int autoValueIndex() const override { return -1; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList<<CapabilityId<<InvNoId; }
    QString tableName() const override { return QLatin1String("inv_capability"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int inv_no_id READ getinv_no_id WRITE setinv_no_id)
    T_DEFINE_PROPERTY(int, inv_no_id)
    Q_PROPERTY(int capability_id READ getcapability_id WRITE setcapability_id)
    T_DEFINE_PROPERTY(int, capability_id)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};


#endif // INVCAPABILITYOBJECT_H
