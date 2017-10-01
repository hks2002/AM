#ifndef EVTLOC_H
#define EVTLOC_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class EvtLocObject;
class Loc;
class EvtEvent;


class T_MODEL_EXPORT EvtLoc : public TAbstractModel
{
public:
    EvtLoc();
    EvtLoc(const EvtLoc &other);
    EvtLoc(const EvtLocObject &object);
    ~EvtLoc();

    int eventId() const;
    void setEventId(int eventId);
    int locId() const;
    void setLocId(int locId);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    Loc locBylocId() const;
    EvtEvent evtEventByeventId() const;
    EvtLoc &operator=(const EvtLoc &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static EvtLoc create(int eventId, int locId, const QString &createdBy, const QString &updatedBy);
    static EvtLoc create(const QVariantMap &values);
    static EvtLoc get(int eventId, int locId);
    static int count();
    static QList<EvtLoc> getAll();

private:
    QSharedDataPointer<EvtLocObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const EvtLoc &model);
    friend QDataStream &operator>>(QDataStream &ds, EvtLoc &model);
};

Q_DECLARE_METATYPE(EvtLoc)
Q_DECLARE_METATYPE(QList<EvtLoc>)

#endif // EVTLOC_H
