#ifndef DEPTSUBDEPT_H
#define DEPTSUBDEPT_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class DeptSubdeptObject;
class Dept;


class T_MODEL_EXPORT DeptSubdept : public TAbstractModel
{
public:
    DeptSubdept();
    DeptSubdept(const DeptSubdept &other);
    DeptSubdept(const DeptSubdeptObject &object);
    ~DeptSubdept();

    int deptId() const;
    void setDeptId(int deptId);
    int subDeptId() const;
    void setSubDeptId(int subDeptId);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    Dept deptBysubDeptId() const;
    DeptSubdept &operator=(const DeptSubdept &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static DeptSubdept create(int deptId, int subDeptId, const QString &createdBy, const QString &updatedBy);
    static DeptSubdept create(const QVariantMap &values);
    static DeptSubdept get(int deptId, int subDeptId);
    static int count();
    static QList<DeptSubdept> getAll();

private:
    QSharedDataPointer<DeptSubdeptObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const DeptSubdept &model);
    friend QDataStream &operator>>(QDataStream &ds, DeptSubdept &model);
};

Q_DECLARE_METATYPE(DeptSubdept)
Q_DECLARE_METATYPE(QList<DeptSubdept>)

#endif // DEPTSUBDEPT_H
