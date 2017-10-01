#ifndef ADVSRYVENDOR_H
#define ADVSRYVENDOR_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class AdvsryVendorObject;
class Vendor;
class Advsry;


class T_MODEL_EXPORT AdvsryVendor : public TAbstractModel
{
public:
    AdvsryVendor();
    AdvsryVendor(const AdvsryVendor &other);
    AdvsryVendor(const AdvsryVendorObject &object);
    ~AdvsryVendor();

    int advsryId() const;
    void setAdvsryId(int advsryId);
    int vendorId() const;
    void setVendorId(int vendorId);
    bool activeBool() const;
    void setActiveBool(bool activeBool);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    Vendor vendorByvendorId() const;
    Advsry advsryByadvsryId() const;
    AdvsryVendor &operator=(const AdvsryVendor &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static AdvsryVendor create(int advsryId, int vendorId, bool activeBool, const QString &createdBy, const QString &updatedBy);
    static AdvsryVendor create(const QVariantMap &values);
    static AdvsryVendor get(int advsryId, int vendorId);
    static int count();
    static QList<AdvsryVendor> getAll();

private:
    QSharedDataPointer<AdvsryVendorObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const AdvsryVendor &model);
    friend QDataStream &operator>>(QDataStream &ds, AdvsryVendor &model);
};

Q_DECLARE_METATYPE(AdvsryVendor)
Q_DECLARE_METATYPE(QList<AdvsryVendor>)

#endif // ADVSRYVENDOR_H
