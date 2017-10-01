#ifndef FNCTCODEOBJECT_H
#define FNCTCODEOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT FncTcodeObject : public TSqlObject, public QSharedData
{
public:
    int tcode_id {0};
    QString tcode_cd;
    QString tcode_name;
    QString desc_desc;
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        TcodeId = 0,
        TcodeCd,
        TcodeName,
        DescDesc,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<TcodeId; }
    int autoValueIndex() const override { return TcodeId; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList; }
    QString tableName() const override { return QLatin1String("fnc_tcode"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int tcode_id READ gettcode_id WRITE settcode_id)
    T_DEFINE_PROPERTY(int, tcode_id)
    Q_PROPERTY(QString tcode_cd READ gettcode_cd WRITE settcode_cd)
    T_DEFINE_PROPERTY(QString, tcode_cd)
    Q_PROPERTY(QString tcode_name READ gettcode_name WRITE settcode_name)
    T_DEFINE_PROPERTY(QString, tcode_name)
    Q_PROPERTY(QString desc_desc READ getdesc_desc WRITE setdesc_desc)
    T_DEFINE_PROPERTY(QString, desc_desc)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};

#endif // FNCTCODEOBJECT_H
