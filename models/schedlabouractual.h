#ifndef SCHEDLABOURACTUAL_H
#define SCHEDLABOURACTUAL_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class SchedLabourActualObject;
class UserApp;
class RefLabourRoleType;
class SchedLabour;


class T_MODEL_EXPORT SchedLabourActual : public TAbstractModel
{
public:
    SchedLabourActual();
    SchedLabourActual(const SchedLabourActual &other);
    SchedLabourActual(const SchedLabourActualObject &object);
    ~SchedLabourActual();

    int schedLabourId() const;
    void setSchedLabourId(int schedLabourId);
    QString labourRoleTypeCd() const;
    void setLabourRoleTypeCd(const QString &labourRoleTypeCd);
    int actualBy() const;
    void setActualBy(int actualBy);
    double adjustedBillingHr() const;
    void setAdjustedBillingHr(double adjustedBillingHr);
    QString labourTimeCd() const;
    void setLabourTimeCd(const QString &labourTimeCd);
    double labourCost() const;
    void setLabourCost(double labourCost);
    QDateTime actualStartDt() const;
    void setActualStartDt(const QDateTime &actualStartDt);
    QDateTime actualEndDt() const;
    void setActualEndDt(const QDateTime &actualEndDt);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    UserApp userAppByactualBy() const;
    RefLabourRoleType refLabourRoleTypeBylabourRoleTypeCd() const;
    SchedLabour schedLabourByschedLabourId() const;
    SchedLabourActual &operator=(const SchedLabourActual &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static SchedLabourActual create(int schedLabourId, const QString &labourRoleTypeCd, int actualBy, double adjustedBillingHr, const QString &labourTimeCd, double labourCost, const QDateTime &actualStartDt, const QDateTime &actualEndDt, const QString &createdBy, const QString &updatedBy);
    static SchedLabourActual create(const QVariantMap &values);
    static SchedLabourActual get(int schedLabourId, const QString &labourRoleTypeCd);
    static int count();
    static QList<SchedLabourActual> getAll();

private:
    QSharedDataPointer<SchedLabourActualObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const SchedLabourActual &model);
    friend QDataStream &operator>>(QDataStream &ds, SchedLabourActual &model);
};

Q_DECLARE_METATYPE(SchedLabourActual)
Q_DECLARE_METATYPE(QList<SchedLabourActual>)

#endif // SCHEDLABOURACTUAL_H
