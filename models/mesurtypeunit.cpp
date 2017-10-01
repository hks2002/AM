#include <TreeFrogModel>
#include "mesurtypeunit.h"
#include "mesurtypeunitobject.h"
#include "mesurunit.h"
#include "refmesurtype.h"

MesurTypeUnit::MesurTypeUnit()
    : TAbstractModel(), d(new MesurTypeUnitObject())
{
    d->mesur_unit_id = 0;
}

MesurTypeUnit::MesurTypeUnit(const MesurTypeUnit &other)
    : TAbstractModel(), d(new MesurTypeUnitObject(*other.d))
{ }

MesurTypeUnit::MesurTypeUnit(const MesurTypeUnitObject &object)
    : TAbstractModel(), d(new MesurTypeUnitObject(object))
{ }

MesurTypeUnit::~MesurTypeUnit()
{
    // If the reference count becomes 0,
    // the shared data object 'MesurTypeUnitObject' is deleted.
}

QString MesurTypeUnit::mesurTypeCd() const
{
    return d->mesur_type_cd;
}

void MesurTypeUnit::setMesurTypeCd(const QString &mesurTypeCd)
{
    d->mesur_type_cd = mesurTypeCd;
}

int MesurTypeUnit::mesurUnitId() const
{
    return d->mesur_unit_id;
}

void MesurTypeUnit::setMesurUnitId(int mesurUnitId)
{
    d->mesur_unit_id = mesurUnitId;
}

QDateTime MesurTypeUnit::createdAt() const
{
    return d->created_at;
}

QString MesurTypeUnit::createdBy() const
{
    return d->created_by;
}

void MesurTypeUnit::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime MesurTypeUnit::updatedAt() const
{
    return d->updated_at;
}

QString MesurTypeUnit::updatedBy() const
{
    return d->updated_by;
}

void MesurTypeUnit::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

MesurUnit MesurTypeUnit::mesurUnitBymesurUnitId() const
{
 return MesurUnit::get(d->mesur_unit_id);
}

RefMesurType MesurTypeUnit::refMesurTypeBymesurTypeCd() const
{
 return RefMesurType::get(d->mesur_type_cd);
}

MesurTypeUnit &MesurTypeUnit::operator=(const MesurTypeUnit &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

MesurTypeUnit MesurTypeUnit::create(const QString &mesurTypeCd, int mesurUnitId, const QString &createdBy, const QString &updatedBy)
{
    MesurTypeUnitObject obj;
    obj.mesur_type_cd = mesurTypeCd;
    obj.mesur_unit_id = mesurUnitId;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return MesurTypeUnit();
    }
    return MesurTypeUnit(obj);
}

MesurTypeUnit MesurTypeUnit::create(const QVariantMap &values)
{
    MesurTypeUnit model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

MesurTypeUnit MesurTypeUnit::get(const QString &mesurTypeCd, int mesurUnitId)
{
    TSqlORMapper<MesurTypeUnitObject> mapper;
    return MesurTypeUnit(mapper.findByPrimaryKey(QVariantList()<<QVariant(mesurTypeCd)<<QVariant(mesurUnitId)));
}

int MesurTypeUnit::count()
{
    TSqlORMapper<MesurTypeUnitObject> mapper;
    return mapper.findCount();
}

QList<MesurTypeUnit> MesurTypeUnit::getAll()
{
    return tfGetModelListByCriteria<MesurTypeUnit, MesurTypeUnitObject>();
}

TModelObject *MesurTypeUnit::modelData()
{
    return d.data();
}

const TModelObject *MesurTypeUnit::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const MesurTypeUnit &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, MesurTypeUnit &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(MesurTypeUnit)
