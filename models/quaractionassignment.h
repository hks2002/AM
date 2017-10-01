#ifndef QUARACTIONASSIGNMENT_H
#define QUARACTIONASSIGNMENT_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class QuarActionAssignmentObject;
class UserApp;
class QuarQuar;
class QuarAction;


class T_MODEL_EXPORT QuarActionAssignment : public TAbstractModel
{
public:
    QuarActionAssignment();
    QuarActionAssignment(const QuarActionAssignment &other);
    QuarActionAssignment(const QuarActionAssignmentObject &object);
    ~QuarActionAssignment();

    int quarActionId() const;
    void setQuarActionId(int quarActionId);
    int quarId() const;
    void setQuarId(int quarId);
    bool assignedBool() const;
    void setAssignedBool(bool assignedBool);
    QDateTime assignedDt() const;
    void setAssignedDt(const QDateTime &assignedDt);
    int userId() const;
    void setUserId(int userId);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    UserApp userAppByuserId() const;
    QuarQuar quarQuarByquarId() const;
    QuarAction quarActionByquarActionId() const;
    QuarActionAssignment &operator=(const QuarActionAssignment &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static QuarActionAssignment create(int quarActionId, int quarId, bool assignedBool, const QDateTime &assignedDt, int userId, const QString &createdBy, const QString &updatedBy);
    static QuarActionAssignment create(const QVariantMap &values);
    static QuarActionAssignment get(int quarActionId, int quarId);
    static int count();
    static QList<QuarActionAssignment> getAll();

private:
    QSharedDataPointer<QuarActionAssignmentObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const QuarActionAssignment &model);
    friend QDataStream &operator>>(QDataStream &ds, QuarActionAssignment &model);
};

Q_DECLARE_METATYPE(QuarActionAssignment)
Q_DECLARE_METATYPE(QList<QuarActionAssignment>)

#endif // QUARACTIONASSIGNMENT_H
