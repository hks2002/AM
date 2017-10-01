#ifndef ORGCODEOBJECT_H
#define ORGCODEOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT OrgCodeObject : public TSqlObject, public QSharedData
{
public:
    int org_id {0};
    QString icao_cd;
    QString iata_cd;
    QString callsign_cd;
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        OrgId = 0,
        IcaoCd,
        IataCd,
        CallsignCd,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<OrgId; }
    int autoValueIndex() const override { return -1; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList<<OrgId; }
    QString tableName() const override { return QLatin1String("org_code"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int org_id READ getorg_id WRITE setorg_id)
    T_DEFINE_PROPERTY(int, org_id)
    Q_PROPERTY(QString icao_cd READ geticao_cd WRITE seticao_cd)
    T_DEFINE_PROPERTY(QString, icao_cd)
    Q_PROPERTY(QString iata_cd READ getiata_cd WRITE setiata_cd)
    T_DEFINE_PROPERTY(QString, iata_cd)
    Q_PROPERTY(QString callsign_cd READ getcallsign_cd WRITE setcallsign_cd)
    T_DEFINE_PROPERTY(QString, callsign_cd)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};

#endif // ORGCODEOBJECT_H
