#include <TreeFrogModel>
#include "advsry.h"
#include "advsryobject.h"
#include "refadvsrytype.h"

Advsry::Advsry()
    : TAbstractModel(), d(new AdvsryObject())
{
    d->advsry_id = 0;
}

Advsry::Advsry(const Advsry &other)
    : TAbstractModel(), d(new AdvsryObject(*other.d))
{ }

Advsry::Advsry(const AdvsryObject &object)
    : TAbstractModel(), d(new AdvsryObject(object))
{ }

Advsry::~Advsry()
{
    // If the reference count becomes 0,
    // the shared data object 'AdvsryObject' is deleted.
}

int Advsry::advsryId() const
{
    return d->advsry_id;
}

QString Advsry::advsryTypeCd() const
{
    return d->advsry_type_cd;
}

void Advsry::setAdvsryTypeCd(const QString &advsryTypeCd)
{
    d->advsry_type_cd = advsryTypeCd;
}

QString Advsry::advsryName() const
{
    return d->advsry_name;
}

void Advsry::setAdvsryName(const QString &advsryName)
{
    d->advsry_name = advsryName;
}

QString Advsry::advsryDesc() const
{
    return d->advsry_desc;
}

void Advsry::setAdvsryDesc(const QString &advsryDesc)
{
    d->advsry_desc = advsryDesc;
}

bool Advsry::activeBool() const
{
    return d->active_bool;
}

void Advsry::setActiveBool(bool activeBool)
{
    d->active_bool = activeBool;
}

QDateTime Advsry::clearDt() const
{
    return d->clear_dt;
}

void Advsry::setClearDt(const QDateTime &clearDt)
{
    d->clear_dt = clearDt;
}

QString Advsry::clearNote() const
{
    return d->clear_note;
}

void Advsry::setClearNote(const QString &clearNote)
{
    d->clear_note = clearNote;
}

QDateTime Advsry::createdAt() const
{
    return d->created_at;
}

QString Advsry::createdBy() const
{
    return d->created_by;
}

void Advsry::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime Advsry::updatedAt() const
{
    return d->updated_at;
}

QString Advsry::updatedBy() const
{
    return d->updated_by;
}

void Advsry::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

RefAdvsryType Advsry::refAdvsryTypeByadvsryTypeCd() const
{
 return RefAdvsryType::get(d->advsry_type_cd);
}

Advsry &Advsry::operator=(const Advsry &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

Advsry Advsry::create(const QString &advsryTypeCd, const QString &advsryName, const QString &advsryDesc, bool activeBool, const QDateTime &clearDt, const QString &clearNote, const QString &createdBy, const QString &updatedBy)
{
    AdvsryObject obj;
    obj.advsry_type_cd = advsryTypeCd;
    obj.advsry_name = advsryName;
    obj.advsry_desc = advsryDesc;
    obj.active_bool = activeBool;
    obj.clear_dt = clearDt;
    obj.clear_note = clearNote;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return Advsry();
    }
    return Advsry(obj);
}

Advsry Advsry::create(const QVariantMap &values)
{
    Advsry model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

Advsry Advsry::get(int advsryId)
{
    TSqlORMapper<AdvsryObject> mapper;
    return Advsry(mapper.findByPrimaryKey(advsryId));
}

int Advsry::count()
{
    TSqlORMapper<AdvsryObject> mapper;
    return mapper.findCount();
}

QList<Advsry> Advsry::getAll()
{
    return tfGetModelListByCriteria<Advsry, AdvsryObject>();
}

TModelObject *Advsry::modelData()
{
    return d.data();
}

const TModelObject *Advsry::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const Advsry &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, Advsry &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(Advsry)
