#ifndef REFOWNBYOBJECT_H
#define REFOWNBYOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT RefOwnByObject : public TSqlObject, public QSharedData
{
public:
    QString own_by_cd;
    QString own_by_name_en;
    QString own_by_name_zh;
    QString own_by_desc;
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        OwnByCd = 0,
        OwnByNameEn,
        OwnByNameZh,
        OwnByDesc,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<OwnByCd; }
    int autoValueIndex() const override { return -1; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList; }
    QString tableName() const override { return QLatin1String("ref_own_by"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(QString own_by_cd READ getown_by_cd WRITE setown_by_cd)
    T_DEFINE_PROPERTY(QString, own_by_cd)
    Q_PROPERTY(QString own_by_name_en READ getown_by_name_en WRITE setown_by_name_en)
    T_DEFINE_PROPERTY(QString, own_by_name_en)
    Q_PROPERTY(QString own_by_name_zh READ getown_by_name_zh WRITE setown_by_name_zh)
    T_DEFINE_PROPERTY(QString, own_by_name_zh)
    Q_PROPERTY(QString own_by_desc READ getown_by_desc WRITE setown_by_desc)
    T_DEFINE_PROPERTY(QString, own_by_desc)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};

#endif // REFOWNBYOBJECT_H
