#ifndef REFEVENTSTATUS_H
#define REFEVENTSTATUS_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class RefEventStatusObject;


class T_MODEL_EXPORT RefEventStatus : public TAbstractModel
{
public:
    RefEventStatus();
    RefEventStatus(const RefEventStatus &other);
    RefEventStatus(const RefEventStatusObject &object);
    ~RefEventStatus();

    QString eventStatusCd() const;
    void setEventStatusCd(const QString &eventStatusCd);
    QString eventStatusNameEn() const;
    void setEventStatusNameEn(const QString &eventStatusNameEn);
    QString eventStatusNameZh() const;
    void setEventStatusNameZh(const QString &eventStatusNameZh);
    QString eventStatusDesc() const;
    void setEventStatusDesc(const QString &eventStatusDesc);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    RefEventStatus &operator=(const RefEventStatus &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static RefEventStatus create(const QString &eventStatusCd, const QString &eventStatusNameEn, const QString &eventStatusNameZh, const QString &eventStatusDesc, const QString &createdBy, const QString &updatedBy);
    static RefEventStatus create(const QVariantMap &values);
    static RefEventStatus get(const QString &eventStatusCd);
    static int count();
    static QList<RefEventStatus> getAll();

private:
    QSharedDataPointer<RefEventStatusObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const RefEventStatus &model);
    friend QDataStream &operator>>(QDataStream &ds, RefEventStatus &model);
};

Q_DECLARE_METATYPE(RefEventStatus)
Q_DECLARE_METATYPE(QList<RefEventStatus>)

#endif // REFEVENTSTATUS_H
