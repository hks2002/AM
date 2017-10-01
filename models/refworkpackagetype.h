#ifndef REFWORKPACKAGETYPE_H
#define REFWORKPACKAGETYPE_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class RefWorkpackageTypeObject;


class T_MODEL_EXPORT RefWorkpackageType : public TAbstractModel
{
public:
    RefWorkpackageType();
    RefWorkpackageType(const RefWorkpackageType &other);
    RefWorkpackageType(const RefWorkpackageTypeObject &object);
    ~RefWorkpackageType();

    QString workpackageTypeCd() const;
    void setWorkpackageTypeCd(const QString &workpackageTypeCd);
    QString workpackageTypeNameEn() const;
    void setWorkpackageTypeNameEn(const QString &workpackageTypeNameEn);
    QString workpackageTypeNameZh() const;
    void setWorkpackageTypeNameZh(const QString &workpackageTypeNameZh);
    QString workpackageTypeDesc() const;
    void setWorkpackageTypeDesc(const QString &workpackageTypeDesc);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    RefWorkpackageType &operator=(const RefWorkpackageType &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static RefWorkpackageType create(const QString &workpackageTypeCd, const QString &workpackageTypeNameEn, const QString &workpackageTypeNameZh, const QString &workpackageTypeDesc, const QString &createdBy, const QString &updatedBy);
    static RefWorkpackageType create(const QVariantMap &values);
    static RefWorkpackageType get(const QString &workpackageTypeCd);
    static int count();
    static QList<RefWorkpackageType> getAll();

private:
    QSharedDataPointer<RefWorkpackageTypeObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const RefWorkpackageType &model);
    friend QDataStream &operator>>(QDataStream &ds, RefWorkpackageType &model);
};

Q_DECLARE_METATYPE(RefWorkpackageType)
Q_DECLARE_METATYPE(QList<RefWorkpackageType>)

#endif // REFWORKPACKAGETYPE_H
