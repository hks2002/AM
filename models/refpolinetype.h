#ifndef REFPOLINETYPE_H
#define REFPOLINETYPE_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class RefPoLineTypeObject;


class T_MODEL_EXPORT RefPoLineType : public TAbstractModel
{
public:
    RefPoLineType();
    RefPoLineType(const RefPoLineType &other);
    RefPoLineType(const RefPoLineTypeObject &object);
    ~RefPoLineType();

    QString poLineTypeCd() const;
    void setPoLineTypeCd(const QString &poLineTypeCd);
    QString poLineTypeNameEn() const;
    void setPoLineTypeNameEn(const QString &poLineTypeNameEn);
    QString poLineTypeNameZh() const;
    void setPoLineTypeNameZh(const QString &poLineTypeNameZh);
    QString poLineTypeDesc() const;
    void setPoLineTypeDesc(const QString &poLineTypeDesc);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    RefPoLineType &operator=(const RefPoLineType &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static RefPoLineType create(const QString &poLineTypeCd, const QString &poLineTypeNameEn, const QString &poLineTypeNameZh, const QString &poLineTypeDesc, const QString &createdBy, const QString &updatedBy);
    static RefPoLineType create(const QVariantMap &values);
    static RefPoLineType get(const QString &poLineTypeCd);
    static int count();
    static QList<RefPoLineType> getAll();

private:
    QSharedDataPointer<RefPoLineTypeObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const RefPoLineType &model);
    friend QDataStream &operator>>(QDataStream &ds, RefPoLineType &model);
};

Q_DECLARE_METATYPE(RefPoLineType)
Q_DECLARE_METATYPE(QList<RefPoLineType>)

#endif // REFPOLINETYPE_H
