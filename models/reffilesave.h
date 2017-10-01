#ifndef REFFILESAVE_H
#define REFFILESAVE_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class RefFileSaveObject;


class T_MODEL_EXPORT RefFileSave : public TAbstractModel
{
public:
    RefFileSave();
    RefFileSave(const RefFileSave &other);
    RefFileSave(const RefFileSaveObject &object);
    ~RefFileSave();

    QString fileSaveCd() const;
    void setFileSaveCd(const QString &fileSaveCd);
    QString fileSaveNameZh() const;
    void setFileSaveNameZh(const QString &fileSaveNameZh);
    QString fileSaveNameEn() const;
    void setFileSaveNameEn(const QString &fileSaveNameEn);
    QString fileSaveDesc() const;
    void setFileSaveDesc(const QString &fileSaveDesc);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    RefFileSave &operator=(const RefFileSave &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static RefFileSave create(const QString &fileSaveCd, const QString &fileSaveNameZh, const QString &fileSaveNameEn, const QString &fileSaveDesc, const QString &createdBy, const QString &updatedBy);
    static RefFileSave create(const QVariantMap &values);
    static RefFileSave get(const QString &fileSaveCd);
    static int count();
    static QList<RefFileSave> getAll();

private:
    QSharedDataPointer<RefFileSaveObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const RefFileSave &model);
    friend QDataStream &operator>>(QDataStream &ds, RefFileSave &model);
};

Q_DECLARE_METATYPE(RefFileSave)
Q_DECLARE_METATYPE(QList<RefFileSave>)

#endif // REFFILESAVE_H
