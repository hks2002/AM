#include <TreeFrogModel>
#include "tax.h"
#include "taxobject.h"
#include "fncaccount.h"

Tax::Tax()
    : TAbstractModel(), d(new TaxObject())
{
    d->tax_id = 0;
    d->account_id = 0;
}

Tax::Tax(const Tax &other)
    : TAbstractModel(), d(new TaxObject(*other.d))
{ }

Tax::Tax(const TaxObject &object)
    : TAbstractModel(), d(new TaxObject(object))
{ }

Tax::~Tax()
{
    // If the reference count becomes 0,
    // the shared data object 'TaxObject' is deleted.
}

int Tax::taxId() const
{
    return d->tax_id;
}

QString Tax::taxCd() const
{
    return d->tax_cd;
}

void Tax::setTaxCd(const QString &taxCd)
{
    d->tax_cd = taxCd;
}

QString Tax::taxName() const
{
    return d->tax_name;
}

void Tax::setTaxName(const QString &taxName)
{
    d->tax_name = taxName;
}

int Tax::accountId() const
{
    return d->account_id;
}

void Tax::setAccountId(int accountId)
{
    d->account_id = accountId;
}

bool Tax::recoverableBool() const
{
    return d->recoverable_bool;
}

void Tax::setRecoverableBool(bool recoverableBool)
{
    d->recoverable_bool = recoverableBool;
}

bool Tax::archiveBool() const
{
    return d->archive_bool;
}

void Tax::setArchiveBool(bool archiveBool)
{
    d->archive_bool = archiveBool;
}

QDateTime Tax::createdAt() const
{
    return d->created_at;
}

QString Tax::createdBy() const
{
    return d->created_by;
}

void Tax::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime Tax::updatedAt() const
{
    return d->updated_at;
}

QString Tax::updatedBy() const
{
    return d->updated_by;
}

void Tax::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

FncAccount Tax::fncAccountByaccountId() const
{
 return FncAccount::get(d->account_id);
}

Tax &Tax::operator=(const Tax &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

Tax Tax::create(const QString &taxCd, const QString &taxName, int accountId, bool recoverableBool, bool archiveBool, const QString &createdBy, const QString &updatedBy)
{
    TaxObject obj;
    obj.tax_cd = taxCd;
    obj.tax_name = taxName;
    obj.account_id = accountId;
    obj.recoverable_bool = recoverableBool;
    obj.archive_bool = archiveBool;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return Tax();
    }
    return Tax(obj);
}

Tax Tax::create(const QVariantMap &values)
{
    Tax model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

Tax Tax::get(int taxId)
{
    TSqlORMapper<TaxObject> mapper;
    return Tax(mapper.findByPrimaryKey(taxId));
}

int Tax::count()
{
    TSqlORMapper<TaxObject> mapper;
    return mapper.findCount();
}

QList<Tax> Tax::getAll()
{
    return tfGetModelListByCriteria<Tax, TaxObject>();
}

TModelObject *Tax::modelData()
{
    return d.data();
}

const TModelObject *Tax::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const Tax &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, Tax &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(Tax)
