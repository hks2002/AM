#ifndef REFASSMBLCLASSOBJECT_H
#define REFASSMBLCLASSOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT RefAssmblClassObject : public TSqlObject, public QSharedData
{
public:
    QString assmbl_class_cd;
    QString assmbl_class_name_en;
    QString assmbl_class_name_zh;
    QString assmbl_class_desc;
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        AssmblClassCd = 0,
        AssmblClassNameEn,
        AssmblClassNameZh,
        AssmblClassDesc,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<AssmblClassCd; }
    int autoValueIndex() const override { return -1; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList; }
    QString tableName() const override { return QLatin1String("ref_assmbl_class"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(QString assmbl_class_cd READ getassmbl_class_cd WRITE setassmbl_class_cd)
    T_DEFINE_PROPERTY(QString, assmbl_class_cd)
    Q_PROPERTY(QString assmbl_class_name_en READ getassmbl_class_name_en WRITE setassmbl_class_name_en)
    T_DEFINE_PROPERTY(QString, assmbl_class_name_en)
    Q_PROPERTY(QString assmbl_class_name_zh READ getassmbl_class_name_zh WRITE setassmbl_class_name_zh)
    T_DEFINE_PROPERTY(QString, assmbl_class_name_zh)
    Q_PROPERTY(QString assmbl_class_desc READ getassmbl_class_desc WRITE setassmbl_class_desc)
    T_DEFINE_PROPERTY(QString, assmbl_class_desc)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};

#endif // REFASSMBLCLASSOBJECT_H
