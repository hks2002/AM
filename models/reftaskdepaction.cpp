#include <TreeFrogModel>
#include "reftaskdepaction.h"
#include "reftaskdepactionobject.h"

RefTaskDepAction::RefTaskDepAction()
    : TAbstractModel(), d(new RefTaskDepActionObject())
{ }

RefTaskDepAction::RefTaskDepAction(const RefTaskDepAction &other)
    : TAbstractModel(), d(new RefTaskDepActionObject(*other.d))
{ }

RefTaskDepAction::RefTaskDepAction(const RefTaskDepActionObject &object)
    : TAbstractModel(), d(new RefTaskDepActionObject(object))
{ }

RefTaskDepAction::~RefTaskDepAction()
{
    // If the reference count becomes 0,
    // the shared data object 'RefTaskDepActionObject' is deleted.
}

QString RefTaskDepAction::taskDepActionCd() const
{
    return d->task_dep_action_cd;
}

void RefTaskDepAction::setTaskDepActionCd(const QString &taskDepActionCd)
{
    d->task_dep_action_cd = taskDepActionCd;
}

QString RefTaskDepAction::taskDepActionNameEn() const
{
    return d->task_dep_action_name_en;
}

void RefTaskDepAction::setTaskDepActionNameEn(const QString &taskDepActionNameEn)
{
    d->task_dep_action_name_en = taskDepActionNameEn;
}

QString RefTaskDepAction::taskDepActionNameZh() const
{
    return d->task_dep_action_name_zh;
}

void RefTaskDepAction::setTaskDepActionNameZh(const QString &taskDepActionNameZh)
{
    d->task_dep_action_name_zh = taskDepActionNameZh;
}

QString RefTaskDepAction::taskDepActionDesc() const
{
    return d->task_dep_action_desc;
}

void RefTaskDepAction::setTaskDepActionDesc(const QString &taskDepActionDesc)
{
    d->task_dep_action_desc = taskDepActionDesc;
}

QDateTime RefTaskDepAction::createdAt() const
{
    return d->created_at;
}

QString RefTaskDepAction::createdBy() const
{
    return d->created_by;
}

void RefTaskDepAction::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime RefTaskDepAction::updatedAt() const
{
    return d->updated_at;
}

QString RefTaskDepAction::updatedBy() const
{
    return d->updated_by;
}

void RefTaskDepAction::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

RefTaskDepAction &RefTaskDepAction::operator=(const RefTaskDepAction &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

RefTaskDepAction RefTaskDepAction::create(const QString &taskDepActionCd, const QString &taskDepActionNameEn, const QString &taskDepActionNameZh, const QString &taskDepActionDesc, const QString &createdBy, const QString &updatedBy)
{
    RefTaskDepActionObject obj;
    obj.task_dep_action_cd = taskDepActionCd;
    obj.task_dep_action_name_en = taskDepActionNameEn;
    obj.task_dep_action_name_zh = taskDepActionNameZh;
    obj.task_dep_action_desc = taskDepActionDesc;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return RefTaskDepAction();
    }
    return RefTaskDepAction(obj);
}

RefTaskDepAction RefTaskDepAction::create(const QVariantMap &values)
{
    RefTaskDepAction model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

RefTaskDepAction RefTaskDepAction::get(const QString &taskDepActionCd)
{
    TSqlORMapper<RefTaskDepActionObject> mapper;
    return RefTaskDepAction(mapper.findByPrimaryKey(taskDepActionCd));
}

int RefTaskDepAction::count()
{
    TSqlORMapper<RefTaskDepActionObject> mapper;
    return mapper.findCount();
}

QList<RefTaskDepAction> RefTaskDepAction::getAll()
{
    return tfGetModelListByCriteria<RefTaskDepAction, RefTaskDepActionObject>();
}

TModelObject *RefTaskDepAction::modelData()
{
    return d.data();
}

const TModelObject *RefTaskDepAction::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const RefTaskDepAction &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, RefTaskDepAction &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(RefTaskDepAction)
