#include <TreeFrogModel>
#include "regbodydoc.h"
#include "regbodydocobject.h"

RegBodyDoc::RegBodyDoc()
    : TAbstractModel(), d(new RegBodyDocObject())
{
    d->reg_body_doc_id = 0;
}

RegBodyDoc::RegBodyDoc(const RegBodyDoc &other)
    : TAbstractModel(), d(new RegBodyDocObject(*other.d))
{ }

RegBodyDoc::RegBodyDoc(const RegBodyDocObject &object)
    : TAbstractModel(), d(new RegBodyDocObject(object))
{ }

RegBodyDoc::~RegBodyDoc()
{
    // If the reference count becomes 0,
    // the shared data object 'RegBodyDocObject' is deleted.
}

int RegBodyDoc::regBodyDocId() const
{
    return d->reg_body_doc_id;
}

QString RegBodyDoc::regBodyDocCd() const
{
    return d->reg_body_doc_cd;
}

void RegBodyDoc::setRegBodyDocCd(const QString &regBodyDocCd)
{
    d->reg_body_doc_cd = regBodyDocCd;
}

QString RegBodyDoc::regBodyDocNameZh() const
{
    return d->reg_body_doc_name_zh;
}

void RegBodyDoc::setRegBodyDocNameZh(const QString &regBodyDocNameZh)
{
    d->reg_body_doc_name_zh = regBodyDocNameZh;
}

QString RegBodyDoc::regBodyDocNameEn() const
{
    return d->reg_body_doc_name_en;
}

void RegBodyDoc::setRegBodyDocNameEn(const QString &regBodyDocNameEn)
{
    d->reg_body_doc_name_en = regBodyDocNameEn;
}

QDateTime RegBodyDoc::createdAt() const
{
    return d->created_at;
}

QString RegBodyDoc::createdBy() const
{
    return d->created_by;
}

void RegBodyDoc::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime RegBodyDoc::updatedAt() const
{
    return d->updated_at;
}

QString RegBodyDoc::updatedBy() const
{
    return d->updated_by;
}

void RegBodyDoc::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

RegBodyDoc &RegBodyDoc::operator=(const RegBodyDoc &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

RegBodyDoc RegBodyDoc::create(const QString &regBodyDocCd, const QString &regBodyDocNameZh, const QString &regBodyDocNameEn, const QString &createdBy, const QString &updatedBy)
{
    RegBodyDocObject obj;
    obj.reg_body_doc_cd = regBodyDocCd;
    obj.reg_body_doc_name_zh = regBodyDocNameZh;
    obj.reg_body_doc_name_en = regBodyDocNameEn;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return RegBodyDoc();
    }
    return RegBodyDoc(obj);
}

RegBodyDoc RegBodyDoc::create(const QVariantMap &values)
{
    RegBodyDoc model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

RegBodyDoc RegBodyDoc::get(int regBodyDocId)
{
    TSqlORMapper<RegBodyDocObject> mapper;
    return RegBodyDoc(mapper.findByPrimaryKey(regBodyDocId));
}

int RegBodyDoc::count()
{
    TSqlORMapper<RegBodyDocObject> mapper;
    return mapper.findCount();
}

QList<RegBodyDoc> RegBodyDoc::getAll()
{
    return tfGetModelListByCriteria<RegBodyDoc, RegBodyDocObject>();
}

TModelObject *RegBodyDoc::modelData()
{
    return d.data();
}

const TModelObject *RegBodyDoc::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const RegBodyDoc &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, RegBodyDoc &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(RegBodyDoc)
