#ifndef POLINEKITLINE_H
#define POLINEKITLINE_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class PoLineKitLineObject;
class EqpKitPartNo;
class PoLine;


class T_MODEL_EXPORT PoLineKitLine : public TAbstractModel
{
public:
    PoLineKitLine();
    PoLineKitLine(const PoLineKitLine &other);
    PoLineKitLine(const PoLineKitLineObject &object);
    ~PoLineKitLine();

    int poLineId() const;
    void setPoLineId(int poLineId);
    int kitPartNoId() const;
    void setKitPartNoId(int kitPartNoId);
    int partNoId() const;
    void setPartNoId(int partNoId);
    int kitQt() const;
    void setKitQt(int kitQt);
    double valuePct() const;
    void setValuePct(double valuePct);
    double unitPrice() const;
    void setUnitPrice(double unitPrice);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    EqpKitPartNo eqpKitPartNoBykitPartNoIdpartNoId() const;
    PoLine poLineBypoLineId() const;
    PoLineKitLine &operator=(const PoLineKitLine &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static PoLineKitLine create(int poLineId, int kitPartNoId, int partNoId, int kitQt, double valuePct, double unitPrice, const QString &createdBy, const QString &updatedBy);
    static PoLineKitLine create(const QVariantMap &values);
    static PoLineKitLine get(int poLineId, int kitPartNoId, int partNoId);
    static int count();
    static QList<PoLineKitLine> getAll();

private:
    QSharedDataPointer<PoLineKitLineObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const PoLineKitLine &model);
    friend QDataStream &operator>>(QDataStream &ds, PoLineKitLine &model);
};

Q_DECLARE_METATYPE(PoLineKitLine)
Q_DECLARE_METATYPE(QList<PoLineKitLine>)

#endif // POLINEKITLINE_H
