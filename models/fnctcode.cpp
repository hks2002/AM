#include <TreeFrogModel>
#include "fnctcode.h"
#include "fnctcodeobject.h"

FncTcode::FncTcode()
    : TAbstractModel(), d(new FncTcodeObject())
{
    d->tcode_id = 0;
}

FncTcode::FncTcode(const FncTcode &other)
    : TAbstractModel(), d(new FncTcodeObject(*other.d))
{ }

FncTcode::FncTcode(const FncTcodeObject &object)
    : TAbstractModel(), d(new FncTcodeObject(object))
{ }

FncTcode::~FncTcode()
{
    // If the reference count becomes 0,
    // the shared data object 'FncTcodeObject' is deleted.
}

int FncTcode::tcodeId() const
{
    return d->tcode_id;
}

QString FncTcode::tcodeCd() const
{
    return d->tcode_cd;
}

void FncTcode::setTcodeCd(const QString &tcodeCd)
{
    d->tcode_cd = tcodeCd;
}

QString FncTcode::tcodeName() const
{
    return d->tcode_name;
}

void FncTcode::setTcodeName(const QString &tcodeName)
{
    d->tcode_name = tcodeName;
}

QString FncTcode::descDesc() const
{
    return d->desc_desc;
}

void FncTcode::setDescDesc(const QString &descDesc)
{
    d->desc_desc = descDesc;
}

QDateTime FncTcode::createdAt() const
{
    return d->created_at;
}

QString FncTcode::createdBy() const
{
    return d->created_by;
}

void FncTcode::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime FncTcode::updatedAt() const
{
    return d->updated_at;
}

QString FncTcode::updatedBy() const
{
    return d->updated_by;
}

void FncTcode::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

FncTcode &FncTcode::operator=(const FncTcode &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

FncTcode FncTcode::create(const QString &tcodeCd, const QString &tcodeName, const QString &descDesc, const QString &createdBy, const QString &updatedBy)
{
    FncTcodeObject obj;
    obj.tcode_cd = tcodeCd;
    obj.tcode_name = tcodeName;
    obj.desc_desc = descDesc;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return FncTcode();
    }
    return FncTcode(obj);
}

FncTcode FncTcode::create(const QVariantMap &values)
{
    FncTcode model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

FncTcode FncTcode::get(int tcodeId)
{
    TSqlORMapper<FncTcodeObject> mapper;
    return FncTcode(mapper.findByPrimaryKey(tcodeId));
}

int FncTcode::count()
{
    TSqlORMapper<FncTcodeObject> mapper;
    return mapper.findCount();
}

QList<FncTcode> FncTcode::getAll()
{
    return tfGetModelListByCriteria<FncTcode, FncTcodeObject>();
}

TModelObject *FncTcode::modelData()
{
    return d.data();
}

const TModelObject *FncTcode::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const FncTcode &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, FncTcode &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(FncTcode)
