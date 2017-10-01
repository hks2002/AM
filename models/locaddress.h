#ifndef LOCADDRESS_H
#define LOCADDRESS_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class LocAddressObject;
class Address;
class Loc;


class T_MODEL_EXPORT LocAddress : public TAbstractModel
{
public:
    LocAddress();
    LocAddress(const LocAddress &other);
    LocAddress(const LocAddressObject &object);
    ~LocAddress();

    int locId() const;
    void setLocId(int locId);
    int addressId() const;
    void setAddressId(int addressId);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    Address addressByaddressId() const;
    Loc locBylocId() const;
    LocAddress &operator=(const LocAddress &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static LocAddress create(int locId, int addressId, const QString &createdBy, const QString &updatedBy);
    static LocAddress create(const QVariantMap &values);
    static LocAddress get(int locId);
    static int count();
    static QList<LocAddress> getAll();

private:
    QSharedDataPointer<LocAddressObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const LocAddress &model);
    friend QDataStream &operator>>(QDataStream &ds, LocAddress &model);
};

Q_DECLARE_METATYPE(LocAddress)
Q_DECLARE_METATYPE(QList<LocAddress>)

#endif // LOCADDRESS_H
