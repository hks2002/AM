#include <TreeFrogModel>
#include "eqpassmblbomtree.h"
#include "eqpassmblbomtreeobject.h"
#include "eqpassmblbom.h"

EqpAssmblBomTree::EqpAssmblBomTree()
    : TAbstractModel(), d(new EqpAssmblBomTreeObject())
{
    d->assmbl_bom_id = 0;
    d->assmbl_bom_nh_id = 0;
}

EqpAssmblBomTree::EqpAssmblBomTree(const EqpAssmblBomTree &other)
    : TAbstractModel(), d(new EqpAssmblBomTreeObject(*other.d))
{ }

EqpAssmblBomTree::EqpAssmblBomTree(const EqpAssmblBomTreeObject &object)
    : TAbstractModel(), d(new EqpAssmblBomTreeObject(object))
{ }

EqpAssmblBomTree::~EqpAssmblBomTree()
{
    // If the reference count becomes 0,
    // the shared data object 'EqpAssmblBomTreeObject' is deleted.
}

int EqpAssmblBomTree::assmblBomId() const
{
    return d->assmbl_bom_id;
}

void EqpAssmblBomTree::setAssmblBomId(int assmblBomId)
{
    d->assmbl_bom_id = assmblBomId;
}

int EqpAssmblBomTree::assmblBomNhId() const
{
    return d->assmbl_bom_nh_id;
}

void EqpAssmblBomTree::setAssmblBomNhId(int assmblBomNhId)
{
    d->assmbl_bom_nh_id = assmblBomNhId;
}

bool EqpAssmblBomTree::shadeBomBool() const
{
    return d->shade_bom_bool;
}

void EqpAssmblBomTree::setShadeBomBool(bool shadeBomBool)
{
    d->shade_bom_bool = shadeBomBool;
}

QDateTime EqpAssmblBomTree::createdAt() const
{
    return d->created_at;
}

QString EqpAssmblBomTree::createdBy() const
{
    return d->created_by;
}

void EqpAssmblBomTree::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime EqpAssmblBomTree::updatedAt() const
{
    return d->updated_at;
}

QString EqpAssmblBomTree::updatedBy() const
{
    return d->updated_by;
}

void EqpAssmblBomTree::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

EqpAssmblBom EqpAssmblBomTree::eqpAssmblBomByassmblBomNhId() const
{
 return EqpAssmblBom::get(d->assmbl_bom_nh_id);
}

EqpAssmblBomTree &EqpAssmblBomTree::operator=(const EqpAssmblBomTree &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

EqpAssmblBomTree EqpAssmblBomTree::create(int assmblBomId, int assmblBomNhId, bool shadeBomBool, const QString &createdBy, const QString &updatedBy)
{
    EqpAssmblBomTreeObject obj;
    obj.assmbl_bom_id = assmblBomId;
    obj.assmbl_bom_nh_id = assmblBomNhId;
    obj.shade_bom_bool = shadeBomBool;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return EqpAssmblBomTree();
    }
    return EqpAssmblBomTree(obj);
}

EqpAssmblBomTree EqpAssmblBomTree::create(const QVariantMap &values)
{
    EqpAssmblBomTree model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

EqpAssmblBomTree EqpAssmblBomTree::get(int assmblBomId, int assmblBomNhId)
{
    TSqlORMapper<EqpAssmblBomTreeObject> mapper;
    return EqpAssmblBomTree(mapper.findByPrimaryKey(QVariantList()<<QVariant(assmblBomId)<<QVariant(assmblBomNhId)));
}

int EqpAssmblBomTree::count()
{
    TSqlORMapper<EqpAssmblBomTreeObject> mapper;
    return mapper.findCount();
}

QList<EqpAssmblBomTree> EqpAssmblBomTree::getAll()
{
    return tfGetModelListByCriteria<EqpAssmblBomTree, EqpAssmblBomTreeObject>();
}

TModelObject *EqpAssmblBomTree::modelData()
{
    return d.data();
}

const TModelObject *EqpAssmblBomTree::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const EqpAssmblBomTree &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, EqpAssmblBomTree &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(EqpAssmblBomTree)
