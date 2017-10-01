#ifndef REFCREATEWHEN_H
#define REFCREATEWHEN_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class RefCreateWhenObject;


class T_MODEL_EXPORT RefCreateWhen : public TAbstractModel
{
public:
    RefCreateWhen();
    RefCreateWhen(const RefCreateWhen &other);
    RefCreateWhen(const RefCreateWhenObject &object);
    ~RefCreateWhen();

    QString createWhenCd() const;
    void setCreateWhenCd(const QString &createWhenCd);
    QString createWhenNameEn() const;
    void setCreateWhenNameEn(const QString &createWhenNameEn);
    QString createWhenNameZh() const;
    void setCreateWhenNameZh(const QString &createWhenNameZh);
    QString createWhenDesc() const;
    void setCreateWhenDesc(const QString &createWhenDesc);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    RefCreateWhen &operator=(const RefCreateWhen &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static RefCreateWhen create(const QString &createWhenCd, const QString &createWhenNameEn, const QString &createWhenNameZh, const QString &createWhenDesc, const QString &createdBy, const QString &updatedBy);
    static RefCreateWhen create(const QVariantMap &values);
    static RefCreateWhen get(const QString &createWhenCd);
    static int count();
    static QList<RefCreateWhen> getAll();

private:
    QSharedDataPointer<RefCreateWhenObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const RefCreateWhen &model);
    friend QDataStream &operator>>(QDataStream &ds, RefCreateWhen &model);
};

Q_DECLARE_METATYPE(RefCreateWhen)
Q_DECLARE_METATYPE(QList<RefCreateWhen>)

#endif // REFCREATEWHEN_H
