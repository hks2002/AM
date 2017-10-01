#ifndef REFOWNBY_H
#define REFOWNBY_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class RefOwnByObject;


class T_MODEL_EXPORT RefOwnBy : public TAbstractModel
{
public:
    RefOwnBy();
    RefOwnBy(const RefOwnBy &other);
    RefOwnBy(const RefOwnByObject &object);
    ~RefOwnBy();

    QString ownByCd() const;
    void setOwnByCd(const QString &ownByCd);
    QString ownByNameEn() const;
    void setOwnByNameEn(const QString &ownByNameEn);
    QString ownByNameZh() const;
    void setOwnByNameZh(const QString &ownByNameZh);
    QString ownByDesc() const;
    void setOwnByDesc(const QString &ownByDesc);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    RefOwnBy &operator=(const RefOwnBy &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static RefOwnBy create(const QString &ownByCd, const QString &ownByNameEn, const QString &ownByNameZh, const QString &ownByDesc, const QString &createdBy, const QString &updatedBy);
    static RefOwnBy create(const QVariantMap &values);
    static RefOwnBy get(const QString &ownByCd);
    static int count();
    static QList<RefOwnBy> getAll();

private:
    QSharedDataPointer<RefOwnByObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const RefOwnBy &model);
    friend QDataStream &operator>>(QDataStream &ds, RefOwnBy &model);
};

Q_DECLARE_METATYPE(RefOwnBy)
Q_DECLARE_METATYPE(QList<RefOwnBy>)

#endif // REFOWNBY_H
