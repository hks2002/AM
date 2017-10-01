#ifndef LOCWORKTYPECAPABILITY_H
#define LOCWORKTYPECAPABILITY_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class LocWorkTypeCapabilityObject;
class WorkType;
class EqpAssmbl;
class Loc;


class T_MODEL_EXPORT LocWorkTypeCapability : public TAbstractModel
{
public:
    LocWorkTypeCapability();
    LocWorkTypeCapability(const LocWorkTypeCapability &other);
    LocWorkTypeCapability(const LocWorkTypeCapabilityObject &object);
    ~LocWorkTypeCapability();

    int locId() const;
    void setLocId(int locId);
    int assmblId() const;
    void setAssmblId(int assmblId);
    int workTypeId() const;
    void setWorkTypeId(int workTypeId);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    WorkType workTypeByworkTypeId() const;
    EqpAssmbl eqpAssmblByassmblId() const;
    Loc locBylocId() const;
    LocWorkTypeCapability &operator=(const LocWorkTypeCapability &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static LocWorkTypeCapability create(int locId, int assmblId, int workTypeId, const QString &createdBy, const QString &updatedBy);
    static LocWorkTypeCapability create(const QVariantMap &values);
    static LocWorkTypeCapability get(int locId, int assmblId, int workTypeId);
    static int count();
    static QList<LocWorkTypeCapability> getAll();

private:
    QSharedDataPointer<LocWorkTypeCapabilityObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const LocWorkTypeCapability &model);
    friend QDataStream &operator>>(QDataStream &ds, LocWorkTypeCapability &model);
};

Q_DECLARE_METATYPE(LocWorkTypeCapability)
Q_DECLARE_METATYPE(QList<LocWorkTypeCapability>)

#endif // LOCWORKTYPECAPABILITY_H
