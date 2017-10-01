#ifndef REGBODY_H
#define REGBODY_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class RegBodyObject;


class T_MODEL_EXPORT RegBody : public TAbstractModel
{
public:
    RegBody();
    RegBody(const RegBody &other);
    RegBody(const RegBodyObject &object);
    ~RegBody();

    int regBodyId() const;
    QString regBodyCd() const;
    void setRegBodyCd(const QString &regBodyCd);
    QString regBodyNameZh() const;
    void setRegBodyNameZh(const QString &regBodyNameZh);
    QString regBodyNameEn() const;
    void setRegBodyNameEn(const QString &regBodyNameEn);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    RegBody &operator=(const RegBody &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static RegBody create(const QString &regBodyCd, const QString &regBodyNameZh, const QString &regBodyNameEn, const QString &createdBy, const QString &updatedBy);
    static RegBody create(const QVariantMap &values);
    static RegBody get(int regBodyId);
    static int count();
    static QList<RegBody> getAll();

private:
    QSharedDataPointer<RegBodyObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const RegBody &model);
    friend QDataStream &operator>>(QDataStream &ds, RegBody &model);
};

Q_DECLARE_METATYPE(RegBody)
Q_DECLARE_METATYPE(QList<RegBody>)

#endif // REGBODY_H
