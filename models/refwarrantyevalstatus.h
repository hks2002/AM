#ifndef REFWARRANTYEVALSTATUS_H
#define REFWARRANTYEVALSTATUS_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class RefWarrantyEvalStatusObject;


class T_MODEL_EXPORT RefWarrantyEvalStatus : public TAbstractModel
{
public:
    RefWarrantyEvalStatus();
    RefWarrantyEvalStatus(const RefWarrantyEvalStatus &other);
    RefWarrantyEvalStatus(const RefWarrantyEvalStatusObject &object);
    ~RefWarrantyEvalStatus();

    QString warrantyEvalStatusCd() const;
    void setWarrantyEvalStatusCd(const QString &warrantyEvalStatusCd);
    QString warrantyEvalStatusNameEn() const;
    void setWarrantyEvalStatusNameEn(const QString &warrantyEvalStatusNameEn);
    QString warrantyEvalStatusNameZh() const;
    void setWarrantyEvalStatusNameZh(const QString &warrantyEvalStatusNameZh);
    QString warrantyEvalStatusDesc() const;
    void setWarrantyEvalStatusDesc(const QString &warrantyEvalStatusDesc);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    RefWarrantyEvalStatus &operator=(const RefWarrantyEvalStatus &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static RefWarrantyEvalStatus create(const QString &warrantyEvalStatusCd, const QString &warrantyEvalStatusNameEn, const QString &warrantyEvalStatusNameZh, const QString &warrantyEvalStatusDesc, const QString &createdBy, const QString &updatedBy);
    static RefWarrantyEvalStatus create(const QVariantMap &values);
    static RefWarrantyEvalStatus get(const QString &warrantyEvalStatusCd);
    static int count();
    static QList<RefWarrantyEvalStatus> getAll();

private:
    QSharedDataPointer<RefWarrantyEvalStatusObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const RefWarrantyEvalStatus &model);
    friend QDataStream &operator>>(QDataStream &ds, RefWarrantyEvalStatus &model);
};

Q_DECLARE_METATYPE(RefWarrantyEvalStatus)
Q_DECLARE_METATYPE(QList<RefWarrantyEvalStatus>)

#endif // REFWARRANTYEVALSTATUS_H
