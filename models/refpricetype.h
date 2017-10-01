#ifndef REFPRICETYPE_H
#define REFPRICETYPE_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class RefPriceTypeObject;


class T_MODEL_EXPORT RefPriceType : public TAbstractModel
{
public:
    RefPriceType();
    RefPriceType(const RefPriceType &other);
    RefPriceType(const RefPriceTypeObject &object);
    ~RefPriceType();

    QString priceTypeCd() const;
    void setPriceTypeCd(const QString &priceTypeCd);
    QString priceTypeNameEn() const;
    void setPriceTypeNameEn(const QString &priceTypeNameEn);
    QString priceTypeNameZh() const;
    void setPriceTypeNameZh(const QString &priceTypeNameZh);
    QString priceTypeDesc() const;
    void setPriceTypeDesc(const QString &priceTypeDesc);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    RefPriceType &operator=(const RefPriceType &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static RefPriceType create(const QString &priceTypeCd, const QString &priceTypeNameEn, const QString &priceTypeNameZh, const QString &priceTypeDesc, const QString &createdBy, const QString &updatedBy);
    static RefPriceType create(const QVariantMap &values);
    static RefPriceType get(const QString &priceTypeCd);
    static int count();
    static QList<RefPriceType> getAll();

private:
    QSharedDataPointer<RefPriceTypeObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const RefPriceType &model);
    friend QDataStream &operator>>(QDataStream &ds, RefPriceType &model);
};

Q_DECLARE_METATYPE(RefPriceType)
Q_DECLARE_METATYPE(QList<RefPriceType>)

#endif // REFPRICETYPE_H
