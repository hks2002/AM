#include <TreeFrogModel>
#include "locsubloc.h"
#include "locsublocobject.h"
#include "loc.h"

LocSubloc::LocSubloc()
    : TAbstractModel(), d(new LocSublocObject())
{
    d->loc_id = 0;
    d->sub_loc_id = 0;
}

LocSubloc::LocSubloc(const LocSubloc &other)
    : TAbstractModel(), d(new LocSublocObject(*other.d))
{ }

LocSubloc::LocSubloc(const LocSublocObject &object)
    : TAbstractModel(), d(new LocSublocObject(object))
{ }

LocSubloc::~LocSubloc()
{
    // If the reference count becomes 0,
    // the shared data object 'LocSublocObject' is deleted.
}

int LocSubloc::locId() const
{
    return d->loc_id;
}

void LocSubloc::setLocId(int locId)
{
    d->loc_id = locId;
}

int LocSubloc::subLocId() const
{
    return d->sub_loc_id;
}

void LocSubloc::setSubLocId(int subLocId)
{
    d->sub_loc_id = subLocId;
}

QDateTime LocSubloc::createdAt() const
{
    return d->created_at;
}

QString LocSubloc::createdBy() const
{
    return d->created_by;
}

void LocSubloc::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime LocSubloc::updatedAt() const
{
    return d->updated_at;
}

QString LocSubloc::updatedBy() const
{
    return d->updated_by;
}

void LocSubloc::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

Loc LocSubloc::locBysubLocId() const
{
 return Loc::get(d->sub_loc_id);
}

LocSubloc &LocSubloc::operator=(const LocSubloc &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

LocSubloc LocSubloc::create(int locId, int subLocId, const QString &createdBy, const QString &updatedBy)
{
    LocSublocObject obj;
    obj.loc_id = locId;
    obj.sub_loc_id = subLocId;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return LocSubloc();
    }
    return LocSubloc(obj);
}

LocSubloc LocSubloc::create(const QVariantMap &values)
{
    LocSubloc model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

LocSubloc LocSubloc::get(int locId, int subLocId)
{
    TSqlORMapper<LocSublocObject> mapper;
    return LocSubloc(mapper.findByPrimaryKey(QVariantList()<<QVariant(locId)<<QVariant(subLocId)));
}

int LocSubloc::count()
{
    TSqlORMapper<LocSublocObject> mapper;
    return mapper.findCount();
}

QList<LocSubloc> LocSubloc::getAll()
{
    return tfGetModelListByCriteria<LocSubloc, LocSublocObject>();
}

TModelObject *LocSubloc::modelData()
{
    return d.data();
}

const TModelObject *LocSubloc::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const LocSubloc &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, LocSubloc &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(LocSubloc)
