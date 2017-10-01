#ifndef POINVOICELINETAX_H
#define POINVOICELINETAX_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class PoInvoiceLineTaxObject;
class Tax;
class PoInvoiceLine;


class T_MODEL_EXPORT PoInvoiceLineTax : public TAbstractModel
{
public:
    PoInvoiceLineTax();
    PoInvoiceLineTax(const PoInvoiceLineTax &other);
    PoInvoiceLineTax(const PoInvoiceLineTaxObject &object);
    ~PoInvoiceLineTax();

    int poInvoiceLineId() const;
    void setPoInvoiceLineId(int poInvoiceLineId);
    int taxId() const;
    void setTaxId(int taxId);
    double taxAmount() const;
    void setTaxAmount(double taxAmount);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    Tax taxBytaxId() const;
    PoInvoiceLine poInvoiceLineBypoInvoiceLineId() const;
    PoInvoiceLineTax &operator=(const PoInvoiceLineTax &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static PoInvoiceLineTax create(int poInvoiceLineId, int taxId, double taxAmount, const QString &createdBy, const QString &updatedBy);
    static PoInvoiceLineTax create(const QVariantMap &values);
    static PoInvoiceLineTax get(int poInvoiceLineId);
    static int count();
    static QList<PoInvoiceLineTax> getAll();

private:
    QSharedDataPointer<PoInvoiceLineTaxObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const PoInvoiceLineTax &model);
    friend QDataStream &operator>>(QDataStream &ds, PoInvoiceLineTax &model);
};

Q_DECLARE_METATYPE(PoInvoiceLineTax)
Q_DECLARE_METATYPE(QList<PoInvoiceLineTax>)

#endif // POINVOICELINETAX_H
