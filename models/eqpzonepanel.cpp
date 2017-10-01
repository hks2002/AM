#include <TreeFrogModel>
#include "eqpzonepanel.h"
#include "eqpzonepanelobject.h"
#include "eqppanel.h"
#include "eqpzone.h"
#include "eqpassmbl.h"

EqpZonePanel::EqpZonePanel()
    : TAbstractModel(), d(new EqpZonePanelObject())
{
    d->zone_panel_id = 0;
    d->assmbl_id = 0;
    d->zone_id = 0;
    d->panel_id = 0;
}

EqpZonePanel::EqpZonePanel(const EqpZonePanel &other)
    : TAbstractModel(), d(new EqpZonePanelObject(*other.d))
{ }

EqpZonePanel::EqpZonePanel(const EqpZonePanelObject &object)
    : TAbstractModel(), d(new EqpZonePanelObject(object))
{ }

EqpZonePanel::~EqpZonePanel()
{
    // If the reference count becomes 0,
    // the shared data object 'EqpZonePanelObject' is deleted.
}

int EqpZonePanel::zonePanelId() const
{
    return d->zone_panel_id;
}

int EqpZonePanel::assmblId() const
{
    return d->assmbl_id;
}

void EqpZonePanel::setAssmblId(int assmblId)
{
    d->assmbl_id = assmblId;
}

int EqpZonePanel::zoneId() const
{
    return d->zone_id;
}

void EqpZonePanel::setZoneId(int zoneId)
{
    d->zone_id = zoneId;
}

int EqpZonePanel::panelId() const
{
    return d->panel_id;
}

void EqpZonePanel::setPanelId(int panelId)
{
    d->panel_id = panelId;
}

QDateTime EqpZonePanel::createdAt() const
{
    return d->created_at;
}

QString EqpZonePanel::createdBy() const
{
    return d->created_by;
}

void EqpZonePanel::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime EqpZonePanel::updatedAt() const
{
    return d->updated_at;
}

QString EqpZonePanel::updatedBy() const
{
    return d->updated_by;
}

void EqpZonePanel::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

EqpPanel EqpZonePanel::eqpPanelBypanelId() const
{
 return EqpPanel::get(d->panel_id);
}

EqpZone EqpZonePanel::eqpZoneByzoneId() const
{
 return EqpZone::get(d->zone_id);
}

EqpAssmbl EqpZonePanel::eqpAssmblByassmblId() const
{
 return EqpAssmbl::get(d->assmbl_id);
}

EqpZonePanel &EqpZonePanel::operator=(const EqpZonePanel &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

EqpZonePanel EqpZonePanel::create(int assmblId, int zoneId, int panelId, const QString &createdBy, const QString &updatedBy)
{
    EqpZonePanelObject obj;
    obj.assmbl_id = assmblId;
    obj.zone_id = zoneId;
    obj.panel_id = panelId;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return EqpZonePanel();
    }
    return EqpZonePanel(obj);
}

EqpZonePanel EqpZonePanel::create(const QVariantMap &values)
{
    EqpZonePanel model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

EqpZonePanel EqpZonePanel::get(int zonePanelId)
{
    TSqlORMapper<EqpZonePanelObject> mapper;
    return EqpZonePanel(mapper.findByPrimaryKey(zonePanelId));
}

int EqpZonePanel::count()
{
    TSqlORMapper<EqpZonePanelObject> mapper;
    return mapper.findCount();
}

QList<EqpZonePanel> EqpZonePanel::getAll()
{
    return tfGetModelListByCriteria<EqpZonePanel, EqpZonePanelObject>();
}

TModelObject *EqpZonePanel::modelData()
{
    return d.data();
}

const TModelObject *EqpZonePanel::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const EqpZonePanel &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, EqpZonePanel &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(EqpZonePanel)
