#ifndef REFPOTYPE_H
#define REFPOTYPE_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class RefPoTypeObject;


class T_MODEL_EXPORT RefPoType : public TAbstractModel
{
public:
    RefPoType();
    RefPoType(const RefPoType &other);
    RefPoType(const RefPoTypeObject &object);
    ~RefPoType();

    QString poTypeCd() const;
    void setPoTypeCd(const QString &poTypeCd);
    QString poTypeNameEn() const;
    void setPoTypeNameEn(const QString &poTypeNameEn);
    QString poTypeNameZh() const;
    void setPoTypeNameZh(const QString &poTypeNameZh);
    QString poTypeDesc() const;
    void setPoTypeDesc(const QString &poTypeDesc);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    RefPoType &operator=(const RefPoType &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static RefPoType create(const QString &poTypeCd, const QString &poTypeNameEn, const QString &poTypeNameZh, const QString &poTypeDesc, const QString &createdBy, const QString &updatedBy);
    static RefPoType create(const QVariantMap &values);
    static RefPoType get(const QString &poTypeCd);
    static int count();
    static QList<RefPoType> getAll();

private:
    QSharedDataPointer<RefPoTypeObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const RefPoType &model);
    friend QDataStream &operator>>(QDataStream &ds, RefPoType &model);
};

Q_DECLARE_METATYPE(RefPoType)
Q_DECLARE_METATYPE(QList<RefPoType>)

#endif // REFPOTYPE_H
