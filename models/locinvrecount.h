#ifndef LOCINVRECOUNT_H
#define LOCINVRECOUNT_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class LocInvRecountObject;
class InvInv;
class UserApp;
class LocPartCount;
class EqpPartNo;
class Loc;


class T_MODEL_EXPORT LocInvRecount : public TAbstractModel
{
public:
    LocInvRecount();
    LocInvRecount(const LocInvRecount &other);
    LocInvRecount(const LocInvRecountObject &object);
    ~LocInvRecount();

    int invRecountId() const;
    int locId() const;
    void setLocId(int locId);
    int partNoId() const;
    void setPartNoId(int partNoId);
    int locPartCountId() const;
    void setLocPartCountId(int locPartCountId);
    int userId() const;
    void setUserId(int userId);
    int invNoId() const;
    void setInvNoId(int invNoId);
    QString serialNoOem() const;
    void setSerialNoOem(const QString &serialNoOem);
    int countActualQt() const;
    void setCountActualQt(int countActualQt);
    int countExpectQt() const;
    void setCountExpectQt(int countExpectQt);
    QDateTime recountDt() const;
    void setRecountDt(const QDateTime &recountDt);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    InvInv invInvByinvNoId() const;
    UserApp userAppByuserId() const;
    LocPartCount locPartCountBylocPartCountId() const;
    EqpPartNo eqpPartNoBypartNoId() const;
    Loc locBylocId() const;
    LocInvRecount &operator=(const LocInvRecount &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static LocInvRecount create(int locId, int partNoId, int locPartCountId, int userId, int invNoId, const QString &serialNoOem, int countActualQt, int countExpectQt, const QDateTime &recountDt, const QString &createdBy, const QString &updatedBy);
    static LocInvRecount create(const QVariantMap &values);
    static LocInvRecount get(int invRecountId);
    static int count();
    static QList<LocInvRecount> getAll();

private:
    QSharedDataPointer<LocInvRecountObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const LocInvRecount &model);
    friend QDataStream &operator>>(QDataStream &ds, LocInvRecount &model);
};

Q_DECLARE_METATYPE(LocInvRecount)
Q_DECLARE_METATYPE(QList<LocInvRecount>)

#endif // LOCINVRECOUNT_H
