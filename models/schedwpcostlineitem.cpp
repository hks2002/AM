#include <TreeFrogModel>
#include "schedwpcostlineitem.h"
#include "schedwpcostlineitemobject.h"
#include "poinvoice.h"
#include "currency.h"
#include "refcostlineitemtype.h"
#include "schedwp.h"

SchedWpCostLineItem::SchedWpCostLineItem()
    : TAbstractModel(), d(new SchedWpCostLineItemObject())
{
    d->sched_id = 0;
    d->init_exp_cost = 0;
    d->exp_cost = 0;
    d->actual_cost = 0;
    d->currency_id = 0;
    d->invoice_id = 0;
}

SchedWpCostLineItem::SchedWpCostLineItem(const SchedWpCostLineItem &other)
    : TAbstractModel(), d(new SchedWpCostLineItemObject(*other.d))
{ }

SchedWpCostLineItem::SchedWpCostLineItem(const SchedWpCostLineItemObject &object)
    : TAbstractModel(), d(new SchedWpCostLineItemObject(object))
{ }

SchedWpCostLineItem::~SchedWpCostLineItem()
{
    // If the reference count becomes 0,
    // the shared data object 'SchedWpCostLineItemObject' is deleted.
}

int SchedWpCostLineItem::schedId() const
{
    return d->sched_id;
}

void SchedWpCostLineItem::setSchedId(int schedId)
{
    d->sched_id = schedId;
}

QString SchedWpCostLineItem::costLineItemTypeCd() const
{
    return d->cost_line_item_type_cd;
}

void SchedWpCostLineItem::setCostLineItemTypeCd(const QString &costLineItemTypeCd)
{
    d->cost_line_item_type_cd = costLineItemTypeCd;
}

double SchedWpCostLineItem::initExpCost() const
{
    return d->init_exp_cost;
}

void SchedWpCostLineItem::setInitExpCost(double initExpCost)
{
    d->init_exp_cost = initExpCost;
}

double SchedWpCostLineItem::expCost() const
{
    return d->exp_cost;
}

void SchedWpCostLineItem::setExpCost(double expCost)
{
    d->exp_cost = expCost;
}

double SchedWpCostLineItem::actualCost() const
{
    return d->actual_cost;
}

void SchedWpCostLineItem::setActualCost(double actualCost)
{
    d->actual_cost = actualCost;
}

int SchedWpCostLineItem::currencyId() const
{
    return d->currency_id;
}

void SchedWpCostLineItem::setCurrencyId(int currencyId)
{
    d->currency_id = currencyId;
}

QString SchedWpCostLineItem::itemNote() const
{
    return d->item_note;
}

void SchedWpCostLineItem::setItemNote(const QString &itemNote)
{
    d->item_note = itemNote;
}

int SchedWpCostLineItem::invoiceId() const
{
    return d->invoice_id;
}

void SchedWpCostLineItem::setInvoiceId(int invoiceId)
{
    d->invoice_id = invoiceId;
}

QDateTime SchedWpCostLineItem::createdAt() const
{
    return d->created_at;
}

QString SchedWpCostLineItem::createdBy() const
{
    return d->created_by;
}

void SchedWpCostLineItem::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime SchedWpCostLineItem::updatedAt() const
{
    return d->updated_at;
}

QString SchedWpCostLineItem::updatedBy() const
{
    return d->updated_by;
}

void SchedWpCostLineItem::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

PoInvoice SchedWpCostLineItem::poInvoiceByinvoiceId() const
{
 return PoInvoice::get(d->invoice_id);
}

Currency SchedWpCostLineItem::currencyBycurrencyId() const
{
 return Currency::get(d->currency_id);
}

RefCostLineItemType SchedWpCostLineItem::refCostLineItemTypeBycostLineItemTypeCd() const
{
 return RefCostLineItemType::get(d->cost_line_item_type_cd);
}

SchedWp SchedWpCostLineItem::schedWpByschedId() const
{
 return SchedWp::get(d->sched_id);
}

SchedWpCostLineItem &SchedWpCostLineItem::operator=(const SchedWpCostLineItem &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

SchedWpCostLineItem SchedWpCostLineItem::create(int schedId, const QString &costLineItemTypeCd, double initExpCost, double expCost, double actualCost, int currencyId, const QString &itemNote, int invoiceId, const QString &createdBy, const QString &updatedBy)
{
    SchedWpCostLineItemObject obj;
    obj.sched_id = schedId;
    obj.cost_line_item_type_cd = costLineItemTypeCd;
    obj.init_exp_cost = initExpCost;
    obj.exp_cost = expCost;
    obj.actual_cost = actualCost;
    obj.currency_id = currencyId;
    obj.item_note = itemNote;
    obj.invoice_id = invoiceId;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return SchedWpCostLineItem();
    }
    return SchedWpCostLineItem(obj);
}

SchedWpCostLineItem SchedWpCostLineItem::create(const QVariantMap &values)
{
    SchedWpCostLineItem model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

SchedWpCostLineItem SchedWpCostLineItem::get(int schedId, const QString &costLineItemTypeCd)
{
    TSqlORMapper<SchedWpCostLineItemObject> mapper;
    return SchedWpCostLineItem(mapper.findByPrimaryKey(QVariantList()<<QVariant(schedId)<<QVariant(costLineItemTypeCd)));
}

int SchedWpCostLineItem::count()
{
    TSqlORMapper<SchedWpCostLineItemObject> mapper;
    return mapper.findCount();
}

QList<SchedWpCostLineItem> SchedWpCostLineItem::getAll()
{
    return tfGetModelListByCriteria<SchedWpCostLineItem, SchedWpCostLineItemObject>();
}

TModelObject *SchedWpCostLineItem::modelData()
{
    return d.data();
}

const TModelObject *SchedWpCostLineItem::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const SchedWpCostLineItem &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, SchedWpCostLineItem &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(SchedWpCostLineItem)
