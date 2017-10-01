#ifndef EVTINV_H
#define EVTINV_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class EvtInvObject;
class EqpPartNo;
class EqpAssmblBomPos;
class EqpAssmbl;
class EqpAssmblBom;
class InvInv;
class EvtEvent;


class T_MODEL_EXPORT EvtInv : public TAbstractModel
{
public:
    EvtInv();
    EvtInv(const EvtInv &other);
    EvtInv(const EvtInvObject &object);
    ~EvtInv();

    int eventId() const;
    void setEventId(int eventId);
    int invNoId() const;
    void setInvNoId(int invNoId);
    int nhInvNoId() const;
    void setNhInvNoId(int nhInvNoId);
    int assmblInvNoId() const;
    void setAssmblInvNoId(int assmblInvNoId);
    int hInvNoId() const;
    void setHInvNoId(int hInvNoId);
    int assmblBomId() const;
    void setAssmblBomId(int assmblBomId);
    int assmblId() const;
    void setAssmblId(int assmblId);
    int assmblBomPosId() const;
    void setAssmblBomPosId(int assmblBomPosId);
    int partNoId() const;
    void setPartNoId(int partNoId);
    bool mainInvBool() const;
    void setMainInvBool(bool mainInvBool);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    EqpPartNo eqpPartNoBypartNoId() const;
    EqpAssmblBomPos eqpAssmblBomPosByassmblBomPosId() const;
    EqpAssmbl eqpAssmblByassmblId() const;
    EqpAssmblBom eqpAssmblBomByassmblBomId() const;
    InvInv invInvByhInvNoId() const;
    EvtEvent evtEventByeventId() const;
    EvtInv &operator=(const EvtInv &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static EvtInv create(int eventId, int invNoId, int nhInvNoId, int assmblInvNoId, int hInvNoId, int assmblBomId, int assmblId, int assmblBomPosId, int partNoId, bool mainInvBool, const QString &createdBy, const QString &updatedBy);
    static EvtInv create(const QVariantMap &values);
    static EvtInv get(int eventId, int invNoId);
    static int count();
    static QList<EvtInv> getAll();

private:
    QSharedDataPointer<EvtInvObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const EvtInv &model);
    friend QDataStream &operator>>(QDataStream &ds, EvtInv &model);
};

Q_DECLARE_METATYPE(EvtInv)
Q_DECLARE_METATYPE(QList<EvtInv>)

#endif // EVTINV_H
