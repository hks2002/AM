#include <TreeFrogModel>
#include "orgsuborg.h"
#include "orgsuborgobject.h"
#include "org.h"

OrgSuborg::OrgSuborg()
    : TAbstractModel(), d(new OrgSuborgObject())
{
    d->org_id = 0;
    d->sub_org_id = 0;
}

OrgSuborg::OrgSuborg(const OrgSuborg &other)
    : TAbstractModel(), d(new OrgSuborgObject(*other.d))
{ }

OrgSuborg::OrgSuborg(const OrgSuborgObject &object)
    : TAbstractModel(), d(new OrgSuborgObject(object))
{ }

OrgSuborg::~OrgSuborg()
{
    // If the reference count becomes 0,
    // the shared data object 'OrgSuborgObject' is deleted.
}

int OrgSuborg::orgId() const
{
    return d->org_id;
}

void OrgSuborg::setOrgId(int orgId)
{
    d->org_id = orgId;
}

int OrgSuborg::subOrgId() const
{
    return d->sub_org_id;
}

void OrgSuborg::setSubOrgId(int subOrgId)
{
    d->sub_org_id = subOrgId;
}

QDateTime OrgSuborg::createdAt() const
{
    return d->created_at;
}

QString OrgSuborg::createdBy() const
{
    return d->created_by;
}

void OrgSuborg::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime OrgSuborg::updatedAt() const
{
    return d->updated_at;
}

QString OrgSuborg::updatedBy() const
{
    return d->updated_by;
}

void OrgSuborg::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

Org OrgSuborg::orgBysubOrgId() const
{
 return Org::get(d->sub_org_id);
}

OrgSuborg &OrgSuborg::operator=(const OrgSuborg &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

OrgSuborg OrgSuborg::create(int orgId, int subOrgId, const QString &createdBy, const QString &updatedBy)
{
    OrgSuborgObject obj;
    obj.org_id = orgId;
    obj.sub_org_id = subOrgId;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return OrgSuborg();
    }
    return OrgSuborg(obj);
}

OrgSuborg OrgSuborg::create(const QVariantMap &values)
{
    OrgSuborg model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

OrgSuborg OrgSuborg::get(int orgId, int subOrgId)
{
    TSqlORMapper<OrgSuborgObject> mapper;
    return OrgSuborg(mapper.findByPrimaryKey(QVariantList()<<QVariant(orgId)<<QVariant(subOrgId)));
}

int OrgSuborg::count()
{
    TSqlORMapper<OrgSuborgObject> mapper;
    return mapper.findCount();
}

QList<OrgSuborg> OrgSuborg::getAll()
{
    return tfGetModelListByCriteria<OrgSuborg, OrgSuborgObject>();
}

TModelObject *OrgSuborg::modelData()
{
    return d.data();
}

const TModelObject *OrgSuborg::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const OrgSuborg &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, OrgSuborg &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(OrgSuborg)
