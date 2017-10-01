#include <TreeFrogModel>
#include "refdocissueby.h"
#include "refdocissuebyobject.h"

RefDocIssueBy::RefDocIssueBy()
    : TAbstractModel(), d(new RefDocIssueByObject())
{ }

RefDocIssueBy::RefDocIssueBy(const RefDocIssueBy &other)
    : TAbstractModel(), d(new RefDocIssueByObject(*other.d))
{ }

RefDocIssueBy::RefDocIssueBy(const RefDocIssueByObject &object)
    : TAbstractModel(), d(new RefDocIssueByObject(object))
{ }

RefDocIssueBy::~RefDocIssueBy()
{
    // If the reference count becomes 0,
    // the shared data object 'RefDocIssueByObject' is deleted.
}

QString RefDocIssueBy::docIssueByCd() const
{
    return d->doc_issue_by_cd;
}

void RefDocIssueBy::setDocIssueByCd(const QString &docIssueByCd)
{
    d->doc_issue_by_cd = docIssueByCd;
}

QString RefDocIssueBy::docIssueByNameEn() const
{
    return d->doc_issue_by_name_en;
}

void RefDocIssueBy::setDocIssueByNameEn(const QString &docIssueByNameEn)
{
    d->doc_issue_by_name_en = docIssueByNameEn;
}

QString RefDocIssueBy::docIssueByNameZh() const
{
    return d->doc_issue_by_name_zh;
}

void RefDocIssueBy::setDocIssueByNameZh(const QString &docIssueByNameZh)
{
    d->doc_issue_by_name_zh = docIssueByNameZh;
}

QString RefDocIssueBy::docIssueByDesc() const
{
    return d->doc_issue_by_desc;
}

void RefDocIssueBy::setDocIssueByDesc(const QString &docIssueByDesc)
{
    d->doc_issue_by_desc = docIssueByDesc;
}

QDateTime RefDocIssueBy::createdAt() const
{
    return d->created_at;
}

QString RefDocIssueBy::createdBy() const
{
    return d->created_by;
}

void RefDocIssueBy::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime RefDocIssueBy::updatedAt() const
{
    return d->updated_at;
}

QString RefDocIssueBy::updatedBy() const
{
    return d->updated_by;
}

void RefDocIssueBy::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

RefDocIssueBy &RefDocIssueBy::operator=(const RefDocIssueBy &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

RefDocIssueBy RefDocIssueBy::create(const QString &docIssueByCd, const QString &docIssueByNameEn, const QString &docIssueByNameZh, const QString &docIssueByDesc, const QString &createdBy, const QString &updatedBy)
{
    RefDocIssueByObject obj;
    obj.doc_issue_by_cd = docIssueByCd;
    obj.doc_issue_by_name_en = docIssueByNameEn;
    obj.doc_issue_by_name_zh = docIssueByNameZh;
    obj.doc_issue_by_desc = docIssueByDesc;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return RefDocIssueBy();
    }
    return RefDocIssueBy(obj);
}

RefDocIssueBy RefDocIssueBy::create(const QVariantMap &values)
{
    RefDocIssueBy model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

RefDocIssueBy RefDocIssueBy::get(const QString &docIssueByCd)
{
    TSqlORMapper<RefDocIssueByObject> mapper;
    return RefDocIssueBy(mapper.findByPrimaryKey(docIssueByCd));
}

int RefDocIssueBy::count()
{
    TSqlORMapper<RefDocIssueByObject> mapper;
    return mapper.findCount();
}

QList<RefDocIssueBy> RefDocIssueBy::getAll()
{
    return tfGetModelListByCriteria<RefDocIssueBy, RefDocIssueByObject>();
}

TModelObject *RefDocIssueBy::modelData()
{
    return d.data();
}

const TModelObject *RefDocIssueBy::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const RefDocIssueBy &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, RefDocIssueBy &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(RefDocIssueBy)
