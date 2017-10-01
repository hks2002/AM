#ifndef VCONTROLLERACTIONROLETAB_H
#define VCONTROLLERACTIONROLETAB_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class VControllerActionRoleTabObject;


class T_MODEL_EXPORT VControllerActionRoleTab : public TAbstractModel
{
public:
    VControllerActionRoleTab();
    VControllerActionRoleTab(const VControllerActionRoleTab &other);
    VControllerActionRoleTab(const VControllerActionRoleTabObject &object);
    ~VControllerActionRoleTab();

    QString controller() const;
    void setController(const QString &controller);
    QString action() const;
    void setAction(const QString &action);
    int roleId() const;
    void setRoleId(int roleId);
    VControllerActionRoleTab &operator=(const VControllerActionRoleTab &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static VControllerActionRoleTab create(const QString &controller, const QString &action, int roleId);
    static VControllerActionRoleTab create(const QVariantMap &values);
    static VControllerActionRoleTab get(const QString &controller, const QString &action, int roleId);
    static int count();
    static QList<VControllerActionRoleTab> getAll();

private:
    QSharedDataPointer<VControllerActionRoleTabObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const VControllerActionRoleTab &model);
    friend QDataStream &operator>>(QDataStream &ds, VControllerActionRoleTab &model);
};

Q_DECLARE_METATYPE(VControllerActionRoleTab)
Q_DECLARE_METATYPE(QList<VControllerActionRoleTab>)

#endif // VCONTROLLERACTIONROLETAB_H
