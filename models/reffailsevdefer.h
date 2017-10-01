#ifndef REFFAILSEVDEFER_H
#define REFFAILSEVDEFER_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class RefFailSevDeferObject;
class RefFailDefer;
class RefFailSev;


class T_MODEL_EXPORT RefFailSevDefer : public TAbstractModel
{
public:
    RefFailSevDefer();
    RefFailSevDefer(const RefFailSevDefer &other);
    RefFailSevDefer(const RefFailSevDeferObject &object);
    ~RefFailSevDefer();

    QString failSevCd() const;
    void setFailSevCd(const QString &failSevCd);
    QString failDeferCd() const;
    void setFailDeferCd(const QString &failDeferCd);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    RefFailDefer refFailDeferByfailDeferCd() const;
    RefFailSev refFailSevByfailSevCd() const;
    RefFailSevDefer &operator=(const RefFailSevDefer &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static RefFailSevDefer create(const QString &failSevCd, const QString &failDeferCd, const QString &createdBy, const QString &updatedBy);
    static RefFailSevDefer create(const QVariantMap &values);
    static RefFailSevDefer get(const QString &failSevCd, const QString &failDeferCd);
    static int count();
    static QList<RefFailSevDefer> getAll();

private:
    QSharedDataPointer<RefFailSevDeferObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const RefFailSevDefer &model);
    friend QDataStream &operator>>(QDataStream &ds, RefFailSevDefer &model);
};

Q_DECLARE_METATYPE(RefFailSevDefer)
Q_DECLARE_METATYPE(QList<RefFailSevDefer>)

#endif // REFFAILSEVDEFER_H
