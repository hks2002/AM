#ifndef USERPOAUTHLVLOBJECT_H
#define USERPOAUTHLVLOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT UserPoAuthLvlObject : public TSqlObject, public QSharedData
{
public:
    int user_id {0};
    int currency_id {0};
    double auth_lvl_limit {0};
    bool active_bool;
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        UserId = 0,
        CurrencyId,
        AuthLvlLimit,
        ActiveBool,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<UserId<<CurrencyId; }
    int autoValueIndex() const override { return -1; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList<<CurrencyId<<UserId; }
    QString tableName() const override { return QLatin1String("user_po_auth_lvl"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int user_id READ getuser_id WRITE setuser_id)
    T_DEFINE_PROPERTY(int, user_id)
    Q_PROPERTY(int currency_id READ getcurrency_id WRITE setcurrency_id)
    T_DEFINE_PROPERTY(int, currency_id)
    Q_PROPERTY(double auth_lvl_limit READ getauth_lvl_limit WRITE setauth_lvl_limit)
    T_DEFINE_PROPERTY(double, auth_lvl_limit)
    Q_PROPERTY(bool active_bool READ getactive_bool WRITE setactive_bool)
    T_DEFINE_PROPERTY(bool, active_bool)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};

#endif // USERPOAUTHLVLOBJECT_H
