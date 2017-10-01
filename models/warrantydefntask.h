#ifndef WARRANTYDEFNTASK_H
#define WARRANTYDEFNTASK_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class WarrantyDefnTaskObject;
class TaskTask;
class WarrantyDefn;


class T_MODEL_EXPORT WarrantyDefnTask : public TAbstractModel
{
public:
    WarrantyDefnTask();
    WarrantyDefnTask(const WarrantyDefnTask &other);
    WarrantyDefnTask(const WarrantyDefnTaskObject &object);
    ~WarrantyDefnTask();

    int warrantyDefnId() const;
    void setWarrantyDefnId(int warrantyDefnId);
    int taskId() const;
    void setTaskId(int taskId);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    TaskTask taskTaskBytaskId() const;
    WarrantyDefn warrantyDefnBywarrantyDefnId() const;
    WarrantyDefnTask &operator=(const WarrantyDefnTask &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static WarrantyDefnTask create(int warrantyDefnId, int taskId, const QString &createdBy, const QString &updatedBy);
    static WarrantyDefnTask create(const QVariantMap &values);
    static WarrantyDefnTask get(int warrantyDefnId, int taskId);
    static int count();
    static QList<WarrantyDefnTask> getAll();

private:
    QSharedDataPointer<WarrantyDefnTaskObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const WarrantyDefnTask &model);
    friend QDataStream &operator>>(QDataStream &ds, WarrantyDefnTask &model);
};

Q_DECLARE_METATYPE(WarrantyDefnTask)
Q_DECLARE_METATYPE(QList<WarrantyDefnTask>)

#endif // WARRANTYDEFNTASK_H
