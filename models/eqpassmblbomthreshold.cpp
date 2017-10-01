#include <TreeFrogModel>
#include "eqpassmblbomthreshold.h"
#include "eqpassmblbomthresholdobject.h"
#include "refthresholdmode.h"
#include "eqpassmblbom.h"

EqpAssmblBomThreshold::EqpAssmblBomThreshold()
    : TAbstractModel(), d(new EqpAssmblBomThresholdObject())
{
    d->assmbl_bom_id = 0;
    d->threshold_days_qt = 0;
    d->threshold_qt = 0;
}

EqpAssmblBomThreshold::EqpAssmblBomThreshold(const EqpAssmblBomThreshold &other)
    : TAbstractModel(), d(new EqpAssmblBomThresholdObject(*other.d))
{ }

EqpAssmblBomThreshold::EqpAssmblBomThreshold(const EqpAssmblBomThresholdObject &object)
    : TAbstractModel(), d(new EqpAssmblBomThresholdObject(object))
{ }

EqpAssmblBomThreshold::~EqpAssmblBomThreshold()
{
    // If the reference count becomes 0,
    // the shared data object 'EqpAssmblBomThresholdObject' is deleted.
}

int EqpAssmblBomThreshold::assmblBomId() const
{
    return d->assmbl_bom_id;
}

void EqpAssmblBomThreshold::setAssmblBomId(int assmblBomId)
{
    d->assmbl_bom_id = assmblBomId;
}

QString EqpAssmblBomThreshold::thresholdModeCd() const
{
    return d->threshold_mode_cd;
}

void EqpAssmblBomThreshold::setThresholdModeCd(const QString &thresholdModeCd)
{
    d->threshold_mode_cd = thresholdModeCd;
}

int EqpAssmblBomThreshold::thresholdDaysQt() const
{
    return d->threshold_days_qt;
}

void EqpAssmblBomThreshold::setThresholdDaysQt(int thresholdDaysQt)
{
    d->threshold_days_qt = thresholdDaysQt;
}

int EqpAssmblBomThreshold::thresholdQt() const
{
    return d->threshold_qt;
}

void EqpAssmblBomThreshold::setThresholdQt(int thresholdQt)
{
    d->threshold_qt = thresholdQt;
}

QString EqpAssmblBomThreshold::thresholdDesc() const
{
    return d->threshold_desc;
}

void EqpAssmblBomThreshold::setThresholdDesc(const QString &thresholdDesc)
{
    d->threshold_desc = thresholdDesc;
}

QDateTime EqpAssmblBomThreshold::effectiveDt() const
{
    return d->effective_dt;
}

void EqpAssmblBomThreshold::setEffectiveDt(const QDateTime &effectiveDt)
{
    d->effective_dt = effectiveDt;
}

QDateTime EqpAssmblBomThreshold::createdAt() const
{
    return d->created_at;
}

QString EqpAssmblBomThreshold::createdBy() const
{
    return d->created_by;
}

void EqpAssmblBomThreshold::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime EqpAssmblBomThreshold::updatedAt() const
{
    return d->updated_at;
}

QString EqpAssmblBomThreshold::updatedBy() const
{
    return d->updated_by;
}

void EqpAssmblBomThreshold::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

RefThresholdMode EqpAssmblBomThreshold::refThresholdModeBythresholdModeCd() const
{
 return RefThresholdMode::get(d->threshold_mode_cd);
}

EqpAssmblBom EqpAssmblBomThreshold::eqpAssmblBomByassmblBomId() const
{
 return EqpAssmblBom::get(d->assmbl_bom_id);
}

EqpAssmblBomThreshold &EqpAssmblBomThreshold::operator=(const EqpAssmblBomThreshold &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

EqpAssmblBomThreshold EqpAssmblBomThreshold::create(int assmblBomId, const QString &thresholdModeCd, int thresholdDaysQt, int thresholdQt, const QString &thresholdDesc, const QDateTime &effectiveDt, const QString &createdBy, const QString &updatedBy)
{
    EqpAssmblBomThresholdObject obj;
    obj.assmbl_bom_id = assmblBomId;
    obj.threshold_mode_cd = thresholdModeCd;
    obj.threshold_days_qt = thresholdDaysQt;
    obj.threshold_qt = thresholdQt;
    obj.threshold_desc = thresholdDesc;
    obj.effective_dt = effectiveDt;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return EqpAssmblBomThreshold();
    }
    return EqpAssmblBomThreshold(obj);
}

EqpAssmblBomThreshold EqpAssmblBomThreshold::create(const QVariantMap &values)
{
    EqpAssmblBomThreshold model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

EqpAssmblBomThreshold EqpAssmblBomThreshold::get(int assmblBomId, const QString &thresholdModeCd)
{
    TSqlORMapper<EqpAssmblBomThresholdObject> mapper;
    return EqpAssmblBomThreshold(mapper.findByPrimaryKey(QVariantList()<<QVariant(assmblBomId)<<QVariant(thresholdModeCd)));
}

int EqpAssmblBomThreshold::count()
{
    TSqlORMapper<EqpAssmblBomThresholdObject> mapper;
    return mapper.findCount();
}

QList<EqpAssmblBomThreshold> EqpAssmblBomThreshold::getAll()
{
    return tfGetModelListByCriteria<EqpAssmblBomThreshold, EqpAssmblBomThresholdObject>();
}

TModelObject *EqpAssmblBomThreshold::modelData()
{
    return d.data();
}

const TModelObject *EqpAssmblBomThreshold::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const EqpAssmblBomThreshold &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, EqpAssmblBomThreshold &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(EqpAssmblBomThreshold)
