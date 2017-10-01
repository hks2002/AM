#ifndef REFEVENTREASON_H
#define REFEVENTREASON_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class RefEventReasonObject;


class T_MODEL_EXPORT RefEventReason : public TAbstractModel
{
public:
    RefEventReason();
    RefEventReason(const RefEventReason &other);
    RefEventReason(const RefEventReasonObject &object);
    ~RefEventReason();

    QString eventReasonCd() const;
    void setEventReasonCd(const QString &eventReasonCd);
    QString eventReasonNameEn() const;
    void setEventReasonNameEn(const QString &eventReasonNameEn);
    QString eventReasonNameZh() const;
    void setEventReasonNameZh(const QString &eventReasonNameZh);
    QString eventReasonDesc() const;
    void setEventReasonDesc(const QString &eventReasonDesc);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    RefEventReason &operator=(const RefEventReason &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static RefEventReason create(const QString &eventReasonCd, const QString &eventReasonNameEn, const QString &eventReasonNameZh, const QString &eventReasonDesc, const QString &createdBy, const QString &updatedBy);
    static RefEventReason create(const QVariantMap &values);
    static RefEventReason get(const QString &eventReasonCd);
    static int count();
    static QList<RefEventReason> getAll();

private:
    QSharedDataPointer<RefEventReasonObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const RefEventReason &model);
    friend QDataStream &operator>>(QDataStream &ds, RefEventReason &model);
};

Q_DECLARE_METATYPE(RefEventReason)
Q_DECLARE_METATYPE(QList<RefEventReason>)

#endif // REFEVENTREASON_H
