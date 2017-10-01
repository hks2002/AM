#include <TreeFrogModel>
#include "refborrowrate.h"
#include "refborrowrateobject.h"

RefBorrowRate::RefBorrowRate()
    : TAbstractModel(), d(new RefBorrowRateObject())
{ }

RefBorrowRate::RefBorrowRate(const RefBorrowRate &other)
    : TAbstractModel(), d(new RefBorrowRateObject(*other.d))
{ }

RefBorrowRate::RefBorrowRate(const RefBorrowRateObject &object)
    : TAbstractModel(), d(new RefBorrowRateObject(object))
{ }

RefBorrowRate::~RefBorrowRate()
{
    // If the reference count becomes 0,
    // the shared data object 'RefBorrowRateObject' is deleted.
}

QString RefBorrowRate::borrowRateCd() const
{
    return d->borrow_rate_cd;
}

void RefBorrowRate::setBorrowRateCd(const QString &borrowRateCd)
{
    d->borrow_rate_cd = borrowRateCd;
}

QString RefBorrowRate::borrowRateNameEn() const
{
    return d->borrow_rate_name_en;
}

void RefBorrowRate::setBorrowRateNameEn(const QString &borrowRateNameEn)
{
    d->borrow_rate_name_en = borrowRateNameEn;
}

QString RefBorrowRate::borrowRateNameZh() const
{
    return d->borrow_rate_name_zh;
}

void RefBorrowRate::setBorrowRateNameZh(const QString &borrowRateNameZh)
{
    d->borrow_rate_name_zh = borrowRateNameZh;
}

QString RefBorrowRate::borrowRateDesc() const
{
    return d->borrow_rate_desc;
}

void RefBorrowRate::setBorrowRateDesc(const QString &borrowRateDesc)
{
    d->borrow_rate_desc = borrowRateDesc;
}

QDateTime RefBorrowRate::createdAt() const
{
    return d->created_at;
}

QString RefBorrowRate::createdBy() const
{
    return d->created_by;
}

void RefBorrowRate::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime RefBorrowRate::updatedAt() const
{
    return d->updated_at;
}

QString RefBorrowRate::updatedBy() const
{
    return d->updated_by;
}

void RefBorrowRate::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

RefBorrowRate &RefBorrowRate::operator=(const RefBorrowRate &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

RefBorrowRate RefBorrowRate::create(const QString &borrowRateCd, const QString &borrowRateNameEn, const QString &borrowRateNameZh, const QString &borrowRateDesc, const QString &createdBy, const QString &updatedBy)
{
    RefBorrowRateObject obj;
    obj.borrow_rate_cd = borrowRateCd;
    obj.borrow_rate_name_en = borrowRateNameEn;
    obj.borrow_rate_name_zh = borrowRateNameZh;
    obj.borrow_rate_desc = borrowRateDesc;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return RefBorrowRate();
    }
    return RefBorrowRate(obj);
}

RefBorrowRate RefBorrowRate::create(const QVariantMap &values)
{
    RefBorrowRate model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

RefBorrowRate RefBorrowRate::get(const QString &borrowRateCd)
{
    TSqlORMapper<RefBorrowRateObject> mapper;
    return RefBorrowRate(mapper.findByPrimaryKey(borrowRateCd));
}

int RefBorrowRate::count()
{
    TSqlORMapper<RefBorrowRateObject> mapper;
    return mapper.findCount();
}

QList<RefBorrowRate> RefBorrowRate::getAll()
{
    return tfGetModelListByCriteria<RefBorrowRate, RefBorrowRateObject>();
}

TModelObject *RefBorrowRate::modelData()
{
    return d.data();
}

const TModelObject *RefBorrowRate::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const RefBorrowRate &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, RefBorrowRate &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(RefBorrowRate)
