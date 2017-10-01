#ifndef TAGTAGOBJECT_H
#define TAGTAGOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT TagTagObject : public TSqlObject, public QSharedData
{
public:
    int tag_id {0};
    QString tag_cd;
    QString tag_desc;
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        TagId = 0,
        TagCd,
        TagDesc,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<TagId; }
    int autoValueIndex() const override { return TagId; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList; }
    QString tableName() const override { return QLatin1String("tag_tag"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int tag_id READ gettag_id WRITE settag_id)
    T_DEFINE_PROPERTY(int, tag_id)
    Q_PROPERTY(QString tag_cd READ gettag_cd WRITE settag_cd)
    T_DEFINE_PROPERTY(QString, tag_cd)
    Q_PROPERTY(QString tag_desc READ gettag_desc WRITE settag_desc)
    T_DEFINE_PROPERTY(QString, tag_desc)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};

#endif // TAGTAGOBJECT_H
