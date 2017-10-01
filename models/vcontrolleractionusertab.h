#ifndef VCONTROLLERACTIONUSERTAB_H
#define VCONTROLLERACTIONUSERTAB_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class VControllerActionUserTabObject;


class T_MODEL_EXPORT VControllerActionUserTab : public TAbstractModel
{
public:
    VControllerActionUserTab();
    VControllerActionUserTab(const VControllerActionUserTab &other);
    VControllerActionUserTab(const VControllerActionUserTabObject &object);
    ~VControllerActionUserTab();

    QString controller() const;
    void setController(const QString &controller);
    QString action() const;
    void setAction(const QString &action);
    int userId() const;
    void setUserId(int userId);
    VControllerActionUserTab &operator=(const VControllerActionUserTab &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static VControllerActionUserTab create(const QString &controller, const QString &action, int userId);
    static VControllerActionUserTab create(const QVariantMap &values);
    static VControllerActionUserTab get(const QString &controller, const QString &action, int userId);
    static int count();
    static QList<VControllerActionUserTab> getAll();

private:
    QSharedDataPointer<VControllerActionUserTabObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const VControllerActionUserTab &model);
    friend QDataStream &operator>>(QDataStream &ds, VControllerActionUserTab &model);
};

Q_DECLARE_METATYPE(VControllerActionUserTab)
Q_DECLARE_METATYPE(QList<VControllerActionUserTab>)

#endif // VCONTROLLERACTIONUSERTAB_H
