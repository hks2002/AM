#include <TreeFrogModel>
#include "eqpassmbldatatype.h"
#include "eqpassmbldatatypeobject.h"
#include "datatype.h"
#include "eqpassmbl.h"

EqpAssmblDataType::EqpAssmblDataType()
    : TAbstractModel(), d(new EqpAssmblDataTypeObject())
{
    d->assmbl_id = 0;
    d->data_type_id = 0;
}

EqpAssmblDataType::EqpAssmblDataType(const EqpAssmblDataType &other)
    : TAbstractModel(), d(new EqpAssmblDataTypeObject(*other.d))
{ }

EqpAssmblDataType::EqpAssmblDataType(const EqpAssmblDataTypeObject &object)
    : TAbstractModel(), d(new EqpAssmblDataTypeObject(object))
{ }

EqpAssmblDataType::~EqpAssmblDataType()
{
    // If the reference count becomes 0,
    // the shared data object 'EqpAssmblDataTypeObject' is deleted.
}

int EqpAssmblDataType::assmblId() const
{
    return d->assmbl_id;
}

void EqpAssmblDataType::setAssmblId(int assmblId)
{
    d->assmbl_id = assmblId;
}

int EqpAssmblDataType::dataTypeId() const
{
    return d->data_type_id;
}

void EqpAssmblDataType::setDataTypeId(int dataTypeId)
{
    d->data_type_id = dataTypeId;
}

QDateTime EqpAssmblDataType::createdAt() const
{
    return d->created_at;
}

QString EqpAssmblDataType::createdBy() const
{
    return d->created_by;
}

void EqpAssmblDataType::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime EqpAssmblDataType::updatedAt() const
{
    return d->updated_at;
}

QString EqpAssmblDataType::updatedBy() const
{
    return d->updated_by;
}

void EqpAssmblDataType::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

DataType EqpAssmblDataType::dataTypeBydataTypeId() const
{
 return DataType::get(d->data_type_id);
}

EqpAssmbl EqpAssmblDataType::eqpAssmblByassmblId() const
{
 return EqpAssmbl::get(d->assmbl_id);
}

EqpAssmblDataType &EqpAssmblDataType::operator=(const EqpAssmblDataType &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

EqpAssmblDataType EqpAssmblDataType::create(int assmblId, int dataTypeId, const QString &createdBy, const QString &updatedBy)
{
    EqpAssmblDataTypeObject obj;
    obj.assmbl_id = assmblId;
    obj.data_type_id = dataTypeId;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return EqpAssmblDataType();
    }
    return EqpAssmblDataType(obj);
}

EqpAssmblDataType EqpAssmblDataType::create(const QVariantMap &values)
{
    EqpAssmblDataType model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

EqpAssmblDataType EqpAssmblDataType::get(int assmblId, int dataTypeId)
{
    TSqlORMapper<EqpAssmblDataTypeObject> mapper;
    return EqpAssmblDataType(mapper.findByPrimaryKey(QVariantList()<<QVariant(assmblId)<<QVariant(dataTypeId)));
}

int EqpAssmblDataType::count()
{
    TSqlORMapper<EqpAssmblDataTypeObject> mapper;
    return mapper.findCount();
}

QList<EqpAssmblDataType> EqpAssmblDataType::getAll()
{
    return tfGetModelListByCriteria<EqpAssmblDataType, EqpAssmblDataTypeObject>();
}

TModelObject *EqpAssmblDataType::modelData()
{
    return d.data();
}

const TModelObject *EqpAssmblDataType::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const EqpAssmblDataType &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, EqpAssmblDataType &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(EqpAssmblDataType)
