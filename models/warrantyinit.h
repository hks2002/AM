#ifndef WARRANTYINIT_H
#define WARRANTYINIT_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class WarrantyInitObject;
class RefWarrantyPriority;
class WarrantyDefn;


class T_MODEL_EXPORT WarrantyInit : public TAbstractModel
{
public:
    WarrantyInit();
    WarrantyInit(const WarrantyInit &other);
    WarrantyInit(const WarrantyInitObject &object);
    ~WarrantyInit();

    int warrantyInitId() const;
    int warrantyDefnId() const;
    void setWarrantyDefnId(int warrantyDefnId);
    QString warrantyPriorityCd() const;
    void setWarrantyPriorityCd(const QString &warrantyPriorityCd);
    bool expiresFirstBool() const;
    void setExpiresFirstBool(bool expiresFirstBool);
    QDateTime startDt() const;
    void setStartDt(const QDateTime &startDt);
    QDateTime endDt() const;
    void setEndDt(const QDateTime &endDt);
    double startTsnHoursQt() const;
    void setStartTsnHoursQt(double startTsnHoursQt);
    double endTsnHoursQt() const;
    void setEndTsnHoursQt(double endTsnHoursQt);
    int startTsnCyclesQt() const;
    void setStartTsnCyclesQt(int startTsnCyclesQt);
    int endTsnCyclesQt() const;
    void setEndTsnCyclesQt(int endTsnCyclesQt);
    bool expiredBool() const;
    void setExpiredBool(bool expiredBool);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    RefWarrantyPriority refWarrantyPriorityBywarrantyPriorityCd() const;
    WarrantyDefn warrantyDefnBywarrantyDefnId() const;
    WarrantyInit &operator=(const WarrantyInit &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static WarrantyInit create(int warrantyDefnId, const QString &warrantyPriorityCd, bool expiresFirstBool, const QDateTime &startDt, const QDateTime &endDt, double startTsnHoursQt, double endTsnHoursQt, int startTsnCyclesQt, int endTsnCyclesQt, bool expiredBool, const QString &createdBy, const QString &updatedBy);
    static WarrantyInit create(const QVariantMap &values);
    static WarrantyInit get(int warrantyInitId);
    static int count();
    static QList<WarrantyInit> getAll();

private:
    QSharedDataPointer<WarrantyInitObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const WarrantyInit &model);
    friend QDataStream &operator>>(QDataStream &ds, WarrantyInit &model);
};

Q_DECLARE_METATYPE(WarrantyInit)
Q_DECLARE_METATYPE(QList<WarrantyInit>)

#endif // WARRANTYINIT_H
