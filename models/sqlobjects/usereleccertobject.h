#ifndef USERELECCERTOBJECT_H
#define USERELECCERTOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT UserElecCertObject : public TSqlObject, public QSharedData
{
public:
    int user_elec_cert_id {0};
    int user_id {0};
    QByteArray hand_sign_img;
    QString public_key;
    QDateTime issue_dt;
    QDateTime expire_dt;
    bool active_bool;
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        UserElecCertId = 0,
        UserId,
        HandSignImg,
        PublicKey,
        IssueDt,
        ExpireDt,
        ActiveBool,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<UserElecCertId; }
    int autoValueIndex() const override { return UserElecCertId; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList<<UserId; }
    QString tableName() const override { return QLatin1String("user_elec_cert"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int user_elec_cert_id READ getuser_elec_cert_id WRITE setuser_elec_cert_id)
    T_DEFINE_PROPERTY(int, user_elec_cert_id)
    Q_PROPERTY(int user_id READ getuser_id WRITE setuser_id)
    T_DEFINE_PROPERTY(int, user_id)
    Q_PROPERTY(QByteArray hand_sign_img READ gethand_sign_img WRITE sethand_sign_img)
    T_DEFINE_PROPERTY(QByteArray, hand_sign_img)
    Q_PROPERTY(QString public_key READ getpublic_key WRITE setpublic_key)
    T_DEFINE_PROPERTY(QString, public_key)
    Q_PROPERTY(QDateTime issue_dt READ getissue_dt WRITE setissue_dt)
    T_DEFINE_PROPERTY(QDateTime, issue_dt)
    Q_PROPERTY(QDateTime expire_dt READ getexpire_dt WRITE setexpire_dt)
    T_DEFINE_PROPERTY(QDateTime, expire_dt)
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

#endif // USERELECCERTOBJECT_H
