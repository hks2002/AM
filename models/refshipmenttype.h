#ifndef REFSHIPMENTTYPE_H
#define REFSHIPMENTTYPE_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class RefShipmentTypeObject;


class T_MODEL_EXPORT RefShipmentType : public TAbstractModel
{
public:
    RefShipmentType();
    RefShipmentType(const RefShipmentType &other);
    RefShipmentType(const RefShipmentTypeObject &object);
    ~RefShipmentType();

    QString shipmentTypeCd() const;
    void setShipmentTypeCd(const QString &shipmentTypeCd);
    QString shipmentTypeNameEn() const;
    void setShipmentTypeNameEn(const QString &shipmentTypeNameEn);
    QString shipmentTypeNameZh() const;
    void setShipmentTypeNameZh(const QString &shipmentTypeNameZh);
    QString shipmentTypeDesc() const;
    void setShipmentTypeDesc(const QString &shipmentTypeDesc);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    RefShipmentType &operator=(const RefShipmentType &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static RefShipmentType create(const QString &shipmentTypeCd, const QString &shipmentTypeNameEn, const QString &shipmentTypeNameZh, const QString &shipmentTypeDesc, const QString &createdBy, const QString &updatedBy);
    static RefShipmentType create(const QVariantMap &values);
    static RefShipmentType get(const QString &shipmentTypeCd);
    static int count();
    static QList<RefShipmentType> getAll();

private:
    QSharedDataPointer<RefShipmentTypeObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const RefShipmentType &model);
    friend QDataStream &operator>>(QDataStream &ds, RefShipmentType &model);
};

Q_DECLARE_METATYPE(RefShipmentType)
Q_DECLARE_METATYPE(QList<RefShipmentType>)

#endif // REFSHIPMENTTYPE_H
