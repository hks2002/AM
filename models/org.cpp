#include <TreeFrogModel>
#include "org.h"
#include "orgobject.h"

Org::Org()
    : TAbstractModel(), d(new OrgObject())
{
    d->org_id = 0;
}

Org::Org(const Org &other)
    : TAbstractModel(), d(new OrgObject(*other.d))
{ }

Org::Org(const OrgObject &object)
    : TAbstractModel(), d(new OrgObject(object))
{ }

Org::~Org()
{
    // If the reference count becomes 0,
    // the shared data object 'OrgObject' is deleted.
}

int Org::orgId() const
{
    return d->org_id;
}

QString Org::orgCd() const
{
    return d->org_cd;
}

void Org::setOrgCd(const QString &orgCd)
{
    d->org_cd = orgCd;
}

QString Org::orgNameZh() const
{
    return d->org_name_zh;
}

void Org::setOrgNameZh(const QString &orgNameZh)
{
    d->org_name_zh = orgNameZh;
}

QString Org::orgNameEn() const
{
    return d->org_name_en;
}

void Org::setOrgNameEn(const QString &orgNameEn)
{
    d->org_name_en = orgNameEn;
}

QString Org::logo() const
{
    return d->logo;
}

void Org::setLogo(const QString &logo)
{
    d->logo = logo;
}

QDateTime Org::createdAt() const
{
    return d->created_at;
}

QString Org::createdBy() const
{
    return d->created_by;
}

void Org::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime Org::updatedAt() const
{
    return d->updated_at;
}

QString Org::updatedBy() const
{
    return d->updated_by;
}

void Org::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

Org &Org::operator=(const Org &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

Org Org::create(const QString &orgCd, const QString &orgNameZh, const QString &orgNameEn, const QString &logo, const QString &createdBy, const QString &updatedBy)
{
    OrgObject obj;
    obj.org_cd = orgCd;
    obj.org_name_zh = orgNameZh;
    obj.org_name_en = orgNameEn;
    obj.logo = logo;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return Org();
    }
    return Org(obj);
}

Org Org::create(const QVariantMap &values)
{
    Org model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

Org Org::get(int orgId)
{
    TSqlORMapper<OrgObject> mapper;
    return Org(mapper.findByPrimaryKey(orgId));
}

int Org::count()
{
    TSqlORMapper<OrgObject> mapper;
    return mapper.findCount();
}

QList<Org> Org::getAll()
{
    return tfGetModelListByCriteria<Org, OrgObject>();
}

TModelObject *Org::modelData()
{
    return d.data();
}

const TModelObject *Org::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const Org &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, Org &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(Org)
