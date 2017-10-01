#ifndef LOCDOCKSETTING_H
#define LOCDOCKSETTING_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class LocDockSettingObject;
class Loc;


class T_MODEL_EXPORT LocDockSetting : public TAbstractModel
{
public:
    LocDockSetting();
    LocDockSetting(const LocDockSetting &other);
    LocDockSetting(const LocDockSettingObject &object);
    ~LocDockSetting();

    int locId() const;
    void setLocId(int locId);
    bool defaultDockBool() const;
    void setDefaultDockBool(bool defaultDockBool);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    Loc locBylocId() const;
    LocDockSetting &operator=(const LocDockSetting &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static LocDockSetting create(int locId, bool defaultDockBool, const QString &createdBy, const QString &updatedBy);
    static LocDockSetting create(const QVariantMap &values);
    static LocDockSetting get(int locId);
    static int count();
    static QList<LocDockSetting> getAll();

private:
    QSharedDataPointer<LocDockSettingObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const LocDockSetting &model);
    friend QDataStream &operator>>(QDataStream &ds, LocDockSetting &model);
};

Q_DECLARE_METATYPE(LocDockSetting)
Q_DECLARE_METATYPE(QList<LocDockSetting>)

#endif // LOCDOCKSETTING_H
