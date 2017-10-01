#ifndef VCONTROLLERACTIONUSERACTION_H
#define VCONTROLLERACTIONUSERACTION_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class VControllerActionUserActionObject;


class T_MODEL_EXPORT VControllerActionUserAction : public TAbstractModel
{
public:
    VControllerActionUserAction();
    VControllerActionUserAction(const VControllerActionUserAction &other);
    VControllerActionUserAction(const VControllerActionUserActionObject &object);
    ~VControllerActionUserAction();

    QString controller() const;
    void setController(const QString &controller);
    QString action() const;
    void setAction(const QString &action);
    int userId() const;
    void setUserId(int userId);
    VControllerActionUserAction &operator=(const VControllerActionUserAction &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static VControllerActionUserAction create(const QString &controller, const QString &action, int userId);
    static VControllerActionUserAction create(const QVariantMap &values);
    static VControllerActionUserAction get(const QString &controller, const QString &action, int userId);
    static int count();
    static QList<VControllerActionUserAction> getAll();

private:
    QSharedDataPointer<VControllerActionUserActionObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const VControllerActionUserAction &model);
    friend QDataStream &operator>>(QDataStream &ds, VControllerActionUserAction &model);
};

Q_DECLARE_METATYPE(VControllerActionUserAction)
Q_DECLARE_METATYPE(QList<VControllerActionUserAction>)

#endif // VCONTROLLERACTIONUSERACTION_H
