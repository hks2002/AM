#include <TreeFrogModel>
#include "refreqaction.h"
#include "refreqactionobject.h"

RefReqAction::RefReqAction()
    : TAbstractModel(), d(new RefReqActionObject())
{ }

RefReqAction::RefReqAction(const RefReqAction &other)
    : TAbstractModel(), d(new RefReqActionObject(*other.d))
{ }

RefReqAction::RefReqAction(const RefReqActionObject &object)
    : TAbstractModel(), d(new RefReqActionObject(object))
{ }

RefReqAction::~RefReqAction()
{
    // If the reference count becomes 0,
    // the shared data object 'RefReqActionObject' is deleted.
}

QString RefReqAction::reqActionCd() const
{
    return d->req_action_cd;
}

void RefReqAction::setReqActionCd(const QString &reqActionCd)
{
    d->req_action_cd = reqActionCd;
}

QString RefReqAction::reqActionNameEn() const
{
    return d->req_action_name_en;
}

void RefReqAction::setReqActionNameEn(const QString &reqActionNameEn)
{
    d->req_action_name_en = reqActionNameEn;
}

QString RefReqAction::reqActionNameZh() const
{
    return d->req_action_name_zh;
}

void RefReqAction::setReqActionNameZh(const QString &reqActionNameZh)
{
    d->req_action_name_zh = reqActionNameZh;
}

QString RefReqAction::reqActionDesc() const
{
    return d->req_action_desc;
}

void RefReqAction::setReqActionDesc(const QString &reqActionDesc)
{
    d->req_action_desc = reqActionDesc;
}

QDateTime RefReqAction::createdAt() const
{
    return d->created_at;
}

QString RefReqAction::createdBy() const
{
    return d->created_by;
}

void RefReqAction::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime RefReqAction::updatedAt() const
{
    return d->updated_at;
}

QString RefReqAction::updatedBy() const
{
    return d->updated_by;
}

void RefReqAction::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

RefReqAction &RefReqAction::operator=(const RefReqAction &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

RefReqAction RefReqAction::create(const QString &reqActionCd, const QString &reqActionNameEn, const QString &reqActionNameZh, const QString &reqActionDesc, const QString &createdBy, const QString &updatedBy)
{
    RefReqActionObject obj;
    obj.req_action_cd = reqActionCd;
    obj.req_action_name_en = reqActionNameEn;
    obj.req_action_name_zh = reqActionNameZh;
    obj.req_action_desc = reqActionDesc;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return RefReqAction();
    }
    return RefReqAction(obj);
}

RefReqAction RefReqAction::create(const QVariantMap &values)
{
    RefReqAction model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

RefReqAction RefReqAction::get(const QString &reqActionCd)
{
    TSqlORMapper<RefReqActionObject> mapper;
    return RefReqAction(mapper.findByPrimaryKey(reqActionCd));
}

int RefReqAction::count()
{
    TSqlORMapper<RefReqActionObject> mapper;
    return mapper.findCount();
}

QList<RefReqAction> RefReqAction::getAll()
{
    return tfGetModelListByCriteria<RefReqAction, RefReqActionObject>();
}

TModelObject *RefReqAction::modelData()
{
    return d.data();
}

const TModelObject *RefReqAction::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const RefReqAction &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, RefReqAction &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(RefReqAction)
