#ifndef REFPAYMENTTERMS_H
#define REFPAYMENTTERMS_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class RefPaymentTermsObject;


class T_MODEL_EXPORT RefPaymentTerms : public TAbstractModel
{
public:
    RefPaymentTerms();
    RefPaymentTerms(const RefPaymentTerms &other);
    RefPaymentTerms(const RefPaymentTermsObject &object);
    ~RefPaymentTerms();

    QString paymentTermsCd() const;
    void setPaymentTermsCd(const QString &paymentTermsCd);
    QString paymentTermsNameEn() const;
    void setPaymentTermsNameEn(const QString &paymentTermsNameEn);
    QString paymentTermsNameZh() const;
    void setPaymentTermsNameZh(const QString &paymentTermsNameZh);
    QString paymentTermsDesc() const;
    void setPaymentTermsDesc(const QString &paymentTermsDesc);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    RefPaymentTerms &operator=(const RefPaymentTerms &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static RefPaymentTerms create(const QString &paymentTermsCd, const QString &paymentTermsNameEn, const QString &paymentTermsNameZh, const QString &paymentTermsDesc, const QString &createdBy, const QString &updatedBy);
    static RefPaymentTerms create(const QVariantMap &values);
    static RefPaymentTerms get(const QString &paymentTermsCd);
    static int count();
    static QList<RefPaymentTerms> getAll();

private:
    QSharedDataPointer<RefPaymentTermsObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const RefPaymentTerms &model);
    friend QDataStream &operator>>(QDataStream &ds, RefPaymentTerms &model);
};

Q_DECLARE_METATYPE(RefPaymentTerms)
Q_DECLARE_METATYPE(QList<RefPaymentTerms>)

#endif // REFPAYMENTTERMS_H
