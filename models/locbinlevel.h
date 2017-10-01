#ifndef LOCBINLEVEL_H
#define LOCBINLEVEL_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class LocBinLevelObject;
class OwnerApp;
class EqpPartNo;
class Loc;


class T_MODEL_EXPORT LocBinLevel : public TAbstractModel
{
public:
    LocBinLevel();
    LocBinLevel(const LocBinLevel &other);
    LocBinLevel(const LocBinLevelObject &object);
    ~LocBinLevel();

    int locId() const;
    void setLocId(int locId);
    int partNoId() const;
    void setPartNoId(int partNoId);
    int ownerId() const;
    void setOwnerId(int ownerId);
    int minQt() const;
    void setMinQt(int minQt);
    int maxQt() const;
    void setMaxQt(int maxQt);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    OwnerApp ownerAppByownerId() const;
    EqpPartNo eqpPartNoBypartNoId() const;
    Loc locBylocId() const;
    LocBinLevel &operator=(const LocBinLevel &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static LocBinLevel create(int locId, int partNoId, int ownerId, int minQt, int maxQt, const QString &createdBy, const QString &updatedBy);
    static LocBinLevel create(const QVariantMap &values);
    static LocBinLevel get(int locId, int partNoId, int ownerId);
    static int count();
    static QList<LocBinLevel> getAll();

private:
    QSharedDataPointer<LocBinLevelObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const LocBinLevel &model);
    friend QDataStream &operator>>(QDataStream &ds, LocBinLevel &model);
};

Q_DECLARE_METATYPE(LocBinLevel)
Q_DECLARE_METATYPE(QList<LocBinLevel>)

#endif // LOCBINLEVEL_H
