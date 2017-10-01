#include <TreeFrogModel>
#include "eqppartnocompatdef.h"
#include "eqppartnocompatdefobject.h"
#include "eqppartno.h"
#include "eqpassmbl.h"

EqpPartNoCompatDef::EqpPartNoCompatDef()
    : TAbstractModel(), d(new EqpPartNoCompatDefObject())
{
    d->assmbl_id = 0;
    d->part_no_id = 0;
    d->compat_part_no_id = 0;
}

EqpPartNoCompatDef::EqpPartNoCompatDef(const EqpPartNoCompatDef &other)
    : TAbstractModel(), d(new EqpPartNoCompatDefObject(*other.d))
{ }

EqpPartNoCompatDef::EqpPartNoCompatDef(const EqpPartNoCompatDefObject &object)
    : TAbstractModel(), d(new EqpPartNoCompatDefObject(object))
{ }

EqpPartNoCompatDef::~EqpPartNoCompatDef()
{
    // If the reference count becomes 0,
    // the shared data object 'EqpPartNoCompatDefObject' is deleted.
}

int EqpPartNoCompatDef::assmblId() const
{
    return d->assmbl_id;
}

void EqpPartNoCompatDef::setAssmblId(int assmblId)
{
    d->assmbl_id = assmblId;
}

int EqpPartNoCompatDef::partNoId() const
{
    return d->part_no_id;
}

void EqpPartNoCompatDef::setPartNoId(int partNoId)
{
    d->part_no_id = partNoId;
}

int EqpPartNoCompatDef::compatPartNoId() const
{
    return d->compat_part_no_id;
}

void EqpPartNoCompatDef::setCompatPartNoId(int compatPartNoId)
{
    d->compat_part_no_id = compatPartNoId;
}

QDateTime EqpPartNoCompatDef::createdAt() const
{
    return d->created_at;
}

QString EqpPartNoCompatDef::createdBy() const
{
    return d->created_by;
}

void EqpPartNoCompatDef::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime EqpPartNoCompatDef::updatedAt() const
{
    return d->updated_at;
}

QString EqpPartNoCompatDef::updatedBy() const
{
    return d->updated_by;
}

void EqpPartNoCompatDef::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

EqpPartNo EqpPartNoCompatDef::eqpPartNoBycompatPartNoId() const
{
 return EqpPartNo::get(d->compat_part_no_id);
}

EqpAssmbl EqpPartNoCompatDef::eqpAssmblByassmblId() const
{
 return EqpAssmbl::get(d->assmbl_id);
}

EqpPartNoCompatDef &EqpPartNoCompatDef::operator=(const EqpPartNoCompatDef &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

EqpPartNoCompatDef EqpPartNoCompatDef::create(int assmblId, int partNoId, int compatPartNoId, const QString &createdBy, const QString &updatedBy)
{
    EqpPartNoCompatDefObject obj;
    obj.assmbl_id = assmblId;
    obj.part_no_id = partNoId;
    obj.compat_part_no_id = compatPartNoId;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return EqpPartNoCompatDef();
    }
    return EqpPartNoCompatDef(obj);
}

EqpPartNoCompatDef EqpPartNoCompatDef::create(const QVariantMap &values)
{
    EqpPartNoCompatDef model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

EqpPartNoCompatDef EqpPartNoCompatDef::get(int assmblId, int partNoId, int compatPartNoId)
{
    TSqlORMapper<EqpPartNoCompatDefObject> mapper;
    return EqpPartNoCompatDef(mapper.findByPrimaryKey(QVariantList()<<QVariant(assmblId)<<QVariant(partNoId)<<QVariant(compatPartNoId)));
}

int EqpPartNoCompatDef::count()
{
    TSqlORMapper<EqpPartNoCompatDefObject> mapper;
    return mapper.findCount();
}

QList<EqpPartNoCompatDef> EqpPartNoCompatDef::getAll()
{
    return tfGetModelListByCriteria<EqpPartNoCompatDef, EqpPartNoCompatDefObject>();
}

TModelObject *EqpPartNoCompatDef::modelData()
{
    return d.data();
}

const TModelObject *EqpPartNoCompatDef::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const EqpPartNoCompatDef &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, EqpPartNoCompatDef &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(EqpPartNoCompatDef)
