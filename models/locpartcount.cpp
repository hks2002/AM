#include <TreeFrogModel>
#include "locpartcount.h"
#include "locpartcountobject.h"
#include "userapp.h"
#include "eqppartno.h"
#include "loc.h"

LocPartCount::LocPartCount()
    : TAbstractModel(), d(new LocPartCountObject())
{
    d->loc_part_count_id = 0;
    d->loc_id = 0;
    d->part_no_id = 0;
    d->user_id = 0;
    d->count_actual_qt = 0;
    d->count_expect_qt = 0;
}

LocPartCount::LocPartCount(const LocPartCount &other)
    : TAbstractModel(), d(new LocPartCountObject(*other.d))
{ }

LocPartCount::LocPartCount(const LocPartCountObject &object)
    : TAbstractModel(), d(new LocPartCountObject(object))
{ }

LocPartCount::~LocPartCount()
{
    // If the reference count becomes 0,
    // the shared data object 'LocPartCountObject' is deleted.
}

int LocPartCount::locPartCountId() const
{
    return d->loc_part_count_id;
}

int LocPartCount::locId() const
{
    return d->loc_id;
}

void LocPartCount::setLocId(int locId)
{
    d->loc_id = locId;
}

int LocPartCount::partNoId() const
{
    return d->part_no_id;
}

void LocPartCount::setPartNoId(int partNoId)
{
    d->part_no_id = partNoId;
}

int LocPartCount::userId() const
{
    return d->user_id;
}

void LocPartCount::setUserId(int userId)
{
    d->user_id = userId;
}

QDateTime LocPartCount::lastCountDt() const
{
    return d->last_count_dt;
}

void LocPartCount::setLastCountDt(const QDateTime &lastCountDt)
{
    d->last_count_dt = lastCountDt;
}

QDateTime LocPartCount::nextCountDt() const
{
    return d->next_count_dt;
}

void LocPartCount::setNextCountDt(const QDateTime &nextCountDt)
{
    d->next_count_dt = nextCountDt;
}

bool LocPartCount::reqRecountBool() const
{
    return d->req_recount_bool;
}

void LocPartCount::setReqRecountBool(bool reqRecountBool)
{
    d->req_recount_bool = reqRecountBool;
}

bool LocPartCount::histBool() const
{
    return d->hist_bool;
}

void LocPartCount::setHistBool(bool histBool)
{
    d->hist_bool = histBool;
}

bool LocPartCount::countAcceptBool() const
{
    return d->count_accept_bool;
}

void LocPartCount::setCountAcceptBool(bool countAcceptBool)
{
    d->count_accept_bool = countAcceptBool;
}

int LocPartCount::countActualQt() const
{
    return d->count_actual_qt;
}

void LocPartCount::setCountActualQt(int countActualQt)
{
    d->count_actual_qt = countActualQt;
}

int LocPartCount::countExpectQt() const
{
    return d->count_expect_qt;
}

void LocPartCount::setCountExpectQt(int countExpectQt)
{
    d->count_expect_qt = countExpectQt;
}

QDateTime LocPartCount::createdAt() const
{
    return d->created_at;
}

QString LocPartCount::createdBy() const
{
    return d->created_by;
}

void LocPartCount::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime LocPartCount::updatedAt() const
{
    return d->updated_at;
}

QString LocPartCount::updatedBy() const
{
    return d->updated_by;
}

void LocPartCount::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

UserApp LocPartCount::userAppByuserId() const
{
 return UserApp::get(d->user_id);
}

EqpPartNo LocPartCount::eqpPartNoBypartNoId() const
{
 return EqpPartNo::get(d->part_no_id);
}

Loc LocPartCount::locBylocId() const
{
 return Loc::get(d->loc_id);
}

LocPartCount &LocPartCount::operator=(const LocPartCount &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

LocPartCount LocPartCount::create(int locId, int partNoId, int userId, const QDateTime &lastCountDt, const QDateTime &nextCountDt, bool reqRecountBool, bool histBool, bool countAcceptBool, int countActualQt, int countExpectQt, const QString &createdBy, const QString &updatedBy)
{
    LocPartCountObject obj;
    obj.loc_id = locId;
    obj.part_no_id = partNoId;
    obj.user_id = userId;
    obj.last_count_dt = lastCountDt;
    obj.next_count_dt = nextCountDt;
    obj.req_recount_bool = reqRecountBool;
    obj.hist_bool = histBool;
    obj.count_accept_bool = countAcceptBool;
    obj.count_actual_qt = countActualQt;
    obj.count_expect_qt = countExpectQt;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return LocPartCount();
    }
    return LocPartCount(obj);
}

LocPartCount LocPartCount::create(const QVariantMap &values)
{
    LocPartCount model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

LocPartCount LocPartCount::get(int locPartCountId)
{
    TSqlORMapper<LocPartCountObject> mapper;
    return LocPartCount(mapper.findByPrimaryKey(locPartCountId));
}

int LocPartCount::count()
{
    TSqlORMapper<LocPartCountObject> mapper;
    return mapper.findCount();
}

QList<LocPartCount> LocPartCount::getAll()
{
    return tfGetModelListByCriteria<LocPartCount, LocPartCountObject>();
}

TModelObject *LocPartCount::modelData()
{
    return d.data();
}

const TModelObject *LocPartCount::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const LocPartCount &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, LocPartCount &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(LocPartCount)
