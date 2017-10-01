#include <TreeFrogModel>
#include "tagtag.h"
#include "tagtagobject.h"

TagTag::TagTag()
    : TAbstractModel(), d(new TagTagObject())
{
    d->tag_id = 0;
}

TagTag::TagTag(const TagTag &other)
    : TAbstractModel(), d(new TagTagObject(*other.d))
{ }

TagTag::TagTag(const TagTagObject &object)
    : TAbstractModel(), d(new TagTagObject(object))
{ }

TagTag::~TagTag()
{
    // If the reference count becomes 0,
    // the shared data object 'TagTagObject' is deleted.
}

int TagTag::tagId() const
{
    return d->tag_id;
}

QString TagTag::tagCd() const
{
    return d->tag_cd;
}

void TagTag::setTagCd(const QString &tagCd)
{
    d->tag_cd = tagCd;
}

QString TagTag::tagDesc() const
{
    return d->tag_desc;
}

void TagTag::setTagDesc(const QString &tagDesc)
{
    d->tag_desc = tagDesc;
}

QDateTime TagTag::createdAt() const
{
    return d->created_at;
}

QString TagTag::createdBy() const
{
    return d->created_by;
}

void TagTag::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime TagTag::updatedAt() const
{
    return d->updated_at;
}

QString TagTag::updatedBy() const
{
    return d->updated_by;
}

void TagTag::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

TagTag &TagTag::operator=(const TagTag &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

TagTag TagTag::create(const QString &tagCd, const QString &tagDesc, const QString &createdBy, const QString &updatedBy)
{
    TagTagObject obj;
    obj.tag_cd = tagCd;
    obj.tag_desc = tagDesc;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return TagTag();
    }
    return TagTag(obj);
}

TagTag TagTag::create(const QVariantMap &values)
{
    TagTag model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

TagTag TagTag::get(int tagId)
{
    TSqlORMapper<TagTagObject> mapper;
    return TagTag(mapper.findByPrimaryKey(tagId));
}

int TagTag::count()
{
    TSqlORMapper<TagTagObject> mapper;
    return mapper.findCount();
}

QList<TagTag> TagTag::getAll()
{
    return tfGetModelListByCriteria<TagTag, TagTagObject>();
}

TModelObject *TagTag::modelData()
{
    return d.data();
}

const TModelObject *TagTag::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const TagTag &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, TagTag &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(TagTag)
