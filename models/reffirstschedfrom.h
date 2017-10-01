#ifndef REFFIRSTSCHEDFROM_H
#define REFFIRSTSCHEDFROM_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class RefFirstSchedFromObject;


class T_MODEL_EXPORT RefFirstSchedFrom : public TAbstractModel
{
public:
    RefFirstSchedFrom();
    RefFirstSchedFrom(const RefFirstSchedFrom &other);
    RefFirstSchedFrom(const RefFirstSchedFromObject &object);
    ~RefFirstSchedFrom();

    QString firstSchedFromCd() const;
    void setFirstSchedFromCd(const QString &firstSchedFromCd);
    QString firstSchedFromNameEn() const;
    void setFirstSchedFromNameEn(const QString &firstSchedFromNameEn);
    QString firstSchedFromNameZh() const;
    void setFirstSchedFromNameZh(const QString &firstSchedFromNameZh);
    QString firstSchedFromDesc() const;
    void setFirstSchedFromDesc(const QString &firstSchedFromDesc);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    RefFirstSchedFrom &operator=(const RefFirstSchedFrom &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static RefFirstSchedFrom create(const QString &firstSchedFromCd, const QString &firstSchedFromNameEn, const QString &firstSchedFromNameZh, const QString &firstSchedFromDesc, const QString &createdBy, const QString &updatedBy);
    static RefFirstSchedFrom create(const QVariantMap &values);
    static RefFirstSchedFrom get(const QString &firstSchedFromCd);
    static int count();
    static QList<RefFirstSchedFrom> getAll();

private:
    QSharedDataPointer<RefFirstSchedFromObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const RefFirstSchedFrom &model);
    friend QDataStream &operator>>(QDataStream &ds, RefFirstSchedFrom &model);
};

Q_DECLARE_METATYPE(RefFirstSchedFrom)
Q_DECLARE_METATYPE(QList<RefFirstSchedFrom>)

#endif // REFFIRSTSCHEDFROM_H
