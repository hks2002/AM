#ifndef EQPPARTNOTECHDATA_H
#define EQPPARTNOTECHDATA_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class EqpPartNoTechDataObject;
class RefMesurType;
class MesurUnit;
class EqpPartNo;


class T_MODEL_EXPORT EqpPartNoTechData : public TAbstractModel
{
public:
    EqpPartNoTechData();
    EqpPartNoTechData(const EqpPartNoTechData &other);
    EqpPartNoTechData(const EqpPartNoTechDataObject &object);
    ~EqpPartNoTechData();

    int partNoId() const;
    void setPartNoId(int partNoId);
    int mesurUnitId() const;
    void setMesurUnitId(int mesurUnitId);
    QString mesurTypeCd() const;
    void setMesurTypeCd(const QString &mesurTypeCd);
    double mesurQt() const;
    void setMesurQt(double mesurQt);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    RefMesurType refMesurTypeBymesurTypeCd() const;
    MesurUnit mesurUnitBymesurUnitId() const;
    EqpPartNo eqpPartNoBypartNoId() const;
    EqpPartNoTechData &operator=(const EqpPartNoTechData &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static EqpPartNoTechData create(int partNoId, int mesurUnitId, const QString &mesurTypeCd, double mesurQt, const QString &createdBy, const QString &updatedBy);
    static EqpPartNoTechData create(const QVariantMap &values);
    static EqpPartNoTechData get(int partNoId, int mesurUnitId, const QString &mesurTypeCd);
    static int count();
    static QList<EqpPartNoTechData> getAll();

private:
    QSharedDataPointer<EqpPartNoTechDataObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const EqpPartNoTechData &model);
    friend QDataStream &operator>>(QDataStream &ds, EqpPartNoTechData &model);
};

Q_DECLARE_METATYPE(EqpPartNoTechData)
Q_DECLARE_METATYPE(QList<EqpPartNoTechData>)

#endif // EQPPARTNOTECHDATA_H
