#include <TreeFrogModel>
#include "maintprgm.h"
#include "maintprgmobject.h"
#include "userapp.h"
#include "refmaintprgmstatus.h"
#include "maintprgmdefn.h"

MaintPrgm::MaintPrgm()
    : TAbstractModel(), d(new MaintPrgmObject())
{
    d->maint_prgm_id = 0;
    d->maint_prgm_defn_id = 0;
    d->revision_ord = 0;
    d->carrier_revision_ord = 0;
    d->actived_by = 0;
    d->locked_by = 0;
}

MaintPrgm::MaintPrgm(const MaintPrgm &other)
    : TAbstractModel(), d(new MaintPrgmObject(*other.d))
{ }

MaintPrgm::MaintPrgm(const MaintPrgmObject &object)
    : TAbstractModel(), d(new MaintPrgmObject(object))
{ }

MaintPrgm::~MaintPrgm()
{
    // If the reference count becomes 0,
    // the shared data object 'MaintPrgmObject' is deleted.
}

int MaintPrgm::maintPrgmId() const
{
    return d->maint_prgm_id;
}

int MaintPrgm::maintPrgmDefnId() const
{
    return d->maint_prgm_defn_id;
}

void MaintPrgm::setMaintPrgmDefnId(int maintPrgmDefnId)
{
    d->maint_prgm_defn_id = maintPrgmDefnId;
}

QString MaintPrgm::maintPrgmCd() const
{
    return d->maint_prgm_cd;
}

void MaintPrgm::setMaintPrgmCd(const QString &maintPrgmCd)
{
    d->maint_prgm_cd = maintPrgmCd;
}

QString MaintPrgm::maintPrgmDesc() const
{
    return d->maint_prgm_desc;
}

void MaintPrgm::setMaintPrgmDesc(const QString &maintPrgmDesc)
{
    d->maint_prgm_desc = maintPrgmDesc;
}

QString MaintPrgm::maintPrgmStatusCd() const
{
    return d->maint_prgm_status_cd;
}

void MaintPrgm::setMaintPrgmStatusCd(const QString &maintPrgmStatusCd)
{
    d->maint_prgm_status_cd = maintPrgmStatusCd;
}

int MaintPrgm::revisionOrd() const
{
    return d->revision_ord;
}

void MaintPrgm::setRevisionOrd(int revisionOrd)
{
    d->revision_ord = revisionOrd;
}

int MaintPrgm::carrierRevisionOrd() const
{
    return d->carrier_revision_ord;
}

void MaintPrgm::setCarrierRevisionOrd(int carrierRevisionOrd)
{
    d->carrier_revision_ord = carrierRevisionOrd;
}

int MaintPrgm::activedBy() const
{
    return d->actived_by;
}

void MaintPrgm::setActivedBy(int activedBy)
{
    d->actived_by = activedBy;
}

QDateTime MaintPrgm::activedDt() const
{
    return d->actived_dt;
}

void MaintPrgm::setActivedDt(const QDateTime &activedDt)
{
    d->actived_dt = activedDt;
}

QString MaintPrgm::activeDesc() const
{
    return d->active_desc;
}

void MaintPrgm::setActiveDesc(const QString &activeDesc)
{
    d->active_desc = activeDesc;
}

bool MaintPrgm::lockedBool() const
{
    return d->locked_bool;
}

void MaintPrgm::setLockedBool(bool lockedBool)
{
    d->locked_bool = lockedBool;
}

QDateTime MaintPrgm::lockedDt() const
{
    return d->locked_dt;
}

void MaintPrgm::setLockedDt(const QDateTime &lockedDt)
{
    d->locked_dt = lockedDt;
}

int MaintPrgm::lockedBy() const
{
    return d->locked_by;
}

void MaintPrgm::setLockedBy(int lockedBy)
{
    d->locked_by = lockedBy;
}

QDateTime MaintPrgm::createdAt() const
{
    return d->created_at;
}

QString MaintPrgm::createdBy() const
{
    return d->created_by;
}

void MaintPrgm::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime MaintPrgm::updatedAt() const
{
    return d->updated_at;
}

QString MaintPrgm::updatedBy() const
{
    return d->updated_by;
}

void MaintPrgm::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

UserApp MaintPrgm::userAppBylockedBy() const
{
 return UserApp::get(d->locked_by);
}

RefMaintPrgmStatus MaintPrgm::refMaintPrgmStatusBymaintPrgmStatusCd() const
{
 return RefMaintPrgmStatus::get(d->maint_prgm_status_cd);
}

MaintPrgmDefn MaintPrgm::maintPrgmDefnBymaintPrgmDefnId() const
{
 return MaintPrgmDefn::get(d->maint_prgm_defn_id);
}

MaintPrgm &MaintPrgm::operator=(const MaintPrgm &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

MaintPrgm MaintPrgm::create(int maintPrgmDefnId, const QString &maintPrgmCd, const QString &maintPrgmDesc, const QString &maintPrgmStatusCd, int revisionOrd, int carrierRevisionOrd, int activedBy, const QDateTime &activedDt, const QString &activeDesc, bool lockedBool, const QDateTime &lockedDt, int lockedBy, const QString &createdBy, const QString &updatedBy)
{
    MaintPrgmObject obj;
    obj.maint_prgm_defn_id = maintPrgmDefnId;
    obj.maint_prgm_cd = maintPrgmCd;
    obj.maint_prgm_desc = maintPrgmDesc;
    obj.maint_prgm_status_cd = maintPrgmStatusCd;
    obj.revision_ord = revisionOrd;
    obj.carrier_revision_ord = carrierRevisionOrd;
    obj.actived_by = activedBy;
    obj.actived_dt = activedDt;
    obj.active_desc = activeDesc;
    obj.locked_bool = lockedBool;
    obj.locked_dt = lockedDt;
    obj.locked_by = lockedBy;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return MaintPrgm();
    }
    return MaintPrgm(obj);
}

MaintPrgm MaintPrgm::create(const QVariantMap &values)
{
    MaintPrgm model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

MaintPrgm MaintPrgm::get(int maintPrgmId)
{
    TSqlORMapper<MaintPrgmObject> mapper;
    return MaintPrgm(mapper.findByPrimaryKey(maintPrgmId));
}

int MaintPrgm::count()
{
    TSqlORMapper<MaintPrgmObject> mapper;
    return mapper.findCount();
}

QList<MaintPrgm> MaintPrgm::getAll()
{
    return tfGetModelListByCriteria<MaintPrgm, MaintPrgmObject>();
}

TModelObject *MaintPrgm::modelData()
{
    return d.data();
}

const TModelObject *MaintPrgm::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const MaintPrgm &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, MaintPrgm &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(MaintPrgm)
