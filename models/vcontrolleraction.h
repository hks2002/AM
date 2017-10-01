#ifndef VCONTROLLERACTION_H
#define VCONTROLLERACTION_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class VControllerActionObject;


class T_MODEL_EXPORT VControllerAction : public TAbstractModel
{
public:
    VControllerAction();
    VControllerAction(const VControllerAction &other);
    VControllerAction(const VControllerActionObject &object);
    ~VControllerAction();

    QString controller() const;
    void setController(const QString &controller);
    QString action() const;
    void setAction(const QString &action);
    VControllerAction &operator=(const VControllerAction &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static VControllerAction create(const QString &controller, const QString &action);
    static VControllerAction create(const QVariantMap &values);
    static VControllerAction get(const QString &controller, const QString &action);
    static int count();
    static QList<VControllerAction> getAll();

private:
    QSharedDataPointer<VControllerActionObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const VControllerAction &model);
    friend QDataStream &operator>>(QDataStream &ds, VControllerAction &model);
};

Q_DECLARE_METATYPE(VControllerAction)
Q_DECLARE_METATYPE(QList<VControllerAction>)

#endif // VCONTROLLERACTION_H
