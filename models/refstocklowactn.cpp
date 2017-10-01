#include <TreeFrogModel>
#include "refstocklowactn.h"
#include "refstocklowactnobject.h"

RefStockLowActn::RefStockLowActn()
    : TAbstractModel(), d(new RefStockLowActnObject())
{ }

RefStockLowActn::RefStockLowActn(const RefStockLowActn &other)
    : TAbstractModel(), d(new RefStockLowActnObject(*other.d))
{ }

RefStockLowActn::RefStockLowActn(const RefStockLowActnObject &object)
    : TAbstractModel(), d(new RefStockLowActnObject(object))
{ }

RefStockLowActn::~RefStockLowActn()
{
    // If the reference count becomes 0,
    // the shared data object 'RefStockLowActnObject' is deleted.
}

QString RefStockLowActn::stockLowActnCd() const
{
    return d->stock_low_actn_cd;
}

void RefStockLowActn::setStockLowActnCd(const QString &stockLowActnCd)
{
    d->stock_low_actn_cd = stockLowActnCd;
}

QString RefStockLowActn::stockLowActnNameEn() const
{
    return d->stock_low_actn_name_en;
}

void RefStockLowActn::setStockLowActnNameEn(const QString &stockLowActnNameEn)
{
    d->stock_low_actn_name_en = stockLowActnNameEn;
}

QString RefStockLowActn::stockLowActnNameZh() const
{
    return d->stock_low_actn_name_zh;
}

void RefStockLowActn::setStockLowActnNameZh(const QString &stockLowActnNameZh)
{
    d->stock_low_actn_name_zh = stockLowActnNameZh;
}

QString RefStockLowActn::stockLowActnDesc() const
{
    return d->stock_low_actn_desc;
}

void RefStockLowActn::setStockLowActnDesc(const QString &stockLowActnDesc)
{
    d->stock_low_actn_desc = stockLowActnDesc;
}

QDateTime RefStockLowActn::createdAt() const
{
    return d->created_at;
}

QString RefStockLowActn::createdBy() const
{
    return d->created_by;
}

void RefStockLowActn::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime RefStockLowActn::updatedAt() const
{
    return d->updated_at;
}

QString RefStockLowActn::updatedBy() const
{
    return d->updated_by;
}

void RefStockLowActn::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

RefStockLowActn &RefStockLowActn::operator=(const RefStockLowActn &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

RefStockLowActn RefStockLowActn::create(const QString &stockLowActnCd, const QString &stockLowActnNameEn, const QString &stockLowActnNameZh, const QString &stockLowActnDesc, const QString &createdBy, const QString &updatedBy)
{
    RefStockLowActnObject obj;
    obj.stock_low_actn_cd = stockLowActnCd;
    obj.stock_low_actn_name_en = stockLowActnNameEn;
    obj.stock_low_actn_name_zh = stockLowActnNameZh;
    obj.stock_low_actn_desc = stockLowActnDesc;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return RefStockLowActn();
    }
    return RefStockLowActn(obj);
}

RefStockLowActn RefStockLowActn::create(const QVariantMap &values)
{
    RefStockLowActn model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

RefStockLowActn RefStockLowActn::get(const QString &stockLowActnCd)
{
    TSqlORMapper<RefStockLowActnObject> mapper;
    return RefStockLowActn(mapper.findByPrimaryKey(stockLowActnCd));
}

int RefStockLowActn::count()
{
    TSqlORMapper<RefStockLowActnObject> mapper;
    return mapper.findCount();
}

QList<RefStockLowActn> RefStockLowActn::getAll()
{
    return tfGetModelListByCriteria<RefStockLowActn, RefStockLowActnObject>();
}

TModelObject *RefStockLowActn::modelData()
{
    return d.data();
}

const TModelObject *RefStockLowActn::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const RefStockLowActn &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, RefStockLowActn &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(RefStockLowActn)
