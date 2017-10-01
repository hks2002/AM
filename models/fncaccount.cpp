#include <TreeFrogModel>
#include "fncaccount.h"
#include "fncaccountobject.h"
#include "fnctcode.h"
#include "refaccounttype.h"

FncAccount::FncAccount()
    : TAbstractModel(), d(new FncAccountObject())
{
    d->account_id = 0;
    d->nh_account_id = 0;
    d->tcode_id = 0;
}

FncAccount::FncAccount(const FncAccount &other)
    : TAbstractModel(), d(new FncAccountObject(*other.d))
{ }

FncAccount::FncAccount(const FncAccountObject &object)
    : TAbstractModel(), d(new FncAccountObject(object))
{ }

FncAccount::~FncAccount()
{
    // If the reference count becomes 0,
    // the shared data object 'FncAccountObject' is deleted.
}

int FncAccount::accountId() const
{
    return d->account_id;
}

QString FncAccount::accountCd() const
{
    return d->account_cd;
}

void FncAccount::setAccountCd(const QString &accountCd)
{
    d->account_cd = accountCd;
}

int FncAccount::nhAccountId() const
{
    return d->nh_account_id;
}

void FncAccount::setNhAccountId(int nhAccountId)
{
    d->nh_account_id = nhAccountId;
}

QString FncAccount::accountTypeCd() const
{
    return d->account_type_cd;
}

void FncAccount::setAccountTypeCd(const QString &accountTypeCd)
{
    d->account_type_cd = accountTypeCd;
}

QString FncAccount::accountName() const
{
    return d->account_name;
}

void FncAccount::setAccountName(const QString &accountName)
{
    d->account_name = accountName;
}

QString FncAccount::accountDesc() const
{
    return d->account_desc;
}

void FncAccount::setAccountDesc(const QString &accountDesc)
{
    d->account_desc = accountDesc;
}

bool FncAccount::defaultBool() const
{
    return d->default_bool;
}

void FncAccount::setDefaultBool(bool defaultBool)
{
    d->default_bool = defaultBool;
}

bool FncAccount::closedBool() const
{
    return d->closed_bool;
}

void FncAccount::setClosedBool(bool closedBool)
{
    d->closed_bool = closedBool;
}

int FncAccount::tcodeId() const
{
    return d->tcode_id;
}

void FncAccount::setTcodeId(int tcodeId)
{
    d->tcode_id = tcodeId;
}

QString FncAccount::extKey() const
{
    return d->ext_key;
}

void FncAccount::setExtKey(const QString &extKey)
{
    d->ext_key = extKey;
}

QDateTime FncAccount::createdAt() const
{
    return d->created_at;
}

QString FncAccount::createdBy() const
{
    return d->created_by;
}

void FncAccount::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime FncAccount::updatedAt() const
{
    return d->updated_at;
}

QString FncAccount::updatedBy() const
{
    return d->updated_by;
}

void FncAccount::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

FncTcode FncAccount::fncTcodeBytcodeId() const
{
 return FncTcode::get(d->tcode_id);
}

RefAccountType FncAccount::refAccountTypeByaccountTypeCd() const
{
 return RefAccountType::get(d->account_type_cd);
}

FncAccount &FncAccount::operator=(const FncAccount &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

FncAccount FncAccount::create(const QString &accountCd, int nhAccountId, const QString &accountTypeCd, const QString &accountName, const QString &accountDesc, bool defaultBool, bool closedBool, int tcodeId, const QString &extKey, const QString &createdBy, const QString &updatedBy)
{
    FncAccountObject obj;
    obj.account_cd = accountCd;
    obj.nh_account_id = nhAccountId;
    obj.account_type_cd = accountTypeCd;
    obj.account_name = accountName;
    obj.account_desc = accountDesc;
    obj.default_bool = defaultBool;
    obj.closed_bool = closedBool;
    obj.tcode_id = tcodeId;
    obj.ext_key = extKey;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return FncAccount();
    }
    return FncAccount(obj);
}

FncAccount FncAccount::create(const QVariantMap &values)
{
    FncAccount model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

FncAccount FncAccount::get(int accountId)
{
    TSqlORMapper<FncAccountObject> mapper;
    return FncAccount(mapper.findByPrimaryKey(accountId));
}

int FncAccount::count()
{
    TSqlORMapper<FncAccountObject> mapper;
    return mapper.findCount();
}

QList<FncAccount> FncAccount::getAll()
{
    return tfGetModelListByCriteria<FncAccount, FncAccountObject>();
}

TModelObject *FncAccount::modelData()
{
    return d.data();
}

const TModelObject *FncAccount::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const FncAccount &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, FncAccount &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(FncAccount)
