#ifndef TRANSPORTOROBJECT_H
#define TRANSPORTOROBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT TransportorObject : public TSqlObject, public QSharedData
{
public:
    int transportor_id {0};
    QString transportor_cd;
    QString transportor_name_zh;
    QString transportor_name_en;
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        TransportorId = 0,
        TransportorCd,
        TransportorNameZh,
        TransportorNameEn,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

public slots:
    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<TransportorId; }
    int autoValueIndex() const override { return TransportorId; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList; }
    QString tableName() const override { return QLatin1String("transportor"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int transportor_id READ gettransportor_id WRITE settransportor_id)
    T_DEFINE_PROPERTY(int, transportor_id)
    Q_PROPERTY(QString transportor_cd READ gettransportor_cd WRITE settransportor_cd)
    T_DEFINE_PROPERTY(QString, transportor_cd)
    Q_PROPERTY(QString transportor_name_zh READ gettransportor_name_zh WRITE settransportor_name_zh)
    T_DEFINE_PROPERTY(QString, transportor_name_zh)
    Q_PROPERTY(QString transportor_name_en READ gettransportor_name_en WRITE settransportor_name_en)
    T_DEFINE_PROPERTY(QString, transportor_name_en)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};


#endif // TRANSPORTOROBJECT_H
