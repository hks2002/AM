#ifndef REFWARRANTYSTATUS_H
#define REFWARRANTYSTATUS_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class RefWarrantyStatusObject;


class T_MODEL_EXPORT RefWarrantyStatus : public TAbstractModel
{
public:
    RefWarrantyStatus();
    RefWarrantyStatus(const RefWarrantyStatus &other);
    RefWarrantyStatus(const RefWarrantyStatusObject &object);
    ~RefWarrantyStatus();

    QString warrantyStatusCd() const;
    void setWarrantyStatusCd(const QString &warrantyStatusCd);
    QString warrantyStatusNameEn() const;
    void setWarrantyStatusNameEn(const QString &warrantyStatusNameEn);
    QString warrantyStatusNameZh() const;
    void setWarrantyStatusNameZh(const QString &warrantyStatusNameZh);
    QString warrantyStatusDesc() const;
    void setWarrantyStatusDesc(const QString &warrantyStatusDesc);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    RefWarrantyStatus &operator=(const RefWarrantyStatus &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static RefWarrantyStatus create(const QString &warrantyStatusCd, const QString &warrantyStatusNameEn, const QString &warrantyStatusNameZh, const QString &warrantyStatusDesc, const QString &createdBy, const QString &updatedBy);
    static RefWarrantyStatus create(const QVariantMap &values);
    static RefWarrantyStatus get(const QString &warrantyStatusCd);
    static int count();
    static QList<RefWarrantyStatus> getAll();

private:
    QSharedDataPointer<RefWarrantyStatusObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const RefWarrantyStatus &model);
    friend QDataStream &operator>>(QDataStream &ds, RefWarrantyStatus &model);
};

Q_DECLARE_METATYPE(RefWarrantyStatus)
Q_DECLARE_METATYPE(QList<RefWarrantyStatus>)

#endif // REFWARRANTYSTATUS_H
