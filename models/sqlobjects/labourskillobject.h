#ifndef LABOURSKILLOBJECT_H
#define LABOURSKILLOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT LabourSkillObject : public TSqlObject, public QSharedData
{
public:
    int labour_skill_id {0};
    QString labour_skill_cd;
    QString labour_skill_name_zh;
    QString labour_skill_name_en;
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        LabourSkillId = 0,
        LabourSkillCd,
        LabourSkillNameZh,
        LabourSkillNameEn,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<LabourSkillId; }
    int autoValueIndex() const override { return LabourSkillId; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList; }
    QString tableName() const override { return QLatin1String("labour_skill"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int labour_skill_id READ getlabour_skill_id WRITE setlabour_skill_id)
    T_DEFINE_PROPERTY(int, labour_skill_id)
    Q_PROPERTY(QString labour_skill_cd READ getlabour_skill_cd WRITE setlabour_skill_cd)
    T_DEFINE_PROPERTY(QString, labour_skill_cd)
    Q_PROPERTY(QString labour_skill_name_zh READ getlabour_skill_name_zh WRITE setlabour_skill_name_zh)
    T_DEFINE_PROPERTY(QString, labour_skill_name_zh)
    Q_PROPERTY(QString labour_skill_name_en READ getlabour_skill_name_en WRITE setlabour_skill_name_en)
    T_DEFINE_PROPERTY(QString, labour_skill_name_en)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};

#endif // LABOURSKILLOBJECT_H
