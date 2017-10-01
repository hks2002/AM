#include <TreeFrogModel>
#include "reffailsev.h"
#include "reffailsevobject.h"

RefFailSev::RefFailSev()
    : TAbstractModel(), d(new RefFailSevObject())
{ }

RefFailSev::RefFailSev(const RefFailSev &other)
    : TAbstractModel(), d(new RefFailSevObject(*other.d))
{ }

RefFailSev::RefFailSev(const RefFailSevObject &object)
    : TAbstractModel(), d(new RefFailSevObject(object))
{ }

RefFailSev::~RefFailSev()
{
    // If the reference count becomes 0,
    // the shared data object 'RefFailSevObject' is deleted.
}

QString RefFailSev::failSevCd() const
{
    return d->fail_sev_cd;
}

void RefFailSev::setFailSevCd(const QString &failSevCd)
{
    d->fail_sev_cd = failSevCd;
}

QString RefFailSev::failSevNameEn() const
{
    return d->fail_sev_name_en;
}

void RefFailSev::setFailSevNameEn(const QString &failSevNameEn)
{
    d->fail_sev_name_en = failSevNameEn;
}

QString RefFailSev::failSevNameZh() const
{
    return d->fail_sev_name_zh;
}

void RefFailSev::setFailSevNameZh(const QString &failSevNameZh)
{
    d->fail_sev_name_zh = failSevNameZh;
}

QString RefFailSev::failSevDesc() const
{
    return d->fail_sev_desc;
}

void RefFailSev::setFailSevDesc(const QString &failSevDesc)
{
    d->fail_sev_desc = failSevDesc;
}

QDateTime RefFailSev::createdAt() const
{
    return d->created_at;
}

QString RefFailSev::createdBy() const
{
    return d->created_by;
}

void RefFailSev::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime RefFailSev::updatedAt() const
{
    return d->updated_at;
}

QString RefFailSev::updatedBy() const
{
    return d->updated_by;
}

void RefFailSev::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

RefFailSev &RefFailSev::operator=(const RefFailSev &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

RefFailSev RefFailSev::create(const QString &failSevCd, const QString &failSevNameEn, const QString &failSevNameZh, const QString &failSevDesc, const QString &createdBy, const QString &updatedBy)
{
    RefFailSevObject obj;
    obj.fail_sev_cd = failSevCd;
    obj.fail_sev_name_en = failSevNameEn;
    obj.fail_sev_name_zh = failSevNameZh;
    obj.fail_sev_desc = failSevDesc;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return RefFailSev();
    }
    return RefFailSev(obj);
}

RefFailSev RefFailSev::create(const QVariantMap &values)
{
    RefFailSev model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

RefFailSev RefFailSev::get(const QString &failSevCd)
{
    TSqlORMapper<RefFailSevObject> mapper;
    return RefFailSev(mapper.findByPrimaryKey(failSevCd));
}

int RefFailSev::count()
{
    TSqlORMapper<RefFailSevObject> mapper;
    return mapper.findCount();
}

QList<RefFailSev> RefFailSev::getAll()
{
    return tfGetModelListByCriteria<RefFailSev, RefFailSevObject>();
}

TModelObject *RefFailSev::modelData()
{
    return d.data();
}

const TModelObject *RefFailSev::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const RefFailSev &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, RefFailSev &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(RefFailSev)
