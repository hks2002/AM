#ifndef REFDOCDISPOSITION_H
#define REFDOCDISPOSITION_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class RefDocDispositionObject;


class T_MODEL_EXPORT RefDocDisposition : public TAbstractModel
{
public:
    RefDocDisposition();
    RefDocDisposition(const RefDocDisposition &other);
    RefDocDisposition(const RefDocDispositionObject &object);
    ~RefDocDisposition();

    QString docDispositionCd() const;
    void setDocDispositionCd(const QString &docDispositionCd);
    QString docDispositionNameEn() const;
    void setDocDispositionNameEn(const QString &docDispositionNameEn);
    QString docDispositionNameZh() const;
    void setDocDispositionNameZh(const QString &docDispositionNameZh);
    QString docDispositionDesc() const;
    void setDocDispositionDesc(const QString &docDispositionDesc);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    RefDocDisposition &operator=(const RefDocDisposition &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static RefDocDisposition create(const QString &docDispositionCd, const QString &docDispositionNameEn, const QString &docDispositionNameZh, const QString &docDispositionDesc, const QString &createdBy, const QString &updatedBy);
    static RefDocDisposition create(const QVariantMap &values);
    static RefDocDisposition get(const QString &docDispositionCd);
    static int count();
    static QList<RefDocDisposition> getAll();

private:
    QSharedDataPointer<RefDocDispositionObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const RefDocDisposition &model);
    friend QDataStream &operator>>(QDataStream &ds, RefDocDisposition &model);
};

Q_DECLARE_METATYPE(RefDocDisposition)
Q_DECLARE_METATYPE(QList<RefDocDisposition>)

#endif // REFDOCDISPOSITION_H
