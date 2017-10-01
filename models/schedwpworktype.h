#ifndef SCHEDWPWORKTYPE_H
#define SCHEDWPWORKTYPE_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class SchedWpWorkTypeObject;
class WorkType;
class SchedWp;


class T_MODEL_EXPORT SchedWpWorkType : public TAbstractModel
{
public:
    SchedWpWorkType();
    SchedWpWorkType(const SchedWpWorkType &other);
    SchedWpWorkType(const SchedWpWorkTypeObject &object);
    ~SchedWpWorkType();

    int schedId() const;
    void setSchedId(int schedId);
    int workTypeId() const;
    void setWorkTypeId(int workTypeId);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    WorkType workTypeByworkTypeId() const;
    SchedWp schedWpByschedId() const;
    SchedWpWorkType &operator=(const SchedWpWorkType &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static SchedWpWorkType create(int schedId, int workTypeId, const QString &createdBy, const QString &updatedBy);
    static SchedWpWorkType create(const QVariantMap &values);
    static SchedWpWorkType get(int schedId, int workTypeId);
    static int count();
    static QList<SchedWpWorkType> getAll();

private:
    QSharedDataPointer<SchedWpWorkTypeObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const SchedWpWorkType &model);
    friend QDataStream &operator>>(QDataStream &ds, SchedWpWorkType &model);
};

Q_DECLARE_METATYPE(SchedWpWorkType)
Q_DECLARE_METATYPE(QList<SchedWpWorkType>)

#endif // SCHEDWPWORKTYPE_H
