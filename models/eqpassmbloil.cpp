#include <TreeFrogModel>
#include "eqpassmbloil.h"
#include "eqpassmbloilobject.h"
#include "mesurunit.h"
#include "eqpassmbldatatype.h"

EqpAssmblOil::EqpAssmblOil()
    : TAbstractModel(), d(new EqpAssmblOilObject())
{
    d->assmbl_id = 0;
    d->mesur_unit_id = 0;
    d->data_type_id = 0;
    d->full_qty = 0;
    d->caution_rate = 0;
    d->warning_rate = 0;
}

EqpAssmblOil::EqpAssmblOil(const EqpAssmblOil &other)
    : TAbstractModel(), d(new EqpAssmblOilObject(*other.d))
{ }

EqpAssmblOil::EqpAssmblOil(const EqpAssmblOilObject &object)
    : TAbstractModel(), d(new EqpAssmblOilObject(object))
{ }

EqpAssmblOil::~EqpAssmblOil()
{
    // If the reference count becomes 0,
    // the shared data object 'EqpAssmblOilObject' is deleted.
}

int EqpAssmblOil::assmblId() const
{
    return d->assmbl_id;
}

void EqpAssmblOil::setAssmblId(int assmblId)
{
    d->assmbl_id = assmblId;
}

int EqpAssmblOil::mesurUnitId() const
{
    return d->mesur_unit_id;
}

void EqpAssmblOil::setMesurUnitId(int mesurUnitId)
{
    d->mesur_unit_id = mesurUnitId;
}

int EqpAssmblOil::dataTypeId() const
{
    return d->data_type_id;
}

void EqpAssmblOil::setDataTypeId(int dataTypeId)
{
    d->data_type_id = dataTypeId;
}

double EqpAssmblOil::fullQty() const
{
    return d->full_qty;
}

void EqpAssmblOil::setFullQty(double fullQty)
{
    d->full_qty = fullQty;
}

double EqpAssmblOil::cautionRate() const
{
    return d->caution_rate;
}

void EqpAssmblOil::setCautionRate(double cautionRate)
{
    d->caution_rate = cautionRate;
}

double EqpAssmblOil::warningRate() const
{
    return d->warning_rate;
}

void EqpAssmblOil::setWarningRate(double warningRate)
{
    d->warning_rate = warningRate;
}

QDateTime EqpAssmblOil::createdAt() const
{
    return d->created_at;
}

QString EqpAssmblOil::createdBy() const
{
    return d->created_by;
}

void EqpAssmblOil::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime EqpAssmblOil::updatedAt() const
{
    return d->updated_at;
}

QString EqpAssmblOil::updatedBy() const
{
    return d->updated_by;
}

void EqpAssmblOil::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

MesurUnit EqpAssmblOil::mesurUnitBymesurUnitId() const
{
 return MesurUnit::get(d->mesur_unit_id);
}

EqpAssmblDataType EqpAssmblOil::eqpAssmblDataTypeByassmblIddataTypeId() const
{
 return EqpAssmblDataType::get(d->assmbl_id, d->data_type_id);
}

EqpAssmblOil &EqpAssmblOil::operator=(const EqpAssmblOil &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

EqpAssmblOil EqpAssmblOil::create(int assmblId, int mesurUnitId, int dataTypeId, double fullQty, double cautionRate, double warningRate, const QString &createdBy, const QString &updatedBy)
{
    EqpAssmblOilObject obj;
    obj.assmbl_id = assmblId;
    obj.mesur_unit_id = mesurUnitId;
    obj.data_type_id = dataTypeId;
    obj.full_qty = fullQty;
    obj.caution_rate = cautionRate;
    obj.warning_rate = warningRate;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return EqpAssmblOil();
    }
    return EqpAssmblOil(obj);
}

EqpAssmblOil EqpAssmblOil::create(const QVariantMap &values)
{
    EqpAssmblOil model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

EqpAssmblOil EqpAssmblOil::get(int assmblId, int mesurUnitId, int dataTypeId)
{
    TSqlORMapper<EqpAssmblOilObject> mapper;
    return EqpAssmblOil(mapper.findByPrimaryKey(QVariantList()<<QVariant(assmblId)<<QVariant(mesurUnitId)<<QVariant(dataTypeId)));
}

int EqpAssmblOil::count()
{
    TSqlORMapper<EqpAssmblOilObject> mapper;
    return mapper.findCount();
}

QList<EqpAssmblOil> EqpAssmblOil::getAll()
{
    return tfGetModelListByCriteria<EqpAssmblOil, EqpAssmblOilObject>();
}

TModelObject *EqpAssmblOil::modelData()
{
    return d.data();
}

const TModelObject *EqpAssmblOil::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const EqpAssmblOil &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, EqpAssmblOil &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(EqpAssmblOil)
