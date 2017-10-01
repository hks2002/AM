#include <TreeFrogModel>
#include "labourskill.h"
#include "labourskillobject.h"

LabourSkill::LabourSkill()
    : TAbstractModel(), d(new LabourSkillObject())
{
    d->labour_skill_id = 0;
}

LabourSkill::LabourSkill(const LabourSkill &other)
    : TAbstractModel(), d(new LabourSkillObject(*other.d))
{ }

LabourSkill::LabourSkill(const LabourSkillObject &object)
    : TAbstractModel(), d(new LabourSkillObject(object))
{ }

LabourSkill::~LabourSkill()
{
    // If the reference count becomes 0,
    // the shared data object 'LabourSkillObject' is deleted.
}

int LabourSkill::labourSkillId() const
{
    return d->labour_skill_id;
}

QString LabourSkill::labourSkillCd() const
{
    return d->labour_skill_cd;
}

void LabourSkill::setLabourSkillCd(const QString &labourSkillCd)
{
    d->labour_skill_cd = labourSkillCd;
}

QString LabourSkill::labourSkillNameZh() const
{
    return d->labour_skill_name_zh;
}

void LabourSkill::setLabourSkillNameZh(const QString &labourSkillNameZh)
{
    d->labour_skill_name_zh = labourSkillNameZh;
}

QString LabourSkill::labourSkillNameEn() const
{
    return d->labour_skill_name_en;
}

void LabourSkill::setLabourSkillNameEn(const QString &labourSkillNameEn)
{
    d->labour_skill_name_en = labourSkillNameEn;
}

QDateTime LabourSkill::createdAt() const
{
    return d->created_at;
}

QString LabourSkill::createdBy() const
{
    return d->created_by;
}

void LabourSkill::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime LabourSkill::updatedAt() const
{
    return d->updated_at;
}

QString LabourSkill::updatedBy() const
{
    return d->updated_by;
}

void LabourSkill::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

LabourSkill &LabourSkill::operator=(const LabourSkill &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

LabourSkill LabourSkill::create(const QString &labourSkillCd, const QString &labourSkillNameZh, const QString &labourSkillNameEn, const QString &createdBy, const QString &updatedBy)
{
    LabourSkillObject obj;
    obj.labour_skill_cd = labourSkillCd;
    obj.labour_skill_name_zh = labourSkillNameZh;
    obj.labour_skill_name_en = labourSkillNameEn;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return LabourSkill();
    }
    return LabourSkill(obj);
}

LabourSkill LabourSkill::create(const QVariantMap &values)
{
    LabourSkill model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

LabourSkill LabourSkill::get(int labourSkillId)
{
    TSqlORMapper<LabourSkillObject> mapper;
    return LabourSkill(mapper.findByPrimaryKey(labourSkillId));
}

int LabourSkill::count()
{
    TSqlORMapper<LabourSkillObject> mapper;
    return mapper.findCount();
}

QList<LabourSkill> LabourSkill::getAll()
{
    return tfGetModelListByCriteria<LabourSkill, LabourSkillObject>();
}

TModelObject *LabourSkill::modelData()
{
    return d.data();
}

const TModelObject *LabourSkill::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const LabourSkill &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, LabourSkill &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(LabourSkill)
