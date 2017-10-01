#ifndef REFREQPRIORITYOBJECT_H
#define REFREQPRIORITYOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT RefReqPriorityObject : public TSqlObject, public QSharedData
{
public:
    QString req_priority_cd;
    QString req_priority_name_en;
    QString req_priority_name_zh;
    QString req_priority_desc;
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        ReqPriorityCd = 0,
        ReqPriorityNameEn,
        ReqPriorityNameZh,
        ReqPriorityDesc,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<ReqPriorityCd; }
    int autoValueIndex() const override { return -1; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList; }
    QString tableName() const override { return QLatin1String("ref_req_priority"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(QString req_priority_cd READ getreq_priority_cd WRITE setreq_priority_cd)
    T_DEFINE_PROPERTY(QString, req_priority_cd)
    Q_PROPERTY(QString req_priority_name_en READ getreq_priority_name_en WRITE setreq_priority_name_en)
    T_DEFINE_PROPERTY(QString, req_priority_name_en)
    Q_PROPERTY(QString req_priority_name_zh READ getreq_priority_name_zh WRITE setreq_priority_name_zh)
    T_DEFINE_PROPERTY(QString, req_priority_name_zh)
    Q_PROPERTY(QString req_priority_desc READ getreq_priority_desc WRITE setreq_priority_desc)
    T_DEFINE_PROPERTY(QString, req_priority_desc)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};

#endif // REFREQPRIORITYOBJECT_H
