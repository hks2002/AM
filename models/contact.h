#ifndef CONTACT_H
#define CONTACT_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class ContactObject;


class T_MODEL_EXPORT Contact : public TAbstractModel
{
public:
    Contact();
    Contact(const Contact &other);
    Contact(const ContactObject &object);
    ~Contact();

    int contactId() const;
    QString addressEmail() const;
    void setAddressEmail(const QString &addressEmail);
    QString contactName() const;
    void setContactName(const QString &contactName);
    QString jobTitle() const;
    void setJobTitle(const QString &jobTitle);
    QString faxPh() const;
    void setFaxPh(const QString &faxPh);
    QString phonePh() const;
    void setPhonePh(const QString &phonePh);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    Contact &operator=(const Contact &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static Contact create(const QString &addressEmail, const QString &contactName, const QString &jobTitle, const QString &faxPh, const QString &phonePh, const QString &createdBy, const QString &updatedBy);
    static Contact create(const QVariantMap &values);
    static Contact get(int contactId);
    static int count();
    static QList<Contact> getAll();

private:
    QSharedDataPointer<ContactObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const Contact &model);
    friend QDataStream &operator>>(QDataStream &ds, Contact &model);
};

Q_DECLARE_METATYPE(Contact)
Q_DECLARE_METATYPE(QList<Contact>)

#endif // CONTACT_H
