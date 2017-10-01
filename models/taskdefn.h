#ifndef TASKDEFN_H
#define TASKDEFN_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class TaskDefnObject;


class T_MODEL_EXPORT TaskDefn : public TAbstractModel
{
public:
    TaskDefn();
    TaskDefn(const TaskDefn &other);
    TaskDefn(const TaskDefnObject &object);
    ~TaskDefn();

    int taskDefnId() const;
    int lastRevisionOrd() const;
    void setLastRevisionOrd(int lastRevisionOrd);
    bool newRevisionBool() const;
    void setNewRevisionBool(bool newRevisionBool);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    TaskDefn &operator=(const TaskDefn &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static TaskDefn create(int lastRevisionOrd, bool newRevisionBool, const QString &createdBy, const QString &updatedBy);
    static TaskDefn create(const QVariantMap &values);
    static TaskDefn get(int taskDefnId);
    static int count();
    static QList<TaskDefn> getAll();

private:
    QSharedDataPointer<TaskDefnObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const TaskDefn &model);
    friend QDataStream &operator>>(QDataStream &ds, TaskDefn &model);
};

Q_DECLARE_METATYPE(TaskDefn)
Q_DECLARE_METATYPE(QList<TaskDefn>)

#endif // TASKDEFN_H
