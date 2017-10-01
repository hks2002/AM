#include <TreeFrogModel>
#include "refpolinetype.h"
#include "refpolinetypeobject.h"

RefPoLineType::RefPoLineType()
    : TAbstractModel(), d(new RefPoLineTypeObject())
{ }

RefPoLineType::RefPoLineType(const RefPoLineType &other)
    : TAbstractModel(), d(new RefPoLineTypeObject(*other.d))
{ }

RefPoLineType::RefPoLineType(const RefPoLineTypeObject &object)
    : TAbstractModel(), d(new RefPoLineTypeObject(object))
{ }

RefPoLineType::~RefPoLineType()
{
    // If the reference count becomes 0,
    // the shared data object 'RefPoLineTypeObject' is deleted.
}

QString RefPoLineType::poLineTypeCd() const
{
    return d->po_line_type_cd;
}

void RefPoLineType::setPoLineTypeCd(const QString &poLineTypeCd)
{
    d->po_line_type_cd = poLineTypeCd;
}

QString RefPoLineType::poLineTypeNameEn() const
{
    return d->po_line_type_name_en;
}

void RefPoLineType::setPoLineTypeNameEn(const QString &poLineTypeNameEn)
{
    d->po_line_type_name_en = poLineTypeNameEn;
}

QString RefPoLineType::poLineTypeNameZh() const
{
    return d->po_line_type_name_zh;
}

void RefPoLineType::setPoLineTypeNameZh(const QString &poLineTypeNameZh)
{
    d->po_line_type_name_zh = poLineTypeNameZh;
}

QString RefPoLineType::poLineTypeDesc() const
{
    return d->po_line_type_desc;
}

void RefPoLineType::setPoLineTypeDesc(const QString &poLineTypeDesc)
{
    d->po_line_type_desc = poLineTypeDesc;
}

QDateTime RefPoLineType::createdAt() const
{
    return d->created_at;
}

QString RefPoLineType::createdBy() const
{
    return d->created_by;
}

void RefPoLineType::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime RefPoLineType::updatedAt() const
{
    return d->updated_at;
}

QString RefPoLineType::updatedBy() const
{
    return d->updated_by;
}

void RefPoLineType::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

RefPoLineType &RefPoLineType::operator=(const RefPoLineType &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

RefPoLineType RefPoLineType::create(const QString &poLineTypeCd, const QString &poLineTypeNameEn, const QString &poLineTypeNameZh, const QString &poLineTypeDesc, const QString &createdBy, const QString &updatedBy)
{
    RefPoLineTypeObject obj;
    obj.po_line_type_cd = poLineTypeCd;
    obj.po_line_type_name_en = poLineTypeNameEn;
    obj.po_line_type_name_zh = poLineTypeNameZh;
    obj.po_line_type_desc = poLineTypeDesc;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return RefPoLineType();
    }
    return RefPoLineType(obj);
}

RefPoLineType RefPoLineType::create(const QVariantMap &values)
{
    RefPoLineType model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

RefPoLineType RefPoLineType::get(const QString &poLineTypeCd)
{
    TSqlORMapper<RefPoLineTypeObject> mapper;
    return RefPoLineType(mapper.findByPrimaryKey(poLineTypeCd));
}

int RefPoLineType::count()
{
    TSqlORMapper<RefPoLineTypeObject> mapper;
    return mapper.findCount();
}

QList<RefPoLineType> RefPoLineType::getAll()
{
    return tfGetModelListByCriteria<RefPoLineType, RefPoLineTypeObject>();
}

TModelObject *RefPoLineType::modelData()
{
    return d.data();
}

const TModelObject *RefPoLineType::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const RefPoLineType &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, RefPoLineType &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(RefPoLineType)
