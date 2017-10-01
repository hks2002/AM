#ifndef EVTHR_H
#define EVTHR_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class EvtHrObject;
class UserApp;
class EvtEvent;


class T_MODEL_EXPORT EvtHr : public TAbstractModel
{
public:
    EvtHr();
    EvtHr(const EvtHr &other);
    EvtHr(const EvtHrObject &object);
    ~EvtHr();

    int eventId() const;
    void setEventId(int eventId);
    int userId() const;
    void setUserId(int userId);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    UserApp userAppByuserId() const;
    EvtEvent evtEventByeventId() const;
    EvtHr &operator=(const EvtHr &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static EvtHr create(int eventId, int userId, const QString &createdBy, const QString &updatedBy);
    static EvtHr create(const QVariantMap &values);
    static EvtHr get(int eventId, int userId);
    static int count();
    static QList<EvtHr> getAll();

private:
    QSharedDataPointer<EvtHrObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const EvtHr &model);
    friend QDataStream &operator>>(QDataStream &ds, EvtHr &model);
};

Q_DECLARE_METATYPE(EvtHr)
Q_DECLARE_METATYPE(QList<EvtHr>)

#endif // EVTHR_H
