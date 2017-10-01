#ifndef REFOWNERTYPE_H
#define REFOWNERTYPE_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class RefOwnerTypeObject;


class T_MODEL_EXPORT RefOwnerType : public TAbstractModel
{
public:
    RefOwnerType();
    RefOwnerType(const RefOwnerType &other);
    RefOwnerType(const RefOwnerTypeObject &object);
    ~RefOwnerType();

    QString ownerTypeCd() const;
    void setOwnerTypeCd(const QString &ownerTypeCd);
    QString ownerTypeNameEn() const;
    void setOwnerTypeNameEn(const QString &ownerTypeNameEn);
    QString ownerTypeNameZh() const;
    void setOwnerTypeNameZh(const QString &ownerTypeNameZh);
    QString ownerTypeDesc() const;
    void setOwnerTypeDesc(const QString &ownerTypeDesc);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    RefOwnerType &operator=(const RefOwnerType &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static RefOwnerType create(const QString &ownerTypeCd, const QString &ownerTypeNameEn, const QString &ownerTypeNameZh, const QString &ownerTypeDesc, const QString &createdBy, const QString &updatedBy);
    static RefOwnerType create(const QVariantMap &values);
    static RefOwnerType get(const QString &ownerTypeCd);
    static int count();
    static QList<RefOwnerType> getAll();

private:
    QSharedDataPointer<RefOwnerTypeObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const RefOwnerType &model);
    friend QDataStream &operator>>(QDataStream &ds, RefOwnerType &model);
};

Q_DECLARE_METATYPE(RefOwnerType)
Q_DECLARE_METATYPE(QList<RefOwnerType>)

#endif // REFOWNERTYPE_H
