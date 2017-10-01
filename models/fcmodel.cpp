#include <TreeFrogModel>
#include "fcmodel.h"
#include "fcmodelobject.h"
#include "authority.h"

FcModel::FcModel()
    : TAbstractModel(), d(new FcModelObject())
{
    d->fc_model_id = 0;
    d->authority_id = 0;
}

FcModel::FcModel(const FcModel &other)
    : TAbstractModel(), d(new FcModelObject(*other.d))
{ }

FcModel::FcModel(const FcModelObject &object)
    : TAbstractModel(), d(new FcModelObject(object))
{ }

FcModel::~FcModel()
{
    // If the reference count becomes 0,
    // the shared data object 'FcModelObject' is deleted.
}

int FcModel::fcModelId() const
{
    return d->fc_model_id;
}

QString FcModel::fcCd() const
{
    return d->fc_cd;
}

void FcModel::setFcCd(const QString &fcCd)
{
    d->fc_cd = fcCd;
}

bool FcModel::defaultBool() const
{
    return d->default_bool;
}

void FcModel::setDefaultBool(bool defaultBool)
{
    d->default_bool = defaultBool;
}

QString FcModel::descDesc() const
{
    return d->desc_desc;
}

void FcModel::setDescDesc(const QString &descDesc)
{
    d->desc_desc = descDesc;
}

int FcModel::authorityId() const
{
    return d->authority_id;
}

void FcModel::setAuthorityId(int authorityId)
{
    d->authority_id = authorityId;
}

QDateTime FcModel::createdAt() const
{
    return d->created_at;
}

QString FcModel::createdBy() const
{
    return d->created_by;
}

void FcModel::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime FcModel::updatedAt() const
{
    return d->updated_at;
}

QString FcModel::updatedBy() const
{
    return d->updated_by;
}

void FcModel::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

Authority FcModel::authorityByauthorityId() const
{
 return Authority::get(d->authority_id);
}

FcModel &FcModel::operator=(const FcModel &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

FcModel FcModel::create(const QString &fcCd, bool defaultBool, const QString &descDesc, int authorityId, const QString &createdBy, const QString &updatedBy)
{
    FcModelObject obj;
    obj.fc_cd = fcCd;
    obj.default_bool = defaultBool;
    obj.desc_desc = descDesc;
    obj.authority_id = authorityId;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return FcModel();
    }
    return FcModel(obj);
}

FcModel FcModel::create(const QVariantMap &values)
{
    FcModel model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

FcModel FcModel::get(int fcModelId)
{
    TSqlORMapper<FcModelObject> mapper;
    return FcModel(mapper.findByPrimaryKey(fcModelId));
}

int FcModel::count()
{
    TSqlORMapper<FcModelObject> mapper;
    return mapper.findCount();
}

QList<FcModel> FcModel::getAll()
{
    return tfGetModelListByCriteria<FcModel, FcModelObject>();
}

TModelObject *FcModel::modelData()
{
    return d.data();
}

const TModelObject *FcModel::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const FcModel &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, FcModel &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(FcModel)
