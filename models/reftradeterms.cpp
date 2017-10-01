#include <TreeFrogModel>
#include "reftradeterms.h"
#include "reftradetermsobject.h"

RefTradeTerms::RefTradeTerms()
    : TAbstractModel(), d(new RefTradeTermsObject())
{ }

RefTradeTerms::RefTradeTerms(const RefTradeTerms &other)
    : TAbstractModel(), d(new RefTradeTermsObject(*other.d))
{ }

RefTradeTerms::RefTradeTerms(const RefTradeTermsObject &object)
    : TAbstractModel(), d(new RefTradeTermsObject(object))
{ }

RefTradeTerms::~RefTradeTerms()
{
    // If the reference count becomes 0,
    // the shared data object 'RefTradeTermsObject' is deleted.
}

QString RefTradeTerms::tradeTermCd() const
{
    return d->trade_term_cd;
}

void RefTradeTerms::setTradeTermCd(const QString &tradeTermCd)
{
    d->trade_term_cd = tradeTermCd;
}

QString RefTradeTerms::tradeTermNameEn() const
{
    return d->trade_term_name_en;
}

void RefTradeTerms::setTradeTermNameEn(const QString &tradeTermNameEn)
{
    d->trade_term_name_en = tradeTermNameEn;
}

QString RefTradeTerms::tradeTermNameZh() const
{
    return d->trade_term_name_zh;
}

void RefTradeTerms::setTradeTermNameZh(const QString &tradeTermNameZh)
{
    d->trade_term_name_zh = tradeTermNameZh;
}

QString RefTradeTerms::tradeTermDesc() const
{
    return d->trade_term_desc;
}

void RefTradeTerms::setTradeTermDesc(const QString &tradeTermDesc)
{
    d->trade_term_desc = tradeTermDesc;
}

QDateTime RefTradeTerms::createdAt() const
{
    return d->created_at;
}

QString RefTradeTerms::createdBy() const
{
    return d->created_by;
}

void RefTradeTerms::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime RefTradeTerms::updatedAt() const
{
    return d->updated_at;
}

QString RefTradeTerms::updatedBy() const
{
    return d->updated_by;
}

void RefTradeTerms::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

RefTradeTerms &RefTradeTerms::operator=(const RefTradeTerms &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

RefTradeTerms RefTradeTerms::create(const QString &tradeTermCd, const QString &tradeTermNameEn, const QString &tradeTermNameZh, const QString &tradeTermDesc, const QString &createdBy, const QString &updatedBy)
{
    RefTradeTermsObject obj;
    obj.trade_term_cd = tradeTermCd;
    obj.trade_term_name_en = tradeTermNameEn;
    obj.trade_term_name_zh = tradeTermNameZh;
    obj.trade_term_desc = tradeTermDesc;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return RefTradeTerms();
    }
    return RefTradeTerms(obj);
}

RefTradeTerms RefTradeTerms::create(const QVariantMap &values)
{
    RefTradeTerms model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

RefTradeTerms RefTradeTerms::get(const QString &tradeTermCd)
{
    TSqlORMapper<RefTradeTermsObject> mapper;
    return RefTradeTerms(mapper.findByPrimaryKey(tradeTermCd));
}

int RefTradeTerms::count()
{
    TSqlORMapper<RefTradeTermsObject> mapper;
    return mapper.findCount();
}

QList<RefTradeTerms> RefTradeTerms::getAll()
{
    return tfGetModelListByCriteria<RefTradeTerms, RefTradeTermsObject>();
}

TModelObject *RefTradeTerms::modelData()
{
    return d.data();
}

const TModelObject *RefTradeTerms::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const RefTradeTerms &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, RefTradeTerms &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(RefTradeTerms)
