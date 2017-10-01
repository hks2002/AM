#ifndef REFREQTYPE_H
#define REFREQTYPE_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class RefReqTypeObject;


class T_MODEL_EXPORT RefReqType : public TAbstractModel
{
public:
    RefReqType();
    RefReqType(const RefReqType &other);
    RefReqType(const RefReqTypeObject &object);
    ~RefReqType();

    QString reqTypeCd() const;
    void setReqTypeCd(const QString &reqTypeCd);
    QString reqTypeNameEn() const;
    void setReqTypeNameEn(const QString &reqTypeNameEn);
    QString reqTypeNameZh() const;
    void setReqTypeNameZh(const QString &reqTypeNameZh);
    QString reqTypeDesc() const;
    void setReqTypeDesc(const QString &reqTypeDesc);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    RefReqType &operator=(const RefReqType &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static RefReqType create(const QString &reqTypeCd, const QString &reqTypeNameEn, const QString &reqTypeNameZh, const QString &reqTypeDesc, const QString &createdBy, const QString &updatedBy);
    static RefReqType create(const QVariantMap &values);
    static RefReqType get(const QString &reqTypeCd);
    static int count();
    static QList<RefReqType> getAll();

private:
    QSharedDataPointer<RefReqTypeObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const RefReqType &model);
    friend QDataStream &operator>>(QDataStream &ds, RefReqType &model);
};

Q_DECLARE_METATYPE(RefReqType)
Q_DECLARE_METATYPE(QList<RefReqType>)

#endif // REFREQTYPE_H
