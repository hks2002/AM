#include <TreeFrogModel>
#include "poauth.h"
#include "poauthobject.h"
#include "userapp.h"
#include "poheader.h"

PoAuth::PoAuth()
    : TAbstractModel(), d(new PoAuthObject())
{
    d->po_auth_id = 0;
    d->po_id = 0;
    d->auth_by = 0;
}

PoAuth::PoAuth(const PoAuth &other)
    : TAbstractModel(), d(new PoAuthObject(*other.d))
{ }

PoAuth::PoAuth(const PoAuthObject &object)
    : TAbstractModel(), d(new PoAuthObject(object))
{ }

PoAuth::~PoAuth()
{
    // If the reference count becomes 0,
    // the shared data object 'PoAuthObject' is deleted.
}

int PoAuth::poAuthId() const
{
    return d->po_auth_id;
}

int PoAuth::poId() const
{
    return d->po_id;
}

void PoAuth::setPoId(int poId)
{
    d->po_id = poId;
}

bool PoAuth::aogOverrideBool() const
{
    return d->aog_override_bool;
}

void PoAuth::setAogOverrideBool(bool aogOverrideBool)
{
    d->aog_override_bool = aogOverrideBool;
}

bool PoAuth::revertedBool() const
{
    return d->reverted_bool;
}

void PoAuth::setRevertedBool(bool revertedBool)
{
    d->reverted_bool = revertedBool;
}

QDateTime PoAuth::authDt() const
{
    return d->auth_dt;
}

void PoAuth::setAuthDt(const QDateTime &authDt)
{
    d->auth_dt = authDt;
}

QString PoAuth::authNote() const
{
    return d->auth_note;
}

void PoAuth::setAuthNote(const QString &authNote)
{
    d->auth_note = authNote;
}

int PoAuth::authBy() const
{
    return d->auth_by;
}

void PoAuth::setAuthBy(int authBy)
{
    d->auth_by = authBy;
}

QDateTime PoAuth::createdAt() const
{
    return d->created_at;
}

QString PoAuth::createdBy() const
{
    return d->created_by;
}

void PoAuth::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime PoAuth::updatedAt() const
{
    return d->updated_at;
}

QString PoAuth::updatedBy() const
{
    return d->updated_by;
}

void PoAuth::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

UserApp PoAuth::userAppByauthBy() const
{
 return UserApp::get(d->auth_by);
}

PoHeader PoAuth::poHeaderBypoId() const
{
 return PoHeader::get(d->po_id);
}

PoAuth &PoAuth::operator=(const PoAuth &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

PoAuth PoAuth::create(int poId, bool aogOverrideBool, bool revertedBool, const QDateTime &authDt, const QString &authNote, int authBy, const QString &createdBy, const QString &updatedBy)
{
    PoAuthObject obj;
    obj.po_id = poId;
    obj.aog_override_bool = aogOverrideBool;
    obj.reverted_bool = revertedBool;
    obj.auth_dt = authDt;
    obj.auth_note = authNote;
    obj.auth_by = authBy;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return PoAuth();
    }
    return PoAuth(obj);
}

PoAuth PoAuth::create(const QVariantMap &values)
{
    PoAuth model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

PoAuth PoAuth::get(int poAuthId)
{
    TSqlORMapper<PoAuthObject> mapper;
    return PoAuth(mapper.findByPrimaryKey(poAuthId));
}

int PoAuth::count()
{
    TSqlORMapper<PoAuthObject> mapper;
    return mapper.findCount();
}

QList<PoAuth> PoAuth::getAll()
{
    return tfGetModelListByCriteria<PoAuth, PoAuthObject>();
}

TModelObject *PoAuth::modelData()
{
    return d.data();
}

const TModelObject *PoAuth::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const PoAuth &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, PoAuth &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(PoAuth)
