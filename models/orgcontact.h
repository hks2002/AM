#ifndef ORGCONTACT_H
#define ORGCONTACT_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class OrgContactObject;
class Contact;
class Org;


class T_MODEL_EXPORT OrgContact : public TAbstractModel
{
public:
    OrgContact();
    OrgContact(const OrgContact &other);
    OrgContact(const OrgContactObject &object);
    ~OrgContact();

    int orgId() const;
    void setOrgId(int orgId);
    int contactId() const;
    void setContactId(int contactId);
    bool mainBool() const;
    void setMainBool(bool mainBool);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    Contact contactBycontactId() const;
    Org orgByorgId() const;
    OrgContact &operator=(const OrgContact &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static OrgContact create(int orgId, int contactId, bool mainBool, const QString &createdBy, const QString &updatedBy);
    static OrgContact create(const QVariantMap &values);
    static OrgContact get(int orgId, int contactId);
    static int count();
    static QList<OrgContact> getAll();

private:
    QSharedDataPointer<OrgContactObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const OrgContact &model);
    friend QDataStream &operator>>(QDataStream &ds, OrgContact &model);
};

Q_DECLARE_METATYPE(OrgContact)
Q_DECLARE_METATYPE(QList<OrgContact>)

#endif // ORGCONTACT_H
