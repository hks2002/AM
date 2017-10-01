#ifndef ALERTDEFDEPT_H
#define ALERTDEFDEPT_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class AlertDefDeptObject;
class Dept;
class AlertDef;


class T_MODEL_EXPORT AlertDefDept : public TAbstractModel
{
public:
    AlertDefDept();
    AlertDefDept(const AlertDefDept &other);
    AlertDefDept(const AlertDefDeptObject &object);
    ~AlertDefDept();

    int alertDefId() const;
    void setAlertDefId(int alertDefId);
    int deptId() const;
    void setDeptId(int deptId);
    bool activeBool() const;
    void setActiveBool(bool activeBool);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    Dept deptBydeptId() const;
    AlertDef alertDefByalertDefId() const;
    AlertDefDept &operator=(const AlertDefDept &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static AlertDefDept create(int alertDefId, int deptId, bool activeBool, const QString &createdBy, const QString &updatedBy);
    static AlertDefDept create(const QVariantMap &values);
    static AlertDefDept get(int alertDefId, int deptId);
    static int count();
    static QList<AlertDefDept> getAll();

private:
    QSharedDataPointer<AlertDefDeptObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const AlertDefDept &model);
    friend QDataStream &operator>>(QDataStream &ds, AlertDefDept &model);
};

Q_DECLARE_METATYPE(AlertDefDept)
Q_DECLARE_METATYPE(QList<AlertDefDept>)

#endif // ALERTDEFDEPT_H
