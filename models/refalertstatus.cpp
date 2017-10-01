#include <TreeFrogModel>
#include "refalertstatus.h"
#include "refalertstatusobject.h"

RefAlertStatus::RefAlertStatus()
    : TAbstractModel(), d(new RefAlertStatusObject())
{ }

RefAlertStatus::RefAlertStatus(const RefAlertStatus &other)
    : TAbstractModel(), d(new RefAlertStatusObject(*other.d))
{ }

RefAlertStatus::RefAlertStatus(const RefAlertStatusObject &object)
    : TAbstractModel(), d(new RefAlertStatusObject(object))
{ }

RefAlertStatus::~RefAlertStatus()
{
    // If the reference count becomes 0,
    // the shared data object 'RefAlertStatusObject' is deleted.
}

QString RefAlertStatus::alertStatusCd() const
{
    return d->alert_status_cd;
}

void RefAlertStatus::setAlertStatusCd(const QString &alertStatusCd)
{
    d->alert_status_cd = alertStatusCd;
}

QString RefAlertStatus::alertStatusNameEn() const
{
    return d->alert_status_name_en;
}

void RefAlertStatus::setAlertStatusNameEn(const QString &alertStatusNameEn)
{
    d->alert_status_name_en = alertStatusNameEn;
}

QString RefAlertStatus::alertStatusNameZh() const
{
    return d->alert_status_name_zh;
}

void RefAlertStatus::setAlertStatusNameZh(const QString &alertStatusNameZh)
{
    d->alert_status_name_zh = alertStatusNameZh;
}

QString RefAlertStatus::alertStatusDesc() const
{
    return d->alert_status_desc;
}

void RefAlertStatus::setAlertStatusDesc(const QString &alertStatusDesc)
{
    d->alert_status_desc = alertStatusDesc;
}

QDateTime RefAlertStatus::createdAt() const
{
    return d->created_at;
}

QString RefAlertStatus::createdBy() const
{
    return d->created_by;
}

void RefAlertStatus::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime RefAlertStatus::updatedAt() const
{
    return d->updated_at;
}

QString RefAlertStatus::updatedBy() const
{
    return d->updated_by;
}

void RefAlertStatus::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

RefAlertStatus &RefAlertStatus::operator=(const RefAlertStatus &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

RefAlertStatus RefAlertStatus::create(const QString &alertStatusCd, const QString &alertStatusNameEn, const QString &alertStatusNameZh, const QString &alertStatusDesc, const QString &createdBy, const QString &updatedBy)
{
    RefAlertStatusObject obj;
    obj.alert_status_cd = alertStatusCd;
    obj.alert_status_name_en = alertStatusNameEn;
    obj.alert_status_name_zh = alertStatusNameZh;
    obj.alert_status_desc = alertStatusDesc;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return RefAlertStatus();
    }
    return RefAlertStatus(obj);
}

RefAlertStatus RefAlertStatus::create(const QVariantMap &values)
{
    RefAlertStatus model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

RefAlertStatus RefAlertStatus::get(const QString &alertStatusCd)
{
    TSqlORMapper<RefAlertStatusObject> mapper;
    return RefAlertStatus(mapper.findByPrimaryKey(alertStatusCd));
}

int RefAlertStatus::count()
{
    TSqlORMapper<RefAlertStatusObject> mapper;
    return mapper.findCount();
}

QList<RefAlertStatus> RefAlertStatus::getAll()
{
    return tfGetModelListByCriteria<RefAlertStatus, RefAlertStatusObject>();
}

TModelObject *RefAlertStatus::modelData()
{
    return d.data();
}

const TModelObject *RefAlertStatus::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const RefAlertStatus &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, RefAlertStatus &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(RefAlertStatus)
