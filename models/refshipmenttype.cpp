#include <TreeFrogModel>
#include "refshipmenttype.h"
#include "refshipmenttypeobject.h"

RefShipmentType::RefShipmentType()
    : TAbstractModel(), d(new RefShipmentTypeObject())
{ }

RefShipmentType::RefShipmentType(const RefShipmentType &other)
    : TAbstractModel(), d(new RefShipmentTypeObject(*other.d))
{ }

RefShipmentType::RefShipmentType(const RefShipmentTypeObject &object)
    : TAbstractModel(), d(new RefShipmentTypeObject(object))
{ }

RefShipmentType::~RefShipmentType()
{
    // If the reference count becomes 0,
    // the shared data object 'RefShipmentTypeObject' is deleted.
}

QString RefShipmentType::shipmentTypeCd() const
{
    return d->shipment_type_cd;
}

void RefShipmentType::setShipmentTypeCd(const QString &shipmentTypeCd)
{
    d->shipment_type_cd = shipmentTypeCd;
}

QString RefShipmentType::shipmentTypeNameEn() const
{
    return d->shipment_type_name_en;
}

void RefShipmentType::setShipmentTypeNameEn(const QString &shipmentTypeNameEn)
{
    d->shipment_type_name_en = shipmentTypeNameEn;
}

QString RefShipmentType::shipmentTypeNameZh() const
{
    return d->shipment_type_name_zh;
}

void RefShipmentType::setShipmentTypeNameZh(const QString &shipmentTypeNameZh)
{
    d->shipment_type_name_zh = shipmentTypeNameZh;
}

QString RefShipmentType::shipmentTypeDesc() const
{
    return d->shipment_type_desc;
}

void RefShipmentType::setShipmentTypeDesc(const QString &shipmentTypeDesc)
{
    d->shipment_type_desc = shipmentTypeDesc;
}

QDateTime RefShipmentType::createdAt() const
{
    return d->created_at;
}

QString RefShipmentType::createdBy() const
{
    return d->created_by;
}

void RefShipmentType::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime RefShipmentType::updatedAt() const
{
    return d->updated_at;
}

QString RefShipmentType::updatedBy() const
{
    return d->updated_by;
}

void RefShipmentType::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

RefShipmentType &RefShipmentType::operator=(const RefShipmentType &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

RefShipmentType RefShipmentType::create(const QString &shipmentTypeCd, const QString &shipmentTypeNameEn, const QString &shipmentTypeNameZh, const QString &shipmentTypeDesc, const QString &createdBy, const QString &updatedBy)
{
    RefShipmentTypeObject obj;
    obj.shipment_type_cd = shipmentTypeCd;
    obj.shipment_type_name_en = shipmentTypeNameEn;
    obj.shipment_type_name_zh = shipmentTypeNameZh;
    obj.shipment_type_desc = shipmentTypeDesc;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return RefShipmentType();
    }
    return RefShipmentType(obj);
}

RefShipmentType RefShipmentType::create(const QVariantMap &values)
{
    RefShipmentType model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

RefShipmentType RefShipmentType::get(const QString &shipmentTypeCd)
{
    TSqlORMapper<RefShipmentTypeObject> mapper;
    return RefShipmentType(mapper.findByPrimaryKey(shipmentTypeCd));
}

int RefShipmentType::count()
{
    TSqlORMapper<RefShipmentTypeObject> mapper;
    return mapper.findCount();
}

QList<RefShipmentType> RefShipmentType::getAll()
{
    return tfGetModelListByCriteria<RefShipmentType, RefShipmentTypeObject>();
}

TModelObject *RefShipmentType::modelData()
{
    return d.data();
}

const TModelObject *RefShipmentType::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const RefShipmentType &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, RefShipmentType &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(RefShipmentType)
