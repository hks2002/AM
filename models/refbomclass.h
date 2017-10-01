#ifndef REFBOMCLASS_H
#define REFBOMCLASS_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class RefBomClassObject;


class T_MODEL_EXPORT RefBomClass : public TAbstractModel
{
public:
    RefBomClass();
    RefBomClass(const RefBomClass &other);
    RefBomClass(const RefBomClassObject &object);
    ~RefBomClass();

    QString bomClassCd() const;
    void setBomClassCd(const QString &bomClassCd);
    QString bomClassNameEn() const;
    void setBomClassNameEn(const QString &bomClassNameEn);
    QString bomClassNameZh() const;
    void setBomClassNameZh(const QString &bomClassNameZh);
    QString bomClassDesc() const;
    void setBomClassDesc(const QString &bomClassDesc);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    RefBomClass &operator=(const RefBomClass &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static RefBomClass create(const QString &bomClassCd, const QString &bomClassNameEn, const QString &bomClassNameZh, const QString &bomClassDesc, const QString &createdBy, const QString &updatedBy);
    static RefBomClass create(const QVariantMap &values);
    static RefBomClass get(const QString &bomClassCd);
    static int count();
    static QList<RefBomClass> getAll();

private:
    QSharedDataPointer<RefBomClassObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const RefBomClass &model);
    friend QDataStream &operator>>(QDataStream &ds, RefBomClass &model);
};

Q_DECLARE_METATYPE(RefBomClass)
Q_DECLARE_METATYPE(QList<RefBomClass>)

#endif // REFBOMCLASS_H
