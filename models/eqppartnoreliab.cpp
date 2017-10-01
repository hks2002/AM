#include <TreeFrogModel>
#include "eqppartnoreliab.h"
#include "eqppartnoreliabobject.h"
#include "refengunit.h"
#include "eqppartno.h"

EqpPartNoReliab::EqpPartNoReliab()
    : TAbstractModel(), d(new EqpPartNoReliabObject())
{
    d->part_no_id = 0;
    d->mtbf_qt = 0;
    d->mtbr_qt = 0;
    d->mtbur_qt = 0;
    d->mttr_qt = 0;
}

EqpPartNoReliab::EqpPartNoReliab(const EqpPartNoReliab &other)
    : TAbstractModel(), d(new EqpPartNoReliabObject(*other.d))
{ }

EqpPartNoReliab::EqpPartNoReliab(const EqpPartNoReliabObject &object)
    : TAbstractModel(), d(new EqpPartNoReliabObject(object))
{ }

EqpPartNoReliab::~EqpPartNoReliab()
{
    // If the reference count becomes 0,
    // the shared data object 'EqpPartNoReliabObject' is deleted.
}

int EqpPartNoReliab::partNoId() const
{
    return d->part_no_id;
}

void EqpPartNoReliab::setPartNoId(int partNoId)
{
    d->part_no_id = partNoId;
}

QString EqpPartNoReliab::engUnitCd() const
{
    return d->eng_unit_cd;
}

void EqpPartNoReliab::setEngUnitCd(const QString &engUnitCd)
{
    d->eng_unit_cd = engUnitCd;
}

double EqpPartNoReliab::mtbfQt() const
{
    return d->mtbf_qt;
}

void EqpPartNoReliab::setMtbfQt(double mtbfQt)
{
    d->mtbf_qt = mtbfQt;
}

double EqpPartNoReliab::mtbrQt() const
{
    return d->mtbr_qt;
}

void EqpPartNoReliab::setMtbrQt(double mtbrQt)
{
    d->mtbr_qt = mtbrQt;
}

double EqpPartNoReliab::mtburQt() const
{
    return d->mtbur_qt;
}

void EqpPartNoReliab::setMtburQt(double mtburQt)
{
    d->mtbur_qt = mtburQt;
}

double EqpPartNoReliab::mttrQt() const
{
    return d->mttr_qt;
}

void EqpPartNoReliab::setMttrQt(double mttrQt)
{
    d->mttr_qt = mttrQt;
}

QDateTime EqpPartNoReliab::createdAt() const
{
    return d->created_at;
}

QString EqpPartNoReliab::createdBy() const
{
    return d->created_by;
}

void EqpPartNoReliab::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime EqpPartNoReliab::updatedAt() const
{
    return d->updated_at;
}

QString EqpPartNoReliab::updatedBy() const
{
    return d->updated_by;
}

void EqpPartNoReliab::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

RefEngUnit EqpPartNoReliab::refEngUnitByengUnitCd() const
{
 return RefEngUnit::get(d->eng_unit_cd);
}

EqpPartNo EqpPartNoReliab::eqpPartNoBypartNoId() const
{
 return EqpPartNo::get(d->part_no_id);
}

EqpPartNoReliab &EqpPartNoReliab::operator=(const EqpPartNoReliab &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

EqpPartNoReliab EqpPartNoReliab::create(int partNoId, const QString &engUnitCd, double mtbfQt, double mtbrQt, double mtburQt, double mttrQt, const QString &createdBy, const QString &updatedBy)
{
    EqpPartNoReliabObject obj;
    obj.part_no_id = partNoId;
    obj.eng_unit_cd = engUnitCd;
    obj.mtbf_qt = mtbfQt;
    obj.mtbr_qt = mtbrQt;
    obj.mtbur_qt = mtburQt;
    obj.mttr_qt = mttrQt;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return EqpPartNoReliab();
    }
    return EqpPartNoReliab(obj);
}

EqpPartNoReliab EqpPartNoReliab::create(const QVariantMap &values)
{
    EqpPartNoReliab model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

EqpPartNoReliab EqpPartNoReliab::get(int partNoId, const QString &engUnitCd)
{
    TSqlORMapper<EqpPartNoReliabObject> mapper;
    return EqpPartNoReliab(mapper.findByPrimaryKey(QVariantList()<<QVariant(partNoId)<<QVariant(engUnitCd)));
}

int EqpPartNoReliab::count()
{
    TSqlORMapper<EqpPartNoReliabObject> mapper;
    return mapper.findCount();
}

QList<EqpPartNoReliab> EqpPartNoReliab::getAll()
{
    return tfGetModelListByCriteria<EqpPartNoReliab, EqpPartNoReliabObject>();
}

TModelObject *EqpPartNoReliab::modelData()
{
    return d.data();
}

const TModelObject *EqpPartNoReliab::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const EqpPartNoReliab &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, EqpPartNoReliab &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(EqpPartNoReliab)
