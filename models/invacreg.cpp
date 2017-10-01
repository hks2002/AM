#include <TreeFrogModel>
#include "invacreg.h"
#include "invacregobject.h"
#include "fcmodel.h"
#include "country.h"
#include "regbody.h"
#include "org.h"
#include "invinv.h"

InvAcReg::InvAcReg()
    : TAbstractModel(), d(new InvAcRegObject())
{
    d->inv_no_id = 0;
    d->org_id = 0;
    d->reg_body_id = 0;
    d->country_id = 0;
    d->fc_model_id = 0;
}

InvAcReg::InvAcReg(const InvAcReg &other)
    : TAbstractModel(), d(new InvAcRegObject(*other.d))
{ }

InvAcReg::InvAcReg(const InvAcRegObject &object)
    : TAbstractModel(), d(new InvAcRegObject(object))
{ }

InvAcReg::~InvAcReg()
{
    // If the reference count becomes 0,
    // the shared data object 'InvAcRegObject' is deleted.
}

int InvAcReg::invNoId() const
{
    return d->inv_no_id;
}

void InvAcReg::setInvNoId(int invNoId)
{
    d->inv_no_id = invNoId;
}

int InvAcReg::orgId() const
{
    return d->org_id;
}

void InvAcReg::setOrgId(int orgId)
{
    d->org_id = orgId;
}

int InvAcReg::regBodyId() const
{
    return d->reg_body_id;
}

void InvAcReg::setRegBodyId(int regBodyId)
{
    d->reg_body_id = regBodyId;
}

int InvAcReg::countryId() const
{
    return d->country_id;
}

void InvAcReg::setCountryId(int countryId)
{
    d->country_id = countryId;
}

int InvAcReg::fcModelId() const
{
    return d->fc_model_id;
}

void InvAcReg::setFcModelId(int fcModelId)
{
    d->fc_model_id = fcModelId;
}

QString InvAcReg::acRegCd() const
{
    return d->ac_reg_cd;
}

void InvAcReg::setAcRegCd(const QString &acRegCd)
{
    d->ac_reg_cd = acRegCd;
}

QString InvAcReg::airworthCd() const
{
    return d->airworth_cd;
}

void InvAcReg::setAirworthCd(const QString &airworthCd)
{
    d->airworth_cd = airworthCd;
}

bool InvAcReg::privateBool() const
{
    return d->private_bool;
}

void InvAcReg::setPrivateBool(bool privateBool)
{
    d->private_bool = privateBool;
}

QString InvAcReg::varNoOem() const
{
    return d->var_no_oem;
}

void InvAcReg::setVarNoOem(const QString &varNoOem)
{
    d->var_no_oem = varNoOem;
}

QString InvAcReg::lineNoOem() const
{
    return d->line_no_oem;
}

void InvAcReg::setLineNoOem(const QString &lineNoOem)
{
    d->line_no_oem = lineNoOem;
}

QString InvAcReg::finNoCd() const
{
    return d->fin_no_cd;
}

void InvAcReg::setFinNoCd(const QString &finNoCd)
{
    d->fin_no_cd = finNoCd;
}

QDateTime InvAcReg::createdAt() const
{
    return d->created_at;
}

QString InvAcReg::createdBy() const
{
    return d->created_by;
}

void InvAcReg::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime InvAcReg::updatedAt() const
{
    return d->updated_at;
}

QString InvAcReg::updatedBy() const
{
    return d->updated_by;
}

void InvAcReg::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

FcModel InvAcReg::fcModelByfcModelId() const
{
 return FcModel::get(d->fc_model_id);
}

Country InvAcReg::countryBycountryId() const
{
 return Country::get(d->country_id);
}

RegBody InvAcReg::regBodyByregBodyId() const
{
 return RegBody::get(d->reg_body_id);
}

Org InvAcReg::orgByorgId() const
{
 return Org::get(d->org_id);
}

InvInv InvAcReg::invInvByinvNoId() const
{
 return InvInv::get(d->inv_no_id);
}

InvAcReg &InvAcReg::operator=(const InvAcReg &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

InvAcReg InvAcReg::create(int invNoId, int orgId, int regBodyId, int countryId, int fcModelId, const QString &acRegCd, const QString &airworthCd, bool privateBool, const QString &varNoOem, const QString &lineNoOem, const QString &finNoCd, const QString &createdBy, const QString &updatedBy)
{
    InvAcRegObject obj;
    obj.inv_no_id = invNoId;
    obj.org_id = orgId;
    obj.reg_body_id = regBodyId;
    obj.country_id = countryId;
    obj.fc_model_id = fcModelId;
    obj.ac_reg_cd = acRegCd;
    obj.airworth_cd = airworthCd;
    obj.private_bool = privateBool;
    obj.var_no_oem = varNoOem;
    obj.line_no_oem = lineNoOem;
    obj.fin_no_cd = finNoCd;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return InvAcReg();
    }
    return InvAcReg(obj);
}

InvAcReg InvAcReg::create(const QVariantMap &values)
{
    InvAcReg model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

InvAcReg InvAcReg::get(int invNoId)
{
    TSqlORMapper<InvAcRegObject> mapper;
    return InvAcReg(mapper.findByPrimaryKey(invNoId));
}

int InvAcReg::count()
{
    TSqlORMapper<InvAcRegObject> mapper;
    return mapper.findCount();
}

QList<InvAcReg> InvAcReg::getAll()
{
    return tfGetModelListByCriteria<InvAcReg, InvAcRegObject>();
}

TModelObject *InvAcReg::modelData()
{
    return d.data();
}

const TModelObject *InvAcReg::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const InvAcReg &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, InvAcReg &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(InvAcReg)
