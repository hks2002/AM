#include <TreeFrogModel>
#include "datatype.h"
#include "datatypeobject.h"
#include "refengunit.h"

DataType::DataType()
    : TAbstractModel(), d(new DataTypeObject())
{
    d->data_type_id = 0;
}

DataType::DataType(const DataType &other)
    : TAbstractModel(), d(new DataTypeObject(*other.d))
{ }

DataType::DataType(const DataTypeObject &object)
    : TAbstractModel(), d(new DataTypeObject(object))
{ }

DataType::~DataType()
{
    // If the reference count becomes 0,
    // the shared data object 'DataTypeObject' is deleted.
}

int DataType::dataTypeId() const
{
    return d->data_type_id;
}

QString DataType::dataTypeCd() const
{
    return d->data_type_cd;
}

void DataType::setDataTypeCd(const QString &dataTypeCd)
{
    d->data_type_cd = dataTypeCd;
}

QString DataType::dataTypeNameZh() const
{
    return d->data_type_name_zh;
}

void DataType::setDataTypeNameZh(const QString &dataTypeNameZh)
{
    d->data_type_name_zh = dataTypeNameZh;
}

QString DataType::dataTypeNameEn() const
{
    return d->data_type_name_en;
}

void DataType::setDataTypeNameEn(const QString &dataTypeNameEn)
{
    d->data_type_name_en = dataTypeNameEn;
}

QString DataType::engUnitCd() const
{
    return d->eng_unit_cd;
}

void DataType::setEngUnitCd(const QString &engUnitCd)
{
    d->eng_unit_cd = engUnitCd;
}

QDateTime DataType::createdAt() const
{
    return d->created_at;
}

QString DataType::createdBy() const
{
    return d->created_by;
}

void DataType::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime DataType::updatedAt() const
{
    return d->updated_at;
}

QString DataType::updatedBy() const
{
    return d->updated_by;
}

void DataType::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

RefEngUnit DataType::refEngUnitByengUnitCd() const
{
 return RefEngUnit::get(d->eng_unit_cd);
}

DataType &DataType::operator=(const DataType &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

DataType DataType::create(const QString &dataTypeCd, const QString &dataTypeNameZh, const QString &dataTypeNameEn, const QString &engUnitCd, const QString &createdBy, const QString &updatedBy)
{
    DataTypeObject obj;
    obj.data_type_cd = dataTypeCd;
    obj.data_type_name_zh = dataTypeNameZh;
    obj.data_type_name_en = dataTypeNameEn;
    obj.eng_unit_cd = engUnitCd;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return DataType();
    }
    return DataType(obj);
}

DataType DataType::create(const QVariantMap &values)
{
    DataType model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

DataType DataType::get(int dataTypeId)
{
    TSqlORMapper<DataTypeObject> mapper;
    return DataType(mapper.findByPrimaryKey(dataTypeId));
}

int DataType::count()
{
    TSqlORMapper<DataTypeObject> mapper;
    return mapper.findCount();
}

QList<DataType> DataType::getAll()
{
    return tfGetModelListByCriteria<DataType, DataTypeObject>();
}

TModelObject *DataType::modelData()
{
    return d.data();
}

const TModelObject *DataType::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const DataType &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, DataType &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(DataType)
