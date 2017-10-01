#ifndef EQPPARTNOCONTROL_H
#define EQPPARTNOCONTROL_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class EqpPartNoControlObject;
class EqpPartNo;


class T_MODEL_EXPORT EqpPartNoControl : public TAbstractModel
{
public:
    EqpPartNoControl();
    EqpPartNoControl(const EqpPartNoControl &other);
    EqpPartNoControl(const EqpPartNoControlObject &object);
    ~EqpPartNoControl();

    int partNoId() const;
    void setPartNoId(int partNoId);
    bool controlReserveBool() const;
    void setControlReserveBool(bool controlReserveBool);
    bool noAutoReserveBool() const;
    void setNoAutoReserveBool(bool noAutoReserveBool);
    bool receiptInspBool() const;
    void setReceiptInspBool(bool receiptInspBool);
    bool purchasableBool() const;
    void setPurchasableBool(bool purchasableBool);
    bool repairBool() const;
    void setRepairBool(bool repairBool);
    int shelfLifeQt() const;
    void setShelfLifeQt(int shelfLifeQt);
    QString shelfLifeUnit() const;
    void setShelfLifeUnit(const QString &shelfLifeUnit);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    EqpPartNo eqpPartNoBypartNoId() const;
    EqpPartNoControl &operator=(const EqpPartNoControl &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static EqpPartNoControl create(int partNoId, bool controlReserveBool, bool noAutoReserveBool, bool receiptInspBool, bool purchasableBool, bool repairBool, int shelfLifeQt, const QString &shelfLifeUnit, const QString &createdBy, const QString &updatedBy);
    static EqpPartNoControl create(const QVariantMap &values);
    static EqpPartNoControl get(int partNoId);
    static int count();
    static QList<EqpPartNoControl> getAll();

private:
    QSharedDataPointer<EqpPartNoControlObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const EqpPartNoControl &model);
    friend QDataStream &operator>>(QDataStream &ds, EqpPartNoControl &model);
};

Q_DECLARE_METATYPE(EqpPartNoControl)
Q_DECLARE_METATYPE(QList<EqpPartNoControl>)

#endif // EQPPARTNOCONTROL_H
