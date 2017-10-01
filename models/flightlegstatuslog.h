#ifndef FLIGHTLEGSTATUSLOG_H
#define FLIGHTLEGSTATUSLOG_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class FlightLegStatusLogObject;
class UserApp;
class FlightLeg;


class T_MODEL_EXPORT FlightLegStatusLog : public TAbstractModel
{
public:
    FlightLegStatusLog();
    FlightLegStatusLog(const FlightLegStatusLog &other);
    FlightLegStatusLog(const FlightLegStatusLogObject &object);
    ~FlightLegStatusLog();

    int legStatusLogId() const;
    int legId() const;
    void setLegId(int legId);
    QDateTime logDt() const;
    void setLogDt(const QDateTime &logDt);
    QString flightLegStatusCd() const;
    void setFlightLegStatusCd(const QString &flightLegStatusCd);
    bool systemBool() const;
    void setSystemBool(bool systemBool);
    int logBy() const;
    void setLogBy(int logBy);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    UserApp userAppBylogBy() const;
    FlightLeg flightLegBylegId() const;
    FlightLegStatusLog &operator=(const FlightLegStatusLog &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static FlightLegStatusLog create(int legId, const QDateTime &logDt, const QString &flightLegStatusCd, bool systemBool, int logBy, const QString &createdBy, const QString &updatedBy);
    static FlightLegStatusLog create(const QVariantMap &values);
    static FlightLegStatusLog get(int legStatusLogId);
    static int count();
    static QList<FlightLegStatusLog> getAll();

private:
    QSharedDataPointer<FlightLegStatusLogObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const FlightLegStatusLog &model);
    friend QDataStream &operator>>(QDataStream &ds, FlightLegStatusLog &model);
};

Q_DECLARE_METATYPE(FlightLegStatusLog)
Q_DECLARE_METATYPE(QList<FlightLegStatusLog>)

#endif // FLIGHTLEGSTATUSLOG_H
