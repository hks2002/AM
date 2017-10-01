#ifndef REFFAILSEVDEFEROBJECT_H
#define REFFAILSEVDEFEROBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT RefFailSevDeferObject : public TSqlObject, public QSharedData
{
public:
    QString fail_sev_cd;
    QString fail_defer_cd;
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        FailSevCd = 0,
        FailDeferCd,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<FailSevCd<<FailDeferCd; }
    int autoValueIndex() const override { return -1; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList<<FailDeferCd<<FailSevCd; }
    QString tableName() const override { return QLatin1String("ref_fail_sev_defer"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(QString fail_sev_cd READ getfail_sev_cd WRITE setfail_sev_cd)
    T_DEFINE_PROPERTY(QString, fail_sev_cd)
    Q_PROPERTY(QString fail_defer_cd READ getfail_defer_cd WRITE setfail_defer_cd)
    T_DEFINE_PROPERTY(QString, fail_defer_cd)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};

#endif // REFFAILSEVDEFEROBJECT_H
