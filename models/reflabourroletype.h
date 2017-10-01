#ifndef REFLABOURROLETYPE_H
#define REFLABOURROLETYPE_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class RefLabourRoleTypeObject;


class T_MODEL_EXPORT RefLabourRoleType : public TAbstractModel
{
public:
    RefLabourRoleType();
    RefLabourRoleType(const RefLabourRoleType &other);
    RefLabourRoleType(const RefLabourRoleTypeObject &object);
    ~RefLabourRoleType();

    QString labourRoleTypeCd() const;
    void setLabourRoleTypeCd(const QString &labourRoleTypeCd);
    QString labourRoleTypeNameEn() const;
    void setLabourRoleTypeNameEn(const QString &labourRoleTypeNameEn);
    QString labourRoleTypeNameZh() const;
    void setLabourRoleTypeNameZh(const QString &labourRoleTypeNameZh);
    QString labourRoleTypeDesc() const;
    void setLabourRoleTypeDesc(const QString &labourRoleTypeDesc);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    RefLabourRoleType &operator=(const RefLabourRoleType &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static RefLabourRoleType create(const QString &labourRoleTypeCd, const QString &labourRoleTypeNameEn, const QString &labourRoleTypeNameZh, const QString &labourRoleTypeDesc, const QString &createdBy, const QString &updatedBy);
    static RefLabourRoleType create(const QVariantMap &values);
    static RefLabourRoleType get(const QString &labourRoleTypeCd);
    static int count();
    static QList<RefLabourRoleType> getAll();

private:
    QSharedDataPointer<RefLabourRoleTypeObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const RefLabourRoleType &model);
    friend QDataStream &operator>>(QDataStream &ds, RefLabourRoleType &model);
};

Q_DECLARE_METATYPE(RefLabourRoleType)
Q_DECLARE_METATYPE(QList<RefLabourRoleType>)

#endif // REFLABOURROLETYPE_H
