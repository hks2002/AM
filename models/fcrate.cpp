#include <TreeFrogModel>
#include "fcrate.h"
#include "fcrateobject.h"
#include "datatype.h"
#include "fcrange.h"
#include "fcmodel.h"

FcRate::FcRate()
    : TAbstractModel(), d(new FcRateObject())
{
    d->fc_model_id = 0;
    d->fc_range_id = 0;
    d->data_type_id = 0;
    d->forecast_rate_qt = 0;
}

FcRate::FcRate(const FcRate &other)
    : TAbstractModel(), d(new FcRateObject(*other.d))
{ }

FcRate::FcRate(const FcRateObject &object)
    : TAbstractModel(), d(new FcRateObject(object))
{ }

FcRate::~FcRate()
{
    // If the reference count becomes 0,
    // the shared data object 'FcRateObject' is deleted.
}

int FcRate::fcModelId() const
{
    return d->fc_model_id;
}

void FcRate::setFcModelId(int fcModelId)
{
    d->fc_model_id = fcModelId;
}

int FcRate::fcRangeId() const
{
    return d->fc_range_id;
}

void FcRate::setFcRangeId(int fcRangeId)
{
    d->fc_range_id = fcRangeId;
}

int FcRate::dataTypeId() const
{
    return d->data_type_id;
}

void FcRate::setDataTypeId(int dataTypeId)
{
    d->data_type_id = dataTypeId;
}

double FcRate::forecastRateQt() const
{
    return d->forecast_rate_qt;
}

void FcRate::setForecastRateQt(double forecastRateQt)
{
    d->forecast_rate_qt = forecastRateQt;
}

QDateTime FcRate::createdAt() const
{
    return d->created_at;
}

QString FcRate::createdBy() const
{
    return d->created_by;
}

void FcRate::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime FcRate::updatedAt() const
{
    return d->updated_at;
}

QString FcRate::updatedBy() const
{
    return d->updated_by;
}

void FcRate::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

DataType FcRate::dataTypeBydataTypeId() const
{
 return DataType::get(d->data_type_id);
}

FcRange FcRate::fcRangeByfcRangeId() const
{
 return FcRange::get(d->fc_range_id);
}

FcModel FcRate::fcModelByfcModelId() const
{
 return FcModel::get(d->fc_model_id);
}

FcRate &FcRate::operator=(const FcRate &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

FcRate FcRate::create(int fcModelId, int fcRangeId, int dataTypeId, double forecastRateQt, const QString &createdBy, const QString &updatedBy)
{
    FcRateObject obj;
    obj.fc_model_id = fcModelId;
    obj.fc_range_id = fcRangeId;
    obj.data_type_id = dataTypeId;
    obj.forecast_rate_qt = forecastRateQt;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return FcRate();
    }
    return FcRate(obj);
}

FcRate FcRate::create(const QVariantMap &values)
{
    FcRate model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

FcRate FcRate::get(int fcModelId, int fcRangeId, int dataTypeId)
{
    TSqlORMapper<FcRateObject> mapper;
    return FcRate(mapper.findByPrimaryKey(QVariantList()<<QVariant(fcModelId)<<QVariant(fcRangeId)<<QVariant(dataTypeId)));
}

int FcRate::count()
{
    TSqlORMapper<FcRateObject> mapper;
    return mapper.findCount();
}

QList<FcRate> FcRate::getAll()
{
    return tfGetModelListByCriteria<FcRate, FcRateObject>();
}

TModelObject *FcRate::modelData()
{
    return d.data();
}

const TModelObject *FcRate::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const FcRate &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, FcRate &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(FcRate)
