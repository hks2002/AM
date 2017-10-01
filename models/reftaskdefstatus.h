#ifndef REFTASKDEFSTATUS_H
#define REFTASKDEFSTATUS_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class RefTaskDefStatusObject;


class T_MODEL_EXPORT RefTaskDefStatus : public TAbstractModel
{
public:
    RefTaskDefStatus();
    RefTaskDefStatus(const RefTaskDefStatus &other);
    RefTaskDefStatus(const RefTaskDefStatusObject &object);
    ~RefTaskDefStatus();

    QString taskDefStatusCd() const;
    void setTaskDefStatusCd(const QString &taskDefStatusCd);
    QString taskDefStatusNameEn() const;
    void setTaskDefStatusNameEn(const QString &taskDefStatusNameEn);
    QString taskDefStatusNameZh() const;
    void setTaskDefStatusNameZh(const QString &taskDefStatusNameZh);
    QString taskDefStatusDesc() const;
    void setTaskDefStatusDesc(const QString &taskDefStatusDesc);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    RefTaskDefStatus &operator=(const RefTaskDefStatus &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static RefTaskDefStatus create(const QString &taskDefStatusCd, const QString &taskDefStatusNameEn, const QString &taskDefStatusNameZh, const QString &taskDefStatusDesc, const QString &createdBy, const QString &updatedBy);
    static RefTaskDefStatus create(const QVariantMap &values);
    static RefTaskDefStatus get(const QString &taskDefStatusCd);
    static int count();
    static QList<RefTaskDefStatus> getAll();

private:
    QSharedDataPointer<RefTaskDefStatusObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const RefTaskDefStatus &model);
    friend QDataStream &operator>>(QDataStream &ds, RefTaskDefStatus &model);
};

Q_DECLARE_METATYPE(RefTaskDefStatus)
Q_DECLARE_METATYPE(QList<RefTaskDefStatus>)

#endif // REFTASKDEFSTATUS_H
