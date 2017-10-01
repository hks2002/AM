#ifndef SCHEDSTASK_H
#define SCHEDSTASK_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class SchedStaskObject;
class FncAccount;
class RefReschedFrom;
class RefCancelWhen;
class RefFirstSchedFrom;
class InvInv;
class TaskOriginator;
class TaskSubclass;
class RefTaskClass;
class EqpPartNo;
class TaskTask;


class T_MODEL_EXPORT SchedStask : public TAbstractModel
{
public:
    SchedStask();
    SchedStask(const SchedStask &other);
    SchedStask(const SchedStaskObject &object);
    ~SchedStask();

    int schedId() const;
    int hSchedId() const;
    void setHSchedId(int hSchedId);
    int taskId() const;
    void setTaskId(int taskId);
    int partNoId() const;
    void setPartNoId(int partNoId);
    QString taskClassCd() const;
    void setTaskClassCd(const QString &taskClassCd);
    int taskSubclassId() const;
    void setTaskSubclassId(int taskSubclassId);
    int taskOriginatorId() const;
    void setTaskOriginatorId(int taskOriginatorId);
    QString taskRefDesc() const;
    void setTaskRefDesc(const QString &taskRefDesc);
    int invNoId() const;
    void setInvNoId(int invNoId);
    QString taskName() const;
    void setTaskName(const QString &taskName);
    QString taskDesc() const;
    void setTaskDesc(const QString &taskDesc);
    QString instructionDesc() const;
    void setInstructionDesc(const QString &instructionDesc);
    QString operationRestriction() const;
    void setOperationRestriction(const QString &operationRestriction);
    QString engineeringDesc() const;
    void setEngineeringDesc(const QString &engineeringDesc);
    QString barcodeDesc() const;
    void setBarcodeDesc(const QString &barcodeDesc);
    QString estDurationQt() const;
    void setEstDurationQt(const QString &estDurationQt);
    QString nrMultQt() const;
    void setNrMultQt(const QString &nrMultQt);
    QString firstSchedFromCd() const;
    void setFirstSchedFromCd(const QString &firstSchedFromCd);
    QString cancelWhenCd() const;
    void setCancelWhenCd(const QString &cancelWhenCd);
    QString reschedFromCd() const;
    void setReschedFromCd(const QString &reschedFromCd);
    QDateTime planByDt() const;
    void setPlanByDt(const QDateTime &planByDt);
    QString warrantyNote() const;
    void setWarrantyNote(const QString &warrantyNote);
    int woCommitLineOrd() const;
    void setWoCommitLineOrd(int woCommitLineOrd);
    int accountId() const;
    void setAccountId(int accountId);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    FncAccount fncAccountByaccountId() const;
    RefReschedFrom refReschedFromByreschedFromCd() const;
    RefCancelWhen refCancelWhenBycancelWhenCd() const;
    RefFirstSchedFrom refFirstSchedFromByfirstSchedFromCd() const;
    InvInv invInvByinvNoId() const;
    TaskOriginator taskOriginatorBytaskOriginatorId() const;
    TaskSubclass taskSubclassBytaskSubclassId() const;
    RefTaskClass refTaskClassBytaskClassCd() const;
    EqpPartNo eqpPartNoBypartNoId() const;
    TaskTask taskTaskBytaskId() const;
    SchedStask &operator=(const SchedStask &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static SchedStask create(int hSchedId, int taskId, int partNoId, const QString &taskClassCd, int taskSubclassId, int taskOriginatorId, const QString &taskRefDesc, int invNoId, const QString &taskName, const QString &taskDesc, const QString &instructionDesc, const QString &operationRestriction, const QString &engineeringDesc, const QString &barcodeDesc, const QString &estDurationQt, const QString &nrMultQt, const QString &firstSchedFromCd, const QString &cancelWhenCd, const QString &reschedFromCd, const QDateTime &planByDt, const QString &warrantyNote, int woCommitLineOrd, int accountId, const QString &createdBy, const QString &updatedBy);
    static SchedStask create(const QVariantMap &values);
    static SchedStask get(int schedId);
    static int count();
    static QList<SchedStask> getAll();

private:
    QSharedDataPointer<SchedStaskObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const SchedStask &model);
    friend QDataStream &operator>>(QDataStream &ds, SchedStask &model);
};

Q_DECLARE_METATYPE(SchedStask)
Q_DECLARE_METATYPE(QList<SchedStask>)

#endif // SCHEDSTASK_H
