#ifndef REFWARRANTYSUBTYPE_H
#define REFWARRANTYSUBTYPE_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class RefWarrantySubtypeObject;


class T_MODEL_EXPORT RefWarrantySubtype : public TAbstractModel
{
public:
    RefWarrantySubtype();
    RefWarrantySubtype(const RefWarrantySubtype &other);
    RefWarrantySubtype(const RefWarrantySubtypeObject &object);
    ~RefWarrantySubtype();

    QString warrantySubtypeCd() const;
    void setWarrantySubtypeCd(const QString &warrantySubtypeCd);
    QString warrantySubtypeNameEn() const;
    void setWarrantySubtypeNameEn(const QString &warrantySubtypeNameEn);
    QString warrantySubtypeNameZh() const;
    void setWarrantySubtypeNameZh(const QString &warrantySubtypeNameZh);
    QString warrantySubtypeDesc() const;
    void setWarrantySubtypeDesc(const QString &warrantySubtypeDesc);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    RefWarrantySubtype &operator=(const RefWarrantySubtype &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static RefWarrantySubtype create(const QString &warrantySubtypeCd, const QString &warrantySubtypeNameEn, const QString &warrantySubtypeNameZh, const QString &warrantySubtypeDesc, const QString &createdBy, const QString &updatedBy);
    static RefWarrantySubtype create(const QVariantMap &values);
    static RefWarrantySubtype get(const QString &warrantySubtypeCd);
    static int count();
    static QList<RefWarrantySubtype> getAll();

private:
    QSharedDataPointer<RefWarrantySubtypeObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const RefWarrantySubtype &model);
    friend QDataStream &operator>>(QDataStream &ds, RefWarrantySubtype &model);
};

Q_DECLARE_METATYPE(RefWarrantySubtype)
Q_DECLARE_METATYPE(QList<RefWarrantySubtype>)

#endif // REFWARRANTYSUBTYPE_H
