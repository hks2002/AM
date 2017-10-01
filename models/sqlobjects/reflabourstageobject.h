#ifndef REFLABOURSTAGEOBJECT_H
#define REFLABOURSTAGEOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT RefLabourStageObject : public TSqlObject, public QSharedData
{
public:
    QString labour_stage_cd;
    QString labour_stage_name_en;
    QString labour_stage_name_zh;
    QString labour_stage_desc;
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        LabourStageCd = 0,
        LabourStageNameEn,
        LabourStageNameZh,
        LabourStageDesc,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<LabourStageCd; }
    int autoValueIndex() const override { return -1; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList; }
    QString tableName() const override { return QLatin1String("ref_labour_stage"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(QString labour_stage_cd READ getlabour_stage_cd WRITE setlabour_stage_cd)
    T_DEFINE_PROPERTY(QString, labour_stage_cd)
    Q_PROPERTY(QString labour_stage_name_en READ getlabour_stage_name_en WRITE setlabour_stage_name_en)
    T_DEFINE_PROPERTY(QString, labour_stage_name_en)
    Q_PROPERTY(QString labour_stage_name_zh READ getlabour_stage_name_zh WRITE setlabour_stage_name_zh)
    T_DEFINE_PROPERTY(QString, labour_stage_name_zh)
    Q_PROPERTY(QString labour_stage_desc READ getlabour_stage_desc WRITE setlabour_stage_desc)
    T_DEFINE_PROPERTY(QString, labour_stage_desc)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};

#endif // REFLABOURSTAGEOBJECT_H
