#ifndef POLINETAX_H
#define POLINETAX_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class PoLineTaxObject;
class Tax;
class PoLine;


class T_MODEL_EXPORT PoLineTax : public TAbstractModel
{
public:
    PoLineTax();
    PoLineTax(const PoLineTax &other);
    PoLineTax(const PoLineTaxObject &object);
    ~PoLineTax();

    int poLineId() const;
    void setPoLineId(int poLineId);
    int taxId() const;
    void setTaxId(int taxId);
    double taxAmount() const;
    void setTaxAmount(double taxAmount);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    Tax taxBytaxId() const;
    PoLine poLineBypoLineId() const;
    PoLineTax &operator=(const PoLineTax &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static PoLineTax create(int poLineId, int taxId, double taxAmount, const QString &createdBy, const QString &updatedBy);
    static PoLineTax create(const QVariantMap &values);
    static PoLineTax get(int poLineId);
    static int count();
    static QList<PoLineTax> getAll();

private:
    QSharedDataPointer<PoLineTaxObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const PoLineTax &model);
    friend QDataStream &operator>>(QDataStream &ds, PoLineTax &model);
};

Q_DECLARE_METATYPE(PoLineTax)
Q_DECLARE_METATYPE(QList<PoLineTax>)

#endif // POLINETAX_H
