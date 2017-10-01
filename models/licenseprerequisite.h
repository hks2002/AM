#ifndef LICENSEPREREQUISITE_H
#define LICENSEPREREQUISITE_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class LicensePrerequisiteObject;
class LabourSkill;


class T_MODEL_EXPORT LicensePrerequisite : public TAbstractModel
{
public:
    LicensePrerequisite();
    LicensePrerequisite(const LicensePrerequisite &other);
    LicensePrerequisite(const LicensePrerequisiteObject &object);
    ~LicensePrerequisite();

    int licenseId() const;
    void setLicenseId(int licenseId);
    int labourSkillId() const;
    void setLabourSkillId(int labourSkillId);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    LabourSkill labourSkillBylabourSkillId() const;
    LicensePrerequisite &operator=(const LicensePrerequisite &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static LicensePrerequisite create(int licenseId, int labourSkillId, const QString &createdBy, const QString &updatedBy);
    static LicensePrerequisite create(const QVariantMap &values);
    static LicensePrerequisite get(int licenseId, int labourSkillId);
    static int count();
    static QList<LicensePrerequisite> getAll();

private:
    QSharedDataPointer<LicensePrerequisiteObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const LicensePrerequisite &model);
    friend QDataStream &operator>>(QDataStream &ds, LicensePrerequisite &model);
};

Q_DECLARE_METATYPE(LicensePrerequisite)
Q_DECLARE_METATYPE(QList<LicensePrerequisite>)

#endif // LICENSEPREREQUISITE_H
