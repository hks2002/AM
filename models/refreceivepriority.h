#ifndef REFRECEIVEPRIORITY_H
#define REFRECEIVEPRIORITY_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class RefReceivePriorityObject;


class T_MODEL_EXPORT RefReceivePriority : public TAbstractModel
{
public:
    RefReceivePriority();
    RefReceivePriority(const RefReceivePriority &other);
    RefReceivePriority(const RefReceivePriorityObject &object);
    ~RefReceivePriority();

    QString rcvPriorityCd() const;
    void setRcvPriorityCd(const QString &rcvPriorityCd);
    QString rcvPriorityNameEn() const;
    void setRcvPriorityNameEn(const QString &rcvPriorityNameEn);
    QString rcvPriorityNameZh() const;
    void setRcvPriorityNameZh(const QString &rcvPriorityNameZh);
    QString rcvPriorityDesc() const;
    void setRcvPriorityDesc(const QString &rcvPriorityDesc);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    RefReceivePriority &operator=(const RefReceivePriority &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static RefReceivePriority create(const QString &rcvPriorityCd, const QString &rcvPriorityNameEn, const QString &rcvPriorityNameZh, const QString &rcvPriorityDesc, const QString &createdBy, const QString &updatedBy);
    static RefReceivePriority create(const QVariantMap &values);
    static RefReceivePriority get(const QString &rcvPriorityCd);
    static int count();
    static QList<RefReceivePriority> getAll();

private:
    QSharedDataPointer<RefReceivePriorityObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const RefReceivePriority &model);
    friend QDataStream &operator>>(QDataStream &ds, RefReceivePriority &model);
};

Q_DECLARE_METATYPE(RefReceivePriority)
Q_DECLARE_METATYPE(QList<RefReceivePriority>)

#endif // REFRECEIVEPRIORITY_H
