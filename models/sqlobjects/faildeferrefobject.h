#ifndef FAILDEFERREFOBJECT_H
#define FAILDEFERREFOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT FailDeferRefObject : public TSqlObject, public QSharedData
{
public:
    int fail_defer_ref_id {0};
    QString fail_defer_cd;
    QString defer_ref_name;
    QString defer_ref_desc;
    QString fail_sev_cd;
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        FailDeferRefId = 0,
        FailDeferCd,
        DeferRefName,
        DeferRefDesc,
        FailSevCd,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<FailDeferRefId; }
    int autoValueIndex() const override { return FailDeferRefId; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList<<FailSevCd<<FailDeferCd; }
    QString tableName() const override { return QLatin1String("fail_defer_ref"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int fail_defer_ref_id READ getfail_defer_ref_id WRITE setfail_defer_ref_id)
    T_DEFINE_PROPERTY(int, fail_defer_ref_id)
    Q_PROPERTY(QString fail_defer_cd READ getfail_defer_cd WRITE setfail_defer_cd)
    T_DEFINE_PROPERTY(QString, fail_defer_cd)
    Q_PROPERTY(QString defer_ref_name READ getdefer_ref_name WRITE setdefer_ref_name)
    T_DEFINE_PROPERTY(QString, defer_ref_name)
    Q_PROPERTY(QString defer_ref_desc READ getdefer_ref_desc WRITE setdefer_ref_desc)
    T_DEFINE_PROPERTY(QString, defer_ref_desc)
    Q_PROPERTY(QString fail_sev_cd READ getfail_sev_cd WRITE setfail_sev_cd)
    T_DEFINE_PROPERTY(QString, fail_sev_cd)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};

#endif // FAILDEFERREFOBJECT_H
