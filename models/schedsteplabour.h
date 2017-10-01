#ifndef SCHEDSTEPLABOUR_H
#define SCHEDSTEPLABOUR_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class SchedStepLabourObject;
class UserApp;
class RefLabourRoleType;
class SchedStep;


class T_MODEL_EXPORT SchedStepLabour : public TAbstractModel
{
public:
    SchedStepLabour();
    SchedStepLabour(const SchedStepLabour &other);
    SchedStepLabour(const SchedStepLabourObject &object);
    ~SchedStepLabour();

    int stepId() const;
    void setStepId(int stepId);
    QString labourRoleTypeCd() const;
    void setLabourRoleTypeCd(const QString &labourRoleTypeCd);
    int actualBy() const;
    void setActualBy(int actualBy);
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
    SchedStep schedStepBystepId() const;
    SchedStepLabour &operator=(const SchedStepLabour &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static SchedStepLabour create(int stepId, const QString &labourRoleTypeCd, int actualBy, const QDateTime &actualStartDt, const QDateTime &actualEndDt, const QString &createdBy, const QString &updatedBy);
    static SchedStepLabour create(const QVariantMap &values);
    static SchedStepLabour get(int stepId, const QString &labourRoleTypeCd);
    static int count();
    static QList<SchedStepLabour> getAll();

private:
    QSharedDataPointer<SchedStepLabourObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const SchedStepLabour &model);
    friend QDataStream &operator>>(QDataStream &ds, SchedStepLabour &model);
};

Q_DECLARE_METATYPE(SchedStepLabour)
Q_DECLARE_METATYPE(QList<SchedStepLabour>)

#endif // SCHEDSTEPLABOUR_H
