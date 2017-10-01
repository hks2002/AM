#include <TreeFrogModel>
#include "refthresholdmode.h"
#include "refthresholdmodeobject.h"

RefThresholdMode::RefThresholdMode()
    : TAbstractModel(), d(new RefThresholdModeObject())
{ }

RefThresholdMode::RefThresholdMode(const RefThresholdMode &other)
    : TAbstractModel(), d(new RefThresholdModeObject(*other.d))
{ }

RefThresholdMode::RefThresholdMode(const RefThresholdModeObject &object)
    : TAbstractModel(), d(new RefThresholdModeObject(object))
{ }

RefThresholdMode::~RefThresholdMode()
{
    // If the reference count becomes 0,
    // the shared data object 'RefThresholdModeObject' is deleted.
}

QString RefThresholdMode::thresholdModeCd() const
{
    return d->threshold_mode_cd;
}

void RefThresholdMode::setThresholdModeCd(const QString &thresholdModeCd)
{
    d->threshold_mode_cd = thresholdModeCd;
}

QString RefThresholdMode::thresholdModeNameEn() const
{
    return d->threshold_mode_name_en;
}

void RefThresholdMode::setThresholdModeNameEn(const QString &thresholdModeNameEn)
{
    d->threshold_mode_name_en = thresholdModeNameEn;
}

QString RefThresholdMode::thresholdModeNameZh() const
{
    return d->threshold_mode_name_zh;
}

void RefThresholdMode::setThresholdModeNameZh(const QString &thresholdModeNameZh)
{
    d->threshold_mode_name_zh = thresholdModeNameZh;
}

QString RefThresholdMode::thresholdModeDesc() const
{
    return d->threshold_mode_desc;
}

void RefThresholdMode::setThresholdModeDesc(const QString &thresholdModeDesc)
{
    d->threshold_mode_desc = thresholdModeDesc;
}

QDateTime RefThresholdMode::createdAt() const
{
    return d->created_at;
}

QString RefThresholdMode::createdBy() const
{
    return d->created_by;
}

void RefThresholdMode::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime RefThresholdMode::updatedAt() const
{
    return d->updated_at;
}

QString RefThresholdMode::updatedBy() const
{
    return d->updated_by;
}

void RefThresholdMode::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

RefThresholdMode &RefThresholdMode::operator=(const RefThresholdMode &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

RefThresholdMode RefThresholdMode::create(const QString &thresholdModeCd, const QString &thresholdModeNameEn, const QString &thresholdModeNameZh, const QString &thresholdModeDesc, const QString &createdBy, const QString &updatedBy)
{
    RefThresholdModeObject obj;
    obj.threshold_mode_cd = thresholdModeCd;
    obj.threshold_mode_name_en = thresholdModeNameEn;
    obj.threshold_mode_name_zh = thresholdModeNameZh;
    obj.threshold_mode_desc = thresholdModeDesc;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return RefThresholdMode();
    }
    return RefThresholdMode(obj);
}

RefThresholdMode RefThresholdMode::create(const QVariantMap &values)
{
    RefThresholdMode model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

RefThresholdMode RefThresholdMode::get(const QString &thresholdModeCd)
{
    TSqlORMapper<RefThresholdModeObject> mapper;
    return RefThresholdMode(mapper.findByPrimaryKey(thresholdModeCd));
}

int RefThresholdMode::count()
{
    TSqlORMapper<RefThresholdModeObject> mapper;
    return mapper.findCount();
}

QList<RefThresholdMode> RefThresholdMode::getAll()
{
    return tfGetModelListByCriteria<RefThresholdMode, RefThresholdModeObject>();
}

TModelObject *RefThresholdMode::modelData()
{
    return d.data();
}

const TModelObject *RefThresholdMode::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const RefThresholdMode &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, RefThresholdMode &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(RefThresholdMode)
