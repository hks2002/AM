#ifndef VTODOLISTBUTTONUSER_H
#define VTODOLISTBUTTONUSER_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class VTodoListButtonUserObject;


class T_MODEL_EXPORT VTodoListButtonUser : public TAbstractModel
{
public:
    VTodoListButtonUser();
    VTodoListButtonUser(const VTodoListButtonUser &other);
    VTodoListButtonUser(const VTodoListButtonUserObject &object);
    ~VTodoListButtonUser();

    int userId() const;
    void setUserId(int userId);
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
    VTodoListButtonUser &operator=(const VTodoListButtonUser &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static VTodoListButtonUser create(int userId, int todoListOrder, int todoListId, const QString &todoListCd, const QString &todoListNameZh, const QString &todoListNameEn, const QString &todoListTooltip, const QString &todoListDesc, int buttonId, int buttonOrder, const QString &buttonCd, const QString &buttonNameZh, const QString &buttonNameEn, const QString &buttonTooltip, const QString &buttonDesc, const QString &controller, const QString &action);
    static VTodoListButtonUser create(const QVariantMap &values);
    static VTodoListButtonUser get(int userId, int todoListOrder, int todoListId, const QString &todoListCd, const QString &todoListNameZh, const QString &todoListNameEn, const QString &todoListTooltip, const QString &todoListDesc, int buttonId, int buttonOrder, const QString &buttonCd, const QString &buttonNameZh, const QString &buttonNameEn, const QString &buttonTooltip, const QString &buttonDesc, const QString &controller, const QString &action);
    static int count();
    static QList<VTodoListButtonUser> getAll();

private:
    QSharedDataPointer<VTodoListButtonUserObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const VTodoListButtonUser &model);
    friend QDataStream &operator>>(QDataStream &ds, VTodoListButtonUser &model);
};

Q_DECLARE_METATYPE(VTodoListButtonUser)
Q_DECLARE_METATYPE(QList<VTodoListButtonUser>)

#endif // VTODOLISTBUTTONUSER_H
