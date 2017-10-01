#ifndef LOCLINESETTING_H
#define LOCLINESETTING_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class LocLineSettingObject;
class Loc;


class T_MODEL_EXPORT LocLineSetting : public TAbstractModel
{
public:
    LocLineSetting();
    LocLineSetting(const LocLineSetting &other);
    LocLineSetting(const LocLineSettingObject &object);
    ~LocLineSetting();

    int locId() const;
    void setLocId(int locId);
    QString minGroundTimeQt() const;
    void setMinGroundTimeQt(const QString &minGroundTimeQt);
    int durationBufferQt() const;
    void setDurationBufferQt(int durationBufferQt);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    Loc locBylocId() const;
    LocLineSetting &operator=(const LocLineSetting &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static LocLineSetting create(int locId, const QString &minGroundTimeQt, int durationBufferQt, const QString &createdBy, const QString &updatedBy);
    static LocLineSetting create(const QVariantMap &values);
    static LocLineSetting get(int locId);
    static int count();
    static QList<LocLineSetting> getAll();

private:
    QSharedDataPointer<LocLineSettingObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const LocLineSetting &model);
    friend QDataStream &operator>>(QDataStream &ds, LocLineSetting &model);
};

Q_DECLARE_METATYPE(LocLineSetting)
Q_DECLARE_METATYPE(QList<LocLineSetting>)

#endif // LOCLINESETTING_H
