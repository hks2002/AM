#ifndef INVACREG_H
#define INVACREG_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class InvAcRegObject;
class FcModel;
class Country;
class RegBody;
class Org;
class InvInv;


class T_MODEL_EXPORT InvAcReg : public TAbstractModel
{
public:
    InvAcReg();
    InvAcReg(const InvAcReg &other);
    InvAcReg(const InvAcRegObject &object);
    ~InvAcReg();

    int invNoId() const;
    void setInvNoId(int invNoId);
    int orgId() const;
    void setOrgId(int orgId);
    int regBodyId() const;
    void setRegBodyId(int regBodyId);
    int countryId() const;
    void setCountryId(int countryId);
    int fcModelId() const;
    void setFcModelId(int fcModelId);
    QString acRegCd() const;
    void setAcRegCd(const QString &acRegCd);
    QString airworthCd() const;
    void setAirworthCd(const QString &airworthCd);
    bool privateBool() const;
    void setPrivateBool(bool privateBool);
    QString varNoOem() const;
    void setVarNoOem(const QString &varNoOem);
    QString lineNoOem() const;
    void setLineNoOem(const QString &lineNoOem);
    QString finNoCd() const;
    void setFinNoCd(const QString &finNoCd);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    FcModel fcModelByfcModelId() const;
    Country countryBycountryId() const;
    RegBody regBodyByregBodyId() const;
    Org orgByorgId() const;
    InvInv invInvByinvNoId() const;
    InvAcReg &operator=(const InvAcReg &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static InvAcReg create(int invNoId, int orgId, int regBodyId, int countryId, int fcModelId, const QString &acRegCd, const QString &airworthCd, bool privateBool, const QString &varNoOem, const QString &lineNoOem, const QString &finNoCd, const QString &createdBy, const QString &updatedBy);
    static InvAcReg create(const QVariantMap &values);
    static InvAcReg get(int invNoId);
    static int count();
    static QList<InvAcReg> getAll();

private:
    QSharedDataPointer<InvAcRegObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const InvAcReg &model);
    friend QDataStream &operator>>(QDataStream &ds, InvAcReg &model);
};

Q_DECLARE_METATYPE(InvAcReg)
Q_DECLARE_METATYPE(QList<InvAcReg>)

#endif // INVACREG_H
