#ifndef ADVSRYTASKROLE_H
#define ADVSRYTASKROLE_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class AdvsryTaskRoleObject;
class RoleApp;
class AdvsryTask;


class T_MODEL_EXPORT AdvsryTaskRole : public TAbstractModel
{
public:
    AdvsryTaskRole();
    AdvsryTaskRole(const AdvsryTaskRole &other);
    AdvsryTaskRole(const AdvsryTaskRoleObject &object);
    ~AdvsryTaskRole();

    int advsryTaskId() const;
    void setAdvsryTaskId(int advsryTaskId);
    int roleId() const;
    void setRoleId(int roleId);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    RoleApp roleAppByroleId() const;
    AdvsryTask advsryTaskByadvsryTaskId() const;
    AdvsryTaskRole &operator=(const AdvsryTaskRole &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static AdvsryTaskRole create(int advsryTaskId, int roleId, const QString &createdBy, const QString &updatedBy);
    static AdvsryTaskRole create(const QVariantMap &values);
    static AdvsryTaskRole get(int advsryTaskId, int roleId);
    static int count();
    static QList<AdvsryTaskRole> getAll();

private:
    QSharedDataPointer<AdvsryTaskRoleObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const AdvsryTaskRole &model);
    friend QDataStream &operator>>(QDataStream &ds, AdvsryTaskRole &model);
};

Q_DECLARE_METATYPE(AdvsryTaskRole)
Q_DECLARE_METATYPE(QList<AdvsryTaskRole>)

#endif // ADVSRYTASKROLE_H
