#ifndef INVCSGNXCHGOBJECT_H
#define INVCSGNXCHGOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT InvCsgnXchgObject : public TSqlObject, public QSharedData
{
public:
    int inv_csgn_xchg_id {0};
    int po_id {0};
    int inv_no_id {0};
    int rtrn_inv_no_id {0};
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        InvCsgnXchgId = 0,
        PoId,
        InvNoId,
        RtrnInvNoId,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

public slots:
    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<InvCsgnXchgId; }
    int autoValueIndex() const override { return InvCsgnXchgId; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList<<RtrnInvNoId<<InvNoId<<PoId; }
    QString tableName() const override { return QLatin1String("inv_csgn_xchg"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int inv_csgn_xchg_id READ getinv_csgn_xchg_id WRITE setinv_csgn_xchg_id)
    T_DEFINE_PROPERTY(int, inv_csgn_xchg_id)
    Q_PROPERTY(int po_id READ getpo_id WRITE setpo_id)
    T_DEFINE_PROPERTY(int, po_id)
    Q_PROPERTY(int inv_no_id READ getinv_no_id WRITE setinv_no_id)
    T_DEFINE_PROPERTY(int, inv_no_id)
    Q_PROPERTY(int rtrn_inv_no_id READ getrtrn_inv_no_id WRITE setrtrn_inv_no_id)
    T_DEFINE_PROPERTY(int, rtrn_inv_no_id)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};


#endif // INVCSGNXCHGOBJECT_H
