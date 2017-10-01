#include <TreeFrogModel>
#include "claimpartline.h"
#include "claimpartlineobject.h"
#include "invinv.h"
#include "warrantyevalpart.h"
#include "claim.h"

ClaimPartLine::ClaimPartLine()
    : TAbstractModel(), d(new ClaimPartLineObject())
{
    d->claim_id = 0;
    d->warranty_eval_id = 0;
    d->sched_id = 0;
    d->sched_part_id = 0;
    d->inv_no_id = 0;
    d->claim_qt = 0;
    d->unit_price = 0;
    d->line_price = 0;
}

ClaimPartLine::ClaimPartLine(const ClaimPartLine &other)
    : TAbstractModel(), d(new ClaimPartLineObject(*other.d))
{ }

ClaimPartLine::ClaimPartLine(const ClaimPartLineObject &object)
    : TAbstractModel(), d(new ClaimPartLineObject(object))
{ }

ClaimPartLine::~ClaimPartLine()
{
    // If the reference count becomes 0,
    // the shared data object 'ClaimPartLineObject' is deleted.
}

int ClaimPartLine::claimId() const
{
    return d->claim_id;
}

void ClaimPartLine::setClaimId(int claimId)
{
    d->claim_id = claimId;
}

int ClaimPartLine::warrantyEvalId() const
{
    return d->warranty_eval_id;
}

void ClaimPartLine::setWarrantyEvalId(int warrantyEvalId)
{
    d->warranty_eval_id = warrantyEvalId;
}

int ClaimPartLine::schedId() const
{
    return d->sched_id;
}

void ClaimPartLine::setSchedId(int schedId)
{
    d->sched_id = schedId;
}

int ClaimPartLine::schedPartId() const
{
    return d->sched_part_id;
}

void ClaimPartLine::setSchedPartId(int schedPartId)
{
    d->sched_part_id = schedPartId;
}

int ClaimPartLine::invNoId() const
{
    return d->inv_no_id;
}

void ClaimPartLine::setInvNoId(int invNoId)
{
    d->inv_no_id = invNoId;
}

QString ClaimPartLine::lineLdesc() const
{
    return d->line_ldesc;
}

void ClaimPartLine::setLineLdesc(const QString &lineLdesc)
{
    d->line_ldesc = lineLdesc;
}

int ClaimPartLine::claimQt() const
{
    return d->claim_qt;
}

void ClaimPartLine::setClaimQt(int claimQt)
{
    d->claim_qt = claimQt;
}

double ClaimPartLine::unitPrice() const
{
    return d->unit_price;
}

void ClaimPartLine::setUnitPrice(double unitPrice)
{
    d->unit_price = unitPrice;
}

double ClaimPartLine::linePrice() const
{
    return d->line_price;
}

void ClaimPartLine::setLinePrice(double linePrice)
{
    d->line_price = linePrice;
}

QString ClaimPartLine::note() const
{
    return d->note;
}

void ClaimPartLine::setNote(const QString &note)
{
    d->note = note;
}

bool ClaimPartLine::rejectWarrantyBool() const
{
    return d->reject_warranty_bool;
}

void ClaimPartLine::setRejectWarrantyBool(bool rejectWarrantyBool)
{
    d->reject_warranty_bool = rejectWarrantyBool;
}

QDateTime ClaimPartLine::createdAt() const
{
    return d->created_at;
}

QString ClaimPartLine::createdBy() const
{
    return d->created_by;
}

void ClaimPartLine::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime ClaimPartLine::updatedAt() const
{
    return d->updated_at;
}

QString ClaimPartLine::updatedBy() const
{
    return d->updated_by;
}

void ClaimPartLine::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

InvInv ClaimPartLine::invInvByinvNoId() const
{
 return InvInv::get(d->inv_no_id);
}

WarrantyEvalPart ClaimPartLine::warrantyEvalPartBywarrantyEvalIdschedIdschedPartId() const
{
 return WarrantyEvalPart::get(d->warranty_eval_id, d->sched_id, d->sched_part_id);
}

Claim ClaimPartLine::claimByclaimId() const
{
 return Claim::get(d->claim_id);
}

ClaimPartLine &ClaimPartLine::operator=(const ClaimPartLine &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

ClaimPartLine ClaimPartLine::create(int claimId, int warrantyEvalId, int schedId, int schedPartId, int invNoId, const QString &lineLdesc, int claimQt, double unitPrice, double linePrice, const QString &note, bool rejectWarrantyBool, const QString &createdBy, const QString &updatedBy)
{
    ClaimPartLineObject obj;
    obj.claim_id = claimId;
    obj.warranty_eval_id = warrantyEvalId;
    obj.sched_id = schedId;
    obj.sched_part_id = schedPartId;
    obj.inv_no_id = invNoId;
    obj.line_ldesc = lineLdesc;
    obj.claim_qt = claimQt;
    obj.unit_price = unitPrice;
    obj.line_price = linePrice;
    obj.note = note;
    obj.reject_warranty_bool = rejectWarrantyBool;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return ClaimPartLine();
    }
    return ClaimPartLine(obj);
}

ClaimPartLine ClaimPartLine::create(const QVariantMap &values)
{
    ClaimPartLine model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

ClaimPartLine ClaimPartLine::get(int claimId, int warrantyEvalId)
{
    TSqlORMapper<ClaimPartLineObject> mapper;
    return ClaimPartLine(mapper.findByPrimaryKey(QVariantList()<<QVariant(claimId)<<QVariant(warrantyEvalId)));
}

int ClaimPartLine::count()
{
    TSqlORMapper<ClaimPartLineObject> mapper;
    return mapper.findCount();
}

QList<ClaimPartLine> ClaimPartLine::getAll()
{
    return tfGetModelListByCriteria<ClaimPartLine, ClaimPartLineObject>();
}

TModelObject *ClaimPartLine::modelData()
{
    return d.data();
}

const TModelObject *ClaimPartLine::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const ClaimPartLine &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, ClaimPartLine &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(ClaimPartLine)
