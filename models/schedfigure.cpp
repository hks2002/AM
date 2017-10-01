#include <TreeFrogModel>
#include "schedfigure.h"
#include "schedfigureobject.h"
#include "taskfigure.h"
#include "schedstask.h"

SchedFigure::SchedFigure()
    : TAbstractModel(), d(new SchedFigureObject())
{
    d->figure_id = 0;
    d->sched_id = 0;
    d->task_id = 0;
    d->figure_ord = 0;
}

SchedFigure::SchedFigure(const SchedFigure &other)
    : TAbstractModel(), d(new SchedFigureObject(*other.d))
{ }

SchedFigure::SchedFigure(const SchedFigureObject &object)
    : TAbstractModel(), d(new SchedFigureObject(object))
{ }

SchedFigure::~SchedFigure()
{
    // If the reference count becomes 0,
    // the shared data object 'SchedFigureObject' is deleted.
}

int SchedFigure::figureId() const
{
    return d->figure_id;
}

int SchedFigure::schedId() const
{
    return d->sched_id;
}

void SchedFigure::setSchedId(int schedId)
{
    d->sched_id = schedId;
}

int SchedFigure::taskId() const
{
    return d->task_id;
}

void SchedFigure::setTaskId(int taskId)
{
    d->task_id = taskId;
}

int SchedFigure::figureOrd() const
{
    return d->figure_ord;
}

void SchedFigure::setFigureOrd(int figureOrd)
{
    d->figure_ord = figureOrd;
}

QString SchedFigure::figure() const
{
    return d->figure;
}

void SchedFigure::setFigure(const QString &figure)
{
    d->figure = figure;
}

QDateTime SchedFigure::createdAt() const
{
    return d->created_at;
}

QString SchedFigure::createdBy() const
{
    return d->created_by;
}

void SchedFigure::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime SchedFigure::updatedAt() const
{
    return d->updated_at;
}

QString SchedFigure::updatedBy() const
{
    return d->updated_by;
}

void SchedFigure::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

TaskFigure SchedFigure::taskFigureBytaskIdfigureOrd() const
{
 return TaskFigure::get(d->task_id, d->figure_ord);
}

SchedStask SchedFigure::schedStaskByschedId() const
{
 return SchedStask::get(d->sched_id);
}

SchedFigure &SchedFigure::operator=(const SchedFigure &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

SchedFigure SchedFigure::create(int schedId, int taskId, int figureOrd, const QString &figure, const QString &createdBy, const QString &updatedBy)
{
    SchedFigureObject obj;
    obj.sched_id = schedId;
    obj.task_id = taskId;
    obj.figure_ord = figureOrd;
    obj.figure = figure;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return SchedFigure();
    }
    return SchedFigure(obj);
}

SchedFigure SchedFigure::create(const QVariantMap &values)
{
    SchedFigure model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

SchedFigure SchedFigure::get(int figureId)
{
    TSqlORMapper<SchedFigureObject> mapper;
    return SchedFigure(mapper.findByPrimaryKey(figureId));
}

int SchedFigure::count()
{
    TSqlORMapper<SchedFigureObject> mapper;
    return mapper.findCount();
}

QList<SchedFigure> SchedFigure::getAll()
{
    return tfGetModelListByCriteria<SchedFigure, SchedFigureObject>();
}

TModelObject *SchedFigure::modelData()
{
    return d.data();
}

const TModelObject *SchedFigure::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const SchedFigure &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, SchedFigure &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(SchedFigure)
