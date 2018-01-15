#ifndef USERLOGINHISOBJECT_H
#define USERLOGINHISOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT UserLoginHisObject : public TSqlObject, public QSharedData
{
public:
    int user_login_his_id {0};
    int user_id {0};
    QDateTime login_dt;
    QString login_ip;
    QString login_mac;
    QString login_computer;
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        UserLoginHisId = 0,
        UserId,
        LoginDt,
        LoginIp,
        LoginMac,
        LoginComputer,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

public slots:
    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<UserLoginHisId; }
    int autoValueIndex() const override { return UserLoginHisId; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList<<UserId; }
    QString tableName() const override { return QLatin1String("user_login_his"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int user_login_his_id READ getuser_login_his_id WRITE setuser_login_his_id)
    T_DEFINE_PROPERTY(int, user_login_his_id)
    Q_PROPERTY(int user_id READ getuser_id WRITE setuser_id)
    T_DEFINE_PROPERTY(int, user_id)
    Q_PROPERTY(QDateTime login_dt READ getlogin_dt WRITE setlogin_dt)
    T_DEFINE_PROPERTY(QDateTime, login_dt)
    Q_PROPERTY(QString login_ip READ getlogin_ip WRITE setlogin_ip)
    T_DEFINE_PROPERTY(QString, login_ip)
    Q_PROPERTY(QString login_mac READ getlogin_mac WRITE setlogin_mac)
    T_DEFINE_PROPERTY(QString, login_mac)
    Q_PROPERTY(QString login_computer READ getlogin_computer WRITE setlogin_computer)
    T_DEFINE_PROPERTY(QString, login_computer)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};


#endif // USERLOGINHISOBJECT_H
