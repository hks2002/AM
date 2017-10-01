#ifndef MAINTPRGMCARRIERMAP_H
#define MAINTPRGMCARRIERMAP_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class MaintPrgmCarrierMapObject;
class Carrier;
class MaintPrgm;


class T_MODEL_EXPORT MaintPrgmCarrierMap : public TAbstractModel
{
public:
    MaintPrgmCarrierMap();
    MaintPrgmCarrierMap(const MaintPrgmCarrierMap &other);
    MaintPrgmCarrierMap(const MaintPrgmCarrierMapObject &object);
    ~MaintPrgmCarrierMap();

    int maintPrgmId() const;
    void setMaintPrgmId(int maintPrgmId);
    int carrierId() const;
    void setCarrierId(int carrierId);
    int carrierRevisionOrd() const;
    void setCarrierRevisionOrd(int carrierRevisionOrd);
    bool latestRevisionBool() const;
    void setLatestRevisionBool(bool latestRevisionBool);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    Carrier carrierBycarrierId() const;
    MaintPrgm maintPrgmBymaintPrgmId() const;
    MaintPrgmCarrierMap &operator=(const MaintPrgmCarrierMap &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static MaintPrgmCarrierMap create(int maintPrgmId, int carrierId, int carrierRevisionOrd, bool latestRevisionBool, const QString &createdBy, const QString &updatedBy);
    static MaintPrgmCarrierMap create(const QVariantMap &values);
    static MaintPrgmCarrierMap get(int maintPrgmId, int carrierId);
    static int count();
    static QList<MaintPrgmCarrierMap> getAll();

private:
    QSharedDataPointer<MaintPrgmCarrierMapObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const MaintPrgmCarrierMap &model);
    friend QDataStream &operator>>(QDataStream &ds, MaintPrgmCarrierMap &model);
};

Q_DECLARE_METATYPE(MaintPrgmCarrierMap)
Q_DECLARE_METATYPE(QList<MaintPrgmCarrierMap>)

#endif // MAINTPRGMCARRIERMAP_H
