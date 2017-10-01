#ifndef REFRESCHEDFROM_H
#define REFRESCHEDFROM_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class RefReschedFromObject;


class T_MODEL_EXPORT RefReschedFrom : public TAbstractModel
{
public:
    RefReschedFrom();
    RefReschedFrom(const RefReschedFrom &other);
    RefReschedFrom(const RefReschedFromObject &object);
    ~RefReschedFrom();

    QString reschedFromCd() const;
    void setReschedFromCd(const QString &reschedFromCd);
    QString reschedFromNameEn() const;
    void setReschedFromNameEn(const QString &reschedFromNameEn);
    QString reschedFromNameZh() const;
    void setReschedFromNameZh(const QString &reschedFromNameZh);
    QString reschedFromDesc() const;
    void setReschedFromDesc(const QString &reschedFromDesc);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    RefReschedFrom &operator=(const RefReschedFrom &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static RefReschedFrom create(const QString &reschedFromCd, const QString &reschedFromNameEn, const QString &reschedFromNameZh, const QString &reschedFromDesc, const QString &createdBy, const QString &updatedBy);
    static RefReschedFrom create(const QVariantMap &values);
    static RefReschedFrom get(const QString &reschedFromCd);
    static int count();
    static QList<RefReschedFrom> getAll();

private:
    QSharedDataPointer<RefReschedFromObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const RefReschedFrom &model);
    friend QDataStream &operator>>(QDataStream &ds, RefReschedFrom &model);
};

Q_DECLARE_METATYPE(RefReschedFrom)
Q_DECLARE_METATYPE(QList<RefReschedFrom>)

#endif // REFRESCHEDFROM_H
