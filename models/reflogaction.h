#ifndef REFLOGACTION_H
#define REFLOGACTION_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class RefLogActionObject;


class T_MODEL_EXPORT RefLogAction : public TAbstractModel
{
public:
    RefLogAction();
    RefLogAction(const RefLogAction &other);
    RefLogAction(const RefLogActionObject &object);
    ~RefLogAction();

    QString logActionCd() const;
    void setLogActionCd(const QString &logActionCd);
    QString logActionNameEn() const;
    void setLogActionNameEn(const QString &logActionNameEn);
    QString logActionNameZh() const;
    void setLogActionNameZh(const QString &logActionNameZh);
    QString logActionDesc() const;
    void setLogActionDesc(const QString &logActionDesc);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    RefLogAction &operator=(const RefLogAction &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static RefLogAction create(const QString &logActionCd, const QString &logActionNameEn, const QString &logActionNameZh, const QString &logActionDesc, const QString &createdBy, const QString &updatedBy);
    static RefLogAction create(const QVariantMap &values);
    static RefLogAction get(const QString &logActionCd);
    static int count();
    static QList<RefLogAction> getAll();

private:
    QSharedDataPointer<RefLogActionObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const RefLogAction &model);
    friend QDataStream &operator>>(QDataStream &ds, RefLogAction &model);
};

Q_DECLARE_METATYPE(RefLogAction)
Q_DECLARE_METATYPE(QList<RefLogAction>)

#endif // REFLOGACTION_H
