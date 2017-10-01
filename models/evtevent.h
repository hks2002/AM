#ifndef EVTEVENT_H
#define EVTEVENT_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class EvtEventObject;
class RefEventStatus;
class RefEventReason;
class RefEventType;


class T_MODEL_EXPORT EvtEvent : public TAbstractModel
{
public:
    EvtEvent();
    EvtEvent(const EvtEvent &other);
    EvtEvent(const EvtEventObject &object);
    ~EvtEvent();

    int eventId() const;
    QString eventTypeCd() const;
    void setEventTypeCd(const QString &eventTypeCd);
    QString eventReasonCd() const;
    void setEventReasonCd(const QString &eventReasonCd);
    QString eventStatusCd() const;
    void setEventStatusCd(const QString &eventStatusCd);
    QString eventName() const;
    void setEventName(const QString &eventName);
    QString eventDesc() const;
    void setEventDesc(const QString &eventDesc);
    QDateTime eventDt() const;
    void setEventDt(const QDateTime &eventDt);
    int nhEventId() const;
    void setNhEventId(int nhEventId);
    int hEventId() const;
    void setHEventId(int hEventId);
    int subEventOrd() const;
    void setSubEventOrd(int subEventOrd);
    bool histBool() const;
    void setHistBool(bool histBool);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    RefEventStatus refEventStatusByeventStatusCd() const;
    RefEventReason refEventReasonByeventReasonCd() const;
    RefEventType refEventTypeByeventTypeCd() const;
    EvtEvent &operator=(const EvtEvent &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static EvtEvent create(const QString &eventTypeCd, const QString &eventReasonCd, const QString &eventStatusCd, const QString &eventName, const QString &eventDesc, const QDateTime &eventDt, int nhEventId, int hEventId, int subEventOrd, bool histBool, const QString &createdBy, const QString &updatedBy);
    static EvtEvent create(const QVariantMap &values);
    static EvtEvent get(int eventId);
    static int count();
    static QList<EvtEvent> getAll();

private:
    QSharedDataPointer<EvtEventObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const EvtEvent &model);
    friend QDataStream &operator>>(QDataStream &ds, EvtEvent &model);
};

Q_DECLARE_METATYPE(EvtEvent)
Q_DECLARE_METATYPE(QList<EvtEvent>)

#endif // EVTEVENT_H
