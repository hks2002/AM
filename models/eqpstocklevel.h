#ifndef EQPSTOCKLEVEL_H
#define EQPSTOCKLEVEL_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class EqpStockLevelObject;
class RefStockLowActn;
class OwnerApp;
class Loc;
class EqpStock;


class T_MODEL_EXPORT EqpStockLevel : public TAbstractModel
{
public:
    EqpStockLevel();
    EqpStockLevel(const EqpStockLevel &other);
    EqpStockLevel(const EqpStockLevelObject &object);
    ~EqpStockLevel();

    int stockId() const;
    void setStockId(int stockId);
    int locId() const;
    void setLocId(int locId);
    int ownerId() const;
    void setOwnerId(int ownerId);
    int maxQt() const;
    void setMaxQt(int maxQt);
    int minReorderQt() const;
    void setMinReorderQt(int minReorderQt);
    int reorderQt() const;
    void setReorderQt(int reorderQt);
    QString stockLowActnCd() const;
    void setStockLowActnCd(const QString &stockLowActnCd);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    RefStockLowActn refStockLowActnBystockLowActnCd() const;
    OwnerApp ownerAppByownerId() const;
    Loc locBylocId() const;
    EqpStock eqpStockBystockId() const;
    EqpStockLevel &operator=(const EqpStockLevel &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static EqpStockLevel create(int stockId, int locId, int ownerId, int maxQt, int minReorderQt, int reorderQt, const QString &stockLowActnCd, const QString &createdBy, const QString &updatedBy);
    static EqpStockLevel create(const QVariantMap &values);
    static EqpStockLevel get(int stockId, int locId, int ownerId);
    static int count();
    static QList<EqpStockLevel> getAll();

private:
    QSharedDataPointer<EqpStockLevelObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const EqpStockLevel &model);
    friend QDataStream &operator>>(QDataStream &ds, EqpStockLevel &model);
};

Q_DECLARE_METATYPE(EqpStockLevel)
Q_DECLARE_METATYPE(QList<EqpStockLevel>)

#endif // EQPSTOCKLEVEL_H
