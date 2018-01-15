#ifndef LICENSEPREREQUISITEOBJECT_H
#define LICENSEPREREQUISITEOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT LicensePrerequisiteObject : public TSqlObject, public QSharedData
{
public:
    int license_id {0};
    int labour_skill_id {0};
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        LicenseId = 0,
        LabourSkillId,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

public slots:
    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<LicenseId<<LabourSkillId; }
    int autoValueIndex() const override { return -1; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList<<LabourSkillId; }
    QString tableName() const override { return QLatin1String("license_prerequisite"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int license_id READ getlicense_id WRITE setlicense_id)
    T_DEFINE_PROPERTY(int, license_id)
    Q_PROPERTY(int labour_skill_id READ getlabour_skill_id WRITE setlabour_skill_id)
    T_DEFINE_PROPERTY(int, labour_skill_id)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};


#endif // LICENSEPREREQUISITEOBJECT_H
