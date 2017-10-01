#ifndef CHARGEOBJECT_H
#define CHARGEOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT ChargeObject : public TSqlObject, public QSharedData
{
public:
    int charge_id {0};
    QString charge_cd;
    QString charge_name;
    int account_id {0};
    bool recoverable_bool;
    bool archive_bool;
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        ChargeId = 0,
        ChargeCd,
        ChargeName,
        AccountId,
        RecoverableBool,
        ArchiveBool,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<ChargeId; }
    int autoValueIndex() const override { return ChargeId; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList<<AccountId; }
    QString tableName() const override { return QLatin1String("charge"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int charge_id READ getcharge_id WRITE setcharge_id)
    T_DEFINE_PROPERTY(int, charge_id)
    Q_PROPERTY(QString charge_cd READ getcharge_cd WRITE setcharge_cd)
    T_DEFINE_PROPERTY(QString, charge_cd)
    Q_PROPERTY(QString charge_name READ getcharge_name WRITE setcharge_name)
    T_DEFINE_PROPERTY(QString, charge_name)
    Q_PROPERTY(int account_id READ getaccount_id WRITE setaccount_id)
    T_DEFINE_PROPERTY(int, account_id)
    Q_PROPERTY(bool recoverable_bool READ getrecoverable_bool WRITE setrecoverable_bool)
    T_DEFINE_PROPERTY(bool, recoverable_bool)
    Q_PROPERTY(bool archive_bool READ getarchive_bool WRITE setarchive_bool)
    T_DEFINE_PROPERTY(bool, archive_bool)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};

#endif // CHARGEOBJECT_H
