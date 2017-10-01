#ifndef SCHEDWPSIGN_H
#define SCHEDWPSIGN_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class SchedWpSignObject;
class UserApp;
class SchedWp;


class T_MODEL_EXPORT SchedWpSign : public TAbstractModel
{
public:
    SchedWpSign();
    SchedWpSign(const SchedWpSign &other);
    SchedWpSign(const SchedWpSignObject &object);
    ~SchedWpSign();

    int schedWpSignId() const;
    int schedId() const;
    void setSchedId(int schedId);
    bool signedBool() const;
    void setSignedBool(bool signedBool);
    int signedBy() const;
    void setSignedBy(int signedBy);
    QDateTime signoffDt() const;
    void setSignoffDt(const QDateTime &signoffDt);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    UserApp userAppBysignedBy() const;
    SchedWp schedWpByschedId() const;
    SchedWpSign &operator=(const SchedWpSign &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static SchedWpSign create(int schedId, bool signedBool, int signedBy, const QDateTime &signoffDt, const QString &createdBy, const QString &updatedBy);
    static SchedWpSign create(const QVariantMap &values);
    static SchedWpSign get(int schedWpSignId);
    static int count();
    static QList<SchedWpSign> getAll();

private:
    QSharedDataPointer<SchedWpSignObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const SchedWpSign &model);
    friend QDataStream &operator>>(QDataStream &ds, SchedWpSign &model);
};

Q_DECLARE_METATYPE(SchedWpSign)
Q_DECLARE_METATYPE(QList<SchedWpSign>)

#endif // SCHEDWPSIGN_H
