#ifndef DEPTSUBDEPTOBJECT_H
#define DEPTSUBDEPTOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT DeptSubdeptObject : public TSqlObject, public QSharedData
{
public:
    int dept_id {0};
    int sub_dept_id {0};
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        DeptId = 0,
        SubDeptId,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

public slots:
    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<DeptId<<SubDeptId; }
    int autoValueIndex() const override { return -1; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList<<SubDeptId<<DeptId; }
    QString tableName() const override { return QLatin1String("dept_subdept"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int dept_id READ getdept_id WRITE setdept_id)
    T_DEFINE_PROPERTY(int, dept_id)
    Q_PROPERTY(int sub_dept_id READ getsub_dept_id WRITE setsub_dept_id)
    T_DEFINE_PROPERTY(int, sub_dept_id)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};


#endif // DEPTSUBDEPTOBJECT_H
