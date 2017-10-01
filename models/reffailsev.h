#ifndef REFFAILSEV_H
#define REFFAILSEV_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class RefFailSevObject;


class T_MODEL_EXPORT RefFailSev : public TAbstractModel
{
public:
    RefFailSev();
    RefFailSev(const RefFailSev &other);
    RefFailSev(const RefFailSevObject &object);
    ~RefFailSev();

    QString failSevCd() const;
    void setFailSevCd(const QString &failSevCd);
    QString failSevNameEn() const;
    void setFailSevNameEn(const QString &failSevNameEn);
    QString failSevNameZh() const;
    void setFailSevNameZh(const QString &failSevNameZh);
    QString failSevDesc() const;
    void setFailSevDesc(const QString &failSevDesc);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    RefFailSev &operator=(const RefFailSev &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static RefFailSev create(const QString &failSevCd, const QString &failSevNameEn, const QString &failSevNameZh, const QString &failSevDesc, const QString &createdBy, const QString &updatedBy);
    static RefFailSev create(const QVariantMap &values);
    static RefFailSev get(const QString &failSevCd);
    static int count();
    static QList<RefFailSev> getAll();

private:
    QSharedDataPointer<RefFailSevObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const RefFailSev &model);
    friend QDataStream &operator>>(QDataStream &ds, RefFailSev &model);
};

Q_DECLARE_METATYPE(RefFailSev)
Q_DECLARE_METATYPE(QList<RefFailSev>)

#endif // REFFAILSEV_H
