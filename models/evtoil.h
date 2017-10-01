#ifndef EVTOIL_H
#define EVTOIL_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class EvtOilObject;
class MesurUnit;
class EvtEvent;


class T_MODEL_EXPORT EvtOil : public TAbstractModel
{
public:
    EvtOil();
    EvtOil(const EvtOil &other);
    EvtOil(const EvtOilObject &object);
    ~EvtOil();

    int eventId() const;
    void setEventId(int eventId);
    int mesurUnitId() const;
    void setMesurUnitId(int mesurUnitId);
    double fillQty() const;
    void setFillQty(double fillQty);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    MesurUnit mesurUnitBymesurUnitId() const;
    EvtEvent evtEventByeventId() const;
    EvtOil &operator=(const EvtOil &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static EvtOil create(int eventId, int mesurUnitId, double fillQty, const QString &createdBy, const QString &updatedBy);
    static EvtOil create(const QVariantMap &values);
    static EvtOil get(int eventId);
    static int count();
    static QList<EvtOil> getAll();

private:
    QSharedDataPointer<EvtOilObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const EvtOil &model);
    friend QDataStream &operator>>(QDataStream &ds, EvtOil &model);
};

Q_DECLARE_METATYPE(EvtOil)
Q_DECLARE_METATYPE(QList<EvtOil>)

#endif // EVTOIL_H
