#ifndef FNCXACTIONLOGACCOUNTOBJECT_H
#define FNCXACTIONLOGACCOUNTOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT FncXactionLogAccountObject : public TSqlObject, public QSharedData
{
public:
    int xaction_id {0};
    int account_id {0};
    int xaction_account_id {0};
    double credit_cost {0};
    double debit_cost {0};
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        XactionId = 0,
        AccountId,
        XactionAccountId,
        CreditCost,
        DebitCost,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

public slots:
    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<XactionId<<AccountId<<XactionAccountId; }
    int autoValueIndex() const override { return -1; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList<<XactionAccountId<<AccountId<<XactionId; }
    QString tableName() const override { return QLatin1String("fnc_xaction_log_account"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int xaction_id READ getxaction_id WRITE setxaction_id)
    T_DEFINE_PROPERTY(int, xaction_id)
    Q_PROPERTY(int account_id READ getaccount_id WRITE setaccount_id)
    T_DEFINE_PROPERTY(int, account_id)
    Q_PROPERTY(int xaction_account_id READ getxaction_account_id WRITE setxaction_account_id)
    T_DEFINE_PROPERTY(int, xaction_account_id)
    Q_PROPERTY(double credit_cost READ getcredit_cost WRITE setcredit_cost)
    T_DEFINE_PROPERTY(double, credit_cost)
    Q_PROPERTY(double debit_cost READ getdebit_cost WRITE setdebit_cost)
    T_DEFINE_PROPERTY(double, debit_cost)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};


#endif // FNCXACTIONLOGACCOUNTOBJECT_H
