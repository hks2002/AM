#ifndef MANUFACT_H
#define MANUFACT_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class ManufactObject;


class T_MODEL_EXPORT Manufact : public TAbstractModel
{
public:
    Manufact();
    Manufact(const Manufact &other);
    Manufact(const ManufactObject &object);
    ~Manufact();

    int manufactId() const;
    QString manufactCd() const;
    void setManufactCd(const QString &manufactCd);
    QString manufactName() const;
    void setManufactName(const QString &manufactName);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    Manufact &operator=(const Manufact &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static Manufact create(const QString &manufactCd, const QString &manufactName, const QString &createdBy, const QString &updatedBy);
    static Manufact create(const QVariantMap &values);
    static Manufact get(int manufactId);
    static int count();
    static QList<Manufact> getAll();

private:
    QSharedDataPointer<ManufactObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const Manufact &model);
    friend QDataStream &operator>>(QDataStream &ds, Manufact &model);
};

Q_DECLARE_METATYPE(Manufact)
Q_DECLARE_METATYPE(QList<Manufact>)

#endif // MANUFACT_H
