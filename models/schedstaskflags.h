#ifndef SCHEDSTASKFLAGS_H
#define SCHEDSTASKFLAGS_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class SchedStaskFlagsObject;
class SchedStask;


class T_MODEL_EXPORT SchedStaskFlags : public TAbstractModel
{
public:
    SchedStaskFlags();
    SchedStaskFlags(const SchedStaskFlags &other);
    SchedStaskFlags(const SchedStaskFlagsObject &object);
    ~SchedStaskFlags();

    int schedId() const;
    void setSchedId(int schedId);
    bool preventExeBool() const;
    void setPreventExeBool(bool preventExeBool);
    QDateTime preventExeReviewDt() const;
    void setPreventExeReviewDt(const QDateTime &preventExeReviewDt);
    bool etopsBool() const;
    void setEtopsBool(bool etopsBool);
    bool rvsmBool() const;
    void setRvsmBool(bool rvsmBool);
    bool recurBool() const;
    void setRecurBool(bool recurBool);
    bool corrFixBool() const;
    void setCorrFixBool(bool corrFixBool);
    bool orphanFrctBool() const;
    void setOrphanFrctBool(bool orphanFrctBool);
    bool partsReadyBool() const;
    void setPartsReadyBool(bool partsReadyBool);
    bool softDeadlineBool() const;
    void setSoftDeadlineBool(bool softDeadlineBool);
    bool routineBool() const;
    void setRoutineBool(bool routineBool);
    bool requestPartsBool() const;
    void setRequestPartsBool(bool requestPartsBool);
    bool resourceSumBool() const;
    void setResourceSumBool(bool resourceSumBool);
    bool toolsReadyBool() const;
    void setToolsReadyBool(bool toolsReadyBool);
    bool taskLockBool() const;
    void setTaskLockBool(bool taskLockBool);
    bool manualSchedBool() const;
    void setManualSchedBool(bool manualSchedBool);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    SchedStask schedStaskByschedId() const;
    SchedStaskFlags &operator=(const SchedStaskFlags &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static SchedStaskFlags create(int schedId, bool preventExeBool, const QDateTime &preventExeReviewDt, bool etopsBool, bool rvsmBool, bool recurBool, bool corrFixBool, bool orphanFrctBool, bool partsReadyBool, bool softDeadlineBool, bool routineBool, bool requestPartsBool, bool resourceSumBool, bool toolsReadyBool, bool taskLockBool, bool manualSchedBool, const QString &createdBy, const QString &updatedBy);
    static SchedStaskFlags create(const QVariantMap &values);
    static SchedStaskFlags get(int schedId);
    static int count();
    static QList<SchedStaskFlags> getAll();

private:
    QSharedDataPointer<SchedStaskFlagsObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const SchedStaskFlags &model);
    friend QDataStream &operator>>(QDataStream &ds, SchedStaskFlags &model);
};

Q_DECLARE_METATYPE(SchedStaskFlags)
Q_DECLARE_METATYPE(QList<SchedStaskFlags>)

#endif // SCHEDSTASKFLAGS_H
