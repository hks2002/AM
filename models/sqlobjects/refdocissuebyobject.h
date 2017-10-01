#ifndef REFDOCISSUEBYOBJECT_H
#define REFDOCISSUEBYOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT RefDocIssueByObject : public TSqlObject, public QSharedData
{
public:
    QString doc_issue_by_cd;
    QString doc_issue_by_name_en;
    QString doc_issue_by_name_zh;
    QString doc_issue_by_desc;
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        DocIssueByCd = 0,
        DocIssueByNameEn,
        DocIssueByNameZh,
        DocIssueByDesc,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<DocIssueByCd; }
    int autoValueIndex() const override { return -1; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList; }
    QString tableName() const override { return QLatin1String("ref_doc_issue_by"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(QString doc_issue_by_cd READ getdoc_issue_by_cd WRITE setdoc_issue_by_cd)
    T_DEFINE_PROPERTY(QString, doc_issue_by_cd)
    Q_PROPERTY(QString doc_issue_by_name_en READ getdoc_issue_by_name_en WRITE setdoc_issue_by_name_en)
    T_DEFINE_PROPERTY(QString, doc_issue_by_name_en)
    Q_PROPERTY(QString doc_issue_by_name_zh READ getdoc_issue_by_name_zh WRITE setdoc_issue_by_name_zh)
    T_DEFINE_PROPERTY(QString, doc_issue_by_name_zh)
    Q_PROPERTY(QString doc_issue_by_desc READ getdoc_issue_by_desc WRITE setdoc_issue_by_desc)
    T_DEFINE_PROPERTY(QString, doc_issue_by_desc)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};

#endif // REFDOCISSUEBYOBJECT_H
