#ifndef LOCSHOPREPAIR_H
#define LOCSHOPREPAIR_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class LocShopRepairObject;
class EqpPartNo;
class Loc;


class T_MODEL_EXPORT LocShopRepair : public TAbstractModel
{
public:
    LocShopRepair();
    LocShopRepair(const LocShopRepair &other);
    LocShopRepair(const LocShopRepairObject &object);
    ~LocShopRepair();

    int locId() const;
    void setLocId(int locId);
    int partNoId() const;
    void setPartNoId(int partNoId);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    EqpPartNo eqpPartNoBypartNoId() const;
    Loc locBylocId() const;
    LocShopRepair &operator=(const LocShopRepair &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static LocShopRepair create(int locId, int partNoId, const QString &createdBy, const QString &updatedBy);
    static LocShopRepair create(const QVariantMap &values);
    static LocShopRepair get(int locId, int partNoId);
    static int count();
    static QList<LocShopRepair> getAll();

private:
    QSharedDataPointer<LocShopRepairObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const LocShopRepair &model);
    friend QDataStream &operator>>(QDataStream &ds, LocShopRepair &model);
};

Q_DECLARE_METATYPE(LocShopRepair)
Q_DECLARE_METATYPE(QList<LocShopRepair>)

#endif // LOCSHOPREPAIR_H
