#ifndef EVTDEPT_H
#define EVTDEPT_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class EvtDeptObject;
class Dept;
class EvtEvent;


class T_MODEL_EXPORT EvtDept : public TAbstractModel
{
public:
    EvtDept();
    EvtDept(const EvtDept &other);
    EvtDept(const EvtDeptObject &object);
    ~EvtDept();

    int eventId() const;
    void setEventId(int eventId);
    int deptId() const;
    void setDeptId(int deptId);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    Dept deptBydeptId() const;
    EvtEvent evtEventByeventId() const;
    EvtDept &operator=(const EvtDept &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static EvtDept create(int eventId, int deptId, const QString &createdBy, const QString &updatedBy);
    static EvtDept create(const QVariantMap &values);
    static EvtDept get(int eventId, int deptId);
    static int count();
    static QList<EvtDept> getAll();

private:
    QSharedDataPointer<EvtDeptObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const EvtDept &model);
    friend QDataStream &operator>>(QDataStream &ds, EvtDept &model);
};

Q_DECLARE_METATYPE(EvtDept)
Q_DECLARE_METATYPE(QList<EvtDept>)

#endif // EVTDEPT_H
