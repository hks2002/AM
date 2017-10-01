#ifndef VCONTROLLERACTIONROLEALL_H
#define VCONTROLLERACTIONROLEALL_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class VControllerActionRoleAllObject;


class T_MODEL_EXPORT VControllerActionRoleAll : public TAbstractModel
{
public:
    VControllerActionRoleAll();
    VControllerActionRoleAll(const VControllerActionRoleAll &other);
    VControllerActionRoleAll(const VControllerActionRoleAllObject &object);
    ~VControllerActionRoleAll();

    QString controller() const;
    void setController(const QString &controller);
    QString action() const;
    void setAction(const QString &action);
    int roleId() const;
    void setRoleId(int roleId);
    VControllerActionRoleAll &operator=(const VControllerActionRoleAll &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static VControllerActionRoleAll create(const QString &controller, const QString &action, int roleId);
    static VControllerActionRoleAll create(const QVariantMap &values);
    static VControllerActionRoleAll get(const QString &controller, const QString &action, int roleId);
    static int count();
    static QList<VControllerActionRoleAll> getAll();

private:
    QSharedDataPointer<VControllerActionRoleAllObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const VControllerActionRoleAll &model);
    friend QDataStream &operator>>(QDataStream &ds, VControllerActionRoleAll &model);
};

Q_DECLARE_METATYPE(VControllerActionRoleAll)
Q_DECLARE_METATYPE(QList<VControllerActionRoleAll>)

#endif // VCONTROLLERACTIONROLEALL_H
