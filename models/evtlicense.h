#ifndef EVTLICENSE_H
#define EVTLICENSE_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class EvtLicenseObject;
class License;
class EvtEvent;


class T_MODEL_EXPORT EvtLicense : public TAbstractModel
{
public:
    EvtLicense();
    EvtLicense(const EvtLicense &other);
    EvtLicense(const EvtLicenseObject &object);
    ~EvtLicense();

    int eventId() const;
    void setEventId(int eventId);
    int licenseId() const;
    void setLicenseId(int licenseId);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    License licenseBylicenseId() const;
    EvtEvent evtEventByeventId() const;
    EvtLicense &operator=(const EvtLicense &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static EvtLicense create(int eventId, int licenseId, const QString &createdBy, const QString &updatedBy);
    static EvtLicense create(const QVariantMap &values);
    static EvtLicense get(int eventId, int licenseId);
    static int count();
    static QList<EvtLicense> getAll();

private:
    QSharedDataPointer<EvtLicenseObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const EvtLicense &model);
    friend QDataStream &operator>>(QDataStream &ds, EvtLicense &model);
};

Q_DECLARE_METATYPE(EvtLicense)
Q_DECLARE_METATYPE(QList<EvtLicense>)

#endif // EVTLICENSE_H
