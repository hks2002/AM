#ifndef EQPASSMBLOIL_H
#define EQPASSMBLOIL_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class EqpAssmblOilObject;
class MesurUnit;
class EqpAssmblDataType;


class T_MODEL_EXPORT EqpAssmblOil : public TAbstractModel
{
public:
    EqpAssmblOil();
    EqpAssmblOil(const EqpAssmblOil &other);
    EqpAssmblOil(const EqpAssmblOilObject &object);
    ~EqpAssmblOil();

    int assmblId() const;
    void setAssmblId(int assmblId);
    int mesurUnitId() const;
    void setMesurUnitId(int mesurUnitId);
    int dataTypeId() const;
    void setDataTypeId(int dataTypeId);
    double fullQty() const;
    void setFullQty(double fullQty);
    double cautionRate() const;
    void setCautionRate(double cautionRate);
    double warningRate() const;
    void setWarningRate(double warningRate);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    MesurUnit mesurUnitBymesurUnitId() const;
    EqpAssmblDataType eqpAssmblDataTypeByassmblIddataTypeId() const;
    EqpAssmblOil &operator=(const EqpAssmblOil &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static EqpAssmblOil create(int assmblId, int mesurUnitId, int dataTypeId, double fullQty, double cautionRate, double warningRate, const QString &createdBy, const QString &updatedBy);
    static EqpAssmblOil create(const QVariantMap &values);
    static EqpAssmblOil get(int assmblId, int mesurUnitId, int dataTypeId);
    static int count();
    static QList<EqpAssmblOil> getAll();

private:
    QSharedDataPointer<EqpAssmblOilObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const EqpAssmblOil &model);
    friend QDataStream &operator>>(QDataStream &ds, EqpAssmblOil &model);
};

Q_DECLARE_METATYPE(EqpAssmblOil)
Q_DECLARE_METATYPE(QList<EqpAssmblOil>)

#endif // EQPASSMBLOIL_H
