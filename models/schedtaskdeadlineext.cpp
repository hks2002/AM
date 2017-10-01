#include <TreeFrogModel>
#include "schedtaskdeadlineext.h"
#include "schedtaskdeadlineextobject.h"
#include "datatype.h"
#include "schedstask.h"

SchedTaskDeadlineExt::SchedTaskDeadlineExt()
    : TAbstractModel(), d(new SchedTaskDeadlineExtObject())
{
    d->sched_id = 0;
    d->data_type_id = 0;
    d->deviation_qt = 0;
}

SchedTaskDeadlineExt::SchedTaskDeadlineExt(const SchedTaskDeadlineExt &other)
    : TAbstractModel(), d(new SchedTaskDeadlineExtObject(*other.d))
{ }

SchedTaskDeadlineExt::SchedTaskDeadlineExt(const SchedTaskDeadlineExtObject &object)
    : TAbstractModel(), d(new SchedTaskDeadlineExtObject(object))
{ }

SchedTaskDeadlineExt::~SchedTaskDeadlineExt()
{
    // If the reference count becomes 0,
    // the shared data object 'SchedTaskDeadlineExtObject' is deleted.
}

int SchedTaskDeadlineExt::schedId() const
{
    return d->sched_id;
}

void SchedTaskDeadlineExt::setSchedId(int schedId)
{
    d->sched_id = schedId;
}

int SchedTaskDeadlineExt::dataTypeId() const
{
    return d->data_type_id;
}

void SchedTaskDeadlineExt::setDataTypeId(int dataTypeId)
{
    d->data_type_id = dataTypeId;
}

int SchedTaskDeadlineExt::deviationQt() const
{
    return d->deviation_qt;
}

void SchedTaskDeadlineExt::setDeviationQt(int deviationQt)
{
    d->deviation_qt = deviationQt;
}

QString SchedTaskDeadlineExt::extendNote() const
{
    return d->extend_note;
}

void SchedTaskDeadlineExt::setExtendNote(const QString &extendNote)
{
    d->extend_note = extendNote;
}

QDateTime SchedTaskDeadlineExt::createdAt() const
{
    return d->created_at;
}

QString SchedTaskDeadlineExt::createdBy() const
{
    return d->created_by;
}

void SchedTaskDeadlineExt::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime SchedTaskDeadlineExt::updatedAt() const
{
    return d->updated_at;
}

QString SchedTaskDeadlineExt::updatedBy() const
{
    return d->updated_by;
}

void SchedTaskDeadlineExt::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

DataType SchedTaskDeadlineExt::dataTypeBydataTypeId() const
{
 return DataType::get(d->data_type_id);
}

SchedStask SchedTaskDeadlineExt::schedStaskByschedId() const
{
 return SchedStask::get(d->sched_id);
}

SchedTaskDeadlineExt &SchedTaskDeadlineExt::operator=(const SchedTaskDeadlineExt &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

SchedTaskDeadlineExt SchedTaskDeadlineExt::create(int schedId, int dataTypeId, int deviationQt, const QString &extendNote, const QString &createdBy, const QString &updatedBy)
{
    SchedTaskDeadlineExtObject obj;
    obj.sched_id = schedId;
    obj.data_type_id = dataTypeId;
    obj.deviation_qt = deviationQt;
    obj.extend_note = extendNote;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return SchedTaskDeadlineExt();
    }
    return SchedTaskDeadlineExt(obj);
}

SchedTaskDeadlineExt SchedTaskDeadlineExt::create(const QVariantMap &values)
{
    SchedTaskDeadlineExt model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

SchedTaskDeadlineExt SchedTaskDeadlineExt::get(int schedId, int dataTypeId)
{
    TSqlORMapper<SchedTaskDeadlineExtObject> mapper;
    return SchedTaskDeadlineExt(mapper.findByPrimaryKey(QVariantList()<<QVariant(schedId)<<QVariant(dataTypeId)));
}

int SchedTaskDeadlineExt::count()
{
    TSqlORMapper<SchedTaskDeadlineExtObject> mapper;
    return mapper.findCount();
}

QList<SchedTaskDeadlineExt> SchedTaskDeadlineExt::getAll()
{
    return tfGetModelListByCriteria<SchedTaskDeadlineExt, SchedTaskDeadlineExtObject>();
}

TModelObject *SchedTaskDeadlineExt::modelData()
{
    return d.data();
}

const TModelObject *SchedTaskDeadlineExt::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const SchedTaskDeadlineExt &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, SchedTaskDeadlineExt &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(SchedTaskDeadlineExt)
