#ifndef REFALERTSTATUS_H
#define REFALERTSTATUS_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class RefAlertStatusObject;


class T_MODEL_EXPORT RefAlertStatus : public TAbstractModel
{
public:
    RefAlertStatus();
    RefAlertStatus(const RefAlertStatus &other);
    RefAlertStatus(const RefAlertStatusObject &object);
    ~RefAlertStatus();

    QString alertStatusCd() const;
    void setAlertStatusCd(const QString &alertStatusCd);
    QString alertStatusNameEn() const;
    void setAlertStatusNameEn(const QString &alertStatusNameEn);
    QString alertStatusNameZh() const;
    void setAlertStatusNameZh(const QString &alertStatusNameZh);
    QString alertStatusDesc() const;
    void setAlertStatusDesc(const QString &alertStatusDesc);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    RefAlertStatus &operator=(const RefAlertStatus &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static RefAlertStatus create(const QString &alertStatusCd, const QString &alertStatusNameEn, const QString &alertStatusNameZh, const QString &alertStatusDesc, const QString &createdBy, const QString &updatedBy);
    static RefAlertStatus create(const QVariantMap &values);
    static RefAlertStatus get(const QString &alertStatusCd);
    static int count();
    static QList<RefAlertStatus> getAll();

private:
    QSharedDataPointer<RefAlertStatusObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const RefAlertStatus &model);
    friend QDataStream &operator>>(QDataStream &ds, RefAlertStatus &model);
};

Q_DECLARE_METATYPE(RefAlertStatus)
Q_DECLARE_METATYPE(QList<RefAlertStatus>)

#endif // REFALERTSTATUS_H
