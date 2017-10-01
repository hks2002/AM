#include <TreeFrogModel>
#include "polinedoc.h"
#include "polinedocobject.h"
#include "regbodydoc.h"
#include "poline.h"

PoLineDoc::PoLineDoc()
    : TAbstractModel(), d(new PoLineDocObject())
{
    d->po_line_id = 0;
    d->reg_body_doc_id = 0;
}

PoLineDoc::PoLineDoc(const PoLineDoc &other)
    : TAbstractModel(), d(new PoLineDocObject(*other.d))
{ }

PoLineDoc::PoLineDoc(const PoLineDocObject &object)
    : TAbstractModel(), d(new PoLineDocObject(object))
{ }

PoLineDoc::~PoLineDoc()
{
    // If the reference count becomes 0,
    // the shared data object 'PoLineDocObject' is deleted.
}

int PoLineDoc::poLineId() const
{
    return d->po_line_id;
}

void PoLineDoc::setPoLineId(int poLineId)
{
    d->po_line_id = poLineId;
}

int PoLineDoc::regBodyDocId() const
{
    return d->reg_body_doc_id;
}

void PoLineDoc::setRegBodyDocId(int regBodyDocId)
{
    d->reg_body_doc_id = regBodyDocId;
}

bool PoLineDoc::receivedDocBool() const
{
    return d->received_doc_bool;
}

void PoLineDoc::setReceivedDocBool(bool receivedDocBool)
{
    d->received_doc_bool = receivedDocBool;
}

QDateTime PoLineDoc::createdAt() const
{
    return d->created_at;
}

QString PoLineDoc::createdBy() const
{
    return d->created_by;
}

void PoLineDoc::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime PoLineDoc::updatedAt() const
{
    return d->updated_at;
}

QString PoLineDoc::updatedBy() const
{
    return d->updated_by;
}

void PoLineDoc::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

RegBodyDoc PoLineDoc::regBodyDocByregBodyDocId() const
{
 return RegBodyDoc::get(d->reg_body_doc_id);
}

PoLine PoLineDoc::poLineBypoLineId() const
{
 return PoLine::get(d->po_line_id);
}

PoLineDoc &PoLineDoc::operator=(const PoLineDoc &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

PoLineDoc PoLineDoc::create(int poLineId, int regBodyDocId, bool receivedDocBool, const QString &createdBy, const QString &updatedBy)
{
    PoLineDocObject obj;
    obj.po_line_id = poLineId;
    obj.reg_body_doc_id = regBodyDocId;
    obj.received_doc_bool = receivedDocBool;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return PoLineDoc();
    }
    return PoLineDoc(obj);
}

PoLineDoc PoLineDoc::create(const QVariantMap &values)
{
    PoLineDoc model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

PoLineDoc PoLineDoc::get(int poLineId, int regBodyDocId)
{
    TSqlORMapper<PoLineDocObject> mapper;
    return PoLineDoc(mapper.findByPrimaryKey(QVariantList()<<QVariant(poLineId)<<QVariant(regBodyDocId)));
}

int PoLineDoc::count()
{
    TSqlORMapper<PoLineDocObject> mapper;
    return mapper.findCount();
}

QList<PoLineDoc> PoLineDoc::getAll()
{
    return tfGetModelListByCriteria<PoLineDoc, PoLineDocObject>();
}

TModelObject *PoLineDoc::modelData()
{
    return d.data();
}

const TModelObject *PoLineDoc::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const PoLineDoc &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, PoLineDoc &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(PoLineDoc)
