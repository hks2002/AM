#include <TreeFrogModel>
#include "claim.h"
#include "claimobject.h"
#include "userapp.h"
#include "invinv.h"
#include "vendor.h"
#include "warrantyeval.h"
#include "transportor.h"
#include "refclaimto.h"

Claim::Claim()
    : TAbstractModel(), d(new ClaimObject())
{
    d->claim_id = 0;
    d->transportor_id = 0;
    d->warranty_eval_id = 0;
    d->vendor_id = 0;
    d->inv_no_id = 0;
    d->contact_to = 0;
    d->total_requested_qt = 0;
    d->total_recovered_qt = 0;
}

Claim::Claim(const Claim &other)
    : TAbstractModel(), d(new ClaimObject(*other.d))
{ }

Claim::Claim(const ClaimObject &object)
    : TAbstractModel(), d(new ClaimObject(object))
{ }

Claim::~Claim()
{
    // If the reference count becomes 0,
    // the shared data object 'ClaimObject' is deleted.
}

int Claim::claimId() const
{
    return d->claim_id;
}

QString Claim::claimToCd() const
{
    return d->claim_to_cd;
}

void Claim::setClaimToCd(const QString &claimToCd)
{
    d->claim_to_cd = claimToCd;
}

int Claim::transportorId() const
{
    return d->transportor_id;
}

void Claim::setTransportorId(int transportorId)
{
    d->transportor_id = transportorId;
}

int Claim::warrantyEvalId() const
{
    return d->warranty_eval_id;
}

void Claim::setWarrantyEvalId(int warrantyEvalId)
{
    d->warranty_eval_id = warrantyEvalId;
}

int Claim::vendorId() const
{
    return d->vendor_id;
}

void Claim::setVendorId(int vendorId)
{
    d->vendor_id = vendorId;
}

int Claim::invNoId() const
{
    return d->inv_no_id;
}

void Claim::setInvNoId(int invNoId)
{
    d->inv_no_id = invNoId;
}

int Claim::contactTo() const
{
    return d->contact_to;
}

void Claim::setContactTo(int contactTo)
{
    d->contact_to = contactTo;
}

QString Claim::creditRefDesc() const
{
    return d->credit_ref_desc;
}

void Claim::setCreditRefDesc(const QString &creditRefDesc)
{
    d->credit_ref_desc = creditRefDesc;
}

int Claim::totalRequestedQt() const
{
    return d->total_requested_qt;
}

void Claim::setTotalRequestedQt(int totalRequestedQt)
{
    d->total_requested_qt = totalRequestedQt;
}

int Claim::totalRecoveredQt() const
{
    return d->total_recovered_qt;
}

void Claim::setTotalRecoveredQt(int totalRecoveredQt)
{
    d->total_recovered_qt = totalRecoveredQt;
}

QString Claim::claimNote() const
{
    return d->claim_note;
}

void Claim::setClaimNote(const QString &claimNote)
{
    d->claim_note = claimNote;
}

QDateTime Claim::createdAt() const
{
    return d->created_at;
}

QString Claim::createdBy() const
{
    return d->created_by;
}

void Claim::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime Claim::updatedAt() const
{
    return d->updated_at;
}

QString Claim::updatedBy() const
{
    return d->updated_by;
}

void Claim::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

UserApp Claim::userAppBycontactTo() const
{
 return UserApp::get(d->contact_to);
}

InvInv Claim::invInvByinvNoId() const
{
 return InvInv::get(d->inv_no_id);
}

Vendor Claim::vendorByvendorId() const
{
 return Vendor::get(d->vendor_id);
}

WarrantyEval Claim::warrantyEvalBywarrantyEvalId() const
{
 return WarrantyEval::get(d->warranty_eval_id);
}

Transportor Claim::transportorBytransportorId() const
{
 return Transportor::get(d->transportor_id);
}

RefClaimTo Claim::refClaimToByclaimToCd() const
{
 return RefClaimTo::get(d->claim_to_cd);
}

Claim &Claim::operator=(const Claim &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

Claim Claim::create(const QString &claimToCd, int transportorId, int warrantyEvalId, int vendorId, int invNoId, int contactTo, const QString &creditRefDesc, int totalRequestedQt, int totalRecoveredQt, const QString &claimNote, const QString &createdBy, const QString &updatedBy)
{
    ClaimObject obj;
    obj.claim_to_cd = claimToCd;
    obj.transportor_id = transportorId;
    obj.warranty_eval_id = warrantyEvalId;
    obj.vendor_id = vendorId;
    obj.inv_no_id = invNoId;
    obj.contact_to = contactTo;
    obj.credit_ref_desc = creditRefDesc;
    obj.total_requested_qt = totalRequestedQt;
    obj.total_recovered_qt = totalRecoveredQt;
    obj.claim_note = claimNote;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return Claim();
    }
    return Claim(obj);
}

Claim Claim::create(const QVariantMap &values)
{
    Claim model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

Claim Claim::get(int claimId)
{
    TSqlORMapper<ClaimObject> mapper;
    return Claim(mapper.findByPrimaryKey(claimId));
}

int Claim::count()
{
    TSqlORMapper<ClaimObject> mapper;
    return mapper.findCount();
}

QList<Claim> Claim::getAll()
{
    return tfGetModelListByCriteria<Claim, ClaimObject>();
}

TModelObject *Claim::modelData()
{
    return d.data();
}

const TModelObject *Claim::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const Claim &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, Claim &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(Claim)
