#ifndef SCHEDLABOURSCHED_H
#define SCHEDLABOURSCHED_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class SchedLabourSchedObject;
class RefLabourRoleStatus;
class UserApp;
class RefLabourRoleType;
class SchedLabour;


class T_MODEL_EXPORT SchedLabourSched : public TAbstractModel
{
public:
    SchedLabourSched();
    SchedLabourSched(const SchedLabourSched &other);
    SchedLabourSched(const SchedLabourSchedObject &object);
    ~SchedLabourSched();

    int schedLabourId() const;
    void setSchedLabourId(int schedLabourId);
    QString labourRoleTypeCd() const;
    void setLabourRoleTypeCd(const QString &labourRoleTypeCd);
    int schedTo() const;
    void setSchedTo(int schedTo);
    QString labourRoleStatusCd() const;
    void setLabourRoleStatusCd(const QString &labourRoleStatusCd);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    RefLabourRoleStatus refLabourRoleStatusBylabourRoleStatusCd() const;
    UserApp userAppByschedTo() const;
    RefLabourRoleType refLabourRoleTypeBylabourRoleTypeCd() const;
    SchedLabour schedLabourByschedLabourId() const;
    SchedLabourSched &operator=(const SchedLabourSched &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static SchedLabourSched create(int schedLabourId, const QString &labourRoleTypeCd, int schedTo, const QString &labourRoleStatusCd, const QString &createdBy, const QString &updatedBy);
    static SchedLabourSched create(const QVariantMap &values);
    static SchedLabourSched get(int schedLabourId, const QString &labourRoleTypeCd);
    static int count();
    static QList<SchedLabourSched> getAll();

private:
    QSharedDataPointer<SchedLabourSchedObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const SchedLabourSched &model);
    friend QDataStream &operator>>(QDataStream &ds, SchedLabourSched &model);
};

Q_DECLARE_METATYPE(SchedLabourSched)
Q_DECLARE_METATYPE(QList<SchedLabourSched>)

#endif // SCHEDLABOURSCHED_H
