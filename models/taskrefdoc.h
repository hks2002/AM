#ifndef TASKREFDOC_H
#define TASKREFDOC_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class TaskRefDocObject;
class UserApp;
class RefDocDisposition;
class Manufact;
class RegBody;
class RefDocIssueBy;
class Org;
class TaskTask;


class T_MODEL_EXPORT TaskRefDoc : public TAbstractModel
{
public:
    TaskRefDoc();
    TaskRefDoc(const TaskRefDoc &other);
    TaskRefDoc(const TaskRefDocObject &object);
    ~TaskRefDoc();

    int taskId() const;
    void setTaskId(int taskId);
    int orgId() const;
    void setOrgId(int orgId);
    QString amendRefDesc() const;
    void setAmendRefDesc(const QString &amendRefDesc);
    QString docIssueByCd() const;
    void setDocIssueByCd(const QString &docIssueByCd);
    int regBodyId() const;
    void setRegBodyId(int regBodyId);
    int manufactId() const;
    void setManufactId(int manufactId);
    QDateTime issueDt() const;
    void setIssueDt(const QDateTime &issueDt);
    QDateTime receivedDt() const;
    void setReceivedDt(const QDateTime &receivedDt);
    int receivedBy() const;
    void setReceivedBy(int receivedBy);
    QString docDispositionCd() const;
    void setDocDispositionCd(const QString &docDispositionCd);
    QDateTime dispositionDt() const;
    void setDispositionDt(const QDateTime &dispositionDt);
    int dispositionBy() const;
    void setDispositionBy(int dispositionBy);
    QString dispositionDesc() const;
    void setDispositionDesc(const QString &dispositionDesc);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    UserApp userAppBydispositionBy() const;
    RefDocDisposition refDocDispositionBydocDispositionCd() const;
    Manufact manufactBymanufactId() const;
    RegBody regBodyByregBodyId() const;
    RefDocIssueBy refDocIssueByBydocIssueByCd() const;
    Org orgByorgId() const;
    TaskTask taskTaskBytaskId() const;
    TaskRefDoc &operator=(const TaskRefDoc &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static TaskRefDoc create(int taskId, int orgId, const QString &amendRefDesc, const QString &docIssueByCd, int regBodyId, int manufactId, const QDateTime &issueDt, const QDateTime &receivedDt, int receivedBy, const QString &docDispositionCd, const QDateTime &dispositionDt, int dispositionBy, const QString &dispositionDesc, const QString &createdBy, const QString &updatedBy);
    static TaskRefDoc create(const QVariantMap &values);
    static TaskRefDoc get(int taskId);
    static int count();
    static QList<TaskRefDoc> getAll();

private:
    QSharedDataPointer<TaskRefDocObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const TaskRefDoc &model);
    friend QDataStream &operator>>(QDataStream &ds, TaskRefDoc &model);
};

Q_DECLARE_METATYPE(TaskRefDoc)
Q_DECLARE_METATYPE(QList<TaskRefDoc>)

#endif // TASKREFDOC_H
