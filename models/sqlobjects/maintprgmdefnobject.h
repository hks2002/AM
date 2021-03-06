#ifndef MAINTPRGMDEFNOBJECT_H
#define MAINTPRGMDEFNOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT MaintPrgmDefnObject : public TSqlObject, public QSharedData
{
public:
    int maint_prgm_defn_id {0};
    int last_revision_ord {0};
    bool new_revision_bool;
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        MaintPrgmDefnId = 0,
        LastRevisionOrd,
        NewRevisionBool,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

public slots:
    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<MaintPrgmDefnId; }
    int autoValueIndex() const override { return MaintPrgmDefnId; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList; }
    QString tableName() const override { return QLatin1String("maint_prgm_defn"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int maint_prgm_defn_id READ getmaint_prgm_defn_id WRITE setmaint_prgm_defn_id)
    T_DEFINE_PROPERTY(int, maint_prgm_defn_id)
    Q_PROPERTY(int last_revision_ord READ getlast_revision_ord WRITE setlast_revision_ord)
    T_DEFINE_PROPERTY(int, last_revision_ord)
    Q_PROPERTY(bool new_revision_bool READ getnew_revision_bool WRITE setnew_revision_bool)
    T_DEFINE_PROPERTY(bool, new_revision_bool)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};


#endif // MAINTPRGMDEFNOBJECT_H
