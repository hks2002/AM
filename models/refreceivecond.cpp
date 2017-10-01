#include <TreeFrogModel>
#include "refreceivecond.h"
#include "refreceivecondobject.h"

RefReceiveCond::RefReceiveCond()
    : TAbstractModel(), d(new RefReceiveCondObject())
{ }

RefReceiveCond::RefReceiveCond(const RefReceiveCond &other)
    : TAbstractModel(), d(new RefReceiveCondObject(*other.d))
{ }

RefReceiveCond::RefReceiveCond(const RefReceiveCondObject &object)
    : TAbstractModel(), d(new RefReceiveCondObject(object))
{ }

RefReceiveCond::~RefReceiveCond()
{
    // If the reference count becomes 0,
    // the shared data object 'RefReceiveCondObject' is deleted.
}

QString RefReceiveCond::receiveCondCd() const
{
    return d->receive_cond_cd;
}

void RefReceiveCond::setReceiveCondCd(const QString &receiveCondCd)
{
    d->receive_cond_cd = receiveCondCd;
}

QString RefReceiveCond::receiveCondNameEn() const
{
    return d->receive_cond_name_en;
}

void RefReceiveCond::setReceiveCondNameEn(const QString &receiveCondNameEn)
{
    d->receive_cond_name_en = receiveCondNameEn;
}

QString RefReceiveCond::receiveCondNameZh() const
{
    return d->receive_cond_name_zh;
}

void RefReceiveCond::setReceiveCondNameZh(const QString &receiveCondNameZh)
{
    d->receive_cond_name_zh = receiveCondNameZh;
}

QString RefReceiveCond::receiveCondDesc() const
{
    return d->receive_cond_desc;
}

void RefReceiveCond::setReceiveCondDesc(const QString &receiveCondDesc)
{
    d->receive_cond_desc = receiveCondDesc;
}

QDateTime RefReceiveCond::createdAt() const
{
    return d->created_at;
}

QString RefReceiveCond::createdBy() const
{
    return d->created_by;
}

void RefReceiveCond::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime RefReceiveCond::updatedAt() const
{
    return d->updated_at;
}

QString RefReceiveCond::updatedBy() const
{
    return d->updated_by;
}

void RefReceiveCond::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

RefReceiveCond &RefReceiveCond::operator=(const RefReceiveCond &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

RefReceiveCond RefReceiveCond::create(const QString &receiveCondCd, const QString &receiveCondNameEn, const QString &receiveCondNameZh, const QString &receiveCondDesc, const QString &createdBy, const QString &updatedBy)
{
    RefReceiveCondObject obj;
    obj.receive_cond_cd = receiveCondCd;
    obj.receive_cond_name_en = receiveCondNameEn;
    obj.receive_cond_name_zh = receiveCondNameZh;
    obj.receive_cond_desc = receiveCondDesc;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return RefReceiveCond();
    }
    return RefReceiveCond(obj);
}

RefReceiveCond RefReceiveCond::create(const QVariantMap &values)
{
    RefReceiveCond model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

RefReceiveCond RefReceiveCond::get(const QString &receiveCondCd)
{
    TSqlORMapper<RefReceiveCondObject> mapper;
    return RefReceiveCond(mapper.findByPrimaryKey(receiveCondCd));
}

int RefReceiveCond::count()
{
    TSqlORMapper<RefReceiveCondObject> mapper;
    return mapper.findCount();
}

QList<RefReceiveCond> RefReceiveCond::getAll()
{
    return tfGetModelListByCriteria<RefReceiveCond, RefReceiveCondObject>();
}

TModelObject *RefReceiveCond::modelData()
{
    return d.data();
}

const TModelObject *RefReceiveCond::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const RefReceiveCond &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, RefReceiveCond &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(RefReceiveCond)
