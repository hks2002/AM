#ifndef POLINEDOCOBJECT_H
#define POLINEDOCOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT PoLineDocObject : public TSqlObject, public QSharedData
{
public:
    int po_line_id {0};
    int reg_body_doc_id {0};
    bool received_doc_bool;
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        PoLineId = 0,
        RegBodyDocId,
        ReceivedDocBool,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

public slots:
    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<PoLineId<<RegBodyDocId; }
    int autoValueIndex() const override { return -1; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList<<RegBodyDocId<<PoLineId; }
    QString tableName() const override { return QLatin1String("po_line_doc"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int po_line_id READ getpo_line_id WRITE setpo_line_id)
    T_DEFINE_PROPERTY(int, po_line_id)
    Q_PROPERTY(int reg_body_doc_id READ getreg_body_doc_id WRITE setreg_body_doc_id)
    T_DEFINE_PROPERTY(int, reg_body_doc_id)
    Q_PROPERTY(bool received_doc_bool READ getreceived_doc_bool WRITE setreceived_doc_bool)
    T_DEFINE_PROPERTY(bool, received_doc_bool)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};


#endif // POLINEDOCOBJECT_H
