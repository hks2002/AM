#include <TreeFrogModel>
#include "refwarrantystatus.h"
#include "refwarrantystatusobject.h"

RefWarrantyStatus::RefWarrantyStatus()
    : TAbstractModel(), d(new RefWarrantyStatusObject())
{ }

RefWarrantyStatus::RefWarrantyStatus(const RefWarrantyStatus &other)
    : TAbstractModel(), d(new RefWarrantyStatusObject(*other.d))
{ }

RefWarrantyStatus::RefWarrantyStatus(const RefWarrantyStatusObject &object)
    : TAbstractModel(), d(new RefWarrantyStatusObject(object))
{ }

RefWarrantyStatus::~RefWarrantyStatus()
{
    // If the reference count becomes 0,
    // the shared data object 'RefWarrantyStatusObject' is deleted.
}

QString RefWarrantyStatus::warrantyStatusCd() const
{
    return d->warranty_status_cd;
}

void RefWarrantyStatus::setWarrantyStatusCd(const QString &warrantyStatusCd)
{
    d->warranty_status_cd = warrantyStatusCd;
}

QString RefWarrantyStatus::warrantyStatusNameEn() const
{
    return d->warranty_status_name_en;
}

void RefWarrantyStatus::setWarrantyStatusNameEn(const QString &warrantyStatusNameEn)
{
    d->warranty_status_name_en = warrantyStatusNameEn;
}

QString RefWarrantyStatus::warrantyStatusNameZh() const
{
    return d->warranty_status_name_zh;
}

void RefWarrantyStatus::setWarrantyStatusNameZh(const QString &warrantyStatusNameZh)
{
    d->warranty_status_name_zh = warrantyStatusNameZh;
}

QString RefWarrantyStatus::warrantyStatusDesc() const
{
    return d->warranty_status_desc;
}

void RefWarrantyStatus::setWarrantyStatusDesc(const QString &warrantyStatusDesc)
{
    d->warranty_status_desc = warrantyStatusDesc;
}

QDateTime RefWarrantyStatus::createdAt() const
{
    return d->created_at;
}

QString RefWarrantyStatus::createdBy() const
{
    return d->created_by;
}

void RefWarrantyStatus::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime RefWarrantyStatus::updatedAt() const
{
    return d->updated_at;
}

QString RefWarrantyStatus::updatedBy() const
{
    return d->updated_by;
}

void RefWarrantyStatus::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

RefWarrantyStatus &RefWarrantyStatus::operator=(const RefWarrantyStatus &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

RefWarrantyStatus RefWarrantyStatus::create(const QString &warrantyStatusCd, const QString &warrantyStatusNameEn, const QString &warrantyStatusNameZh, const QString &warrantyStatusDesc, const QString &createdBy, const QString &updatedBy)
{
    RefWarrantyStatusObject obj;
    obj.warranty_status_cd = warrantyStatusCd;
    obj.warranty_status_name_en = warrantyStatusNameEn;
    obj.warranty_status_name_zh = warrantyStatusNameZh;
    obj.warranty_status_desc = warrantyStatusDesc;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return RefWarrantyStatus();
    }
    return RefWarrantyStatus(obj);
}

RefWarrantyStatus RefWarrantyStatus::create(const QVariantMap &values)
{
    RefWarrantyStatus model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

RefWarrantyStatus RefWarrantyStatus::get(const QString &warrantyStatusCd)
{
    TSqlORMapper<RefWarrantyStatusObject> mapper;
    return RefWarrantyStatus(mapper.findByPrimaryKey(warrantyStatusCd));
}

int RefWarrantyStatus::count()
{
    TSqlORMapper<RefWarrantyStatusObject> mapper;
    return mapper.findCount();
}

QList<RefWarrantyStatus> RefWarrantyStatus::getAll()
{
    return tfGetModelListByCriteria<RefWarrantyStatus, RefWarrantyStatusObject>();
}

TModelObject *RefWarrantyStatus::modelData()
{
    return d.data();
}

const TModelObject *RefWarrantyStatus::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const RefWarrantyStatus &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, RefWarrantyStatus &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(RefWarrantyStatus)
