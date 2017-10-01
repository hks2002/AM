#ifndef REFREMOVEREASON_H
#define REFREMOVEREASON_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class RefRemoveReasonObject;


class T_MODEL_EXPORT RefRemoveReason : public TAbstractModel
{
public:
    RefRemoveReason();
    RefRemoveReason(const RefRemoveReason &other);
    RefRemoveReason(const RefRemoveReasonObject &object);
    ~RefRemoveReason();

    QString removeReasonCd() const;
    void setRemoveReasonCd(const QString &removeReasonCd);
    QString removeReasonNameEn() const;
    void setRemoveReasonNameEn(const QString &removeReasonNameEn);
    QString removeReasonNameZh() const;
    void setRemoveReasonNameZh(const QString &removeReasonNameZh);
    QString removeReasonDesc() const;
    void setRemoveReasonDesc(const QString &removeReasonDesc);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    RefRemoveReason &operator=(const RefRemoveReason &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static RefRemoveReason create(const QString &removeReasonCd, const QString &removeReasonNameEn, const QString &removeReasonNameZh, const QString &removeReasonDesc, const QString &createdBy, const QString &updatedBy);
    static RefRemoveReason create(const QVariantMap &values);
    static RefRemoveReason get(const QString &removeReasonCd);
    static int count();
    static QList<RefRemoveReason> getAll();

private:
    QSharedDataPointer<RefRemoveReasonObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const RefRemoveReason &model);
    friend QDataStream &operator>>(QDataStream &ds, RefRemoveReason &model);
};

Q_DECLARE_METATYPE(RefRemoveReason)
Q_DECLARE_METATYPE(QList<RefRemoveReason>)

#endif // REFREMOVEREASON_H
