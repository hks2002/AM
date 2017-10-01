#ifndef REFXACTIONTYPE_H
#define REFXACTIONTYPE_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class RefXactionTypeObject;


class T_MODEL_EXPORT RefXactionType : public TAbstractModel
{
public:
    RefXactionType();
    RefXactionType(const RefXactionType &other);
    RefXactionType(const RefXactionTypeObject &object);
    ~RefXactionType();

    QString xactionTypeCd() const;
    void setXactionTypeCd(const QString &xactionTypeCd);
    QString xactionTypeNameEn() const;
    void setXactionTypeNameEn(const QString &xactionTypeNameEn);
    QString xactionTypeNameZh() const;
    void setXactionTypeNameZh(const QString &xactionTypeNameZh);
    QString xactionTypeDesc() const;
    void setXactionTypeDesc(const QString &xactionTypeDesc);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    RefXactionType &operator=(const RefXactionType &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static RefXactionType create(const QString &xactionTypeCd, const QString &xactionTypeNameEn, const QString &xactionTypeNameZh, const QString &xactionTypeDesc, const QString &createdBy, const QString &updatedBy);
    static RefXactionType create(const QVariantMap &values);
    static RefXactionType get(const QString &xactionTypeCd);
    static int count();
    static QList<RefXactionType> getAll();

private:
    QSharedDataPointer<RefXactionTypeObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const RefXactionType &model);
    friend QDataStream &operator>>(QDataStream &ds, RefXactionType &model);
};

Q_DECLARE_METATYPE(RefXactionType)
Q_DECLARE_METATYPE(QList<RefXactionType>)

#endif // REFXACTIONTYPE_H
