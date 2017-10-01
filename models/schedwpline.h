#ifndef SCHEDWPLINE_H
#define SCHEDWPLINE_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class SchedWpLineObject;
class UserApp;
class SchedStask;
class SchedWp;


class T_MODEL_EXPORT SchedWpLine : public TAbstractModel
{
public:
    SchedWpLine();
    SchedWpLine(const SchedWpLine &other);
    SchedWpLine(const SchedWpLineObject &object);
    ~SchedWpLine();

    int schedWpId() const;
    void setSchedWpId(int schedWpId);
    int schedId() const;
    void setSchedId(int schedId);
    int workscopeOrder() const;
    void setWorkscopeOrder(int workscopeOrder);
    QString vendorLineNo() const;
    void setVendorLineNo(const QString &vendorLineNo);
    bool unassignBool() const;
    void setUnassignBool(bool unassignBool);
    QDateTime assignDt() const;
    void setAssignDt(const QDateTime &assignDt);
    int assignBy() const;
    void setAssignBy(int assignBy);
    QDateTime unassignDt() const;
    void setUnassignDt(const QDateTime &unassignDt);
    int unassignBy() const;
    void setUnassignBy(int unassignBy);
    bool collectedBool() const;
    void setCollectedBool(bool collectedBool);
    int collectedBy() const;
    void setCollectedBy(int collectedBy);
    QDateTime collectedDt() const;
    void setCollectedDt(const QDateTime &collectedDt);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    UserApp userAppBycollectedBy() const;
    SchedStask schedStaskByschedId() const;
    SchedWp schedWpByschedWpId() const;
    SchedWpLine &operator=(const SchedWpLine &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static SchedWpLine create(int schedWpId, int schedId, int workscopeOrder, const QString &vendorLineNo, bool unassignBool, const QDateTime &assignDt, int assignBy, const QDateTime &unassignDt, int unassignBy, bool collectedBool, int collectedBy, const QDateTime &collectedDt, const QString &createdBy, const QString &updatedBy);
    static SchedWpLine create(const QVariantMap &values);
    static SchedWpLine get(int schedWpId, int schedId);
    static int count();
    static QList<SchedWpLine> getAll();

private:
    QSharedDataPointer<SchedWpLineObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const SchedWpLine &model);
    friend QDataStream &operator>>(QDataStream &ds, SchedWpLine &model);
};

Q_DECLARE_METATYPE(SchedWpLine)
Q_DECLARE_METATYPE(QList<SchedWpLine>)

#endif // SCHEDWPLINE_H
