#ifndef REFLABOURROLESTATUSOBJECT_H
#define REFLABOURROLESTATUSOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT RefLabourRoleStatusObject : public TSqlObject, public QSharedData
{
public:
    QString labour_role_status_cd;
    QString labour_role_status_name_en;
    QString labour_role_status_name_zh;
    QString labour_role_status_desc;
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        LabourRoleStatusCd = 0,
        LabourRoleStatusNameEn,
        LabourRoleStatusNameZh,
        LabourRoleStatusDesc,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<LabourRoleStatusCd; }
    int autoValueIndex() const override { return -1; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList; }
    QString tableName() const override { return QLatin1String("ref_labour_role_status"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(QString labour_role_status_cd READ getlabour_role_status_cd WRITE setlabour_role_status_cd)
    T_DEFINE_PROPERTY(QString, labour_role_status_cd)
    Q_PROPERTY(QString labour_role_status_name_en READ getlabour_role_status_name_en WRITE setlabour_role_status_name_en)
    T_DEFINE_PROPERTY(QString, labour_role_status_name_en)
    Q_PROPERTY(QString labour_role_status_name_zh READ getlabour_role_status_name_zh WRITE setlabour_role_status_name_zh)
    T_DEFINE_PROPERTY(QString, labour_role_status_name_zh)
    Q_PROPERTY(QString labour_role_status_desc READ getlabour_role_status_desc WRITE setlabour_role_status_desc)
    T_DEFINE_PROPERTY(QString, labour_role_status_desc)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};

#endif // REFLABOURROLESTATUSOBJECT_H
