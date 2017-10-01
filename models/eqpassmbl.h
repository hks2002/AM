#ifndef EQPASSMBL_H
#define EQPASSMBL_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class EqpAssmblObject;
class RefAssmblClass;


class T_MODEL_EXPORT EqpAssmbl : public TAbstractModel
{
public:
    EqpAssmbl();
    EqpAssmbl(const EqpAssmbl &other);
    EqpAssmbl(const EqpAssmblObject &object);
    ~EqpAssmbl();

    int assmblId() const;
    QString assmblCd() const;
    void setAssmblCd(const QString &assmblCd);
    QString assmblClassCd() const;
    void setAssmblClassCd(const QString &assmblClassCd);
    QString assmblName() const;
    void setAssmblName(const QString &assmblName);
    QString assmblDesc() const;
    void setAssmblDesc(const QString &assmblDesc);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    RefAssmblClass refAssmblClassByassmblClassCd() const;
    EqpAssmbl &operator=(const EqpAssmbl &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static EqpAssmbl create(const QString &assmblCd, const QString &assmblClassCd, const QString &assmblName, const QString &assmblDesc, const QString &createdBy, const QString &updatedBy);
    static EqpAssmbl create(const QVariantMap &values);
    static EqpAssmbl get(int assmblId);
    static int count();
    static QList<EqpAssmbl> getAll();

private:
    QSharedDataPointer<EqpAssmblObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const EqpAssmbl &model);
    friend QDataStream &operator>>(QDataStream &ds, EqpAssmbl &model);
};

Q_DECLARE_METATYPE(EqpAssmbl)
Q_DECLARE_METATYPE(QList<EqpAssmbl>)

#endif // EQPASSMBL_H
