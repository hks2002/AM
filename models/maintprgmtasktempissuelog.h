#ifndef MAINTPRGMTASKTEMPISSUELOG_H
#define MAINTPRGMTASKTEMPISSUELOG_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class MaintPrgmTaskTempIssueLogObject;
class UserApp;
class TaskTask;
class MaintPrgm;


class T_MODEL_EXPORT MaintPrgmTaskTempIssueLog : public TAbstractModel
{
public:
    MaintPrgmTaskTempIssueLog();
    MaintPrgmTaskTempIssueLog(const MaintPrgmTaskTempIssueLog &other);
    MaintPrgmTaskTempIssueLog(const MaintPrgmTaskTempIssueLogObject &object);
    ~MaintPrgmTaskTempIssueLog();

    int taskTempIssueLogId() const;
    int maintPrgmId() const;
    void setMaintPrgmId(int maintPrgmId);
    int taskId() const;
    void setTaskId(int taskId);
    int tempIssueBy() const;
    void setTempIssueBy(int tempIssueBy);
    QDateTime tempIssueDt() const;
    void setTempIssueDt(const QDateTime &tempIssueDt);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    UserApp userAppBytempIssueBy() const;
    TaskTask taskTaskBytaskId() const;
    MaintPrgm maintPrgmBymaintPrgmId() const;
    MaintPrgmTaskTempIssueLog &operator=(const MaintPrgmTaskTempIssueLog &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static MaintPrgmTaskTempIssueLog create(int maintPrgmId, int taskId, int tempIssueBy, const QDateTime &tempIssueDt, const QString &createdBy, const QString &updatedBy);
    static MaintPrgmTaskTempIssueLog create(const QVariantMap &values);
    static MaintPrgmTaskTempIssueLog get(int taskTempIssueLogId);
    static int count();
    static QList<MaintPrgmTaskTempIssueLog> getAll();

private:
    QSharedDataPointer<MaintPrgmTaskTempIssueLogObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const MaintPrgmTaskTempIssueLog &model);
    friend QDataStream &operator>>(QDataStream &ds, MaintPrgmTaskTempIssueLog &model);
};

Q_DECLARE_METATYPE(MaintPrgmTaskTempIssueLog)
Q_DECLARE_METATYPE(QList<MaintPrgmTaskTempIssueLog>)

#endif // MAINTPRGMTASKTEMPISSUELOG_H
