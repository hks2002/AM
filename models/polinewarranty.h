#ifndef POLINEWARRANTY_H
#define POLINEWARRANTY_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class PoLineWarrantyObject;
class WarrantyDefn;
class PoLine;


class T_MODEL_EXPORT PoLineWarranty : public TAbstractModel
{
public:
    PoLineWarranty();
    PoLineWarranty(const PoLineWarranty &other);
    PoLineWarranty(const PoLineWarrantyObject &object);
    ~PoLineWarranty();

    int poLineId() const;
    void setPoLineId(int poLineId);
    int warrantyDefnId() const;
    void setWarrantyDefnId(int warrantyDefnId);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    WarrantyDefn warrantyDefnBywarrantyDefnId() const;
    PoLine poLineBypoLineId() const;
    PoLineWarranty &operator=(const PoLineWarranty &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static PoLineWarranty create(int poLineId, int warrantyDefnId, const QString &createdBy, const QString &updatedBy);
    static PoLineWarranty create(const QVariantMap &values);
    static PoLineWarranty get(int poLineId);
    static int count();
    static QList<PoLineWarranty> getAll();

private:
    QSharedDataPointer<PoLineWarrantyObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const PoLineWarranty &model);
    friend QDataStream &operator>>(QDataStream &ds, PoLineWarranty &model);
};

Q_DECLARE_METATYPE(PoLineWarranty)
Q_DECLARE_METATYPE(QList<PoLineWarranty>)

#endif // POLINEWARRANTY_H
