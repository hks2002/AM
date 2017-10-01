#ifndef SCHEDIMPACT_H
#define SCHEDIMPACT_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class SchedImpactObject;
class MesurUnit;
class RefMesurType;
class SchedStask;


class T_MODEL_EXPORT SchedImpact : public TAbstractModel
{
public:
    SchedImpact();
    SchedImpact(const SchedImpact &other);
    SchedImpact(const SchedImpactObject &object);
    ~SchedImpact();

    int schedId() const;
    void setSchedId(int schedId);
    QString mesurTypeCd() const;
    void setMesurTypeCd(const QString &mesurTypeCd);
    int mesurUnitId() const;
    void setMesurUnitId(int mesurUnitId);
    double mesurQt() const;
    void setMesurQt(double mesurQt);
    QString impactDesc() const;
    void setImpactDesc(const QString &impactDesc);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    MesurUnit mesurUnitBymesurUnitId() const;
    RefMesurType refMesurTypeBymesurTypeCd() const;
    SchedStask schedStaskByschedId() const;
    SchedImpact &operator=(const SchedImpact &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static SchedImpact create(int schedId, const QString &mesurTypeCd, int mesurUnitId, double mesurQt, const QString &impactDesc, const QString &createdBy, const QString &updatedBy);
    static SchedImpact create(const QVariantMap &values);
    static SchedImpact get(int schedId, const QString &mesurTypeCd, int mesurUnitId);
    static int count();
    static QList<SchedImpact> getAll();

private:
    QSharedDataPointer<SchedImpactObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const SchedImpact &model);
    friend QDataStream &operator>>(QDataStream &ds, SchedImpact &model);
};

Q_DECLARE_METATYPE(SchedImpact)
Q_DECLARE_METATYPE(QList<SchedImpact>)

#endif // SCHEDIMPACT_H
