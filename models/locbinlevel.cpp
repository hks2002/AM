#include <TreeFrogModel>
#include "locbinlevel.h"
#include "locbinlevelobject.h"
#include "ownerapp.h"
#include "eqppartno.h"
#include "loc.h"

LocBinLevel::LocBinLevel()
    : TAbstractModel(), d(new LocBinLevelObject())
{
    d->loc_id = 0;
    d->part_no_id = 0;
    d->owner_id = 0;
    d->min_qt = 0;
    d->max_qt = 0;
}

LocBinLevel::LocBinLevel(const LocBinLevel &other)
    : TAbstractModel(), d(new LocBinLevelObject(*other.d))
{ }

LocBinLevel::LocBinLevel(const LocBinLevelObject &object)
    : TAbstractModel(), d(new LocBinLevelObject(object))
{ }

LocBinLevel::~LocBinLevel()
{
    // If the reference count becomes 0,
    // the shared data object 'LocBinLevelObject' is deleted.
}

int LocBinLevel::locId() const
{
    return d->loc_id;
}

void LocBinLevel::setLocId(int locId)
{
    d->loc_id = locId;
}

int LocBinLevel::partNoId() const
{
    return d->part_no_id;
}

void LocBinLevel::setPartNoId(int partNoId)
{
    d->part_no_id = partNoId;
}

int LocBinLevel::ownerId() const
{
    return d->owner_id;
}

void LocBinLevel::setOwnerId(int ownerId)
{
    d->owner_id = ownerId;
}

int LocBinLevel::minQt() const
{
    return d->min_qt;
}

void LocBinLevel::setMinQt(int minQt)
{
    d->min_qt = minQt;
}

int LocBinLevel::maxQt() const
{
    return d->max_qt;
}

void LocBinLevel::setMaxQt(int maxQt)
{
    d->max_qt = maxQt;
}

QDateTime LocBinLevel::createdAt() const
{
    return d->created_at;
}

QString LocBinLevel::createdBy() const
{
    return d->created_by;
}

void LocBinLevel::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime LocBinLevel::updatedAt() const
{
    return d->updated_at;
}

QString LocBinLevel::updatedBy() const
{
    return d->updated_by;
}

void LocBinLevel::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

OwnerApp LocBinLevel::ownerAppByownerId() const
{
 return OwnerApp::get(d->owner_id);
}

EqpPartNo LocBinLevel::eqpPartNoBypartNoId() const
{
 return EqpPartNo::get(d->part_no_id);
}

Loc LocBinLevel::locBylocId() const
{
 return Loc::get(d->loc_id);
}

LocBinLevel &LocBinLevel::operator=(const LocBinLevel &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

LocBinLevel LocBinLevel::create(int locId, int partNoId, int ownerId, int minQt, int maxQt, const QString &createdBy, const QString &updatedBy)
{
    LocBinLevelObject obj;
    obj.loc_id = locId;
    obj.part_no_id = partNoId;
    obj.owner_id = ownerId;
    obj.min_qt = minQt;
    obj.max_qt = maxQt;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return LocBinLevel();
    }
    return LocBinLevel(obj);
}

LocBinLevel LocBinLevel::create(const QVariantMap &values)
{
    LocBinLevel model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

LocBinLevel LocBinLevel::get(int locId, int partNoId, int ownerId)
{
    TSqlORMapper<LocBinLevelObject> mapper;
    return LocBinLevel(mapper.findByPrimaryKey(QVariantList()<<QVariant(locId)<<QVariant(partNoId)<<QVariant(ownerId)));
}

int LocBinLevel::count()
{
    TSqlORMapper<LocBinLevelObject> mapper;
    return mapper.findCount();
}

QList<LocBinLevel> LocBinLevel::getAll()
{
    return tfGetModelListByCriteria<LocBinLevel, LocBinLevelObject>();
}

TModelObject *LocBinLevel::modelData()
{
    return d.data();
}

const TModelObject *LocBinLevel::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const LocBinLevel &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, LocBinLevel &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(LocBinLevel)
