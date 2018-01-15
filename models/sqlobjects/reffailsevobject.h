#ifndef REFFAILSEVOBJECT_H
#define REFFAILSEVOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT RefFailSevObject : public TSqlObject, public QSharedData
{
public:
    QString fail_sev_cd;
    QString fail_sev_name_en;
    QString fail_sev_name_zh;
    QString fail_sev_desc;
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        FailSevCd = 0,
        FailSevNameEn,
        FailSevNameZh,
        FailSevDesc,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

public slots:
    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<FailSevCd; }
    int autoValueIndex() const override { return -1; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList; }
    QString tableName() const override { return QLatin1String("ref_fail_sev"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(QString fail_sev_cd READ getfail_sev_cd WRITE setfail_sev_cd)
    T_DEFINE_PROPERTY(QString, fail_sev_cd)
    Q_PROPERTY(QString fail_sev_name_en READ getfail_sev_name_en WRITE setfail_sev_name_en)
    T_DEFINE_PROPERTY(QString, fail_sev_name_en)
    Q_PROPERTY(QString fail_sev_name_zh READ getfail_sev_name_zh WRITE setfail_sev_name_zh)
    T_DEFINE_PROPERTY(QString, fail_sev_name_zh)
    Q_PROPERTY(QString fail_sev_desc READ getfail_sev_desc WRITE setfail_sev_desc)
    T_DEFINE_PROPERTY(QString, fail_sev_desc)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};


#endif // REFFAILSEVOBJECT_H
