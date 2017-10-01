#ifndef WARRANTYDEFNASSMBL_H
#define WARRANTYDEFNASSMBL_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class WarrantyDefnAssmblObject;
class EqpAssmbl;
class WarrantyDefn;


class T_MODEL_EXPORT WarrantyDefnAssmbl : public TAbstractModel
{
public:
    WarrantyDefnAssmbl();
    WarrantyDefnAssmbl(const WarrantyDefnAssmbl &other);
    WarrantyDefnAssmbl(const WarrantyDefnAssmblObject &object);
    ~WarrantyDefnAssmbl();

    int warrantyDefnId() const;
    void setWarrantyDefnId(int warrantyDefnId);
    int assmblId() const;
    void setAssmblId(int assmblId);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    EqpAssmbl eqpAssmblByassmblId() const;
    WarrantyDefn warrantyDefnBywarrantyDefnId() const;
    WarrantyDefnAssmbl &operator=(const WarrantyDefnAssmbl &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static WarrantyDefnAssmbl create(int warrantyDefnId, int assmblId, const QString &createdBy, const QString &updatedBy);
    static WarrantyDefnAssmbl create(const QVariantMap &values);
    static WarrantyDefnAssmbl get(int warrantyDefnId, int assmblId);
    static int count();
    static QList<WarrantyDefnAssmbl> getAll();

private:
    QSharedDataPointer<WarrantyDefnAssmblObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const WarrantyDefnAssmbl &model);
    friend QDataStream &operator>>(QDataStream &ds, WarrantyDefnAssmbl &model);
};

Q_DECLARE_METATYPE(WarrantyDefnAssmbl)
Q_DECLARE_METATYPE(QList<WarrantyDefnAssmbl>)

#endif // WARRANTYDEFNASSMBL_H
