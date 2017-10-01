#include <TreeFrogModel>
#include "refpaymentterms.h"
#include "refpaymenttermsobject.h"

RefPaymentTerms::RefPaymentTerms()
    : TAbstractModel(), d(new RefPaymentTermsObject())
{ }

RefPaymentTerms::RefPaymentTerms(const RefPaymentTerms &other)
    : TAbstractModel(), d(new RefPaymentTermsObject(*other.d))
{ }

RefPaymentTerms::RefPaymentTerms(const RefPaymentTermsObject &object)
    : TAbstractModel(), d(new RefPaymentTermsObject(object))
{ }

RefPaymentTerms::~RefPaymentTerms()
{
    // If the reference count becomes 0,
    // the shared data object 'RefPaymentTermsObject' is deleted.
}

QString RefPaymentTerms::paymentTermsCd() const
{
    return d->payment_terms_cd;
}

void RefPaymentTerms::setPaymentTermsCd(const QString &paymentTermsCd)
{
    d->payment_terms_cd = paymentTermsCd;
}

QString RefPaymentTerms::paymentTermsNameEn() const
{
    return d->payment_terms_name_en;
}

void RefPaymentTerms::setPaymentTermsNameEn(const QString &paymentTermsNameEn)
{
    d->payment_terms_name_en = paymentTermsNameEn;
}

QString RefPaymentTerms::paymentTermsNameZh() const
{
    return d->payment_terms_name_zh;
}

void RefPaymentTerms::setPaymentTermsNameZh(const QString &paymentTermsNameZh)
{
    d->payment_terms_name_zh = paymentTermsNameZh;
}

QString RefPaymentTerms::paymentTermsDesc() const
{
    return d->payment_terms_desc;
}

void RefPaymentTerms::setPaymentTermsDesc(const QString &paymentTermsDesc)
{
    d->payment_terms_desc = paymentTermsDesc;
}

QDateTime RefPaymentTerms::createdAt() const
{
    return d->created_at;
}

QString RefPaymentTerms::createdBy() const
{
    return d->created_by;
}

void RefPaymentTerms::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime RefPaymentTerms::updatedAt() const
{
    return d->updated_at;
}

QString RefPaymentTerms::updatedBy() const
{
    return d->updated_by;
}

void RefPaymentTerms::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

RefPaymentTerms &RefPaymentTerms::operator=(const RefPaymentTerms &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

RefPaymentTerms RefPaymentTerms::create(const QString &paymentTermsCd, const QString &paymentTermsNameEn, const QString &paymentTermsNameZh, const QString &paymentTermsDesc, const QString &createdBy, const QString &updatedBy)
{
    RefPaymentTermsObject obj;
    obj.payment_terms_cd = paymentTermsCd;
    obj.payment_terms_name_en = paymentTermsNameEn;
    obj.payment_terms_name_zh = paymentTermsNameZh;
    obj.payment_terms_desc = paymentTermsDesc;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return RefPaymentTerms();
    }
    return RefPaymentTerms(obj);
}

RefPaymentTerms RefPaymentTerms::create(const QVariantMap &values)
{
    RefPaymentTerms model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

RefPaymentTerms RefPaymentTerms::get(const QString &paymentTermsCd)
{
    TSqlORMapper<RefPaymentTermsObject> mapper;
    return RefPaymentTerms(mapper.findByPrimaryKey(paymentTermsCd));
}

int RefPaymentTerms::count()
{
    TSqlORMapper<RefPaymentTermsObject> mapper;
    return mapper.findCount();
}

QList<RefPaymentTerms> RefPaymentTerms::getAll()
{
    return tfGetModelListByCriteria<RefPaymentTerms, RefPaymentTermsObject>();
}

TModelObject *RefPaymentTerms::modelData()
{
    return d.data();
}

const TModelObject *RefPaymentTerms::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const RefPaymentTerms &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, RefPaymentTerms &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(RefPaymentTerms)
