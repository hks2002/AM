#ifndef ADVSRYTASKDEPT_H
#define ADVSRYTASKDEPT_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class AdvsryTaskDeptObject;
class Dept;
class AdvsryTask;


class T_MODEL_EXPORT AdvsryTaskDept : public TAbstractModel
{
public:
    AdvsryTaskDept();
    AdvsryTaskDept(const AdvsryTaskDept &other);
    AdvsryTaskDept(const AdvsryTaskDeptObject &object);
    ~AdvsryTaskDept();

    int advsryTaskId() const;
    void setAdvsryTaskId(int advsryTaskId);
    int deptId() const;
    void setDeptId(int deptId);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    Dept deptBydeptId() const;
    AdvsryTask advsryTaskByadvsryTaskId() const;
    AdvsryTaskDept &operator=(const AdvsryTaskDept &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static AdvsryTaskDept create(int advsryTaskId, int deptId, const QString &createdBy, const QString &updatedBy);
    static AdvsryTaskDept create(const QVariantMap &values);
    static AdvsryTaskDept get(int advsryTaskId, int deptId);
    static int count();
    static QList<AdvsryTaskDept> getAll();

private:
    QSharedDataPointer<AdvsryTaskDeptObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const AdvsryTaskDept &model);
    friend QDataStream &operator>>(QDataStream &ds, AdvsryTaskDept &model);
};

Q_DECLARE_METATYPE(AdvsryTaskDept)
Q_DECLARE_METATYPE(QList<AdvsryTaskDept>)

#endif // ADVSRYTASKDEPT_H
