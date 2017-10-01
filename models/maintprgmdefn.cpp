#include <TreeFrogModel>
#include "maintprgmdefn.h"
#include "maintprgmdefnobject.h"

MaintPrgmDefn::MaintPrgmDefn()
    : TAbstractModel(), d(new MaintPrgmDefnObject())
{
    d->maint_prgm_defn_id = 0;
    d->last_revision_ord = 0;
}

MaintPrgmDefn::MaintPrgmDefn(const MaintPrgmDefn &other)
    : TAbstractModel(), d(new MaintPrgmDefnObject(*other.d))
{ }

MaintPrgmDefn::MaintPrgmDefn(const MaintPrgmDefnObject &object)
    : TAbstractModel(), d(new MaintPrgmDefnObject(object))
{ }

MaintPrgmDefn::~MaintPrgmDefn()
{
    // If the reference count becomes 0,
    // the shared data object 'MaintPrgmDefnObject' is deleted.
}

int MaintPrgmDefn::maintPrgmDefnId() const
{
    return d->maint_prgm_defn_id;
}

int MaintPrgmDefn::lastRevisionOrd() const
{
    return d->last_revision_ord;
}

void MaintPrgmDefn::setLastRevisionOrd(int lastRevisionOrd)
{
    d->last_revision_ord = lastRevisionOrd;
}

bool MaintPrgmDefn::newRevisionBool() const
{
    return d->new_revision_bool;
}

void MaintPrgmDefn::setNewRevisionBool(bool newRevisionBool)
{
    d->new_revision_bool = newRevisionBool;
}

QDateTime MaintPrgmDefn::createdAt() const
{
    return d->created_at;
}

QString MaintPrgmDefn::createdBy() const
{
    return d->created_by;
}

void MaintPrgmDefn::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime MaintPrgmDefn::updatedAt() const
{
    return d->updated_at;
}

QString MaintPrgmDefn::updatedBy() const
{
    return d->updated_by;
}

void MaintPrgmDefn::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

MaintPrgmDefn &MaintPrgmDefn::operator=(const MaintPrgmDefn &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

MaintPrgmDefn MaintPrgmDefn::create(int lastRevisionOrd, bool newRevisionBool, const QString &createdBy, const QString &updatedBy)
{
    MaintPrgmDefnObject obj;
    obj.last_revision_ord = lastRevisionOrd;
    obj.new_revision_bool = newRevisionBool;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return MaintPrgmDefn();
    }
    return MaintPrgmDefn(obj);
}

MaintPrgmDefn MaintPrgmDefn::create(const QVariantMap &values)
{
    MaintPrgmDefn model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

MaintPrgmDefn MaintPrgmDefn::get(int maintPrgmDefnId)
{
    TSqlORMapper<MaintPrgmDefnObject> mapper;
    return MaintPrgmDefn(mapper.findByPrimaryKey(maintPrgmDefnId));
}

int MaintPrgmDefn::count()
{
    TSqlORMapper<MaintPrgmDefnObject> mapper;
    return mapper.findCount();
}

QList<MaintPrgmDefn> MaintPrgmDefn::getAll()
{
    return tfGetModelListByCriteria<MaintPrgmDefn, MaintPrgmDefnObject>();
}

TModelObject *MaintPrgmDefn::modelData()
{
    return d.data();
}

const TModelObject *MaintPrgmDefn::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const MaintPrgmDefn &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, MaintPrgmDefn &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(MaintPrgmDefn)
