#ifndef ADVSRYPART_H
#define ADVSRYPART_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class AdvsryPartObject;
class EqpPartNo;
class Manufact;
class Advsry;


class T_MODEL_EXPORT AdvsryPart : public TAbstractModel
{
public:
    AdvsryPart();
    AdvsryPart(const AdvsryPart &other);
    AdvsryPart(const AdvsryPartObject &object);
    ~AdvsryPart();

    int advsryId() const;
    void setAdvsryId(int advsryId);
    int manufactId() const;
    void setManufactId(int manufactId);
    int partNoId() const;
    void setPartNoId(int partNoId);
    QString lotNoRange() const;
    void setLotNoRange(const QString &lotNoRange);
    QString serialNoRange() const;
    void setSerialNoRange(const QString &serialNoRange);
    bool activeBool() const;
    void setActiveBool(bool activeBool);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    EqpPartNo eqpPartNoBypartNoId() const;
    Manufact manufactBymanufactId() const;
    Advsry advsryByadvsryId() const;
    AdvsryPart &operator=(const AdvsryPart &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static AdvsryPart create(int advsryId, int manufactId, int partNoId, const QString &lotNoRange, const QString &serialNoRange, bool activeBool, const QString &createdBy, const QString &updatedBy);
    static AdvsryPart create(const QVariantMap &values);
    static AdvsryPart get(int advsryId, int manufactId, int partNoId);
    static int count();
    static QList<AdvsryPart> getAll();

private:
    QSharedDataPointer<AdvsryPartObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const AdvsryPart &model);
    friend QDataStream &operator>>(QDataStream &ds, AdvsryPart &model);
};

Q_DECLARE_METATYPE(AdvsryPart)
Q_DECLARE_METATYPE(QList<AdvsryPart>)

#endif // ADVSRYPART_H
