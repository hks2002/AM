#include <TreeFrogModel>
#include "refaccounttype.h"
#include "refaccounttypeobject.h"

RefAccountType::RefAccountType()
    : TAbstractModel(), d(new RefAccountTypeObject())
{ }

RefAccountType::RefAccountType(const RefAccountType &other)
    : TAbstractModel(), d(new RefAccountTypeObject(*other.d))
{ }

RefAccountType::RefAccountType(const RefAccountTypeObject &object)
    : TAbstractModel(), d(new RefAccountTypeObject(object))
{ }

RefAccountType::~RefAccountType()
{
    // If the reference count becomes 0,
    // the shared data object 'RefAccountTypeObject' is deleted.
}

QString RefAccountType::accountTypeCd() const
{
    return d->account_type_cd;
}

void RefAccountType::setAccountTypeCd(const QString &accountTypeCd)
{
    d->account_type_cd = accountTypeCd;
}

QString RefAccountType::accountTypeNameEn() const
{
    return d->account_type_name_en;
}

void RefAccountType::setAccountTypeNameEn(const QString &accountTypeNameEn)
{
    d->account_type_name_en = accountTypeNameEn;
}

QString RefAccountType::accountTypeNameZh() const
{
    return d->account_type_name_zh;
}

void RefAccountType::setAccountTypeNameZh(const QString &accountTypeNameZh)
{
    d->account_type_name_zh = accountTypeNameZh;
}

QString RefAccountType::accountTypeDesc() const
{
    return d->account_type_desc;
}

void RefAccountType::setAccountTypeDesc(const QString &accountTypeDesc)
{
    d->account_type_desc = accountTypeDesc;
}

QDateTime RefAccountType::createdAt() const
{
    return d->created_at;
}

QString RefAccountType::createdBy() const
{
    return d->created_by;
}

void RefAccountType::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime RefAccountType::updatedAt() const
{
    return d->updated_at;
}

QString RefAccountType::updatedBy() const
{
    return d->updated_by;
}

void RefAccountType::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

RefAccountType &RefAccountType::operator=(const RefAccountType &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

RefAccountType RefAccountType::create(const QString &accountTypeCd, const QString &accountTypeNameEn, const QString &accountTypeNameZh, const QString &accountTypeDesc, const QString &createdBy, const QString &updatedBy)
{
    RefAccountTypeObject obj;
    obj.account_type_cd = accountTypeCd;
    obj.account_type_name_en = accountTypeNameEn;
    obj.account_type_name_zh = accountTypeNameZh;
    obj.account_type_desc = accountTypeDesc;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return RefAccountType();
    }
    return RefAccountType(obj);
}

RefAccountType RefAccountType::create(const QVariantMap &values)
{
    RefAccountType model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

RefAccountType RefAccountType::get(const QString &accountTypeCd)
{
    TSqlORMapper<RefAccountTypeObject> mapper;
    return RefAccountType(mapper.findByPrimaryKey(accountTypeCd));
}

int RefAccountType::count()
{
    TSqlORMapper<RefAccountTypeObject> mapper;
    return mapper.findCount();
}

QList<RefAccountType> RefAccountType::getAll()
{
    return tfGetModelListByCriteria<RefAccountType, RefAccountTypeObject>();
}

TModelObject *RefAccountType::modelData()
{
    return d.data();
}

const TModelObject *RefAccountType::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const RefAccountType &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, RefAccountType &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(RefAccountType)
