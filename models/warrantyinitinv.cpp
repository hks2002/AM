#include <TreeFrogModel>
#include "warrantyinitinv.h"
#include "warrantyinitinvobject.h"
#include "invinv.h"
#include "warrantyinit.h"

WarrantyInitInv::WarrantyInitInv()
    : TAbstractModel(), d(new WarrantyInitInvObject())
{
    d->warranty_init_id = 0;
    d->inv_no_id = 0;
}

WarrantyInitInv::WarrantyInitInv(const WarrantyInitInv &other)
    : TAbstractModel(), d(new WarrantyInitInvObject(*other.d))
{ }

WarrantyInitInv::WarrantyInitInv(const WarrantyInitInvObject &object)
    : TAbstractModel(), d(new WarrantyInitInvObject(object))
{ }

WarrantyInitInv::~WarrantyInitInv()
{
    // If the reference count becomes 0,
    // the shared data object 'WarrantyInitInvObject' is deleted.
}

int WarrantyInitInv::warrantyInitId() const
{
    return d->warranty_init_id;
}

void WarrantyInitInv::setWarrantyInitId(int warrantyInitId)
{
    d->warranty_init_id = warrantyInitId;
}

int WarrantyInitInv::invNoId() const
{
    return d->inv_no_id;
}

void WarrantyInitInv::setInvNoId(int invNoId)
{
    d->inv_no_id = invNoId;
}

bool WarrantyInitInv::mainBool() const
{
    return d->main_bool;
}

void WarrantyInitInv::setMainBool(bool mainBool)
{
    d->main_bool = mainBool;
}

QDateTime WarrantyInitInv::createdAt() const
{
    return d->created_at;
}

QString WarrantyInitInv::createdBy() const
{
    return d->created_by;
}

void WarrantyInitInv::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime WarrantyInitInv::updatedAt() const
{
    return d->updated_at;
}

QString WarrantyInitInv::updatedBy() const
{
    return d->updated_by;
}

void WarrantyInitInv::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

InvInv WarrantyInitInv::invInvByinvNoId() const
{
 return InvInv::get(d->inv_no_id);
}

WarrantyInit WarrantyInitInv::warrantyInitBywarrantyInitId() const
{
 return WarrantyInit::get(d->warranty_init_id);
}

WarrantyInitInv &WarrantyInitInv::operator=(const WarrantyInitInv &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

WarrantyInitInv WarrantyInitInv::create(int warrantyInitId, int invNoId, bool mainBool, const QString &createdBy, const QString &updatedBy)
{
    WarrantyInitInvObject obj;
    obj.warranty_init_id = warrantyInitId;
    obj.inv_no_id = invNoId;
    obj.main_bool = mainBool;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return WarrantyInitInv();
    }
    return WarrantyInitInv(obj);
}

WarrantyInitInv WarrantyInitInv::create(const QVariantMap &values)
{
    WarrantyInitInv model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

WarrantyInitInv WarrantyInitInv::get(int warrantyInitId, int invNoId)
{
    TSqlORMapper<WarrantyInitInvObject> mapper;
    return WarrantyInitInv(mapper.findByPrimaryKey(QVariantList()<<QVariant(warrantyInitId)<<QVariant(invNoId)));
}

int WarrantyInitInv::count()
{
    TSqlORMapper<WarrantyInitInvObject> mapper;
    return mapper.findCount();
}

QList<WarrantyInitInv> WarrantyInitInv::getAll()
{
    return tfGetModelListByCriteria<WarrantyInitInv, WarrantyInitInvObject>();
}

TModelObject *WarrantyInitInv::modelData()
{
    return d.data();
}

const TModelObject *WarrantyInitInv::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const WarrantyInitInv &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, WarrantyInitInv &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(WarrantyInitInv)
