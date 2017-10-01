#ifndef SCHEDWPCOSTLINEITEM_H
#define SCHEDWPCOSTLINEITEM_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class SchedWpCostLineItemObject;
class PoInvoice;
class Currency;
class RefCostLineItemType;
class SchedWp;


class T_MODEL_EXPORT SchedWpCostLineItem : public TAbstractModel
{
public:
    SchedWpCostLineItem();
    SchedWpCostLineItem(const SchedWpCostLineItem &other);
    SchedWpCostLineItem(const SchedWpCostLineItemObject &object);
    ~SchedWpCostLineItem();

    int schedId() const;
    void setSchedId(int schedId);
    QString costLineItemTypeCd() const;
    void setCostLineItemTypeCd(const QString &costLineItemTypeCd);
    double initExpCost() const;
    void setInitExpCost(double initExpCost);
    double expCost() const;
    void setExpCost(double expCost);
    double actualCost() const;
    void setActualCost(double actualCost);
    int currencyId() const;
    void setCurrencyId(int currencyId);
    QString itemNote() const;
    void setItemNote(const QString &itemNote);
    int invoiceId() const;
    void setInvoiceId(int invoiceId);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    PoInvoice poInvoiceByinvoiceId() const;
    Currency currencyBycurrencyId() const;
    RefCostLineItemType refCostLineItemTypeBycostLineItemTypeCd() const;
    SchedWp schedWpByschedId() const;
    SchedWpCostLineItem &operator=(const SchedWpCostLineItem &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static SchedWpCostLineItem create(int schedId, const QString &costLineItemTypeCd, double initExpCost, double expCost, double actualCost, int currencyId, const QString &itemNote, int invoiceId, const QString &createdBy, const QString &updatedBy);
    static SchedWpCostLineItem create(const QVariantMap &values);
    static SchedWpCostLineItem get(int schedId, const QString &costLineItemTypeCd);
    static int count();
    static QList<SchedWpCostLineItem> getAll();

private:
    QSharedDataPointer<SchedWpCostLineItemObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const SchedWpCostLineItem &model);
    friend QDataStream &operator>>(QDataStream &ds, SchedWpCostLineItem &model);
};

Q_DECLARE_METATYPE(SchedWpCostLineItem)
Q_DECLARE_METATYPE(QList<SchedWpCostLineItem>)

#endif // SCHEDWPCOSTLINEITEM_H
