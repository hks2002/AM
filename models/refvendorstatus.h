#ifndef REFVENDORSTATUS_H
#define REFVENDORSTATUS_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class RefVendorStatusObject;


class T_MODEL_EXPORT RefVendorStatus : public TAbstractModel
{
public:
    RefVendorStatus();
    RefVendorStatus(const RefVendorStatus &other);
    RefVendorStatus(const RefVendorStatusObject &object);
    ~RefVendorStatus();

    QString vendorStatusCd() const;
    void setVendorStatusCd(const QString &vendorStatusCd);
    QString vendorStatusNameEn() const;
    void setVendorStatusNameEn(const QString &vendorStatusNameEn);
    QString vendorStatusNameZh() const;
    void setVendorStatusNameZh(const QString &vendorStatusNameZh);
    QString vendorStatusDesc() const;
    void setVendorStatusDesc(const QString &vendorStatusDesc);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    RefVendorStatus &operator=(const RefVendorStatus &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static RefVendorStatus create(const QString &vendorStatusCd, const QString &vendorStatusNameEn, const QString &vendorStatusNameZh, const QString &vendorStatusDesc, const QString &createdBy, const QString &updatedBy);
    static RefVendorStatus create(const QVariantMap &values);
    static RefVendorStatus get(const QString &vendorStatusCd);
    static int count();
    static QList<RefVendorStatus> getAll();

private:
    QSharedDataPointer<RefVendorStatusObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const RefVendorStatus &model);
    friend QDataStream &operator>>(QDataStream &ds, RefVendorStatus &model);
};

Q_DECLARE_METATYPE(RefVendorStatus)
Q_DECLARE_METATYPE(QList<RefVendorStatus>)

#endif // REFVENDORSTATUS_H
