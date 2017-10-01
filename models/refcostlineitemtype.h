#ifndef REFCOSTLINEITEMTYPE_H
#define REFCOSTLINEITEMTYPE_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class RefCostLineItemTypeObject;


class T_MODEL_EXPORT RefCostLineItemType : public TAbstractModel
{
public:
    RefCostLineItemType();
    RefCostLineItemType(const RefCostLineItemType &other);
    RefCostLineItemType(const RefCostLineItemTypeObject &object);
    ~RefCostLineItemType();

    QString costLineItemTypeCd() const;
    void setCostLineItemTypeCd(const QString &costLineItemTypeCd);
    QString costLineItemTypeNameEn() const;
    void setCostLineItemTypeNameEn(const QString &costLineItemTypeNameEn);
    QString costLineItemTypeNameZh() const;
    void setCostLineItemTypeNameZh(const QString &costLineItemTypeNameZh);
    QString costLineItemTypeDesc() const;
    void setCostLineItemTypeDesc(const QString &costLineItemTypeDesc);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    RefCostLineItemType &operator=(const RefCostLineItemType &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static RefCostLineItemType create(const QString &costLineItemTypeCd, const QString &costLineItemTypeNameEn, const QString &costLineItemTypeNameZh, const QString &costLineItemTypeDesc, const QString &createdBy, const QString &updatedBy);
    static RefCostLineItemType create(const QVariantMap &values);
    static RefCostLineItemType get(const QString &costLineItemTypeCd);
    static int count();
    static QList<RefCostLineItemType> getAll();

private:
    QSharedDataPointer<RefCostLineItemTypeObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const RefCostLineItemType &model);
    friend QDataStream &operator>>(QDataStream &ds, RefCostLineItemType &model);
};

Q_DECLARE_METATYPE(RefCostLineItemType)
Q_DECLARE_METATYPE(QList<RefCostLineItemType>)

#endif // REFCOSTLINEITEMTYPE_H
