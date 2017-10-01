#include <TreeFrogModel>
#include "reftaskclass.h"
#include "reftaskclassobject.h"

RefTaskClass::RefTaskClass()
    : TAbstractModel(), d(new RefTaskClassObject())
{ }

RefTaskClass::RefTaskClass(const RefTaskClass &other)
    : TAbstractModel(), d(new RefTaskClassObject(*other.d))
{ }

RefTaskClass::RefTaskClass(const RefTaskClassObject &object)
    : TAbstractModel(), d(new RefTaskClassObject(object))
{ }

RefTaskClass::~RefTaskClass()
{
    // If the reference count becomes 0,
    // the shared data object 'RefTaskClassObject' is deleted.
}

QString RefTaskClass::taskClassCd() const
{
    return d->task_class_cd;
}

void RefTaskClass::setTaskClassCd(const QString &taskClassCd)
{
    d->task_class_cd = taskClassCd;
}

QString RefTaskClass::taskClassNameEn() const
{
    return d->task_class_name_en;
}

void RefTaskClass::setTaskClassNameEn(const QString &taskClassNameEn)
{
    d->task_class_name_en = taskClassNameEn;
}

QString RefTaskClass::taskClassNameZh() const
{
    return d->task_class_name_zh;
}

void RefTaskClass::setTaskClassNameZh(const QString &taskClassNameZh)
{
    d->task_class_name_zh = taskClassNameZh;
}

QString RefTaskClass::taskClassDesc() const
{
    return d->task_class_desc;
}

void RefTaskClass::setTaskClassDesc(const QString &taskClassDesc)
{
    d->task_class_desc = taskClassDesc;
}

QDateTime RefTaskClass::createdAt() const
{
    return d->created_at;
}

QString RefTaskClass::createdBy() const
{
    return d->created_by;
}

void RefTaskClass::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime RefTaskClass::updatedAt() const
{
    return d->updated_at;
}

QString RefTaskClass::updatedBy() const
{
    return d->updated_by;
}

void RefTaskClass::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

RefTaskClass &RefTaskClass::operator=(const RefTaskClass &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

RefTaskClass RefTaskClass::create(const QString &taskClassCd, const QString &taskClassNameEn, const QString &taskClassNameZh, const QString &taskClassDesc, const QString &createdBy, const QString &updatedBy)
{
    RefTaskClassObject obj;
    obj.task_class_cd = taskClassCd;
    obj.task_class_name_en = taskClassNameEn;
    obj.task_class_name_zh = taskClassNameZh;
    obj.task_class_desc = taskClassDesc;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return RefTaskClass();
    }
    return RefTaskClass(obj);
}

RefTaskClass RefTaskClass::create(const QVariantMap &values)
{
    RefTaskClass model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

RefTaskClass RefTaskClass::get(const QString &taskClassCd)
{
    TSqlORMapper<RefTaskClassObject> mapper;
    return RefTaskClass(mapper.findByPrimaryKey(taskClassCd));
}

int RefTaskClass::count()
{
    TSqlORMapper<RefTaskClassObject> mapper;
    return mapper.findCount();
}

QList<RefTaskClass> RefTaskClass::getAll()
{
    return tfGetModelListByCriteria<RefTaskClass, RefTaskClassObject>();
}

TModelObject *RefTaskClass::modelData()
{
    return d.data();
}

const TModelObject *RefTaskClass::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const RefTaskClass &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, RefTaskClass &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(RefTaskClass)
