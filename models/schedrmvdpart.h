#ifndef SCHEDRMVDPART_H
#define SCHEDRMVDPART_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class SchedRmvdPartObject;
class UserApp;
class RefRemoveReason;
class EqpPartNo;
class InvInv;
class SchedPart;


class T_MODEL_EXPORT SchedRmvdPart : public TAbstractModel
{
public:
    SchedRmvdPart();
    SchedRmvdPart(const SchedRmvdPart &other);
    SchedRmvdPart(const SchedRmvdPartObject &object);
    ~SchedRmvdPart();

    int schedPartId() const;
    void setSchedPartId(int schedPartId);
    int invNoId() const;
    void setInvNoId(int invNoId);
    int partNoId() const;
    void setPartNoId(int partNoId);
    QString serialNoOem() const;
    void setSerialNoOem(const QString &serialNoOem);
    QString removeReasonCd() const;
    void setRemoveReasonCd(const QString &removeReasonCd);
    int rmvdQt() const;
    void setRmvdQt(int rmvdQt);
    int rmvdBy() const;
    void setRmvdBy(int rmvdBy);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    UserApp userAppByrmvdBy() const;
    RefRemoveReason refRemoveReasonByremoveReasonCd() const;
    EqpPartNo eqpPartNoBypartNoId() const;
    InvInv invInvByinvNoId() const;
    SchedPart schedPartByschedPartId() const;
    SchedRmvdPart &operator=(const SchedRmvdPart &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static SchedRmvdPart create(int schedPartId, int invNoId, int partNoId, const QString &serialNoOem, const QString &removeReasonCd, int rmvdQt, int rmvdBy, const QString &createdBy, const QString &updatedBy);
    static SchedRmvdPart create(const QVariantMap &values);
    static SchedRmvdPart get(int schedPartId);
    static int count();
    static QList<SchedRmvdPart> getAll();

private:
    QSharedDataPointer<SchedRmvdPartObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const SchedRmvdPart &model);
    friend QDataStream &operator>>(QDataStream &ds, SchedRmvdPart &model);
};

Q_DECLARE_METATYPE(SchedRmvdPart)
Q_DECLARE_METATYPE(QList<SchedRmvdPart>)

#endif // SCHEDRMVDPART_H
