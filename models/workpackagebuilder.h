#ifndef WORKPACKAGEBUILDER_H
#define WORKPACKAGEBUILDER_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class WorkpackageBuilderObject;
class EqpPartNo;
class EqpAssmbl;
class TaskTask;
class RefWorkpackageType;


class T_MODEL_EXPORT WorkpackageBuilder : public TAbstractModel
{
public:
    WorkpackageBuilder();
    WorkpackageBuilder(const WorkpackageBuilder &other);
    WorkpackageBuilder(const WorkpackageBuilderObject &object);
    ~WorkpackageBuilder();

    int workpackageBuilderId() const;
    QString workpackageBuilderName() const;
    void setWorkpackageBuilderName(const QString &workpackageBuilderName);
    QString workpackageTypeCd() const;
    void setWorkpackageTypeCd(const QString &workpackageTypeCd);
    QString workpackageNameString() const;
    void setWorkpackageNameString(const QString &workpackageNameString);
    int taskId() const;
    void setTaskId(int taskId);
    int assmblId() const;
    void setAssmblId(int assmblId);
    int partNoId() const;
    void setPartNoId(int partNoId);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    EqpPartNo eqpPartNoBypartNoId() const;
    EqpAssmbl eqpAssmblByassmblId() const;
    TaskTask taskTaskBytaskId() const;
    RefWorkpackageType refWorkpackageTypeByworkpackageTypeCd() const;
    WorkpackageBuilder &operator=(const WorkpackageBuilder &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static WorkpackageBuilder create(const QString &workpackageBuilderName, const QString &workpackageTypeCd, const QString &workpackageNameString, int taskId, int assmblId, int partNoId, const QString &createdBy, const QString &updatedBy);
    static WorkpackageBuilder create(const QVariantMap &values);
    static WorkpackageBuilder get(int workpackageBuilderId);
    static int count();
    static QList<WorkpackageBuilder> getAll();

private:
    QSharedDataPointer<WorkpackageBuilderObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const WorkpackageBuilder &model);
    friend QDataStream &operator>>(QDataStream &ds, WorkpackageBuilder &model);
};

Q_DECLARE_METATYPE(WorkpackageBuilder)
Q_DECLARE_METATYPE(QList<WorkpackageBuilder>)

#endif // WORKPACKAGEBUILDER_H
