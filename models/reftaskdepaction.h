#ifndef REFTASKDEPACTION_H
#define REFTASKDEPACTION_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class RefTaskDepActionObject;


class T_MODEL_EXPORT RefTaskDepAction : public TAbstractModel
{
public:
    RefTaskDepAction();
    RefTaskDepAction(const RefTaskDepAction &other);
    RefTaskDepAction(const RefTaskDepActionObject &object);
    ~RefTaskDepAction();

    QString taskDepActionCd() const;
    void setTaskDepActionCd(const QString &taskDepActionCd);
    QString taskDepActionNameEn() const;
    void setTaskDepActionNameEn(const QString &taskDepActionNameEn);
    QString taskDepActionNameZh() const;
    void setTaskDepActionNameZh(const QString &taskDepActionNameZh);
    QString taskDepActionDesc() const;
    void setTaskDepActionDesc(const QString &taskDepActionDesc);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    RefTaskDepAction &operator=(const RefTaskDepAction &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static RefTaskDepAction create(const QString &taskDepActionCd, const QString &taskDepActionNameEn, const QString &taskDepActionNameZh, const QString &taskDepActionDesc, const QString &createdBy, const QString &updatedBy);
    static RefTaskDepAction create(const QVariantMap &values);
    static RefTaskDepAction get(const QString &taskDepActionCd);
    static int count();
    static QList<RefTaskDepAction> getAll();

private:
    QSharedDataPointer<RefTaskDepActionObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const RefTaskDepAction &model);
    friend QDataStream &operator>>(QDataStream &ds, RefTaskDepAction &model);
};

Q_DECLARE_METATYPE(RefTaskDepAction)
Q_DECLARE_METATYPE(QList<RefTaskDepAction>)

#endif // REFTASKDEPACTION_H
