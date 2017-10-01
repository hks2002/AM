#include <TreeFrogModel>
#include "orgvendorapproval.h"
#include "orgvendorapprovalobject.h"
#include "refvendortype.h"
#include "vendor.h"
#include "org.h"

OrgVendorApproval::OrgVendorApproval()
    : TAbstractModel(), d(new OrgVendorApprovalObject())
{
    d->org_id = 0;
    d->vendor_id = 0;
}

OrgVendorApproval::OrgVendorApproval(const OrgVendorApproval &other)
    : TAbstractModel(), d(new OrgVendorApprovalObject(*other.d))
{ }

OrgVendorApproval::OrgVendorApproval(const OrgVendorApprovalObject &object)
    : TAbstractModel(), d(new OrgVendorApprovalObject(object))
{ }

OrgVendorApproval::~OrgVendorApproval()
{
    // If the reference count becomes 0,
    // the shared data object 'OrgVendorApprovalObject' is deleted.
}

int OrgVendorApproval::orgId() const
{
    return d->org_id;
}

void OrgVendorApproval::setOrgId(int orgId)
{
    d->org_id = orgId;
}

int OrgVendorApproval::vendorId() const
{
    return d->vendor_id;
}

void OrgVendorApproval::setVendorId(int vendorId)
{
    d->vendor_id = vendorId;
}

QString OrgVendorApproval::vendorTypeCd() const
{
    return d->vendor_type_cd;
}

void OrgVendorApproval::setVendorTypeCd(const QString &vendorTypeCd)
{
    d->vendor_type_cd = vendorTypeCd;
}

QString OrgVendorApproval::approvalCd() const
{
    return d->approval_cd;
}

void OrgVendorApproval::setApprovalCd(const QString &approvalCd)
{
    d->approval_cd = approvalCd;
}

QDateTime OrgVendorApproval::approvalExpiryDt() const
{
    return d->approval_expiry_dt;
}

void OrgVendorApproval::setApprovalExpiryDt(const QDateTime &approvalExpiryDt)
{
    d->approval_expiry_dt = approvalExpiryDt;
}

bool OrgVendorApproval::activeBool() const
{
    return d->active_bool;
}

void OrgVendorApproval::setActiveBool(bool activeBool)
{
    d->active_bool = activeBool;
}

QDateTime OrgVendorApproval::createdAt() const
{
    return d->created_at;
}

QString OrgVendorApproval::createdBy() const
{
    return d->created_by;
}

void OrgVendorApproval::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime OrgVendorApproval::updatedAt() const
{
    return d->updated_at;
}

QString OrgVendorApproval::updatedBy() const
{
    return d->updated_by;
}

void OrgVendorApproval::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

RefVendorType OrgVendorApproval::refVendorTypeByvendorTypeCd() const
{
 return RefVendorType::get(d->vendor_type_cd);
}

Vendor OrgVendorApproval::vendorByvendorId() const
{
 return Vendor::get(d->vendor_id);
}

Org OrgVendorApproval::orgByorgId() const
{
 return Org::get(d->org_id);
}

OrgVendorApproval &OrgVendorApproval::operator=(const OrgVendorApproval &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

OrgVendorApproval OrgVendorApproval::create(int orgId, int vendorId, const QString &vendorTypeCd, const QString &approvalCd, const QDateTime &approvalExpiryDt, bool activeBool, const QString &createdBy, const QString &updatedBy)
{
    OrgVendorApprovalObject obj;
    obj.org_id = orgId;
    obj.vendor_id = vendorId;
    obj.vendor_type_cd = vendorTypeCd;
    obj.approval_cd = approvalCd;
    obj.approval_expiry_dt = approvalExpiryDt;
    obj.active_bool = activeBool;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return OrgVendorApproval();
    }
    return OrgVendorApproval(obj);
}

OrgVendorApproval OrgVendorApproval::create(const QVariantMap &values)
{
    OrgVendorApproval model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

OrgVendorApproval OrgVendorApproval::get(int orgId, int vendorId, const QString &vendorTypeCd)
{
    TSqlORMapper<OrgVendorApprovalObject> mapper;
    return OrgVendorApproval(mapper.findByPrimaryKey(QVariantList()<<QVariant(orgId)<<QVariant(vendorId)<<QVariant(vendorTypeCd)));
}

int OrgVendorApproval::count()
{
    TSqlORMapper<OrgVendorApprovalObject> mapper;
    return mapper.findCount();
}

QList<OrgVendorApproval> OrgVendorApproval::getAll()
{
    return tfGetModelListByCriteria<OrgVendorApproval, OrgVendorApprovalObject>();
}

TModelObject *OrgVendorApproval::modelData()
{
    return d.data();
}

const TModelObject *OrgVendorApproval::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const OrgVendorApproval &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, OrgVendorApproval &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(OrgVendorApproval)
