#ifndef WORKPACKAGEBUILDEROBJECT_H
#define WORKPACKAGEBUILDEROBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT WorkpackageBuilderObject : public TSqlObject, public QSharedData
{
public:
    int workpackage_builder_id {0};
    QString workpackage_builder_name;
    QString workpackage_type_cd;
    QString workpackage_name_string;
    int task_id {0};
    int assmbl_id {0};
    int part_no_id {0};
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        WorkpackageBuilderId = 0,
        WorkpackageBuilderName,
        WorkpackageTypeCd,
        WorkpackageNameString,
        TaskId,
        AssmblId,
        PartNoId,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

public slots:
    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<WorkpackageBuilderId; }
    int autoValueIndex() const override { return WorkpackageBuilderId; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList<<PartNoId<<AssmblId<<TaskId<<WorkpackageTypeCd; }
    QString tableName() const override { return QLatin1String("workpackage_builder"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int workpackage_builder_id READ getworkpackage_builder_id WRITE setworkpackage_builder_id)
    T_DEFINE_PROPERTY(int, workpackage_builder_id)
    Q_PROPERTY(QString workpackage_builder_name READ getworkpackage_builder_name WRITE setworkpackage_builder_name)
    T_DEFINE_PROPERTY(QString, workpackage_builder_name)
    Q_PROPERTY(QString workpackage_type_cd READ getworkpackage_type_cd WRITE setworkpackage_type_cd)
    T_DEFINE_PROPERTY(QString, workpackage_type_cd)
    Q_PROPERTY(QString workpackage_name_string READ getworkpackage_name_string WRITE setworkpackage_name_string)
    T_DEFINE_PROPERTY(QString, workpackage_name_string)
    Q_PROPERTY(int task_id READ gettask_id WRITE settask_id)
    T_DEFINE_PROPERTY(int, task_id)
    Q_PROPERTY(int assmbl_id READ getassmbl_id WRITE setassmbl_id)
    T_DEFINE_PROPERTY(int, assmbl_id)
    Q_PROPERTY(int part_no_id READ getpart_no_id WRITE setpart_no_id)
    T_DEFINE_PROPERTY(int, part_no_id)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};


#endif // WORKPACKAGEBUILDEROBJECT_H
