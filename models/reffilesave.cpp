#include <TreeFrogModel>
#include "reffilesave.h"
#include "reffilesaveobject.h"

RefFileSave::RefFileSave()
    : TAbstractModel(), d(new RefFileSaveObject())
{ }

RefFileSave::RefFileSave(const RefFileSave &other)
    : TAbstractModel(), d(new RefFileSaveObject(*other.d))
{ }

RefFileSave::RefFileSave(const RefFileSaveObject &object)
    : TAbstractModel(), d(new RefFileSaveObject(object))
{ }

RefFileSave::~RefFileSave()
{
    // If the reference count becomes 0,
    // the shared data object 'RefFileSaveObject' is deleted.
}

QString RefFileSave::fileSaveCd() const
{
    return d->file_save_cd;
}

void RefFileSave::setFileSaveCd(const QString &fileSaveCd)
{
    d->file_save_cd = fileSaveCd;
}

QString RefFileSave::fileSaveNameZh() const
{
    return d->file_save_name_zh;
}

void RefFileSave::setFileSaveNameZh(const QString &fileSaveNameZh)
{
    d->file_save_name_zh = fileSaveNameZh;
}

QString RefFileSave::fileSaveNameEn() const
{
    return d->file_save_name_en;
}

void RefFileSave::setFileSaveNameEn(const QString &fileSaveNameEn)
{
    d->file_save_name_en = fileSaveNameEn;
}

QString RefFileSave::fileSaveDesc() const
{
    return d->file_save_desc;
}

void RefFileSave::setFileSaveDesc(const QString &fileSaveDesc)
{
    d->file_save_desc = fileSaveDesc;
}

QDateTime RefFileSave::createdAt() const
{
    return d->created_at;
}

QString RefFileSave::createdBy() const
{
    return d->created_by;
}

void RefFileSave::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime RefFileSave::updatedAt() const
{
    return d->updated_at;
}

QString RefFileSave::updatedBy() const
{
    return d->updated_by;
}

void RefFileSave::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

RefFileSave &RefFileSave::operator=(const RefFileSave &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

RefFileSave RefFileSave::create(const QString &fileSaveCd, const QString &fileSaveNameZh, const QString &fileSaveNameEn, const QString &fileSaveDesc, const QString &createdBy, const QString &updatedBy)
{
    RefFileSaveObject obj;
    obj.file_save_cd = fileSaveCd;
    obj.file_save_name_zh = fileSaveNameZh;
    obj.file_save_name_en = fileSaveNameEn;
    obj.file_save_desc = fileSaveDesc;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return RefFileSave();
    }
    return RefFileSave(obj);
}

RefFileSave RefFileSave::create(const QVariantMap &values)
{
    RefFileSave model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

RefFileSave RefFileSave::get(const QString &fileSaveCd)
{
    TSqlORMapper<RefFileSaveObject> mapper;
    return RefFileSave(mapper.findByPrimaryKey(fileSaveCd));
}

int RefFileSave::count()
{
    TSqlORMapper<RefFileSaveObject> mapper;
    return mapper.findCount();
}

QList<RefFileSave> RefFileSave::getAll()
{
    return tfGetModelListByCriteria<RefFileSave, RefFileSaveObject>();
}

TModelObject *RefFileSave::modelData()
{
    return d.data();
}

const TModelObject *RefFileSave::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const RefFileSave &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, RefFileSave &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(RefFileSave)
