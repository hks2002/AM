#ifndef REFADVSRYTYPE_H
#define REFADVSRYTYPE_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class RefAdvsryTypeObject;


class T_MODEL_EXPORT RefAdvsryType : public TAbstractModel
{
public:
    RefAdvsryType();
    RefAdvsryType(const RefAdvsryType &other);
    RefAdvsryType(const RefAdvsryTypeObject &object);
    ~RefAdvsryType();

    QString advsryTypeCd() const;
    void setAdvsryTypeCd(const QString &advsryTypeCd);
    QString advsryTypeNameEn() const;
    void setAdvsryTypeNameEn(const QString &advsryTypeNameEn);
    QString advsryTypeNameZh() const;
    void setAdvsryTypeNameZh(const QString &advsryTypeNameZh);
    QString advsryTypeDesc() const;
    void setAdvsryTypeDesc(const QString &advsryTypeDesc);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    RefAdvsryType &operator=(const RefAdvsryType &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static RefAdvsryType create(const QString &advsryTypeCd, const QString &advsryTypeNameEn, const QString &advsryTypeNameZh, const QString &advsryTypeDesc, const QString &createdBy, const QString &updatedBy);
    static RefAdvsryType create(const QVariantMap &values);
    static RefAdvsryType get(const QString &advsryTypeCd);
    static int count();
    static QList<RefAdvsryType> getAll();

private:
    QSharedDataPointer<RefAdvsryTypeObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const RefAdvsryType &model);
    friend QDataStream &operator>>(QDataStream &ds, RefAdvsryType &model);
};

Q_DECLARE_METATYPE(RefAdvsryType)
Q_DECLARE_METATYPE(QList<RefAdvsryType>)

#endif // REFADVSRYTYPE_H
