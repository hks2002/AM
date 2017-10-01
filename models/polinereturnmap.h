#ifndef POLINERETURNMAP_H
#define POLINERETURNMAP_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class PoLineReturnMapObject;
class InvInv;
class PoLine;


class T_MODEL_EXPORT PoLineReturnMap : public TAbstractModel
{
public:
    PoLineReturnMap();
    PoLineReturnMap(const PoLineReturnMap &other);
    PoLineReturnMap(const PoLineReturnMapObject &object);
    ~PoLineReturnMap();

    int poLineId() const;
    void setPoLineId(int poLineId);
    int invNoId() const;
    void setInvNoId(int invNoId);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    InvInv invInvByinvNoId() const;
    PoLine poLineBypoLineId() const;
    PoLineReturnMap &operator=(const PoLineReturnMap &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static PoLineReturnMap create(int poLineId, int invNoId, const QString &createdBy, const QString &updatedBy);
    static PoLineReturnMap create(const QVariantMap &values);
    static PoLineReturnMap get(int poLineId);
    static int count();
    static QList<PoLineReturnMap> getAll();

private:
    QSharedDataPointer<PoLineReturnMapObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const PoLineReturnMap &model);
    friend QDataStream &operator>>(QDataStream &ds, PoLineReturnMap &model);
};

Q_DECLARE_METATYPE(PoLineReturnMap)
Q_DECLARE_METATYPE(QList<PoLineReturnMap>)

#endif // POLINERETURNMAP_H
