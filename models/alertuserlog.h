#ifndef ALERTUSERLOG_H
#define ALERTUSERLOG_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class AlertUserLogObject;
class RefAlertStatus;
class UserApp;
class Alert;


class T_MODEL_EXPORT AlertUserLog : public TAbstractModel
{
public:
    AlertUserLog();
    AlertUserLog(const AlertUserLog &other);
    AlertUserLog(const AlertUserLogObject &object);
    ~AlertUserLog();

    int alertId() const;
    void setAlertId(int alertId);
    int userId() const;
    void setUserId(int userId);
    QString alertStatusCd() const;
    void setAlertStatusCd(const QString &alertStatusCd);
    QString userNote() const;
    void setUserNote(const QString &userNote);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    RefAlertStatus refAlertStatusByalertStatusCd() const;
    UserApp userAppByuserId() const;
    Alert alertByalertId() const;
    AlertUserLog &operator=(const AlertUserLog &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static AlertUserLog create(int alertId, int userId, const QString &alertStatusCd, const QString &userNote, const QString &createdBy, const QString &updatedBy);
    static AlertUserLog create(const QVariantMap &values);
    static AlertUserLog get(int alertId, int userId);
    static int count();
    static QList<AlertUserLog> getAll();

private:
    QSharedDataPointer<AlertUserLogObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const AlertUserLog &model);
    friend QDataStream &operator>>(QDataStream &ds, AlertUserLog &model);
};

Q_DECLARE_METATYPE(AlertUserLog)
Q_DECLARE_METATYPE(QList<AlertUserLog>)

#endif // ALERTUSERLOG_H
