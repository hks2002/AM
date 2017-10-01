#ifndef POAUTHOBJECT_H
#define POAUTHOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT PoAuthObject : public TSqlObject, public QSharedData
{
public:
    int po_auth_id {0};
    int po_id {0};
    bool aog_override_bool;
    bool reverted_bool;
    QDateTime auth_dt;
    QString auth_note;
    int auth_by {0};
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        PoAuthId = 0,
        PoId,
        AogOverrideBool,
        RevertedBool,
        AuthDt,
        AuthNote,
        AuthBy,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<PoAuthId; }
    int autoValueIndex() const override { return PoAuthId; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList<<AuthBy<<PoId; }
    QString tableName() const override { return QLatin1String("po_auth"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int po_auth_id READ getpo_auth_id WRITE setpo_auth_id)
    T_DEFINE_PROPERTY(int, po_auth_id)
    Q_PROPERTY(int po_id READ getpo_id WRITE setpo_id)
    T_DEFINE_PROPERTY(int, po_id)
    Q_PROPERTY(bool aog_override_bool READ getaog_override_bool WRITE setaog_override_bool)
    T_DEFINE_PROPERTY(bool, aog_override_bool)
    Q_PROPERTY(bool reverted_bool READ getreverted_bool WRITE setreverted_bool)
    T_DEFINE_PROPERTY(bool, reverted_bool)
    Q_PROPERTY(QDateTime auth_dt READ getauth_dt WRITE setauth_dt)
    T_DEFINE_PROPERTY(QDateTime, auth_dt)
    Q_PROPERTY(QString auth_note READ getauth_note WRITE setauth_note)
    T_DEFINE_PROPERTY(QString, auth_note)
    Q_PROPERTY(int auth_by READ getauth_by WRITE setauth_by)
    T_DEFINE_PROPERTY(int, auth_by)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};

#endif // POAUTHOBJECT_H
