#ifndef VCONTROLLERACTIONUSER_H
#define VCONTROLLERACTIONUSER_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class VControllerActionUserObject;


class T_MODEL_EXPORT VControllerActionUser : public TAbstractModel
{
public:
    VControllerActionUser();
    VControllerActionUser(const VControllerActionUser &other);
    VControllerActionUser(const VControllerActionUserObject &object);
    ~VControllerActionUser();

    QString controller() const;
    void setController(const QString &controller);
    QString action() const;
    void setAction(const QString &action);
    int userId() const;
    void setUserId(int userId);
    VControllerActionUser &operator=(const VControllerActionUser &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static VControllerActionUser create(const QString &controller, const QString &action, int userId);
    static VControllerActionUser create(const QVariantMap &values);
    static VControllerActionUser get(const QString &controller, const QString &action, int userId);
    static int count();
    static QList<VControllerActionUser> getAll();

private:
    QSharedDataPointer<VControllerActionUserObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const VControllerActionUser &model);
    friend QDataStream &operator>>(QDataStream &ds, VControllerActionUser &model);
};

Q_DECLARE_METATYPE(VControllerActionUser)
Q_DECLARE_METATYPE(QList<VControllerActionUser>)

#endif // VCONTROLLERACTIONUSER_H
