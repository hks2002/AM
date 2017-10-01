#include <TreeFrogModel>
#include "orgcode.h"
#include "orgcodeobject.h"
#include "org.h"

OrgCode::OrgCode()
    : TAbstractModel(), d(new OrgCodeObject())
{
    d->org_id = 0;
}

OrgCode::OrgCode(const OrgCode &other)
    : TAbstractModel(), d(new OrgCodeObject(*other.d))
{ }

OrgCode::OrgCode(const OrgCodeObject &object)
    : TAbstractModel(), d(new OrgCodeObject(object))
{ }

OrgCode::~OrgCode()
{
    // If the reference count becomes 0,
    // the shared data object 'OrgCodeObject' is deleted.
}

int OrgCode::orgId() const
{
    return d->org_id;
}

void OrgCode::setOrgId(int orgId)
{
    d->org_id = orgId;
}

QString OrgCode::icaoCd() const
{
    return d->icao_cd;
}

void OrgCode::setIcaoCd(const QString &icaoCd)
{
    d->icao_cd = icaoCd;
}

QString OrgCode::iataCd() const
{
    return d->iata_cd;
}

void OrgCode::setIataCd(const QString &iataCd)
{
    d->iata_cd = iataCd;
}

QString OrgCode::callsignCd() const
{
    return d->callsign_cd;
}

void OrgCode::setCallsignCd(const QString &callsignCd)
{
    d->callsign_cd = callsignCd;
}

QDateTime OrgCode::createdAt() const
{
    return d->created_at;
}

QString OrgCode::createdBy() const
{
    return d->created_by;
}

void OrgCode::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime OrgCode::updatedAt() const
{
    return d->updated_at;
}

QString OrgCode::updatedBy() const
{
    return d->updated_by;
}

void OrgCode::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

Org OrgCode::orgByorgId() const
{
 return Org::get(d->org_id);
}

OrgCode &OrgCode::operator=(const OrgCode &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

OrgCode OrgCode::create(int orgId, const QString &icaoCd, const QString &iataCd, const QString &callsignCd, const QString &createdBy, const QString &updatedBy)
{
    OrgCodeObject obj;
    obj.org_id = orgId;
    obj.icao_cd = icaoCd;
    obj.iata_cd = iataCd;
    obj.callsign_cd = callsignCd;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return OrgCode();
    }
    return OrgCode(obj);
}

OrgCode OrgCode::create(const QVariantMap &values)
{
    OrgCode model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

OrgCode OrgCode::get(int orgId)
{
    TSqlORMapper<OrgCodeObject> mapper;
    return OrgCode(mapper.findByPrimaryKey(orgId));
}

int OrgCode::count()
{
    TSqlORMapper<OrgCodeObject> mapper;
    return mapper.findCount();
}

QList<OrgCode> OrgCode::getAll()
{
    return tfGetModelListByCriteria<OrgCode, OrgCodeObject>();
}

TModelObject *OrgCode::modelData()
{
    return d.data();
}

const TModelObject *OrgCode::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const OrgCode &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, OrgCode &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(OrgCode)
