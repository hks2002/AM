#include <TreeFrogModel>
#include "eqppartnoshipstoragepackage.h"
#include "eqppartnoshipstoragepackageobject.h"
#include "eqppartno.h"

EqpPartNoShipStoragePackage::EqpPartNoShipStoragePackage()
    : TAbstractModel(), d(new EqpPartNoShipStoragePackageObject())
{
    d->part_no_id = 0;
}

EqpPartNoShipStoragePackage::EqpPartNoShipStoragePackage(const EqpPartNoShipStoragePackage &other)
    : TAbstractModel(), d(new EqpPartNoShipStoragePackageObject(*other.d))
{ }

EqpPartNoShipStoragePackage::EqpPartNoShipStoragePackage(const EqpPartNoShipStoragePackageObject &object)
    : TAbstractModel(), d(new EqpPartNoShipStoragePackageObject(object))
{ }

EqpPartNoShipStoragePackage::~EqpPartNoShipStoragePackage()
{
    // If the reference count becomes 0,
    // the shared data object 'EqpPartNoShipStoragePackageObject' is deleted.
}

int EqpPartNoShipStoragePackage::partNoId() const
{
    return d->part_no_id;
}

void EqpPartNoShipStoragePackage::setPartNoId(int partNoId)
{
    d->part_no_id = partNoId;
}

QString EqpPartNoShipStoragePackage::shippingDesc() const
{
    return d->shipping_desc;
}

void EqpPartNoShipStoragePackage::setShippingDesc(const QString &shippingDesc)
{
    d->shipping_desc = shippingDesc;
}

QString EqpPartNoShipStoragePackage::storageDesc() const
{
    return d->storage_desc;
}

void EqpPartNoShipStoragePackage::setStorageDesc(const QString &storageDesc)
{
    d->storage_desc = storageDesc;
}

QString EqpPartNoShipStoragePackage::packingDesc() const
{
    return d->packing_desc;
}

void EqpPartNoShipStoragePackage::setPackingDesc(const QString &packingDesc)
{
    d->packing_desc = packingDesc;
}

QString EqpPartNoShipStoragePackage::hazmatDesc() const
{
    return d->hazmat_desc;
}

void EqpPartNoShipStoragePackage::setHazmatDesc(const QString &hazmatDesc)
{
    d->hazmat_desc = hazmatDesc;
}

QDateTime EqpPartNoShipStoragePackage::createdAt() const
{
    return d->created_at;
}

QString EqpPartNoShipStoragePackage::createdBy() const
{
    return d->created_by;
}

void EqpPartNoShipStoragePackage::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime EqpPartNoShipStoragePackage::updatedAt() const
{
    return d->updated_at;
}

QString EqpPartNoShipStoragePackage::updatedBy() const
{
    return d->updated_by;
}

void EqpPartNoShipStoragePackage::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

EqpPartNo EqpPartNoShipStoragePackage::eqpPartNoBypartNoId() const
{
 return EqpPartNo::get(d->part_no_id);
}

EqpPartNoShipStoragePackage &EqpPartNoShipStoragePackage::operator=(const EqpPartNoShipStoragePackage &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

EqpPartNoShipStoragePackage EqpPartNoShipStoragePackage::create(int partNoId, const QString &shippingDesc, const QString &storageDesc, const QString &packingDesc, const QString &hazmatDesc, const QString &createdBy, const QString &updatedBy)
{
    EqpPartNoShipStoragePackageObject obj;
    obj.part_no_id = partNoId;
    obj.shipping_desc = shippingDesc;
    obj.storage_desc = storageDesc;
    obj.packing_desc = packingDesc;
    obj.hazmat_desc = hazmatDesc;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return EqpPartNoShipStoragePackage();
    }
    return EqpPartNoShipStoragePackage(obj);
}

EqpPartNoShipStoragePackage EqpPartNoShipStoragePackage::create(const QVariantMap &values)
{
    EqpPartNoShipStoragePackage model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

EqpPartNoShipStoragePackage EqpPartNoShipStoragePackage::get(int partNoId)
{
    TSqlORMapper<EqpPartNoShipStoragePackageObject> mapper;
    return EqpPartNoShipStoragePackage(mapper.findByPrimaryKey(partNoId));
}

int EqpPartNoShipStoragePackage::count()
{
    TSqlORMapper<EqpPartNoShipStoragePackageObject> mapper;
    return mapper.findCount();
}

QList<EqpPartNoShipStoragePackage> EqpPartNoShipStoragePackage::getAll()
{
    return tfGetModelListByCriteria<EqpPartNoShipStoragePackage, EqpPartNoShipStoragePackageObject>();
}

TModelObject *EqpPartNoShipStoragePackage::modelData()
{
    return d.data();
}

const TModelObject *EqpPartNoShipStoragePackage::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const EqpPartNoShipStoragePackage &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, EqpPartNoShipStoragePackage &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(EqpPartNoShipStoragePackage)
