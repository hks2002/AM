#ifndef FNCACCOUNTOBJECT_H
#define FNCACCOUNTOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT FncAccountObject : public TSqlObject, public QSharedData
{
public:
    int account_id {0};
    QString account_cd;
    int nh_account_id {0};
    QString account_type_cd;
    QString account_name;
    QString account_desc;
    bool default_bool;
    bool closed_bool;
    int tcode_id {0};
    QString ext_key;
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        AccountId = 0,
        AccountCd,
        NhAccountId,
        AccountTypeCd,
        AccountName,
        AccountDesc,
        DefaultBool,
        ClosedBool,
        TcodeId,
        ExtKey,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

public slots:
    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<AccountId; }
    int autoValueIndex() const override { return AccountId; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList<<TcodeId<<AccountTypeCd; }
    QString tableName() const override { return QLatin1String("fnc_account"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int account_id READ getaccount_id WRITE setaccount_id)
    T_DEFINE_PROPERTY(int, account_id)
    Q_PROPERTY(QString account_cd READ getaccount_cd WRITE setaccount_cd)
    T_DEFINE_PROPERTY(QString, account_cd)
    Q_PROPERTY(int nh_account_id READ getnh_account_id WRITE setnh_account_id)
    T_DEFINE_PROPERTY(int, nh_account_id)
    Q_PROPERTY(QString account_type_cd READ getaccount_type_cd WRITE setaccount_type_cd)
    T_DEFINE_PROPERTY(QString, account_type_cd)
    Q_PROPERTY(QString account_name READ getaccount_name WRITE setaccount_name)
    T_DEFINE_PROPERTY(QString, account_name)
    Q_PROPERTY(QString account_desc READ getaccount_desc WRITE setaccount_desc)
    T_DEFINE_PROPERTY(QString, account_desc)
    Q_PROPERTY(bool default_bool READ getdefault_bool WRITE setdefault_bool)
    T_DEFINE_PROPERTY(bool, default_bool)
    Q_PROPERTY(bool closed_bool READ getclosed_bool WRITE setclosed_bool)
    T_DEFINE_PROPERTY(bool, closed_bool)
    Q_PROPERTY(int tcode_id READ gettcode_id WRITE settcode_id)
    T_DEFINE_PROPERTY(int, tcode_id)
    Q_PROPERTY(QString ext_key READ getext_key WRITE setext_key)
    T_DEFINE_PROPERTY(QString, ext_key)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};


#endif // FNCACCOUNTOBJECT_H
