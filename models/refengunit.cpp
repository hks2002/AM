#include <TreeFrogModel>
#include "refengunit.h"
#include "refengunitobject.h"

RefEngUnit::RefEngUnit()
    : TAbstractModel(), d(new RefEngUnitObject())
{ }

RefEngUnit::RefEngUnit(const RefEngUnit &other)
    : TAbstractModel(), d(new RefEngUnitObject(*other.d))
{ }

RefEngUnit::RefEngUnit(const RefEngUnitObject &object)
    : TAbstractModel(), d(new RefEngUnitObject(object))
{ }

RefEngUnit::~RefEngUnit()
{
    // If the reference count becomes 0,
    // the shared data object 'RefEngUnitObject' is deleted.
}

QString RefEngUnit::engUnitCd() const
{
    return d->eng_unit_cd;
}

void RefEngUnit::setEngUnitCd(const QString &engUnitCd)
{
    d->eng_unit_cd = engUnitCd;
}

QString RefEngUnit::engUnitNameEn() const
{
    return d->eng_unit_name_en;
}

void RefEngUnit::setEngUnitNameEn(const QString &engUnitNameEn)
{
    d->eng_unit_name_en = engUnitNameEn;
}

QString RefEngUnit::engUnitNameZh() const
{
    return d->eng_unit_name_zh;
}

void RefEngUnit::setEngUnitNameZh(const QString &engUnitNameZh)
{
    d->eng_unit_name_zh = engUnitNameZh;
}

QString RefEngUnit::engUnitDesc() const
{
    return d->eng_unit_desc;
}

void RefEngUnit::setEngUnitDesc(const QString &engUnitDesc)
{
    d->eng_unit_desc = engUnitDesc;
}

QDateTime RefEngUnit::createdAt() const
{
    return d->created_at;
}

QString RefEngUnit::createdBy() const
{
    return d->created_by;
}

void RefEngUnit::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime RefEngUnit::updatedAt() const
{
    return d->updated_at;
}

QString RefEngUnit::updatedBy() const
{
    return d->updated_by;
}

void RefEngUnit::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

RefEngUnit &RefEngUnit::operator=(const RefEngUnit &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

RefEngUnit RefEngUnit::create(const QString &engUnitCd, const QString &engUnitNameEn, const QString &engUnitNameZh, const QString &engUnitDesc, const QString &createdBy, const QString &updatedBy)
{
    RefEngUnitObject obj;
    obj.eng_unit_cd = engUnitCd;
    obj.eng_unit_name_en = engUnitNameEn;
    obj.eng_unit_name_zh = engUnitNameZh;
    obj.eng_unit_desc = engUnitDesc;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return RefEngUnit();
    }
    return RefEngUnit(obj);
}

RefEngUnit RefEngUnit::create(const QVariantMap &values)
{
    RefEngUnit model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

RefEngUnit RefEngUnit::get(const QString &engUnitCd)
{
    TSqlORMapper<RefEngUnitObject> mapper;
    return RefEngUnit(mapper.findByPrimaryKey(engUnitCd));
}

int RefEngUnit::count()
{
    TSqlORMapper<RefEngUnitObject> mapper;
    return mapper.findCount();
}

QList<RefEngUnit> RefEngUnit::getAll()
{
    return tfGetModelListByCriteria<RefEngUnit, RefEngUnitObject>();
}

TModelObject *RefEngUnit::modelData()
{
    return d.data();
}

const TModelObject *RefEngUnit::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const RefEngUnit &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, RefEngUnit &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(RefEngUnit)
