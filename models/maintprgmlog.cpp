#include <TreeFrogModel>
#include "maintprgmlog.h"
#include "maintprgmlogobject.h"
#include "reflogaction.h"
#include "maintprgm.h"

MaintPrgmLog::MaintPrgmLog()
    : TAbstractModel(), d(new MaintPrgmLogObject())
{
    d->maint_prgm_log_id = 0;
    d->maint_prgm_id = 0;
}

MaintPrgmLog::MaintPrgmLog(const MaintPrgmLog &other)
    : TAbstractModel(), d(new MaintPrgmLogObject(*other.d))
{ }

MaintPrgmLog::MaintPrgmLog(const MaintPrgmLogObject &object)
    : TAbstractModel(), d(new MaintPrgmLogObject(object))
{ }

MaintPrgmLog::~MaintPrgmLog()
{
    // If the reference count becomes 0,
    // the shared data object 'MaintPrgmLogObject' is deleted.
}

int MaintPrgmLog::maintPrgmLogId() const
{
    return d->maint_prgm_log_id;
}

int MaintPrgmLog::maintPrgmId() const
{
    return d->maint_prgm_id;
}

void MaintPrgmLog::setMaintPrgmId(int maintPrgmId)
{
    d->maint_prgm_id = maintPrgmId;
}

QString MaintPrgmLog::logActionCd() const
{
    return d->log_action_cd;
}

void MaintPrgmLog::setLogActionCd(const QString &logActionCd)
{
    d->log_action_cd = logActionCd;
}

QDateTime MaintPrgmLog::logDt() const
{
    return d->log_dt;
}

void MaintPrgmLog::setLogDt(const QDateTime &logDt)
{
    d->log_dt = logDt;
}

QString MaintPrgmLog::userNote() const
{
    return d->user_note;
}

void MaintPrgmLog::setUserNote(const QString &userNote)
{
    d->user_note = userNote;
}

QString MaintPrgmLog::systemNote() const
{
    return d->system_note;
}

void MaintPrgmLog::setSystemNote(const QString &systemNote)
{
    d->system_note = systemNote;
}

QDateTime MaintPrgmLog::createdAt() const
{
    return d->created_at;
}

QString MaintPrgmLog::createdBy() const
{
    return d->created_by;
}

void MaintPrgmLog::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime MaintPrgmLog::updatedAt() const
{
    return d->updated_at;
}

QString MaintPrgmLog::updatedBy() const
{
    return d->updated_by;
}

void MaintPrgmLog::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

RefLogAction MaintPrgmLog::refLogActionBylogActionCd() const
{
 return RefLogAction::get(d->log_action_cd);
}

MaintPrgm MaintPrgmLog::maintPrgmBymaintPrgmId() const
{
 return MaintPrgm::get(d->maint_prgm_id);
}

MaintPrgmLog &MaintPrgmLog::operator=(const MaintPrgmLog &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

MaintPrgmLog MaintPrgmLog::create(int maintPrgmId, const QString &logActionCd, const QDateTime &logDt, const QString &userNote, const QString &systemNote, const QString &createdBy, const QString &updatedBy)
{
    MaintPrgmLogObject obj;
    obj.maint_prgm_id = maintPrgmId;
    obj.log_action_cd = logActionCd;
    obj.log_dt = logDt;
    obj.user_note = userNote;
    obj.system_note = systemNote;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return MaintPrgmLog();
    }
    return MaintPrgmLog(obj);
}

MaintPrgmLog MaintPrgmLog::create(const QVariantMap &values)
{
    MaintPrgmLog model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

MaintPrgmLog MaintPrgmLog::get(int maintPrgmLogId)
{
    TSqlORMapper<MaintPrgmLogObject> mapper;
    return MaintPrgmLog(mapper.findByPrimaryKey(maintPrgmLogId));
}

int MaintPrgmLog::count()
{
    TSqlORMapper<MaintPrgmLogObject> mapper;
    return mapper.findCount();
}

QList<MaintPrgmLog> MaintPrgmLog::getAll()
{
    return tfGetModelListByCriteria<MaintPrgmLog, MaintPrgmLogObject>();
}

TModelObject *MaintPrgmLog::modelData()
{
    return d.data();
}

const TModelObject *MaintPrgmLog::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const MaintPrgmLog &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, MaintPrgmLog &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(MaintPrgmLog)
