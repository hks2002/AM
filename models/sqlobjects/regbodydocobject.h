#ifndef REGBODYDOCOBJECT_H
#define REGBODYDOCOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT RegBodyDocObject : public TSqlObject, public QSharedData
{
public:
    int reg_body_doc_id {0};
    QString reg_body_doc_cd;
    QString reg_body_doc_name_zh;
    QString reg_body_doc_name_en;
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        RegBodyDocId = 0,
        RegBodyDocCd,
        RegBodyDocNameZh,
        RegBodyDocNameEn,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<RegBodyDocId; }
    int autoValueIndex() const override { return RegBodyDocId; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList; }
    QString tableName() const override { return QLatin1String("reg_body_doc"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int reg_body_doc_id READ getreg_body_doc_id WRITE setreg_body_doc_id)
    T_DEFINE_PROPERTY(int, reg_body_doc_id)
    Q_PROPERTY(QString reg_body_doc_cd READ getreg_body_doc_cd WRITE setreg_body_doc_cd)
    T_DEFINE_PROPERTY(QString, reg_body_doc_cd)
    Q_PROPERTY(QString reg_body_doc_name_zh READ getreg_body_doc_name_zh WRITE setreg_body_doc_name_zh)
    T_DEFINE_PROPERTY(QString, reg_body_doc_name_zh)
    Q_PROPERTY(QString reg_body_doc_name_en READ getreg_body_doc_name_en WRITE setreg_body_doc_name_en)
    T_DEFINE_PROPERTY(QString, reg_body_doc_name_en)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};

#endif // REGBODYDOCOBJECT_H
