#ifndef LOCPARTCOUNT_H
#define LOCPARTCOUNT_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class LocPartCountObject;
class UserApp;
class EqpPartNo;
class Loc;


class T_MODEL_EXPORT LocPartCount : public TAbstractModel
{
public:
    LocPartCount();
    LocPartCount(const LocPartCount &other);
    LocPartCount(const LocPartCountObject &object);
    ~LocPartCount();

    int locPartCountId() const;
    int locId() const;
    void setLocId(int locId);
    int partNoId() const;
    void setPartNoId(int partNoId);
    int userId() const;
    void setUserId(int userId);
    QDateTime lastCountDt() const;
    void setLastCountDt(const QDateTime &lastCountDt);
    QDateTime nextCountDt() const;
    void setNextCountDt(const QDateTime &nextCountDt);
    bool reqRecountBool() const;
    void setReqRecountBool(bool reqRecountBool);
    bool histBool() const;
    void setHistBool(bool histBool);
    bool countAcceptBool() const;
    void setCountAcceptBool(bool countAcceptBool);
    int countActualQt() const;
    void setCountActualQt(int countActualQt);
    int countExpectQt() const;
    void setCountExpectQt(int countExpectQt);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    UserApp userAppByuserId() const;
    EqpPartNo eqpPartNoBypartNoId() const;
    Loc locBylocId() const;
    LocPartCount &operator=(const LocPartCount &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static LocPartCount create(int locId, int partNoId, int userId, const QDateTime &lastCountDt, const QDateTime &nextCountDt, bool reqRecountBool, bool histBool, bool countAcceptBool, int countActualQt, int countExpectQt, const QString &createdBy, const QString &updatedBy);
    static LocPartCount create(const QVariantMap &values);
    static LocPartCount get(int locPartCountId);
    static int count();
    static QList<LocPartCount> getAll();

private:
    QSharedDataPointer<LocPartCountObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const LocPartCount &model);
    friend QDataStream &operator>>(QDataStream &ds, LocPartCount &model);
};

Q_DECLARE_METATYPE(LocPartCount)
Q_DECLARE_METATYPE(QList<LocPartCount>)

#endif // LOCPARTCOUNT_H
