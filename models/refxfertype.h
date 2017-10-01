#ifndef REFXFERTYPE_H
#define REFXFERTYPE_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class RefXferTypeObject;


class T_MODEL_EXPORT RefXferType : public TAbstractModel
{
public:
    RefXferType();
    RefXferType(const RefXferType &other);
    RefXferType(const RefXferTypeObject &object);
    ~RefXferType();

    QString xferTypeCd() const;
    void setXferTypeCd(const QString &xferTypeCd);
    QString xferTypeNameEn() const;
    void setXferTypeNameEn(const QString &xferTypeNameEn);
    QString xferTypeNameZh() const;
    void setXferTypeNameZh(const QString &xferTypeNameZh);
    QString xferTypeDesc() const;
    void setXferTypeDesc(const QString &xferTypeDesc);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    RefXferType &operator=(const RefXferType &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static RefXferType create(const QString &xferTypeCd, const QString &xferTypeNameEn, const QString &xferTypeNameZh, const QString &xferTypeDesc, const QString &createdBy, const QString &updatedBy);
    static RefXferType create(const QVariantMap &values);
    static RefXferType get(const QString &xferTypeCd);
    static int count();
    static QList<RefXferType> getAll();

private:
    QSharedDataPointer<RefXferTypeObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const RefXferType &model);
    friend QDataStream &operator>>(QDataStream &ds, RefXferType &model);
};

Q_DECLARE_METATYPE(RefXferType)
Q_DECLARE_METATYPE(QList<RefXferType>)

#endif // REFXFERTYPE_H
