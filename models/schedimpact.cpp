#include <TreeFrogModel>
#include "schedimpact.h"
#include "schedimpactobject.h"
#include "mesurunit.h"
#include "refmesurtype.h"
#include "schedstask.h"

SchedImpact::SchedImpact()
    : TAbstractModel(), d(new SchedImpactObject())
{
    d->sched_id = 0;
    d->mesur_unit_id = 0;
    d->mesur_qt = 0;
}

SchedImpact::SchedImpact(const SchedImpact &other)
    : TAbstractModel(), d(new SchedImpactObject(*other.d))
{ }

SchedImpact::SchedImpact(const SchedImpactObject &object)
    : TAbstractModel(), d(new SchedImpactObject(object))
{ }

SchedImpact::~SchedImpact()
{
    // If the reference count becomes 0,
    // the shared data object 'SchedImpactObject' is deleted.
}

int SchedImpact::schedId() const
{
    return d->sched_id;
}

void SchedImpact::setSchedId(int schedId)
{
    d->sched_id = schedId;
}

QString SchedImpact::mesurTypeCd() const
{
    return d->mesur_type_cd;
}

void SchedImpact::setMesurTypeCd(const QString &mesurTypeCd)
{
    d->mesur_type_cd = mesurTypeCd;
}

int SchedImpact::mesurUnitId() const
{
    return d->mesur_unit_id;
}

void SchedImpact::setMesurUnitId(int mesurUnitId)
{
    d->mesur_unit_id = mesurUnitId;
}

double SchedImpact::mesurQt() const
{
    return d->mesur_qt;
}

void SchedImpact::setMesurQt(double mesurQt)
{
    d->mesur_qt = mesurQt;
}

QString SchedImpact::impactDesc() const
{
    return d->impact_desc;
}

void SchedImpact::setImpactDesc(const QString &impactDesc)
{
    d->impact_desc = impactDesc;
}

QDateTime SchedImpact::createdAt() const
{
    return d->created_at;
}

QString SchedImpact::createdBy() const
{
    return d->created_by;
}

void SchedImpact::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime SchedImpact::updatedAt() const
{
    return d->updated_at;
}

QString SchedImpact::updatedBy() const
{
    return d->updated_by;
}

void SchedImpact::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

MesurUnit SchedImpact::mesurUnitBymesurUnitId() const
{
 return MesurUnit::get(d->mesur_unit_id);
}

RefMesurType SchedImpact::refMesurTypeBymesurTypeCd() const
{
 return RefMesurType::get(d->mesur_type_cd);
}

SchedStask SchedImpact::schedStaskByschedId() const
{
 return SchedStask::get(d->sched_id);
}

SchedImpact &SchedImpact::operator=(const SchedImpact &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

SchedImpact SchedImpact::create(int schedId, const QString &mesurTypeCd, int mesurUnitId, double mesurQt, const QString &impactDesc, const QString &createdBy, const QString &updatedBy)
{
    SchedImpactObject obj;
    obj.sched_id = schedId;
    obj.mesur_type_cd = mesurTypeCd;
    obj.mesur_unit_id = mesurUnitId;
    obj.mesur_qt = mesurQt;
    obj.impact_desc = impactDesc;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return SchedImpact();
    }
    return SchedImpact(obj);
}

SchedImpact SchedImpact::create(const QVariantMap &values)
{
    SchedImpact model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

SchedImpact SchedImpact::get(int schedId, const QString &mesurTypeCd, int mesurUnitId)
{
    TSqlORMapper<SchedImpactObject> mapper;
    return SchedImpact(mapper.findByPrimaryKey(QVariantList()<<QVariant(schedId)<<QVariant(mesurTypeCd)<<QVariant(mesurUnitId)));
}

int SchedImpact::count()
{
    TSqlORMapper<SchedImpactObject> mapper;
    return mapper.findCount();
}

QList<SchedImpact> SchedImpact::getAll()
{
    return tfGetModelListByCriteria<SchedImpact, SchedImpactObject>();
}

TModelObject *SchedImpact::modelData()
{
    return d.data();
}

const TModelObject *SchedImpact::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const SchedImpact &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, SchedImpact &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(SchedImpact)
