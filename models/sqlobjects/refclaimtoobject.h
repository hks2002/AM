#ifndef REFCLAIMTOOBJECT_H
#define REFCLAIMTOOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT RefClaimToObject : public TSqlObject, public QSharedData
{
public:
    QString claim_to_cd;
    QString claim_to_name_en;
    QString claim_to_name_zh;
    QString claim_to_desc;
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        ClaimToCd = 0,
        ClaimToNameEn,
        ClaimToNameZh,
        ClaimToDesc,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

public slots:
    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<ClaimToCd; }
    int autoValueIndex() const override { return -1; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList; }
    QString tableName() const override { return QLatin1String("ref_claim_to"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(QString claim_to_cd READ getclaim_to_cd WRITE setclaim_to_cd)
    T_DEFINE_PROPERTY(QString, claim_to_cd)
    Q_PROPERTY(QString claim_to_name_en READ getclaim_to_name_en WRITE setclaim_to_name_en)
    T_DEFINE_PROPERTY(QString, claim_to_name_en)
    Q_PROPERTY(QString claim_to_name_zh READ getclaim_to_name_zh WRITE setclaim_to_name_zh)
    T_DEFINE_PROPERTY(QString, claim_to_name_zh)
    Q_PROPERTY(QString claim_to_desc READ getclaim_to_desc WRITE setclaim_to_desc)
    T_DEFINE_PROPERTY(QString, claim_to_desc)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};


#endif // REFCLAIMTOOBJECT_H
