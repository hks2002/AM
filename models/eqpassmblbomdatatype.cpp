#include <TreeFrogModel>
#include "eqpassmblbomdatatype.h"
#include "eqpassmblbomdatatypeobject.h"
#include "datatype.h"
#include "eqpassmblbom.h"

EqpAssmblBomDataType::EqpAssmblBomDataType()
    : TAbstractModel(), d(new EqpAssmblBomDataTypeObject())
{
    d->assmbl_bom_id = 0;
    d->data_type_id = 0;
}

EqpAssmblBomDataType::EqpAssmblBomDataType(const EqpAssmblBomDataType &other)
    : TAbstractModel(), d(new EqpAssmblBomDataTypeObject(*other.d))
{ }

EqpAssmblBomDataType::EqpAssmblBomDataType(const EqpAssmblBomDataTypeObject &object)
    : TAbstractModel(), d(new EqpAssmblBomDataTypeObject(object))
{ }

EqpAssmblBomDataType::~EqpAssmblBomDataType()
{
    // If the reference count becomes 0,
    // the shared data object 'EqpAssmblBomDataTypeObject' is deleted.
}

int EqpAssmblBomDataType::assmblBomId() const
{
    return d->assmbl_bom_id;
}

void EqpAssmblBomDataType::setAssmblBomId(int assmblBomId)
{
    d->assmbl_bom_id = assmblBomId;
}

int EqpAssmblBomDataType::dataTypeId() const
{
    return d->data_type_id;
}

void EqpAssmblBomDataType::setDataTypeId(int dataTypeId)
{
    d->data_type_id = dataTypeId;
}

QDateTime EqpAssmblBomDataType::createdAt() const
{
    return d->created_at;
}

QString EqpAssmblBomDataType::createdBy() const
{
    return d->created_by;
}

void EqpAssmblBomDataType::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime EqpAssmblBomDataType::updatedAt() const
{
    return d->updated_at;
}

QString EqpAssmblBomDataType::updatedBy() const
{
    return d->updated_by;
}

void EqpAssmblBomDataType::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

DataType EqpAssmblBomDataType::dataTypeBydataTypeId() const
{
 return DataType::get(d->data_type_id);
}

EqpAssmblBom EqpAssmblBomDataType::eqpAssmblBomByassmblBomId() const
{
 return EqpAssmblBom::get(d->assmbl_bom_id);
}

EqpAssmblBomDataType &EqpAssmblBomDataType::operator=(const EqpAssmblBomDataType &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

EqpAssmblBomDataType EqpAssmblBomDataType::create(int assmblBomId, int dataTypeId, const QString &createdBy, const QString &updatedBy)
{
    EqpAssmblBomDataTypeObject obj;
    obj.assmbl_bom_id = assmblBomId;
    obj.data_type_id = dataTypeId;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return EqpAssmblBomDataType();
    }
    return EqpAssmblBomDataType(obj);
}

EqpAssmblBomDataType EqpAssmblBomDataType::create(const QVariantMap &values)
{
    EqpAssmblBomDataType model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

EqpAssmblBomDataType EqpAssmblBomDataType::get(int assmblBomId, int dataTypeId)
{
    TSqlORMapper<EqpAssmblBomDataTypeObject> mapper;
    return EqpAssmblBomDataType(mapper.findByPrimaryKey(QVariantList()<<QVariant(assmblBomId)<<QVariant(dataTypeId)));
}

int EqpAssmblBomDataType::count()
{
    TSqlORMapper<EqpAssmblBomDataTypeObject> mapper;
    return mapper.findCount();
}

QList<EqpAssmblBomDataType> EqpAssmblBomDataType::getAll()
{
    return tfGetModelListByCriteria<EqpAssmblBomDataType, EqpAssmblBomDataTypeObject>();
}

TModelObject *EqpAssmblBomDataType::modelData()
{
    return d.data();
}

const TModelObject *EqpAssmblBomDataType::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const EqpAssmblBomDataType &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, EqpAssmblBomDataType &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(EqpAssmblBomDataType)
