#ifndef REFREQPRIORITY_H
#define REFREQPRIORITY_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class RefReqPriorityObject;


class T_MODEL_EXPORT RefReqPriority : public TAbstractModel
{
public:
    RefReqPriority();
    RefReqPriority(const RefReqPriority &other);
    RefReqPriority(const RefReqPriorityObject &object);
    ~RefReqPriority();

    QString reqPriorityCd() const;
    void setReqPriorityCd(const QString &reqPriorityCd);
    QString reqPriorityNameEn() const;
    void setReqPriorityNameEn(const QString &reqPriorityNameEn);
    QString reqPriorityNameZh() const;
    void setReqPriorityNameZh(const QString &reqPriorityNameZh);
    QString reqPriorityDesc() const;
    void setReqPriorityDesc(const QString &reqPriorityDesc);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    RefReqPriority &operator=(const RefReqPriority &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static RefReqPriority create(const QString &reqPriorityCd, const QString &reqPriorityNameEn, const QString &reqPriorityNameZh, const QString &reqPriorityDesc, const QString &createdBy, const QString &updatedBy);
    static RefReqPriority create(const QVariantMap &values);
    static RefReqPriority get(const QString &reqPriorityCd);
    static int count();
    static QList<RefReqPriority> getAll();

private:
    QSharedDataPointer<RefReqPriorityObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const RefReqPriority &model);
    friend QDataStream &operator>>(QDataStream &ds, RefReqPriority &model);
};

Q_DECLARE_METATYPE(RefReqPriority)
Q_DECLARE_METATYPE(QList<RefReqPriority>)

#endif // REFREQPRIORITY_H
