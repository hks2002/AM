#ifndef LOCCONTACT_H
#define LOCCONTACT_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class LocContactObject;
class Contact;
class Loc;


class T_MODEL_EXPORT LocContact : public TAbstractModel
{
public:
    LocContact();
    LocContact(const LocContact &other);
    LocContact(const LocContactObject &object);
    ~LocContact();

    int locId() const;
    void setLocId(int locId);
    int contactId() const;
    void setContactId(int contactId);
    bool defaultBool() const;
    void setDefaultBool(bool defaultBool);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    Contact contactBycontactId() const;
    Loc locBylocId() const;
    LocContact &operator=(const LocContact &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static LocContact create(int locId, int contactId, bool defaultBool, const QString &createdBy, const QString &updatedBy);
    static LocContact create(const QVariantMap &values);
    static LocContact get(int locId, int contactId);
    static int count();
    static QList<LocContact> getAll();

private:
    QSharedDataPointer<LocContactObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const LocContact &model);
    friend QDataStream &operator>>(QDataStream &ds, LocContact &model);
};

Q_DECLARE_METATYPE(LocContact)
Q_DECLARE_METATYPE(QList<LocContact>)

#endif // LOCCONTACT_H
