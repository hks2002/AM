#ifndef REFINVCLASS_H
#define REFINVCLASS_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class RefInvClassObject;


class T_MODEL_EXPORT RefInvClass : public TAbstractModel
{
public:
    RefInvClass();
    RefInvClass(const RefInvClass &other);
    RefInvClass(const RefInvClassObject &object);
    ~RefInvClass();

    QString invClassCd() const;
    void setInvClassCd(const QString &invClassCd);
    QString invClassNameEn() const;
    void setInvClassNameEn(const QString &invClassNameEn);
    QString invClassNameZh() const;
    void setInvClassNameZh(const QString &invClassNameZh);
    QString invClassDesc() const;
    void setInvClassDesc(const QString &invClassDesc);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    RefInvClass &operator=(const RefInvClass &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static RefInvClass create(const QString &invClassCd, const QString &invClassNameEn, const QString &invClassNameZh, const QString &invClassDesc, const QString &createdBy, const QString &updatedBy);
    static RefInvClass create(const QVariantMap &values);
    static RefInvClass get(const QString &invClassCd);
    static int count();
    static QList<RefInvClass> getAll();

private:
    QSharedDataPointer<RefInvClassObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const RefInvClass &model);
    friend QDataStream &operator>>(QDataStream &ds, RefInvClass &model);
};

Q_DECLARE_METATYPE(RefInvClass)
Q_DECLARE_METATYPE(QList<RefInvClass>)

#endif // REFINVCLASS_H
