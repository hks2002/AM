#ifndef EVTINVUSAGE_H
#define EVTINVUSAGE_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class EvtInvUsageObject;
class FlightLeg;
class DataType;
class InvInv;
class EvtEvent;


class T_MODEL_EXPORT EvtInvUsage : public TAbstractModel
{
public:
    EvtInvUsage();
    EvtInvUsage(const EvtInvUsage &other);
    EvtInvUsage(const EvtInvUsageObject &object);
    ~EvtInvUsage();

    int eventId() const;
    void setEventId(int eventId);
    int invNoId() const;
    void setInvNoId(int invNoId);
    int dataTypeId() const;
    void setDataTypeId(int dataTypeId);
    int legId() const;
    void setLegId(int legId);
    double tsiQt() const;
    void setTsiQt(double tsiQt);
    double tsnQt() const;
    void setTsnQt(double tsnQt);
    double tsoQt() const;
    void setTsoQt(double tsoQt);
    double hTsnQt() const;
    void setHTsnQt(double hTsnQt);
    double hTsoQt() const;
    void setHTsoQt(double hTsoQt);
    double nhTsnQt() const;
    void setNhTsnQt(double nhTsnQt);
    double nhTsoQt() const;
    void setNhTsoQt(double nhTsoQt);
    double assmblTsnQt() const;
    void setAssmblTsnQt(double assmblTsnQt);
    double assmblTsoQt() const;
    void setAssmblTsoQt(double assmblTsoQt);
    bool negatedBool() const;
    void setNegatedBool(bool negatedBool);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    FlightLeg flightLegBylegId() const;
    DataType dataTypeBydataTypeId() const;
    InvInv invInvByinvNoId() const;
    EvtEvent evtEventByeventId() const;
    EvtInvUsage &operator=(const EvtInvUsage &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static EvtInvUsage create(int eventId, int invNoId, int dataTypeId, int legId, double tsiQt, double tsnQt, double tsoQt, double hTsnQt, double hTsoQt, double nhTsnQt, double nhTsoQt, double assmblTsnQt, double assmblTsoQt, bool negatedBool, const QString &createdBy, const QString &updatedBy);
    static EvtInvUsage create(const QVariantMap &values);
    static EvtInvUsage get(int eventId, int invNoId, int dataTypeId);
    static int count();
    static QList<EvtInvUsage> getAll();

private:
    QSharedDataPointer<EvtInvUsageObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const EvtInvUsage &model);
    friend QDataStream &operator>>(QDataStream &ds, EvtInvUsage &model);
};

Q_DECLARE_METATYPE(EvtInvUsage)
Q_DECLARE_METATYPE(QList<EvtInvUsage>)

#endif // EVTINVUSAGE_H
