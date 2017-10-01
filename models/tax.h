#ifndef TAX_H
#define TAX_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class TaxObject;
class FncAccount;


class T_MODEL_EXPORT Tax : public TAbstractModel
{
public:
    Tax();
    Tax(const Tax &other);
    Tax(const TaxObject &object);
    ~Tax();

    int taxId() const;
    QString taxCd() const;
    void setTaxCd(const QString &taxCd);
    QString taxName() const;
    void setTaxName(const QString &taxName);
    int accountId() const;
    void setAccountId(int accountId);
    bool recoverableBool() const;
    void setRecoverableBool(bool recoverableBool);
    bool archiveBool() const;
    void setArchiveBool(bool archiveBool);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    FncAccount fncAccountByaccountId() const;
    Tax &operator=(const Tax &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static Tax create(const QString &taxCd, const QString &taxName, int accountId, bool recoverableBool, bool archiveBool, const QString &createdBy, const QString &updatedBy);
    static Tax create(const QVariantMap &values);
    static Tax get(int taxId);
    static int count();
    static QList<Tax> getAll();

private:
    QSharedDataPointer<TaxObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const Tax &model);
    friend QDataStream &operator>>(QDataStream &ds, Tax &model);
};

Q_DECLARE_METATYPE(Tax)
Q_DECLARE_METATYPE(QList<Tax>)

#endif // TAX_H
