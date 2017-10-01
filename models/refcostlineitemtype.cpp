#include <TreeFrogModel>
#include "refcostlineitemtype.h"
#include "refcostlineitemtypeobject.h"

RefCostLineItemType::RefCostLineItemType()
    : TAbstractModel(), d(new RefCostLineItemTypeObject())
{ }

RefCostLineItemType::RefCostLineItemType(const RefCostLineItemType &other)
    : TAbstractModel(), d(new RefCostLineItemTypeObject(*other.d))
{ }

RefCostLineItemType::RefCostLineItemType(const RefCostLineItemTypeObject &object)
    : TAbstractModel(), d(new RefCostLineItemTypeObject(object))
{ }

RefCostLineItemType::~RefCostLineItemType()
{
    // If the reference count becomes 0,
    // the shared data object 'RefCostLineItemTypeObject' is deleted.
}

QString RefCostLineItemType::costLineItemTypeCd() const
{
    return d->cost_line_item_type_cd;
}

void RefCostLineItemType::setCostLineItemTypeCd(const QString &costLineItemTypeCd)
{
    d->cost_line_item_type_cd = costLineItemTypeCd;
}

QString RefCostLineItemType::costLineItemTypeNameEn() const
{
    return d->cost_line_item_type_name_en;
}

void RefCostLineItemType::setCostLineItemTypeNameEn(const QString &costLineItemTypeNameEn)
{
    d->cost_line_item_type_name_en = costLineItemTypeNameEn;
}

QString RefCostLineItemType::costLineItemTypeNameZh() const
{
    return d->cost_line_item_type_name_zh;
}

void RefCostLineItemType::setCostLineItemTypeNameZh(const QString &costLineItemTypeNameZh)
{
    d->cost_line_item_type_name_zh = costLineItemTypeNameZh;
}

QString RefCostLineItemType::costLineItemTypeDesc() const
{
    return d->cost_line_item_type_desc;
}

void RefCostLineItemType::setCostLineItemTypeDesc(const QString &costLineItemTypeDesc)
{
    d->cost_line_item_type_desc = costLineItemTypeDesc;
}

QDateTime RefCostLineItemType::createdAt() const
{
    return d->created_at;
}

QString RefCostLineItemType::createdBy() const
{
    return d->created_by;
}

void RefCostLineItemType::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime RefCostLineItemType::updatedAt() const
{
    return d->updated_at;
}

QString RefCostLineItemType::updatedBy() const
{
    return d->updated_by;
}

void RefCostLineItemType::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

RefCostLineItemType &RefCostLineItemType::operator=(const RefCostLineItemType &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

RefCostLineItemType RefCostLineItemType::create(const QString &costLineItemTypeCd, const QString &costLineItemTypeNameEn, const QString &costLineItemTypeNameZh, const QString &costLineItemTypeDesc, const QString &createdBy, const QString &updatedBy)
{
    RefCostLineItemTypeObject obj;
    obj.cost_line_item_type_cd = costLineItemTypeCd;
    obj.cost_line_item_type_name_en = costLineItemTypeNameEn;
    obj.cost_line_item_type_name_zh = costLineItemTypeNameZh;
    obj.cost_line_item_type_desc = costLineItemTypeDesc;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return RefCostLineItemType();
    }
    return RefCostLineItemType(obj);
}

RefCostLineItemType RefCostLineItemType::create(const QVariantMap &values)
{
    RefCostLineItemType model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

RefCostLineItemType RefCostLineItemType::get(const QString &costLineItemTypeCd)
{
    TSqlORMapper<RefCostLineItemTypeObject> mapper;
    return RefCostLineItemType(mapper.findByPrimaryKey(costLineItemTypeCd));
}

int RefCostLineItemType::count()
{
    TSqlORMapper<RefCostLineItemTypeObject> mapper;
    return mapper.findCount();
}

QList<RefCostLineItemType> RefCostLineItemType::getAll()
{
    return tfGetModelListByCriteria<RefCostLineItemType, RefCostLineItemTypeObject>();
}

TModelObject *RefCostLineItemType::modelData()
{
    return d.data();
}

const TModelObject *RefCostLineItemType::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const RefCostLineItemType &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, RefCostLineItemType &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(RefCostLineItemType)
