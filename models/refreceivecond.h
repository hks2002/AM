#ifndef REFRECEIVECOND_H
#define REFRECEIVECOND_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class RefReceiveCondObject;


class T_MODEL_EXPORT RefReceiveCond : public TAbstractModel
{
public:
    RefReceiveCond();
    RefReceiveCond(const RefReceiveCond &other);
    RefReceiveCond(const RefReceiveCondObject &object);
    ~RefReceiveCond();

    QString receiveCondCd() const;
    void setReceiveCondCd(const QString &receiveCondCd);
    QString receiveCondNameEn() const;
    void setReceiveCondNameEn(const QString &receiveCondNameEn);
    QString receiveCondNameZh() const;
    void setReceiveCondNameZh(const QString &receiveCondNameZh);
    QString receiveCondDesc() const;
    void setReceiveCondDesc(const QString &receiveCondDesc);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    RefReceiveCond &operator=(const RefReceiveCond &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static RefReceiveCond create(const QString &receiveCondCd, const QString &receiveCondNameEn, const QString &receiveCondNameZh, const QString &receiveCondDesc, const QString &createdBy, const QString &updatedBy);
    static RefReceiveCond create(const QVariantMap &values);
    static RefReceiveCond get(const QString &receiveCondCd);
    static int count();
    static QList<RefReceiveCond> getAll();

private:
    QSharedDataPointer<RefReceiveCondObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const RefReceiveCond &model);
    friend QDataStream &operator>>(QDataStream &ds, RefReceiveCond &model);
};

Q_DECLARE_METATYPE(RefReceiveCond)
Q_DECLARE_METATYPE(QList<RefReceiveCond>)

#endif // REFRECEIVECOND_H
