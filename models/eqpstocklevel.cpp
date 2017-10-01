#include <TreeFrogModel>
#include "eqpstocklevel.h"
#include "eqpstocklevelobject.h"
#include "refstocklowactn.h"
#include "ownerapp.h"
#include "loc.h"
#include "eqpstock.h"

EqpStockLevel::EqpStockLevel()
    : TAbstractModel(), d(new EqpStockLevelObject())
{
    d->stock_id = 0;
    d->loc_id = 0;
    d->owner_id = 0;
    d->max_qt = 0;
    d->min_reorder_qt = 0;
    d->reorder_qt = 0;
}

EqpStockLevel::EqpStockLevel(const EqpStockLevel &other)
    : TAbstractModel(), d(new EqpStockLevelObject(*other.d))
{ }

EqpStockLevel::EqpStockLevel(const EqpStockLevelObject &object)
    : TAbstractModel(), d(new EqpStockLevelObject(object))
{ }

EqpStockLevel::~EqpStockLevel()
{
    // If the reference count becomes 0,
    // the shared data object 'EqpStockLevelObject' is deleted.
}

int EqpStockLevel::stockId() const
{
    return d->stock_id;
}

void EqpStockLevel::setStockId(int stockId)
{
    d->stock_id = stockId;
}

int EqpStockLevel::locId() const
{
    return d->loc_id;
}

void EqpStockLevel::setLocId(int locId)
{
    d->loc_id = locId;
}

int EqpStockLevel::ownerId() const
{
    return d->owner_id;
}

void EqpStockLevel::setOwnerId(int ownerId)
{
    d->owner_id = ownerId;
}

int EqpStockLevel::maxQt() const
{
    return d->max_qt;
}

void EqpStockLevel::setMaxQt(int maxQt)
{
    d->max_qt = maxQt;
}

int EqpStockLevel::minReorderQt() const
{
    return d->min_reorder_qt;
}

void EqpStockLevel::setMinReorderQt(int minReorderQt)
{
    d->min_reorder_qt = minReorderQt;
}

int EqpStockLevel::reorderQt() const
{
    return d->reorder_qt;
}

void EqpStockLevel::setReorderQt(int reorderQt)
{
    d->reorder_qt = reorderQt;
}

QString EqpStockLevel::stockLowActnCd() const
{
    return d->stock_low_actn_cd;
}

void EqpStockLevel::setStockLowActnCd(const QString &stockLowActnCd)
{
    d->stock_low_actn_cd = stockLowActnCd;
}

QDateTime EqpStockLevel::createdAt() const
{
    return d->created_at;
}

QString EqpStockLevel::createdBy() const
{
    return d->created_by;
}

void EqpStockLevel::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime EqpStockLevel::updatedAt() const
{
    return d->updated_at;
}

QString EqpStockLevel::updatedBy() const
{
    return d->updated_by;
}

void EqpStockLevel::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

RefStockLowActn EqpStockLevel::refStockLowActnBystockLowActnCd() const
{
 return RefStockLowActn::get(d->stock_low_actn_cd);
}

OwnerApp EqpStockLevel::ownerAppByownerId() const
{
 return OwnerApp::get(d->owner_id);
}

Loc EqpStockLevel::locBylocId() const
{
 return Loc::get(d->loc_id);
}

EqpStock EqpStockLevel::eqpStockBystockId() const
{
 return EqpStock::get(d->stock_id);
}

EqpStockLevel &EqpStockLevel::operator=(const EqpStockLevel &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

EqpStockLevel EqpStockLevel::create(int stockId, int locId, int ownerId, int maxQt, int minReorderQt, int reorderQt, const QString &stockLowActnCd, const QString &createdBy, const QString &updatedBy)
{
    EqpStockLevelObject obj;
    obj.stock_id = stockId;
    obj.loc_id = locId;
    obj.owner_id = ownerId;
    obj.max_qt = maxQt;
    obj.min_reorder_qt = minReorderQt;
    obj.reorder_qt = reorderQt;
    obj.stock_low_actn_cd = stockLowActnCd;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return EqpStockLevel();
    }
    return EqpStockLevel(obj);
}

EqpStockLevel EqpStockLevel::create(const QVariantMap &values)
{
    EqpStockLevel model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

EqpStockLevel EqpStockLevel::get(int stockId, int locId, int ownerId)
{
    TSqlORMapper<EqpStockLevelObject> mapper;
    return EqpStockLevel(mapper.findByPrimaryKey(QVariantList()<<QVariant(stockId)<<QVariant(locId)<<QVariant(ownerId)));
}

int EqpStockLevel::count()
{
    TSqlORMapper<EqpStockLevelObject> mapper;
    return mapper.findCount();
}

QList<EqpStockLevel> EqpStockLevel::getAll()
{
    return tfGetModelListByCriteria<EqpStockLevel, EqpStockLevelObject>();
}

TModelObject *EqpStockLevel::modelData()
{
    return d.data();
}

const TModelObject *EqpStockLevel::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const EqpStockLevel &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, EqpStockLevel &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(EqpStockLevel)
