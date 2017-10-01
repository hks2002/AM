#include <TreeFrogModel>
#include "eqppanel.h"
#include "eqppanelobject.h"
#include "eqpassmbl.h"

EqpPanel::EqpPanel()
    : TAbstractModel(), d(new EqpPanelObject())
{
    d->panel_id = 0;
    d->assmbl_id = 0;
}

EqpPanel::EqpPanel(const EqpPanel &other)
    : TAbstractModel(), d(new EqpPanelObject(*other.d))
{ }

EqpPanel::EqpPanel(const EqpPanelObject &object)
    : TAbstractModel(), d(new EqpPanelObject(object))
{ }

EqpPanel::~EqpPanel()
{
    // If the reference count becomes 0,
    // the shared data object 'EqpPanelObject' is deleted.
}

int EqpPanel::panelId() const
{
    return d->panel_id;
}

int EqpPanel::assmblId() const
{
    return d->assmbl_id;
}

void EqpPanel::setAssmblId(int assmblId)
{
    d->assmbl_id = assmblId;
}

QString EqpPanel::panelCd() const
{
    return d->panel_cd;
}

void EqpPanel::setPanelCd(const QString &panelCd)
{
    d->panel_cd = panelCd;
}

QString EqpPanel::descDesc() const
{
    return d->desc_desc;
}

void EqpPanel::setDescDesc(const QString &descDesc)
{
    d->desc_desc = descDesc;
}

QDateTime EqpPanel::createdAt() const
{
    return d->created_at;
}

QString EqpPanel::createdBy() const
{
    return d->created_by;
}

void EqpPanel::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime EqpPanel::updatedAt() const
{
    return d->updated_at;
}

QString EqpPanel::updatedBy() const
{
    return d->updated_by;
}

void EqpPanel::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

EqpAssmbl EqpPanel::eqpAssmblByassmblId() const
{
 return EqpAssmbl::get(d->assmbl_id);
}

EqpPanel &EqpPanel::operator=(const EqpPanel &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

EqpPanel EqpPanel::create(int assmblId, const QString &panelCd, const QString &descDesc, const QString &createdBy, const QString &updatedBy)
{
    EqpPanelObject obj;
    obj.assmbl_id = assmblId;
    obj.panel_cd = panelCd;
    obj.desc_desc = descDesc;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return EqpPanel();
    }
    return EqpPanel(obj);
}

EqpPanel EqpPanel::create(const QVariantMap &values)
{
    EqpPanel model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

EqpPanel EqpPanel::get(int panelId)
{
    TSqlORMapper<EqpPanelObject> mapper;
    return EqpPanel(mapper.findByPrimaryKey(panelId));
}

int EqpPanel::count()
{
    TSqlORMapper<EqpPanelObject> mapper;
    return mapper.findCount();
}

QList<EqpPanel> EqpPanel::getAll()
{
    return tfGetModelListByCriteria<EqpPanel, EqpPanelObject>();
}

TModelObject *EqpPanel::modelData()
{
    return d.data();
}

const TModelObject *EqpPanel::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const EqpPanel &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, EqpPanel &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(EqpPanel)
