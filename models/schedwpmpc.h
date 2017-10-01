#ifndef SCHEDWPMPC_H
#define SCHEDWPMPC_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class SchedWpMpcObject;
class TaskTask;
class SchedWp;


class T_MODEL_EXPORT SchedWpMpc : public TAbstractModel
{
public:
    SchedWpMpc();
    SchedWpMpc(const SchedWpMpc &other);
    SchedWpMpc(const SchedWpMpcObject &object);
    ~SchedWpMpc();

    int schedId() const;
    void setSchedId(int schedId);
    int taskId() const;
    void setTaskId(int taskId);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    TaskTask taskTaskBytaskId() const;
    SchedWp schedWpByschedId() const;
    SchedWpMpc &operator=(const SchedWpMpc &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static SchedWpMpc create(int schedId, int taskId, const QString &createdBy, const QString &updatedBy);
    static SchedWpMpc create(const QVariantMap &values);
    static SchedWpMpc get(int schedId, int taskId);
    static int count();
    static QList<SchedWpMpc> getAll();

private:
    QSharedDataPointer<SchedWpMpcObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const SchedWpMpc &model);
    friend QDataStream &operator>>(QDataStream &ds, SchedWpMpc &model);
};

Q_DECLARE_METATYPE(SchedWpMpc)
Q_DECLARE_METATYPE(QList<SchedWpMpc>)

#endif // SCHEDWPMPC_H
