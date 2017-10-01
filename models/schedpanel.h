#ifndef SCHEDPANEL_H
#define SCHEDPANEL_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class SchedPanelObject;
class EqpPanel;
class EqpAssmbl;
class SchedStask;


class T_MODEL_EXPORT SchedPanel : public TAbstractModel
{
public:
    SchedPanel();
    SchedPanel(const SchedPanel &other);
    SchedPanel(const SchedPanelObject &object);
    ~SchedPanel();

    int schedId() const;
    void setSchedId(int schedId);
    int assmblId() const;
    void setAssmblId(int assmblId);
    int panelId() const;
    void setPanelId(int panelId);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    EqpPanel eqpPanelBypanelId() const;
    EqpAssmbl eqpAssmblByassmblId() const;
    SchedStask schedStaskByschedId() const;
    SchedPanel &operator=(const SchedPanel &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static SchedPanel create(int schedId, int assmblId, int panelId, const QString &createdBy, const QString &updatedBy);
    static SchedPanel create(const QVariantMap &values);
    static SchedPanel get(int schedId, int assmblId, int panelId);
    static int count();
    static QList<SchedPanel> getAll();

private:
    QSharedDataPointer<SchedPanelObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const SchedPanel &model);
    friend QDataStream &operator>>(QDataStream &ds, SchedPanel &model);
};

Q_DECLARE_METATYPE(SchedPanel)
Q_DECLARE_METATYPE(QList<SchedPanel>)

#endif // SCHEDPANEL_H
