#ifndef TASKASSEMBLBOM_H
#define TASKASSEMBLBOM_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class TaskAssemblBomObject;
class EqpAssmbl;
class EqpAssmblBom;
class TaskTask;


class T_MODEL_EXPORT TaskAssemblBom : public TAbstractModel
{
public:
    TaskAssemblBom();
    TaskAssemblBom(const TaskAssemblBom &other);
    TaskAssemblBom(const TaskAssemblBomObject &object);
    ~TaskAssemblBom();

    int taskId() const;
    void setTaskId(int taskId);
    int assmblBomId() const;
    void setAssmblBomId(int assmblBomId);
    int assmblId() const;
    void setAssmblId(int assmblId);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    EqpAssmbl eqpAssmblByassmblId() const;
    EqpAssmblBom eqpAssmblBomByassmblBomId() const;
    TaskTask taskTaskBytaskId() const;
    TaskAssemblBom &operator=(const TaskAssemblBom &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static TaskAssemblBom create(int taskId, int assmblBomId, int assmblId, const QString &createdBy, const QString &updatedBy);
    static TaskAssemblBom create(const QVariantMap &values);
    static TaskAssemblBom get(int taskId, int assmblBomId, int assmblId);
    static int count();
    static QList<TaskAssemblBom> getAll();

private:
    QSharedDataPointer<TaskAssemblBomObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const TaskAssemblBom &model);
    friend QDataStream &operator>>(QDataStream &ds, TaskAssemblBom &model);
};

Q_DECLARE_METATYPE(TaskAssemblBom)
Q_DECLARE_METATYPE(QList<TaskAssemblBom>)

#endif // TASKASSEMBLBOM_H
