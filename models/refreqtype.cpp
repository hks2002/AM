#include <TreeFrogModel>
#include "refreqtype.h"
#include "refreqtypeobject.h"

RefReqType::RefReqType()
    : TAbstractModel(), d(new RefReqTypeObject())
{ }

RefReqType::RefReqType(const RefReqType &other)
    : TAbstractModel(), d(new RefReqTypeObject(*other.d))
{ }

RefReqType::RefReqType(const RefReqTypeObject &object)
    : TAbstractModel(), d(new RefReqTypeObject(object))
{ }

RefReqType::~RefReqType()
{
    // If the reference count becomes 0,
    // the shared data object 'RefReqTypeObject' is deleted.
}

QString RefReqType::reqTypeCd() const
{
    return d->req_type_cd;
}

void RefReqType::setReqTypeCd(const QString &reqTypeCd)
{
    d->req_type_cd = reqTypeCd;
}

QString RefReqType::reqTypeNameEn() const
{
    return d->req_type_name_en;
}

void RefReqType::setReqTypeNameEn(const QString &reqTypeNameEn)
{
    d->req_type_name_en = reqTypeNameEn;
}

QString RefReqType::reqTypeNameZh() const
{
    return d->req_type_name_zh;
}

void RefReqType::setReqTypeNameZh(const QString &reqTypeNameZh)
{
    d->req_type_name_zh = reqTypeNameZh;
}

QString RefReqType::reqTypeDesc() const
{
    return d->req_type_desc;
}

void RefReqType::setReqTypeDesc(const QString &reqTypeDesc)
{
    d->req_type_desc = reqTypeDesc;
}

QDateTime RefReqType::createdAt() const
{
    return d->created_at;
}

QString RefReqType::createdBy() const
{
    return d->created_by;
}

void RefReqType::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime RefReqType::updatedAt() const
{
    return d->updated_at;
}

QString RefReqType::updatedBy() const
{
    return d->updated_by;
}

void RefReqType::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

RefReqType &RefReqType::operator=(const RefReqType &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

RefReqType RefReqType::create(const QString &reqTypeCd, const QString &reqTypeNameEn, const QString &reqTypeNameZh, const QString &reqTypeDesc, const QString &createdBy, const QString &updatedBy)
{
    RefReqTypeObject obj;
    obj.req_type_cd = reqTypeCd;
    obj.req_type_name_en = reqTypeNameEn;
    obj.req_type_name_zh = reqTypeNameZh;
    obj.req_type_desc = reqTypeDesc;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return RefReqType();
    }
    return RefReqType(obj);
}

RefReqType RefReqType::create(const QVariantMap &values)
{
    RefReqType model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

RefReqType RefReqType::get(const QString &reqTypeCd)
{
    TSqlORMapper<RefReqTypeObject> mapper;
    return RefReqType(mapper.findByPrimaryKey(reqTypeCd));
}

int RefReqType::count()
{
    TSqlORMapper<RefReqTypeObject> mapper;
    return mapper.findCount();
}

QList<RefReqType> RefReqType::getAll()
{
    return tfGetModelListByCriteria<RefReqType, RefReqTypeObject>();
}

TModelObject *RefReqType::modelData()
{
    return d.data();
}

const TModelObject *RefReqType::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const RefReqType &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, RefReqType &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(RefReqType)
