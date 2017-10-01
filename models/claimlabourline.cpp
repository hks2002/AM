#include <TreeFrogModel>
#include "claimlabourline.h"
#include "claimlabourlineobject.h"
#include "warrantyevallabour.h"
#include "claim.h"

ClaimLabourLine::ClaimLabourLine()
    : TAbstractModel(), d(new ClaimLabourLineObject())
{
    d->claim_id = 0;
    d->warranty_eval_id = 0;
    d->sched_id = 0;
    d->labour_id = 0;
    d->claim_qt = 0;
    d->unit_price = 0;
    d->line_price = 0;
}

ClaimLabourLine::ClaimLabourLine(const ClaimLabourLine &other)
    : TAbstractModel(), d(new ClaimLabourLineObject(*other.d))
{ }

ClaimLabourLine::ClaimLabourLine(const ClaimLabourLineObject &object)
    : TAbstractModel(), d(new ClaimLabourLineObject(object))
{ }

ClaimLabourLine::~ClaimLabourLine()
{
    // If the reference count becomes 0,
    // the shared data object 'ClaimLabourLineObject' is deleted.
}

int ClaimLabourLine::claimId() const
{
    return d->claim_id;
}

void ClaimLabourLine::setClaimId(int claimId)
{
    d->claim_id = claimId;
}

int ClaimLabourLine::warrantyEvalId() const
{
    return d->warranty_eval_id;
}

void ClaimLabourLine::setWarrantyEvalId(int warrantyEvalId)
{
    d->warranty_eval_id = warrantyEvalId;
}

int ClaimLabourLine::schedId() const
{
    return d->sched_id;
}

void ClaimLabourLine::setSchedId(int schedId)
{
    d->sched_id = schedId;
}

int ClaimLabourLine::labourId() const
{
    return d->labour_id;
}

void ClaimLabourLine::setLabourId(int labourId)
{
    d->labour_id = labourId;
}

QString ClaimLabourLine::lineDesc() const
{
    return d->line_desc;
}

void ClaimLabourLine::setLineDesc(const QString &lineDesc)
{
    d->line_desc = lineDesc;
}

int ClaimLabourLine::claimQt() const
{
    return d->claim_qt;
}

void ClaimLabourLine::setClaimQt(int claimQt)
{
    d->claim_qt = claimQt;
}

double ClaimLabourLine::unitPrice() const
{
    return d->unit_price;
}

void ClaimLabourLine::setUnitPrice(double unitPrice)
{
    d->unit_price = unitPrice;
}

double ClaimLabourLine::linePrice() const
{
    return d->line_price;
}

void ClaimLabourLine::setLinePrice(double linePrice)
{
    d->line_price = linePrice;
}

QString ClaimLabourLine::note() const
{
    return d->note;
}

void ClaimLabourLine::setNote(const QString &note)
{
    d->note = note;
}

bool ClaimLabourLine::rejectWarrantyBool() const
{
    return d->reject_warranty_bool;
}

void ClaimLabourLine::setRejectWarrantyBool(bool rejectWarrantyBool)
{
    d->reject_warranty_bool = rejectWarrantyBool;
}

QDateTime ClaimLabourLine::createdAt() const
{
    return d->created_at;
}

QString ClaimLabourLine::createdBy() const
{
    return d->created_by;
}

void ClaimLabourLine::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime ClaimLabourLine::updatedAt() const
{
    return d->updated_at;
}

QString ClaimLabourLine::updatedBy() const
{
    return d->updated_by;
}

void ClaimLabourLine::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

WarrantyEvalLabour ClaimLabourLine::warrantyEvalLabourBywarrantyEvalIdschedIdlabourId() const
{
 return WarrantyEvalLabour::get(d->warranty_eval_id, d->sched_id, d->labour_id);
}

Claim ClaimLabourLine::claimByclaimId() const
{
 return Claim::get(d->claim_id);
}

ClaimLabourLine &ClaimLabourLine::operator=(const ClaimLabourLine &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

ClaimLabourLine ClaimLabourLine::create(int claimId, int warrantyEvalId, int schedId, int labourId, const QString &lineDesc, int claimQt, double unitPrice, double linePrice, const QString &note, bool rejectWarrantyBool, const QString &createdBy, const QString &updatedBy)
{
    ClaimLabourLineObject obj;
    obj.claim_id = claimId;
    obj.warranty_eval_id = warrantyEvalId;
    obj.sched_id = schedId;
    obj.labour_id = labourId;
    obj.line_desc = lineDesc;
    obj.claim_qt = claimQt;
    obj.unit_price = unitPrice;
    obj.line_price = linePrice;
    obj.note = note;
    obj.reject_warranty_bool = rejectWarrantyBool;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return ClaimLabourLine();
    }
    return ClaimLabourLine(obj);
}

ClaimLabourLine ClaimLabourLine::create(const QVariantMap &values)
{
    ClaimLabourLine model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

ClaimLabourLine ClaimLabourLine::get(int claimId, int warrantyEvalId)
{
    TSqlORMapper<ClaimLabourLineObject> mapper;
    return ClaimLabourLine(mapper.findByPrimaryKey(QVariantList()<<QVariant(claimId)<<QVariant(warrantyEvalId)));
}

int ClaimLabourLine::count()
{
    TSqlORMapper<ClaimLabourLineObject> mapper;
    return mapper.findCount();
}

QList<ClaimLabourLine> ClaimLabourLine::getAll()
{
    return tfGetModelListByCriteria<ClaimLabourLine, ClaimLabourLineObject>();
}

TModelObject *ClaimLabourLine::modelData()
{
    return d.data();
}

const TModelObject *ClaimLabourLine::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const ClaimLabourLine &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, ClaimLabourLine &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(ClaimLabourLine)
