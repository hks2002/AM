#ifndef LABOURSKILL_H
#define LABOURSKILL_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class LabourSkillObject;


class T_MODEL_EXPORT LabourSkill : public TAbstractModel
{
public:
    LabourSkill();
    LabourSkill(const LabourSkill &other);
    LabourSkill(const LabourSkillObject &object);
    ~LabourSkill();

    int labourSkillId() const;
    QString labourSkillCd() const;
    void setLabourSkillCd(const QString &labourSkillCd);
    QString labourSkillNameZh() const;
    void setLabourSkillNameZh(const QString &labourSkillNameZh);
    QString labourSkillNameEn() const;
    void setLabourSkillNameEn(const QString &labourSkillNameEn);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    LabourSkill &operator=(const LabourSkill &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static LabourSkill create(const QString &labourSkillCd, const QString &labourSkillNameZh, const QString &labourSkillNameEn, const QString &createdBy, const QString &updatedBy);
    static LabourSkill create(const QVariantMap &values);
    static LabourSkill get(int labourSkillId);
    static int count();
    static QList<LabourSkill> getAll();

private:
    QSharedDataPointer<LabourSkillObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const LabourSkill &model);
    friend QDataStream &operator>>(QDataStream &ds, LabourSkill &model);
};

Q_DECLARE_METATYPE(LabourSkill)
Q_DECLARE_METATYPE(QList<LabourSkill>)

#endif // LABOURSKILL_H
