#ifndef POINVOICELINEMAP_H
#define POINVOICELINEMAP_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class PoInvoiceLineMapObject;
class PoInvoiceLine;
class PoInvoice;
class PoLine;
class PoHeader;


class T_MODEL_EXPORT PoInvoiceLineMap : public TAbstractModel
{
public:
    PoInvoiceLineMap();
    PoInvoiceLineMap(const PoInvoiceLineMap &other);
    PoInvoiceLineMap(const PoInvoiceLineMapObject &object);
    ~PoInvoiceLineMap();

    int poId() const;
    void setPoId(int poId);
    int poLineId() const;
    void setPoLineId(int poLineId);
    int poInvoiceId() const;
    void setPoInvoiceId(int poInvoiceId);
    int poInvoiceLineId() const;
    void setPoInvoiceLineId(int poInvoiceLineId);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    PoInvoiceLine poInvoiceLineBypoInvoiceLineId() const;
    PoInvoice poInvoiceBypoInvoiceId() const;
    PoLine poLineBypoLineId() const;
    PoHeader poHeaderBypoId() const;
    PoInvoiceLineMap &operator=(const PoInvoiceLineMap &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static PoInvoiceLineMap create(int poId, int poLineId, int poInvoiceId, int poInvoiceLineId, const QString &createdBy, const QString &updatedBy);
    static PoInvoiceLineMap create(const QVariantMap &values);
    static PoInvoiceLineMap get(int poId, int poLineId, int poInvoiceId, int poInvoiceLineId);
    static int count();
    static QList<PoInvoiceLineMap> getAll();

private:
    QSharedDataPointer<PoInvoiceLineMapObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const PoInvoiceLineMap &model);
    friend QDataStream &operator>>(QDataStream &ds, PoInvoiceLineMap &model);
};

Q_DECLARE_METATYPE(PoInvoiceLineMap)
Q_DECLARE_METATYPE(QList<PoInvoiceLineMap>)

#endif // POINVOICELINEMAP_H
