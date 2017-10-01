#include <TreeFrogModel>
#include "licenseprerequisite.h"
#include "licenseprerequisiteobject.h"
#include "labourskill.h"

LicensePrerequisite::LicensePrerequisite()
    : TAbstractModel(), d(new LicensePrerequisiteObject())
{
    d->license_id = 0;
    d->labour_skill_id = 0;
}

LicensePrerequisite::LicensePrerequisite(const LicensePrerequisite &other)
    : TAbstractModel(), d(new LicensePrerequisiteObject(*other.d))
{ }

LicensePrerequisite::LicensePrerequisite(const LicensePrerequisiteObject &object)
    : TAbstractModel(), d(new LicensePrerequisiteObject(object))
{ }

LicensePrerequisite::~LicensePrerequisite()
{
    // If the reference count becomes 0,
    // the shared data object 'LicensePrerequisiteObject' is deleted.
}

int LicensePrerequisite::licenseId() const
{
    return d->license_id;
}

void LicensePrerequisite::setLicenseId(int licenseId)
{
    d->license_id = licenseId;
}

int LicensePrerequisite::labourSkillId() const
{
    return d->labour_skill_id;
}

void LicensePrerequisite::setLabourSkillId(int labourSkillId)
{
    d->labour_skill_id = labourSkillId;
}

QDateTime LicensePrerequisite::createdAt() const
{
    return d->created_at;
}

QString LicensePrerequisite::createdBy() const
{
    return d->created_by;
}

void LicensePrerequisite::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime LicensePrerequisite::updatedAt() const
{
    return d->updated_at;
}

QString LicensePrerequisite::updatedBy() const
{
    return d->updated_by;
}

void LicensePrerequisite::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

LabourSkill LicensePrerequisite::labourSkillBylabourSkillId() const
{
 return LabourSkill::get(d->labour_skill_id);
}

LicensePrerequisite &LicensePrerequisite::operator=(const LicensePrerequisite &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

LicensePrerequisite LicensePrerequisite::create(int licenseId, int labourSkillId, const QString &createdBy, const QString &updatedBy)
{
    LicensePrerequisiteObject obj;
    obj.license_id = licenseId;
    obj.labour_skill_id = labourSkillId;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return LicensePrerequisite();
    }
    return LicensePrerequisite(obj);
}

LicensePrerequisite LicensePrerequisite::create(const QVariantMap &values)
{
    LicensePrerequisite model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

LicensePrerequisite LicensePrerequisite::get(int licenseId, int labourSkillId)
{
    TSqlORMapper<LicensePrerequisiteObject> mapper;
    return LicensePrerequisite(mapper.findByPrimaryKey(QVariantList()<<QVariant(licenseId)<<QVariant(labourSkillId)));
}

int LicensePrerequisite::count()
{
    TSqlORMapper<LicensePrerequisiteObject> mapper;
    return mapper.findCount();
}

QList<LicensePrerequisite> LicensePrerequisite::getAll()
{
    return tfGetModelListByCriteria<LicensePrerequisite, LicensePrerequisiteObject>();
}

TModelObject *LicensePrerequisite::modelData()
{
    return d.data();
}

const TModelObject *LicensePrerequisite::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const LicensePrerequisite &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, LicensePrerequisite &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(LicensePrerequisite)
