#ifndef REFMAINTPRGMSTATUS_H
#define REFMAINTPRGMSTATUS_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class RefMaintPrgmStatusObject;


class T_MODEL_EXPORT RefMaintPrgmStatus : public TAbstractModel
{
public:
    RefMaintPrgmStatus();
    RefMaintPrgmStatus(const RefMaintPrgmStatus &other);
    RefMaintPrgmStatus(const RefMaintPrgmStatusObject &object);
    ~RefMaintPrgmStatus();

    QString maintPrgmStatusCd() const;
    void setMaintPrgmStatusCd(const QString &maintPrgmStatusCd);
    QString maintPrgmStatusNameEn() const;
    void setMaintPrgmStatusNameEn(const QString &maintPrgmStatusNameEn);
    QString maintPrgmStatusNameZh() const;
    void setMaintPrgmStatusNameZh(const QString &maintPrgmStatusNameZh);
    QString maintPrgmStatusDesc() const;
    void setMaintPrgmStatusDesc(const QString &maintPrgmStatusDesc);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    RefMaintPrgmStatus &operator=(const RefMaintPrgmStatus &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static RefMaintPrgmStatus create(const QString &maintPrgmStatusCd, const QString &maintPrgmStatusNameEn, const QString &maintPrgmStatusNameZh, const QString &maintPrgmStatusDesc, const QString &createdBy, const QString &updatedBy);
    static RefMaintPrgmStatus create(const QVariantMap &values);
    static RefMaintPrgmStatus get(const QString &maintPrgmStatusCd);
    static int count();
    static QList<RefMaintPrgmStatus> getAll();

private:
    QSharedDataPointer<RefMaintPrgmStatusObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const RefMaintPrgmStatus &model);
    friend QDataStream &operator>>(QDataStream &ds, RefMaintPrgmStatus &model);
};

Q_DECLARE_METATYPE(RefMaintPrgmStatus)
Q_DECLARE_METATYPE(QList<RefMaintPrgmStatus>)

#endif // REFMAINTPRGMSTATUS_H
