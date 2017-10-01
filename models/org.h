#ifndef ORG_H
#define ORG_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class OrgObject;


class T_MODEL_EXPORT Org : public TAbstractModel
{
public:
    Org();
    Org(const Org &other);
    Org(const OrgObject &object);
    ~Org();

    int orgId() const;
    QString orgCd() const;
    void setOrgCd(const QString &orgCd);
    QString orgNameZh() const;
    void setOrgNameZh(const QString &orgNameZh);
    QString orgNameEn() const;
    void setOrgNameEn(const QString &orgNameEn);
    QString logo() const;
    void setLogo(const QString &logo);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    Org &operator=(const Org &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static Org create(const QString &orgCd, const QString &orgNameZh, const QString &orgNameEn, const QString &logo, const QString &createdBy, const QString &updatedBy);
    static Org create(const QVariantMap &values);
    static Org get(int orgId);
    static int count();
    static QList<Org> getAll();

private:
    QSharedDataPointer<OrgObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const Org &model);
    friend QDataStream &operator>>(QDataStream &ds, Org &model);
};

Q_DECLARE_METATYPE(Org)
Q_DECLARE_METATYPE(QList<Org>)

#endif // ORG_H
