#ifndef SCHEDZONE_H
#define SCHEDZONE_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class SchedZoneObject;
class EqpZone;
class EqpAssmbl;
class SchedStask;


class T_MODEL_EXPORT SchedZone : public TAbstractModel
{
public:
    SchedZone();
    SchedZone(const SchedZone &other);
    SchedZone(const SchedZoneObject &object);
    ~SchedZone();

    int schedId() const;
    void setSchedId(int schedId);
    int assmblId() const;
    void setAssmblId(int assmblId);
    int zoneId() const;
    void setZoneId(int zoneId);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    EqpZone eqpZoneByzoneId() const;
    EqpAssmbl eqpAssmblByassmblId() const;
    SchedStask schedStaskByschedId() const;
    SchedZone &operator=(const SchedZone &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static SchedZone create(int schedId, int assmblId, int zoneId, const QString &createdBy, const QString &updatedBy);
    static SchedZone create(const QVariantMap &values);
    static SchedZone get(int schedId, int assmblId, int zoneId);
    static int count();
    static QList<SchedZone> getAll();

private:
    QSharedDataPointer<SchedZoneObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const SchedZone &model);
    friend QDataStream &operator>>(QDataStream &ds, SchedZone &model);
};

Q_DECLARE_METATYPE(SchedZone)
Q_DECLARE_METATYPE(QList<SchedZone>)

#endif // SCHEDZONE_H
