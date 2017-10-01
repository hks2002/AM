#ifndef REFXACTIONTYPEOBJECT_H
#define REFXACTIONTYPEOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT RefXactionTypeObject : public TSqlObject, public QSharedData
{
public:
    QString xaction_type_cd;
    QString xaction_type_name_en;
    QString xaction_type_name_zh;
    QString xaction_type_desc;
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        XactionTypeCd = 0,
        XactionTypeNameEn,
        XactionTypeNameZh,
        XactionTypeDesc,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<XactionTypeCd; }
    int autoValueIndex() const override { return -1; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList; }
    QString tableName() const override { return QLatin1String("ref_xaction_type"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(QString xaction_type_cd READ getxaction_type_cd WRITE setxaction_type_cd)
    T_DEFINE_PROPERTY(QString, xaction_type_cd)
    Q_PROPERTY(QString xaction_type_name_en READ getxaction_type_name_en WRITE setxaction_type_name_en)
    T_DEFINE_PROPERTY(QString, xaction_type_name_en)
    Q_PROPERTY(QString xaction_type_name_zh READ getxaction_type_name_zh WRITE setxaction_type_name_zh)
    T_DEFINE_PROPERTY(QString, xaction_type_name_zh)
    Q_PROPERTY(QString xaction_type_desc READ getxaction_type_desc WRITE setxaction_type_desc)
    T_DEFINE_PROPERTY(QString, xaction_type_desc)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};

#endif // REFXACTIONTYPEOBJECT_H
