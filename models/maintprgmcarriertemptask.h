#ifndef MAINTPRGMCARRIERTEMPTASK_H
#define MAINTPRGMCARRIERTEMPTASK_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class MaintPrgmCarrierTempTaskObject;
class Carrier;
class TaskTask;
class TaskDefn;
class MaintPrgmDefn;


class T_MODEL_EXPORT MaintPrgmCarrierTempTask : public TAbstractModel
{
public:
    MaintPrgmCarrierTempTask();
    MaintPrgmCarrierTempTask(const MaintPrgmCarrierTempTask &other);
    MaintPrgmCarrierTempTask(const MaintPrgmCarrierTempTaskObject &object);
    ~MaintPrgmCarrierTempTask();

    int maintPrgmDefnId() const;
    void setMaintPrgmDefnId(int maintPrgmDefnId);
    int taskDefnId() const;
    void setTaskDefnId(int taskDefnId);
    int taskId() const;
    void setTaskId(int taskId);
    int carrierId() const;
    void setCarrierId(int carrierId);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    Carrier carrierBycarrierId() const;
    TaskTask taskTaskBytaskId() const;
    TaskDefn taskDefnBytaskDefnId() const;
    MaintPrgmDefn maintPrgmDefnBymaintPrgmDefnId() const;
    MaintPrgmCarrierTempTask &operator=(const MaintPrgmCarrierTempTask &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static MaintPrgmCarrierTempTask create(int maintPrgmDefnId, int taskDefnId, int taskId, int carrierId, const QString &createdBy, const QString &updatedBy);
    static MaintPrgmCarrierTempTask create(const QVariantMap &values);
    static MaintPrgmCarrierTempTask get(int maintPrgmDefnId, int taskDefnId, int taskId, int carrierId);
    static int count();
    static QList<MaintPrgmCarrierTempTask> getAll();

private:
    QSharedDataPointer<MaintPrgmCarrierTempTaskObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const MaintPrgmCarrierTempTask &model);
    friend QDataStream &operator>>(QDataStream &ds, MaintPrgmCarrierTempTask &model);
};

Q_DECLARE_METATYPE(MaintPrgmCarrierTempTask)
Q_DECLARE_METATYPE(QList<MaintPrgmCarrierTempTask>)

#endif // MAINTPRGMCARRIERTEMPTASK_H
