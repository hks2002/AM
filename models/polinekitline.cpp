#include <TreeFrogModel>
#include "polinekitline.h"
#include "polinekitlineobject.h"
#include "eqpkitpartno.h"
#include "poline.h"

PoLineKitLine::PoLineKitLine()
    : TAbstractModel(), d(new PoLineKitLineObject())
{
    d->po_line_id = 0;
    d->kit_part_no_id = 0;
    d->part_no_id = 0;
    d->kit_qt = 0;
    d->value_pct = 0;
    d->unit_price = 0;
}

PoLineKitLine::PoLineKitLine(const PoLineKitLine &other)
    : TAbstractModel(), d(new PoLineKitLineObject(*other.d))
{ }

PoLineKitLine::PoLineKitLine(const PoLineKitLineObject &object)
    : TAbstractModel(), d(new PoLineKitLineObject(object))
{ }

PoLineKitLine::~PoLineKitLine()
{
    // If the reference count becomes 0,
    // the shared data object 'PoLineKitLineObject' is deleted.
}

int PoLineKitLine::poLineId() const
{
    return d->po_line_id;
}

void PoLineKitLine::setPoLineId(int poLineId)
{
    d->po_line_id = poLineId;
}

int PoLineKitLine::kitPartNoId() const
{
    return d->kit_part_no_id;
}

void PoLineKitLine::setKitPartNoId(int kitPartNoId)
{
    d->kit_part_no_id = kitPartNoId;
}

int PoLineKitLine::partNoId() const
{
    return d->part_no_id;
}

void PoLineKitLine::setPartNoId(int partNoId)
{
    d->part_no_id = partNoId;
}

int PoLineKitLine::kitQt() const
{
    return d->kit_qt;
}

void PoLineKitLine::setKitQt(int kitQt)
{
    d->kit_qt = kitQt;
}

double PoLineKitLine::valuePct() const
{
    return d->value_pct;
}

void PoLineKitLine::setValuePct(double valuePct)
{
    d->value_pct = valuePct;
}

double PoLineKitLine::unitPrice() const
{
    return d->unit_price;
}

void PoLineKitLine::setUnitPrice(double unitPrice)
{
    d->unit_price = unitPrice;
}

QDateTime PoLineKitLine::createdAt() const
{
    return d->created_at;
}

QString PoLineKitLine::createdBy() const
{
    return d->created_by;
}

void PoLineKitLine::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime PoLineKitLine::updatedAt() const
{
    return d->updated_at;
}

QString PoLineKitLine::updatedBy() const
{
    return d->updated_by;
}

void PoLineKitLine::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

EqpKitPartNo PoLineKitLine::eqpKitPartNoBykitPartNoIdpartNoId() const
{
 return EqpKitPartNo::get(d->kit_part_no_id, d->part_no_id);
}

PoLine PoLineKitLine::poLineBypoLineId() const
{
 return PoLine::get(d->po_line_id);
}

PoLineKitLine &PoLineKitLine::operator=(const PoLineKitLine &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

PoLineKitLine PoLineKitLine::create(int poLineId, int kitPartNoId, int partNoId, int kitQt, double valuePct, double unitPrice, const QString &createdBy, const QString &updatedBy)
{
    PoLineKitLineObject obj;
    obj.po_line_id = poLineId;
    obj.kit_part_no_id = kitPartNoId;
    obj.part_no_id = partNoId;
    obj.kit_qt = kitQt;
    obj.value_pct = valuePct;
    obj.unit_price = unitPrice;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return PoLineKitLine();
    }
    return PoLineKitLine(obj);
}

PoLineKitLine PoLineKitLine::create(const QVariantMap &values)
{
    PoLineKitLine model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

PoLineKitLine PoLineKitLine::get(int poLineId, int kitPartNoId, int partNoId)
{
    TSqlORMapper<PoLineKitLineObject> mapper;
    return PoLineKitLine(mapper.findByPrimaryKey(QVariantList()<<QVariant(poLineId)<<QVariant(kitPartNoId)<<QVariant(partNoId)));
}

int PoLineKitLine::count()
{
    TSqlORMapper<PoLineKitLineObject> mapper;
    return mapper.findCount();
}

QList<PoLineKitLine> PoLineKitLine::getAll()
{
    return tfGetModelListByCriteria<PoLineKitLine, PoLineKitLineObject>();
}

TModelObject *PoLineKitLine::modelData()
{
    return d.data();
}

const TModelObject *PoLineKitLine::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const PoLineKitLine &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, PoLineKitLine &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(PoLineKitLine)
