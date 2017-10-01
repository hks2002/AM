#include <TreeFrogModel>
#include "reflabourstage.h"
#include "reflabourstageobject.h"

RefLabourStage::RefLabourStage()
    : TAbstractModel(), d(new RefLabourStageObject())
{ }

RefLabourStage::RefLabourStage(const RefLabourStage &other)
    : TAbstractModel(), d(new RefLabourStageObject(*other.d))
{ }

RefLabourStage::RefLabourStage(const RefLabourStageObject &object)
    : TAbstractModel(), d(new RefLabourStageObject(object))
{ }

RefLabourStage::~RefLabourStage()
{
    // If the reference count becomes 0,
    // the shared data object 'RefLabourStageObject' is deleted.
}

QString RefLabourStage::labourStageCd() const
{
    return d->labour_stage_cd;
}

void RefLabourStage::setLabourStageCd(const QString &labourStageCd)
{
    d->labour_stage_cd = labourStageCd;
}

QString RefLabourStage::labourStageNameEn() const
{
    return d->labour_stage_name_en;
}

void RefLabourStage::setLabourStageNameEn(const QString &labourStageNameEn)
{
    d->labour_stage_name_en = labourStageNameEn;
}

QString RefLabourStage::labourStageNameZh() const
{
    return d->labour_stage_name_zh;
}

void RefLabourStage::setLabourStageNameZh(const QString &labourStageNameZh)
{
    d->labour_stage_name_zh = labourStageNameZh;
}

QString RefLabourStage::labourStageDesc() const
{
    return d->labour_stage_desc;
}

void RefLabourStage::setLabourStageDesc(const QString &labourStageDesc)
{
    d->labour_stage_desc = labourStageDesc;
}

QDateTime RefLabourStage::createdAt() const
{
    return d->created_at;
}

QString RefLabourStage::createdBy() const
{
    return d->created_by;
}

void RefLabourStage::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime RefLabourStage::updatedAt() const
{
    return d->updated_at;
}

QString RefLabourStage::updatedBy() const
{
    return d->updated_by;
}

void RefLabourStage::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

RefLabourStage &RefLabourStage::operator=(const RefLabourStage &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

RefLabourStage RefLabourStage::create(const QString &labourStageCd, const QString &labourStageNameEn, const QString &labourStageNameZh, const QString &labourStageDesc, const QString &createdBy, const QString &updatedBy)
{
    RefLabourStageObject obj;
    obj.labour_stage_cd = labourStageCd;
    obj.labour_stage_name_en = labourStageNameEn;
    obj.labour_stage_name_zh = labourStageNameZh;
    obj.labour_stage_desc = labourStageDesc;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return RefLabourStage();
    }
    return RefLabourStage(obj);
}

RefLabourStage RefLabourStage::create(const QVariantMap &values)
{
    RefLabourStage model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

RefLabourStage RefLabourStage::get(const QString &labourStageCd)
{
    TSqlORMapper<RefLabourStageObject> mapper;
    return RefLabourStage(mapper.findByPrimaryKey(labourStageCd));
}

int RefLabourStage::count()
{
    TSqlORMapper<RefLabourStageObject> mapper;
    return mapper.findCount();
}

QList<RefLabourStage> RefLabourStage::getAll()
{
    return tfGetModelListByCriteria<RefLabourStage, RefLabourStageObject>();
}

TModelObject *RefLabourStage::modelData()
{
    return d.data();
}

const TModelObject *RefLabourStage::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const RefLabourStage &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, RefLabourStage &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(RefLabourStage)
