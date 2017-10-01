#ifndef OWNERAPP_H
#define OWNERAPP_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class OwnerAppObject;
class Vendor;
class Org;
class RefOwnerType;


class T_MODEL_EXPORT OwnerApp : public TAbstractModel
{
public:
    OwnerApp();
    OwnerApp(const OwnerApp &other);
    OwnerApp(const OwnerAppObject &object);
    ~OwnerApp();

    int ownerId() const;
    QString ownerTypeCd() const;
    void setOwnerTypeCd(const QString &ownerTypeCd);
    int orgId() const;
    void setOrgId(int orgId);
    int vendorId() const;
    void setVendorId(int vendorId);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    Vendor vendorByvendorId() const;
    Org orgByorgId() const;
    RefOwnerType refOwnerTypeByownerTypeCd() const;
    OwnerApp &operator=(const OwnerApp &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static OwnerApp create(const QString &ownerTypeCd, int orgId, int vendorId, const QString &createdBy, const QString &updatedBy);
    static OwnerApp create(const QVariantMap &values);
    static OwnerApp get(int ownerId);
    static int count();
    static QList<OwnerApp> getAll();

private:
    QSharedDataPointer<OwnerAppObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const OwnerApp &model);
    friend QDataStream &operator>>(QDataStream &ds, OwnerApp &model);
};

Q_DECLARE_METATYPE(OwnerApp)
Q_DECLARE_METATYPE(QList<OwnerApp>)

#endif // OWNERAPP_H
