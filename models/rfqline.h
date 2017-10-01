#ifndef RFQLINE_H
#define RFQLINE_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class RfqLineObject;
class PoLine;
class PoHeader;
class RefReqPriority;
class EqpPartNo;
class Loc;
class QtyUnit;
class RfqHeader;


class T_MODEL_EXPORT RfqLine : public TAbstractModel
{
public:
    RfqLine();
    RfqLine(const RfqLine &other);
    RfqLine(const RfqLineObject &object);
    ~RfqLine();

    int rfqLineId() const;
    int rfqId() const;
    void setRfqId(int rfqId);
    int lineNoOrd() const;
    void setLineNoOrd(int lineNoOrd);
    QString lineDesc() const;
    void setLineDesc(const QString &lineDesc);
    QString noteToVendor() const;
    void setNoteToVendor(const QString &noteToVendor);
    int rfqQt() const;
    void setRfqQt(int rfqQt);
    int qtyUnitId() const;
    void setQtyUnitId(int qtyUnitId);
    int shipToLocId() const;
    void setShipToLocId(int shipToLocId);
    int partNoId() const;
    void setPartNoId(int partNoId);
    QString reqPriorityCd() const;
    void setReqPriorityCd(const QString &reqPriorityCd);
    int poId() const;
    void setPoId(int poId);
    int poLineId() const;
    void setPoLineId(int poLineId);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    PoLine poLineBypoLineId() const;
    PoHeader poHeaderBypoId() const;
    RefReqPriority refReqPriorityByreqPriorityCd() const;
    EqpPartNo eqpPartNoBypartNoId() const;
    Loc locByshipToLocId() const;
    QtyUnit qtyUnitByqtyUnitId() const;
    RfqHeader rfqHeaderByrfqId() const;
    RfqLine &operator=(const RfqLine &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static RfqLine create(int rfqId, int lineNoOrd, const QString &lineDesc, const QString &noteToVendor, int rfqQt, int qtyUnitId, int shipToLocId, int partNoId, const QString &reqPriorityCd, int poId, int poLineId, const QString &createdBy, const QString &updatedBy);
    static RfqLine create(const QVariantMap &values);
    static RfqLine get(int rfqLineId);
    static int count();
    static QList<RfqLine> getAll();

private:
    QSharedDataPointer<RfqLineObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const RfqLine &model);
    friend QDataStream &operator>>(QDataStream &ds, RfqLine &model);
};

Q_DECLARE_METATYPE(RfqLine)
Q_DECLARE_METATYPE(QList<RfqLine>)

#endif // RFQLINE_H
