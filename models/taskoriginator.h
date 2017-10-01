#ifndef TASKORIGINATOR_H
#define TASKORIGINATOR_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class TaskOriginatorObject;


class T_MODEL_EXPORT TaskOriginator : public TAbstractModel
{
public:
    TaskOriginator();
    TaskOriginator(const TaskOriginator &other);
    TaskOriginator(const TaskOriginatorObject &object);
    ~TaskOriginator();

    int taskOriginatorId() const;
    QString taskOriginatorCd() const;
    void setTaskOriginatorCd(const QString &taskOriginatorCd);
    QString taskOriginatorNameZh() const;
    void setTaskOriginatorNameZh(const QString &taskOriginatorNameZh);
    QString taskOriginatorNameEn() const;
    void setTaskOriginatorNameEn(const QString &taskOriginatorNameEn);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    TaskOriginator &operator=(const TaskOriginator &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static TaskOriginator create(const QString &taskOriginatorCd, const QString &taskOriginatorNameZh, const QString &taskOriginatorNameEn, const QString &createdBy, const QString &updatedBy);
    static TaskOriginator create(const QVariantMap &values);
    static TaskOriginator get(int taskOriginatorId);
    static int count();
    static QList<TaskOriginator> getAll();

private:
    QSharedDataPointer<TaskOriginatorObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const TaskOriginator &model);
    friend QDataStream &operator>>(QDataStream &ds, TaskOriginator &model);
};

Q_DECLARE_METATYPE(TaskOriginator)
Q_DECLARE_METATYPE(QList<TaskOriginator>)

#endif // TASKORIGINATOR_H
