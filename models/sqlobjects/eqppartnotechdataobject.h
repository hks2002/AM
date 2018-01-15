#ifndef EQPPARTNOTECHDATAOBJECT_H
#define EQPPARTNOTECHDATAOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT EqpPartNoTechDataObject : public TSqlObject, public QSharedData
{
public:
    int part_no_id {0};
    int mesur_unit_id {0};
    QString mesur_type_cd;
    double mesur_qt {0};
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        PartNoId = 0,
        MesurUnitId,
        MesurTypeCd,
        MesurQt,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

public slots:
    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<PartNoId<<MesurUnitId<<MesurTypeCd; }
    int autoValueIndex() const override { return -1; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList<<MesurTypeCd<<MesurUnitId<<PartNoId; }
    QString tableName() const override { return QLatin1String("eqp_part_no_tech_data"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int part_no_id READ getpart_no_id WRITE setpart_no_id)
    T_DEFINE_PROPERTY(int, part_no_id)
    Q_PROPERTY(int mesur_unit_id READ getmesur_unit_id WRITE setmesur_unit_id)
    T_DEFINE_PROPERTY(int, mesur_unit_id)
    Q_PROPERTY(QString mesur_type_cd READ getmesur_type_cd WRITE setmesur_type_cd)
    T_DEFINE_PROPERTY(QString, mesur_type_cd)
    Q_PROPERTY(double mesur_qt READ getmesur_qt WRITE setmesur_qt)
    T_DEFINE_PROPERTY(double, mesur_qt)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};


#endif // EQPPARTNOTECHDATAOBJECT_H
