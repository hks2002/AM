#ifndef LOCAIRPORTSETTING_H
#define LOCAIRPORTSETTING_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class LocAirportSettingObject;
class Loc;


class T_MODEL_EXPORT LocAirportSetting : public TAbstractModel
{
public:
    LocAirportSetting();
    LocAirportSetting(const LocAirportSetting &other);
    LocAirportSetting(const LocAirportSettingObject &object);
    ~LocAirportSetting();

    int locId() const;
    void setLocId(int locId);
    QString timezoneCd() const;
    void setTimezoneCd(const QString &timezoneCd);
    bool supplyBool() const;
    void setSupplyBool(bool supplyBool);
    int inboundFlightQt() const;
    void setInboundFlightQt(int inboundFlightQt);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    Loc locBylocId() const;
    LocAirportSetting &operator=(const LocAirportSetting &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static LocAirportSetting create(int locId, const QString &timezoneCd, bool supplyBool, int inboundFlightQt, const QString &createdBy, const QString &updatedBy);
    static LocAirportSetting create(const QVariantMap &values);
    static LocAirportSetting get(int locId);
    static int count();
    static QList<LocAirportSetting> getAll();

private:
    QSharedDataPointer<LocAirportSettingObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const LocAirportSetting &model);
    friend QDataStream &operator>>(QDataStream &ds, LocAirportSetting &model);
};

Q_DECLARE_METATYPE(LocAirportSetting)
Q_DECLARE_METATYPE(QList<LocAirportSetting>)

#endif // LOCAIRPORTSETTING_H
