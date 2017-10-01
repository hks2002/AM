#ifndef EVTVENDORPOTYPE_H
#define EVTVENDORPOTYPE_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class EvtVendorPoTypeObject;
class RefPoType;
class Org;
class Vendor;
class EvtEvent;


class T_MODEL_EXPORT EvtVendorPoType : public TAbstractModel
{
public:
    EvtVendorPoType();
    EvtVendorPoType(const EvtVendorPoType &other);
    EvtVendorPoType(const EvtVendorPoTypeObject &object);
    ~EvtVendorPoType();

    int eventId() const;
    void setEventId(int eventId);
    int vendorId() const;
    void setVendorId(int vendorId);
    int orgId() const;
    void setOrgId(int orgId);
    QString poTypeCd() const;
    void setPoTypeCd(const QString &poTypeCd);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    RefPoType refPoTypeBypoTypeCd() const;
    Org orgByorgId() const;
    Vendor vendorByvendorId() const;
    EvtEvent evtEventByeventId() const;
    EvtVendorPoType &operator=(const EvtVendorPoType &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static EvtVendorPoType create(int eventId, int vendorId, int orgId, const QString &poTypeCd, const QString &createdBy, const QString &updatedBy);
    static EvtVendorPoType create(const QVariantMap &values);
    static EvtVendorPoType get(int eventId, int vendorId);
    static int count();
    static QList<EvtVendorPoType> getAll();

private:
    QSharedDataPointer<EvtVendorPoTypeObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const EvtVendorPoType &model);
    friend QDataStream &operator>>(QDataStream &ds, EvtVendorPoType &model);
};

Q_DECLARE_METATYPE(EvtVendorPoType)
Q_DECLARE_METATYPE(QList<EvtVendorPoType>)

#endif // EVTVENDORPOTYPE_H
