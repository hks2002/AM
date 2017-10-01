#ifndef VCONTROLLERACTIONUSERBUTTON_H
#define VCONTROLLERACTIONUSERBUTTON_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class VControllerActionUserButtonObject;


class T_MODEL_EXPORT VControllerActionUserButton : public TAbstractModel
{
public:
    VControllerActionUserButton();
    VControllerActionUserButton(const VControllerActionUserButton &other);
    VControllerActionUserButton(const VControllerActionUserButtonObject &object);
    ~VControllerActionUserButton();

    QString controller() const;
    void setController(const QString &controller);
    QString action() const;
    void setAction(const QString &action);
    int userId() const;
    void setUserId(int userId);
    VControllerActionUserButton &operator=(const VControllerActionUserButton &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static VControllerActionUserButton create(const QString &controller, const QString &action, int userId);
    static VControllerActionUserButton create(const QVariantMap &values);
    static VControllerActionUserButton get(const QString &controller, const QString &action, int userId);
    static int count();
    static QList<VControllerActionUserButton> getAll();

private:
    QSharedDataPointer<VControllerActionUserButtonObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const VControllerActionUserButton &model);
    friend QDataStream &operator>>(QDataStream &ds, VControllerActionUserButton &model);
};

Q_DECLARE_METATYPE(VControllerActionUserButton)
Q_DECLARE_METATYPE(QList<VControllerActionUserButton>)

#endif // VCONTROLLERACTIONUSERBUTTON_H
