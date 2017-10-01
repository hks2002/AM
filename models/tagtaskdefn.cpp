#include <TreeFrogModel>
#include "tagtaskdefn.h"
#include "tagtaskdefnobject.h"
#include "taskdefn.h"
#include "tagtag.h"

TagTaskDefn::TagTaskDefn()
    : TAbstractModel(), d(new TagTaskDefnObject())
{
    d->tag_id = 0;
    d->task_defn_id = 0;
}

TagTaskDefn::TagTaskDefn(const TagTaskDefn &other)
    : TAbstractModel(), d(new TagTaskDefnObject(*other.d))
{ }

TagTaskDefn::TagTaskDefn(const TagTaskDefnObject &object)
    : TAbstractModel(), d(new TagTaskDefnObject(object))
{ }

TagTaskDefn::~TagTaskDefn()
{
    // If the reference count becomes 0,
    // the shared data object 'TagTaskDefnObject' is deleted.
}

int TagTaskDefn::tagId() const
{
    return d->tag_id;
}

void TagTaskDefn::setTagId(int tagId)
{
    d->tag_id = tagId;
}

int TagTaskDefn::taskDefnId() const
{
    return d->task_defn_id;
}

void TagTaskDefn::setTaskDefnId(int taskDefnId)
{
    d->task_defn_id = taskDefnId;
}

QDateTime TagTaskDefn::createdAt() const
{
    return d->created_at;
}

QString TagTaskDefn::createdBy() const
{
    return d->created_by;
}

void TagTaskDefn::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime TagTaskDefn::updatedAt() const
{
    return d->updated_at;
}

QString TagTaskDefn::updatedBy() const
{
    return d->updated_by;
}

void TagTaskDefn::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

TaskDefn TagTaskDefn::taskDefnBytaskDefnId() const
{
 return TaskDefn::get(d->task_defn_id);
}

TagTag TagTaskDefn::tagTagBytagId() const
{
 return TagTag::get(d->tag_id);
}

TagTaskDefn &TagTaskDefn::operator=(const TagTaskDefn &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

TagTaskDefn TagTaskDefn::create(int tagId, int taskDefnId, const QString &createdBy, const QString &updatedBy)
{
    TagTaskDefnObject obj;
    obj.tag_id = tagId;
    obj.task_defn_id = taskDefnId;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return TagTaskDefn();
    }
    return TagTaskDefn(obj);
}

TagTaskDefn TagTaskDefn::create(const QVariantMap &values)
{
    TagTaskDefn model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

TagTaskDefn TagTaskDefn::get(int tagId, int taskDefnId)
{
    TSqlORMapper<TagTaskDefnObject> mapper;
    return TagTaskDefn(mapper.findByPrimaryKey(QVariantList()<<QVariant(tagId)<<QVariant(taskDefnId)));
}

int TagTaskDefn::count()
{
    TSqlORMapper<TagTaskDefnObject> mapper;
    return mapper.findCount();
}

QList<TagTaskDefn> TagTaskDefn::getAll()
{
    return tfGetModelListByCriteria<TagTaskDefn, TagTaskDefnObject>();
}

TModelObject *TagTaskDefn::modelData()
{
    return d.data();
}

const TModelObject *TagTaskDefn::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const TagTaskDefn &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, TagTaskDefn &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(TagTaskDefn)
