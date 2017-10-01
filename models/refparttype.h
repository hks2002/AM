#ifndef REFPARTTYPE_H
#define REFPARTTYPE_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class RefPartTypeObject;


class T_MODEL_EXPORT RefPartType : public TAbstractModel
{
public:
    RefPartType();
    RefPartType(const RefPartType &other);
    RefPartType(const RefPartTypeObject &object);
    ~RefPartType();

    QString partTypeCd() const;
    void setPartTypeCd(const QString &partTypeCd);
    QString partTypeNameEn() const;
    void setPartTypeNameEn(const QString &partTypeNameEn);
    QString partTypeNameZh() const;
    void setPartTypeNameZh(const QString &partTypeNameZh);
    QString partTypeDesc() const;
    void setPartTypeDesc(const QString &partTypeDesc);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    RefPartType &operator=(const RefPartType &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static RefPartType create(const QString &partTypeCd, const QString &partTypeNameEn, const QString &partTypeNameZh, const QString &partTypeDesc, const QString &createdBy, const QString &updatedBy);
    static RefPartType create(const QVariantMap &values);
    static RefPartType get(const QString &partTypeCd);
    static int count();
    static QList<RefPartType> getAll();

private:
    QSharedDataPointer<RefPartTypeObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const RefPartType &model);
    friend QDataStream &operator>>(QDataStream &ds, RefPartType &model);
};

Q_DECLARE_METATYPE(RefPartType)
Q_DECLARE_METATYPE(QList<RefPartType>)

#endif // REFPARTTYPE_H
