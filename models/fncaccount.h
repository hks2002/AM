#ifndef FNCACCOUNT_H
#define FNCACCOUNT_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class FncAccountObject;
class FncTcode;
class RefAccountType;


class T_MODEL_EXPORT FncAccount : public TAbstractModel
{
public:
    FncAccount();
    FncAccount(const FncAccount &other);
    FncAccount(const FncAccountObject &object);
    ~FncAccount();

    int accountId() const;
    QString accountCd() const;
    void setAccountCd(const QString &accountCd);
    int nhAccountId() const;
    void setNhAccountId(int nhAccountId);
    QString accountTypeCd() const;
    void setAccountTypeCd(const QString &accountTypeCd);
    QString accountName() const;
    void setAccountName(const QString &accountName);
    QString accountDesc() const;
    void setAccountDesc(const QString &accountDesc);
    bool defaultBool() const;
    void setDefaultBool(bool defaultBool);
    bool closedBool() const;
    void setClosedBool(bool closedBool);
    int tcodeId() const;
    void setTcodeId(int tcodeId);
    QString extKey() const;
    void setExtKey(const QString &extKey);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    FncTcode fncTcodeBytcodeId() const;
    RefAccountType refAccountTypeByaccountTypeCd() const;
    FncAccount &operator=(const FncAccount &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static FncAccount create(const QString &accountCd, int nhAccountId, const QString &accountTypeCd, const QString &accountName, const QString &accountDesc, bool defaultBool, bool closedBool, int tcodeId, const QString &extKey, const QString &createdBy, const QString &updatedBy);
    static FncAccount create(const QVariantMap &values);
    static FncAccount get(int accountId);
    static int count();
    static QList<FncAccount> getAll();

private:
    QSharedDataPointer<FncAccountObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const FncAccount &model);
    friend QDataStream &operator>>(QDataStream &ds, FncAccount &model);
};

Q_DECLARE_METATYPE(FncAccount)
Q_DECLARE_METATYPE(QList<FncAccount>)

#endif // FNCACCOUNT_H
