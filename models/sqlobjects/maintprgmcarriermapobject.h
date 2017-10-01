#ifndef MAINTPRGMCARRIERMAPOBJECT_H
#define MAINTPRGMCARRIERMAPOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT MaintPrgmCarrierMapObject : public TSqlObject, public QSharedData
{
public:
    int maint_prgm_id {0};
    int carrier_id {0};
    int carrier_revision_ord {0};
    bool latest_revision_bool;
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        MaintPrgmId = 0,
        CarrierId,
        CarrierRevisionOrd,
        LatestRevisionBool,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<MaintPrgmId<<CarrierId; }
    int autoValueIndex() const override { return -1; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList<<CarrierId<<MaintPrgmId; }
    QString tableName() const override { return QLatin1String("maint_prgm_carrier_map"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int maint_prgm_id READ getmaint_prgm_id WRITE setmaint_prgm_id)
    T_DEFINE_PROPERTY(int, maint_prgm_id)
    Q_PROPERTY(int carrier_id READ getcarrier_id WRITE setcarrier_id)
    T_DEFINE_PROPERTY(int, carrier_id)
    Q_PROPERTY(int carrier_revision_ord READ getcarrier_revision_ord WRITE setcarrier_revision_ord)
    T_DEFINE_PROPERTY(int, carrier_revision_ord)
    Q_PROPERTY(bool latest_revision_bool READ getlatest_revision_bool WRITE setlatest_revision_bool)
    T_DEFINE_PROPERTY(bool, latest_revision_bool)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};

#endif // MAINTPRGMCARRIERMAPOBJECT_H
