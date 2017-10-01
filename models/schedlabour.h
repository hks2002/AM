#ifndef SCHEDLABOUR_H
#define SCHEDLABOUR_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class SchedLabourObject;
class RefLabourStage;
class LabourSkill;
class SchedStask;


class T_MODEL_EXPORT SchedLabour : public TAbstractModel
{
public:
    SchedLabour();
    SchedLabour(const SchedLabour &other);
    SchedLabour(const SchedLabourObject &object);
    ~SchedLabour();

    int schedLabourId() const;
    int schedId() const;
    void setSchedId(int schedId);
    int labourSkillId() const;
    void setLabourSkillId(int labourSkillId);
    int labourOrd() const;
    void setLabourOrd(int labourOrd);
    QString labourStageCd() const;
    void setLabourStageCd(const QString &labourStageCd);
    bool workPerfBool() const;
    void setWorkPerfBool(bool workPerfBool);
    bool inspBool() const;
    void setInspBool(bool inspBool);
    bool riiBool() const;
    void setRiiBool(bool riiBool);
    QString note() const;
    void setNote(const QString &note);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    RefLabourStage refLabourStageBylabourStageCd() const;
    LabourSkill labourSkillBylabourSkillId() const;
    SchedStask schedStaskByschedId() const;
    SchedLabour &operator=(const SchedLabour &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static SchedLabour create(int schedId, int labourSkillId, int labourOrd, const QString &labourStageCd, bool workPerfBool, bool inspBool, bool riiBool, const QString &note, const QString &createdBy, const QString &updatedBy);
    static SchedLabour create(const QVariantMap &values);
    static SchedLabour get(int schedLabourId);
    static int count();
    static QList<SchedLabour> getAll();

private:
    QSharedDataPointer<SchedLabourObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const SchedLabour &model);
    friend QDataStream &operator>>(QDataStream &ds, SchedLabour &model);
};

Q_DECLARE_METATYPE(SchedLabour)
Q_DECLARE_METATYPE(QList<SchedLabour>)

#endif // SCHEDLABOUR_H
