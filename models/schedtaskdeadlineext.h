#ifndef SCHEDTASKDEADLINEEXT_H
#define SCHEDTASKDEADLINEEXT_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class SchedTaskDeadlineExtObject;
class DataType;
class SchedStask;


class T_MODEL_EXPORT SchedTaskDeadlineExt : public TAbstractModel
{
public:
    SchedTaskDeadlineExt();
    SchedTaskDeadlineExt(const SchedTaskDeadlineExt &other);
    SchedTaskDeadlineExt(const SchedTaskDeadlineExtObject &object);
    ~SchedTaskDeadlineExt();

    int schedId() const;
    void setSchedId(int schedId);
    int dataTypeId() const;
    void setDataTypeId(int dataTypeId);
    int deviationQt() const;
    void setDeviationQt(int deviationQt);
    QString extendNote() const;
    void setExtendNote(const QString &extendNote);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    DataType dataTypeBydataTypeId() const;
    SchedStask schedStaskByschedId() const;
    SchedTaskDeadlineExt &operator=(const SchedTaskDeadlineExt &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static SchedTaskDeadlineExt create(int schedId, int dataTypeId, int deviationQt, const QString &extendNote, const QString &createdBy, const QString &updatedBy);
    static SchedTaskDeadlineExt create(const QVariantMap &values);
    static SchedTaskDeadlineExt get(int schedId, int dataTypeId);
    static int count();
    static QList<SchedTaskDeadlineExt> getAll();

private:
    QSharedDataPointer<SchedTaskDeadlineExtObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const SchedTaskDeadlineExt &model);
    friend QDataStream &operator>>(QDataStream &ds, SchedTaskDeadlineExt &model);
};

Q_DECLARE_METATYPE(SchedTaskDeadlineExt)
Q_DECLARE_METATYPE(QList<SchedTaskDeadlineExt>)

#endif // SCHEDTASKDEADLINEEXT_H
