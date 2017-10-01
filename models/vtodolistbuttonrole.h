#ifndef VTODOLISTBUTTONROLE_H
#define VTODOLISTBUTTONROLE_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class VTodoListButtonRoleObject;


class T_MODEL_EXPORT VTodoListButtonRole : public TAbstractModel
{
public:
    VTodoListButtonRole();
    VTodoListButtonRole(const VTodoListButtonRole &other);
    VTodoListButtonRole(const VTodoListButtonRoleObject &object);
    ~VTodoListButtonRole();

    int roleId() const;
    void setRoleId(int roleId);
    int todoListOrder() const;
    void setTodoListOrder(int todoListOrder);
    int todoListId() const;
    void setTodoListId(int todoListId);
    QString todoListCd() const;
    void setTodoListCd(const QString &todoListCd);
    QString todoListNameZh() const;
    void setTodoListNameZh(const QString &todoListNameZh);
    QString todoListNameEn() const;
    void setTodoListNameEn(const QString &todoListNameEn);
    QString todoListTooltip() const;
    void setTodoListTooltip(const QString &todoListTooltip);
    QString todoListDesc() const;
    void setTodoListDesc(const QString &todoListDesc);
    int buttonId() const;
    void setButtonId(int buttonId);
    int buttonOrder() const;
    void setButtonOrder(int buttonOrder);
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
    VTodoListButtonRole &operator=(const VTodoListButtonRole &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static VTodoListButtonRole create(int roleId, int todoListOrder, int todoListId, const QString &todoListCd, const QString &todoListNameZh, const QString &todoListNameEn, const QString &todoListTooltip, const QString &todoListDesc, int buttonId, int buttonOrder, const QString &buttonCd, const QString &buttonNameZh, const QString &buttonNameEn, const QString &buttonTooltip, const QString &buttonDesc, const QString &controller, const QString &action);
    static VTodoListButtonRole create(const QVariantMap &values);
    static VTodoListButtonRole get(int roleId, int todoListOrder, int todoListId, const QString &todoListCd, const QString &todoListNameZh, const QString &todoListNameEn, const QString &todoListTooltip, const QString &todoListDesc, int buttonId, int buttonOrder, const QString &buttonCd, const QString &buttonNameZh, const QString &buttonNameEn, const QString &buttonTooltip, const QString &buttonDesc, const QString &controller, const QString &action);
    static int count();
    static QList<VTodoListButtonRole> getAll();

private:
    QSharedDataPointer<VTodoListButtonRoleObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const VTodoListButtonRole &model);
    friend QDataStream &operator>>(QDataStream &ds, VTodoListButtonRole &model);
};

Q_DECLARE_METATYPE(VTodoListButtonRole)
Q_DECLARE_METATYPE(QList<VTodoListButtonRole>)

#endif // VTODOLISTBUTTONROLE_H
