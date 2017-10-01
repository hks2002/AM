#ifndef REFFLIGHTLEGSTATUS_H
#define REFFLIGHTLEGSTATUS_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class RefFlightLegStatusObject;


class T_MODEL_EXPORT RefFlightLegStatus : public TAbstractModel
{
public:
    RefFlightLegStatus();
    RefFlightLegStatus(const RefFlightLegStatus &other);
    RefFlightLegStatus(const RefFlightLegStatusObject &object);
    ~RefFlightLegStatus();

    QString flightLegStatusCd() const;
    void setFlightLegStatusCd(const QString &flightLegStatusCd);
    QString flightLegStatusNameEn() const;
    void setFlightLegStatusNameEn(const QString &flightLegStatusNameEn);
    QString flightLegStatusNameZh() const;
    void setFlightLegStatusNameZh(const QString &flightLegStatusNameZh);
    QString flightLegStatusDesc() const;
    void setFlightLegStatusDesc(const QString &flightLegStatusDesc);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    RefFlightLegStatus &operator=(const RefFlightLegStatus &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static RefFlightLegStatus create(const QString &flightLegStatusCd, const QString &flightLegStatusNameEn, const QString &flightLegStatusNameZh, const QString &flightLegStatusDesc, const QString &createdBy, const QString &updatedBy);
    static RefFlightLegStatus create(const QVariantMap &values);
    static RefFlightLegStatus get(const QString &flightLegStatusCd);
    static int count();
    static QList<RefFlightLegStatus> getAll();

private:
    QSharedDataPointer<RefFlightLegStatusObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const RefFlightLegStatus &model);
    friend QDataStream &operator>>(QDataStream &ds, RefFlightLegStatus &model);
};

Q_DECLARE_METATYPE(RefFlightLegStatus)
Q_DECLARE_METATYPE(QList<RefFlightLegStatus>)

#endif // REFFLIGHTLEGSTATUS_H
