#ifndef REFSCHEDPARTSTATUS_H
#define REFSCHEDPARTSTATUS_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class RefSchedPartStatusObject;


class T_MODEL_EXPORT RefSchedPartStatus : public TAbstractModel
{
public:
    RefSchedPartStatus();
    RefSchedPartStatus(const RefSchedPartStatus &other);
    RefSchedPartStatus(const RefSchedPartStatusObject &object);
    ~RefSchedPartStatus();

    QString schedPartStatusCd() const;
    void setSchedPartStatusCd(const QString &schedPartStatusCd);
    QString schedPartStatusNameEn() const;
    void setSchedPartStatusNameEn(const QString &schedPartStatusNameEn);
    QString schedPartStatusNameZh() const;
    void setSchedPartStatusNameZh(const QString &schedPartStatusNameZh);
    QString schedPartStatusDesc() const;
    void setSchedPartStatusDesc(const QString &schedPartStatusDesc);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    RefSchedPartStatus &operator=(const RefSchedPartStatus &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static RefSchedPartStatus create(const QString &schedPartStatusCd, const QString &schedPartStatusNameEn, const QString &schedPartStatusNameZh, const QString &schedPartStatusDesc, const QString &createdBy, const QString &updatedBy);
    static RefSchedPartStatus create(const QVariantMap &values);
    static RefSchedPartStatus get(const QString &schedPartStatusCd);
    static int count();
    static QList<RefSchedPartStatus> getAll();

private:
    QSharedDataPointer<RefSchedPartStatusObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const RefSchedPartStatus &model);
    friend QDataStream &operator>>(QDataStream &ds, RefSchedPartStatus &model);
};

Q_DECLARE_METATYPE(RefSchedPartStatus)
Q_DECLARE_METATYPE(QList<RefSchedPartStatus>)

#endif // REFSCHEDPARTSTATUS_H
