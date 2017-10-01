#ifndef EQPPANEL_H
#define EQPPANEL_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class EqpPanelObject;
class EqpAssmbl;


class T_MODEL_EXPORT EqpPanel : public TAbstractModel
{
public:
    EqpPanel();
    EqpPanel(const EqpPanel &other);
    EqpPanel(const EqpPanelObject &object);
    ~EqpPanel();

    int panelId() const;
    int assmblId() const;
    void setAssmblId(int assmblId);
    QString panelCd() const;
    void setPanelCd(const QString &panelCd);
    QString descDesc() const;
    void setDescDesc(const QString &descDesc);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    EqpAssmbl eqpAssmblByassmblId() const;
    EqpPanel &operator=(const EqpPanel &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static EqpPanel create(int assmblId, const QString &panelCd, const QString &descDesc, const QString &createdBy, const QString &updatedBy);
    static EqpPanel create(const QVariantMap &values);
    static EqpPanel get(int panelId);
    static int count();
    static QList<EqpPanel> getAll();

private:
    QSharedDataPointer<EqpPanelObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const EqpPanel &model);
    friend QDataStream &operator>>(QDataStream &ds, EqpPanel &model);
};

Q_DECLARE_METATYPE(EqpPanel)
Q_DECLARE_METATYPE(QList<EqpPanel>)

#endif // EQPPANEL_H
