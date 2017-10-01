#ifndef INVADJUST_H
#define INVADJUST_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class InvAdjustObject;
class UserApp;
class RefXactionType;
class PoLine;
class PoHeader;
class EqpPartNo;
class InvInv;
class EvtEvent;


class T_MODEL_EXPORT InvAdjust : public TAbstractModel
{
public:
    InvAdjust();
    InvAdjust(const InvAdjust &other);
    InvAdjust(const InvAdjustObject &object);
    ~InvAdjust();

    int invAdjustId() const;
    int eventId() const;
    void setEventId(int eventId);
    int invNoId() const;
    void setInvNoId(int invNoId);
    int partNoId() const;
    void setPartNoId(int partNoId);
    int poId() const;
    void setPoId(int poId);
    int poLineId() const;
    void setPoLineId(int poLineId);
    QString xactionTypeCd() const;
    void setXactionTypeCd(const QString &xactionTypeCd);
    int adjustBy() const;
    void setAdjustBy(int adjustBy);
    QDateTime adjustDt() const;
    void setAdjustDt(const QDateTime &adjustDt);
    int adjustQt() const;
    void setAdjustQt(int adjustQt);
    QString userNote() const;
    void setUserNote(const QString &userNote);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    UserApp userAppByadjustBy() const;
    RefXactionType refXactionTypeByxactionTypeCd() const;
    PoLine poLineBypoLineId() const;
    PoHeader poHeaderBypoId() const;
    EqpPartNo eqpPartNoBypartNoId() const;
    InvInv invInvByinvNoId() const;
    EvtEvent evtEventByeventId() const;
    InvAdjust &operator=(const InvAdjust &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static InvAdjust create(int eventId, int invNoId, int partNoId, int poId, int poLineId, const QString &xactionTypeCd, int adjustBy, const QDateTime &adjustDt, int adjustQt, const QString &userNote, const QString &createdBy, const QString &updatedBy);
    static InvAdjust create(const QVariantMap &values);
    static InvAdjust get(int invAdjustId);
    static int count();
    static QList<InvAdjust> getAll();

private:
    QSharedDataPointer<InvAdjustObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const InvAdjust &model);
    friend QDataStream &operator>>(QDataStream &ds, InvAdjust &model);
};

Q_DECLARE_METATYPE(InvAdjust)
Q_DECLARE_METATYPE(QList<InvAdjust>)

#endif // INVADJUST_H
