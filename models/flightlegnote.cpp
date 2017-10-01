#include <TreeFrogModel>
#include "flightlegnote.h"
#include "flightlegnoteobject.h"
#include "userapp.h"
#include "flightleg.h"

FlightLegNote::FlightLegNote()
    : TAbstractModel(), d(new FlightLegNoteObject())
{
    d->leg_id = 0;
    d->note_by = 0;
}

FlightLegNote::FlightLegNote(const FlightLegNote &other)
    : TAbstractModel(), d(new FlightLegNoteObject(*other.d))
{ }

FlightLegNote::FlightLegNote(const FlightLegNoteObject &object)
    : TAbstractModel(), d(new FlightLegNoteObject(object))
{ }

FlightLegNote::~FlightLegNote()
{
    // If the reference count becomes 0,
    // the shared data object 'FlightLegNoteObject' is deleted.
}

int FlightLegNote::legId() const
{
    return d->leg_id;
}

void FlightLegNote::setLegId(int legId)
{
    d->leg_id = legId;
}

QDateTime FlightLegNote::noteDt() const
{
    return d->note_dt;
}

void FlightLegNote::setNoteDt(const QDateTime &noteDt)
{
    d->note_dt = noteDt;
}

bool FlightLegNote::systemBool() const
{
    return d->system_bool;
}

void FlightLegNote::setSystemBool(bool systemBool)
{
    d->system_bool = systemBool;
}

int FlightLegNote::noteBy() const
{
    return d->note_by;
}

void FlightLegNote::setNoteBy(int noteBy)
{
    d->note_by = noteBy;
}

QString FlightLegNote::noteText() const
{
    return d->note_text;
}

void FlightLegNote::setNoteText(const QString &noteText)
{
    d->note_text = noteText;
}

QDateTime FlightLegNote::createdAt() const
{
    return d->created_at;
}

QString FlightLegNote::createdBy() const
{
    return d->created_by;
}

void FlightLegNote::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime FlightLegNote::updatedAt() const
{
    return d->updated_at;
}

QString FlightLegNote::updatedBy() const
{
    return d->updated_by;
}

void FlightLegNote::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

UserApp FlightLegNote::userAppBynoteBy() const
{
 return UserApp::get(d->note_by);
}

FlightLeg FlightLegNote::flightLegBylegId() const
{
 return FlightLeg::get(d->leg_id);
}

FlightLegNote &FlightLegNote::operator=(const FlightLegNote &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

FlightLegNote FlightLegNote::create(int legId, const QDateTime &noteDt, bool systemBool, int noteBy, const QString &noteText, const QString &createdBy, const QString &updatedBy)
{
    FlightLegNoteObject obj;
    obj.leg_id = legId;
    obj.note_dt = noteDt;
    obj.system_bool = systemBool;
    obj.note_by = noteBy;
    obj.note_text = noteText;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return FlightLegNote();
    }
    return FlightLegNote(obj);
}

FlightLegNote FlightLegNote::create(const QVariantMap &values)
{
    FlightLegNote model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

FlightLegNote FlightLegNote::get(int legId)
{
    TSqlORMapper<FlightLegNoteObject> mapper;
    return FlightLegNote(mapper.findByPrimaryKey(legId));
}

int FlightLegNote::count()
{
    TSqlORMapper<FlightLegNoteObject> mapper;
    return mapper.findCount();
}

QList<FlightLegNote> FlightLegNote::getAll()
{
    return tfGetModelListByCriteria<FlightLegNote, FlightLegNoteObject>();
}

TModelObject *FlightLegNote::modelData()
{
    return d.data();
}

const TModelObject *FlightLegNote::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const FlightLegNote &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, FlightLegNote &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(FlightLegNote)
