#ifndef WARRANTYINITTASK_H
#define WARRANTYINITTASK_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class WarrantyInitTaskObject;
class SchedStask;
class WarrantyInit;


class T_MODEL_EXPORT WarrantyInitTask : public TAbstractModel
{
public:
    WarrantyInitTask();
    WarrantyInitTask(const WarrantyInitTask &other);
    WarrantyInitTask(const WarrantyInitTaskObject &object);
    ~WarrantyInitTask();

    int warrantyInitId() const;
    void setWarrantyInitId(int warrantyInitId);
    int schedId() const;
    void setSchedId(int schedId);
    bool mainBool() const;
    void setMainBool(bool mainBool);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    SchedStask schedStaskByschedId() const;
    WarrantyInit warrantyInitBywarrantyInitId() const;
    WarrantyInitTask &operator=(const WarrantyInitTask &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static WarrantyInitTask create(int warrantyInitId, int schedId, bool mainBool, const QString &createdBy, const QString &updatedBy);
    static WarrantyInitTask create(const QVariantMap &values);
    static WarrantyInitTask get(int warrantyInitId, int schedId);
    static int count();
    static QList<WarrantyInitTask> getAll();

private:
    QSharedDataPointer<WarrantyInitTaskObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const WarrantyInitTask &model);
    friend QDataStream &operator>>(QDataStream &ds, WarrantyInitTask &model);
};

Q_DECLARE_METATYPE(WarrantyInitTask)
Q_DECLARE_METATYPE(QList<WarrantyInitTask>)

#endif // WARRANTYINITTASK_H
