#include <TreeFrogModel>
#include "maintprgmcarriermap.h"
#include "maintprgmcarriermapobject.h"
#include "carrier.h"
#include "maintprgm.h"

MaintPrgmCarrierMap::MaintPrgmCarrierMap()
    : TAbstractModel(), d(new MaintPrgmCarrierMapObject())
{
    d->maint_prgm_id = 0;
    d->carrier_id = 0;
    d->carrier_revision_ord = 0;
}

MaintPrgmCarrierMap::MaintPrgmCarrierMap(const MaintPrgmCarrierMap &other)
    : TAbstractModel(), d(new MaintPrgmCarrierMapObject(*other.d))
{ }

MaintPrgmCarrierMap::MaintPrgmCarrierMap(const MaintPrgmCarrierMapObject &object)
    : TAbstractModel(), d(new MaintPrgmCarrierMapObject(object))
{ }

MaintPrgmCarrierMap::~MaintPrgmCarrierMap()
{
    // If the reference count becomes 0,
    // the shared data object 'MaintPrgmCarrierMapObject' is deleted.
}

int MaintPrgmCarrierMap::maintPrgmId() const
{
    return d->maint_prgm_id;
}

void MaintPrgmCarrierMap::setMaintPrgmId(int maintPrgmId)
{
    d->maint_prgm_id = maintPrgmId;
}

int MaintPrgmCarrierMap::carrierId() const
{
    return d->carrier_id;
}

void MaintPrgmCarrierMap::setCarrierId(int carrierId)
{
    d->carrier_id = carrierId;
}

int MaintPrgmCarrierMap::carrierRevisionOrd() const
{
    return d->carrier_revision_ord;
}

void MaintPrgmCarrierMap::setCarrierRevisionOrd(int carrierRevisionOrd)
{
    d->carrier_revision_ord = carrierRevisionOrd;
}

bool MaintPrgmCarrierMap::latestRevisionBool() const
{
    return d->latest_revision_bool;
}

void MaintPrgmCarrierMap::setLatestRevisionBool(bool latestRevisionBool)
{
    d->latest_revision_bool = latestRevisionBool;
}

QDateTime MaintPrgmCarrierMap::createdAt() const
{
    return d->created_at;
}

QString MaintPrgmCarrierMap::createdBy() const
{
    return d->created_by;
}

void MaintPrgmCarrierMap::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime MaintPrgmCarrierMap::updatedAt() const
{
    return d->updated_at;
}

QString MaintPrgmCarrierMap::updatedBy() const
{
    return d->updated_by;
}

void MaintPrgmCarrierMap::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

Carrier MaintPrgmCarrierMap::carrierBycarrierId() const
{
 return Carrier::get(d->carrier_id);
}

MaintPrgm MaintPrgmCarrierMap::maintPrgmBymaintPrgmId() const
{
 return MaintPrgm::get(d->maint_prgm_id);
}

MaintPrgmCarrierMap &MaintPrgmCarrierMap::operator=(const MaintPrgmCarrierMap &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

MaintPrgmCarrierMap MaintPrgmCarrierMap::create(int maintPrgmId, int carrierId, int carrierRevisionOrd, bool latestRevisionBool, const QString &createdBy, const QString &updatedBy)
{
    MaintPrgmCarrierMapObject obj;
    obj.maint_prgm_id = maintPrgmId;
    obj.carrier_id = carrierId;
    obj.carrier_revision_ord = carrierRevisionOrd;
    obj.latest_revision_bool = latestRevisionBool;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return MaintPrgmCarrierMap();
    }
    return MaintPrgmCarrierMap(obj);
}

MaintPrgmCarrierMap MaintPrgmCarrierMap::create(const QVariantMap &values)
{
    MaintPrgmCarrierMap model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

MaintPrgmCarrierMap MaintPrgmCarrierMap::get(int maintPrgmId, int carrierId)
{
    TSqlORMapper<MaintPrgmCarrierMapObject> mapper;
    return MaintPrgmCarrierMap(mapper.findByPrimaryKey(QVariantList()<<QVariant(maintPrgmId)<<QVariant(carrierId)));
}

int MaintPrgmCarrierMap::count()
{
    TSqlORMapper<MaintPrgmCarrierMapObject> mapper;
    return mapper.findCount();
}

QList<MaintPrgmCarrierMap> MaintPrgmCarrierMap::getAll()
{
    return tfGetModelListByCriteria<MaintPrgmCarrierMap, MaintPrgmCarrierMapObject>();
}

TModelObject *MaintPrgmCarrierMap::modelData()
{
    return d.data();
}

const TModelObject *MaintPrgmCarrierMap::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const MaintPrgmCarrierMap &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, MaintPrgmCarrierMap &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(MaintPrgmCarrierMap)
