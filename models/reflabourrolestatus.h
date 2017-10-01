#ifndef REFLABOURROLESTATUS_H
#define REFLABOURROLESTATUS_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class RefLabourRoleStatusObject;


class T_MODEL_EXPORT RefLabourRoleStatus : public TAbstractModel
{
public:
    RefLabourRoleStatus();
    RefLabourRoleStatus(const RefLabourRoleStatus &other);
    RefLabourRoleStatus(const RefLabourRoleStatusObject &object);
    ~RefLabourRoleStatus();

    QString labourRoleStatusCd() const;
    void setLabourRoleStatusCd(const QString &labourRoleStatusCd);
    QString labourRoleStatusNameEn() const;
    void setLabourRoleStatusNameEn(const QString &labourRoleStatusNameEn);
    QString labourRoleStatusNameZh() const;
    void setLabourRoleStatusNameZh(const QString &labourRoleStatusNameZh);
    QString labourRoleStatusDesc() const;
    void setLabourRoleStatusDesc(const QString &labourRoleStatusDesc);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    RefLabourRoleStatus &operator=(const RefLabourRoleStatus &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static RefLabourRoleStatus create(const QString &labourRoleStatusCd, const QString &labourRoleStatusNameEn, const QString &labourRoleStatusNameZh, const QString &labourRoleStatusDesc, const QString &createdBy, const QString &updatedBy);
    static RefLabourRoleStatus create(const QVariantMap &values);
    static RefLabourRoleStatus get(const QString &labourRoleStatusCd);
    static int count();
    static QList<RefLabourRoleStatus> getAll();

private:
    QSharedDataPointer<RefLabourRoleStatusObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const RefLabourRoleStatus &model);
    friend QDataStream &operator>>(QDataStream &ds, RefLabourRoleStatus &model);
};

Q_DECLARE_METATYPE(RefLabourRoleStatus)
Q_DECLARE_METATYPE(QList<RefLabourRoleStatus>)

#endif // REFLABOURROLESTATUS_H
