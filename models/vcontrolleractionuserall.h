#ifndef VCONTROLLERACTIONUSERALL_H
#define VCONTROLLERACTIONUSERALL_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class VControllerActionUserAllObject;


class T_MODEL_EXPORT VControllerActionUserAll : public TAbstractModel
{
public:
    VControllerActionUserAll();
    VControllerActionUserAll(const VControllerActionUserAll &other);
    VControllerActionUserAll(const VControllerActionUserAllObject &object);
    ~VControllerActionUserAll();

    QString controller() const;
    void setController(const QString &controller);
    QString action() const;
    void setAction(const QString &action);
    int userId() const;
    void setUserId(int userId);
    VControllerActionUserAll &operator=(const VControllerActionUserAll &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static VControllerActionUserAll create(const QString &controller, const QString &action, int userId);
    static VControllerActionUserAll create(const QVariantMap &values);
    static VControllerActionUserAll get(const QString &controller, const QString &action, int userId);
    static int count();
    static QList<VControllerActionUserAll> getAll();

private:
    QSharedDataPointer<VControllerActionUserAllObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const VControllerActionUserAll &model);
    friend QDataStream &operator>>(QDataStream &ds, VControllerActionUserAll &model);
};

Q_DECLARE_METATYPE(VControllerActionUserAll)
Q_DECLARE_METATYPE(QList<VControllerActionUserAll>)

#endif // VCONTROLLERACTIONUSERALL_H
