#include <TreeFrogModel>
#include "reffaildefer.h"
#include "reffaildeferobject.h"

RefFailDefer::RefFailDefer()
    : TAbstractModel(), d(new RefFailDeferObject())
{ }

RefFailDefer::RefFailDefer(const RefFailDefer &other)
    : TAbstractModel(), d(new RefFailDeferObject(*other.d))
{ }

RefFailDefer::RefFailDefer(const RefFailDeferObject &object)
    : TAbstractModel(), d(new RefFailDeferObject(object))
{ }

RefFailDefer::~RefFailDefer()
{
    // If the reference count becomes 0,
    // the shared data object 'RefFailDeferObject' is deleted.
}

QString RefFailDefer::failDeferCd() const
{
    return d->fail_defer_cd;
}

void RefFailDefer::setFailDeferCd(const QString &failDeferCd)
{
    d->fail_defer_cd = failDeferCd;
}

QString RefFailDefer::failDeferNameEn() const
{
    return d->fail_defer_name_en;
}

void RefFailDefer::setFailDeferNameEn(const QString &failDeferNameEn)
{
    d->fail_defer_name_en = failDeferNameEn;
}

QString RefFailDefer::failDeferNameZh() const
{
    return d->fail_defer_name_zh;
}

void RefFailDefer::setFailDeferNameZh(const QString &failDeferNameZh)
{
    d->fail_defer_name_zh = failDeferNameZh;
}

QString RefFailDefer::failDeferDesc() const
{
    return d->fail_defer_desc;
}

void RefFailDefer::setFailDeferDesc(const QString &failDeferDesc)
{
    d->fail_defer_desc = failDeferDesc;
}

QDateTime RefFailDefer::createdAt() const
{
    return d->created_at;
}

QString RefFailDefer::createdBy() const
{
    return d->created_by;
}

void RefFailDefer::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime RefFailDefer::updatedAt() const
{
    return d->updated_at;
}

QString RefFailDefer::updatedBy() const
{
    return d->updated_by;
}

void RefFailDefer::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

RefFailDefer &RefFailDefer::operator=(const RefFailDefer &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

RefFailDefer RefFailDefer::create(const QString &failDeferCd, const QString &failDeferNameEn, const QString &failDeferNameZh, const QString &failDeferDesc, const QString &createdBy, const QString &updatedBy)
{
    RefFailDeferObject obj;
    obj.fail_defer_cd = failDeferCd;
    obj.fail_defer_name_en = failDeferNameEn;
    obj.fail_defer_name_zh = failDeferNameZh;
    obj.fail_defer_desc = failDeferDesc;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return RefFailDefer();
    }
    return RefFailDefer(obj);
}

RefFailDefer RefFailDefer::create(const QVariantMap &values)
{
    RefFailDefer model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

RefFailDefer RefFailDefer::get(const QString &failDeferCd)
{
    TSqlORMapper<RefFailDeferObject> mapper;
    return RefFailDefer(mapper.findByPrimaryKey(failDeferCd));
}

int RefFailDefer::count()
{
    TSqlORMapper<RefFailDeferObject> mapper;
    return mapper.findCount();
}

QList<RefFailDefer> RefFailDefer::getAll()
{
    return tfGetModelListByCriteria<RefFailDefer, RefFailDeferObject>();
}

TModelObject *RefFailDefer::modelData()
{
    return d.data();
}

const TModelObject *RefFailDefer::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const RefFailDefer &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, RefFailDefer &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(RefFailDefer)
