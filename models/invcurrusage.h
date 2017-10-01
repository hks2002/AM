#ifndef INVCURRUSAGE_H
#define INVCURRUSAGE_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class InvCurrUsageObject;
class RefEngUnit;
class InvInv;


class T_MODEL_EXPORT InvCurrUsage : public TAbstractModel
{
public:
    InvCurrUsage();
    InvCurrUsage(const InvCurrUsage &other);
    InvCurrUsage(const InvCurrUsageObject &object);
    ~InvCurrUsage();

    int invNoId() const;
    void setInvNoId(int invNoId);
    QString engUnitCd() const;
    void setEngUnitCd(const QString &engUnitCd);
    double tsiQt() const;
    void setTsiQt(double tsiQt);
    double tsnQt() const;
    void setTsnQt(double tsnQt);
    double tsoQt() const;
    void setTsoQt(double tsoQt);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    RefEngUnit refEngUnitByengUnitCd() const;
    InvInv invInvByinvNoId() const;
    InvCurrUsage &operator=(const InvCurrUsage &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static InvCurrUsage create(int invNoId, const QString &engUnitCd, double tsiQt, double tsnQt, double tsoQt, const QString &createdBy, const QString &updatedBy);
    static InvCurrUsage create(const QVariantMap &values);
    static InvCurrUsage get(int invNoId, const QString &engUnitCd);
    static int count();
    static QList<InvCurrUsage> getAll();

private:
    QSharedDataPointer<InvCurrUsageObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const InvCurrUsage &model);
    friend QDataStream &operator>>(QDataStream &ds, InvCurrUsage &model);
};

Q_DECLARE_METATYPE(InvCurrUsage)
Q_DECLARE_METATYPE(QList<InvCurrUsage>)

#endif // INVCURRUSAGE_H
