#include <TreeFrogModel>
#include "refsegmentstatus.h"
#include "refsegmentstatusobject.h"

RefSegmentStatus::RefSegmentStatus()
    : TAbstractModel(), d(new RefSegmentStatusObject())
{ }

RefSegmentStatus::RefSegmentStatus(const RefSegmentStatus &other)
    : TAbstractModel(), d(new RefSegmentStatusObject(*other.d))
{ }

RefSegmentStatus::RefSegmentStatus(const RefSegmentStatusObject &object)
    : TAbstractModel(), d(new RefSegmentStatusObject(object))
{ }

RefSegmentStatus::~RefSegmentStatus()
{
    // If the reference count becomes 0,
    // the shared data object 'RefSegmentStatusObject' is deleted.
}

QString RefSegmentStatus::segmentStatusCd() const
{
    return d->segment_status_cd;
}

void RefSegmentStatus::setSegmentStatusCd(const QString &segmentStatusCd)
{
    d->segment_status_cd = segmentStatusCd;
}

QString RefSegmentStatus::segmentStatusNameEn() const
{
    return d->segment_status_name_en;
}

void RefSegmentStatus::setSegmentStatusNameEn(const QString &segmentStatusNameEn)
{
    d->segment_status_name_en = segmentStatusNameEn;
}

QString RefSegmentStatus::segmentStatusNameZh() const
{
    return d->segment_status_name_zh;
}

void RefSegmentStatus::setSegmentStatusNameZh(const QString &segmentStatusNameZh)
{
    d->segment_status_name_zh = segmentStatusNameZh;
}

QString RefSegmentStatus::segmentStatusDesc() const
{
    return d->segment_status_desc;
}

void RefSegmentStatus::setSegmentStatusDesc(const QString &segmentStatusDesc)
{
    d->segment_status_desc = segmentStatusDesc;
}

QDateTime RefSegmentStatus::createdAt() const
{
    return d->created_at;
}

QString RefSegmentStatus::createdBy() const
{
    return d->created_by;
}

void RefSegmentStatus::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime RefSegmentStatus::updatedAt() const
{
    return d->updated_at;
}

QString RefSegmentStatus::updatedBy() const
{
    return d->updated_by;
}

void RefSegmentStatus::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

RefSegmentStatus &RefSegmentStatus::operator=(const RefSegmentStatus &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

RefSegmentStatus RefSegmentStatus::create(const QString &segmentStatusCd, const QString &segmentStatusNameEn, const QString &segmentStatusNameZh, const QString &segmentStatusDesc, const QString &createdBy, const QString &updatedBy)
{
    RefSegmentStatusObject obj;
    obj.segment_status_cd = segmentStatusCd;
    obj.segment_status_name_en = segmentStatusNameEn;
    obj.segment_status_name_zh = segmentStatusNameZh;
    obj.segment_status_desc = segmentStatusDesc;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return RefSegmentStatus();
    }
    return RefSegmentStatus(obj);
}

RefSegmentStatus RefSegmentStatus::create(const QVariantMap &values)
{
    RefSegmentStatus model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

RefSegmentStatus RefSegmentStatus::get(const QString &segmentStatusCd)
{
    TSqlORMapper<RefSegmentStatusObject> mapper;
    return RefSegmentStatus(mapper.findByPrimaryKey(segmentStatusCd));
}

int RefSegmentStatus::count()
{
    TSqlORMapper<RefSegmentStatusObject> mapper;
    return mapper.findCount();
}

QList<RefSegmentStatus> RefSegmentStatus::getAll()
{
    return tfGetModelListByCriteria<RefSegmentStatus, RefSegmentStatusObject>();
}

TModelObject *RefSegmentStatus::modelData()
{
    return d.data();
}

const TModelObject *RefSegmentStatus::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const RefSegmentStatus &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, RefSegmentStatus &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(RefSegmentStatus)
