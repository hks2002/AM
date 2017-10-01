#ifndef REFPARTSTATUS_H
#define REFPARTSTATUS_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class RefPartStatusObject;


class T_MODEL_EXPORT RefPartStatus : public TAbstractModel
{
public:
    RefPartStatus();
    RefPartStatus(const RefPartStatus &other);
    RefPartStatus(const RefPartStatusObject &object);
    ~RefPartStatus();

    QString partStatusCd() const;
    void setPartStatusCd(const QString &partStatusCd);
    QString partStatusNameEn() const;
    void setPartStatusNameEn(const QString &partStatusNameEn);
    QString partStatusNameZh() const;
    void setPartStatusNameZh(const QString &partStatusNameZh);
    QString partStatusDesc() const;
    void setPartStatusDesc(const QString &partStatusDesc);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    RefPartStatus &operator=(const RefPartStatus &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static RefPartStatus create(const QString &partStatusCd, const QString &partStatusNameEn, const QString &partStatusNameZh, const QString &partStatusDesc, const QString &createdBy, const QString &updatedBy);
    static RefPartStatus create(const QVariantMap &values);
    static RefPartStatus get(const QString &partStatusCd);
    static int count();
    static QList<RefPartStatus> getAll();

private:
    QSharedDataPointer<RefPartStatusObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const RefPartStatus &model);
    friend QDataStream &operator>>(QDataStream &ds, RefPartStatus &model);
};

Q_DECLARE_METATYPE(RefPartStatus)
Q_DECLARE_METATYPE(QList<RefPartStatus>)

#endif // REFPARTSTATUS_H
