#ifndef USERAPPOBJECT_H
#define USERAPPOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT UserAppObject : public TSqlObject, public QSharedData
{
public:
    int user_id {0};
    QString user_name;
    QString full_name_zh;
    QString full_name_en;
    QString hr_cd;
    QString password;
    QString email_addr;
    bool locked_bool;
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        UserId = 0,
        UserName,
        FullNameZh,
        FullNameEn,
        HrCd,
        Password,
        EmailAddr,
        LockedBool,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

public slots:
    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<UserId; }
    int autoValueIndex() const override { return UserId; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList; }
    QString tableName() const override { return QLatin1String("user_app"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int user_id READ getuser_id WRITE setuser_id)
    T_DEFINE_PROPERTY(int, user_id)
    Q_PROPERTY(QString user_name READ getuser_name WRITE setuser_name)
    T_DEFINE_PROPERTY(QString, user_name)
    Q_PROPERTY(QString full_name_zh READ getfull_name_zh WRITE setfull_name_zh)
    T_DEFINE_PROPERTY(QString, full_name_zh)
    Q_PROPERTY(QString full_name_en READ getfull_name_en WRITE setfull_name_en)
    T_DEFINE_PROPERTY(QString, full_name_en)
    Q_PROPERTY(QString hr_cd READ gethr_cd WRITE sethr_cd)
    T_DEFINE_PROPERTY(QString, hr_cd)
    Q_PROPERTY(QString password READ getpassword WRITE setpassword)
    T_DEFINE_PROPERTY(QString, password)
    Q_PROPERTY(QString email_addr READ getemail_addr WRITE setemail_addr)
    T_DEFINE_PROPERTY(QString, email_addr)
    Q_PROPERTY(bool locked_bool READ getlocked_bool WRITE setlocked_bool)
    T_DEFINE_PROPERTY(bool, locked_bool)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};


#endif // USERAPPOBJECT_H
