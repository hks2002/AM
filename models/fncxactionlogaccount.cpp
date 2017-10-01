#include <TreeFrogModel>
#include "fncxactionlogaccount.h"
#include "fncxactionlogaccountobject.h"
#include "fncaccount.h"
#include "fncxactionlog.h"

FncXactionLogAccount::FncXactionLogAccount()
    : TAbstractModel(), d(new FncXactionLogAccountObject())
{
    d->xaction_id = 0;
    d->account_id = 0;
    d->xaction_account_id = 0;
    d->credit_cost = 0;
    d->debit_cost = 0;
}

FncXactionLogAccount::FncXactionLogAccount(const FncXactionLogAccount &other)
    : TAbstractModel(), d(new FncXactionLogAccountObject(*other.d))
{ }

FncXactionLogAccount::FncXactionLogAccount(const FncXactionLogAccountObject &object)
    : TAbstractModel(), d(new FncXactionLogAccountObject(object))
{ }

FncXactionLogAccount::~FncXactionLogAccount()
{
    // If the reference count becomes 0,
    // the shared data object 'FncXactionLogAccountObject' is deleted.
}

int FncXactionLogAccount::xactionId() const
{
    return d->xaction_id;
}

void FncXactionLogAccount::setXactionId(int xactionId)
{
    d->xaction_id = xactionId;
}

int FncXactionLogAccount::accountId() const
{
    return d->account_id;
}

void FncXactionLogAccount::setAccountId(int accountId)
{
    d->account_id = accountId;
}

int FncXactionLogAccount::xactionAccountId() const
{
    return d->xaction_account_id;
}

void FncXactionLogAccount::setXactionAccountId(int xactionAccountId)
{
    d->xaction_account_id = xactionAccountId;
}

double FncXactionLogAccount::creditCost() const
{
    return d->credit_cost;
}

void FncXactionLogAccount::setCreditCost(double creditCost)
{
    d->credit_cost = creditCost;
}

double FncXactionLogAccount::debitCost() const
{
    return d->debit_cost;
}

void FncXactionLogAccount::setDebitCost(double debitCost)
{
    d->debit_cost = debitCost;
}

QDateTime FncXactionLogAccount::createdAt() const
{
    return d->created_at;
}

QString FncXactionLogAccount::createdBy() const
{
    return d->created_by;
}

void FncXactionLogAccount::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime FncXactionLogAccount::updatedAt() const
{
    return d->updated_at;
}

QString FncXactionLogAccount::updatedBy() const
{
    return d->updated_by;
}

void FncXactionLogAccount::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

FncAccount FncXactionLogAccount::fncAccountByxactionAccountId() const
{
 return FncAccount::get(d->xaction_account_id);
}

FncXactionLog FncXactionLogAccount::fncXactionLogByxactionId() const
{
 return FncXactionLog::get(d->xaction_id);
}

FncXactionLogAccount &FncXactionLogAccount::operator=(const FncXactionLogAccount &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

FncXactionLogAccount FncXactionLogAccount::create(int xactionId, int accountId, int xactionAccountId, double creditCost, double debitCost, const QString &createdBy, const QString &updatedBy)
{
    FncXactionLogAccountObject obj;
    obj.xaction_id = xactionId;
    obj.account_id = accountId;
    obj.xaction_account_id = xactionAccountId;
    obj.credit_cost = creditCost;
    obj.debit_cost = debitCost;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return FncXactionLogAccount();
    }
    return FncXactionLogAccount(obj);
}

FncXactionLogAccount FncXactionLogAccount::create(const QVariantMap &values)
{
    FncXactionLogAccount model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

FncXactionLogAccount FncXactionLogAccount::get(int xactionId, int accountId, int xactionAccountId)
{
    TSqlORMapper<FncXactionLogAccountObject> mapper;
    return FncXactionLogAccount(mapper.findByPrimaryKey(QVariantList()<<QVariant(xactionId)<<QVariant(accountId)<<QVariant(xactionAccountId)));
}

int FncXactionLogAccount::count()
{
    TSqlORMapper<FncXactionLogAccountObject> mapper;
    return mapper.findCount();
}

QList<FncXactionLogAccount> FncXactionLogAccount::getAll()
{
    return tfGetModelListByCriteria<FncXactionLogAccount, FncXactionLogAccountObject>();
}

TModelObject *FncXactionLogAccount::modelData()
{
    return d.data();
}

const TModelObject *FncXactionLogAccount::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const FncXactionLogAccount &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, FncXactionLogAccount &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(FncXactionLogAccount)
