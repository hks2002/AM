#ifndef USERSKILL_H
#define USERSKILL_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class UserSkillObject;
class LabourSkill;
class UserApp;


class T_MODEL_EXPORT UserSkill : public TAbstractModel
{
public:
    UserSkill();
    UserSkill(const UserSkill &other);
    UserSkill(const UserSkillObject &object);
    ~UserSkill();

    int userId() const;
    void setUserId(int userId);
    int labourSkillId() const;
    void setLabourSkillId(int labourSkillId);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    LabourSkill labourSkillBylabourSkillId() const;
    UserApp userAppByuserId() const;
    UserSkill &operator=(const UserSkill &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static UserSkill create(int userId, int labourSkillId, const QString &createdBy, const QString &updatedBy);
    static UserSkill create(const QVariantMap &values);
    static UserSkill get(int userId, int labourSkillId);
    static int count();
    static QList<UserSkill> getAll();

private:
    QSharedDataPointer<UserSkillObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const UserSkill &model);
    friend QDataStream &operator>>(QDataStream &ds, UserSkill &model);
};

Q_DECLARE_METATYPE(UserSkill)
Q_DECLARE_METATYPE(QList<UserSkill>)

#endif // USERSKILL_H
