#include <TreeFrogModel>
#include "locinvrecount.h"
#include "locinvrecountobject.h"
#include "invinv.h"
#include "userapp.h"
#include "locpartcount.h"
#include "eqppartno.h"
#include "loc.h"

LocInvRecount::LocInvRecount()
    : TAbstractModel(), d(new LocInvRecountObject())
{
    d->inv_recount_id = 0;
    d->loc_id = 0;
    d->part_no_id = 0;
    d->loc_part_count_id = 0;
    d->user_id = 0;
    d->inv_no_id = 0;
    d->count_actual_qt = 0;
    d->count_expect_qt = 0;
}

LocInvRecount::LocInvRecount(const LocInvRecount &other)
    : TAbstractModel(), d(new LocInvRecountObject(*other.d))
{ }

LocInvRecount::LocInvRecount(const LocInvRecountObject &object)
    : TAbstractModel(), d(new LocInvRecountObject(object))
{ }

LocInvRecount::~LocInvRecount()
{
    // If the reference count becomes 0,
    // the shared data object 'LocInvRecountObject' is deleted.
}

int LocInvRecount::invRecountId() const
{
    return d->inv_recount_id;
}

int LocInvRecount::locId() const
{
    return d->loc_id;
}

void LocInvRecount::setLocId(int locId)
{
    d->loc_id = locId;
}

int LocInvRecount::partNoId() const
{
    return d->part_no_id;
}

void LocInvRecount::setPartNoId(int partNoId)
{
    d->part_no_id = partNoId;
}

int LocInvRecount::locPartCountId() const
{
    return d->loc_part_count_id;
}

void LocInvRecount::setLocPartCountId(int locPartCountId)
{
    d->loc_part_count_id = locPartCountId;
}

int LocInvRecount::userId() const
{
    return d->user_id;
}

void LocInvRecount::setUserId(int userId)
{
    d->user_id = userId;
}

int LocInvRecount::invNoId() const
{
    return d->inv_no_id;
}

void LocInvRecount::setInvNoId(int invNoId)
{
    d->inv_no_id = invNoId;
}

QString LocInvRecount::serialNoOem() const
{
    return d->serial_no_oem;
}

void LocInvRecount::setSerialNoOem(const QString &serialNoOem)
{
    d->serial_no_oem = serialNoOem;
}

int LocInvRecount::countActualQt() const
{
    return d->count_actual_qt;
}

void LocInvRecount::setCountActualQt(int countActualQt)
{
    d->count_actual_qt = countActualQt;
}

int LocInvRecount::countExpectQt() const
{
    return d->count_expect_qt;
}

void LocInvRecount::setCountExpectQt(int countExpectQt)
{
    d->count_expect_qt = countExpectQt;
}

QDateTime LocInvRecount::recountDt() const
{
    return d->recount_dt;
}

void LocInvRecount::setRecountDt(const QDateTime &recountDt)
{
    d->recount_dt = recountDt;
}

QDateTime LocInvRecount::createdAt() const
{
    return d->created_at;
}

QString LocInvRecount::createdBy() const
{
    return d->created_by;
}

void LocInvRecount::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime LocInvRecount::updatedAt() const
{
    return d->updated_at;
}

QString LocInvRecount::updatedBy() const
{
    return d->updated_by;
}

void LocInvRecount::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

InvInv LocInvRecount::invInvByinvNoId() const
{
 return InvInv::get(d->inv_no_id);
}

UserApp LocInvRecount::userAppByuserId() const
{
 return UserApp::get(d->user_id);
}

LocPartCount LocInvRecount::locPartCountBylocPartCountId() const
{
 return LocPartCount::get(d->loc_part_count_id);
}

EqpPartNo LocInvRecount::eqpPartNoBypartNoId() const
{
 return EqpPartNo::get(d->part_no_id);
}

Loc LocInvRecount::locBylocId() const
{
 return Loc::get(d->loc_id);
}

LocInvRecount &LocInvRecount::operator=(const LocInvRecount &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

LocInvRecount LocInvRecount::create(int locId, int partNoId, int locPartCountId, int userId, int invNoId, const QString &serialNoOem, int countActualQt, int countExpectQt, const QDateTime &recountDt, const QString &createdBy, const QString &updatedBy)
{
    LocInvRecountObject obj;
    obj.loc_id = locId;
    obj.part_no_id = partNoId;
    obj.loc_part_count_id = locPartCountId;
    obj.user_id = userId;
    obj.inv_no_id = invNoId;
    obj.serial_no_oem = serialNoOem;
    obj.count_actual_qt = countActualQt;
    obj.count_expect_qt = countExpectQt;
    obj.recount_dt = recountDt;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return LocInvRecount();
    }
    return LocInvRecount(obj);
}

LocInvRecount LocInvRecount::create(const QVariantMap &values)
{
    LocInvRecount model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

LocInvRecount LocInvRecount::get(int invRecountId)
{
    TSqlORMapper<LocInvRecountObject> mapper;
    return LocInvRecount(mapper.findByPrimaryKey(invRecountId));
}

int LocInvRecount::count()
{
    TSqlORMapper<LocInvRecountObject> mapper;
    return mapper.findCount();
}

QList<LocInvRecount> LocInvRecount::getAll()
{
    return tfGetModelListByCriteria<LocInvRecount, LocInvRecountObject>();
}

TModelObject *LocInvRecount::modelData()
{
    return d.data();
}

const TModelObject *LocInvRecount::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const LocInvRecount &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, LocInvRecount &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(LocInvRecount)
