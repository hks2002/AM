#include <TreeFrogModel>
#include "refwarrantyevalstatus.h"
#include "refwarrantyevalstatusobject.h"

RefWarrantyEvalStatus::RefWarrantyEvalStatus()
    : TAbstractModel(), d(new RefWarrantyEvalStatusObject())
{ }

RefWarrantyEvalStatus::RefWarrantyEvalStatus(const RefWarrantyEvalStatus &other)
    : TAbstractModel(), d(new RefWarrantyEvalStatusObject(*other.d))
{ }

RefWarrantyEvalStatus::RefWarrantyEvalStatus(const RefWarrantyEvalStatusObject &object)
    : TAbstractModel(), d(new RefWarrantyEvalStatusObject(object))
{ }

RefWarrantyEvalStatus::~RefWarrantyEvalStatus()
{
    // If the reference count becomes 0,
    // the shared data object 'RefWarrantyEvalStatusObject' is deleted.
}

QString RefWarrantyEvalStatus::warrantyEvalStatusCd() const
{
    return d->warranty_eval_status_cd;
}

void RefWarrantyEvalStatus::setWarrantyEvalStatusCd(const QString &warrantyEvalStatusCd)
{
    d->warranty_eval_status_cd = warrantyEvalStatusCd;
}

QString RefWarrantyEvalStatus::warrantyEvalStatusNameEn() const
{
    return d->warranty_eval_status_name_en;
}

void RefWarrantyEvalStatus::setWarrantyEvalStatusNameEn(const QString &warrantyEvalStatusNameEn)
{
    d->warranty_eval_status_name_en = warrantyEvalStatusNameEn;
}

QString RefWarrantyEvalStatus::warrantyEvalStatusNameZh() const
{
    return d->warranty_eval_status_name_zh;
}

void RefWarrantyEvalStatus::setWarrantyEvalStatusNameZh(const QString &warrantyEvalStatusNameZh)
{
    d->warranty_eval_status_name_zh = warrantyEvalStatusNameZh;
}

QString RefWarrantyEvalStatus::warrantyEvalStatusDesc() const
{
    return d->warranty_eval_status_desc;
}

void RefWarrantyEvalStatus::setWarrantyEvalStatusDesc(const QString &warrantyEvalStatusDesc)
{
    d->warranty_eval_status_desc = warrantyEvalStatusDesc;
}

QDateTime RefWarrantyEvalStatus::createdAt() const
{
    return d->created_at;
}

QString RefWarrantyEvalStatus::createdBy() const
{
    return d->created_by;
}

void RefWarrantyEvalStatus::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime RefWarrantyEvalStatus::updatedAt() const
{
    return d->updated_at;
}

QString RefWarrantyEvalStatus::updatedBy() const
{
    return d->updated_by;
}

void RefWarrantyEvalStatus::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

RefWarrantyEvalStatus &RefWarrantyEvalStatus::operator=(const RefWarrantyEvalStatus &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

RefWarrantyEvalStatus RefWarrantyEvalStatus::create(const QString &warrantyEvalStatusCd, const QString &warrantyEvalStatusNameEn, const QString &warrantyEvalStatusNameZh, const QString &warrantyEvalStatusDesc, const QString &createdBy, const QString &updatedBy)
{
    RefWarrantyEvalStatusObject obj;
    obj.warranty_eval_status_cd = warrantyEvalStatusCd;
    obj.warranty_eval_status_name_en = warrantyEvalStatusNameEn;
    obj.warranty_eval_status_name_zh = warrantyEvalStatusNameZh;
    obj.warranty_eval_status_desc = warrantyEvalStatusDesc;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return RefWarrantyEvalStatus();
    }
    return RefWarrantyEvalStatus(obj);
}

RefWarrantyEvalStatus RefWarrantyEvalStatus::create(const QVariantMap &values)
{
    RefWarrantyEvalStatus model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

RefWarrantyEvalStatus RefWarrantyEvalStatus::get(const QString &warrantyEvalStatusCd)
{
    TSqlORMapper<RefWarrantyEvalStatusObject> mapper;
    return RefWarrantyEvalStatus(mapper.findByPrimaryKey(warrantyEvalStatusCd));
}

int RefWarrantyEvalStatus::count()
{
    TSqlORMapper<RefWarrantyEvalStatusObject> mapper;
    return mapper.findCount();
}

QList<RefWarrantyEvalStatus> RefWarrantyEvalStatus::getAll()
{
    return tfGetModelListByCriteria<RefWarrantyEvalStatus, RefWarrantyEvalStatusObject>();
}

TModelObject *RefWarrantyEvalStatus::modelData()
{
    return d.data();
}

const TModelObject *RefWarrantyEvalStatus::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const RefWarrantyEvalStatus &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, RefWarrantyEvalStatus &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(RefWarrantyEvalStatus)
