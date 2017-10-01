#include <TreeFrogModel>
#include "quarquar.h"
#include "quarquarobject.h"
#include "loc.h"
#include "invinv.h"
#include "userapp.h"

QuarQuar::QuarQuar()
    : TAbstractModel(), d(new QuarQuarObject())
{
    d->quar_id = 0;
    d->user_id = 0;
    d->inv_no_id = 0;
    d->loc_id = 0;
}

QuarQuar::QuarQuar(const QuarQuar &other)
    : TAbstractModel(), d(new QuarQuarObject(*other.d))
{ }

QuarQuar::QuarQuar(const QuarQuarObject &object)
    : TAbstractModel(), d(new QuarQuarObject(object))
{ }

QuarQuar::~QuarQuar()
{
    // If the reference count becomes 0,
    // the shared data object 'QuarQuarObject' is deleted.
}

int QuarQuar::quarId() const
{
    return d->quar_id;
}

QString QuarQuar::quarNote() const
{
    return d->quar_note;
}

void QuarQuar::setQuarNote(const QString &quarNote)
{
    d->quar_note = quarNote;
}

QDateTime QuarQuar::quarDt() const
{
    return d->quar_dt;
}

void QuarQuar::setQuarDt(const QDateTime &quarDt)
{
    d->quar_dt = quarDt;
}

int QuarQuar::userId() const
{
    return d->user_id;
}

void QuarQuar::setUserId(int userId)
{
    d->user_id = userId;
}

int QuarQuar::invNoId() const
{
    return d->inv_no_id;
}

void QuarQuar::setInvNoId(int invNoId)
{
    d->inv_no_id = invNoId;
}

int QuarQuar::locId() const
{
    return d->loc_id;
}

void QuarQuar::setLocId(int locId)
{
    d->loc_id = locId;
}

bool QuarQuar::histBool() const
{
    return d->hist_bool;
}

void QuarQuar::setHistBool(bool histBool)
{
    d->hist_bool = histBool;
}

QDateTime QuarQuar::createdAt() const
{
    return d->created_at;
}

QString QuarQuar::createdBy() const
{
    return d->created_by;
}

void QuarQuar::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime QuarQuar::updatedAt() const
{
    return d->updated_at;
}

QString QuarQuar::updatedBy() const
{
    return d->updated_by;
}

void QuarQuar::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

Loc QuarQuar::locBylocId() const
{
 return Loc::get(d->loc_id);
}

InvInv QuarQuar::invInvByinvNoId() const
{
 return InvInv::get(d->inv_no_id);
}

UserApp QuarQuar::userAppByuserId() const
{
 return UserApp::get(d->user_id);
}

QuarQuar &QuarQuar::operator=(const QuarQuar &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

QuarQuar QuarQuar::create(const QString &quarNote, const QDateTime &quarDt, int userId, int invNoId, int locId, bool histBool, const QString &createdBy, const QString &updatedBy)
{
    QuarQuarObject obj;
    obj.quar_note = quarNote;
    obj.quar_dt = quarDt;
    obj.user_id = userId;
    obj.inv_no_id = invNoId;
    obj.loc_id = locId;
    obj.hist_bool = histBool;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return QuarQuar();
    }
    return QuarQuar(obj);
}

QuarQuar QuarQuar::create(const QVariantMap &values)
{
    QuarQuar model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

QuarQuar QuarQuar::get(int quarId)
{
    TSqlORMapper<QuarQuarObject> mapper;
    return QuarQuar(mapper.findByPrimaryKey(quarId));
}

int QuarQuar::count()
{
    TSqlORMapper<QuarQuarObject> mapper;
    return mapper.findCount();
}

QList<QuarQuar> QuarQuar::getAll()
{
    return tfGetModelListByCriteria<QuarQuar, QuarQuarObject>();
}

TModelObject *QuarQuar::modelData()
{
    return d.data();
}

const TModelObject *QuarQuar::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const QuarQuar &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, QuarQuar &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(QuarQuar)
