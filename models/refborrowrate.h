#ifndef REFBORROWRATE_H
#define REFBORROWRATE_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class RefBorrowRateObject;


class T_MODEL_EXPORT RefBorrowRate : public TAbstractModel
{
public:
    RefBorrowRate();
    RefBorrowRate(const RefBorrowRate &other);
    RefBorrowRate(const RefBorrowRateObject &object);
    ~RefBorrowRate();

    QString borrowRateCd() const;
    void setBorrowRateCd(const QString &borrowRateCd);
    QString borrowRateNameEn() const;
    void setBorrowRateNameEn(const QString &borrowRateNameEn);
    QString borrowRateNameZh() const;
    void setBorrowRateNameZh(const QString &borrowRateNameZh);
    QString borrowRateDesc() const;
    void setBorrowRateDesc(const QString &borrowRateDesc);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    RefBorrowRate &operator=(const RefBorrowRate &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static RefBorrowRate create(const QString &borrowRateCd, const QString &borrowRateNameEn, const QString &borrowRateNameZh, const QString &borrowRateDesc, const QString &createdBy, const QString &updatedBy);
    static RefBorrowRate create(const QVariantMap &values);
    static RefBorrowRate get(const QString &borrowRateCd);
    static int count();
    static QList<RefBorrowRate> getAll();

private:
    QSharedDataPointer<RefBorrowRateObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const RefBorrowRate &model);
    friend QDataStream &operator>>(QDataStream &ds, RefBorrowRate &model);
};

Q_DECLARE_METATYPE(RefBorrowRate)
Q_DECLARE_METATYPE(QList<RefBorrowRate>)

#endif // REFBORROWRATE_H
