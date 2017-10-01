#ifndef REFVENDORTYPE_H
#define REFVENDORTYPE_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class RefVendorTypeObject;


class T_MODEL_EXPORT RefVendorType : public TAbstractModel
{
public:
    RefVendorType();
    RefVendorType(const RefVendorType &other);
    RefVendorType(const RefVendorTypeObject &object);
    ~RefVendorType();

    QString vendorTypeCd() const;
    void setVendorTypeCd(const QString &vendorTypeCd);
    QString vendorTypeNameEn() const;
    void setVendorTypeNameEn(const QString &vendorTypeNameEn);
    QString vendorTypeNameZh() const;
    void setVendorTypeNameZh(const QString &vendorTypeNameZh);
    QString vendorTypeDesc() const;
    void setVendorTypeDesc(const QString &vendorTypeDesc);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    RefVendorType &operator=(const RefVendorType &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static RefVendorType create(const QString &vendorTypeCd, const QString &vendorTypeNameEn, const QString &vendorTypeNameZh, const QString &vendorTypeDesc, const QString &createdBy, const QString &updatedBy);
    static RefVendorType create(const QVariantMap &values);
    static RefVendorType get(const QString &vendorTypeCd);
    static int count();
    static QList<RefVendorType> getAll();

private:
    QSharedDataPointer<RefVendorTypeObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const RefVendorType &model);
    friend QDataStream &operator>>(QDataStream &ds, RefVendorType &model);
};

Q_DECLARE_METATYPE(RefVendorType)
Q_DECLARE_METATYPE(QList<RefVendorType>)

#endif // REFVENDORTYPE_H
