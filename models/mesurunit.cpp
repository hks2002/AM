#include <TreeFrogModel>
#include "mesurunit.h"
#include "mesurunitobject.h"

MesurUnit::MesurUnit()
    : TAbstractModel(), d(new MesurUnitObject())
{
    d->mesur_unit_id = 0;
}

MesurUnit::MesurUnit(const MesurUnit &other)
    : TAbstractModel(), d(new MesurUnitObject(*other.d))
{ }

MesurUnit::MesurUnit(const MesurUnitObject &object)
    : TAbstractModel(), d(new MesurUnitObject(object))
{ }

MesurUnit::~MesurUnit()
{
    // If the reference count becomes 0,
    // the shared data object 'MesurUnitObject' is deleted.
}

int MesurUnit::mesurUnitId() const
{
    return d->mesur_unit_id;
}

QString MesurUnit::mesurUnitCd() const
{
    return d->mesur_unit_cd;
}

void MesurUnit::setMesurUnitCd(const QString &mesurUnitCd)
{
    d->mesur_unit_cd = mesurUnitCd;
}

QString MesurUnit::mesurUnitNameZh() const
{
    return d->mesur_unit_name_zh;
}

void MesurUnit::setMesurUnitNameZh(const QString &mesurUnitNameZh)
{
    d->mesur_unit_name_zh = mesurUnitNameZh;
}

QString MesurUnit::mesurUnitNameEn() const
{
    return d->mesur_unit_name_en;
}

void MesurUnit::setMesurUnitNameEn(const QString &mesurUnitNameEn)
{
    d->mesur_unit_name_en = mesurUnitNameEn;
}

QDateTime MesurUnit::createdAt() const
{
    return d->created_at;
}

QString MesurUnit::createdBy() const
{
    return d->created_by;
}

void MesurUnit::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime MesurUnit::updatedAt() const
{
    return d->updated_at;
}

QString MesurUnit::updatedBy() const
{
    return d->updated_by;
}

void MesurUnit::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

MesurUnit &MesurUnit::operator=(const MesurUnit &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

MesurUnit MesurUnit::create(const QString &mesurUnitCd, const QString &mesurUnitNameZh, const QString &mesurUnitNameEn, const QString &createdBy, const QString &updatedBy)
{
    MesurUnitObject obj;
    obj.mesur_unit_cd = mesurUnitCd;
    obj.mesur_unit_name_zh = mesurUnitNameZh;
    obj.mesur_unit_name_en = mesurUnitNameEn;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return MesurUnit();
    }
    return MesurUnit(obj);
}

MesurUnit MesurUnit::create(const QVariantMap &values)
{
    MesurUnit model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

MesurUnit MesurUnit::get(int mesurUnitId)
{
    TSqlORMapper<MesurUnitObject> mapper;
    return MesurUnit(mapper.findByPrimaryKey(mesurUnitId));
}

int MesurUnit::count()
{
    TSqlORMapper<MesurUnitObject> mapper;
    return mapper.findCount();
}

QList<MesurUnit> MesurUnit::getAll()
{
    return tfGetModelListByCriteria<MesurUnit, MesurUnitObject>();
}

TModelObject *MesurUnit::modelData()
{
    return d.data();
}

const TModelObject *MesurUnit::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const MesurUnit &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, MesurUnit &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(MesurUnit)
