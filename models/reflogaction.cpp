#include <TreeFrogModel>
#include "reflogaction.h"
#include "reflogactionobject.h"

RefLogAction::RefLogAction()
    : TAbstractModel(), d(new RefLogActionObject())
{ }

RefLogAction::RefLogAction(const RefLogAction &other)
    : TAbstractModel(), d(new RefLogActionObject(*other.d))
{ }

RefLogAction::RefLogAction(const RefLogActionObject &object)
    : TAbstractModel(), d(new RefLogActionObject(object))
{ }

RefLogAction::~RefLogAction()
{
    // If the reference count becomes 0,
    // the shared data object 'RefLogActionObject' is deleted.
}

QString RefLogAction::logActionCd() const
{
    return d->log_action_cd;
}

void RefLogAction::setLogActionCd(const QString &logActionCd)
{
    d->log_action_cd = logActionCd;
}

QString RefLogAction::logActionNameEn() const
{
    return d->log_action_name_en;
}

void RefLogAction::setLogActionNameEn(const QString &logActionNameEn)
{
    d->log_action_name_en = logActionNameEn;
}

QString RefLogAction::logActionNameZh() const
{
    return d->log_action_name_zh;
}

void RefLogAction::setLogActionNameZh(const QString &logActionNameZh)
{
    d->log_action_name_zh = logActionNameZh;
}

QString RefLogAction::logActionDesc() const
{
    return d->log_action_desc;
}

void RefLogAction::setLogActionDesc(const QString &logActionDesc)
{
    d->log_action_desc = logActionDesc;
}

QDateTime RefLogAction::createdAt() const
{
    return d->created_at;
}

QString RefLogAction::createdBy() const
{
    return d->created_by;
}

void RefLogAction::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime RefLogAction::updatedAt() const
{
    return d->updated_at;
}

QString RefLogAction::updatedBy() const
{
    return d->updated_by;
}

void RefLogAction::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

RefLogAction &RefLogAction::operator=(const RefLogAction &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

RefLogAction RefLogAction::create(const QString &logActionCd, const QString &logActionNameEn, const QString &logActionNameZh, const QString &logActionDesc, const QString &createdBy, const QString &updatedBy)
{
    RefLogActionObject obj;
    obj.log_action_cd = logActionCd;
    obj.log_action_name_en = logActionNameEn;
    obj.log_action_name_zh = logActionNameZh;
    obj.log_action_desc = logActionDesc;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return RefLogAction();
    }
    return RefLogAction(obj);
}

RefLogAction RefLogAction::create(const QVariantMap &values)
{
    RefLogAction model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

RefLogAction RefLogAction::get(const QString &logActionCd)
{
    TSqlORMapper<RefLogActionObject> mapper;
    return RefLogAction(mapper.findByPrimaryKey(logActionCd));
}

int RefLogAction::count()
{
    TSqlORMapper<RefLogActionObject> mapper;
    return mapper.findCount();
}

QList<RefLogAction> RefLogAction::getAll()
{
    return tfGetModelListByCriteria<RefLogAction, RefLogActionObject>();
}

TModelObject *RefLogAction::modelData()
{
    return d.data();
}

const TModelObject *RefLogAction::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const RefLogAction &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, RefLogAction &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(RefLogAction)
