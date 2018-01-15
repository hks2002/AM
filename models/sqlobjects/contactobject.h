#ifndef CONTACTOBJECT_H
#define CONTACTOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT ContactObject : public TSqlObject, public QSharedData
{
public:
    int contact_id {0};
    QString address_email;
    QString contact_name;
    QString job_title;
    QString fax_ph;
    QString phone_ph;
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        ContactId = 0,
        AddressEmail,
        ContactName,
        JobTitle,
        FaxPh,
        PhonePh,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

public slots:
    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<ContactId; }
    int autoValueIndex() const override { return ContactId; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList; }
    QString tableName() const override { return QLatin1String("contact"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int contact_id READ getcontact_id WRITE setcontact_id)
    T_DEFINE_PROPERTY(int, contact_id)
    Q_PROPERTY(QString address_email READ getaddress_email WRITE setaddress_email)
    T_DEFINE_PROPERTY(QString, address_email)
    Q_PROPERTY(QString contact_name READ getcontact_name WRITE setcontact_name)
    T_DEFINE_PROPERTY(QString, contact_name)
    Q_PROPERTY(QString job_title READ getjob_title WRITE setjob_title)
    T_DEFINE_PROPERTY(QString, job_title)
    Q_PROPERTY(QString fax_ph READ getfax_ph WRITE setfax_ph)
    T_DEFINE_PROPERTY(QString, fax_ph)
    Q_PROPERTY(QString phone_ph READ getphone_ph WRITE setphone_ph)
    T_DEFINE_PROPERTY(QString, phone_ph)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};


#endif // CONTACTOBJECT_H
