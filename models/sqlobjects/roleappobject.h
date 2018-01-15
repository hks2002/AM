#ifndef ROLEAPPOBJECT_H
#define ROLEAPPOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT RoleAppObject : public TSqlObject, public QSharedData
{
public:
    int role_id {0};
    QString role_cd;
    QString role_name_zh;
    QString role_name_en;
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        RoleId = 0,
        RoleCd,
        RoleNameZh,
        RoleNameEn,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

public slots:
    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<RoleId; }
    int autoValueIndex() const override { return RoleId; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList; }
    QString tableName() const override { return QLatin1String("role_app"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int role_id READ getrole_id WRITE setrole_id)
    T_DEFINE_PROPERTY(int, role_id)
    Q_PROPERTY(QString role_cd READ getrole_cd WRITE setrole_cd)
    T_DEFINE_PROPERTY(QString, role_cd)
    Q_PROPERTY(QString role_name_zh READ getrole_name_zh WRITE setrole_name_zh)
    T_DEFINE_PROPERTY(QString, role_name_zh)
    Q_PROPERTY(QString role_name_en READ getrole_name_en WRITE setrole_name_en)
    T_DEFINE_PROPERTY(QString, role_name_en)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};


#endif // ROLEAPPOBJECT_H
