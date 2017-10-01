#ifndef REFSTOCKLOWACTN_H
#define REFSTOCKLOWACTN_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class RefStockLowActnObject;


class T_MODEL_EXPORT RefStockLowActn : public TAbstractModel
{
public:
    RefStockLowActn();
    RefStockLowActn(const RefStockLowActn &other);
    RefStockLowActn(const RefStockLowActnObject &object);
    ~RefStockLowActn();

    QString stockLowActnCd() const;
    void setStockLowActnCd(const QString &stockLowActnCd);
    QString stockLowActnNameEn() const;
    void setStockLowActnNameEn(const QString &stockLowActnNameEn);
    QString stockLowActnNameZh() const;
    void setStockLowActnNameZh(const QString &stockLowActnNameZh);
    QString stockLowActnDesc() const;
    void setStockLowActnDesc(const QString &stockLowActnDesc);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    RefStockLowActn &operator=(const RefStockLowActn &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static RefStockLowActn create(const QString &stockLowActnCd, const QString &stockLowActnNameEn, const QString &stockLowActnNameZh, const QString &stockLowActnDesc, const QString &createdBy, const QString &updatedBy);
    static RefStockLowActn create(const QVariantMap &values);
    static RefStockLowActn get(const QString &stockLowActnCd);
    static int count();
    static QList<RefStockLowActn> getAll();

private:
    QSharedDataPointer<RefStockLowActnObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const RefStockLowActn &model);
    friend QDataStream &operator>>(QDataStream &ds, RefStockLowActn &model);
};

Q_DECLARE_METATYPE(RefStockLowActn)
Q_DECLARE_METATYPE(QList<RefStockLowActn>)

#endif // REFSTOCKLOWACTN_H
