#ifndef VCONTROLLERACTIONALL_H
#define VCONTROLLERACTIONALL_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class VControllerActionAllObject;


class T_MODEL_EXPORT VControllerActionAll : public TAbstractModel
{
public:
    VControllerActionAll();
    VControllerActionAll(const VControllerActionAll &other);
    VControllerActionAll(const VControllerActionAllObject &object);
    ~VControllerActionAll();

    QString controller() const;
    void setController(const QString &controller);
    QString action() const;
    void setAction(const QString &action);
    VControllerActionAll &operator=(const VControllerActionAll &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static VControllerActionAll create(const QString &controller, const QString &action);
    static VControllerActionAll create(const QVariantMap &values);
    static VControllerActionAll get(const QString &controller, const QString &action);
    static int count();
    static QList<VControllerActionAll> getAll();

private:
    QSharedDataPointer<VControllerActionAllObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const VControllerActionAll &model);
    friend QDataStream &operator>>(QDataStream &ds, VControllerActionAll &model);
};

Q_DECLARE_METATYPE(VControllerActionAll)
Q_DECLARE_METATYPE(QList<VControllerActionAll>)

#endif // VCONTROLLERACTIONALL_H
