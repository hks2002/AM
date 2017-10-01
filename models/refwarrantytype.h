#ifndef REFWARRANTYTYPE_H
#define REFWARRANTYTYPE_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class RefWarrantyTypeObject;


class T_MODEL_EXPORT RefWarrantyType : public TAbstractModel
{
public:
    RefWarrantyType();
    RefWarrantyType(const RefWarrantyType &other);
    RefWarrantyType(const RefWarrantyTypeObject &object);
    ~RefWarrantyType();

    QString warrantyTypeCd() const;
    void setWarrantyTypeCd(const QString &warrantyTypeCd);
    QString warrantyTypeNameEn() const;
    void setWarrantyTypeNameEn(const QString &warrantyTypeNameEn);
    QString warrantyTypeNameZh() const;
    void setWarrantyTypeNameZh(const QString &warrantyTypeNameZh);
    QString warrantyTypeDesc() const;
    void setWarrantyTypeDesc(const QString &warrantyTypeDesc);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    RefWarrantyType &operator=(const RefWarrantyType &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static RefWarrantyType create(const QString &warrantyTypeCd, const QString &warrantyTypeNameEn, const QString &warrantyTypeNameZh, const QString &warrantyTypeDesc, const QString &createdBy, const QString &updatedBy);
    static RefWarrantyType create(const QVariantMap &values);
    static RefWarrantyType get(const QString &warrantyTypeCd);
    static int count();
    static QList<RefWarrantyType> getAll();

private:
    QSharedDataPointer<RefWarrantyTypeObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const RefWarrantyType &model);
    friend QDataStream &operator>>(QDataStream &ds, RefWarrantyType &model);
};

Q_DECLARE_METATYPE(RefWarrantyType)
Q_DECLARE_METATYPE(QList<RefWarrantyType>)

#endif // REFWARRANTYTYPE_H
