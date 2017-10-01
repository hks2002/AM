#ifndef ORGDEPT_H
#define ORGDEPT_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class OrgDeptObject;
class Org;
class Dept;


class T_MODEL_EXPORT OrgDept : public TAbstractModel
{
public:
    OrgDept();
    OrgDept(const OrgDept &other);
    OrgDept(const OrgDeptObject &object);
    ~OrgDept();

    int deptId() const;
    void setDeptId(int deptId);
    int orgId() const;
    void setOrgId(int orgId);
    bool primaryBool() const;
    void setPrimaryBool(bool primaryBool);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    Org orgByorgId() const;
    Dept deptBydeptId() const;
    OrgDept &operator=(const OrgDept &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static OrgDept create(int deptId, int orgId, bool primaryBool, const QString &createdBy, const QString &updatedBy);
    static OrgDept create(const QVariantMap &values);
    static OrgDept get(int deptId, int orgId);
    static int count();
    static QList<OrgDept> getAll();

private:
    QSharedDataPointer<OrgDeptObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const OrgDept &model);
    friend QDataStream &operator>>(QDataStream &ds, OrgDept &model);
};

Q_DECLARE_METATYPE(OrgDept)
Q_DECLARE_METATYPE(QList<OrgDept>)

#endif // ORGDEPT_H
