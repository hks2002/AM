#include <TreeFrogModel>
#include "vendor.h"
#include "vendorobject.h"
#include "refvendorstatus.h"
#include "currency.h"

Vendor::Vendor()
    : TAbstractModel(), d(new VendorObject())
{
    d->vendor_id = 0;
    d->currency_id = 0;
}

Vendor::Vendor(const Vendor &other)
    : TAbstractModel(), d(new VendorObject(*other.d))
{ }

Vendor::Vendor(const VendorObject &object)
    : TAbstractModel(), d(new VendorObject(object))
{ }

Vendor::~Vendor()
{
    // If the reference count becomes 0,
    // the shared data object 'VendorObject' is deleted.
}

int Vendor::vendorId() const
{
    return d->vendor_id;
}

QString Vendor::vendorCd() const
{
    return d->vendor_cd;
}

void Vendor::setVendorCd(const QString &vendorCd)
{
    d->vendor_cd = vendorCd;
}

QString Vendor::vendorName() const
{
    return d->vendor_name;
}

void Vendor::setVendorName(const QString &vendorName)
{
    d->vendor_name = vendorName;
}

QString Vendor::certCd() const
{
    return d->cert_cd;
}

void Vendor::setCertCd(const QString &certCd)
{
    d->cert_cd = certCd;
}

QDateTime Vendor::certExpiryDt() const
{
    return d->cert_expiry_dt;
}

void Vendor::setCertExpiryDt(const QDateTime &certExpiryDt)
{
    d->cert_expiry_dt = certExpiryDt;
}

int Vendor::currencyId() const
{
    return d->currency_id;
}

void Vendor::setCurrencyId(int currencyId)
{
    d->currency_id = currencyId;
}

QString Vendor::receiveNote() const
{
    return d->receive_note;
}

void Vendor::setReceiveNote(const QString &receiveNote)
{
    d->receive_note = receiveNote;
}

QString Vendor::vendorNote() const
{
    return d->vendor_note;
}

void Vendor::setVendorNote(const QString &vendorNote)
{
    d->vendor_note = vendorNote;
}

QString Vendor::vendorStatusCd() const
{
    return d->vendor_status_cd;
}

void Vendor::setVendorStatusCd(const QString &vendorStatusCd)
{
    d->vendor_status_cd = vendorStatusCd;
}

QString Vendor::warningDesc() const
{
    return d->warning_desc;
}

void Vendor::setWarningDesc(const QString &warningDesc)
{
    d->warning_desc = warningDesc;
}

QDateTime Vendor::createdAt() const
{
    return d->created_at;
}

QString Vendor::createdBy() const
{
    return d->created_by;
}

void Vendor::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime Vendor::updatedAt() const
{
    return d->updated_at;
}

QString Vendor::updatedBy() const
{
    return d->updated_by;
}

void Vendor::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

RefVendorStatus Vendor::refVendorStatusByvendorStatusCd() const
{
 return RefVendorStatus::get(d->vendor_status_cd);
}

Currency Vendor::currencyBycurrencyId() const
{
 return Currency::get(d->currency_id);
}

Vendor &Vendor::operator=(const Vendor &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

Vendor Vendor::create(const QString &vendorCd, const QString &vendorName, const QString &certCd, const QDateTime &certExpiryDt, int currencyId, const QString &receiveNote, const QString &vendorNote, const QString &vendorStatusCd, const QString &warningDesc, const QString &createdBy, const QString &updatedBy)
{
    VendorObject obj;
    obj.vendor_cd = vendorCd;
    obj.vendor_name = vendorName;
    obj.cert_cd = certCd;
    obj.cert_expiry_dt = certExpiryDt;
    obj.currency_id = currencyId;
    obj.receive_note = receiveNote;
    obj.vendor_note = vendorNote;
    obj.vendor_status_cd = vendorStatusCd;
    obj.warning_desc = warningDesc;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return Vendor();
    }
    return Vendor(obj);
}

Vendor Vendor::create(const QVariantMap &values)
{
    Vendor model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

Vendor Vendor::get(int vendorId)
{
    TSqlORMapper<VendorObject> mapper;
    return Vendor(mapper.findByPrimaryKey(vendorId));
}

int Vendor::count()
{
    TSqlORMapper<VendorObject> mapper;
    return mapper.findCount();
}

QList<Vendor> Vendor::getAll()
{
    return tfGetModelListByCriteria<Vendor, VendorObject>();
}

TModelObject *Vendor::modelData()
{
    return d.data();
}

const TModelObject *Vendor::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const Vendor &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, Vendor &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(Vendor)
