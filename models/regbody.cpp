#include <TreeFrogModel>
#include "regbody.h"
#include "regbodyobject.h"

RegBody::RegBody()
    : TAbstractModel(), d(new RegBodyObject())
{
    d->reg_body_id = 0;
}

RegBody::RegBody(const RegBody &other)
    : TAbstractModel(), d(new RegBodyObject(*other.d))
{ }

RegBody::RegBody(const RegBodyObject &object)
    : TAbstractModel(), d(new RegBodyObject(object))
{ }

RegBody::~RegBody()
{
    // If the reference count becomes 0,
    // the shared data object 'RegBodyObject' is deleted.
}

int RegBody::regBodyId() const
{
    return d->reg_body_id;
}

QString RegBody::regBodyCd() const
{
    return d->reg_body_cd;
}

void RegBody::setRegBodyCd(const QString &regBodyCd)
{
    d->reg_body_cd = regBodyCd;
}

QString RegBody::regBodyNameZh() const
{
    return d->reg_body_name_zh;
}

void RegBody::setRegBodyNameZh(const QString &regBodyNameZh)
{
    d->reg_body_name_zh = regBodyNameZh;
}

QString RegBody::regBodyNameEn() const
{
    return d->reg_body_name_en;
}

void RegBody::setRegBodyNameEn(const QString &regBodyNameEn)
{
    d->reg_body_name_en = regBodyNameEn;
}

QDateTime RegBody::createdAt() const
{
    return d->created_at;
}

QString RegBody::createdBy() const
{
    return d->created_by;
}

void RegBody::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime RegBody::updatedAt() const
{
    return d->updated_at;
}

QString RegBody::updatedBy() const
{
    return d->updated_by;
}

void RegBody::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

RegBody &RegBody::operator=(const RegBody &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

RegBody RegBody::create(const QString &regBodyCd, const QString &regBodyNameZh, const QString &regBodyNameEn, const QString &createdBy, const QString &updatedBy)
{
    RegBodyObject obj;
    obj.reg_body_cd = regBodyCd;
    obj.reg_body_name_zh = regBodyNameZh;
    obj.reg_body_name_en = regBodyNameEn;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return RegBody();
    }
    return RegBody(obj);
}

RegBody RegBody::create(const QVariantMap &values)
{
    RegBody model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

RegBody RegBody::get(int regBodyId)
{
    TSqlORMapper<RegBodyObject> mapper;
    return RegBody(mapper.findByPrimaryKey(regBodyId));
}

int RegBody::count()
{
    TSqlORMapper<RegBodyObject> mapper;
    return mapper.findCount();
}

QList<RegBody> RegBody::getAll()
{
    return tfGetModelListByCriteria<RegBody, RegBodyObject>();
}

TModelObject *RegBody::modelData()
{
    return d.data();
}

const TModelObject *RegBody::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const RegBody &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, RegBody &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(RegBody)
