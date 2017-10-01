#ifndef MAINTPRGMTASK_H
#define MAINTPRGMTASK_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class MaintPrgmTaskObject;
class UserApp;
class TaskTask;
class TaskDefn;
class MaintPrgm;


class T_MODEL_EXPORT MaintPrgmTask : public TAbstractModel
{
public:
    MaintPrgmTask();
    MaintPrgmTask(const MaintPrgmTask &other);
    MaintPrgmTask(const MaintPrgmTaskObject &object);
    ~MaintPrgmTask();

    int maintPrgmId() const;
    void setMaintPrgmId(int maintPrgmId);
    int taskDefnId() const;
    void setTaskDefnId(int taskDefnId);
    int taskId() const;
    void setTaskId(int taskId);
    int blockDefnId() const;
    void setBlockDefnId(int blockDefnId);
    int blockId() const;
    void setBlockId(int blockId);
    QString blockNote() const;
    void setBlockNote(const QString &blockNote);
    int issueOrd() const;
    void setIssueOrd(int issueOrd);
    QString groupCd() const;
    void setGroupCd(const QString &groupCd);
    bool unassignBool() const;
    void setUnassignBool(bool unassignBool);
    bool onConditionBool() const;
    void setOnConditionBool(bool onConditionBool);
    QDateTime actionDt() const;
    void setActionDt(const QDateTime &actionDt);
    QString actionNote() const;
    void setActionNote(const QString &actionNote);
    int actionBy() const;
    void setActionBy(int actionBy);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    UserApp userAppByactionBy() const;
    TaskTask taskTaskByblockId() const;
    TaskDefn taskDefnByblockDefnId() const;
    MaintPrgm maintPrgmBymaintPrgmId() const;
    MaintPrgmTask &operator=(const MaintPrgmTask &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static MaintPrgmTask create(int maintPrgmId, int taskDefnId, int taskId, int blockDefnId, int blockId, const QString &blockNote, int issueOrd, const QString &groupCd, bool unassignBool, bool onConditionBool, const QDateTime &actionDt, const QString &actionNote, int actionBy, const QString &createdBy, const QString &updatedBy);
    static MaintPrgmTask create(const QVariantMap &values);
    static MaintPrgmTask get(int maintPrgmId, int taskDefnId, int taskId, int blockDefnId, int blockId);
    static int count();
    static QList<MaintPrgmTask> getAll();

private:
    QSharedDataPointer<MaintPrgmTaskObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const MaintPrgmTask &model);
    friend QDataStream &operator>>(QDataStream &ds, MaintPrgmTask &model);
};

Q_DECLARE_METATYPE(MaintPrgmTask)
Q_DECLARE_METATYPE(QList<MaintPrgmTask>)

#endif // MAINTPRGMTASK_H
