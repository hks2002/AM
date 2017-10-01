#ifndef EQPPARTNORELIABOBJECT_H
#define EQPPARTNORELIABOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT EqpPartNoReliabObject : public TSqlObject, public QSharedData
{
public:
    int part_no_id {0};
    QString eng_unit_cd;
    double mtbf_qt {0};
    double mtbr_qt {0};
    double mtbur_qt {0};
    double mttr_qt {0};
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        PartNoId = 0,
        EngUnitCd,
        MtbfQt,
        MtbrQt,
        MtburQt,
        MttrQt,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<PartNoId<<EngUnitCd; }
    int autoValueIndex() const override { return -1; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList<<EngUnitCd<<PartNoId; }
    QString tableName() const override { return QLatin1String("eqp_part_no_reliab"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int part_no_id READ getpart_no_id WRITE setpart_no_id)
    T_DEFINE_PROPERTY(int, part_no_id)
    Q_PROPERTY(QString eng_unit_cd READ geteng_unit_cd WRITE seteng_unit_cd)
    T_DEFINE_PROPERTY(QString, eng_unit_cd)
    Q_PROPERTY(double mtbf_qt READ getmtbf_qt WRITE setmtbf_qt)
    T_DEFINE_PROPERTY(double, mtbf_qt)
    Q_PROPERTY(double mtbr_qt READ getmtbr_qt WRITE setmtbr_qt)
    T_DEFINE_PROPERTY(double, mtbr_qt)
    Q_PROPERTY(double mtbur_qt READ getmtbur_qt WRITE setmtbur_qt)
    T_DEFINE_PROPERTY(double, mtbur_qt)
    Q_PROPERTY(double mttr_qt READ getmttr_qt WRITE setmttr_qt)
    T_DEFINE_PROPERTY(double, mttr_qt)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};

#endif // EQPPARTNORELIABOBJECT_H
