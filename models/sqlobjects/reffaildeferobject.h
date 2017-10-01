#ifndef REFFAILDEFEROBJECT_H
#define REFFAILDEFEROBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT RefFailDeferObject : public TSqlObject, public QSharedData
{
public:
    QString fail_defer_cd;
    QString fail_defer_name_en;
    QString fail_defer_name_zh;
    QString fail_defer_desc;
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        FailDeferCd = 0,
        FailDeferNameEn,
        FailDeferNameZh,
        FailDeferDesc,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<FailDeferCd; }
    int autoValueIndex() const override { return -1; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList; }
    QString tableName() const override { return QLatin1String("ref_fail_defer"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(QString fail_defer_cd READ getfail_defer_cd WRITE setfail_defer_cd)
    T_DEFINE_PROPERTY(QString, fail_defer_cd)
    Q_PROPERTY(QString fail_defer_name_en READ getfail_defer_name_en WRITE setfail_defer_name_en)
    T_DEFINE_PROPERTY(QString, fail_defer_name_en)
    Q_PROPERTY(QString fail_defer_name_zh READ getfail_defer_name_zh WRITE setfail_defer_name_zh)
    T_DEFINE_PROPERTY(QString, fail_defer_name_zh)
    Q_PROPERTY(QString fail_defer_desc READ getfail_defer_desc WRITE setfail_defer_desc)
    T_DEFINE_PROPERTY(QString, fail_defer_desc)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};

#endif // REFFAILDEFEROBJECT_H
