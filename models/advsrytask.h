#ifndef ADVSRYTASK_H
#define ADVSRYTASK_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class AdvsryTaskObject;
class TaskTask;
class Advsry;


class T_MODEL_EXPORT AdvsryTask : public TAbstractModel
{
public:
    AdvsryTask();
    AdvsryTask(const AdvsryTask &other);
    AdvsryTask(const AdvsryTaskObject &object);
    ~AdvsryTask();

    int advsryTaskId() const;
    int advsryId() const;
    void setAdvsryId(int advsryId);
    int taskId() const;
    void setTaskId(int taskId);
    bool activeBool() const;
    void setActiveBool(bool activeBool);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    TaskTask taskTaskBytaskId() const;
    Advsry advsryByadvsryId() const;
    AdvsryTask &operator=(const AdvsryTask &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static AdvsryTask create(int advsryId, int taskId, bool activeBool, const QString &createdBy, const QString &updatedBy);
    static AdvsryTask create(const QVariantMap &values);
    static AdvsryTask get(int advsryTaskId);
    static int count();
    static QList<AdvsryTask> getAll();

private:
    QSharedDataPointer<AdvsryTaskObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const AdvsryTask &model);
    friend QDataStream &operator>>(QDataStream &ds, AdvsryTask &model);
};

Q_DECLARE_METATYPE(AdvsryTask)
Q_DECLARE_METATYPE(QList<AdvsryTask>)

#endif // ADVSRYTASK_H
