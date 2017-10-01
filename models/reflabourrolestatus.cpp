#include <TreeFrogModel>
#include "reflabourrolestatus.h"
#include "reflabourrolestatusobject.h"

RefLabourRoleStatus::RefLabourRoleStatus()
    : TAbstractModel(), d(new RefLabourRoleStatusObject())
{ }

RefLabourRoleStatus::RefLabourRoleStatus(const RefLabourRoleStatus &other)
    : TAbstractModel(), d(new RefLabourRoleStatusObject(*other.d))
{ }

RefLabourRoleStatus::RefLabourRoleStatus(const RefLabourRoleStatusObject &object)
    : TAbstractModel(), d(new RefLabourRoleStatusObject(object))
{ }

RefLabourRoleStatus::~RefLabourRoleStatus()
{
    // If the reference count becomes 0,
    // the shared data object 'RefLabourRoleStatusObject' is deleted.
}

QString RefLabourRoleStatus::labourRoleStatusCd() const
{
    return d->labour_role_status_cd;
}

void RefLabourRoleStatus::setLabourRoleStatusCd(const QString &labourRoleStatusCd)
{
    d->labour_role_status_cd = labourRoleStatusCd;
}

QString RefLabourRoleStatus::labourRoleStatusNameEn() const
{
    return d->labour_role_status_name_en;
}

void RefLabourRoleStatus::setLabourRoleStatusNameEn(const QString &labourRoleStatusNameEn)
{
    d->labour_role_status_name_en = labourRoleStatusNameEn;
}

QString RefLabourRoleStatus::labourRoleStatusNameZh() const
{
    return d->labour_role_status_name_zh;
}

void RefLabourRoleStatus::setLabourRoleStatusNameZh(const QString &labourRoleStatusNameZh)
{
    d->labour_role_status_name_zh = labourRoleStatusNameZh;
}

QString RefLabourRoleStatus::labourRoleStatusDesc() const
{
    return d->labour_role_status_desc;
}

void RefLabourRoleStatus::setLabourRoleStatusDesc(const QString &labourRoleStatusDesc)
{
    d->labour_role_status_desc = labourRoleStatusDesc;
}

QDateTime RefLabourRoleStatus::createdAt() const
{
    return d->created_at;
}

QString RefLabourRoleStatus::createdBy() const
{
    return d->created_by;
}

void RefLabourRoleStatus::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime RefLabourRoleStatus::updatedAt() const
{
    return d->updated_at;
}

QString RefLabourRoleStatus::updatedBy() const
{
    return d->updated_by;
}

void RefLabourRoleStatus::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

RefLabourRoleStatus &RefLabourRoleStatus::operator=(const RefLabourRoleStatus &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

RefLabourRoleStatus RefLabourRoleStatus::create(const QString &labourRoleStatusCd, const QString &labourRoleStatusNameEn, const QString &labourRoleStatusNameZh, const QString &labourRoleStatusDesc, const QString &createdBy, const QString &updatedBy)
{
    RefLabourRoleStatusObject obj;
    obj.labour_role_status_cd = labourRoleStatusCd;
    obj.labour_role_status_name_en = labourRoleStatusNameEn;
    obj.labour_role_status_name_zh = labourRoleStatusNameZh;
    obj.labour_role_status_desc = labourRoleStatusDesc;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return RefLabourRoleStatus();
    }
    return RefLabourRoleStatus(obj);
}

RefLabourRoleStatus RefLabourRoleStatus::create(const QVariantMap &values)
{
    RefLabourRoleStatus model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

RefLabourRoleStatus RefLabourRoleStatus::get(const QString &labourRoleStatusCd)
{
    TSqlORMapper<RefLabourRoleStatusObject> mapper;
    return RefLabourRoleStatus(mapper.findByPrimaryKey(labourRoleStatusCd));
}

int RefLabourRoleStatus::count()
{
    TSqlORMapper<RefLabourRoleStatusObject> mapper;
    return mapper.findCount();
}

QList<RefLabourRoleStatus> RefLabourRoleStatus::getAll()
{
    return tfGetModelListByCriteria<RefLabourRoleStatus, RefLabourRoleStatusObject>();
}

TModelObject *RefLabourRoleStatus::modelData()
{
    return d.data();
}

const TModelObject *RefLabourRoleStatus::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const RefLabourRoleStatus &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, RefLabourRoleStatus &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(RefLabourRoleStatus)
