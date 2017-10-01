#include <TreeFrogModel>
#include "loclabourcapacity.h"
#include "loclabourcapacityobject.h"
#include "labourskill.h"
#include "loc.h"

LocLabourCapacity::LocLabourCapacity()
    : TAbstractModel(), d(new LocLabourCapacityObject())
{
    d->loc_id = 0;
    d->labour_skill_id = 0;
    d->hours_per_day_qt = 0;
}

LocLabourCapacity::LocLabourCapacity(const LocLabourCapacity &other)
    : TAbstractModel(), d(new LocLabourCapacityObject(*other.d))
{ }

LocLabourCapacity::LocLabourCapacity(const LocLabourCapacityObject &object)
    : TAbstractModel(), d(new LocLabourCapacityObject(object))
{ }

LocLabourCapacity::~LocLabourCapacity()
{
    // If the reference count becomes 0,
    // the shared data object 'LocLabourCapacityObject' is deleted.
}

int LocLabourCapacity::locId() const
{
    return d->loc_id;
}

void LocLabourCapacity::setLocId(int locId)
{
    d->loc_id = locId;
}

int LocLabourCapacity::labourSkillId() const
{
    return d->labour_skill_id;
}

void LocLabourCapacity::setLabourSkillId(int labourSkillId)
{
    d->labour_skill_id = labourSkillId;
}

double LocLabourCapacity::hoursPerDayQt() const
{
    return d->hours_per_day_qt;
}

void LocLabourCapacity::setHoursPerDayQt(double hoursPerDayQt)
{
    d->hours_per_day_qt = hoursPerDayQt;
}

QDateTime LocLabourCapacity::createdAt() const
{
    return d->created_at;
}

QString LocLabourCapacity::createdBy() const
{
    return d->created_by;
}

void LocLabourCapacity::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime LocLabourCapacity::updatedAt() const
{
    return d->updated_at;
}

QString LocLabourCapacity::updatedBy() const
{
    return d->updated_by;
}

void LocLabourCapacity::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

LabourSkill LocLabourCapacity::labourSkillBylabourSkillId() const
{
 return LabourSkill::get(d->labour_skill_id);
}

Loc LocLabourCapacity::locBylocId() const
{
 return Loc::get(d->loc_id);
}

LocLabourCapacity &LocLabourCapacity::operator=(const LocLabourCapacity &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

LocLabourCapacity LocLabourCapacity::create(int locId, int labourSkillId, double hoursPerDayQt, const QString &createdBy, const QString &updatedBy)
{
    LocLabourCapacityObject obj;
    obj.loc_id = locId;
    obj.labour_skill_id = labourSkillId;
    obj.hours_per_day_qt = hoursPerDayQt;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return LocLabourCapacity();
    }
    return LocLabourCapacity(obj);
}

LocLabourCapacity LocLabourCapacity::create(const QVariantMap &values)
{
    LocLabourCapacity model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

LocLabourCapacity LocLabourCapacity::get(int locId, int labourSkillId)
{
    TSqlORMapper<LocLabourCapacityObject> mapper;
    return LocLabourCapacity(mapper.findByPrimaryKey(QVariantList()<<QVariant(locId)<<QVariant(labourSkillId)));
}

int LocLabourCapacity::count()
{
    TSqlORMapper<LocLabourCapacityObject> mapper;
    return mapper.findCount();
}

QList<LocLabourCapacity> LocLabourCapacity::getAll()
{
    return tfGetModelListByCriteria<LocLabourCapacity, LocLabourCapacityObject>();
}

TModelObject *LocLabourCapacity::modelData()
{
    return d.data();
}

const TModelObject *LocLabourCapacity::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const LocLabourCapacity &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, LocLabourCapacity &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(LocLabourCapacity)
