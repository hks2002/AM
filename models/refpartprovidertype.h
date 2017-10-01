#ifndef REFPARTPROVIDERTYPE_H
#define REFPARTPROVIDERTYPE_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class RefPartProviderTypeObject;


class T_MODEL_EXPORT RefPartProviderType : public TAbstractModel
{
public:
    RefPartProviderType();
    RefPartProviderType(const RefPartProviderType &other);
    RefPartProviderType(const RefPartProviderTypeObject &object);
    ~RefPartProviderType();

    QString partProviderTypeCd() const;
    void setPartProviderTypeCd(const QString &partProviderTypeCd);
    QString partProviderTypeNameEn() const;
    void setPartProviderTypeNameEn(const QString &partProviderTypeNameEn);
    QString partProviderTypeNameZh() const;
    void setPartProviderTypeNameZh(const QString &partProviderTypeNameZh);
    QString partProviderTypeDesc() const;
    void setPartProviderTypeDesc(const QString &partProviderTypeDesc);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    RefPartProviderType &operator=(const RefPartProviderType &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static RefPartProviderType create(const QString &partProviderTypeCd, const QString &partProviderTypeNameEn, const QString &partProviderTypeNameZh, const QString &partProviderTypeDesc, const QString &createdBy, const QString &updatedBy);
    static RefPartProviderType create(const QVariantMap &values);
    static RefPartProviderType get(const QString &partProviderTypeCd);
    static int count();
    static QList<RefPartProviderType> getAll();

private:
    QSharedDataPointer<RefPartProviderTypeObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const RefPartProviderType &model);
    friend QDataStream &operator>>(QDataStream &ds, RefPartProviderType &model);
};

Q_DECLARE_METATYPE(RefPartProviderType)
Q_DECLARE_METATYPE(QList<RefPartProviderType>)

#endif // REFPARTPROVIDERTYPE_H
