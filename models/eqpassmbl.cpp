#include <TreeFrogModel>
#include "eqpassmbl.h"
#include "eqpassmblobject.h"
#include "refassmblclass.h"

EqpAssmbl::EqpAssmbl()
    : TAbstractModel(), d(new EqpAssmblObject())
{
    d->assmbl_id = 0;
}

EqpAssmbl::EqpAssmbl(const EqpAssmbl &other)
    : TAbstractModel(), d(new EqpAssmblObject(*other.d))
{ }

EqpAssmbl::EqpAssmbl(const EqpAssmblObject &object)
    : TAbstractModel(), d(new EqpAssmblObject(object))
{ }

EqpAssmbl::~EqpAssmbl()
{
    // If the reference count becomes 0,
    // the shared data object 'EqpAssmblObject' is deleted.
}

int EqpAssmbl::assmblId() const
{
    return d->assmbl_id;
}

QString EqpAssmbl::assmblCd() const
{
    return d->assmbl_cd;
}

void EqpAssmbl::setAssmblCd(const QString &assmblCd)
{
    d->assmbl_cd = assmblCd;
}

QString EqpAssmbl::assmblClassCd() const
{
    return d->assmbl_class_cd;
}

void EqpAssmbl::setAssmblClassCd(const QString &assmblClassCd)
{
    d->assmbl_class_cd = assmblClassCd;
}

QString EqpAssmbl::assmblName() const
{
    return d->assmbl_name;
}

void EqpAssmbl::setAssmblName(const QString &assmblName)
{
    d->assmbl_name = assmblName;
}

QString EqpAssmbl::assmblDesc() const
{
    return d->assmbl_desc;
}

void EqpAssmbl::setAssmblDesc(const QString &assmblDesc)
{
    d->assmbl_desc = assmblDesc;
}

QDateTime EqpAssmbl::createdAt() const
{
    return d->created_at;
}

QString EqpAssmbl::createdBy() const
{
    return d->created_by;
}

void EqpAssmbl::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime EqpAssmbl::updatedAt() const
{
    return d->updated_at;
}

QString EqpAssmbl::updatedBy() const
{
    return d->updated_by;
}

void EqpAssmbl::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

RefAssmblClass EqpAssmbl::refAssmblClassByassmblClassCd() const
{
 return RefAssmblClass::get(d->assmbl_class_cd);
}

EqpAssmbl &EqpAssmbl::operator=(const EqpAssmbl &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

EqpAssmbl EqpAssmbl::create(const QString &assmblCd, const QString &assmblClassCd, const QString &assmblName, const QString &assmblDesc, const QString &createdBy, const QString &updatedBy)
{
    EqpAssmblObject obj;
    obj.assmbl_cd = assmblCd;
    obj.assmbl_class_cd = assmblClassCd;
    obj.assmbl_name = assmblName;
    obj.assmbl_desc = assmblDesc;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return EqpAssmbl();
    }
    return EqpAssmbl(obj);
}

EqpAssmbl EqpAssmbl::create(const QVariantMap &values)
{
    EqpAssmbl model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

EqpAssmbl EqpAssmbl::get(int assmblId)
{
    TSqlORMapper<EqpAssmblObject> mapper;
    return EqpAssmbl(mapper.findByPrimaryKey(assmblId));
}

int EqpAssmbl::count()
{
    TSqlORMapper<EqpAssmblObject> mapper;
    return mapper.findCount();
}

QList<EqpAssmbl> EqpAssmbl::getAll()
{
    return tfGetModelListByCriteria<EqpAssmbl, EqpAssmblObject>();
}

TModelObject *EqpAssmbl::modelData()
{
    return d.data();
}

const TModelObject *EqpAssmbl::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const EqpAssmbl &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, EqpAssmbl &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(EqpAssmbl)
