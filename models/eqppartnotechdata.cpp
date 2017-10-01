#include <TreeFrogModel>
#include "eqppartnotechdata.h"
#include "eqppartnotechdataobject.h"
#include "refmesurtype.h"
#include "mesurunit.h"
#include "eqppartno.h"

EqpPartNoTechData::EqpPartNoTechData()
    : TAbstractModel(), d(new EqpPartNoTechDataObject())
{
    d->part_no_id = 0;
    d->mesur_unit_id = 0;
    d->mesur_qt = 0;
}

EqpPartNoTechData::EqpPartNoTechData(const EqpPartNoTechData &other)
    : TAbstractModel(), d(new EqpPartNoTechDataObject(*other.d))
{ }

EqpPartNoTechData::EqpPartNoTechData(const EqpPartNoTechDataObject &object)
    : TAbstractModel(), d(new EqpPartNoTechDataObject(object))
{ }

EqpPartNoTechData::~EqpPartNoTechData()
{
    // If the reference count becomes 0,
    // the shared data object 'EqpPartNoTechDataObject' is deleted.
}

int EqpPartNoTechData::partNoId() const
{
    return d->part_no_id;
}

void EqpPartNoTechData::setPartNoId(int partNoId)
{
    d->part_no_id = partNoId;
}

int EqpPartNoTechData::mesurUnitId() const
{
    return d->mesur_unit_id;
}

void EqpPartNoTechData::setMesurUnitId(int mesurUnitId)
{
    d->mesur_unit_id = mesurUnitId;
}

QString EqpPartNoTechData::mesurTypeCd() const
{
    return d->mesur_type_cd;
}

void EqpPartNoTechData::setMesurTypeCd(const QString &mesurTypeCd)
{
    d->mesur_type_cd = mesurTypeCd;
}

double EqpPartNoTechData::mesurQt() const
{
    return d->mesur_qt;
}

void EqpPartNoTechData::setMesurQt(double mesurQt)
{
    d->mesur_qt = mesurQt;
}

QDateTime EqpPartNoTechData::createdAt() const
{
    return d->created_at;
}

QString EqpPartNoTechData::createdBy() const
{
    return d->created_by;
}

void EqpPartNoTechData::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime EqpPartNoTechData::updatedAt() const
{
    return d->updated_at;
}

QString EqpPartNoTechData::updatedBy() const
{
    return d->updated_by;
}

void EqpPartNoTechData::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

RefMesurType EqpPartNoTechData::refMesurTypeBymesurTypeCd() const
{
 return RefMesurType::get(d->mesur_type_cd);
}

MesurUnit EqpPartNoTechData::mesurUnitBymesurUnitId() const
{
 return MesurUnit::get(d->mesur_unit_id);
}

EqpPartNo EqpPartNoTechData::eqpPartNoBypartNoId() const
{
 return EqpPartNo::get(d->part_no_id);
}

EqpPartNoTechData &EqpPartNoTechData::operator=(const EqpPartNoTechData &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

EqpPartNoTechData EqpPartNoTechData::create(int partNoId, int mesurUnitId, const QString &mesurTypeCd, double mesurQt, const QString &createdBy, const QString &updatedBy)
{
    EqpPartNoTechDataObject obj;
    obj.part_no_id = partNoId;
    obj.mesur_unit_id = mesurUnitId;
    obj.mesur_type_cd = mesurTypeCd;
    obj.mesur_qt = mesurQt;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return EqpPartNoTechData();
    }
    return EqpPartNoTechData(obj);
}

EqpPartNoTechData EqpPartNoTechData::create(const QVariantMap &values)
{
    EqpPartNoTechData model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

EqpPartNoTechData EqpPartNoTechData::get(int partNoId, int mesurUnitId, const QString &mesurTypeCd)
{
    TSqlORMapper<EqpPartNoTechDataObject> mapper;
    return EqpPartNoTechData(mapper.findByPrimaryKey(QVariantList()<<QVariant(partNoId)<<QVariant(mesurUnitId)<<QVariant(mesurTypeCd)));
}

int EqpPartNoTechData::count()
{
    TSqlORMapper<EqpPartNoTechDataObject> mapper;
    return mapper.findCount();
}

QList<EqpPartNoTechData> EqpPartNoTechData::getAll()
{
    return tfGetModelListByCriteria<EqpPartNoTechData, EqpPartNoTechDataObject>();
}

TModelObject *EqpPartNoTechData::modelData()
{
    return d.data();
}

const TModelObject *EqpPartNoTechData::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const EqpPartNoTechData &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, EqpPartNoTechData &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(EqpPartNoTechData)
