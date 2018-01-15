#ifndef FCMODELOBJECT_H
#define FCMODELOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT FcModelObject : public TSqlObject, public QSharedData
{
public:
    int fc_model_id {0};
    QString fc_cd;
    bool default_bool;
    QString desc_desc;
    int authority_id {0};
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        FcModelId = 0,
        FcCd,
        DefaultBool,
        DescDesc,
        AuthorityId,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

public slots:
    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<FcModelId; }
    int autoValueIndex() const override { return FcModelId; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList<<AuthorityId; }
    QString tableName() const override { return QLatin1String("fc_model"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int fc_model_id READ getfc_model_id WRITE setfc_model_id)
    T_DEFINE_PROPERTY(int, fc_model_id)
    Q_PROPERTY(QString fc_cd READ getfc_cd WRITE setfc_cd)
    T_DEFINE_PROPERTY(QString, fc_cd)
    Q_PROPERTY(bool default_bool READ getdefault_bool WRITE setdefault_bool)
    T_DEFINE_PROPERTY(bool, default_bool)
    Q_PROPERTY(QString desc_desc READ getdesc_desc WRITE setdesc_desc)
    T_DEFINE_PROPERTY(QString, desc_desc)
    Q_PROPERTY(int authority_id READ getauthority_id WRITE setauthority_id)
    T_DEFINE_PROPERTY(int, authority_id)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};


#endif // FCMODELOBJECT_H
