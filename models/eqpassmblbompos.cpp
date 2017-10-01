#include <TreeFrogModel>
#include "eqpassmblbompos.h"
#include "eqpassmblbomposobject.h"
#include "eqpassmblbom.h"

EqpAssmblBomPos::EqpAssmblBomPos()
    : TAbstractModel(), d(new EqpAssmblBomPosObject())
{
    d->assmbl_bom_pos_id = 0;
    d->assmbl_bom_id = 0;
}

EqpAssmblBomPos::EqpAssmblBomPos(const EqpAssmblBomPos &other)
    : TAbstractModel(), d(new EqpAssmblBomPosObject(*other.d))
{ }

EqpAssmblBomPos::EqpAssmblBomPos(const EqpAssmblBomPosObject &object)
    : TAbstractModel(), d(new EqpAssmblBomPosObject(object))
{ }

EqpAssmblBomPos::~EqpAssmblBomPos()
{
    // If the reference count becomes 0,
    // the shared data object 'EqpAssmblBomPosObject' is deleted.
}

int EqpAssmblBomPos::assmblBomPosId() const
{
    return d->assmbl_bom_pos_id;
}

int EqpAssmblBomPos::assmblBomId() const
{
    return d->assmbl_bom_id;
}

void EqpAssmblBomPos::setAssmblBomId(int assmblBomId)
{
    d->assmbl_bom_id = assmblBomId;
}

QString EqpAssmblBomPos::eqpPosCd() const
{
    return d->eqp_pos_cd;
}

void EqpAssmblBomPos::setEqpPosCd(const QString &eqpPosCd)
{
    d->eqp_pos_cd = eqpPosCd;
}

QDateTime EqpAssmblBomPos::createdAt() const
{
    return d->created_at;
}

QString EqpAssmblBomPos::createdBy() const
{
    return d->created_by;
}

void EqpAssmblBomPos::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime EqpAssmblBomPos::updatedAt() const
{
    return d->updated_at;
}

QString EqpAssmblBomPos::updatedBy() const
{
    return d->updated_by;
}

void EqpAssmblBomPos::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

EqpAssmblBom EqpAssmblBomPos::eqpAssmblBomByassmblBomId() const
{
 return EqpAssmblBom::get(d->assmbl_bom_id);
}

EqpAssmblBomPos &EqpAssmblBomPos::operator=(const EqpAssmblBomPos &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

EqpAssmblBomPos EqpAssmblBomPos::create(int assmblBomId, const QString &eqpPosCd, const QString &createdBy, const QString &updatedBy)
{
    EqpAssmblBomPosObject obj;
    obj.assmbl_bom_id = assmblBomId;
    obj.eqp_pos_cd = eqpPosCd;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return EqpAssmblBomPos();
    }
    return EqpAssmblBomPos(obj);
}

EqpAssmblBomPos EqpAssmblBomPos::create(const QVariantMap &values)
{
    EqpAssmblBomPos model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

EqpAssmblBomPos EqpAssmblBomPos::get(int assmblBomPosId)
{
    TSqlORMapper<EqpAssmblBomPosObject> mapper;
    return EqpAssmblBomPos(mapper.findByPrimaryKey(assmblBomPosId));
}

int EqpAssmblBomPos::count()
{
    TSqlORMapper<EqpAssmblBomPosObject> mapper;
    return mapper.findCount();
}

QList<EqpAssmblBomPos> EqpAssmblBomPos::getAll()
{
    return tfGetModelListByCriteria<EqpAssmblBomPos, EqpAssmblBomPosObject>();
}

TModelObject *EqpAssmblBomPos::modelData()
{
    return d.data();
}

const TModelObject *EqpAssmblBomPos::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const EqpAssmblBomPos &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, EqpAssmblBomPos &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(EqpAssmblBomPos)
