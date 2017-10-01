#ifndef REFMESURTYPE_H
#define REFMESURTYPE_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class RefMesurTypeObject;


class T_MODEL_EXPORT RefMesurType : public TAbstractModel
{
public:
    RefMesurType();
    RefMesurType(const RefMesurType &other);
    RefMesurType(const RefMesurTypeObject &object);
    ~RefMesurType();

    QString mesurTypeCd() const;
    void setMesurTypeCd(const QString &mesurTypeCd);
    QString mesurTypeNameEn() const;
    void setMesurTypeNameEn(const QString &mesurTypeNameEn);
    QString mesurTypeNameZh() const;
    void setMesurTypeNameZh(const QString &mesurTypeNameZh);
    QString mesurTypeDesc() const;
    void setMesurTypeDesc(const QString &mesurTypeDesc);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    RefMesurType &operator=(const RefMesurType &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static RefMesurType create(const QString &mesurTypeCd, const QString &mesurTypeNameEn, const QString &mesurTypeNameZh, const QString &mesurTypeDesc, const QString &createdBy, const QString &updatedBy);
    static RefMesurType create(const QVariantMap &values);
    static RefMesurType get(const QString &mesurTypeCd);
    static int count();
    static QList<RefMesurType> getAll();

private:
    QSharedDataPointer<RefMesurTypeObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const RefMesurType &model);
    friend QDataStream &operator>>(QDataStream &ds, RefMesurType &model);
};

Q_DECLARE_METATYPE(RefMesurType)
Q_DECLARE_METATYPE(QList<RefMesurType>)

#endif // REFMESURTYPE_H
