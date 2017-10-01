#include <TreeFrogModel>
#include "loclinesetting.h"
#include "loclinesettingobject.h"
#include "loc.h"

LocLineSetting::LocLineSetting()
    : TAbstractModel(), d(new LocLineSettingObject())
{
    d->loc_id = 0;
    d->duration_buffer_qt = 0;
}

LocLineSetting::LocLineSetting(const LocLineSetting &other)
    : TAbstractModel(), d(new LocLineSettingObject(*other.d))
{ }

LocLineSetting::LocLineSetting(const LocLineSettingObject &object)
    : TAbstractModel(), d(new LocLineSettingObject(object))
{ }

LocLineSetting::~LocLineSetting()
{
    // If the reference count becomes 0,
    // the shared data object 'LocLineSettingObject' is deleted.
}

int LocLineSetting::locId() const
{
    return d->loc_id;
}

void LocLineSetting::setLocId(int locId)
{
    d->loc_id = locId;
}

QString LocLineSetting::minGroundTimeQt() const
{
    return d->min_ground_time_qt;
}

void LocLineSetting::setMinGroundTimeQt(const QString &minGroundTimeQt)
{
    d->min_ground_time_qt = minGroundTimeQt;
}

int LocLineSetting::durationBufferQt() const
{
    return d->duration_buffer_qt;
}

void LocLineSetting::setDurationBufferQt(int durationBufferQt)
{
    d->duration_buffer_qt = durationBufferQt;
}

QDateTime LocLineSetting::createdAt() const
{
    return d->created_at;
}

QString LocLineSetting::createdBy() const
{
    return d->created_by;
}

void LocLineSetting::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime LocLineSetting::updatedAt() const
{
    return d->updated_at;
}

QString LocLineSetting::updatedBy() const
{
    return d->updated_by;
}

void LocLineSetting::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

Loc LocLineSetting::locBylocId() const
{
 return Loc::get(d->loc_id);
}

LocLineSetting &LocLineSetting::operator=(const LocLineSetting &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

LocLineSetting LocLineSetting::create(int locId, const QString &minGroundTimeQt, int durationBufferQt, const QString &createdBy, const QString &updatedBy)
{
    LocLineSettingObject obj;
    obj.loc_id = locId;
    obj.min_ground_time_qt = minGroundTimeQt;
    obj.duration_buffer_qt = durationBufferQt;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return LocLineSetting();
    }
    return LocLineSetting(obj);
}

LocLineSetting LocLineSetting::create(const QVariantMap &values)
{
    LocLineSetting model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

LocLineSetting LocLineSetting::get(int locId)
{
    TSqlORMapper<LocLineSettingObject> mapper;
    return LocLineSetting(mapper.findByPrimaryKey(locId));
}

int LocLineSetting::count()
{
    TSqlORMapper<LocLineSettingObject> mapper;
    return mapper.findCount();
}

QList<LocLineSetting> LocLineSetting::getAll()
{
    return tfGetModelListByCriteria<LocLineSetting, LocLineSettingObject>();
}

TModelObject *LocLineSetting::modelData()
{
    return d.data();
}

const TModelObject *LocLineSetting::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const LocLineSetting &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, LocLineSetting &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(LocLineSetting)
