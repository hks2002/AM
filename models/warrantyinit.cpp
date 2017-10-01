#include <TreeFrogModel>
#include "warrantyinit.h"
#include "warrantyinitobject.h"
#include "refwarrantypriority.h"
#include "warrantydefn.h"

WarrantyInit::WarrantyInit()
    : TAbstractModel(), d(new WarrantyInitObject())
{
    d->warranty_init_id = 0;
    d->warranty_defn_id = 0;
    d->start_tsn_hours_qt = 0;
    d->end_tsn_hours_qt = 0;
    d->start_tsn_cycles_qt = 0;
    d->end_tsn_cycles_qt = 0;
}

WarrantyInit::WarrantyInit(const WarrantyInit &other)
    : TAbstractModel(), d(new WarrantyInitObject(*other.d))
{ }

WarrantyInit::WarrantyInit(const WarrantyInitObject &object)
    : TAbstractModel(), d(new WarrantyInitObject(object))
{ }

WarrantyInit::~WarrantyInit()
{
    // If the reference count becomes 0,
    // the shared data object 'WarrantyInitObject' is deleted.
}

int WarrantyInit::warrantyInitId() const
{
    return d->warranty_init_id;
}

int WarrantyInit::warrantyDefnId() const
{
    return d->warranty_defn_id;
}

void WarrantyInit::setWarrantyDefnId(int warrantyDefnId)
{
    d->warranty_defn_id = warrantyDefnId;
}

QString WarrantyInit::warrantyPriorityCd() const
{
    return d->warranty_priority_cd;
}

void WarrantyInit::setWarrantyPriorityCd(const QString &warrantyPriorityCd)
{
    d->warranty_priority_cd = warrantyPriorityCd;
}

bool WarrantyInit::expiresFirstBool() const
{
    return d->expires_first_bool;
}

void WarrantyInit::setExpiresFirstBool(bool expiresFirstBool)
{
    d->expires_first_bool = expiresFirstBool;
}

QDateTime WarrantyInit::startDt() const
{
    return d->start_dt;
}

void WarrantyInit::setStartDt(const QDateTime &startDt)
{
    d->start_dt = startDt;
}

QDateTime WarrantyInit::endDt() const
{
    return d->end_dt;
}

void WarrantyInit::setEndDt(const QDateTime &endDt)
{
    d->end_dt = endDt;
}

double WarrantyInit::startTsnHoursQt() const
{
    return d->start_tsn_hours_qt;
}

void WarrantyInit::setStartTsnHoursQt(double startTsnHoursQt)
{
    d->start_tsn_hours_qt = startTsnHoursQt;
}

double WarrantyInit::endTsnHoursQt() const
{
    return d->end_tsn_hours_qt;
}

void WarrantyInit::setEndTsnHoursQt(double endTsnHoursQt)
{
    d->end_tsn_hours_qt = endTsnHoursQt;
}

int WarrantyInit::startTsnCyclesQt() const
{
    return d->start_tsn_cycles_qt;
}

void WarrantyInit::setStartTsnCyclesQt(int startTsnCyclesQt)
{
    d->start_tsn_cycles_qt = startTsnCyclesQt;
}

int WarrantyInit::endTsnCyclesQt() const
{
    return d->end_tsn_cycles_qt;
}

void WarrantyInit::setEndTsnCyclesQt(int endTsnCyclesQt)
{
    d->end_tsn_cycles_qt = endTsnCyclesQt;
}

bool WarrantyInit::expiredBool() const
{
    return d->expired_bool;
}

void WarrantyInit::setExpiredBool(bool expiredBool)
{
    d->expired_bool = expiredBool;
}

QDateTime WarrantyInit::createdAt() const
{
    return d->created_at;
}

QString WarrantyInit::createdBy() const
{
    return d->created_by;
}

void WarrantyInit::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime WarrantyInit::updatedAt() const
{
    return d->updated_at;
}

QString WarrantyInit::updatedBy() const
{
    return d->updated_by;
}

void WarrantyInit::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

RefWarrantyPriority WarrantyInit::refWarrantyPriorityBywarrantyPriorityCd() const
{
 return RefWarrantyPriority::get(d->warranty_priority_cd);
}

WarrantyDefn WarrantyInit::warrantyDefnBywarrantyDefnId() const
{
 return WarrantyDefn::get(d->warranty_defn_id);
}

WarrantyInit &WarrantyInit::operator=(const WarrantyInit &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

WarrantyInit WarrantyInit::create(int warrantyDefnId, const QString &warrantyPriorityCd, bool expiresFirstBool, const QDateTime &startDt, const QDateTime &endDt, double startTsnHoursQt, double endTsnHoursQt, int startTsnCyclesQt, int endTsnCyclesQt, bool expiredBool, const QString &createdBy, const QString &updatedBy)
{
    WarrantyInitObject obj;
    obj.warranty_defn_id = warrantyDefnId;
    obj.warranty_priority_cd = warrantyPriorityCd;
    obj.expires_first_bool = expiresFirstBool;
    obj.start_dt = startDt;
    obj.end_dt = endDt;
    obj.start_tsn_hours_qt = startTsnHoursQt;
    obj.end_tsn_hours_qt = endTsnHoursQt;
    obj.start_tsn_cycles_qt = startTsnCyclesQt;
    obj.end_tsn_cycles_qt = endTsnCyclesQt;
    obj.expired_bool = expiredBool;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return WarrantyInit();
    }
    return WarrantyInit(obj);
}

WarrantyInit WarrantyInit::create(const QVariantMap &values)
{
    WarrantyInit model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

WarrantyInit WarrantyInit::get(int warrantyInitId)
{
    TSqlORMapper<WarrantyInitObject> mapper;
    return WarrantyInit(mapper.findByPrimaryKey(warrantyInitId));
}

int WarrantyInit::count()
{
    TSqlORMapper<WarrantyInitObject> mapper;
    return mapper.findCount();
}

QList<WarrantyInit> WarrantyInit::getAll()
{
    return tfGetModelListByCriteria<WarrantyInit, WarrantyInitObject>();
}

TModelObject *WarrantyInit::modelData()
{
    return d.data();
}

const TModelObject *WarrantyInit::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const WarrantyInit &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, WarrantyInit &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(WarrantyInit)
