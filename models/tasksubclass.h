#ifndef TASKSUBCLASS_H
#define TASKSUBCLASS_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class TaskSubclassObject;


class T_MODEL_EXPORT TaskSubclass : public TAbstractModel
{
public:
    TaskSubclass();
    TaskSubclass(const TaskSubclass &other);
    TaskSubclass(const TaskSubclassObject &object);
    ~TaskSubclass();

    int taskSubclassId() const;
    QString taskSubclassCd() const;
    void setTaskSubclassCd(const QString &taskSubclassCd);
    QString taskSubclassNameZh() const;
    void setTaskSubclassNameZh(const QString &taskSubclassNameZh);
    QString taskSubclassNameEn() const;
    void setTaskSubclassNameEn(const QString &taskSubclassNameEn);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    TaskSubclass &operator=(const TaskSubclass &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static TaskSubclass create(const QString &taskSubclassCd, const QString &taskSubclassNameZh, const QString &taskSubclassNameEn, const QString &createdBy, const QString &updatedBy);
    static TaskSubclass create(const QVariantMap &values);
    static TaskSubclass get(int taskSubclassId);
    static int count();
    static QList<TaskSubclass> getAll();

private:
    QSharedDataPointer<TaskSubclassObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const TaskSubclass &model);
    friend QDataStream &operator>>(QDataStream &ds, TaskSubclass &model);
};

Q_DECLARE_METATYPE(TaskSubclass)
Q_DECLARE_METATYPE(QList<TaskSubclass>)

#endif // TASKSUBCLASS_H
