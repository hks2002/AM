#ifndef EQPPARTNOSHIPSTORAGEPACKAGE_H
#define EQPPARTNOSHIPSTORAGEPACKAGE_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class EqpPartNoShipStoragePackageObject;
class EqpPartNo;


class T_MODEL_EXPORT EqpPartNoShipStoragePackage : public TAbstractModel
{
public:
    EqpPartNoShipStoragePackage();
    EqpPartNoShipStoragePackage(const EqpPartNoShipStoragePackage &other);
    EqpPartNoShipStoragePackage(const EqpPartNoShipStoragePackageObject &object);
    ~EqpPartNoShipStoragePackage();

    int partNoId() const;
    void setPartNoId(int partNoId);
    QString shippingDesc() const;
    void setShippingDesc(const QString &shippingDesc);
    QString storageDesc() const;
    void setStorageDesc(const QString &storageDesc);
    QString packingDesc() const;
    void setPackingDesc(const QString &packingDesc);
    QString hazmatDesc() const;
    void setHazmatDesc(const QString &hazmatDesc);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    EqpPartNo eqpPartNoBypartNoId() const;
    EqpPartNoShipStoragePackage &operator=(const EqpPartNoShipStoragePackage &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static EqpPartNoShipStoragePackage create(int partNoId, const QString &shippingDesc, const QString &storageDesc, const QString &packingDesc, const QString &hazmatDesc, const QString &createdBy, const QString &updatedBy);
    static EqpPartNoShipStoragePackage create(const QVariantMap &values);
    static EqpPartNoShipStoragePackage get(int partNoId);
    static int count();
    static QList<EqpPartNoShipStoragePackage> getAll();

private:
    QSharedDataPointer<EqpPartNoShipStoragePackageObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const EqpPartNoShipStoragePackage &model);
    friend QDataStream &operator>>(QDataStream &ds, EqpPartNoShipStoragePackage &model);
};

Q_DECLARE_METATYPE(EqpPartNoShipStoragePackage)
Q_DECLARE_METATYPE(QList<EqpPartNoShipStoragePackage>)

#endif // EQPPARTNOSHIPSTORAGEPACKAGE_H
