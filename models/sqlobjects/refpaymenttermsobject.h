#ifndef REFPAYMENTTERMSOBJECT_H
#define REFPAYMENTTERMSOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT RefPaymentTermsObject : public TSqlObject, public QSharedData
{
public:
    QString payment_terms_cd;
    QString payment_terms_name_en;
    QString payment_terms_name_zh;
    QString payment_terms_desc;
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        PaymentTermsCd = 0,
        PaymentTermsNameEn,
        PaymentTermsNameZh,
        PaymentTermsDesc,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

public slots:
    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<PaymentTermsCd; }
    int autoValueIndex() const override { return -1; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList; }
    QString tableName() const override { return QLatin1String("ref_payment_terms"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(QString payment_terms_cd READ getpayment_terms_cd WRITE setpayment_terms_cd)
    T_DEFINE_PROPERTY(QString, payment_terms_cd)
    Q_PROPERTY(QString payment_terms_name_en READ getpayment_terms_name_en WRITE setpayment_terms_name_en)
    T_DEFINE_PROPERTY(QString, payment_terms_name_en)
    Q_PROPERTY(QString payment_terms_name_zh READ getpayment_terms_name_zh WRITE setpayment_terms_name_zh)
    T_DEFINE_PROPERTY(QString, payment_terms_name_zh)
    Q_PROPERTY(QString payment_terms_desc READ getpayment_terms_desc WRITE setpayment_terms_desc)
    T_DEFINE_PROPERTY(QString, payment_terms_desc)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};


#endif // REFPAYMENTTERMSOBJECT_H
