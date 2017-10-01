#ifndef SCHEDFIGURE_H
#define SCHEDFIGURE_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class SchedFigureObject;
class TaskFigure;
class SchedStask;


class T_MODEL_EXPORT SchedFigure : public TAbstractModel
{
public:
    SchedFigure();
    SchedFigure(const SchedFigure &other);
    SchedFigure(const SchedFigureObject &object);
    ~SchedFigure();

    int figureId() const;
    int schedId() const;
    void setSchedId(int schedId);
    int taskId() const;
    void setTaskId(int taskId);
    int figureOrd() const;
    void setFigureOrd(int figureOrd);
    QString figure() const;
    void setFigure(const QString &figure);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    TaskFigure taskFigureBytaskIdfigureOrd() const;
    SchedStask schedStaskByschedId() const;
    SchedFigure &operator=(const SchedFigure &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static SchedFigure create(int schedId, int taskId, int figureOrd, const QString &figure, const QString &createdBy, const QString &updatedBy);
    static SchedFigure create(const QVariantMap &values);
    static SchedFigure get(int figureId);
    static int count();
    static QList<SchedFigure> getAll();

private:
    QSharedDataPointer<SchedFigureObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const SchedFigure &model);
    friend QDataStream &operator>>(QDataStream &ds, SchedFigure &model);
};

Q_DECLARE_METATYPE(SchedFigure)
Q_DECLARE_METATYPE(QList<SchedFigure>)

#endif // SCHEDFIGURE_H
