#ifndef TASKLABOURREQ_H
#define TASKLABOURREQ_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class TaskLabourReqObject;
class License;
class LabourSkill;
class TaskTask;


class T_MODEL_EXPORT TaskLabourReq : public TAbstractModel
{
public:
    TaskLabourReq();
    TaskLabourReq(const TaskLabourReq &other);
    TaskLabourReq(const TaskLabourReqObject &object);
    ~TaskLabourReq();

    int taskId() const;
    void setTaskId(int taskId);
    int labourSkillId() const;
    void setLabourSkillId(int labourSkillId);
    QString manHour() const;
    void setManHour(const QString &manHour);
    int manCt() const;
    void setManCt(int manCt);
    bool inspBool() const;
    void setInspBool(bool inspBool);
    double inspHour() const;
    void setInspHour(double inspHour);
    int inspLicense() const;
    void setInspLicense(int inspLicense);
    bool riiBool() const;
    void setRiiBool(bool riiBool);
    double riiHour() const;
    void setRiiHour(double riiHour);
    int riiLicense() const;
    void setRiiLicense(int riiLicense);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    License licenseByriiLicense() const;
    LabourSkill labourSkillBylabourSkillId() const;
    TaskTask taskTaskBytaskId() const;
    TaskLabourReq &operator=(const TaskLabourReq &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static TaskLabourReq create(int taskId, int labourSkillId, const QString &manHour, int manCt, bool inspBool, double inspHour, int inspLicense, bool riiBool, double riiHour, int riiLicense, const QString &createdBy, const QString &updatedBy);
    static TaskLabourReq create(const QVariantMap &values);
    static TaskLabourReq get(int taskId, int labourSkillId);
    static int count();
    static QList<TaskLabourReq> getAll();

private:
    QSharedDataPointer<TaskLabourReqObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const TaskLabourReq &model);
    friend QDataStream &operator>>(QDataStream &ds, TaskLabourReq &model);
};

Q_DECLARE_METATYPE(TaskLabourReq)
Q_DECLARE_METATYPE(QList<TaskLabourReq>)

#endif // TASKLABOURREQ_H
