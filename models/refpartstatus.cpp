#include <TreeFrogModel>
#include "refpartstatus.h"
#include "refpartstatusobject.h"

RefPartStatus::RefPartStatus()
    : TAbstractModel(), d(new RefPartStatusObject())
{ }

RefPartStatus::RefPartStatus(const RefPartStatus &other)
    : TAbstractModel(), d(new RefPartStatusObject(*other.d))
{ }

RefPartStatus::RefPartStatus(const RefPartStatusObject &object)
    : TAbstractModel(), d(new RefPartStatusObject(object))
{ }

RefPartStatus::~RefPartStatus()
{
    // If the reference count becomes 0,
    // the shared data object 'RefPartStatusObject' is deleted.
}

QString RefPartStatus::partStatusCd() const
{
    return d->part_status_cd;
}

void RefPartStatus::setPartStatusCd(const QString &partStatusCd)
{
    d->part_status_cd = partStatusCd;
}

QString RefPartStatus::partStatusNameEn() const
{
    return d->part_status_name_en;
}

void RefPartStatus::setPartStatusNameEn(const QString &partStatusNameEn)
{
    d->part_status_name_en = partStatusNameEn;
}

QString RefPartStatus::partStatusNameZh() const
{
    return d->part_status_name_zh;
}

void RefPartStatus::setPartStatusNameZh(const QString &partStatusNameZh)
{
    d->part_status_name_zh = partStatusNameZh;
}

QString RefPartStatus::partStatusDesc() const
{
    return d->part_status_desc;
}

void RefPartStatus::setPartStatusDesc(const QString &partStatusDesc)
{
    d->part_status_desc = partStatusDesc;
}

QDateTime RefPartStatus::createdAt() const
{
    return d->created_at;
}

QString RefPartStatus::createdBy() const
{
    return d->created_by;
}

void RefPartStatus::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime RefPartStatus::updatedAt() const
{
    return d->updated_at;
}

QString RefPartStatus::updatedBy() const
{
    return d->updated_by;
}

void RefPartStatus::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

RefPartStatus &RefPartStatus::operator=(const RefPartStatus &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

RefPartStatus RefPartStatus::create(const QString &partStatusCd, const QString &partStatusNameEn, const QString &partStatusNameZh, const QString &partStatusDesc, const QString &createdBy, const QString &updatedBy)
{
    RefPartStatusObject obj;
    obj.part_status_cd = partStatusCd;
    obj.part_status_name_en = partStatusNameEn;
    obj.part_status_name_zh = partStatusNameZh;
    obj.part_status_desc = partStatusDesc;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return RefPartStatus();
    }
    return RefPartStatus(obj);
}

RefPartStatus RefPartStatus::create(const QVariantMap &values)
{
    RefPartStatus model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

RefPartStatus RefPartStatus::get(const QString &partStatusCd)
{
    TSqlORMapper<RefPartStatusObject> mapper;
    return RefPartStatus(mapper.findByPrimaryKey(partStatusCd));
}

int RefPartStatus::count()
{
    TSqlORMapper<RefPartStatusObject> mapper;
    return mapper.findCount();
}

QList<RefPartStatus> RefPartStatus::getAll()
{
    return tfGetModelListByCriteria<RefPartStatus, RefPartStatusObject>();
}

TModelObject *RefPartStatus::modelData()
{
    return d.data();
}

const TModelObject *RefPartStatus::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const RefPartStatus &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, RefPartStatus &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(RefPartStatus)
