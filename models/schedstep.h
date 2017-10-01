#ifndef SCHEDSTEP_H
#define SCHEDSTEP_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class SchedStepObject;
class TaskStep;
class SchedStask;


class T_MODEL_EXPORT SchedStep : public TAbstractModel
{
public:
    SchedStep();
    SchedStep(const SchedStep &other);
    SchedStep(const SchedStepObject &object);
    ~SchedStep();

    int stepId() const;
    int schedId() const;
    void setSchedId(int schedId);
    int taskId() const;
    void setTaskId(int taskId);
    QString stepDesc() const;
    void setStepDesc(const QString &stepDesc);
    int stepOrd() const;
    void setStepOrd(int stepOrd);
    bool signBool() const;
    void setSignBool(bool signBool);
    bool inspBool() const;
    void setInspBool(bool inspBool);
    bool riiBool() const;
    void setRiiBool(bool riiBool);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    TaskStep taskStepBytaskIdstepOrd() const;
    SchedStask schedStaskByschedId() const;
    SchedStep &operator=(const SchedStep &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static SchedStep create(int schedId, int taskId, const QString &stepDesc, int stepOrd, bool signBool, bool inspBool, bool riiBool, const QString &createdBy, const QString &updatedBy);
    static SchedStep create(const QVariantMap &values);
    static SchedStep get(int stepId);
    static int count();
    static QList<SchedStep> getAll();

private:
    QSharedDataPointer<SchedStepObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const SchedStep &model);
    friend QDataStream &operator>>(QDataStream &ds, SchedStep &model);
};

Q_DECLARE_METATYPE(SchedStep)
Q_DECLARE_METATYPE(QList<SchedStep>)

#endif // SCHEDSTEP_H
