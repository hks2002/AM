#ifndef EVTPARTNO_H
#define EVTPARTNO_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class EvtPartNoObject;
class EqpPartNo;
class EvtEvent;


class T_MODEL_EXPORT EvtPartNo : public TAbstractModel
{
public:
    EvtPartNo();
    EvtPartNo(const EvtPartNo &other);
    EvtPartNo(const EvtPartNoObject &object);
    ~EvtPartNo();

    int eventId() const;
    void setEventId(int eventId);
    int partNoId() const;
    void setPartNoId(int partNoId);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    EqpPartNo eqpPartNoBypartNoId() const;
    EvtEvent evtEventByeventId() const;
    EvtPartNo &operator=(const EvtPartNo &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static EvtPartNo create(int eventId, int partNoId, const QString &createdBy, const QString &updatedBy);
    static EvtPartNo create(const QVariantMap &values);
    static EvtPartNo get(int eventId, int partNoId);
    static int count();
    static QList<EvtPartNo> getAll();

private:
    QSharedDataPointer<EvtPartNoObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const EvtPartNo &model);
    friend QDataStream &operator>>(QDataStream &ds, EvtPartNo &model);
};

Q_DECLARE_METATYPE(EvtPartNo)
Q_DECLARE_METATYPE(QList<EvtPartNo>)

#endif // EVTPARTNO_H
