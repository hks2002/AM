#ifndef LICENSE_H
#define LICENSE_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class LicenseObject;
class RefLicenseStatus;


class T_MODEL_EXPORT License : public TAbstractModel
{
public:
    License();
    License(const License &other);
    License(const LicenseObject &object);
    ~License();

    int licenseId() const;
    QString licenseCd() const;
    void setLicenseCd(const QString &licenseCd);
    QString licenseName() const;
    void setLicenseName(const QString &licenseName);
    QString licenseDesc() const;
    void setLicenseDesc(const QString &licenseDesc);
    QString licenseStatusCd() const;
    void setLicenseStatusCd(const QString &licenseStatusCd);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    RefLicenseStatus refLicenseStatusBylicenseStatusCd() const;
    License &operator=(const License &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static License create(const QString &licenseCd, const QString &licenseName, const QString &licenseDesc, const QString &licenseStatusCd, const QString &createdBy, const QString &updatedBy);
    static License create(const QVariantMap &values);
    static License get(int licenseId);
    static int count();
    static QList<License> getAll();

private:
    QSharedDataPointer<LicenseObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const License &model);
    friend QDataStream &operator>>(QDataStream &ds, License &model);
};

Q_DECLARE_METATYPE(License)
Q_DECLARE_METATYPE(QList<License>)

#endif // LICENSE_H
