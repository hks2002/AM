#ifndef OPERATIONCAPABILITYOBJECT_H
#define OPERATIONCAPABILITYOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT OperationCapabilityObject : public TSqlObject, public QSharedData
{
public:
    int capability_id {0};
    QString capability_cd;
    QString capability_name_zh;
    QString capability_name_en;
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        CapabilityId = 0,
        CapabilityCd,
        CapabilityNameZh,
        CapabilityNameEn,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<CapabilityId; }
    int autoValueIndex() const override { return CapabilityId; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList; }
    QString tableName() const override { return QLatin1String("operation_capability"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int capability_id READ getcapability_id WRITE setcapability_id)
    T_DEFINE_PROPERTY(int, capability_id)
    Q_PROPERTY(QString capability_cd READ getcapability_cd WRITE setcapability_cd)
    T_DEFINE_PROPERTY(QString, capability_cd)
    Q_PROPERTY(QString capability_name_zh READ getcapability_name_zh WRITE setcapability_name_zh)
    T_DEFINE_PROPERTY(QString, capability_name_zh)
    Q_PROPERTY(QString capability_name_en READ getcapability_name_en WRITE setcapability_name_en)
    T_DEFINE_PROPERTY(QString, capability_name_en)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};

#endif // OPERATIONCAPABILITYOBJECT_H
