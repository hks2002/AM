#ifndef ALERT_H
#define ALERT_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class AlertObject;
class RefAlertStatus;
class AlertDef;


class T_MODEL_EXPORT Alert : public TAbstractModel
{
public:
    Alert();
    Alert(const Alert &other);
    Alert(const AlertObject &object);
    ~Alert();

    int alertId() const;
    int alertDefId() const;
    void setAlertDefId(int alertDefId);
    QString alertStatusCd() const;
    void setAlertStatusCd(const QString &alertStatusCd);
    QString msgTitle() const;
    void setMsgTitle(const QString &msgTitle);
    QString message() const;
    void setMessage(const QString &message);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    RefAlertStatus refAlertStatusByalertStatusCd() const;
    AlertDef alertDefByalertDefId() const;
    Alert &operator=(const Alert &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static Alert create(int alertDefId, const QString &alertStatusCd, const QString &msgTitle, const QString &message, const QString &createdBy, const QString &updatedBy);
    static Alert create(const QVariantMap &values);
    static Alert get(int alertId);
    static int count();
    static QList<Alert> getAll();

private:
    QSharedDataPointer<AlertObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const Alert &model);
    friend QDataStream &operator>>(QDataStream &ds, Alert &model);
};

Q_DECLARE_METATYPE(Alert)
Q_DECLARE_METATYPE(QList<Alert>)

#endif // ALERT_H
