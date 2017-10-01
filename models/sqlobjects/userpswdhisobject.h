#ifndef USERPSWDHISOBJECT_H
#define USERPSWDHISOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT UserPswdHisObject : public TSqlObject, public QSharedData
{
public:
    int user_pswd_his_id {0};
    int user_id {0};
    QString password;
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        UserPswdHisId = 0,
        UserId,
        Password,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<UserPswdHisId; }
    int autoValueIndex() const override { return UserPswdHisId; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList<<UserId; }
    QString tableName() const override { return QLatin1String("user_pswd_his"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int user_pswd_his_id READ getuser_pswd_his_id WRITE setuser_pswd_his_id)
    T_DEFINE_PROPERTY(int, user_pswd_his_id)
    Q_PROPERTY(int user_id READ getuser_id WRITE setuser_id)
    T_DEFINE_PROPERTY(int, user_id)
    Q_PROPERTY(QString password READ getpassword WRITE setpassword)
    T_DEFINE_PROPERTY(QString, password)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};

#endif // USERPSWDHISOBJECT_H
