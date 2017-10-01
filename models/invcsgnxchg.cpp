#include <TreeFrogModel>
#include "invcsgnxchg.h"
#include "invcsgnxchgobject.h"
#include "invinv.h"
#include "poheader.h"

InvCsgnXchg::InvCsgnXchg()
    : TAbstractModel(), d(new InvCsgnXchgObject())
{
    d->inv_csgn_xchg_id = 0;
    d->po_id = 0;
    d->inv_no_id = 0;
    d->rtrn_inv_no_id = 0;
}

InvCsgnXchg::InvCsgnXchg(const InvCsgnXchg &other)
    : TAbstractModel(), d(new InvCsgnXchgObject(*other.d))
{ }

InvCsgnXchg::InvCsgnXchg(const InvCsgnXchgObject &object)
    : TAbstractModel(), d(new InvCsgnXchgObject(object))
{ }

InvCsgnXchg::~InvCsgnXchg()
{
    // If the reference count becomes 0,
    // the shared data object 'InvCsgnXchgObject' is deleted.
}

int InvCsgnXchg::invCsgnXchgId() const
{
    return d->inv_csgn_xchg_id;
}

int InvCsgnXchg::poId() const
{
    return d->po_id;
}

void InvCsgnXchg::setPoId(int poId)
{
    d->po_id = poId;
}

int InvCsgnXchg::invNoId() const
{
    return d->inv_no_id;
}

void InvCsgnXchg::setInvNoId(int invNoId)
{
    d->inv_no_id = invNoId;
}

int InvCsgnXchg::rtrnInvNoId() const
{
    return d->rtrn_inv_no_id;
}

void InvCsgnXchg::setRtrnInvNoId(int rtrnInvNoId)
{
    d->rtrn_inv_no_id = rtrnInvNoId;
}

QDateTime InvCsgnXchg::createdAt() const
{
    return d->created_at;
}

QString InvCsgnXchg::createdBy() const
{
    return d->created_by;
}

void InvCsgnXchg::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime InvCsgnXchg::updatedAt() const
{
    return d->updated_at;
}

QString InvCsgnXchg::updatedBy() const
{
    return d->updated_by;
}

void InvCsgnXchg::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

InvInv InvCsgnXchg::invInvByrtrnInvNoId() const
{
 return InvInv::get(d->rtrn_inv_no_id);
}

PoHeader InvCsgnXchg::poHeaderBypoId() const
{
 return PoHeader::get(d->po_id);
}

InvCsgnXchg &InvCsgnXchg::operator=(const InvCsgnXchg &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

InvCsgnXchg InvCsgnXchg::create(int poId, int invNoId, int rtrnInvNoId, const QString &createdBy, const QString &updatedBy)
{
    InvCsgnXchgObject obj;
    obj.po_id = poId;
    obj.inv_no_id = invNoId;
    obj.rtrn_inv_no_id = rtrnInvNoId;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return InvCsgnXchg();
    }
    return InvCsgnXchg(obj);
}

InvCsgnXchg InvCsgnXchg::create(const QVariantMap &values)
{
    InvCsgnXchg model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

InvCsgnXchg InvCsgnXchg::get(int invCsgnXchgId)
{
    TSqlORMapper<InvCsgnXchgObject> mapper;
    return InvCsgnXchg(mapper.findByPrimaryKey(invCsgnXchgId));
}

int InvCsgnXchg::count()
{
    TSqlORMapper<InvCsgnXchgObject> mapper;
    return mapper.findCount();
}

QList<InvCsgnXchg> InvCsgnXchg::getAll()
{
    return tfGetModelListByCriteria<InvCsgnXchg, InvCsgnXchgObject>();
}

TModelObject *InvCsgnXchg::modelData()
{
    return d.data();
}

const TModelObject *InvCsgnXchg::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const InvCsgnXchg &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, InvCsgnXchg &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(InvCsgnXchg)
