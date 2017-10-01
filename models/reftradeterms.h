#ifndef REFTRADETERMS_H
#define REFTRADETERMS_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class RefTradeTermsObject;


class T_MODEL_EXPORT RefTradeTerms : public TAbstractModel
{
public:
    RefTradeTerms();
    RefTradeTerms(const RefTradeTerms &other);
    RefTradeTerms(const RefTradeTermsObject &object);
    ~RefTradeTerms();

    QString tradeTermCd() const;
    void setTradeTermCd(const QString &tradeTermCd);
    QString tradeTermNameEn() const;
    void setTradeTermNameEn(const QString &tradeTermNameEn);
    QString tradeTermNameZh() const;
    void setTradeTermNameZh(const QString &tradeTermNameZh);
    QString tradeTermDesc() const;
    void setTradeTermDesc(const QString &tradeTermDesc);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    RefTradeTerms &operator=(const RefTradeTerms &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static RefTradeTerms create(const QString &tradeTermCd, const QString &tradeTermNameEn, const QString &tradeTermNameZh, const QString &tradeTermDesc, const QString &createdBy, const QString &updatedBy);
    static RefTradeTerms create(const QVariantMap &values);
    static RefTradeTerms get(const QString &tradeTermCd);
    static int count();
    static QList<RefTradeTerms> getAll();

private:
    QSharedDataPointer<RefTradeTermsObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const RefTradeTerms &model);
    friend QDataStream &operator>>(QDataStream &ds, RefTradeTerms &model);
};

Q_DECLARE_METATYPE(RefTradeTerms)
Q_DECLARE_METATYPE(QList<RefTradeTerms>)

#endif // REFTRADETERMS_H
