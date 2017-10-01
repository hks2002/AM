#ifndef REFWARRANTYPRIORITY_H
#define REFWARRANTYPRIORITY_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class RefWarrantyPriorityObject;


class T_MODEL_EXPORT RefWarrantyPriority : public TAbstractModel
{
public:
    RefWarrantyPriority();
    RefWarrantyPriority(const RefWarrantyPriority &other);
    RefWarrantyPriority(const RefWarrantyPriorityObject &object);
    ~RefWarrantyPriority();

    QString warrantyPriorityCd() const;
    void setWarrantyPriorityCd(const QString &warrantyPriorityCd);
    QString warrantyPriorityNameEn() const;
    void setWarrantyPriorityNameEn(const QString &warrantyPriorityNameEn);
    QString warrantyPriorityNameZh() const;
    void setWarrantyPriorityNameZh(const QString &warrantyPriorityNameZh);
    QString warrantyPriorityDesc() const;
    void setWarrantyPriorityDesc(const QString &warrantyPriorityDesc);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    RefWarrantyPriority &operator=(const RefWarrantyPriority &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static RefWarrantyPriority create(const QString &warrantyPriorityCd, const QString &warrantyPriorityNameEn, const QString &warrantyPriorityNameZh, const QString &warrantyPriorityDesc, const QString &createdBy, const QString &updatedBy);
    static RefWarrantyPriority create(const QVariantMap &values);
    static RefWarrantyPriority get(const QString &warrantyPriorityCd);
    static int count();
    static QList<RefWarrantyPriority> getAll();

private:
    QSharedDataPointer<RefWarrantyPriorityObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const RefWarrantyPriority &model);
    friend QDataStream &operator>>(QDataStream &ds, RefWarrantyPriority &model);
};

Q_DECLARE_METATYPE(RefWarrantyPriority)
Q_DECLARE_METATYPE(QList<RefWarrantyPriority>)

#endif // REFWARRANTYPRIORITY_H
