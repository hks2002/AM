#include <TreeFrogModel>
#include "rfqheader.h"
#include "rfqheaderobject.h"
#include "userapp.h"

RfqHeader::RfqHeader()
    : TAbstractModel(), d(new RfqHeaderObject())
{
    d->rfq_id = 0;
    d->contact_to = 0;
}

RfqHeader::RfqHeader(const RfqHeader &other)
    : TAbstractModel(), d(new RfqHeaderObject(*other.d))
{ }

RfqHeader::RfqHeader(const RfqHeaderObject &object)
    : TAbstractModel(), d(new RfqHeaderObject(object))
{ }

RfqHeader::~RfqHeader()
{
    // If the reference count becomes 0,
    // the shared data object 'RfqHeaderObject' is deleted.
}

int RfqHeader::rfqId() const
{
    return d->rfq_id;
}

QString RfqHeader::rfqCd() const
{
    return d->rfq_cd;
}

void RfqHeader::setRfqCd(const QString &rfqCd)
{
    d->rfq_cd = rfqCd;
}

int RfqHeader::contactTo() const
{
    return d->contact_to;
}

void RfqHeader::setContactTo(int contactTo)
{
    d->contact_to = contactTo;
}

QDateTime RfqHeader::rfqIssuedDt() const
{
    return d->rfq_issued_dt;
}

void RfqHeader::setRfqIssuedDt(const QDateTime &rfqIssuedDt)
{
    d->rfq_issued_dt = rfqIssuedDt;
}

QDateTime RfqHeader::createdAt() const
{
    return d->created_at;
}

QString RfqHeader::createdBy() const
{
    return d->created_by;
}

void RfqHeader::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime RfqHeader::updatedAt() const
{
    return d->updated_at;
}

QString RfqHeader::updatedBy() const
{
    return d->updated_by;
}

void RfqHeader::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

UserApp RfqHeader::userAppBycontactTo() const
{
 return UserApp::get(d->contact_to);
}

RfqHeader &RfqHeader::operator=(const RfqHeader &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

RfqHeader RfqHeader::create(const QString &rfqCd, int contactTo, const QDateTime &rfqIssuedDt, const QString &createdBy, const QString &updatedBy)
{
    RfqHeaderObject obj;
    obj.rfq_cd = rfqCd;
    obj.contact_to = contactTo;
    obj.rfq_issued_dt = rfqIssuedDt;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return RfqHeader();
    }
    return RfqHeader(obj);
}

RfqHeader RfqHeader::create(const QVariantMap &values)
{
    RfqHeader model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

RfqHeader RfqHeader::get(int rfqId)
{
    TSqlORMapper<RfqHeaderObject> mapper;
    return RfqHeader(mapper.findByPrimaryKey(rfqId));
}

int RfqHeader::count()
{
    TSqlORMapper<RfqHeaderObject> mapper;
    return mapper.findCount();
}

QList<RfqHeader> RfqHeader::getAll()
{
    return tfGetModelListByCriteria<RfqHeader, RfqHeaderObject>();
}

TModelObject *RfqHeader::modelData()
{
    return d.data();
}

const TModelObject *RfqHeader::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const RfqHeader &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, RfqHeader &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(RfqHeader)
