#include <TreeFrogModel>
#include "fcrange.h"
#include "fcrangeobject.h"
#include "fcmodel.h"

FcRange::FcRange()
    : TAbstractModel(), d(new FcRangeObject())
{
    d->fc_range_id = 0;
    d->fc_model_id = 0;
    d->start_month = 0;
    d->start_day = 0;
    d->end_month = 0;
    d->end_day = 0;
}

FcRange::FcRange(const FcRange &other)
    : TAbstractModel(), d(new FcRangeObject(*other.d))
{ }

FcRange::FcRange(const FcRangeObject &object)
    : TAbstractModel(), d(new FcRangeObject(object))
{ }

FcRange::~FcRange()
{
    // If the reference count becomes 0,
    // the shared data object 'FcRangeObject' is deleted.
}

int FcRange::fcRangeId() const
{
    return d->fc_range_id;
}

int FcRange::fcModelId() const
{
    return d->fc_model_id;
}

void FcRange::setFcModelId(int fcModelId)
{
    d->fc_model_id = fcModelId;
}

int FcRange::startMonth() const
{
    return d->start_month;
}

void FcRange::setStartMonth(int startMonth)
{
    d->start_month = startMonth;
}

int FcRange::startDay() const
{
    return d->start_day;
}

void FcRange::setStartDay(int startDay)
{
    d->start_day = startDay;
}

int FcRange::endMonth() const
{
    return d->end_month;
}

void FcRange::setEndMonth(int endMonth)
{
    d->end_month = endMonth;
}

int FcRange::endDay() const
{
    return d->end_day;
}

void FcRange::setEndDay(int endDay)
{
    d->end_day = endDay;
}

QDateTime FcRange::createdAt() const
{
    return d->created_at;
}

QString FcRange::createdBy() const
{
    return d->created_by;
}

void FcRange::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime FcRange::updatedAt() const
{
    return d->updated_at;
}

QString FcRange::updatedBy() const
{
    return d->updated_by;
}

void FcRange::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

FcModel FcRange::fcModelByfcModelId() const
{
 return FcModel::get(d->fc_model_id);
}

FcRange &FcRange::operator=(const FcRange &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

FcRange FcRange::create(int fcModelId, int startMonth, int startDay, int endMonth, int endDay, const QString &createdBy, const QString &updatedBy)
{
    FcRangeObject obj;
    obj.fc_model_id = fcModelId;
    obj.start_month = startMonth;
    obj.start_day = startDay;
    obj.end_month = endMonth;
    obj.end_day = endDay;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return FcRange();
    }
    return FcRange(obj);
}

FcRange FcRange::create(const QVariantMap &values)
{
    FcRange model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

FcRange FcRange::get(int fcRangeId)
{
    TSqlORMapper<FcRangeObject> mapper;
    return FcRange(mapper.findByPrimaryKey(fcRangeId));
}

int FcRange::count()
{
    TSqlORMapper<FcRangeObject> mapper;
    return mapper.findCount();
}

QList<FcRange> FcRange::getAll()
{
    return tfGetModelListByCriteria<FcRange, FcRangeObject>();
}

TModelObject *FcRange::modelData()
{
    return d.data();
}

const TModelObject *FcRange::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const FcRange &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, FcRange &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(FcRange)
