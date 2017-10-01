#include <TreeFrogModel>
#include "loc.h"
#include "locobject.h"
#include "refloctype.h"

Loc::Loc()
    : TAbstractModel(), d(new LocObject())
{
    d->loc_id = 0;
}

Loc::Loc(const Loc &other)
    : TAbstractModel(), d(new LocObject(*other.d))
{ }

Loc::Loc(const LocObject &object)
    : TAbstractModel(), d(new LocObject(object))
{ }

Loc::~Loc()
{
    // If the reference count becomes 0,
    // the shared data object 'LocObject' is deleted.
}

int Loc::locId() const
{
    return d->loc_id;
}

QString Loc::locCd() const
{
    return d->loc_cd;
}

void Loc::setLocCd(const QString &locCd)
{
    d->loc_cd = locCd;
}

QString Loc::locTypeCd() const
{
    return d->loc_type_cd;
}

void Loc::setLocTypeCd(const QString &locTypeCd)
{
    d->loc_type_cd = locTypeCd;
}

QString Loc::locName() const
{
    return d->loc_name;
}

void Loc::setLocName(const QString &locName)
{
    d->loc_name = locName;
}

QDateTime Loc::createdAt() const
{
    return d->created_at;
}

QString Loc::createdBy() const
{
    return d->created_by;
}

void Loc::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime Loc::updatedAt() const
{
    return d->updated_at;
}

QString Loc::updatedBy() const
{
    return d->updated_by;
}

void Loc::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

RefLocType Loc::refLocTypeBylocTypeCd() const
{
 return RefLocType::get(d->loc_type_cd);
}

Loc &Loc::operator=(const Loc &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

Loc Loc::create(const QString &locCd, const QString &locTypeCd, const QString &locName, const QString &createdBy, const QString &updatedBy)
{
    LocObject obj;
    obj.loc_cd = locCd;
    obj.loc_type_cd = locTypeCd;
    obj.loc_name = locName;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return Loc();
    }
    return Loc(obj);
}

Loc Loc::create(const QVariantMap &values)
{
    Loc model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

Loc Loc::get(int locId)
{
    TSqlORMapper<LocObject> mapper;
    return Loc(mapper.findByPrimaryKey(locId));
}

int Loc::count()
{
    TSqlORMapper<LocObject> mapper;
    return mapper.findCount();
}

QList<Loc> Loc::getAll()
{
    return tfGetModelListByCriteria<Loc, LocObject>();
}

TModelObject *Loc::modelData()
{
    return d.data();
}

const TModelObject *Loc::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const Loc &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, Loc &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(Loc)
