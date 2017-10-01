#include <TreeFrogModel>
#include "faildeferref.h"
#include "faildeferrefobject.h"
#include "reffailsev.h"
#include "reffaildefer.h"

FailDeferRef::FailDeferRef()
    : TAbstractModel(), d(new FailDeferRefObject())
{
    d->fail_defer_ref_id = 0;
}

FailDeferRef::FailDeferRef(const FailDeferRef &other)
    : TAbstractModel(), d(new FailDeferRefObject(*other.d))
{ }

FailDeferRef::FailDeferRef(const FailDeferRefObject &object)
    : TAbstractModel(), d(new FailDeferRefObject(object))
{ }

FailDeferRef::~FailDeferRef()
{
    // If the reference count becomes 0,
    // the shared data object 'FailDeferRefObject' is deleted.
}

int FailDeferRef::failDeferRefId() const
{
    return d->fail_defer_ref_id;
}

QString FailDeferRef::failDeferCd() const
{
    return d->fail_defer_cd;
}

void FailDeferRef::setFailDeferCd(const QString &failDeferCd)
{
    d->fail_defer_cd = failDeferCd;
}

QString FailDeferRef::deferRefName() const
{
    return d->defer_ref_name;
}

void FailDeferRef::setDeferRefName(const QString &deferRefName)
{
    d->defer_ref_name = deferRefName;
}

QString FailDeferRef::deferRefDesc() const
{
    return d->defer_ref_desc;
}

void FailDeferRef::setDeferRefDesc(const QString &deferRefDesc)
{
    d->defer_ref_desc = deferRefDesc;
}

QString FailDeferRef::failSevCd() const
{
    return d->fail_sev_cd;
}

void FailDeferRef::setFailSevCd(const QString &failSevCd)
{
    d->fail_sev_cd = failSevCd;
}

QDateTime FailDeferRef::createdAt() const
{
    return d->created_at;
}

QString FailDeferRef::createdBy() const
{
    return d->created_by;
}

void FailDeferRef::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime FailDeferRef::updatedAt() const
{
    return d->updated_at;
}

QString FailDeferRef::updatedBy() const
{
    return d->updated_by;
}

void FailDeferRef::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

RefFailSev FailDeferRef::refFailSevByfailSevCd() const
{
 return RefFailSev::get(d->fail_sev_cd);
}

RefFailDefer FailDeferRef::refFailDeferByfailDeferCd() const
{
 return RefFailDefer::get(d->fail_defer_cd);
}

FailDeferRef &FailDeferRef::operator=(const FailDeferRef &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

FailDeferRef FailDeferRef::create(const QString &failDeferCd, const QString &deferRefName, const QString &deferRefDesc, const QString &failSevCd, const QString &createdBy, const QString &updatedBy)
{
    FailDeferRefObject obj;
    obj.fail_defer_cd = failDeferCd;
    obj.defer_ref_name = deferRefName;
    obj.defer_ref_desc = deferRefDesc;
    obj.fail_sev_cd = failSevCd;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return FailDeferRef();
    }
    return FailDeferRef(obj);
}

FailDeferRef FailDeferRef::create(const QVariantMap &values)
{
    FailDeferRef model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

FailDeferRef FailDeferRef::get(int failDeferRefId)
{
    TSqlORMapper<FailDeferRefObject> mapper;
    return FailDeferRef(mapper.findByPrimaryKey(failDeferRefId));
}

int FailDeferRef::count()
{
    TSqlORMapper<FailDeferRefObject> mapper;
    return mapper.findCount();
}

QList<FailDeferRef> FailDeferRef::getAll()
{
    return tfGetModelListByCriteria<FailDeferRef, FailDeferRefObject>();
}

TModelObject *FailDeferRef::modelData()
{
    return d.data();
}

const TModelObject *FailDeferRef::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const FailDeferRef &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, FailDeferRef &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(FailDeferRef)
