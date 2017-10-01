#ifndef EVTVENDOR_H
#define EVTVENDOR_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class EvtVendorObject;
class Vendor;
class EvtEvent;


class T_MODEL_EXPORT EvtVendor : public TAbstractModel
{
public:
    EvtVendor();
    EvtVendor(const EvtVendor &other);
    EvtVendor(const EvtVendorObject &object);
    ~EvtVendor();

    int eventId() const;
    void setEventId(int eventId);
    int vendorId() const;
    void setVendorId(int vendorId);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    Vendor vendorByvendorId() const;
    EvtEvent evtEventByeventId() const;
    EvtVendor &operator=(const EvtVendor &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static EvtVendor create(int eventId, int vendorId, const QString &createdBy, const QString &updatedBy);
    static EvtVendor create(const QVariantMap &values);
    static EvtVendor get(int eventId, int vendorId);
    static int count();
    static QList<EvtVendor> getAll();

private:
    QSharedDataPointer<EvtVendorObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const EvtVendor &model);
    friend QDataStream &operator>>(QDataStream &ds, EvtVendor &model);
};

Q_DECLARE_METATYPE(EvtVendor)
Q_DECLARE_METATYPE(QList<EvtVendor>)

#endif // EVTVENDOR_H
