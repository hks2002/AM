#include <TreeFrogModel>
#include "invkit.h"
#include "invkitobject.h"
#include "invinv.h"

InvKit::InvKit()
    : TAbstractModel(), d(new InvKitObject())
{
    d->inv_no_id = 0;
}

InvKit::InvKit(const InvKit &other)
    : TAbstractModel(), d(new InvKitObject(*other.d))
{ }

InvKit::InvKit(const InvKitObject &object)
    : TAbstractModel(), d(new InvKitObject(object))
{ }

InvKit::~InvKit()
{
    // If the reference count becomes 0,
    // the shared data object 'InvKitObject' is deleted.
}

int InvKit::invNoId() const
{
    return d->inv_no_id;
}

void InvKit::setInvNoId(int invNoId)
{
    d->inv_no_id = invNoId;
}

bool InvKit::kitCompleteBool() const
{
    return d->kit_complete_bool;
}

void InvKit::setKitCompleteBool(bool kitCompleteBool)
{
    d->kit_complete_bool = kitCompleteBool;
}

bool InvKit::kitSealedBool() const
{
    return d->kit_sealed_bool;
}

void InvKit::setKitSealedBool(bool kitSealedBool)
{
    d->kit_sealed_bool = kitSealedBool;
}

QDateTime InvKit::createdAt() const
{
    return d->created_at;
}

QString InvKit::createdBy() const
{
    return d->created_by;
}

void InvKit::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime InvKit::updatedAt() const
{
    return d->updated_at;
}

QString InvKit::updatedBy() const
{
    return d->updated_by;
}

void InvKit::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

InvInv InvKit::invInvByinvNoId() const
{
 return InvInv::get(d->inv_no_id);
}

InvKit &InvKit::operator=(const InvKit &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

InvKit InvKit::create(int invNoId, bool kitCompleteBool, bool kitSealedBool, const QString &createdBy, const QString &updatedBy)
{
    InvKitObject obj;
    obj.inv_no_id = invNoId;
    obj.kit_complete_bool = kitCompleteBool;
    obj.kit_sealed_bool = kitSealedBool;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return InvKit();
    }
    return InvKit(obj);
}

InvKit InvKit::create(const QVariantMap &values)
{
    InvKit model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

InvKit InvKit::get(int invNoId)
{
    TSqlORMapper<InvKitObject> mapper;
    return InvKit(mapper.findByPrimaryKey(invNoId));
}

int InvKit::count()
{
    TSqlORMapper<InvKitObject> mapper;
    return mapper.findCount();
}

QList<InvKit> InvKit::getAll()
{
    return tfGetModelListByCriteria<InvKit, InvKitObject>();
}

TModelObject *InvKit::modelData()
{
    return d.data();
}

const TModelObject *InvKit::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const InvKit &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, InvKit &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(InvKit)
