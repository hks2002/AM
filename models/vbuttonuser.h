#ifndef VBUTTONUSER_H
#define VBUTTONUSER_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class VButtonUserObject;


class T_MODEL_EXPORT VButtonUser : public TAbstractModel
{
public:
    VButtonUser();
    VButtonUser(const VButtonUser &other);
    VButtonUser(const VButtonUserObject &object);
    ~VButtonUser();

    int buttonId() const;
    void setButtonId(int buttonId);
    QString buttonCd() const;
    void setButtonCd(const QString &buttonCd);
    QString buttonNameZh() const;
    void setButtonNameZh(const QString &buttonNameZh);
    QString buttonNameEn() const;
    void setButtonNameEn(const QString &buttonNameEn);
    QString buttonTooltip() const;
    void setButtonTooltip(const QString &buttonTooltip);
    QString buttonDesc() const;
    void setButtonDesc(const QString &buttonDesc);
    QString controller() const;
    void setController(const QString &controller);
    QString action() const;
    void setAction(const QString &action);
    int userId() const;
    void setUserId(int userId);
    int todoListOrder() const;
    void setTodoListOrder(int todoListOrder);
    int buttonOrder() const;
    void setButtonOrder(int buttonOrder);
    VButtonUser &operator=(const VButtonUser &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static VButtonUser create(int buttonId, const QString &buttonCd, const QString &buttonNameZh, const QString &buttonNameEn, const QString &buttonTooltip, const QString &buttonDesc, const QString &controller, const QString &action, int userId, int todoListOrder, int buttonOrder);
    static VButtonUser create(const QVariantMap &values);
    static VButtonUser get(int buttonId, const QString &buttonCd, const QString &buttonNameZh, const QString &buttonNameEn, const QString &buttonTooltip, const QString &buttonDesc, const QString &controller, const QString &action, int userId, int todoListOrder, int buttonOrder);
    static int count();
    static QList<VButtonUser> getAll();

private:
    QSharedDataPointer<VButtonUserObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const VButtonUser &model);
    friend QDataStream &operator>>(QDataStream &ds, VButtonUser &model);
};

Q_DECLARE_METATYPE(VButtonUser)
Q_DECLARE_METATYPE(QList<VButtonUser>)

#endif // VBUTTONUSER_H
