#ifndef TASKREFDOCOBJECT_H
#define TASKREFDOCOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT TaskRefDocObject : public TSqlObject, public QSharedData
{
public:
    int task_id {0};
    int org_id {0};
    QString amend_ref_desc;
    QString doc_issue_by_cd;
    int reg_body_id {0};
    int manufact_id {0};
    QDateTime issue_dt;
    QDateTime received_dt;
    int received_by {0};
    QString doc_disposition_cd;
    QDateTime disposition_dt;
    int disposition_by {0};
    QString disposition_desc;
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        TaskId = 0,
        OrgId,
        AmendRefDesc,
        DocIssueByCd,
        RegBodyId,
        ManufactId,
        IssueDt,
        ReceivedDt,
        ReceivedBy,
        DocDispositionCd,
        DispositionDt,
        DispositionBy,
        DispositionDesc,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<TaskId; }
    int autoValueIndex() const override { return -1; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList<<DispositionBy<<DocDispositionCd<<ReceivedBy<<ManufactId<<RegBodyId<<DocIssueByCd<<OrgId<<TaskId; }
    QString tableName() const override { return QLatin1String("task_ref_doc"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int task_id READ gettask_id WRITE settask_id)
    T_DEFINE_PROPERTY(int, task_id)
    Q_PROPERTY(int org_id READ getorg_id WRITE setorg_id)
    T_DEFINE_PROPERTY(int, org_id)
    Q_PROPERTY(QString amend_ref_desc READ getamend_ref_desc WRITE setamend_ref_desc)
    T_DEFINE_PROPERTY(QString, amend_ref_desc)
    Q_PROPERTY(QString doc_issue_by_cd READ getdoc_issue_by_cd WRITE setdoc_issue_by_cd)
    T_DEFINE_PROPERTY(QString, doc_issue_by_cd)
    Q_PROPERTY(int reg_body_id READ getreg_body_id WRITE setreg_body_id)
    T_DEFINE_PROPERTY(int, reg_body_id)
    Q_PROPERTY(int manufact_id READ getmanufact_id WRITE setmanufact_id)
    T_DEFINE_PROPERTY(int, manufact_id)
    Q_PROPERTY(QDateTime issue_dt READ getissue_dt WRITE setissue_dt)
    T_DEFINE_PROPERTY(QDateTime, issue_dt)
    Q_PROPERTY(QDateTime received_dt READ getreceived_dt WRITE setreceived_dt)
    T_DEFINE_PROPERTY(QDateTime, received_dt)
    Q_PROPERTY(int received_by READ getreceived_by WRITE setreceived_by)
    T_DEFINE_PROPERTY(int, received_by)
    Q_PROPERTY(QString doc_disposition_cd READ getdoc_disposition_cd WRITE setdoc_disposition_cd)
    T_DEFINE_PROPERTY(QString, doc_disposition_cd)
    Q_PROPERTY(QDateTime disposition_dt READ getdisposition_dt WRITE setdisposition_dt)
    T_DEFINE_PROPERTY(QDateTime, disposition_dt)
    Q_PROPERTY(int disposition_by READ getdisposition_by WRITE setdisposition_by)
    T_DEFINE_PROPERTY(int, disposition_by)
    Q_PROPERTY(QString disposition_desc READ getdisposition_desc WRITE setdisposition_desc)
    T_DEFINE_PROPERTY(QString, disposition_desc)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};

#endif // TASKREFDOCOBJECT_H
