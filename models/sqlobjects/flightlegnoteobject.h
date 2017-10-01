#ifndef FLIGHTLEGNOTEOBJECT_H
#define FLIGHTLEGNOTEOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT FlightLegNoteObject : public TSqlObject, public QSharedData
{
public:
    int leg_id {0};
    QDateTime note_dt;
    bool system_bool;
    int note_by {0};
    QString note_text;
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        LegId = 0,
        NoteDt,
        SystemBool,
        NoteBy,
        NoteText,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<LegId; }
    int autoValueIndex() const override { return -1; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList<<NoteBy<<LegId; }
    QString tableName() const override { return QLatin1String("flight_leg_note"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int leg_id READ getleg_id WRITE setleg_id)
    T_DEFINE_PROPERTY(int, leg_id)
    Q_PROPERTY(QDateTime note_dt READ getnote_dt WRITE setnote_dt)
    T_DEFINE_PROPERTY(QDateTime, note_dt)
    Q_PROPERTY(bool system_bool READ getsystem_bool WRITE setsystem_bool)
    T_DEFINE_PROPERTY(bool, system_bool)
    Q_PROPERTY(int note_by READ getnote_by WRITE setnote_by)
    T_DEFINE_PROPERTY(int, note_by)
    Q_PROPERTY(QString note_text READ getnote_text WRITE setnote_text)
    T_DEFINE_PROPERTY(QString, note_text)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};

#endif // FLIGHTLEGNOTEOBJECT_H
