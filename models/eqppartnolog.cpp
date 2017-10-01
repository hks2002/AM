#include <TreeFrogModel>
#include "eqppartnolog.h"
#include "eqppartnologobject.h"
#include "reflogaction.h"
#include "eqppartno.h"

EqpPartNoLog::EqpPartNoLog()
    : TAbstractModel(), d(new EqpPartNoLogObject())
{
    d->part_no_log_id = 0;
    d->part_no_id = 0;
}

EqpPartNoLog::EqpPartNoLog(const EqpPartNoLog &other)
    : TAbstractModel(), d(new EqpPartNoLogObject(*other.d))
{ }

EqpPartNoLog::EqpPartNoLog(const EqpPartNoLogObject &object)
    : TAbstractModel(), d(new EqpPartNoLogObject(object))
{ }

EqpPartNoLog::~EqpPartNoLog()
{
    // If the reference count becomes 0,
    // the shared data object 'EqpPartNoLogObject' is deleted.
}

int EqpPartNoLog::partNoLogId() const
{
    return d->part_no_log_id;
}

int EqpPartNoLog::partNoId() const
{
    return d->part_no_id;
}

void EqpPartNoLog::setPartNoId(int partNoId)
{
    d->part_no_id = partNoId;
}

QString EqpPartNoLog::logActionCd() const
{
    return d->log_action_cd;
}

void EqpPartNoLog::setLogActionCd(const QString &logActionCd)
{
    d->log_action_cd = logActionCd;
}

QString EqpPartNoLog::userNote() const
{
    return d->user_note;
}

void EqpPartNoLog::setUserNote(const QString &userNote)
{
    d->user_note = userNote;
}

QString EqpPartNoLog::systemNote() const
{
    return d->system_note;
}

void EqpPartNoLog::setSystemNote(const QString &systemNote)
{
    d->system_note = systemNote;
}

QDateTime EqpPartNoLog::createdAt() const
{
    return d->created_at;
}

QString EqpPartNoLog::createdBy() const
{
    return d->created_by;
}

void EqpPartNoLog::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime EqpPartNoLog::updatedAt() const
{
    return d->updated_at;
}

QString EqpPartNoLog::updatedBy() const
{
    return d->updated_by;
}

void EqpPartNoLog::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

RefLogAction EqpPartNoLog::refLogActionBylogActionCd() const
{
 return RefLogAction::get(d->log_action_cd);
}

EqpPartNo EqpPartNoLog::eqpPartNoBypartNoId() const
{
 return EqpPartNo::get(d->part_no_id);
}

EqpPartNoLog &EqpPartNoLog::operator=(const EqpPartNoLog &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

EqpPartNoLog EqpPartNoLog::create(int partNoId, const QString &logActionCd, const QString &userNote, const QString &systemNote, const QString &createdBy, const QString &updatedBy)
{
    EqpPartNoLogObject obj;
    obj.part_no_id = partNoId;
    obj.log_action_cd = logActionCd;
    obj.user_note = userNote;
    obj.system_note = systemNote;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return EqpPartNoLog();
    }
    return EqpPartNoLog(obj);
}

EqpPartNoLog EqpPartNoLog::create(const QVariantMap &values)
{
    EqpPartNoLog model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

EqpPartNoLog EqpPartNoLog::get(int partNoLogId)
{
    TSqlORMapper<EqpPartNoLogObject> mapper;
    return EqpPartNoLog(mapper.findByPrimaryKey(partNoLogId));
}

int EqpPartNoLog::count()
{
    TSqlORMapper<EqpPartNoLogObject> mapper;
    return mapper.findCount();
}

QList<EqpPartNoLog> EqpPartNoLog::getAll()
{
    return tfGetModelListByCriteria<EqpPartNoLog, EqpPartNoLogObject>();
}

TModelObject *EqpPartNoLog::modelData()
{
    return d.data();
}

const TModelObject *EqpPartNoLog::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const EqpPartNoLog &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, EqpPartNoLog &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(EqpPartNoLog)
