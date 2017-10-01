#include <TreeFrogModel>
#include "eqpassmblbom.h"
#include "eqpassmblbomobject.h"
#include "refbomclass.h"
#include "eqpassmbl.h"

EqpAssmblBom::EqpAssmblBom()
    : TAbstractModel(), d(new EqpAssmblBomObject())
{
    d->assmbl_bom_id = 0;
    d->assmbl_id = 0;
    d->pos_ct = 0;
}

EqpAssmblBom::EqpAssmblBom(const EqpAssmblBom &other)
    : TAbstractModel(), d(new EqpAssmblBomObject(*other.d))
{ }

EqpAssmblBom::EqpAssmblBom(const EqpAssmblBomObject &object)
    : TAbstractModel(), d(new EqpAssmblBomObject(object))
{ }

EqpAssmblBom::~EqpAssmblBom()
{
    // If the reference count becomes 0,
    // the shared data object 'EqpAssmblBomObject' is deleted.
}

int EqpAssmblBom::assmblBomId() const
{
    return d->assmbl_bom_id;
}

int EqpAssmblBom::assmblId() const
{
    return d->assmbl_id;
}

void EqpAssmblBom::setAssmblId(int assmblId)
{
    d->assmbl_id = assmblId;
}

QString EqpAssmblBom::assmblBomCd() const
{
    return d->assmbl_bom_cd;
}

void EqpAssmblBom::setAssmblBomCd(const QString &assmblBomCd)
{
    d->assmbl_bom_cd = assmblBomCd;
}

QString EqpAssmblBom::assmblBomName() const
{
    return d->assmbl_bom_name;
}

void EqpAssmblBom::setAssmblBomName(const QString &assmblBomName)
{
    d->assmbl_bom_name = assmblBomName;
}

QString EqpAssmblBom::bomClassCd() const
{
    return d->bom_class_cd;
}

void EqpAssmblBom::setBomClassCd(const QString &bomClassCd)
{
    d->bom_class_cd = bomClassCd;
}

bool EqpAssmblBom::mandatoryBool() const
{
    return d->mandatory_bool;
}

void EqpAssmblBom::setMandatoryBool(bool mandatoryBool)
{
    d->mandatory_bool = mandatoryBool;
}

bool EqpAssmblBom::softwareBool() const
{
    return d->software_bool;
}

void EqpAssmblBom::setSoftwareBool(bool softwareBool)
{
    d->software_bool = softwareBool;
}

int EqpAssmblBom::posCt() const
{
    return d->pos_ct;
}

void EqpAssmblBom::setPosCt(int posCt)
{
    d->pos_ct = posCt;
}

bool EqpAssmblBom::mustSpecialPartNo() const
{
    return d->must_special_part_no;
}

void EqpAssmblBom::setMustSpecialPartNo(bool mustSpecialPartNo)
{
    d->must_special_part_no = mustSpecialPartNo;
}

QString EqpAssmblBom::applDesc() const
{
    return d->appl_desc;
}

void EqpAssmblBom::setApplDesc(const QString &applDesc)
{
    d->appl_desc = applDesc;
}

QString EqpAssmblBom::applEffDesc() const
{
    return d->appl_eff_desc;
}

void EqpAssmblBom::setApplEffDesc(const QString &applEffDesc)
{
    d->appl_eff_desc = applEffDesc;
}

QString EqpAssmblBom::applSqlDesc() const
{
    return d->appl_sql_desc;
}

void EqpAssmblBom::setApplSqlDesc(const QString &applSqlDesc)
{
    d->appl_sql_desc = applSqlDesc;
}

QDateTime EqpAssmblBom::createdAt() const
{
    return d->created_at;
}

QString EqpAssmblBom::createdBy() const
{
    return d->created_by;
}

void EqpAssmblBom::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime EqpAssmblBom::updatedAt() const
{
    return d->updated_at;
}

QString EqpAssmblBom::updatedBy() const
{
    return d->updated_by;
}

void EqpAssmblBom::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

RefBomClass EqpAssmblBom::refBomClassBybomClassCd() const
{
 return RefBomClass::get(d->bom_class_cd);
}

EqpAssmbl EqpAssmblBom::eqpAssmblByassmblId() const
{
 return EqpAssmbl::get(d->assmbl_id);
}

EqpAssmblBom &EqpAssmblBom::operator=(const EqpAssmblBom &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

EqpAssmblBom EqpAssmblBom::create(int assmblId, const QString &assmblBomCd, const QString &assmblBomName, const QString &bomClassCd, bool mandatoryBool, bool softwareBool, int posCt, bool mustSpecialPartNo, const QString &applDesc, const QString &applEffDesc, const QString &applSqlDesc, const QString &createdBy, const QString &updatedBy)
{
    EqpAssmblBomObject obj;
    obj.assmbl_id = assmblId;
    obj.assmbl_bom_cd = assmblBomCd;
    obj.assmbl_bom_name = assmblBomName;
    obj.bom_class_cd = bomClassCd;
    obj.mandatory_bool = mandatoryBool;
    obj.software_bool = softwareBool;
    obj.pos_ct = posCt;
    obj.must_special_part_no = mustSpecialPartNo;
    obj.appl_desc = applDesc;
    obj.appl_eff_desc = applEffDesc;
    obj.appl_sql_desc = applSqlDesc;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return EqpAssmblBom();
    }
    return EqpAssmblBom(obj);
}

EqpAssmblBom EqpAssmblBom::create(const QVariantMap &values)
{
    EqpAssmblBom model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

EqpAssmblBom EqpAssmblBom::get(int assmblBomId)
{
    TSqlORMapper<EqpAssmblBomObject> mapper;
    return EqpAssmblBom(mapper.findByPrimaryKey(assmblBomId));
}

int EqpAssmblBom::count()
{
    TSqlORMapper<EqpAssmblBomObject> mapper;
    return mapper.findCount();
}

QList<EqpAssmblBom> EqpAssmblBom::getAll()
{
    return tfGetModelListByCriteria<EqpAssmblBom, EqpAssmblBomObject>();
}

TModelObject *EqpAssmblBom::modelData()
{
    return d.data();
}

const TModelObject *EqpAssmblBom::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const EqpAssmblBom &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, EqpAssmblBom &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(EqpAssmblBom)
