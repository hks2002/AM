#include <TreeFrogModel>
#include "locworktypecapability.h"
#include "locworktypecapabilityobject.h"
#include "worktype.h"
#include "eqpassmbl.h"
#include "loc.h"

LocWorkTypeCapability::LocWorkTypeCapability()
    : TAbstractModel(), d(new LocWorkTypeCapabilityObject())
{
    d->loc_id = 0;
    d->assmbl_id = 0;
    d->work_type_id = 0;
}

LocWorkTypeCapability::LocWorkTypeCapability(const LocWorkTypeCapability &other)
    : TAbstractModel(), d(new LocWorkTypeCapabilityObject(*other.d))
{ }

LocWorkTypeCapability::LocWorkTypeCapability(const LocWorkTypeCapabilityObject &object)
    : TAbstractModel(), d(new LocWorkTypeCapabilityObject(object))
{ }

LocWorkTypeCapability::~LocWorkTypeCapability()
{
    // If the reference count becomes 0,
    // the shared data object 'LocWorkTypeCapabilityObject' is deleted.
}

int LocWorkTypeCapability::locId() const
{
    return d->loc_id;
}

void LocWorkTypeCapability::setLocId(int locId)
{
    d->loc_id = locId;
}

int LocWorkTypeCapability::assmblId() const
{
    return d->assmbl_id;
}

void LocWorkTypeCapability::setAssmblId(int assmblId)
{
    d->assmbl_id = assmblId;
}

int LocWorkTypeCapability::workTypeId() const
{
    return d->work_type_id;
}

void LocWorkTypeCapability::setWorkTypeId(int workTypeId)
{
    d->work_type_id = workTypeId;
}

QDateTime LocWorkTypeCapability::createdAt() const
{
    return d->created_at;
}

QString LocWorkTypeCapability::createdBy() const
{
    return d->created_by;
}

void LocWorkTypeCapability::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime LocWorkTypeCapability::updatedAt() const
{
    return d->updated_at;
}

QString LocWorkTypeCapability::updatedBy() const
{
    return d->updated_by;
}

void LocWorkTypeCapability::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

WorkType LocWorkTypeCapability::workTypeByworkTypeId() const
{
 return WorkType::get(d->work_type_id);
}

EqpAssmbl LocWorkTypeCapability::eqpAssmblByassmblId() const
{
 return EqpAssmbl::get(d->assmbl_id);
}

Loc LocWorkTypeCapability::locBylocId() const
{
 return Loc::get(d->loc_id);
}

LocWorkTypeCapability &LocWorkTypeCapability::operator=(const LocWorkTypeCapability &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

LocWorkTypeCapability LocWorkTypeCapability::create(int locId, int assmblId, int workTypeId, const QString &createdBy, const QString &updatedBy)
{
    LocWorkTypeCapabilityObject obj;
    obj.loc_id = locId;
    obj.assmbl_id = assmblId;
    obj.work_type_id = workTypeId;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return LocWorkTypeCapability();
    }
    return LocWorkTypeCapability(obj);
}

LocWorkTypeCapability LocWorkTypeCapability::create(const QVariantMap &values)
{
    LocWorkTypeCapability model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

LocWorkTypeCapability LocWorkTypeCapability::get(int locId, int assmblId, int workTypeId)
{
    TSqlORMapper<LocWorkTypeCapabilityObject> mapper;
    return LocWorkTypeCapability(mapper.findByPrimaryKey(QVariantList()<<QVariant(locId)<<QVariant(assmblId)<<QVariant(workTypeId)));
}

int LocWorkTypeCapability::count()
{
    TSqlORMapper<LocWorkTypeCapabilityObject> mapper;
    return mapper.findCount();
}

QList<LocWorkTypeCapability> LocWorkTypeCapability::getAll()
{
    return tfGetModelListByCriteria<LocWorkTypeCapability, LocWorkTypeCapabilityObject>();
}

TModelObject *LocWorkTypeCapability::modelData()
{
    return d.data();
}

const TModelObject *LocWorkTypeCapability::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const LocWorkTypeCapability &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, LocWorkTypeCapability &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(LocWorkTypeCapability)
