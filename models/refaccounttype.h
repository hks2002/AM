#ifndef REFACCOUNTTYPE_H
#define REFACCOUNTTYPE_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class RefAccountTypeObject;


class T_MODEL_EXPORT RefAccountType : public TAbstractModel
{
public:
    RefAccountType();
    RefAccountType(const RefAccountType &other);
    RefAccountType(const RefAccountTypeObject &object);
    ~RefAccountType();

    QString accountTypeCd() const;
    void setAccountTypeCd(const QString &accountTypeCd);
    QString accountTypeNameEn() const;
    void setAccountTypeNameEn(const QString &accountTypeNameEn);
    QString accountTypeNameZh() const;
    void setAccountTypeNameZh(const QString &accountTypeNameZh);
    QString accountTypeDesc() const;
    void setAccountTypeDesc(const QString &accountTypeDesc);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    RefAccountType &operator=(const RefAccountType &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static RefAccountType create(const QString &accountTypeCd, const QString &accountTypeNameEn, const QString &accountTypeNameZh, const QString &accountTypeDesc, const QString &createdBy, const QString &updatedBy);
    static RefAccountType create(const QVariantMap &values);
    static RefAccountType get(const QString &accountTypeCd);
    static int count();
    static QList<RefAccountType> getAll();

private:
    QSharedDataPointer<RefAccountTypeObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const RefAccountType &model);
    friend QDataStream &operator>>(QDataStream &ds, RefAccountType &model);
};

Q_DECLARE_METATYPE(RefAccountType)
Q_DECLARE_METATYPE(QList<RefAccountType>)

#endif // REFACCOUNTTYPE_H
