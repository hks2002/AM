#ifndef LOCSUBLOC_H
#define LOCSUBLOC_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class LocSublocObject;
class Loc;


class T_MODEL_EXPORT LocSubloc : public TAbstractModel
{
public:
    LocSubloc();
    LocSubloc(const LocSubloc &other);
    LocSubloc(const LocSublocObject &object);
    ~LocSubloc();

    int locId() const;
    void setLocId(int locId);
    int subLocId() const;
    void setSubLocId(int subLocId);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    Loc locBysubLocId() const;
    LocSubloc &operator=(const LocSubloc &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static LocSubloc create(int locId, int subLocId, const QString &createdBy, const QString &updatedBy);
    static LocSubloc create(const QVariantMap &values);
    static LocSubloc get(int locId, int subLocId);
    static int count();
    static QList<LocSubloc> getAll();

private:
    QSharedDataPointer<LocSublocObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const LocSubloc &model);
    friend QDataStream &operator>>(QDataStream &ds, LocSubloc &model);
};

Q_DECLARE_METATYPE(LocSubloc)
Q_DECLARE_METATYPE(QList<LocSubloc>)

#endif // LOCSUBLOC_H
