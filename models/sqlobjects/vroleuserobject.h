#ifndef VROLEUSEROBJECT_H
#define VROLEUSEROBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT VRoleUserObject : public TSqlObject, public QSharedData
{
public:
    int role_id {0};
    QString role_cd;
    QString role_name_zh;
    QString role_name_en;
    int user_id {0};
    QString user_name;
    QString hr_cd;
    QString full_name_zh;
    QString full_name_en;

    enum PropertyIndex {
        RoleId = 0,
        RoleCd,
        RoleNameZh,
        RoleNameEn,
        UserId,
        UserName,
        HrCd,
        FullNameZh,
        FullNameEn,
    };

public slots:
    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList; return fkIdxList; }
    int autoValueIndex() const override { return -1; }
    QString tableName() const override { return QLatin1String("v_role_user"); }

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
    Q_PROPERTY(int user_id READ getuser_id WRITE setuser_id)
    T_DEFINE_PROPERTY(int, user_id)
    Q_PROPERTY(QString user_name READ getuser_name WRITE setuser_name)
    T_DEFINE_PROPERTY(QString, user_name)
    Q_PROPERTY(QString hr_cd READ gethr_cd WRITE sethr_cd)
    T_DEFINE_PROPERTY(QString, hr_cd)
    Q_PROPERTY(QString full_name_zh READ getfull_name_zh WRITE setfull_name_zh)
    T_DEFINE_PROPERTY(QString, full_name_zh)
    Q_PROPERTY(QString full_name_en READ getfull_name_en WRITE setfull_name_en)
    T_DEFINE_PROPERTY(QString, full_name_en)
};


#endif // VROLEUSEROBJECT_H
