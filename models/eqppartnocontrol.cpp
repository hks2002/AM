#include <TreeFrogModel>
#include "eqppartnocontrol.h"
#include "eqppartnocontrolobject.h"
#include "eqppartno.h"

EqpPartNoControl::EqpPartNoControl()
    : TAbstractModel(), d(new EqpPartNoControlObject())
{
    d->part_no_id = 0;
    d->shelf_life_qt = 0;
}

EqpPartNoControl::EqpPartNoControl(const EqpPartNoControl &other)
    : TAbstractModel(), d(new EqpPartNoControlObject(*other.d))
{ }

EqpPartNoControl::EqpPartNoControl(const EqpPartNoControlObject &object)
    : TAbstractModel(), d(new EqpPartNoControlObject(object))
{ }

EqpPartNoControl::~EqpPartNoControl()
{
    // If the reference count becomes 0,
    // the shared data object 'EqpPartNoControlObject' is deleted.
}

int EqpPartNoControl::partNoId() const
{
    return d->part_no_id;
}

void EqpPartNoControl::setPartNoId(int partNoId)
{
    d->part_no_id = partNoId;
}

bool EqpPartNoControl::controlReserveBool() const
{
    return d->control_reserve_bool;
}

void EqpPartNoControl::setControlReserveBool(bool controlReserveBool)
{
    d->control_reserve_bool = controlReserveBool;
}

bool EqpPartNoControl::noAutoReserveBool() const
{
    return d->no_auto_reserve_bool;
}

void EqpPartNoControl::setNoAutoReserveBool(bool noAutoReserveBool)
{
    d->no_auto_reserve_bool = noAutoReserveBool;
}

bool EqpPartNoControl::receiptInspBool() const
{
    return d->receipt_insp_bool;
}

void EqpPartNoControl::setReceiptInspBool(bool receiptInspBool)
{
    d->receipt_insp_bool = receiptInspBool;
}

bool EqpPartNoControl::purchasableBool() const
{
    return d->purchasable_bool;
}

void EqpPartNoControl::setPurchasableBool(bool purchasableBool)
{
    d->purchasable_bool = purchasableBool;
}

bool EqpPartNoControl::repairBool() const
{
    return d->repair_bool;
}

void EqpPartNoControl::setRepairBool(bool repairBool)
{
    d->repair_bool = repairBool;
}

int EqpPartNoControl::shelfLifeQt() const
{
    return d->shelf_life_qt;
}

void EqpPartNoControl::setShelfLifeQt(int shelfLifeQt)
{
    d->shelf_life_qt = shelfLifeQt;
}

QString EqpPartNoControl::shelfLifeUnit() const
{
    return d->shelf_life_unit;
}

void EqpPartNoControl::setShelfLifeUnit(const QString &shelfLifeUnit)
{
    d->shelf_life_unit = shelfLifeUnit;
}

QDateTime EqpPartNoControl::createdAt() const
{
    return d->created_at;
}

QString EqpPartNoControl::createdBy() const
{
    return d->created_by;
}

void EqpPartNoControl::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime EqpPartNoControl::updatedAt() const
{
    return d->updated_at;
}

QString EqpPartNoControl::updatedBy() const
{
    return d->updated_by;
}

void EqpPartNoControl::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

EqpPartNo EqpPartNoControl::eqpPartNoBypartNoId() const
{
 return EqpPartNo::get(d->part_no_id);
}

EqpPartNoControl &EqpPartNoControl::operator=(const EqpPartNoControl &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

EqpPartNoControl EqpPartNoControl::create(int partNoId, bool controlReserveBool, bool noAutoReserveBool, bool receiptInspBool, bool purchasableBool, bool repairBool, int shelfLifeQt, const QString &shelfLifeUnit, const QString &createdBy, const QString &updatedBy)
{
    EqpPartNoControlObject obj;
    obj.part_no_id = partNoId;
    obj.control_reserve_bool = controlReserveBool;
    obj.no_auto_reserve_bool = noAutoReserveBool;
    obj.receipt_insp_bool = receiptInspBool;
    obj.purchasable_bool = purchasableBool;
    obj.repair_bool = repairBool;
    obj.shelf_life_qt = shelfLifeQt;
    obj.shelf_life_unit = shelfLifeUnit;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return EqpPartNoControl();
    }
    return EqpPartNoControl(obj);
}

EqpPartNoControl EqpPartNoControl::create(const QVariantMap &values)
{
    EqpPartNoControl model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

EqpPartNoControl EqpPartNoControl::get(int partNoId)
{
    TSqlORMapper<EqpPartNoControlObject> mapper;
    return EqpPartNoControl(mapper.findByPrimaryKey(partNoId));
}

int EqpPartNoControl::count()
{
    TSqlORMapper<EqpPartNoControlObject> mapper;
    return mapper.findCount();
}

QList<EqpPartNoControl> EqpPartNoControl::getAll()
{
    return tfGetModelListByCriteria<EqpPartNoControl, EqpPartNoControlObject>();
}

TModelObject *EqpPartNoControl::modelData()
{
    return d.data();
}

const TModelObject *EqpPartNoControl::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const EqpPartNoControl &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, EqpPartNoControl &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(EqpPartNoControl)
