#include <TreeFrogModel>
#include "polinereturnmap.h"
#include "polinereturnmapobject.h"
#include "invinv.h"
#include "poline.h"

PoLineReturnMap::PoLineReturnMap()
    : TAbstractModel(), d(new PoLineReturnMapObject())
{
    d->po_line_id = 0;
    d->inv_no_id = 0;
}

PoLineReturnMap::PoLineReturnMap(const PoLineReturnMap &other)
    : TAbstractModel(), d(new PoLineReturnMapObject(*other.d))
{ }

PoLineReturnMap::PoLineReturnMap(const PoLineReturnMapObject &object)
    : TAbstractModel(), d(new PoLineReturnMapObject(object))
{ }

PoLineReturnMap::~PoLineReturnMap()
{
    // If the reference count becomes 0,
    // the shared data object 'PoLineReturnMapObject' is deleted.
}

int PoLineReturnMap::poLineId() const
{
    return d->po_line_id;
}

void PoLineReturnMap::setPoLineId(int poLineId)
{
    d->po_line_id = poLineId;
}

int PoLineReturnMap::invNoId() const
{
    return d->inv_no_id;
}

void PoLineReturnMap::setInvNoId(int invNoId)
{
    d->inv_no_id = invNoId;
}

QDateTime PoLineReturnMap::createdAt() const
{
    return d->created_at;
}

QString PoLineReturnMap::createdBy() const
{
    return d->created_by;
}

void PoLineReturnMap::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime PoLineReturnMap::updatedAt() const
{
    return d->updated_at;
}

QString PoLineReturnMap::updatedBy() const
{
    return d->updated_by;
}

void PoLineReturnMap::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

InvInv PoLineReturnMap::invInvByinvNoId() const
{
 return InvInv::get(d->inv_no_id);
}

PoLine PoLineReturnMap::poLineBypoLineId() const
{
 return PoLine::get(d->po_line_id);
}

PoLineReturnMap &PoLineReturnMap::operator=(const PoLineReturnMap &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

PoLineReturnMap PoLineReturnMap::create(int poLineId, int invNoId, const QString &createdBy, const QString &updatedBy)
{
    PoLineReturnMapObject obj;
    obj.po_line_id = poLineId;
    obj.inv_no_id = invNoId;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return PoLineReturnMap();
    }
    return PoLineReturnMap(obj);
}

PoLineReturnMap PoLineReturnMap::create(const QVariantMap &values)
{
    PoLineReturnMap model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

PoLineReturnMap PoLineReturnMap::get(int poLineId)
{
    TSqlORMapper<PoLineReturnMapObject> mapper;
    return PoLineReturnMap(mapper.findByPrimaryKey(poLineId));
}

int PoLineReturnMap::count()
{
    TSqlORMapper<PoLineReturnMapObject> mapper;
    return mapper.findCount();
}

QList<PoLineReturnMap> PoLineReturnMap::getAll()
{
    return tfGetModelListByCriteria<PoLineReturnMap, PoLineReturnMapObject>();
}

TModelObject *PoLineReturnMap::modelData()
{
    return d.data();
}

const TModelObject *PoLineReturnMap::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const PoLineReturnMap &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, PoLineReturnMap &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(PoLineReturnMap)
