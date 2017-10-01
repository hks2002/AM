#ifndef DEPTOBJECT_H
#define DEPTOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT DeptObject : public TSqlObject, public QSharedData
{
public:
    int dept_id {0};
    QString dept_cd;
    QString dept_name_zh;
    QString dept_name_en;
    QString dept_desc;
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        DeptId = 0,
        DeptCd,
        DeptNameZh,
        DeptNameEn,
        DeptDesc,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<DeptId; }
    int autoValueIndex() const override { return DeptId; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList; }
    QString tableName() const override { return QLatin1String("dept"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int dept_id READ getdept_id WRITE setdept_id)
    T_DEFINE_PROPERTY(int, dept_id)
    Q_PROPERTY(QString dept_cd READ getdept_cd WRITE setdept_cd)
    T_DEFINE_PROPERTY(QString, dept_cd)
    Q_PROPERTY(QString dept_name_zh READ getdept_name_zh WRITE setdept_name_zh)
    T_DEFINE_PROPERTY(QString, dept_name_zh)
    Q_PROPERTY(QString dept_name_en READ getdept_name_en WRITE setdept_name_en)
    T_DEFINE_PROPERTY(QString, dept_name_en)
    Q_PROPERTY(QString dept_desc READ getdept_desc WRITE setdept_desc)
    T_DEFINE_PROPERTY(QString, dept_desc)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};

#endif // DEPTOBJECT_H
