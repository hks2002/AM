#ifndef EQPPARTNOCOMPATTASK_H
#define EQPPARTNOCOMPATTASK_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class EqpPartNoCompatTaskObject;
class TaskDefn;
class EqpPartNo;
class EqpAssmbl;


class T_MODEL_EXPORT EqpPartNoCompatTask : public TAbstractModel
{
public:
    EqpPartNoCompatTask();
    EqpPartNoCompatTask(const EqpPartNoCompatTask &other);
    EqpPartNoCompatTask(const EqpPartNoCompatTaskObject &object);
    ~EqpPartNoCompatTask();

    int assmblId() const;
    void setAssmblId(int assmblId);
    int partNoId() const;
    void setPartNoId(int partNoId);
    int taskDefnId() const;
    void setTaskDefnId(int taskDefnId);
    bool preCompleteBool() const;
    void setPreCompleteBool(bool preCompleteBool);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    TaskDefn taskDefnBytaskDefnId() const;
    EqpPartNo eqpPartNoBypartNoId() const;
    EqpAssmbl eqpAssmblByassmblId() const;
    EqpPartNoCompatTask &operator=(const EqpPartNoCompatTask &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static EqpPartNoCompatTask create(int assmblId, int partNoId, int taskDefnId, bool preCompleteBool, const QString &createdBy, const QString &updatedBy);
    static EqpPartNoCompatTask create(const QVariantMap &values);
    static EqpPartNoCompatTask get(int assmblId, int partNoId, int taskDefnId);
    static int count();
    static QList<EqpPartNoCompatTask> getAll();

private:
    QSharedDataPointer<EqpPartNoCompatTaskObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const EqpPartNoCompatTask &model);
    friend QDataStream &operator>>(QDataStream &ds, EqpPartNoCompatTask &model);
};

Q_DECLARE_METATYPE(EqpPartNoCompatTask)
Q_DECLARE_METATYPE(QList<EqpPartNoCompatTask>)

#endif // EQPPARTNOCOMPATTASK_H
