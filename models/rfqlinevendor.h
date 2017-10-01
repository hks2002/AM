#ifndef RFQLINEVENDOR_H
#define RFQLINEVENDOR_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class RfqLineVendorObject;
class QtyUnit;
class RefReceiveCond;
class EqpPartNo;
class RfqLine;
class RfqVendor;


class T_MODEL_EXPORT RfqLineVendor : public TAbstractModel
{
public:
    RfqLineVendor();
    RfqLineVendor(const RfqLineVendor &other);
    RfqLineVendor(const RfqLineVendorObject &object);
    ~RfqLineVendor();

    int rfqId() const;
    void setRfqId(int rfqId);
    int rfqLineId() const;
    void setRfqLineId(int rfqLineId);
    int vendorId() const;
    void setVendorId(int vendorId);
    bool noQuoteBool() const;
    void setNoQuoteBool(bool noQuoteBool);
    bool noSupplyBool() const;
    void setNoSupplyBool(bool noSupplyBool);
    int partNoId() const;
    void setPartNoId(int partNoId);
    QString receiveCondCd() const;
    void setReceiveCondCd(const QString &receiveCondCd);
    int quoteQt() const;
    void setQuoteQt(int quoteQt);
    QDateTime quoteDt() const;
    void setQuoteDt(const QDateTime &quoteDt);
    double unitPrice() const;
    void setUnitPrice(double unitPrice);
    int qtyUnitId() const;
    void setQtyUnitId(int qtyUnitId);
    double linePrice() const;
    void setLinePrice(double linePrice);
    QString leadTime() const;
    void setLeadTime(const QString &leadTime);
    QDateTime effectiveToDt() const;
    void setEffectiveToDt(const QDateTime &effectiveToDt);
    bool respondedBool() const;
    void setRespondedBool(bool respondedBool);
    QString noteToVendor() const;
    void setNoteToVendor(const QString &noteToVendor);
    QString docRefDesc() const;
    void setDocRefDesc(const QString &docRefDesc);
    QDateTime respondDt() const;
    void setRespondDt(const QDateTime &respondDt);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    QtyUnit qtyUnitByqtyUnitId() const;
    RefReceiveCond refReceiveCondByreceiveCondCd() const;
    EqpPartNo eqpPartNoBypartNoId() const;
    RfqLine rfqLineByrfqLineId() const;
    RfqVendor rfqVendorByrfqIdvendorId() const;
    RfqLineVendor &operator=(const RfqLineVendor &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static RfqLineVendor create(int rfqId, int rfqLineId, int vendorId, bool noQuoteBool, bool noSupplyBool, int partNoId, const QString &receiveCondCd, int quoteQt, const QDateTime &quoteDt, double unitPrice, int qtyUnitId, double linePrice, const QString &leadTime, const QDateTime &effectiveToDt, bool respondedBool, const QString &noteToVendor, const QString &docRefDesc, const QDateTime &respondDt, const QString &createdBy, const QString &updatedBy);
    static RfqLineVendor create(const QVariantMap &values);
    static RfqLineVendor get(int rfqId, int rfqLineId, int vendorId);
    static int count();
    static QList<RfqLineVendor> getAll();

private:
    QSharedDataPointer<RfqLineVendorObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const RfqLineVendor &model);
    friend QDataStream &operator>>(QDataStream &ds, RfqLineVendor &model);
};

Q_DECLARE_METATYPE(RfqLineVendor)
Q_DECLARE_METATYPE(QList<RfqLineVendor>)

#endif // RFQLINEVENDOR_H
