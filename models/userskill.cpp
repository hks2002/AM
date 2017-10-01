#include <TreeFrogModel>
#include "userskill.h"
#include "userskillobject.h"
#include "labourskill.h"
#include "userapp.h"

UserSkill::UserSkill()
    : TAbstractModel(), d(new UserSkillObject())
{
    d->user_id = 0;
    d->labour_skill_id = 0;
}

UserSkill::UserSkill(const UserSkill &other)
    : TAbstractModel(), d(new UserSkillObject(*other.d))
{ }

UserSkill::UserSkill(const UserSkillObject &object)
    : TAbstractModel(), d(new UserSkillObject(object))
{ }

UserSkill::~UserSkill()
{
    // If the reference count becomes 0,
    // the shared data object 'UserSkillObject' is deleted.
}

int UserSkill::userId() const
{
    return d->user_id;
}

void UserSkill::setUserId(int userId)
{
    d->user_id = userId;
}

int UserSkill::labourSkillId() const
{
    return d->labour_skill_id;
}

void UserSkill::setLabourSkillId(int labourSkillId)
{
    d->labour_skill_id = labourSkillId;
}

QDateTime UserSkill::createdAt() const
{
    return d->created_at;
}

QString UserSkill::createdBy() const
{
    return d->created_by;
}

void UserSkill::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime UserSkill::updatedAt() const
{
    return d->updated_at;
}

QString UserSkill::updatedBy() const
{
    return d->updated_by;
}

void UserSkill::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

LabourSkill UserSkill::labourSkillBylabourSkillId() const
{
 return LabourSkill::get(d->labour_skill_id);
}

UserApp UserSkill::userAppByuserId() const
{
 return UserApp::get(d->user_id);
}

UserSkill &UserSkill::operator=(const UserSkill &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

UserSkill UserSkill::create(int userId, int labourSkillId, const QString &createdBy, const QString &updatedBy)
{
    UserSkillObject obj;
    obj.user_id = userId;
    obj.labour_skill_id = labourSkillId;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return UserSkill();
    }
    return UserSkill(obj);
}

UserSkill UserSkill::create(const QVariantMap &values)
{
    UserSkill model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

UserSkill UserSkill::get(int userId, int labourSkillId)
{
    TSqlORMapper<UserSkillObject> mapper;
    return UserSkill(mapper.findByPrimaryKey(QVariantList()<<QVariant(userId)<<QVariant(labourSkillId)));
}

int UserSkill::count()
{
    TSqlORMapper<UserSkillObject> mapper;
    return mapper.findCount();
}

QList<UserSkill> UserSkill::getAll()
{
    return tfGetModelListByCriteria<UserSkill, UserSkillObject>();
}

TModelObject *UserSkill::modelData()
{
    return d.data();
}

const TModelObject *UserSkill::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const UserSkill &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, UserSkill &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(UserSkill)
