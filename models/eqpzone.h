#ifndef EQPZONE_H
#define EQPZONE_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class EqpZoneObject;
class EqpAssmbl;


class T_MODEL_EXPORT EqpZone : public TAbstractModel
{
public:
    EqpZone();
    EqpZone(const EqpZone &other);
    EqpZone(const EqpZoneObject &object);
    ~EqpZone();

    int zoneId() const;
    int assmblId() const;
    void setAssmblId(int assmblId);
    QString zoneCd() const;
    void setZoneCd(const QString &zoneCd);
    QString descDesc() const;
    void setDescDesc(const QString &descDesc);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    EqpAssmbl eqpAssmblByassmblId() const;
    EqpZone &operator=(const EqpZone &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static EqpZone create(int assmblId, const QString &zoneCd, const QString &descDesc, const QString &createdBy, const QString &updatedBy);
    static EqpZone create(const QVariantMap &values);
    static EqpZone get(int zoneId);
    static int count();
    static QList<EqpZone> getAll();

private:
    QSharedDataPointer<EqpZoneObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const EqpZone &model);
    friend QDataStream &operator>>(QDataStream &ds, EqpZone &model);
};

Q_DECLARE_METATYPE(EqpZone)
Q_DECLARE_METATYPE(QList<EqpZone>)

#endif // EQPZONE_H
