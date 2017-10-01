#ifndef REFCANCELWHEN_H
#define REFCANCELWHEN_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class RefCancelWhenObject;


class T_MODEL_EXPORT RefCancelWhen : public TAbstractModel
{
public:
    RefCancelWhen();
    RefCancelWhen(const RefCancelWhen &other);
    RefCancelWhen(const RefCancelWhenObject &object);
    ~RefCancelWhen();

    QString cancelWhenCd() const;
    void setCancelWhenCd(const QString &cancelWhenCd);
    QString cancelWhenNameEn() const;
    void setCancelWhenNameEn(const QString &cancelWhenNameEn);
    QString cancelWhenNameZh() const;
    void setCancelWhenNameZh(const QString &cancelWhenNameZh);
    QString cancelWhenDesc() const;
    void setCancelWhenDesc(const QString &cancelWhenDesc);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    RefCancelWhen &operator=(const RefCancelWhen &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static RefCancelWhen create(const QString &cancelWhenCd, const QString &cancelWhenNameEn, const QString &cancelWhenNameZh, const QString &cancelWhenDesc, const QString &createdBy, const QString &updatedBy);
    static RefCancelWhen create(const QVariantMap &values);
    static RefCancelWhen get(const QString &cancelWhenCd);
    static int count();
    static QList<RefCancelWhen> getAll();

private:
    QSharedDataPointer<RefCancelWhenObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const RefCancelWhen &model);
    friend QDataStream &operator>>(QDataStream &ds, RefCancelWhen &model);
};

Q_DECLARE_METATYPE(RefCancelWhen)
Q_DECLARE_METATYPE(QList<RefCancelWhen>)

#endif // REFCANCELWHEN_H
