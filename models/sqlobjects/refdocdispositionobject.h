#ifndef REFDOCDISPOSITIONOBJECT_H
#define REFDOCDISPOSITIONOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT RefDocDispositionObject : public TSqlObject, public QSharedData
{
public:
    QString doc_disposition_cd;
    QString doc_disposition_name_en;
    QString doc_disposition_name_zh;
    QString doc_disposition_desc;
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        DocDispositionCd = 0,
        DocDispositionNameEn,
        DocDispositionNameZh,
        DocDispositionDesc,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

public slots:
    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<DocDispositionCd; }
    int autoValueIndex() const override { return -1; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList; }
    QString tableName() const override { return QLatin1String("ref_doc_disposition"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(QString doc_disposition_cd READ getdoc_disposition_cd WRITE setdoc_disposition_cd)
    T_DEFINE_PROPERTY(QString, doc_disposition_cd)
    Q_PROPERTY(QString doc_disposition_name_en READ getdoc_disposition_name_en WRITE setdoc_disposition_name_en)
    T_DEFINE_PROPERTY(QString, doc_disposition_name_en)
    Q_PROPERTY(QString doc_disposition_name_zh READ getdoc_disposition_name_zh WRITE setdoc_disposition_name_zh)
    T_DEFINE_PROPERTY(QString, doc_disposition_name_zh)
    Q_PROPERTY(QString doc_disposition_desc READ getdoc_disposition_desc WRITE setdoc_disposition_desc)
    T_DEFINE_PROPERTY(QString, doc_disposition_desc)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};


#endif // REFDOCDISPOSITIONOBJECT_H
