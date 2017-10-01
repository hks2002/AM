#include <TreeFrogModel>
#include "invkitmap.h"
#include "invkitmapobject.h"
#include "invinv.h"
#include "invkit.h"

InvKitMap::InvKitMap()
    : TAbstractModel(), d(new InvKitMapObject())
{
    d->inv_kit_map_id = 0;
    d->kit_inv_no_id = 0;
    d->inv_no_id = 0;
}

InvKitMap::InvKitMap(const InvKitMap &other)
    : TAbstractModel(), d(new InvKitMapObject(*other.d))
{ }

InvKitMap::InvKitMap(const InvKitMapObject &object)
    : TAbstractModel(), d(new InvKitMapObject(object))
{ }

InvKitMap::~InvKitMap()
{
    // If the reference count becomes 0,
    // the shared data object 'InvKitMapObject' is deleted.
}

int InvKitMap::invKitMapId() const
{
    return d->inv_kit_map_id;
}

int InvKitMap::kitInvNoId() const
{
    return d->kit_inv_no_id;
}

void InvKitMap::setKitInvNoId(int kitInvNoId)
{
    d->kit_inv_no_id = kitInvNoId;
}

int InvKitMap::invNoId() const
{
    return d->inv_no_id;
}

void InvKitMap::setInvNoId(int invNoId)
{
    d->inv_no_id = invNoId;
}

QDateTime InvKitMap::createdAt() const
{
    return d->created_at;
}

QString InvKitMap::createdBy() const
{
    return d->created_by;
}

void InvKitMap::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime InvKitMap::updatedAt() const
{
    return d->updated_at;
}

QString InvKitMap::updatedBy() const
{
    return d->updated_by;
}

void InvKitMap::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

InvInv InvKitMap::invInvByinvNoId() const
{
 return InvInv::get(d->inv_no_id);
}

InvKit InvKitMap::invKitBykitInvNoId() const
{
 return InvKit::get(d->kit_inv_no_id);
}

InvKitMap &InvKitMap::operator=(const InvKitMap &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

InvKitMap InvKitMap::create(int kitInvNoId, int invNoId, const QString &createdBy, const QString &updatedBy)
{
    InvKitMapObject obj;
    obj.kit_inv_no_id = kitInvNoId;
    obj.inv_no_id = invNoId;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return InvKitMap();
    }
    return InvKitMap(obj);
}

InvKitMap InvKitMap::create(const QVariantMap &values)
{
    InvKitMap model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

InvKitMap InvKitMap::get(int invKitMapId)
{
    TSqlORMapper<InvKitMapObject> mapper;
    return InvKitMap(mapper.findByPrimaryKey(invKitMapId));
}

int InvKitMap::count()
{
    TSqlORMapper<InvKitMapObject> mapper;
    return mapper.findCount();
}

QList<InvKitMap> InvKitMap::getAll()
{
    return tfGetModelListByCriteria<InvKitMap, InvKitMapObject>();
}

TModelObject *InvKitMap::modelData()
{
    return d.data();
}

const TModelObject *InvKitMap::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const InvKitMap &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, InvKitMap &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(InvKitMap)
