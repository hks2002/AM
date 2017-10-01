#include <TreeFrogModel>
#include "eqpassmblbompart.h"
#include "eqpassmblbompartobject.h"
#include "eqppartno.h"
#include "eqpassmblbom.h"

EqpAssmblBomPart::EqpAssmblBomPart()
    : TAbstractModel(), d(new EqpAssmblBomPartObject())
{
    d->assmbl_bom_id = 0;
    d->part_no_id = 0;
    d->interchg_ord = 0;
}

EqpAssmblBomPart::EqpAssmblBomPart(const EqpAssmblBomPart &other)
    : TAbstractModel(), d(new EqpAssmblBomPartObject(*other.d))
{ }

EqpAssmblBomPart::EqpAssmblBomPart(const EqpAssmblBomPartObject &object)
    : TAbstractModel(), d(new EqpAssmblBomPartObject(object))
{ }

EqpAssmblBomPart::~EqpAssmblBomPart()
{
    // If the reference count becomes 0,
    // the shared data object 'EqpAssmblBomPartObject' is deleted.
}

int EqpAssmblBomPart::assmblBomId() const
{
    return d->assmbl_bom_id;
}

void EqpAssmblBomPart::setAssmblBomId(int assmblBomId)
{
    d->assmbl_bom_id = assmblBomId;
}

int EqpAssmblBomPart::partNoId() const
{
    return d->part_no_id;
}

void EqpAssmblBomPart::setPartNoId(int partNoId)
{
    d->part_no_id = partNoId;
}

bool EqpAssmblBomPart::standardBool() const
{
    return d->standard_bool;
}

void EqpAssmblBomPart::setStandardBool(bool standardBool)
{
    d->standard_bool = standardBool;
}

bool EqpAssmblBomPart::approvedBool() const
{
    return d->approved_bool;
}

void EqpAssmblBomPart::setApprovedBool(bool approvedBool)
{
    d->approved_bool = approvedBool;
}

int EqpAssmblBomPart::interchgOrd() const
{
    return d->interchg_ord;
}

void EqpAssmblBomPart::setInterchgOrd(int interchgOrd)
{
    d->interchg_ord = interchgOrd;
}

bool EqpAssmblBomPart::conditionalBool() const
{
    return d->conditional_bool;
}

void EqpAssmblBomPart::setConditionalBool(bool conditionalBool)
{
    d->conditional_bool = conditionalBool;
}

QString EqpAssmblBomPart::applDesc() const
{
    return d->appl_desc;
}

void EqpAssmblBomPart::setApplDesc(const QString &applDesc)
{
    d->appl_desc = applDesc;
}

QString EqpAssmblBomPart::applEffDesc() const
{
    return d->appl_eff_desc;
}

void EqpAssmblBomPart::setApplEffDesc(const QString &applEffDesc)
{
    d->appl_eff_desc = applEffDesc;
}

QString EqpAssmblBomPart::applSqlDesc() const
{
    return d->appl_sql_desc;
}

void EqpAssmblBomPart::setApplSqlDesc(const QString &applSqlDesc)
{
    d->appl_sql_desc = applSqlDesc;
}

QDateTime EqpAssmblBomPart::createdAt() const
{
    return d->created_at;
}

QString EqpAssmblBomPart::createdBy() const
{
    return d->created_by;
}

void EqpAssmblBomPart::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime EqpAssmblBomPart::updatedAt() const
{
    return d->updated_at;
}

QString EqpAssmblBomPart::updatedBy() const
{
    return d->updated_by;
}

void EqpAssmblBomPart::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

EqpPartNo EqpAssmblBomPart::eqpPartNoBypartNoId() const
{
 return EqpPartNo::get(d->part_no_id);
}

EqpAssmblBom EqpAssmblBomPart::eqpAssmblBomByassmblBomId() const
{
 return EqpAssmblBom::get(d->assmbl_bom_id);
}

EqpAssmblBomPart &EqpAssmblBomPart::operator=(const EqpAssmblBomPart &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

EqpAssmblBomPart EqpAssmblBomPart::create(int assmblBomId, int partNoId, bool standardBool, bool approvedBool, int interchgOrd, bool conditionalBool, const QString &applDesc, const QString &applEffDesc, const QString &applSqlDesc, const QString &createdBy, const QString &updatedBy)
{
    EqpAssmblBomPartObject obj;
    obj.assmbl_bom_id = assmblBomId;
    obj.part_no_id = partNoId;
    obj.standard_bool = standardBool;
    obj.approved_bool = approvedBool;
    obj.interchg_ord = interchgOrd;
    obj.conditional_bool = conditionalBool;
    obj.appl_desc = applDesc;
    obj.appl_eff_desc = applEffDesc;
    obj.appl_sql_desc = applSqlDesc;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return EqpAssmblBomPart();
    }
    return EqpAssmblBomPart(obj);
}

EqpAssmblBomPart EqpAssmblBomPart::create(const QVariantMap &values)
{
    EqpAssmblBomPart model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

EqpAssmblBomPart EqpAssmblBomPart::get(int assmblBomId, int partNoId)
{
    TSqlORMapper<EqpAssmblBomPartObject> mapper;
    return EqpAssmblBomPart(mapper.findByPrimaryKey(QVariantList()<<QVariant(assmblBomId)<<QVariant(partNoId)));
}

int EqpAssmblBomPart::count()
{
    TSqlORMapper<EqpAssmblBomPartObject> mapper;
    return mapper.findCount();
}

QList<EqpAssmblBomPart> EqpAssmblBomPart::getAll()
{
    return tfGetModelListByCriteria<EqpAssmblBomPart, EqpAssmblBomPartObject>();
}

TModelObject *EqpAssmblBomPart::modelData()
{
    return d.data();
}

const TModelObject *EqpAssmblBomPart::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const EqpAssmblBomPart &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, EqpAssmblBomPart &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(EqpAssmblBomPart)
