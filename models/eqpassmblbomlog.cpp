#include <TreeFrogModel>
#include "eqpassmblbomlog.h"
#include "eqpassmblbomlogobject.h"
#include "reflogaction.h"
#include "eqpassmblbom.h"
#include "eqpassmbl.h"

EqpAssmblBomLog::EqpAssmblBomLog()
    : TAbstractModel(), d(new EqpAssmblBomLogObject())
{
    d->assmbl_bom_log_id = 0;
    d->assmbl_id = 0;
    d->assmbl_bom_id = 0;
}

EqpAssmblBomLog::EqpAssmblBomLog(const EqpAssmblBomLog &other)
    : TAbstractModel(), d(new EqpAssmblBomLogObject(*other.d))
{ }

EqpAssmblBomLog::EqpAssmblBomLog(const EqpAssmblBomLogObject &object)
    : TAbstractModel(), d(new EqpAssmblBomLogObject(object))
{ }

EqpAssmblBomLog::~EqpAssmblBomLog()
{
    // If the reference count becomes 0,
    // the shared data object 'EqpAssmblBomLogObject' is deleted.
}

int EqpAssmblBomLog::assmblBomLogId() const
{
    return d->assmbl_bom_log_id;
}

int EqpAssmblBomLog::assmblId() const
{
    return d->assmbl_id;
}

void EqpAssmblBomLog::setAssmblId(int assmblId)
{
    d->assmbl_id = assmblId;
}

int EqpAssmblBomLog::assmblBomId() const
{
    return d->assmbl_bom_id;
}

void EqpAssmblBomLog::setAssmblBomId(int assmblBomId)
{
    d->assmbl_bom_id = assmblBomId;
}

QString EqpAssmblBomLog::logActionCd() const
{
    return d->log_action_cd;
}

void EqpAssmblBomLog::setLogActionCd(const QString &logActionCd)
{
    d->log_action_cd = logActionCd;
}

QString EqpAssmblBomLog::userNote() const
{
    return d->user_note;
}

void EqpAssmblBomLog::setUserNote(const QString &userNote)
{
    d->user_note = userNote;
}

QString EqpAssmblBomLog::systemNote() const
{
    return d->system_note;
}

void EqpAssmblBomLog::setSystemNote(const QString &systemNote)
{
    d->system_note = systemNote;
}

QDateTime EqpAssmblBomLog::createdAt() const
{
    return d->created_at;
}

QString EqpAssmblBomLog::createdBy() const
{
    return d->created_by;
}

void EqpAssmblBomLog::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime EqpAssmblBomLog::updatedAt() const
{
    return d->updated_at;
}

QString EqpAssmblBomLog::updatedBy() const
{
    return d->updated_by;
}

void EqpAssmblBomLog::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

RefLogAction EqpAssmblBomLog::refLogActionBylogActionCd() const
{
 return RefLogAction::get(d->log_action_cd);
}

EqpAssmblBom EqpAssmblBomLog::eqpAssmblBomByassmblBomId() const
{
 return EqpAssmblBom::get(d->assmbl_bom_id);
}

EqpAssmbl EqpAssmblBomLog::eqpAssmblByassmblId() const
{
 return EqpAssmbl::get(d->assmbl_id);
}

EqpAssmblBomLog &EqpAssmblBomLog::operator=(const EqpAssmblBomLog &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

EqpAssmblBomLog EqpAssmblBomLog::create(int assmblId, int assmblBomId, const QString &logActionCd, const QString &userNote, const QString &systemNote, const QString &createdBy, const QString &updatedBy)
{
    EqpAssmblBomLogObject obj;
    obj.assmbl_id = assmblId;
    obj.assmbl_bom_id = assmblBomId;
    obj.log_action_cd = logActionCd;
    obj.user_note = userNote;
    obj.system_note = systemNote;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return EqpAssmblBomLog();
    }
    return EqpAssmblBomLog(obj);
}

EqpAssmblBomLog EqpAssmblBomLog::create(const QVariantMap &values)
{
    EqpAssmblBomLog model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

EqpAssmblBomLog EqpAssmblBomLog::get(int assmblBomLogId)
{
    TSqlORMapper<EqpAssmblBomLogObject> mapper;
    return EqpAssmblBomLog(mapper.findByPrimaryKey(assmblBomLogId));
}

int EqpAssmblBomLog::count()
{
    TSqlORMapper<EqpAssmblBomLogObject> mapper;
    return mapper.findCount();
}

QList<EqpAssmblBomLog> EqpAssmblBomLog::getAll()
{
    return tfGetModelListByCriteria<EqpAssmblBomLog, EqpAssmblBomLogObject>();
}

TModelObject *EqpAssmblBomLog::modelData()
{
    return d.data();
}

const TModelObject *EqpAssmblBomLog::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const EqpAssmblBomLog &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, EqpAssmblBomLog &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(EqpAssmblBomLog)
