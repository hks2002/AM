#ifndef POINVOICELINE_H
#define POINVOICELINE_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class PoInvoiceLineObject;
class FncAccount;
class QtyUnit;
class EqpPartNo;
class PoInvoice;


class T_MODEL_EXPORT PoInvoiceLine : public TAbstractModel
{
public:
    PoInvoiceLine();
    PoInvoiceLine(const PoInvoiceLine &other);
    PoInvoiceLine(const PoInvoiceLineObject &object);
    ~PoInvoiceLine();

    int poInvoiceLineId() const;
    int poInvoiceId() const;
    void setPoInvoiceId(int poInvoiceId);
    int lineNoOrd() const;
    void setLineNoOrd(int lineNoOrd);
    QString lineDesc() const;
    void setLineDesc(const QString &lineDesc);
    int partNoId() const;
    void setPartNoId(int partNoId);
    int invoiceQt() const;
    void setInvoiceQt(int invoiceQt);
    int qtyUnitId() const;
    void setQtyUnitId(int qtyUnitId);
    double unitPrice() const;
    void setUnitPrice(double unitPrice);
    double linePrice() const;
    void setLinePrice(double linePrice);
    QString invoiceLineNote() const;
    void setInvoiceLineNote(const QString &invoiceLineNote);
    bool csgnBool() const;
    void setCsgnBool(bool csgnBool);
    int accountId() const;
    void setAccountId(int accountId);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    FncAccount fncAccountByaccountId() const;
    QtyUnit qtyUnitByqtyUnitId() const;
    EqpPartNo eqpPartNoBypartNoId() const;
    PoInvoice poInvoiceBypoInvoiceId() const;
    PoInvoiceLine &operator=(const PoInvoiceLine &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static PoInvoiceLine create(int poInvoiceId, int lineNoOrd, const QString &lineDesc, int partNoId, int invoiceQt, int qtyUnitId, double unitPrice, double linePrice, const QString &invoiceLineNote, bool csgnBool, int accountId, const QString &createdBy, const QString &updatedBy);
    static PoInvoiceLine create(const QVariantMap &values);
    static PoInvoiceLine get(int poInvoiceLineId);
    static int count();
    static QList<PoInvoiceLine> getAll();

private:
    QSharedDataPointer<PoInvoiceLineObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const PoInvoiceLine &model);
    friend QDataStream &operator>>(QDataStream &ds, PoInvoiceLine &model);
};

Q_DECLARE_METATYPE(PoInvoiceLine)
Q_DECLARE_METATYPE(QList<PoInvoiceLine>)

#endif // POINVOICELINE_H
