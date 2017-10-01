#ifndef EQPPARTNORELIAB_H
#define EQPPARTNORELIAB_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class EqpPartNoReliabObject;
class RefEngUnit;
class EqpPartNo;


class T_MODEL_EXPORT EqpPartNoReliab : public TAbstractModel
{
public:
    EqpPartNoReliab();
    EqpPartNoReliab(const EqpPartNoReliab &other);
    EqpPartNoReliab(const EqpPartNoReliabObject &object);
    ~EqpPartNoReliab();

    int partNoId() const;
    void setPartNoId(int partNoId);
    QString engUnitCd() const;
    void setEngUnitCd(const QString &engUnitCd);
    double mtbfQt() const;
    void setMtbfQt(double mtbfQt);
    double mtbrQt() const;
    void setMtbrQt(double mtbrQt);
    double mtburQt() const;
    void setMtburQt(double mtburQt);
    double mttrQt() const;
    void setMttrQt(double mttrQt);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    RefEngUnit refEngUnitByengUnitCd() const;
    EqpPartNo eqpPartNoBypartNoId() const;
    EqpPartNoReliab &operator=(const EqpPartNoReliab &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static EqpPartNoReliab create(int partNoId, const QString &engUnitCd, double mtbfQt, double mtbrQt, double mtburQt, double mttrQt, const QString &createdBy, const QString &updatedBy);
    static EqpPartNoReliab create(const QVariantMap &values);
    static EqpPartNoReliab get(int partNoId, const QString &engUnitCd);
    static int count();
    static QList<EqpPartNoReliab> getAll();

private:
    QSharedDataPointer<EqpPartNoReliabObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const EqpPartNoReliab &model);
    friend QDataStream &operator>>(QDataStream &ds, EqpPartNoReliab &model);
};

Q_DECLARE_METATYPE(EqpPartNoReliab)
Q_DECLARE_METATYPE(QList<EqpPartNoReliab>)

#endif // EQPPARTNORELIAB_H
