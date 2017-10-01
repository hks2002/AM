#include <TreeFrogModel>
#include "refmaintprgmstatus.h"
#include "refmaintprgmstatusobject.h"

RefMaintPrgmStatus::RefMaintPrgmStatus()
    : TAbstractModel(), d(new RefMaintPrgmStatusObject())
{ }

RefMaintPrgmStatus::RefMaintPrgmStatus(const RefMaintPrgmStatus &other)
    : TAbstractModel(), d(new RefMaintPrgmStatusObject(*other.d))
{ }

RefMaintPrgmStatus::RefMaintPrgmStatus(const RefMaintPrgmStatusObject &object)
    : TAbstractModel(), d(new RefMaintPrgmStatusObject(object))
{ }

RefMaintPrgmStatus::~RefMaintPrgmStatus()
{
    // If the reference count becomes 0,
    // the shared data object 'RefMaintPrgmStatusObject' is deleted.
}

QString RefMaintPrgmStatus::maintPrgmStatusCd() const
{
    return d->maint_prgm_status_cd;
}

void RefMaintPrgmStatus::setMaintPrgmStatusCd(const QString &maintPrgmStatusCd)
{
    d->maint_prgm_status_cd = maintPrgmStatusCd;
}

QString RefMaintPrgmStatus::maintPrgmStatusNameEn() const
{
    return d->maint_prgm_status_name_en;
}

void RefMaintPrgmStatus::setMaintPrgmStatusNameEn(const QString &maintPrgmStatusNameEn)
{
    d->maint_prgm_status_name_en = maintPrgmStatusNameEn;
}

QString RefMaintPrgmStatus::maintPrgmStatusNameZh() const
{
    return d->maint_prgm_status_name_zh;
}

void RefMaintPrgmStatus::setMaintPrgmStatusNameZh(const QString &maintPrgmStatusNameZh)
{
    d->maint_prgm_status_name_zh = maintPrgmStatusNameZh;
}

QString RefMaintPrgmStatus::maintPrgmStatusDesc() const
{
    return d->maint_prgm_status_desc;
}

void RefMaintPrgmStatus::setMaintPrgmStatusDesc(const QString &maintPrgmStatusDesc)
{
    d->maint_prgm_status_desc = maintPrgmStatusDesc;
}

QDateTime RefMaintPrgmStatus::createdAt() const
{
    return d->created_at;
}

QString RefMaintPrgmStatus::createdBy() const
{
    return d->created_by;
}

void RefMaintPrgmStatus::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime RefMaintPrgmStatus::updatedAt() const
{
    return d->updated_at;
}

QString RefMaintPrgmStatus::updatedBy() const
{
    return d->updated_by;
}

void RefMaintPrgmStatus::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

RefMaintPrgmStatus &RefMaintPrgmStatus::operator=(const RefMaintPrgmStatus &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

RefMaintPrgmStatus RefMaintPrgmStatus::create(const QString &maintPrgmStatusCd, const QString &maintPrgmStatusNameEn, const QString &maintPrgmStatusNameZh, const QString &maintPrgmStatusDesc, const QString &createdBy, const QString &updatedBy)
{
    RefMaintPrgmStatusObject obj;
    obj.maint_prgm_status_cd = maintPrgmStatusCd;
    obj.maint_prgm_status_name_en = maintPrgmStatusNameEn;
    obj.maint_prgm_status_name_zh = maintPrgmStatusNameZh;
    obj.maint_prgm_status_desc = maintPrgmStatusDesc;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return RefMaintPrgmStatus();
    }
    return RefMaintPrgmStatus(obj);
}

RefMaintPrgmStatus RefMaintPrgmStatus::create(const QVariantMap &values)
{
    RefMaintPrgmStatus model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

RefMaintPrgmStatus RefMaintPrgmStatus::get(const QString &maintPrgmStatusCd)
{
    TSqlORMapper<RefMaintPrgmStatusObject> mapper;
    return RefMaintPrgmStatus(mapper.findByPrimaryKey(maintPrgmStatusCd));
}

int RefMaintPrgmStatus::count()
{
    TSqlORMapper<RefMaintPrgmStatusObject> mapper;
    return mapper.findCount();
}

QList<RefMaintPrgmStatus> RefMaintPrgmStatus::getAll()
{
    return tfGetModelListByCriteria<RefMaintPrgmStatus, RefMaintPrgmStatusObject>();
}

TModelObject *RefMaintPrgmStatus::modelData()
{
    return d.data();
}

const TModelObject *RefMaintPrgmStatus::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const RefMaintPrgmStatus &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, RefMaintPrgmStatus &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(RefMaintPrgmStatus)
