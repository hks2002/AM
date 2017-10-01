#ifndef REFINVCOND_H
#define REFINVCOND_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class RefInvCondObject;


class T_MODEL_EXPORT RefInvCond : public TAbstractModel
{
public:
    RefInvCond();
    RefInvCond(const RefInvCond &other);
    RefInvCond(const RefInvCondObject &object);
    ~RefInvCond();

    QString invCondCd() const;
    void setInvCondCd(const QString &invCondCd);
    QString invCondNameEn() const;
    void setInvCondNameEn(const QString &invCondNameEn);
    QString invCondNameZh() const;
    void setInvCondNameZh(const QString &invCondNameZh);
    QString invCondDesc() const;
    void setInvCondDesc(const QString &invCondDesc);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    RefInvCond &operator=(const RefInvCond &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static RefInvCond create(const QString &invCondCd, const QString &invCondNameEn, const QString &invCondNameZh, const QString &invCondDesc, const QString &createdBy, const QString &updatedBy);
    static RefInvCond create(const QVariantMap &values);
    static RefInvCond get(const QString &invCondCd);
    static int count();
    static QList<RefInvCond> getAll();

private:
    QSharedDataPointer<RefInvCondObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const RefInvCond &model);
    friend QDataStream &operator>>(QDataStream &ds, RefInvCond &model);
};

Q_DECLARE_METATYPE(RefInvCond)
Q_DECLARE_METATYPE(QList<RefInvCond>)

#endif // REFINVCOND_H
