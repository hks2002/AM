#ifndef FLIGHTLEG_H
#define FLIGHTLEG_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class FlightLegObject;
class InvAcReg;
class Loc;
class RefFlightLegStatus;


class T_MODEL_EXPORT FlightLeg : public TAbstractModel
{
public:
    FlightLeg();
    FlightLeg(const FlightLeg &other);
    FlightLeg(const FlightLegObject &object);
    ~FlightLeg();

    int legId() const;
    QString legNo() const;
    void setLegNo(const QString &legNo);
    bool histBool() const;
    void setHistBool(bool histBool);
    QString flightLegStatusCd() const;
    void setFlightLegStatusCd(const QString &flightLegStatusCd);
    QDateTime actualDepartureDt() const;
    void setActualDepartureDt(const QDateTime &actualDepartureDt);
    int departureLocId() const;
    void setDepartureLocId(int departureLocId);
    int arrivalLocId() const;
    void setArrivalLocId(int arrivalLocId);
    QDateTime actualArrivalDt() const;
    void setActualArrivalDt(const QDateTime &actualArrivalDt);
    QDateTime recordedDt() const;
    void setRecordedDt(const QDateTime &recordedDt);
    QString legDesc() const;
    void setLegDesc(const QString &legDesc);
    QString masterFlightNo() const;
    void setMasterFlightNo(const QString &masterFlightNo);
    QString extKey() const;
    void setExtKey(const QString &extKey);
    int aircraftId() const;
    void setAircraftId(int aircraftId);
    QString logbookRef() const;
    void setLogbookRef(const QString &logbookRef);
    QString departureGateCd() const;
    void setDepartureGateCd(const QString &departureGateCd);
    QString arrivalGateCd() const;
    void setArrivalGateCd(const QString &arrivalGateCd);
    QDateTime schedDepartureDt() const;
    void setSchedDepartureDt(const QDateTime &schedDepartureDt);
    QDateTime schedArrivalDt() const;
    void setSchedArrivalDt(const QDateTime &schedArrivalDt);
    QDateTime offDt() const;
    void setOffDt(const QDateTime &offDt);
    QDateTime onDt() const;
    void setOnDt(const QDateTime &onDt);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    InvAcReg invAcRegByaircraftId() const;
    Loc locByarrivalLocId() const;
    RefFlightLegStatus refFlightLegStatusByflightLegStatusCd() const;
    FlightLeg &operator=(const FlightLeg &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static FlightLeg create(const QString &legNo, bool histBool, const QString &flightLegStatusCd, const QDateTime &actualDepartureDt, int departureLocId, int arrivalLocId, const QDateTime &actualArrivalDt, const QDateTime &recordedDt, const QString &legDesc, const QString &masterFlightNo, const QString &extKey, int aircraftId, const QString &logbookRef, const QString &departureGateCd, const QString &arrivalGateCd, const QDateTime &schedDepartureDt, const QDateTime &schedArrivalDt, const QDateTime &offDt, const QDateTime &onDt, const QString &createdBy, const QString &updatedBy);
    static FlightLeg create(const QVariantMap &values);
    static FlightLeg get(int legId);
    static int count();
    static QList<FlightLeg> getAll();

private:
    QSharedDataPointer<FlightLegObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const FlightLeg &model);
    friend QDataStream &operator>>(QDataStream &ds, FlightLeg &model);
};

Q_DECLARE_METATYPE(FlightLeg)
Q_DECLARE_METATYPE(QList<FlightLeg>)

#endif // FLIGHTLEG_H
