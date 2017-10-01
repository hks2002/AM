#ifndef REFPARTUSE_H
#define REFPARTUSE_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class RefPartUseObject;


class T_MODEL_EXPORT RefPartUse : public TAbstractModel
{
public:
    RefPartUse();
    RefPartUse(const RefPartUse &other);
    RefPartUse(const RefPartUseObject &object);
    ~RefPartUse();

    QString partUseCd() const;
    void setPartUseCd(const QString &partUseCd);
    QString partUseNameEn() const;
    void setPartUseNameEn(const QString &partUseNameEn);
    QString partUseNameZh() const;
    void setPartUseNameZh(const QString &partUseNameZh);
    QString partUseDesc() const;
    void setPartUseDesc(const QString &partUseDesc);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    RefPartUse &operator=(const RefPartUse &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static RefPartUse create(const QString &partUseCd, const QString &partUseNameEn, const QString &partUseNameZh, const QString &partUseDesc, const QString &createdBy, const QString &updatedBy);
    static RefPartUse create(const QVariantMap &values);
    static RefPartUse get(const QString &partUseCd);
    static int count();
    static QList<RefPartUse> getAll();

private:
    QSharedDataPointer<RefPartUseObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const RefPartUse &model);
    friend QDataStream &operator>>(QDataStream &ds, RefPartUse &model);
};

Q_DECLARE_METATYPE(RefPartUse)
Q_DECLARE_METATYPE(QList<RefPartUse>)

#endif // REFPARTUSE_H
