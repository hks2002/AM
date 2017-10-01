#ifndef DEPTUSER_H
#define DEPTUSER_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class DeptUserObject;
class UserApp;
class Dept;


class T_MODEL_EXPORT DeptUser : public TAbstractModel
{
public:
    DeptUser();
    DeptUser(const DeptUser &other);
    DeptUser(const DeptUserObject &object);
    ~DeptUser();

    int deptId() const;
    void setDeptId(int deptId);
    int userId() const;
    void setUserId(int userId);
    bool defaultBool() const;
    void setDefaultBool(bool defaultBool);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    UserApp userAppByuserId() const;
    Dept deptBydeptId() const;
    DeptUser &operator=(const DeptUser &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static DeptUser create(int deptId, int userId, bool defaultBool, const QString &createdBy, const QString &updatedBy);
    static DeptUser create(const QVariantMap &values);
    static DeptUser get(int deptId, int userId);
    static int count();
    static QList<DeptUser> getAll();

private:
    QSharedDataPointer<DeptUserObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const DeptUser &model);
    friend QDataStream &operator>>(QDataStream &ds, DeptUser &model);
};

Q_DECLARE_METATYPE(DeptUser)
Q_DECLARE_METATYPE(QList<DeptUser>)

#endif // DEPTUSER_H
