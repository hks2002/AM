#include <TreeFrogModel>
#include "evtdept.h"
#include "evtdeptobject.h"
#include "dept.h"
#include "evtevent.h"

EvtDept::EvtDept()
    : TAbstractModel(), d(new EvtDeptObject())
{
    d->event_id = 0;
    d->dept_id = 0;
}

EvtDept::EvtDept(const EvtDept &other)
    : TAbstractModel(), d(new EvtDeptObject(*other.d))
{ }

EvtDept::EvtDept(const EvtDeptObject &object)
    : TAbstractModel(), d(new EvtDeptObject(object))
{ }

EvtDept::~EvtDept()
{
    // If the reference count becomes 0,
    // the shared data object 'EvtDeptObject' is deleted.
}

int EvtDept::eventId() const
{
    return d->event_id;
}

void EvtDept::setEventId(int eventId)
{
    d->event_id = eventId;
}

int EvtDept::deptId() const
{
    return d->dept_id;
}

void EvtDept::setDeptId(int deptId)
{
    d->dept_id = deptId;
}

QDateTime EvtDept::createdAt() const
{
    return d->created_at;
}

QString EvtDept::createdBy() const
{
    return d->created_by;
}

void EvtDept::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime EvtDept::updatedAt() const
{
    return d->updated_at;
}

QString EvtDept::updatedBy() const
{
    return d->updated_by;
}

void EvtDept::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

Dept EvtDept::deptBydeptId() const
{
 return Dept::get(d->dept_id);
}

EvtEvent EvtDept::evtEventByeventId() const
{
 return EvtEvent::get(d->event_id);
}

EvtDept &EvtDept::operator=(const EvtDept &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

EvtDept EvtDept::create(int eventId, int deptId, const QString &createdBy, const QString &updatedBy)
{
    EvtDeptObject obj;
    obj.event_id = eventId;
    obj.dept_id = deptId;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return EvtDept();
    }
    return EvtDept(obj);
}

EvtDept EvtDept::create(const QVariantMap &values)
{
    EvtDept model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

EvtDept EvtDept::get(int eventId, int deptId)
{
    TSqlORMapper<EvtDeptObject> mapper;
    return EvtDept(mapper.findByPrimaryKey(QVariantList()<<QVariant(eventId)<<QVariant(deptId)));
}

int EvtDept::count()
{
    TSqlORMapper<EvtDeptObject> mapper;
    return mapper.findCount();
}

QList<EvtDept> EvtDept::getAll()
{
    return tfGetModelListByCriteria<EvtDept, EvtDeptObject>();
}

TModelObject *EvtDept::modelData()
{
    return d.data();
}

const TModelObject *EvtDept::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const EvtDept &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, EvtDept &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(EvtDept)
