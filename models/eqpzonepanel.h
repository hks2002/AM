#ifndef EQPZONEPANEL_H
#define EQPZONEPANEL_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class EqpZonePanelObject;
class EqpPanel;
class EqpZone;
class EqpAssmbl;


class T_MODEL_EXPORT EqpZonePanel : public TAbstractModel
{
public:
    EqpZonePanel();
    EqpZonePanel(const EqpZonePanel &other);
    EqpZonePanel(const EqpZonePanelObject &object);
    ~EqpZonePanel();

    int zonePanelId() const;
    int assmblId() const;
    void setAssmblId(int assmblId);
    int zoneId() const;
    void setZoneId(int zoneId);
    int panelId() const;
    void setPanelId(int panelId);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    EqpPanel eqpPanelBypanelId() const;
    EqpZone eqpZoneByzoneId() const;
    EqpAssmbl eqpAssmblByassmblId() const;
    EqpZonePanel &operator=(const EqpZonePanel &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static EqpZonePanel create(int assmblId, int zoneId, int panelId, const QString &createdBy, const QString &updatedBy);
    static EqpZonePanel create(const QVariantMap &values);
    static EqpZonePanel get(int zonePanelId);
    static int count();
    static QList<EqpZonePanel> getAll();

private:
    QSharedDataPointer<EqpZonePanelObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const EqpZonePanel &model);
    friend QDataStream &operator>>(QDataStream &ds, EqpZonePanel &model);
};

Q_DECLARE_METATYPE(EqpZonePanel)
Q_DECLARE_METATYPE(QList<EqpZonePanel>)

#endif // EQPZONEPANEL_H
