#ifndef EQPASSMBLOILOBJECT_H
#define EQPASSMBLOILOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT EqpAssmblOilObject : public TSqlObject, public QSharedData
{
public:
    int assmbl_id {0};
    int mesur_unit_id {0};
    int data_type_id {0};
    double full_qty {0};
    double caution_rate {0};
    double warning_rate {0};
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        AssmblId = 0,
        MesurUnitId,
        DataTypeId,
        FullQty,
        CautionRate,
        WarningRate,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

public slots:
    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<AssmblId<<MesurUnitId<<DataTypeId; }
    int autoValueIndex() const override { return -1; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList<<MesurUnitId<<AssmblId<<DataTypeId; }
    QString tableName() const override { return QLatin1String("eqp_assmbl_oil"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int assmbl_id READ getassmbl_id WRITE setassmbl_id)
    T_DEFINE_PROPERTY(int, assmbl_id)
    Q_PROPERTY(int mesur_unit_id READ getmesur_unit_id WRITE setmesur_unit_id)
    T_DEFINE_PROPERTY(int, mesur_unit_id)
    Q_PROPERTY(int data_type_id READ getdata_type_id WRITE setdata_type_id)
    T_DEFINE_PROPERTY(int, data_type_id)
    Q_PROPERTY(double full_qty READ getfull_qty WRITE setfull_qty)
    T_DEFINE_PROPERTY(double, full_qty)
    Q_PROPERTY(double caution_rate READ getcaution_rate WRITE setcaution_rate)
    T_DEFINE_PROPERTY(double, caution_rate)
    Q_PROPERTY(double warning_rate READ getwarning_rate WRITE setwarning_rate)
    T_DEFINE_PROPERTY(double, warning_rate)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};


#endif // EQPASSMBLOILOBJECT_H
