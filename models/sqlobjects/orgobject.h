#ifndef ORGOBJECT_H
#define ORGOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT OrgObject : public TSqlObject, public QSharedData
{
public:
    int org_id {0};
    QString org_cd;
    QString org_name_zh;
    QString org_name_en;
    QString logo;
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        OrgId = 0,
        OrgCd,
        OrgNameZh,
        OrgNameEn,
        Logo,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

public slots:
    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<OrgId; }
    int autoValueIndex() const override { return OrgId; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList; }
    QString tableName() const override { return QLatin1String("org"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int org_id READ getorg_id WRITE setorg_id)
    T_DEFINE_PROPERTY(int, org_id)
    Q_PROPERTY(QString org_cd READ getorg_cd WRITE setorg_cd)
    T_DEFINE_PROPERTY(QString, org_cd)
    Q_PROPERTY(QString org_name_zh READ getorg_name_zh WRITE setorg_name_zh)
    T_DEFINE_PROPERTY(QString, org_name_zh)
    Q_PROPERTY(QString org_name_en READ getorg_name_en WRITE setorg_name_en)
    T_DEFINE_PROPERTY(QString, org_name_en)
    Q_PROPERTY(QString logo READ getlogo WRITE setlogo)
    T_DEFINE_PROPERTY(QString, logo)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};


#endif // ORGOBJECT_H
