#ifndef REFASSMBLCLASS_H
#define REFASSMBLCLASS_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class RefAssmblClassObject;


class T_MODEL_EXPORT RefAssmblClass : public TAbstractModel
{
public:
    RefAssmblClass();
    RefAssmblClass(const RefAssmblClass &other);
    RefAssmblClass(const RefAssmblClassObject &object);
    ~RefAssmblClass();

    QString assmblClassCd() const;
    void setAssmblClassCd(const QString &assmblClassCd);
    QString assmblClassNameEn() const;
    void setAssmblClassNameEn(const QString &assmblClassNameEn);
    QString assmblClassNameZh() const;
    void setAssmblClassNameZh(const QString &assmblClassNameZh);
    QString assmblClassDesc() const;
    void setAssmblClassDesc(const QString &assmblClassDesc);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    RefAssmblClass &operator=(const RefAssmblClass &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static RefAssmblClass create(const QString &assmblClassCd, const QString &assmblClassNameEn, const QString &assmblClassNameZh, const QString &assmblClassDesc, const QString &createdBy, const QString &updatedBy);
    static RefAssmblClass create(const QVariantMap &values);
    static RefAssmblClass get(const QString &assmblClassCd);
    static int count();
    static QList<RefAssmblClass> getAll();

private:
    QSharedDataPointer<RefAssmblClassObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const RefAssmblClass &model);
    friend QDataStream &operator>>(QDataStream &ds, RefAssmblClass &model);
};

Q_DECLARE_METATYPE(RefAssmblClass)
Q_DECLARE_METATYPE(QList<RefAssmblClass>)

#endif // REFASSMBLCLASS_H
