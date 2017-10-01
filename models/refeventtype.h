#ifndef REFEVENTTYPE_H
#define REFEVENTTYPE_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class RefEventTypeObject;


class T_MODEL_EXPORT RefEventType : public TAbstractModel
{
public:
    RefEventType();
    RefEventType(const RefEventType &other);
    RefEventType(const RefEventTypeObject &object);
    ~RefEventType();

    QString eventTypeCd() const;
    void setEventTypeCd(const QString &eventTypeCd);
    QString eventTypeNameEn() const;
    void setEventTypeNameEn(const QString &eventTypeNameEn);
    QString eventTypeNameZh() const;
    void setEventTypeNameZh(const QString &eventTypeNameZh);
    QString eventTypeDesc() const;
    void setEventTypeDesc(const QString &eventTypeDesc);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    RefEventType &operator=(const RefEventType &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static RefEventType create(const QString &eventTypeCd, const QString &eventTypeNameEn, const QString &eventTypeNameZh, const QString &eventTypeDesc, const QString &createdBy, const QString &updatedBy);
    static RefEventType create(const QVariantMap &values);
    static RefEventType get(const QString &eventTypeCd);
    static int count();
    static QList<RefEventType> getAll();

private:
    QSharedDataPointer<RefEventTypeObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const RefEventType &model);
    friend QDataStream &operator>>(QDataStream &ds, RefEventType &model);
};

Q_DECLARE_METATYPE(RefEventType)
Q_DECLARE_METATYPE(QList<RefEventType>)

#endif // REFEVENTTYPE_H
