#ifndef TAXOBJECT_H
#define TAXOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT TaxObject : public TSqlObject, public QSharedData
{
public:
    int tax_id {0};
    QString tax_cd;
    QString tax_name;
    int account_id {0};
    bool recoverable_bool;
    bool archive_bool;
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        TaxId = 0,
        TaxCd,
        TaxName,
        AccountId,
        RecoverableBool,
        ArchiveBool,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

public slots:
    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<TaxId; }
    int autoValueIndex() const override { return TaxId; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList<<AccountId; }
    QString tableName() const override { return QLatin1String("tax"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int tax_id READ gettax_id WRITE settax_id)
    T_DEFINE_PROPERTY(int, tax_id)
    Q_PROPERTY(QString tax_cd READ gettax_cd WRITE settax_cd)
    T_DEFINE_PROPERTY(QString, tax_cd)
    Q_PROPERTY(QString tax_name READ gettax_name WRITE settax_name)
    T_DEFINE_PROPERTY(QString, tax_name)
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


#endif // TAXOBJECT_H
