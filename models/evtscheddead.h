#ifndef EVTSCHEDDEAD_H
#define EVTSCHEDDEAD_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class EvtSchedDeadObject;
class DataType;
class EvtEvent;


class T_MODEL_EXPORT EvtSchedDead : public TAbstractModel
{
public:
    EvtSchedDead();
    EvtSchedDead(const EvtSchedDead &other);
    EvtSchedDead(const EvtSchedDeadObject &object);
    ~EvtSchedDead();

    int eventId() const;
    void setEventId(int eventId);
    int dataTypeId() const;
    void setDataTypeId(int dataTypeId);
    double schedDeadQt() const;
    void setSchedDeadQt(double schedDeadQt);
    QDateTime schedDeadDt() const;
    void setSchedDeadDt(const QDateTime &schedDeadDt);
    QDateTime schedDeadDtLastUpdated() const;
    void setSchedDeadDtLastUpdated(const QDateTime &schedDeadDtLastUpdated);
    QString schedFromCd() const;
    void setSchedFromCd(const QString &schedFromCd);
    double startQt() const;
    void setStartQt(double startQt);
    QDateTime startDt() const;
    void setStartDt(const QDateTime &startDt);
    double usageRemQt() const;
    void setUsageRemQt(double usageRemQt);
    bool schedDriverBool() const;
    void setSchedDriverBool(bool schedDriverBool);
    double deviationQt() const;
    void setDeviationQt(double deviationQt);
    double intervalQt() const;
    void setIntervalQt(double intervalQt);
    double prefixedQt() const;
    void setPrefixedQt(double prefixedQt);
    double postfixedQt() const;
    void setPostfixedQt(double postfixedQt);
    double notifyQt() const;
    void setNotifyQt(double notifyQt);
    double minPlanQt() const;
    void setMinPlanQt(double minPlanQt);
    bool postfixedMandBool() const;
    void setPostfixedMandBool(bool postfixedMandBool);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    DataType dataTypeBydataTypeId() const;
    EvtEvent evtEventByeventId() const;
    EvtSchedDead &operator=(const EvtSchedDead &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static EvtSchedDead create(int eventId, int dataTypeId, double schedDeadQt, const QDateTime &schedDeadDt, const QDateTime &schedDeadDtLastUpdated, const QString &schedFromCd, double startQt, const QDateTime &startDt, double usageRemQt, bool schedDriverBool, double deviationQt, double intervalQt, double prefixedQt, double postfixedQt, double notifyQt, double minPlanQt, bool postfixedMandBool, const QString &createdBy, const QString &updatedBy);
    static EvtSchedDead create(const QVariantMap &values);
    static EvtSchedDead get(int eventId, int dataTypeId);
    static int count();
    static QList<EvtSchedDead> getAll();

private:
    QSharedDataPointer<EvtSchedDeadObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const EvtSchedDead &model);
    friend QDataStream &operator>>(QDataStream &ds, EvtSchedDead &model);
};

Q_DECLARE_METATYPE(EvtSchedDead)
Q_DECLARE_METATYPE(QList<EvtSchedDead>)

#endif // EVTSCHEDDEAD_H
