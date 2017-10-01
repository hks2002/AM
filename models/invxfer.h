#ifndef INVXFER_H
#define INVXFER_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class InvXferObject;
class UserApp;
class RefXferType;
class EvtEvent;
class InvInv;


class T_MODEL_EXPORT InvXfer : public TAbstractModel
{
public:
    InvXfer();
    InvXfer(const InvXfer &other);
    InvXfer(const InvXferObject &object);
    ~InvXfer();

    int invXferId() const;
    int invNoId() const;
    void setInvNoId(int invNoId);
    int eventId() const;
    void setEventId(int eventId);
    QString xferTypeCd() const;
    void setXferTypeCd(const QString &xferTypeCd);
    int xferQt() const;
    void setXferQt(int xferQt);
    double unitPrice() const;
    void setUnitPrice(double unitPrice);
    int receivedBy() const;
    void setReceivedBy(int receivedBy);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    UserApp userAppByreceivedBy() const;
    RefXferType refXferTypeByxferTypeCd() const;
    EvtEvent evtEventByeventId() const;
    InvInv invInvByinvNoId() const;
    InvXfer &operator=(const InvXfer &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static InvXfer create(int invNoId, int eventId, const QString &xferTypeCd, int xferQt, double unitPrice, int receivedBy, const QString &createdBy, const QString &updatedBy);
    static InvXfer create(const QVariantMap &values);
    static InvXfer get(int invXferId);
    static int count();
    static QList<InvXfer> getAll();

private:
    QSharedDataPointer<InvXferObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const InvXfer &model);
    friend QDataStream &operator>>(QDataStream &ds, InvXfer &model);
};

Q_DECLARE_METATYPE(InvXfer)
Q_DECLARE_METATYPE(QList<InvXfer>)

#endif // INVXFER_H
