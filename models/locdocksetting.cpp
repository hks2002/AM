#include <TreeFrogModel>
#include "locdocksetting.h"
#include "locdocksettingobject.h"
#include "loc.h"

LocDockSetting::LocDockSetting()
    : TAbstractModel(), d(new LocDockSettingObject())
{
    d->loc_id = 0;
}

LocDockSetting::LocDockSetting(const LocDockSetting &other)
    : TAbstractModel(), d(new LocDockSettingObject(*other.d))
{ }

LocDockSetting::LocDockSetting(const LocDockSettingObject &object)
    : TAbstractModel(), d(new LocDockSettingObject(object))
{ }

LocDockSetting::~LocDockSetting()
{
    // If the reference count becomes 0,
    // the shared data object 'LocDockSettingObject' is deleted.
}

int LocDockSetting::locId() const
{
    return d->loc_id;
}

void LocDockSetting::setLocId(int locId)
{
    d->loc_id = locId;
}

bool LocDockSetting::defaultDockBool() const
{
    return d->default_dock_bool;
}

void LocDockSetting::setDefaultDockBool(bool defaultDockBool)
{
    d->default_dock_bool = defaultDockBool;
}

QDateTime LocDockSetting::createdAt() const
{
    return d->created_at;
}

QString LocDockSetting::createdBy() const
{
    return d->created_by;
}

void LocDockSetting::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime LocDockSetting::updatedAt() const
{
    return d->updated_at;
}

QString LocDockSetting::updatedBy() const
{
    return d->updated_by;
}

void LocDockSetting::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

Loc LocDockSetting::locBylocId() const
{
 return Loc::get(d->loc_id);
}

LocDockSetting &LocDockSetting::operator=(const LocDockSetting &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

LocDockSetting LocDockSetting::create(int locId, bool defaultDockBool, const QString &createdBy, const QString &updatedBy)
{
    LocDockSettingObject obj;
    obj.loc_id = locId;
    obj.default_dock_bool = defaultDockBool;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return LocDockSetting();
    }
    return LocDockSetting(obj);
}

LocDockSetting LocDockSetting::create(const QVariantMap &values)
{
    LocDockSetting model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

LocDockSetting LocDockSetting::get(int locId)
{
    TSqlORMapper<LocDockSettingObject> mapper;
    return LocDockSetting(mapper.findByPrimaryKey(locId));
}

int LocDockSetting::count()
{
    TSqlORMapper<LocDockSettingObject> mapper;
    return mapper.findCount();
}

QList<LocDockSetting> LocDockSetting::getAll()
{
    return tfGetModelListByCriteria<LocDockSetting, LocDockSettingObject>();
}

TModelObject *LocDockSetting::modelData()
{
    return d.data();
}

const TModelObject *LocDockSetting::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const LocDockSetting &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, LocDockSetting &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(LocDockSetting)
