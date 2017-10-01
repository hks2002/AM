#ifndef VCONTROLLERACTIONROLEUSER_H
#define VCONTROLLERACTIONROLEUSER_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class VControllerActionRoleUserObject;


class T_MODEL_EXPORT VControllerActionRoleUser : public TAbstractModel
{
public:
    VControllerActionRoleUser();
    VControllerActionRoleUser(const VControllerActionRoleUser &other);
    VControllerActionRoleUser(const VControllerActionRoleUserObject &object);
    ~VControllerActionRoleUser();

    QString controller() const;
    void setController(const QString &controller);
    QString action() const;
    void setAction(const QString &action);
    int roleId() const;
    void setRoleId(int roleId);
    int userId() const;
    void setUserId(int userId);
    VControllerActionRoleUser &operator=(const VControllerActionRoleUser &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static VControllerActionRoleUser create(const QString &controller, const QString &action, int roleId, int userId);
    static VControllerActionRoleUser create(const QVariantMap &values);
    static VControllerActionRoleUser get(const QString &controller, const QString &action, int roleId, int userId);
    static VControllerActionRoleUser getByUser(const QString &controller, const QString &action, int userId);
    static VControllerActionRoleUser getByRole(const QString &controller, const QString &action, int roleId);
    static int count();
    static QList<VControllerActionRoleUser> getAll();

private:
    QSharedDataPointer<VControllerActionRoleUserObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const VControllerActionRoleUser &model);
    friend QDataStream &operator>>(QDataStream &ds, VControllerActionRoleUser &model);
};

Q_DECLARE_METATYPE(VControllerActionRoleUser)
Q_DECLARE_METATYPE(QList<VControllerActionRoleUser>)

#endif // VCONTROLLERACTIONROLEUSER_H
