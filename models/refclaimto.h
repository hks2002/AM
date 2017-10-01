#ifndef REFCLAIMTO_H
#define REFCLAIMTO_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class RefClaimToObject;


class T_MODEL_EXPORT RefClaimTo : public TAbstractModel
{
public:
    RefClaimTo();
    RefClaimTo(const RefClaimTo &other);
    RefClaimTo(const RefClaimToObject &object);
    ~RefClaimTo();

    QString claimToCd() const;
    void setClaimToCd(const QString &claimToCd);
    QString claimToNameEn() const;
    void setClaimToNameEn(const QString &claimToNameEn);
    QString claimToNameZh() const;
    void setClaimToNameZh(const QString &claimToNameZh);
    QString claimToDesc() const;
    void setClaimToDesc(const QString &claimToDesc);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    RefClaimTo &operator=(const RefClaimTo &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static RefClaimTo create(const QString &claimToCd, const QString &claimToNameEn, const QString &claimToNameZh, const QString &claimToDesc, const QString &createdBy, const QString &updatedBy);
    static RefClaimTo create(const QVariantMap &values);
    static RefClaimTo get(const QString &claimToCd);
    static int count();
    static QList<RefClaimTo> getAll();

private:
    QSharedDataPointer<RefClaimToObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const RefClaimTo &model);
    friend QDataStream &operator>>(QDataStream &ds, RefClaimTo &model);
};

Q_DECLARE_METATYPE(RefClaimTo)
Q_DECLARE_METATYPE(QList<RefClaimTo>)

#endif // REFCLAIMTO_H
