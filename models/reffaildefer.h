#ifndef REFFAILDEFER_H
#define REFFAILDEFER_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class RefFailDeferObject;


class T_MODEL_EXPORT RefFailDefer : public TAbstractModel
{
public:
    RefFailDefer();
    RefFailDefer(const RefFailDefer &other);
    RefFailDefer(const RefFailDeferObject &object);
    ~RefFailDefer();

    QString failDeferCd() const;
    void setFailDeferCd(const QString &failDeferCd);
    QString failDeferNameEn() const;
    void setFailDeferNameEn(const QString &failDeferNameEn);
    QString failDeferNameZh() const;
    void setFailDeferNameZh(const QString &failDeferNameZh);
    QString failDeferDesc() const;
    void setFailDeferDesc(const QString &failDeferDesc);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    RefFailDefer &operator=(const RefFailDefer &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static RefFailDefer create(const QString &failDeferCd, const QString &failDeferNameEn, const QString &failDeferNameZh, const QString &failDeferDesc, const QString &createdBy, const QString &updatedBy);
    static RefFailDefer create(const QVariantMap &values);
    static RefFailDefer get(const QString &failDeferCd);
    static int count();
    static QList<RefFailDefer> getAll();

private:
    QSharedDataPointer<RefFailDeferObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const RefFailDefer &model);
    friend QDataStream &operator>>(QDataStream &ds, RefFailDefer &model);
};

Q_DECLARE_METATYPE(RefFailDefer)
Q_DECLARE_METATYPE(QList<RefFailDefer>)

#endif // REFFAILDEFER_H
