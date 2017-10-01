#ifndef WARRANTYEVALTASK_H
#define WARRANTYEVALTASK_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class WarrantyEvalTaskObject;
class SchedStask;
class WarrantyEval;


class T_MODEL_EXPORT WarrantyEvalTask : public TAbstractModel
{
public:
    WarrantyEvalTask();
    WarrantyEvalTask(const WarrantyEvalTask &other);
    WarrantyEvalTask(const WarrantyEvalTaskObject &object);
    ~WarrantyEvalTask();

    int warrantyEvalId() const;
    void setWarrantyEvalId(int warrantyEvalId);
    int schedId() const;
    void setSchedId(int schedId);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    SchedStask schedStaskByschedId() const;
    WarrantyEval warrantyEvalBywarrantyEvalId() const;
    WarrantyEvalTask &operator=(const WarrantyEvalTask &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static WarrantyEvalTask create(int warrantyEvalId, int schedId, const QString &createdBy, const QString &updatedBy);
    static WarrantyEvalTask create(const QVariantMap &values);
    static WarrantyEvalTask get(int warrantyEvalId, int schedId);
    static int count();
    static QList<WarrantyEvalTask> getAll();

private:
    QSharedDataPointer<WarrantyEvalTaskObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const WarrantyEvalTask &model);
    friend QDataStream &operator>>(QDataStream &ds, WarrantyEvalTask &model);
};

Q_DECLARE_METATYPE(WarrantyEvalTask)
Q_DECLARE_METATYPE(QList<WarrantyEvalTask>)

#endif // WARRANTYEVALTASK_H
