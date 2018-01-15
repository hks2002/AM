#ifndef INVCURRUSAGEOBJECT_H
#define INVCURRUSAGEOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT InvCurrUsageObject : public TSqlObject, public QSharedData
{
public:
    int inv_no_id {0};
    QString eng_unit_cd;
    double tsi_qt {0};
    double tsn_qt {0};
    double tso_qt {0};
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        InvNoId = 0,
        EngUnitCd,
        TsiQt,
        TsnQt,
        TsoQt,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

public slots:
    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<InvNoId<<EngUnitCd; }
    int autoValueIndex() const override { return -1; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList<<EngUnitCd<<InvNoId; }
    QString tableName() const override { return QLatin1String("inv_curr_usage"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int inv_no_id READ getinv_no_id WRITE setinv_no_id)
    T_DEFINE_PROPERTY(int, inv_no_id)
    Q_PROPERTY(QString eng_unit_cd READ geteng_unit_cd WRITE seteng_unit_cd)
    T_DEFINE_PROPERTY(QString, eng_unit_cd)
    Q_PROPERTY(double tsi_qt READ gettsi_qt WRITE settsi_qt)
    T_DEFINE_PROPERTY(double, tsi_qt)
    Q_PROPERTY(double tsn_qt READ gettsn_qt WRITE settsn_qt)
    T_DEFINE_PROPERTY(double, tsn_qt)
    Q_PROPERTY(double tso_qt READ gettso_qt WRITE settso_qt)
    T_DEFINE_PROPERTY(double, tso_qt)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};


#endif // INVCURRUSAGEOBJECT_H
