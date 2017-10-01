#ifndef FAILDEFERREF_H
#define FAILDEFERREF_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class FailDeferRefObject;
class RefFailSev;
class RefFailDefer;


class T_MODEL_EXPORT FailDeferRef : public TAbstractModel
{
public:
    FailDeferRef();
    FailDeferRef(const FailDeferRef &other);
    FailDeferRef(const FailDeferRefObject &object);
    ~FailDeferRef();

    int failDeferRefId() const;
    QString failDeferCd() const;
    void setFailDeferCd(const QString &failDeferCd);
    QString deferRefName() const;
    void setDeferRefName(const QString &deferRefName);
    QString deferRefDesc() const;
    void setDeferRefDesc(const QString &deferRefDesc);
    QString failSevCd() const;
    void setFailSevCd(const QString &failSevCd);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    RefFailSev refFailSevByfailSevCd() const;
    RefFailDefer refFailDeferByfailDeferCd() const;
    FailDeferRef &operator=(const FailDeferRef &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static FailDeferRef create(const QString &failDeferCd, const QString &deferRefName, const QString &deferRefDesc, const QString &failSevCd, const QString &createdBy, const QString &updatedBy);
    static FailDeferRef create(const QVariantMap &values);
    static FailDeferRef get(int failDeferRefId);
    static int count();
    static QList<FailDeferRef> getAll();

private:
    QSharedDataPointer<FailDeferRefObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const FailDeferRef &model);
    friend QDataStream &operator>>(QDataStream &ds, FailDeferRef &model);
};

Q_DECLARE_METATYPE(FailDeferRef)
Q_DECLARE_METATYPE(QList<FailDeferRef>)

#endif // FAILDEFERREF_H
