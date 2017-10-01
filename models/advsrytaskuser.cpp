#include <TreeFrogModel>
#include "advsrytaskuser.h"
#include "advsrytaskuserobject.h"
#include "userapp.h"
#include "advsrytask.h"

AdvsryTaskUser::AdvsryTaskUser()
    : TAbstractModel(), d(new AdvsryTaskUserObject())
{
    d->advsry_task_id = 0;
    d->user_id = 0;
}

AdvsryTaskUser::AdvsryTaskUser(const AdvsryTaskUser &other)
    : TAbstractModel(), d(new AdvsryTaskUserObject(*other.d))
{ }

AdvsryTaskUser::AdvsryTaskUser(const AdvsryTaskUserObject &object)
    : TAbstractModel(), d(new AdvsryTaskUserObject(object))
{ }

AdvsryTaskUser::~AdvsryTaskUser()
{
    // If the reference count becomes 0,
    // the shared data object 'AdvsryTaskUserObject' is deleted.
}

int AdvsryTaskUser::advsryTaskId() const
{
    return d->advsry_task_id;
}

void AdvsryTaskUser::setAdvsryTaskId(int advsryTaskId)
{
    d->advsry_task_id = advsryTaskId;
}

int AdvsryTaskUser::userId() const
{
    return d->user_id;
}

void AdvsryTaskUser::setUserId(int userId)
{
    d->user_id = userId;
}

QDateTime AdvsryTaskUser::createdAt() const
{
    return d->created_at;
}

QString AdvsryTaskUser::createdBy() const
{
    return d->created_by;
}

void AdvsryTaskUser::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime AdvsryTaskUser::updatedAt() const
{
    return d->updated_at;
}

QString AdvsryTaskUser::updatedBy() const
{
    return d->updated_by;
}

void AdvsryTaskUser::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

UserApp AdvsryTaskUser::userAppByuserId() const
{
 return UserApp::get(d->user_id);
}

AdvsryTask AdvsryTaskUser::advsryTaskByadvsryTaskId() const
{
 return AdvsryTask::get(d->advsry_task_id);
}

AdvsryTaskUser &AdvsryTaskUser::operator=(const AdvsryTaskUser &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

AdvsryTaskUser AdvsryTaskUser::create(int advsryTaskId, int userId, const QString &createdBy, const QString &updatedBy)
{
    AdvsryTaskUserObject obj;
    obj.advsry_task_id = advsryTaskId;
    obj.user_id = userId;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return AdvsryTaskUser();
    }
    return AdvsryTaskUser(obj);
}

AdvsryTaskUser AdvsryTaskUser::create(const QVariantMap &values)
{
    AdvsryTaskUser model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

AdvsryTaskUser AdvsryTaskUser::get(int advsryTaskId, int userId)
{
    TSqlORMapper<AdvsryTaskUserObject> mapper;
    return AdvsryTaskUser(mapper.findByPrimaryKey(QVariantList()<<QVariant(advsryTaskId)<<QVariant(userId)));
}

int AdvsryTaskUser::count()
{
    TSqlORMapper<AdvsryTaskUserObject> mapper;
    return mapper.findCount();
}

QList<AdvsryTaskUser> AdvsryTaskUser::getAll()
{
    return tfGetModelListByCriteria<AdvsryTaskUser, AdvsryTaskUserObject>();
}

TModelObject *AdvsryTaskUser::modelData()
{
    return d.data();
}

const TModelObject *AdvsryTaskUser::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const AdvsryTaskUser &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, AdvsryTaskUser &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(AdvsryTaskUser)
