#ifndef WARRANTYINITINV_H
#define WARRANTYINITINV_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class WarrantyInitInvObject;
class InvInv;
class WarrantyInit;


class T_MODEL_EXPORT WarrantyInitInv : public TAbstractModel
{
public:
    WarrantyInitInv();
    WarrantyInitInv(const WarrantyInitInv &other);
    WarrantyInitInv(const WarrantyInitInvObject &object);
    ~WarrantyInitInv();

    int warrantyInitId() const;
    void setWarrantyInitId(int warrantyInitId);
    int invNoId() const;
    void setInvNoId(int invNoId);
    bool mainBool() const;
    void setMainBool(bool mainBool);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    InvInv invInvByinvNoId() const;
    WarrantyInit warrantyInitBywarrantyInitId() const;
    WarrantyInitInv &operator=(const WarrantyInitInv &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static WarrantyInitInv create(int warrantyInitId, int invNoId, bool mainBool, const QString &createdBy, const QString &updatedBy);
    static WarrantyInitInv create(const QVariantMap &values);
    static WarrantyInitInv get(int warrantyInitId, int invNoId);
    static int count();
    static QList<WarrantyInitInv> getAll();

private:
    QSharedDataPointer<WarrantyInitInvObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const WarrantyInitInv &model);
    friend QDataStream &operator>>(QDataStream &ds, WarrantyInitInv &model);
};

Q_DECLARE_METATYPE(WarrantyInitInv)
Q_DECLARE_METATYPE(QList<WarrantyInitInv>)

#endif // WARRANTYINITINV_H
