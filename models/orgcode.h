#ifndef ORGCODE_H
#define ORGCODE_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class OrgCodeObject;
class Org;


class T_MODEL_EXPORT OrgCode : public TAbstractModel
{
public:
    OrgCode();
    OrgCode(const OrgCode &other);
    OrgCode(const OrgCodeObject &object);
    ~OrgCode();

    int orgId() const;
    void setOrgId(int orgId);
    QString icaoCd() const;
    void setIcaoCd(const QString &icaoCd);
    QString iataCd() const;
    void setIataCd(const QString &iataCd);
    QString callsignCd() const;
    void setCallsignCd(const QString &callsignCd);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    Org orgByorgId() const;
    OrgCode &operator=(const OrgCode &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static OrgCode create(int orgId, const QString &icaoCd, const QString &iataCd, const QString &callsignCd, const QString &createdBy, const QString &updatedBy);
    static OrgCode create(const QVariantMap &values);
    static OrgCode get(int orgId);
    static int count();
    static QList<OrgCode> getAll();

private:
    QSharedDataPointer<OrgCodeObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const OrgCode &model);
    friend QDataStream &operator>>(QDataStream &ds, OrgCode &model);
};

Q_DECLARE_METATYPE(OrgCode)
Q_DECLARE_METATYPE(QList<OrgCode>)

#endif // ORGCODE_H
