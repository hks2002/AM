#ifndef WARRANTYDEFNSUBTYPE_H
#define WARRANTYDEFNSUBTYPE_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class WarrantyDefnSubtypeObject;
class RefWarrantySubtype;
class WarrantyDefn;


class T_MODEL_EXPORT WarrantyDefnSubtype : public TAbstractModel
{
public:
    WarrantyDefnSubtype();
    WarrantyDefnSubtype(const WarrantyDefnSubtype &other);
    WarrantyDefnSubtype(const WarrantyDefnSubtypeObject &object);
    ~WarrantyDefnSubtype();

    int warrantyDefnId() const;
    void setWarrantyDefnId(int warrantyDefnId);
    QString warrantySubtypeCd() const;
    void setWarrantySubtypeCd(const QString &warrantySubtypeCd);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    RefWarrantySubtype refWarrantySubtypeBywarrantySubtypeCd() const;
    WarrantyDefn warrantyDefnBywarrantyDefnId() const;
    WarrantyDefnSubtype &operator=(const WarrantyDefnSubtype &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static WarrantyDefnSubtype create(int warrantyDefnId, const QString &warrantySubtypeCd, const QString &createdBy, const QString &updatedBy);
    static WarrantyDefnSubtype create(const QVariantMap &values);
    static WarrantyDefnSubtype get(int warrantyDefnId, const QString &warrantySubtypeCd);
    static int count();
    static QList<WarrantyDefnSubtype> getAll();

private:
    QSharedDataPointer<WarrantyDefnSubtypeObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const WarrantyDefnSubtype &model);
    friend QDataStream &operator>>(QDataStream &ds, WarrantyDefnSubtype &model);
};

Q_DECLARE_METATYPE(WarrantyDefnSubtype)
Q_DECLARE_METATYPE(QList<WarrantyDefnSubtype>)

#endif // WARRANTYDEFNSUBTYPE_H
