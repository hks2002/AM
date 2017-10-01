#ifndef CURRENCY_H
#define CURRENCY_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class CurrencyObject;


class T_MODEL_EXPORT Currency : public TAbstractModel
{
public:
    Currency();
    Currency(const Currency &other);
    Currency(const CurrencyObject &object);
    ~Currency();

    int currencyId() const;
    QString currencyCd() const;
    void setCurrencyCd(const QString &currencyCd);
    QString currencyNameZh() const;
    void setCurrencyNameZh(const QString &currencyNameZh);
    QString currencyNameEn() const;
    void setCurrencyNameEn(const QString &currencyNameEn);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    Currency &operator=(const Currency &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static Currency create(const QString &currencyCd, const QString &currencyNameZh, const QString &currencyNameEn, const QString &createdBy, const QString &updatedBy);
    static Currency create(const QVariantMap &values);
    static Currency get(int currencyId);
    static int count();
    static QList<Currency> getAll();

private:
    QSharedDataPointer<CurrencyObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const Currency &model);
    friend QDataStream &operator>>(QDataStream &ds, Currency &model);
};

Q_DECLARE_METATYPE(Currency)
Q_DECLARE_METATYPE(QList<Currency>)

#endif // CURRENCY_H
