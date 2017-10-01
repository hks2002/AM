#ifndef RFQHEADEROBJECT_H
#define RFQHEADEROBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT RfqHeaderObject : public TSqlObject, public QSharedData
{
public:
    int rfq_id {0};
    QString rfq_cd;
    int contact_to {0};
    QDateTime rfq_issued_dt;
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        RfqId = 0,
        RfqCd,
        ContactTo,
        RfqIssuedDt,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<RfqId; }
    int autoValueIndex() const override { return RfqId; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList<<ContactTo; }
    QString tableName() const override { return QLatin1String("rfq_header"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int rfq_id READ getrfq_id WRITE setrfq_id)
    T_DEFINE_PROPERTY(int, rfq_id)
    Q_PROPERTY(QString rfq_cd READ getrfq_cd WRITE setrfq_cd)
    T_DEFINE_PROPERTY(QString, rfq_cd)
    Q_PROPERTY(int contact_to READ getcontact_to WRITE setcontact_to)
    T_DEFINE_PROPERTY(int, contact_to)
    Q_PROPERTY(QDateTime rfq_issued_dt READ getrfq_issued_dt WRITE setrfq_issued_dt)
    T_DEFINE_PROPERTY(QDateTime, rfq_issued_dt)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};

#endif // RFQHEADEROBJECT_H
