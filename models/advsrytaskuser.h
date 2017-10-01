#ifndef ADVSRYTASKUSER_H
#define ADVSRYTASKUSER_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class AdvsryTaskUserObject;
class UserApp;
class AdvsryTask;


class T_MODEL_EXPORT AdvsryTaskUser : public TAbstractModel
{
public:
    AdvsryTaskUser();
    AdvsryTaskUser(const AdvsryTaskUser &other);
    AdvsryTaskUser(const AdvsryTaskUserObject &object);
    ~AdvsryTaskUser();

    int advsryTaskId() const;
    void setAdvsryTaskId(int advsryTaskId);
    int userId() const;
    void setUserId(int userId);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    UserApp userAppByuserId() const;
    AdvsryTask advsryTaskByadvsryTaskId() const;
    AdvsryTaskUser &operator=(const AdvsryTaskUser &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static AdvsryTaskUser create(int advsryTaskId, int userId, const QString &createdBy, const QString &updatedBy);
    static AdvsryTaskUser create(const QVariantMap &values);
    static AdvsryTaskUser get(int advsryTaskId, int userId);
    static int count();
    static QList<AdvsryTaskUser> getAll();

private:
    QSharedDataPointer<AdvsryTaskUserObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const AdvsryTaskUser &model);
    friend QDataStream &operator>>(QDataStream &ds, AdvsryTaskUser &model);
};

Q_DECLARE_METATYPE(AdvsryTaskUser)
Q_DECLARE_METATYPE(QList<AdvsryTaskUser>)

#endif // ADVSRYTASKUSER_H
