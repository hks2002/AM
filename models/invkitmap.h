#ifndef INVKITMAP_H
#define INVKITMAP_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class InvKitMapObject;
class InvInv;
class InvKit;


class T_MODEL_EXPORT InvKitMap : public TAbstractModel
{
public:
    InvKitMap();
    InvKitMap(const InvKitMap &other);
    InvKitMap(const InvKitMapObject &object);
    ~InvKitMap();

    int invKitMapId() const;
    int kitInvNoId() const;
    void setKitInvNoId(int kitInvNoId);
    int invNoId() const;
    void setInvNoId(int invNoId);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    InvInv invInvByinvNoId() const;
    InvKit invKitBykitInvNoId() const;
    InvKitMap &operator=(const InvKitMap &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static InvKitMap create(int kitInvNoId, int invNoId, const QString &createdBy, const QString &updatedBy);
    static InvKitMap create(const QVariantMap &values);
    static InvKitMap get(int invKitMapId);
    static int count();
    static QList<InvKitMap> getAll();

private:
    QSharedDataPointer<InvKitMapObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const InvKitMap &model);
    friend QDataStream &operator>>(QDataStream &ds, InvKitMap &model);
};

Q_DECLARE_METATYPE(InvKitMap)
Q_DECLARE_METATYPE(QList<InvKitMap>)

#endif // INVKITMAP_H
