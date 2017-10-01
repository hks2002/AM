#ifndef REFLICENSESTATUS_H
#define REFLICENSESTATUS_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class RefLicenseStatusObject;


class T_MODEL_EXPORT RefLicenseStatus : public TAbstractModel
{
public:
    RefLicenseStatus();
    RefLicenseStatus(const RefLicenseStatus &other);
    RefLicenseStatus(const RefLicenseStatusObject &object);
    ~RefLicenseStatus();

    QString licenseStatusCd() const;
    void setLicenseStatusCd(const QString &licenseStatusCd);
    QString licenseStatusNameEn() const;
    void setLicenseStatusNameEn(const QString &licenseStatusNameEn);
    QString licenseStatusNameZh() const;
    void setLicenseStatusNameZh(const QString &licenseStatusNameZh);
    QString licenseStatusDesc() const;
    void setLicenseStatusDesc(const QString &licenseStatusDesc);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    RefLicenseStatus &operator=(const RefLicenseStatus &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static RefLicenseStatus create(const QString &licenseStatusCd, const QString &licenseStatusNameEn, const QString &licenseStatusNameZh, const QString &licenseStatusDesc, const QString &createdBy, const QString &updatedBy);
    static RefLicenseStatus create(const QVariantMap &values);
    static RefLicenseStatus get(const QString &licenseStatusCd);
    static int count();
    static QList<RefLicenseStatus> getAll();

private:
    QSharedDataPointer<RefLicenseStatusObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const RefLicenseStatus &model);
    friend QDataStream &operator>>(QDataStream &ds, RefLicenseStatus &model);
};

Q_DECLARE_METATYPE(RefLicenseStatus)
Q_DECLARE_METATYPE(QList<RefLicenseStatus>)

#endif // REFLICENSESTATUS_H
