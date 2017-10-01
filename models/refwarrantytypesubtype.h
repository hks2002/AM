#ifndef REFWARRANTYTYPESUBTYPE_H
#define REFWARRANTYTYPESUBTYPE_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class RefWarrantyTypeSubtypeObject;


class T_MODEL_EXPORT RefWarrantyTypeSubtype : public TAbstractModel
{
public:
    RefWarrantyTypeSubtype();
    RefWarrantyTypeSubtype(const RefWarrantyTypeSubtype &other);
    RefWarrantyTypeSubtype(const RefWarrantyTypeSubtypeObject &object);
    ~RefWarrantyTypeSubtype();

    QString warrantyTypeCd() const;
    void setWarrantyTypeCd(const QString &warrantyTypeCd);
    QString warrantySubtypeCd() const;
    void setWarrantySubtypeCd(const QString &warrantySubtypeCd);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    RefWarrantyTypeSubtype &operator=(const RefWarrantyTypeSubtype &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static RefWarrantyTypeSubtype create(const QString &warrantyTypeCd, const QString &warrantySubtypeCd, const QString &createdBy, const QString &updatedBy);
    static RefWarrantyTypeSubtype create(const QVariantMap &values);
    static RefWarrantyTypeSubtype get(const QString &warrantyTypeCd, const QString &warrantySubtypeCd);
    static int count();
    static QList<RefWarrantyTypeSubtype> getAll();

private:
    QSharedDataPointer<RefWarrantyTypeSubtypeObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const RefWarrantyTypeSubtype &model);
    friend QDataStream &operator>>(QDataStream &ds, RefWarrantyTypeSubtype &model);
};

Q_DECLARE_METATYPE(RefWarrantyTypeSubtype)
Q_DECLARE_METATYPE(QList<RefWarrantyTypeSubtype>)

#endif // REFWARRANTYTYPESUBTYPE_H
