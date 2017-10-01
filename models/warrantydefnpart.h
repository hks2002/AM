#ifndef WARRANTYDEFNPART_H
#define WARRANTYDEFNPART_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class WarrantyDefnPartObject;
class EqpPartNo;
class WarrantyDefn;


class T_MODEL_EXPORT WarrantyDefnPart : public TAbstractModel
{
public:
    WarrantyDefnPart();
    WarrantyDefnPart(const WarrantyDefnPart &other);
    WarrantyDefnPart(const WarrantyDefnPartObject &object);
    ~WarrantyDefnPart();

    int warrantyDefnId() const;
    void setWarrantyDefnId(int warrantyDefnId);
    int partNoId() const;
    void setPartNoId(int partNoId);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    EqpPartNo eqpPartNoBypartNoId() const;
    WarrantyDefn warrantyDefnBywarrantyDefnId() const;
    WarrantyDefnPart &operator=(const WarrantyDefnPart &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static WarrantyDefnPart create(int warrantyDefnId, int partNoId, const QString &createdBy, const QString &updatedBy);
    static WarrantyDefnPart create(const QVariantMap &values);
    static WarrantyDefnPart get(int warrantyDefnId, int partNoId);
    static int count();
    static QList<WarrantyDefnPart> getAll();

private:
    QSharedDataPointer<WarrantyDefnPartObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const WarrantyDefnPart &model);
    friend QDataStream &operator>>(QDataStream &ds, WarrantyDefnPart &model);
};

Q_DECLARE_METATYPE(WarrantyDefnPart)
Q_DECLARE_METATYPE(QList<WarrantyDefnPart>)

#endif // WARRANTYDEFNPART_H
