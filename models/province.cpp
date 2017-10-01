#include <TreeFrogModel>
#include "province.h"
#include "provinceobject.h"

Province::Province()
    : TAbstractModel(), d(new ProvinceObject())
{
    d->province_id = 0;
}

Province::Province(const Province &other)
    : TAbstractModel(), d(new ProvinceObject(*other.d))
{ }

Province::Province(const ProvinceObject &object)
    : TAbstractModel(), d(new ProvinceObject(object))
{ }

Province::~Province()
{
    // If the reference count becomes 0,
    // the shared data object 'ProvinceObject' is deleted.
}

int Province::provinceId() const
{
    return d->province_id;
}

QString Province::provinceNameZh() const
{
    return d->province_name_zh;
}

void Province::setProvinceNameZh(const QString &provinceNameZh)
{
    d->province_name_zh = provinceNameZh;
}

QString Province::provinceNameEn() const
{
    return d->province_name_en;
}

void Province::setProvinceNameEn(const QString &provinceNameEn)
{
    d->province_name_en = provinceNameEn;
}

QString Province::provinceDesc() const
{
    return d->province_desc;
}

void Province::setProvinceDesc(const QString &provinceDesc)
{
    d->province_desc = provinceDesc;
}

QDateTime Province::createdAt() const
{
    return d->created_at;
}

QString Province::createdBy() const
{
    return d->created_by;
}

void Province::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime Province::updatedAt() const
{
    return d->updated_at;
}

QString Province::updatedBy() const
{
    return d->updated_by;
}

void Province::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

Province &Province::operator=(const Province &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

Province Province::create(const QString &provinceNameZh, const QString &provinceNameEn, const QString &provinceDesc, const QString &createdBy, const QString &updatedBy)
{
    ProvinceObject obj;
    obj.province_name_zh = provinceNameZh;
    obj.province_name_en = provinceNameEn;
    obj.province_desc = provinceDesc;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return Province();
    }
    return Province(obj);
}

Province Province::create(const QVariantMap &values)
{
    Province model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

Province Province::get(int provinceId)
{
    TSqlORMapper<ProvinceObject> mapper;
    return Province(mapper.findByPrimaryKey(provinceId));
}

int Province::count()
{
    TSqlORMapper<ProvinceObject> mapper;
    return mapper.findCount();
}

QList<Province> Province::getAll()
{
    return tfGetModelListByCriteria<Province, ProvinceObject>();
}

TModelObject *Province::modelData()
{
    return d.data();
}

const TModelObject *Province::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const Province &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, Province &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(Province)
