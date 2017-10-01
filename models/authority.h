#ifndef AUTHORITY_H
#define AUTHORITY_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class AuthorityObject;


class T_MODEL_EXPORT Authority : public TAbstractModel
{
public:
    Authority();
    Authority(const Authority &other);
    Authority(const AuthorityObject &object);
    ~Authority();

    int authorityId() const;
    QString authorityCd() const;
    void setAuthorityCd(const QString &authorityCd);
    QString authorityName() const;
    void setAuthorityName(const QString &authorityName);
    QString authorityDesc() const;
    void setAuthorityDesc(const QString &authorityDesc);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    Authority &operator=(const Authority &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static Authority create(const QString &authorityCd, const QString &authorityName, const QString &authorityDesc, const QString &createdBy, const QString &updatedBy);
    static Authority create(const QVariantMap &values);
    static Authority get(int authorityId);
    static int count();
    static QList<Authority> getAll();

private:
    QSharedDataPointer<AuthorityObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const Authority &model);
    friend QDataStream &operator>>(QDataStream &ds, Authority &model);
};

Q_DECLARE_METATYPE(Authority)
Q_DECLARE_METATYPE(QList<Authority>)

#endif // AUTHORITY_H
