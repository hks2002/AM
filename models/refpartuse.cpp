#include <TreeFrogModel>
#include "refpartuse.h"
#include "refpartuseobject.h"

RefPartUse::RefPartUse()
    : TAbstractModel(), d(new RefPartUseObject())
{ }

RefPartUse::RefPartUse(const RefPartUse &other)
    : TAbstractModel(), d(new RefPartUseObject(*other.d))
{ }

RefPartUse::RefPartUse(const RefPartUseObject &object)
    : TAbstractModel(), d(new RefPartUseObject(object))
{ }

RefPartUse::~RefPartUse()
{
    // If the reference count becomes 0,
    // the shared data object 'RefPartUseObject' is deleted.
}

QString RefPartUse::partUseCd() const
{
    return d->part_use_cd;
}

void RefPartUse::setPartUseCd(const QString &partUseCd)
{
    d->part_use_cd = partUseCd;
}

QString RefPartUse::partUseNameEn() const
{
    return d->part_use_name_en;
}

void RefPartUse::setPartUseNameEn(const QString &partUseNameEn)
{
    d->part_use_name_en = partUseNameEn;
}

QString RefPartUse::partUseNameZh() const
{
    return d->part_use_name_zh;
}

void RefPartUse::setPartUseNameZh(const QString &partUseNameZh)
{
    d->part_use_name_zh = partUseNameZh;
}

QString RefPartUse::partUseDesc() const
{
    return d->part_use_desc;
}

void RefPartUse::setPartUseDesc(const QString &partUseDesc)
{
    d->part_use_desc = partUseDesc;
}

QDateTime RefPartUse::createdAt() const
{
    return d->created_at;
}

QString RefPartUse::createdBy() const
{
    return d->created_by;
}

void RefPartUse::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime RefPartUse::updatedAt() const
{
    return d->updated_at;
}

QString RefPartUse::updatedBy() const
{
    return d->updated_by;
}

void RefPartUse::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

RefPartUse &RefPartUse::operator=(const RefPartUse &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

RefPartUse RefPartUse::create(const QString &partUseCd, const QString &partUseNameEn, const QString &partUseNameZh, const QString &partUseDesc, const QString &createdBy, const QString &updatedBy)
{
    RefPartUseObject obj;
    obj.part_use_cd = partUseCd;
    obj.part_use_name_en = partUseNameEn;
    obj.part_use_name_zh = partUseNameZh;
    obj.part_use_desc = partUseDesc;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return RefPartUse();
    }
    return RefPartUse(obj);
}

RefPartUse RefPartUse::create(const QVariantMap &values)
{
    RefPartUse model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

RefPartUse RefPartUse::get(const QString &partUseCd)
{
    TSqlORMapper<RefPartUseObject> mapper;
    return RefPartUse(mapper.findByPrimaryKey(partUseCd));
}

int RefPartUse::count()
{
    TSqlORMapper<RefPartUseObject> mapper;
    return mapper.findCount();
}

QList<RefPartUse> RefPartUse::getAll()
{
    return tfGetModelListByCriteria<RefPartUse, RefPartUseObject>();
}

TModelObject *RefPartUse::modelData()
{
    return d.data();
}

const TModelObject *RefPartUse::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const RefPartUse &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, RefPartUse &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(RefPartUse)
