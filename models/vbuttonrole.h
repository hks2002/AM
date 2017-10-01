#ifndef VBUTTONROLE_H
#define VBUTTONROLE_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class VButtonRoleObject;


class T_MODEL_EXPORT VButtonRole : public TAbstractModel
{
public:
    VButtonRole();
    VButtonRole(const VButtonRole &other);
    VButtonRole(const VButtonRoleObject &object);
    ~VButtonRole();

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
    int roleId() const;
    void setRoleId(int roleId);
    int todoListOrder() const;
    void setTodoListOrder(int todoListOrder);
    int buttonOrder() const;
    void setButtonOrder(int buttonOrder);
    VButtonRole &operator=(const VButtonRole &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static VButtonRole create(int buttonId, const QString &buttonCd, const QString &buttonNameZh, const QString &buttonNameEn, const QString &buttonTooltip, const QString &buttonDesc, const QString &controller, const QString &action, int roleId, int todoListOrder, int buttonOrder);
    static VButtonRole create(const QVariantMap &values);
    static VButtonRole get(int buttonId, const QString &buttonCd, const QString &buttonNameZh, const QString &buttonNameEn, const QString &buttonTooltip, const QString &buttonDesc, const QString &controller, const QString &action, int roleId, int todoListOrder, int buttonOrder);
    static int count();
    static QList<VButtonRole> getAll();

private:
    QSharedDataPointer<VButtonRoleObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const VButtonRole &model);
    friend QDataStream &operator>>(QDataStream &ds, VButtonRole &model);
};

Q_DECLARE_METATYPE(VButtonRole)
Q_DECLARE_METATYPE(QList<VButtonRole>)

#endif // VBUTTONROLE_H
