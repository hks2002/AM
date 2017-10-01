#include <TreeFrogModel>
#include "warrantyeval.h"
#include "warrantyevalobject.h"
#include "userapp.h"
#include "refwarrantyevalstatus.h"
#include "warrantyinit.h"

WarrantyEval::WarrantyEval()
    : TAbstractModel(), d(new WarrantyEvalObject())
{
    d->warranty_eval_id = 0;
    d->warranty_init_id = 0;
    d->reject_by = 0;
}

WarrantyEval::WarrantyEval(const WarrantyEval &other)
    : TAbstractModel(), d(new WarrantyEvalObject(*other.d))
{ }

WarrantyEval::WarrantyEval(const WarrantyEvalObject &object)
    : TAbstractModel(), d(new WarrantyEvalObject(object))
{ }

WarrantyEval::~WarrantyEval()
{
    // If the reference count becomes 0,
    // the shared data object 'WarrantyEvalObject' is deleted.
}

int WarrantyEval::warrantyEvalId() const
{
    return d->warranty_eval_id;
}

int WarrantyEval::warrantyInitId() const
{
    return d->warranty_init_id;
}

void WarrantyEval::setWarrantyInitId(int warrantyInitId)
{
    d->warranty_init_id = warrantyInitId;
}

QString WarrantyEval::warrantyEvalStatusCd() const
{
    return d->warranty_eval_status_cd;
}

void WarrantyEval::setWarrantyEvalStatusCd(const QString &warrantyEvalStatusCd)
{
    d->warranty_eval_status_cd = warrantyEvalStatusCd;
}

int WarrantyEval::rejectBy() const
{
    return d->reject_by;
}

void WarrantyEval::setRejectBy(int rejectBy)
{
    d->reject_by = rejectBy;
}

QDateTime WarrantyEval::rejectDt() const
{
    return d->reject_dt;
}

void WarrantyEval::setRejectDt(const QDateTime &rejectDt)
{
    d->reject_dt = rejectDt;
}

QDateTime WarrantyEval::createdAt() const
{
    return d->created_at;
}

QString WarrantyEval::createdBy() const
{
    return d->created_by;
}

void WarrantyEval::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime WarrantyEval::updatedAt() const
{
    return d->updated_at;
}

QString WarrantyEval::updatedBy() const
{
    return d->updated_by;
}

void WarrantyEval::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

UserApp WarrantyEval::userAppByrejectBy() const
{
 return UserApp::get(d->reject_by);
}

RefWarrantyEvalStatus WarrantyEval::refWarrantyEvalStatusBywarrantyEvalStatusCd() const
{
 return RefWarrantyEvalStatus::get(d->warranty_eval_status_cd);
}

WarrantyInit WarrantyEval::warrantyInitBywarrantyInitId() const
{
 return WarrantyInit::get(d->warranty_init_id);
}

WarrantyEval &WarrantyEval::operator=(const WarrantyEval &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

WarrantyEval WarrantyEval::create(int warrantyInitId, const QString &warrantyEvalStatusCd, int rejectBy, const QDateTime &rejectDt, const QString &createdBy, const QString &updatedBy)
{
    WarrantyEvalObject obj;
    obj.warranty_init_id = warrantyInitId;
    obj.warranty_eval_status_cd = warrantyEvalStatusCd;
    obj.reject_by = rejectBy;
    obj.reject_dt = rejectDt;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return WarrantyEval();
    }
    return WarrantyEval(obj);
}

WarrantyEval WarrantyEval::create(const QVariantMap &values)
{
    WarrantyEval model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

WarrantyEval WarrantyEval::get(int warrantyEvalId)
{
    TSqlORMapper<WarrantyEvalObject> mapper;
    return WarrantyEval(mapper.findByPrimaryKey(warrantyEvalId));
}

int WarrantyEval::count()
{
    TSqlORMapper<WarrantyEvalObject> mapper;
    return mapper.findCount();
}

QList<WarrantyEval> WarrantyEval::getAll()
{
    return tfGetModelListByCriteria<WarrantyEval, WarrantyEvalObject>();
}

TModelObject *WarrantyEval::modelData()
{
    return d.data();
}

const TModelObject *WarrantyEval::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const WarrantyEval &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, WarrantyEval &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(WarrantyEval)
