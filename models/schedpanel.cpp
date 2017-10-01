#include <TreeFrogModel>
#include "schedpanel.h"
#include "schedpanelobject.h"
#include "eqppanel.h"
#include "eqpassmbl.h"
#include "schedstask.h"

SchedPanel::SchedPanel()
    : TAbstractModel(), d(new SchedPanelObject())
{
    d->sched_id = 0;
    d->assmbl_id = 0;
    d->panel_id = 0;
}

SchedPanel::SchedPanel(const SchedPanel &other)
    : TAbstractModel(), d(new SchedPanelObject(*other.d))
{ }

SchedPanel::SchedPanel(const SchedPanelObject &object)
    : TAbstractModel(), d(new SchedPanelObject(object))
{ }

SchedPanel::~SchedPanel()
{
    // If the reference count becomes 0,
    // the shared data object 'SchedPanelObject' is deleted.
}

int SchedPanel::schedId() const
{
    return d->sched_id;
}

void SchedPanel::setSchedId(int schedId)
{
    d->sched_id = schedId;
}

int SchedPanel::assmblId() const
{
    return d->assmbl_id;
}

void SchedPanel::setAssmblId(int assmblId)
{
    d->assmbl_id = assmblId;
}

int SchedPanel::panelId() const
{
    return d->panel_id;
}

void SchedPanel::setPanelId(int panelId)
{
    d->panel_id = panelId;
}

QDateTime SchedPanel::createdAt() const
{
    return d->created_at;
}

QString SchedPanel::createdBy() const
{
    return d->created_by;
}

void SchedPanel::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime SchedPanel::updatedAt() const
{
    return d->updated_at;
}

QString SchedPanel::updatedBy() const
{
    return d->updated_by;
}

void SchedPanel::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

EqpPanel SchedPanel::eqpPanelBypanelId() const
{
 return EqpPanel::get(d->panel_id);
}

EqpAssmbl SchedPanel::eqpAssmblByassmblId() const
{
 return EqpAssmbl::get(d->assmbl_id);
}

SchedStask SchedPanel::schedStaskByschedId() const
{
 return SchedStask::get(d->sched_id);
}

SchedPanel &SchedPanel::operator=(const SchedPanel &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

SchedPanel SchedPanel::create(int schedId, int assmblId, int panelId, const QString &createdBy, const QString &updatedBy)
{
    SchedPanelObject obj;
    obj.sched_id = schedId;
    obj.assmbl_id = assmblId;
    obj.panel_id = panelId;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return SchedPanel();
    }
    return SchedPanel(obj);
}

SchedPanel SchedPanel::create(const QVariantMap &values)
{
    SchedPanel model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

SchedPanel SchedPanel::get(int schedId, int assmblId, int panelId)
{
    TSqlORMapper<SchedPanelObject> mapper;
    return SchedPanel(mapper.findByPrimaryKey(QVariantList()<<QVariant(schedId)<<QVariant(assmblId)<<QVariant(panelId)));
}

int SchedPanel::count()
{
    TSqlORMapper<SchedPanelObject> mapper;
    return mapper.findCount();
}

QList<SchedPanel> SchedPanel::getAll()
{
    return tfGetModelListByCriteria<SchedPanel, SchedPanelObject>();
}

TModelObject *SchedPanel::modelData()
{
    return d.data();
}

const TModelObject *SchedPanel::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const SchedPanel &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, SchedPanel &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(SchedPanel)
