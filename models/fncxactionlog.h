#ifndef FNCXACTIONLOG_H
#define FNCXACTIONLOG_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class FncXactionLogObject;
class Currency;
class InvInv;
class EqpPartNo;
class PoInvoiceLine;
class PoInvoice;
class PoLine;
class PoHeader;
class RefXactionType;


class T_MODEL_EXPORT FncXactionLog : public TAbstractModel
{
public:
    FncXactionLog();
    FncXactionLog(const FncXactionLog &other);
    FncXactionLog(const FncXactionLogObject &object);
    ~FncXactionLog();

    int xactionId() const;
    QString xactionTypeCd() const;
    void setXactionTypeCd(const QString &xactionTypeCd);
    QString xactionDesc() const;
    void setXactionDesc(const QString &xactionDesc);
    QDateTime xactionDt() const;
    void setXactionDt(const QDateTime &xactionDt);
    int poId() const;
    void setPoId(int poId);
    int poLineId() const;
    void setPoLineId(int poLineId);
    int poInvoiceId() const;
    void setPoInvoiceId(int poInvoiceId);
    int poInvoiceLineId() const;
    void setPoInvoiceLineId(int poInvoiceLineId);
    int partNoId() const;
    void setPartNoId(int partNoId);
    int invNoId() const;
    void setInvNoId(int invNoId);
    int qty() const;
    void setQty(int qty);
    double unitPrice() const;
    void setUnitPrice(double unitPrice);
    int currencyId() const;
    void setCurrencyId(int currencyId);
    double exchgQt() const;
    void setExchgQt(double exchgQt);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    Currency currencyBycurrencyId() const;
    InvInv invInvByinvNoId() const;
    EqpPartNo eqpPartNoBypartNoId() const;
    PoInvoiceLine poInvoiceLineBypoInvoiceLineId() const;
    PoInvoice poInvoiceBypoInvoiceId() const;
    PoLine poLineBypoLineId() const;
    PoHeader poHeaderBypoId() const;
    RefXactionType refXactionTypeByxactionTypeCd() const;
    FncXactionLog &operator=(const FncXactionLog &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static FncXactionLog create(const QString &xactionTypeCd, const QString &xactionDesc, const QDateTime &xactionDt, int poId, int poLineId, int poInvoiceId, int poInvoiceLineId, int partNoId, int invNoId, int qty, double unitPrice, int currencyId, double exchgQt, const QString &createdBy, const QString &updatedBy);
    static FncXactionLog create(const QVariantMap &values);
    static FncXactionLog get(int xactionId);
    static int count();
    static QList<FncXactionLog> getAll();

private:
    QSharedDataPointer<FncXactionLogObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const FncXactionLog &model);
    friend QDataStream &operator>>(QDataStream &ds, FncXactionLog &model);
};

Q_DECLARE_METATYPE(FncXactionLog)
Q_DECLARE_METATYPE(QList<FncXactionLog>)

#endif // FNCXACTIONLOG_H
