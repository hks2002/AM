#ifndef WORKTYPEOBJECT_H
#define WORKTYPEOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT WorkTypeObject : public TSqlObject, public QSharedData
{
public:
    int work_type_id {0};
    QString work_type_cd;
    QString work_type_name_zh;
    QString work_type_name_en;
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        WorkTypeId = 0,
        WorkTypeCd,
        WorkTypeNameZh,
        WorkTypeNameEn,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<WorkTypeId; }
    int autoValueIndex() const override { return WorkTypeId; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList; }
    QString tableName() const override { return QLatin1String("work_type"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int work_type_id READ getwork_type_id WRITE setwork_type_id)
    T_DEFINE_PROPERTY(int, work_type_id)
    Q_PROPERTY(QString work_type_cd READ getwork_type_cd WRITE setwork_type_cd)
    T_DEFINE_PROPERTY(QString, work_type_cd)
    Q_PROPERTY(QString work_type_name_zh READ getwork_type_name_zh WRITE setwork_type_name_zh)
    T_DEFINE_PROPERTY(QString, work_type_name_zh)
    Q_PROPERTY(QString work_type_name_en READ getwork_type_name_en WRITE setwork_type_name_en)
    T_DEFINE_PROPERTY(QString, work_type_name_en)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};

#endif // WORKTYPEOBJECT_H
