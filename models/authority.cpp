#include <TreeFrogModel>
#include "authority.h"
#include "authorityobject.h"

Authority::Authority()
    : TAbstractModel(), d(new AuthorityObject())
{
    d->authority_id = 0;
}

Authority::Authority(const Authority &other)
    : TAbstractModel(), d(new AuthorityObject(*other.d))
{ }

Authority::Authority(const AuthorityObject &object)
    : TAbstractModel(), d(new AuthorityObject(object))
{ }

Authority::~Authority()
{
    // If the reference count becomes 0,
    // the shared data object 'AuthorityObject' is deleted.
}

int Authority::authorityId() const
{
    return d->authority_id;
}

QString Authority::authorityCd() const
{
    return d->authority_cd;
}

void Authority::setAuthorityCd(const QString &authorityCd)
{
    d->authority_cd = authorityCd;
}

QString Authority::authorityName() const
{
    return d->authority_name;
}

void Authority::setAuthorityName(const QString &authorityName)
{
    d->authority_name = authorityName;
}

QString Authority::authorityDesc() const
{
    return d->authority_desc;
}

void Authority::setAuthorityDesc(const QString &authorityDesc)
{
    d->authority_desc = authorityDesc;
}

QDateTime Authority::createdAt() const
{
    return d->created_at;
}

QString Authority::createdBy() const
{
    return d->created_by;
}

void Authority::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime Authority::updatedAt() const
{
    return d->updated_at;
}

QString Authority::updatedBy() const
{
    return d->updated_by;
}

void Authority::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

Authority &Authority::operator=(const Authority &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

Authority Authority::create(const QString &authorityCd, const QString &authorityName, const QString &authorityDesc, const QString &createdBy, const QString &updatedBy)
{
    AuthorityObject obj;
    obj.authority_cd = authorityCd;
    obj.authority_name = authorityName;
    obj.authority_desc = authorityDesc;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return Authority();
    }
    return Authority(obj);
}

Authority Authority::create(const QVariantMap &values)
{
    Authority model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

Authority Authority::get(int authorityId)
{
    TSqlORMapper<AuthorityObject> mapper;
    return Authority(mapper.findByPrimaryKey(authorityId));
}

int Authority::count()
{
    TSqlORMapper<AuthorityObject> mapper;
    return mapper.findCount();
}

QList<Authority> Authority::getAll()
{
    return tfGetModelListByCriteria<Authority, AuthorityObject>();
}

TModelObject *Authority::modelData()
{
    return d.data();
}

const TModelObject *Authority::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const Authority &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, Authority &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(Authority)
