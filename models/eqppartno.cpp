#include <TreeFrogModel>
#include "eqppartno.h"
#include "eqppartnoobject.h"
#include "refparttype.h"
#include "refpartuse.h"
#include "qtyunit.h"
#include "fncaccount.h"
#include "refinvclass.h"
#include "refpartstatus.h"
#include "manufact.h"

EqpPartNo::EqpPartNo()
    : TAbstractModel(), d(new EqpPartNoObject())
{
    d->part_no_id = 0;
    d->manufact_id = 0;
    d->account_id = 0;
    d->qty_unit_id = 0;
}

EqpPartNo::EqpPartNo(const EqpPartNo &other)
    : TAbstractModel(), d(new EqpPartNoObject(*other.d))
{ }

EqpPartNo::EqpPartNo(const EqpPartNoObject &object)
    : TAbstractModel(), d(new EqpPartNoObject(object))
{ }

EqpPartNo::~EqpPartNo()
{
    // If the reference count becomes 0,
    // the shared data object 'EqpPartNoObject' is deleted.
}

int EqpPartNo::partNoId() const
{
    return d->part_no_id;
}

int EqpPartNo::manufactId() const
{
    return d->manufact_id;
}

void EqpPartNo::setManufactId(int manufactId)
{
    d->manufact_id = manufactId;
}

QString EqpPartNo::partNoOem() const
{
    return d->part_no_oem;
}

void EqpPartNo::setPartNoOem(const QString &partNoOem)
{
    d->part_no_oem = partNoOem;
}

QString EqpPartNo::partNoName() const
{
    return d->part_no_name;
}

void EqpPartNo::setPartNoName(const QString &partNoName)
{
    d->part_no_name = partNoName;
}

QString EqpPartNo::modelName() const
{
    return d->model_name;
}

void EqpPartNo::setModelName(const QString &modelName)
{
    d->model_name = modelName;
}

QString EqpPartNo::partNoDesc() const
{
    return d->part_no_desc;
}

void EqpPartNo::setPartNoDesc(const QString &partNoDesc)
{
    d->part_no_desc = partNoDesc;
}

QString EqpPartNo::partStatusCd() const
{
    return d->part_status_cd;
}

void EqpPartNo::setPartStatusCd(const QString &partStatusCd)
{
    d->part_status_cd = partStatusCd;
}

QString EqpPartNo::invClassCd() const
{
    return d->inv_class_cd;
}

void EqpPartNo::setInvClassCd(const QString &invClassCd)
{
    d->inv_class_cd = invClassCd;
}

int EqpPartNo::accountId() const
{
    return d->account_id;
}

void EqpPartNo::setAccountId(int accountId)
{
    d->account_id = accountId;
}

bool EqpPartNo::pmaBool() const
{
    return d->pma_bool;
}

void EqpPartNo::setPmaBool(bool pmaBool)
{
    d->pma_bool = pmaBool;
}

QString EqpPartNo::picture() const
{
    return d->picture;
}

void EqpPartNo::setPicture(const QString &picture)
{
    d->picture = picture;
}

int EqpPartNo::qtyUnitId() const
{
    return d->qty_unit_id;
}

void EqpPartNo::setQtyUnitId(int qtyUnitId)
{
    d->qty_unit_id = qtyUnitId;
}

QString EqpPartNo::partUseCd() const
{
    return d->part_use_cd;
}

void EqpPartNo::setPartUseCd(const QString &partUseCd)
{
    d->part_use_cd = partUseCd;
}

QString EqpPartNo::partTypeCd() const
{
    return d->part_type_cd;
}

void EqpPartNo::setPartTypeCd(const QString &partTypeCd)
{
    d->part_type_cd = partTypeCd;
}

QDateTime EqpPartNo::createdAt() const
{
    return d->created_at;
}

QString EqpPartNo::createdBy() const
{
    return d->created_by;
}

void EqpPartNo::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime EqpPartNo::updatedAt() const
{
    return d->updated_at;
}

QString EqpPartNo::updatedBy() const
{
    return d->updated_by;
}

void EqpPartNo::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

RefPartType EqpPartNo::refPartTypeBypartTypeCd() const
{
 return RefPartType::get(d->part_type_cd);
}

RefPartUse EqpPartNo::refPartUseBypartUseCd() const
{
 return RefPartUse::get(d->part_use_cd);
}

QtyUnit EqpPartNo::qtyUnitByqtyUnitId() const
{
 return QtyUnit::get(d->qty_unit_id);
}

FncAccount EqpPartNo::fncAccountByaccountId() const
{
 return FncAccount::get(d->account_id);
}

RefInvClass EqpPartNo::refInvClassByinvClassCd() const
{
 return RefInvClass::get(d->inv_class_cd);
}

RefPartStatus EqpPartNo::refPartStatusBypartStatusCd() const
{
 return RefPartStatus::get(d->part_status_cd);
}

Manufact EqpPartNo::manufactBymanufactId() const
{
 return Manufact::get(d->manufact_id);
}

EqpPartNo &EqpPartNo::operator=(const EqpPartNo &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

EqpPartNo EqpPartNo::create(int manufactId, const QString &partNoOem, const QString &partNoName, const QString &modelName, const QString &partNoDesc, const QString &partStatusCd, const QString &invClassCd, int accountId, bool pmaBool, const QString &picture, int qtyUnitId, const QString &partUseCd, const QString &partTypeCd, const QString &createdBy, const QString &updatedBy)
{
    EqpPartNoObject obj;
    obj.manufact_id = manufactId;
    obj.part_no_oem = partNoOem;
    obj.part_no_name = partNoName;
    obj.model_name = modelName;
    obj.part_no_desc = partNoDesc;
    obj.part_status_cd = partStatusCd;
    obj.inv_class_cd = invClassCd;
    obj.account_id = accountId;
    obj.pma_bool = pmaBool;
    obj.picture = picture;
    obj.qty_unit_id = qtyUnitId;
    obj.part_use_cd = partUseCd;
    obj.part_type_cd = partTypeCd;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return EqpPartNo();
    }
    return EqpPartNo(obj);
}

EqpPartNo EqpPartNo::create(const QVariantMap &values)
{
    EqpPartNo model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

EqpPartNo EqpPartNo::get(int partNoId)
{
    TSqlORMapper<EqpPartNoObject> mapper;
    return EqpPartNo(mapper.findByPrimaryKey(partNoId));
}

int EqpPartNo::count()
{
    TSqlORMapper<EqpPartNoObject> mapper;
    return mapper.findCount();
}

QList<EqpPartNo> EqpPartNo::getAll()
{
    return tfGetModelListByCriteria<EqpPartNo, EqpPartNoObject>();
}

TModelObject *EqpPartNo::modelData()
{
    return d.data();
}

const TModelObject *EqpPartNo::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const EqpPartNo &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, EqpPartNo &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(EqpPartNo)
