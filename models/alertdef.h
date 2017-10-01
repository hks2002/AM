#ifndef ALERTDEF_H
#define ALERTDEF_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class AlertDefObject;


class T_MODEL_EXPORT AlertDef : public TAbstractModel
{
public:
    AlertDef();
    AlertDef(const AlertDef &other);
    AlertDef(const AlertDefObject &object);
    ~AlertDef();

    int alertDefId() const;
    QString alertName() const;
    void setAlertName(const QString &alertName);
    QString alertDesc() const;
    void setAlertDesc(const QString &alertDesc);
    bool activeBool() const;
    void setActiveBool(bool activeBool);
    QString category() const;
    void setCategory(const QString &category);
    QString notifyCd() const;
    void setNotifyCd(const QString &notifyCd);
    int priority() const;
    void setPriority(int priority);
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
    AlertDef &operator=(const AlertDef &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static AlertDef create(const QString &alertName, const QString &alertDesc, bool activeBool, const QString &category, const QString &notifyCd, int priority, const QString &msgTitle, const QString &message, const QString &createdBy, const QString &updatedBy);
    static AlertDef create(const QVariantMap &values);
    static AlertDef get(int alertDefId);
    static int count();
    static QList<AlertDef> getAll();

private:
    QSharedDataPointer<AlertDefObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const AlertDef &model);
    friend QDataStream &operator>>(QDataStream &ds, AlertDef &model);
};

Q_DECLARE_METATYPE(AlertDef)
Q_DECLARE_METATYPE(QList<AlertDef>)

#endif // ALERTDEF_H
