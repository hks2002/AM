#ifndef EQPPARTNO_H
#define EQPPARTNO_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class EqpPartNoObject;
class RefPartType;
class RefPartUse;
class QtyUnit;
class FncAccount;
class RefInvClass;
class RefPartStatus;
class Manufact;


class T_MODEL_EXPORT EqpPartNo : public TAbstractModel
{
public:
    EqpPartNo();
    EqpPartNo(const EqpPartNo &other);
    EqpPartNo(const EqpPartNoObject &object);
    ~EqpPartNo();

    int partNoId() const;
    int manufactId() const;
    void setManufactId(int manufactId);
    QString partNoOem() const;
    void setPartNoOem(const QString &partNoOem);
    QString partNoName() const;
    void setPartNoName(const QString &partNoName);
    QString modelName() const;
    void setModelName(const QString &modelName);
    QString partNoDesc() const;
    void setPartNoDesc(const QString &partNoDesc);
    QString partStatusCd() const;
    void setPartStatusCd(const QString &partStatusCd);
    QString invClassCd() const;
    void setInvClassCd(const QString &invClassCd);
    int accountId() const;
    void setAccountId(int accountId);
    bool pmaBool() const;
    void setPmaBool(bool pmaBool);
    QString picture() const;
    void setPicture(const QString &picture);
    int qtyUnitId() const;
    void setQtyUnitId(int qtyUnitId);
    QString partUseCd() const;
    void setPartUseCd(const QString &partUseCd);
    QString partTypeCd() const;
    void setPartTypeCd(const QString &partTypeCd);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    RefPartType refPartTypeBypartTypeCd() const;
    RefPartUse refPartUseBypartUseCd() const;
    QtyUnit qtyUnitByqtyUnitId() const;
    FncAccount fncAccountByaccountId() const;
    RefInvClass refInvClassByinvClassCd() const;
    RefPartStatus refPartStatusBypartStatusCd() const;
    Manufact manufactBymanufactId() const;
    EqpPartNo &operator=(const EqpPartNo &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static EqpPartNo create(int manufactId, const QString &partNoOem, const QString &partNoName, const QString &modelName, const QString &partNoDesc, const QString &partStatusCd, const QString &invClassCd, int accountId, bool pmaBool, const QString &picture, int qtyUnitId, const QString &partUseCd, const QString &partTypeCd, const QString &createdBy, const QString &updatedBy);
    static EqpPartNo create(const QVariantMap &values);
    static EqpPartNo get(int partNoId);
    static int count();
    static QList<EqpPartNo> getAll();

private:
    QSharedDataPointer<EqpPartNoObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const EqpPartNo &model);
    friend QDataStream &operator>>(QDataStream &ds, EqpPartNo &model);
};

Q_DECLARE_METATYPE(EqpPartNo)
Q_DECLARE_METATYPE(QList<EqpPartNo>)

#endif // EQPPARTNO_H
