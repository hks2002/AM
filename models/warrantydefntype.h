#ifndef WARRANTYDEFNTYPE_H
#define WARRANTYDEFNTYPE_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class WarrantyDefnTypeObject;
class RefWarrantyType;
class WarrantyDefn;


class T_MODEL_EXPORT WarrantyDefnType : public TAbstractModel
{
public:
    WarrantyDefnType();
    WarrantyDefnType(const WarrantyDefnType &other);
    WarrantyDefnType(const WarrantyDefnTypeObject &object);
    ~WarrantyDefnType();

    int warrantyDefnId() const;
    void setWarrantyDefnId(int warrantyDefnId);
    QString warrantyTypeCd() const;
    void setWarrantyTypeCd(const QString &warrantyTypeCd);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    RefWarrantyType refWarrantyTypeBywarrantyTypeCd() const;
    WarrantyDefn warrantyDefnBywarrantyDefnId() const;
    WarrantyDefnType &operator=(const WarrantyDefnType &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static WarrantyDefnType create(int warrantyDefnId, const QString &warrantyTypeCd, const QString &createdBy, const QString &updatedBy);
    static WarrantyDefnType create(const QVariantMap &values);
    static WarrantyDefnType get(int warrantyDefnId, const QString &warrantyTypeCd);
    static int count();
    static QList<WarrantyDefnType> getAll();

private:
    QSharedDataPointer<WarrantyDefnTypeObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const WarrantyDefnType &model);
    friend QDataStream &operator>>(QDataStream &ds, WarrantyDefnType &model);
};

Q_DECLARE_METATYPE(WarrantyDefnType)
Q_DECLARE_METATYPE(QList<WarrantyDefnType>)

#endif // WARRANTYDEFNTYPE_H
