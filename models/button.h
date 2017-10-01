#ifndef BUTTON_H
#define BUTTON_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class ButtonObject;


class T_MODEL_EXPORT Button : public TAbstractModel
{
public:
    Button();
    Button(const Button &other);
    Button(const ButtonObject &object);
    ~Button();

    int buttonId() const;
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
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    Button &operator=(const Button &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static Button create(const QString &buttonCd, const QString &buttonNameZh, const QString &buttonNameEn, const QString &buttonTooltip, const QString &buttonDesc, const QString &controller, const QString &action, const QString &createdBy, const QString &updatedBy);
    static Button create(const QVariantMap &values);
    static Button get(int buttonId);
    static int count();
    static QList<Button> getAll();

private:
    QSharedDataPointer<ButtonObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const Button &model);
    friend QDataStream &operator>>(QDataStream &ds, Button &model);
};

Q_DECLARE_METATYPE(Button)
Q_DECLARE_METATYPE(QList<Button>)

#endif // BUTTON_H
