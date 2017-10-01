#include <TreeFrogModel>
#include "reffailsevdefer.h"
#include "reffailsevdeferobject.h"
#include "reffaildefer.h"
#include "reffailsev.h"

RefFailSevDefer::RefFailSevDefer()
    : TAbstractModel(), d(new RefFailSevDeferObject())
{ }

RefFailSevDefer::RefFailSevDefer(const RefFailSevDefer &other)
    : TAbstractModel(), d(new RefFailSevDeferObject(*other.d))
{ }

RefFailSevDefer::RefFailSevDefer(const RefFailSevDeferObject &object)
    : TAbstractModel(), d(new RefFailSevDeferObject(object))
{ }

RefFailSevDefer::~RefFailSevDefer()
{
    // If the reference count becomes 0,
    // the shared data object 'RefFailSevDeferObject' is deleted.
}

QString RefFailSevDefer::failSevCd() const
{
    return d->fail_sev_cd;
}

void RefFailSevDefer::setFailSevCd(const QString &failSevCd)
{
    d->fail_sev_cd = failSevCd;
}

QString RefFailSevDefer::failDeferCd() const
{
    return d->fail_defer_cd;
}

void RefFailSevDefer::setFailDeferCd(const QString &failDeferCd)
{
    d->fail_defer_cd = failDeferCd;
}

QDateTime RefFailSevDefer::createdAt() const
{
    return d->created_at;
}

QString RefFailSevDefer::createdBy() const
{
    return d->created_by;
}

void RefFailSevDefer::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime RefFailSevDefer::updatedAt() const
{
    return d->updated_at;
}

QString RefFailSevDefer::updatedBy() const
{
    return d->updated_by;
}

void RefFailSevDefer::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

RefFailDefer RefFailSevDefer::refFailDeferByfailDeferCd() const
{
 return RefFailDefer::get(d->fail_defer_cd);
}

RefFailSev RefFailSevDefer::refFailSevByfailSevCd() const
{
 return RefFailSev::get(d->fail_sev_cd);
}

RefFailSevDefer &RefFailSevDefer::operator=(const RefFailSevDefer &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

RefFailSevDefer RefFailSevDefer::create(const QString &failSevCd, const QString &failDeferCd, const QString &createdBy, const QString &updatedBy)
{
    RefFailSevDeferObject obj;
    obj.fail_sev_cd = failSevCd;
    obj.fail_defer_cd = failDeferCd;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return RefFailSevDefer();
    }
    return RefFailSevDefer(obj);
}

RefFailSevDefer RefFailSevDefer::create(const QVariantMap &values)
{
    RefFailSevDefer model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

RefFailSevDefer RefFailSevDefer::get(const QString &failSevCd, const QString &failDeferCd)
{
    TSqlORMapper<RefFailSevDeferObject> mapper;
    return RefFailSevDefer(mapper.findByPrimaryKey(QVariantList()<<QVariant(failSevCd)<<QVariant(failDeferCd)));
}

int RefFailSevDefer::count()
{
    TSqlORMapper<RefFailSevDeferObject> mapper;
    return mapper.findCount();
}

QList<RefFailSevDefer> RefFailSevDefer::getAll()
{
    return tfGetModelListByCriteria<RefFailSevDefer, RefFailSevDeferObject>();
}

TModelObject *RefFailSevDefer::modelData()
{
    return d.data();
}

const TModelObject *RefFailSevDefer::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const RefFailSevDefer &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, RefFailSevDefer &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(RefFailSevDefer)
