#ifndef VCONTROLLERACTIONROLEBUTTON_H
#define VCONTROLLERACTIONROLEBUTTON_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class VControllerActionRoleButtonObject;


class T_MODEL_EXPORT VControllerActionRoleButton : public TAbstractModel
{
public:
    VControllerActionRoleButton();
    VControllerActionRoleButton(const VControllerActionRoleButton &other);
    VControllerActionRoleButton(const VControllerActionRoleButtonObject &object);
    ~VControllerActionRoleButton();

    QString controller() const;
    void setController(const QString &controller);
    QString action() const;
    void setAction(const QString &action);
    int roleId() const;
    void setRoleId(int roleId);
    VControllerActionRoleButton &operator=(const VControllerActionRoleButton &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static VControllerActionRoleButton create(const QString &controller, const QString &action, int roleId);
    static VControllerActionRoleButton create(const QVariantMap &values);
    static VControllerActionRoleButton get(const QString &controller, const QString &action, int roleId);
    static int count();
    static QList<VControllerActionRoleButton> getAll();

private:
    QSharedDataPointer<VControllerActionRoleButtonObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const VControllerActionRoleButton &model);
    friend QDataStream &operator>>(QDataStream &ds, VControllerActionRoleButton &model);
};

Q_DECLARE_METATYPE(VControllerActionRoleButton)
Q_DECLARE_METATYPE(QList<VControllerActionRoleButton>)

#endif // VCONTROLLERACTIONROLEBUTTON_H
