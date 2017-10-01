#ifndef QTYUNIT_H
#define QTYUNIT_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class QtyUnitObject;


class T_MODEL_EXPORT QtyUnit : public TAbstractModel
{
public:
    QtyUnit();
    QtyUnit(const QtyUnit &other);
    QtyUnit(const QtyUnitObject &object);
    ~QtyUnit();

    int qtyUnitId() const;
    QString qtyUnitCd() const;
    void setQtyUnitCd(const QString &qtyUnitCd);
    QString qtyUnitNameZh() const;
    void setQtyUnitNameZh(const QString &qtyUnitNameZh);
    QString qtyUnitNameEn() const;
    void setQtyUnitNameEn(const QString &qtyUnitNameEn);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    QtyUnit &operator=(const QtyUnit &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static QtyUnit create(const QString &qtyUnitCd, const QString &qtyUnitNameZh, const QString &qtyUnitNameEn, const QString &createdBy, const QString &updatedBy);
    static QtyUnit create(const QVariantMap &values);
    static QtyUnit get(int qtyUnitId);
    static int count();
    static QList<QtyUnit> getAll();

private:
    QSharedDataPointer<QtyUnitObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const QtyUnit &model);
    friend QDataStream &operator>>(QDataStream &ds, QtyUnit &model);
};

Q_DECLARE_METATYPE(QtyUnit)
Q_DECLARE_METATYPE(QList<QtyUnit>)

#endif // QTYUNIT_H
