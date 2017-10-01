#ifndef REFLOCTYPE_H
#define REFLOCTYPE_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class RefLocTypeObject;


class T_MODEL_EXPORT RefLocType : public TAbstractModel
{
public:
    RefLocType();
    RefLocType(const RefLocType &other);
    RefLocType(const RefLocTypeObject &object);
    ~RefLocType();

    QString locTypeCd() const;
    void setLocTypeCd(const QString &locTypeCd);
    QString locTypeNameEn() const;
    void setLocTypeNameEn(const QString &locTypeNameEn);
    QString locTypeNameZh() const;
    void setLocTypeNameZh(const QString &locTypeNameZh);
    QString locTypeDesc() const;
    void setLocTypeDesc(const QString &locTypeDesc);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    RefLocType &operator=(const RefLocType &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static RefLocType create(const QString &locTypeCd, const QString &locTypeNameEn, const QString &locTypeNameZh, const QString &locTypeDesc, const QString &createdBy, const QString &updatedBy);
    static RefLocType create(const QVariantMap &values);
    static RefLocType get(const QString &locTypeCd);
    static int count();
    static QList<RefLocType> getAll();

private:
    QSharedDataPointer<RefLocTypeObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const RefLocType &model);
    friend QDataStream &operator>>(QDataStream &ds, RefLocType &model);
};

Q_DECLARE_METATYPE(RefLocType)
Q_DECLARE_METATYPE(QList<RefLocType>)

#endif // REFLOCTYPE_H
