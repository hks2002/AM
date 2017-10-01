#ifndef REFREQACTION_H
#define REFREQACTION_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class RefReqActionObject;


class T_MODEL_EXPORT RefReqAction : public TAbstractModel
{
public:
    RefReqAction();
    RefReqAction(const RefReqAction &other);
    RefReqAction(const RefReqActionObject &object);
    ~RefReqAction();

    QString reqActionCd() const;
    void setReqActionCd(const QString &reqActionCd);
    QString reqActionNameEn() const;
    void setReqActionNameEn(const QString &reqActionNameEn);
    QString reqActionNameZh() const;
    void setReqActionNameZh(const QString &reqActionNameZh);
    QString reqActionDesc() const;
    void setReqActionDesc(const QString &reqActionDesc);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    RefReqAction &operator=(const RefReqAction &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static RefReqAction create(const QString &reqActionCd, const QString &reqActionNameEn, const QString &reqActionNameZh, const QString &reqActionDesc, const QString &createdBy, const QString &updatedBy);
    static RefReqAction create(const QVariantMap &values);
    static RefReqAction get(const QString &reqActionCd);
    static int count();
    static QList<RefReqAction> getAll();

private:
    QSharedDataPointer<RefReqActionObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const RefReqAction &model);
    friend QDataStream &operator>>(QDataStream &ds, RefReqAction &model);
};

Q_DECLARE_METATYPE(RefReqAction)
Q_DECLARE_METATYPE(QList<RefReqAction>)

#endif // REFREQACTION_H
