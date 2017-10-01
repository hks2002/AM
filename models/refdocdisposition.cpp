#include <TreeFrogModel>
#include "refdocdisposition.h"
#include "refdocdispositionobject.h"

RefDocDisposition::RefDocDisposition()
    : TAbstractModel(), d(new RefDocDispositionObject())
{ }

RefDocDisposition::RefDocDisposition(const RefDocDisposition &other)
    : TAbstractModel(), d(new RefDocDispositionObject(*other.d))
{ }

RefDocDisposition::RefDocDisposition(const RefDocDispositionObject &object)
    : TAbstractModel(), d(new RefDocDispositionObject(object))
{ }

RefDocDisposition::~RefDocDisposition()
{
    // If the reference count becomes 0,
    // the shared data object 'RefDocDispositionObject' is deleted.
}

QString RefDocDisposition::docDispositionCd() const
{
    return d->doc_disposition_cd;
}

void RefDocDisposition::setDocDispositionCd(const QString &docDispositionCd)
{
    d->doc_disposition_cd = docDispositionCd;
}

QString RefDocDisposition::docDispositionNameEn() const
{
    return d->doc_disposition_name_en;
}

void RefDocDisposition::setDocDispositionNameEn(const QString &docDispositionNameEn)
{
    d->doc_disposition_name_en = docDispositionNameEn;
}

QString RefDocDisposition::docDispositionNameZh() const
{
    return d->doc_disposition_name_zh;
}

void RefDocDisposition::setDocDispositionNameZh(const QString &docDispositionNameZh)
{
    d->doc_disposition_name_zh = docDispositionNameZh;
}

QString RefDocDisposition::docDispositionDesc() const
{
    return d->doc_disposition_desc;
}

void RefDocDisposition::setDocDispositionDesc(const QString &docDispositionDesc)
{
    d->doc_disposition_desc = docDispositionDesc;
}

QDateTime RefDocDisposition::createdAt() const
{
    return d->created_at;
}

QString RefDocDisposition::createdBy() const
{
    return d->created_by;
}

void RefDocDisposition::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime RefDocDisposition::updatedAt() const
{
    return d->updated_at;
}

QString RefDocDisposition::updatedBy() const
{
    return d->updated_by;
}

void RefDocDisposition::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

RefDocDisposition &RefDocDisposition::operator=(const RefDocDisposition &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

RefDocDisposition RefDocDisposition::create(const QString &docDispositionCd, const QString &docDispositionNameEn, const QString &docDispositionNameZh, const QString &docDispositionDesc, const QString &createdBy, const QString &updatedBy)
{
    RefDocDispositionObject obj;
    obj.doc_disposition_cd = docDispositionCd;
    obj.doc_disposition_name_en = docDispositionNameEn;
    obj.doc_disposition_name_zh = docDispositionNameZh;
    obj.doc_disposition_desc = docDispositionDesc;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return RefDocDisposition();
    }
    return RefDocDisposition(obj);
}

RefDocDisposition RefDocDisposition::create(const QVariantMap &values)
{
    RefDocDisposition model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

RefDocDisposition RefDocDisposition::get(const QString &docDispositionCd)
{
    TSqlORMapper<RefDocDispositionObject> mapper;
    return RefDocDisposition(mapper.findByPrimaryKey(docDispositionCd));
}

int RefDocDisposition::count()
{
    TSqlORMapper<RefDocDispositionObject> mapper;
    return mapper.findCount();
}

QList<RefDocDisposition> RefDocDisposition::getAll()
{
    return tfGetModelListByCriteria<RefDocDisposition, RefDocDispositionObject>();
}

TModelObject *RefDocDisposition::modelData()
{
    return d.data();
}

const TModelObject *RefDocDisposition::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const RefDocDisposition &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, RefDocDisposition &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(RefDocDisposition)
