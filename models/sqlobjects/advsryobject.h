#ifndef ADVSRYOBJECT_H
#define ADVSRYOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT AdvsryObject : public TSqlObject, public QSharedData
{
public:
    int advsry_id {0};
    QString advsry_type_cd;
    QString advsry_name;
    QString advsry_desc;
    bool active_bool;
    QDateTime clear_dt;
    QString clear_note;
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        AdvsryId = 0,
        AdvsryTypeCd,
        AdvsryName,
        AdvsryDesc,
        ActiveBool,
        ClearDt,
        ClearNote,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

public slots:
    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<AdvsryId; }
    int autoValueIndex() const override { return AdvsryId; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList<<AdvsryTypeCd; }
    QString tableName() const override { return QLatin1String("advsry"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int advsry_id READ getadvsry_id WRITE setadvsry_id)
    T_DEFINE_PROPERTY(int, advsry_id)
    Q_PROPERTY(QString advsry_type_cd READ getadvsry_type_cd WRITE setadvsry_type_cd)
    T_DEFINE_PROPERTY(QString, advsry_type_cd)
    Q_PROPERTY(QString advsry_name READ getadvsry_name WRITE setadvsry_name)
    T_DEFINE_PROPERTY(QString, advsry_name)
    Q_PROPERTY(QString advsry_desc READ getadvsry_desc WRITE setadvsry_desc)
    T_DEFINE_PROPERTY(QString, advsry_desc)
    Q_PROPERTY(bool active_bool READ getactive_bool WRITE setactive_bool)
    T_DEFINE_PROPERTY(bool, active_bool)
    Q_PROPERTY(QDateTime clear_dt READ getclear_dt WRITE setclear_dt)
    T_DEFINE_PROPERTY(QDateTime, clear_dt)
    Q_PROPERTY(QString clear_note READ getclear_note WRITE setclear_note)
    T_DEFINE_PROPERTY(QString, clear_note)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};


#endif // ADVSRYOBJECT_H
