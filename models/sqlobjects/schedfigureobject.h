#ifndef SCHEDFIGUREOBJECT_H
#define SCHEDFIGUREOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT SchedFigureObject : public TSqlObject, public QSharedData
{
public:
    int figure_id {0};
    int sched_id {0};
    int task_id {0};
    int figure_ord {0};
    QString figure;
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        FigureId = 0,
        SchedId,
        TaskId,
        FigureOrd,
        Figure,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<FigureId; }
    int autoValueIndex() const override { return FigureId; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList<<TaskId<<FigureOrd<<SchedId; }
    QString tableName() const override { return QLatin1String("sched_figure"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int figure_id READ getfigure_id WRITE setfigure_id)
    T_DEFINE_PROPERTY(int, figure_id)
    Q_PROPERTY(int sched_id READ getsched_id WRITE setsched_id)
    T_DEFINE_PROPERTY(int, sched_id)
    Q_PROPERTY(int task_id READ gettask_id WRITE settask_id)
    T_DEFINE_PROPERTY(int, task_id)
    Q_PROPERTY(int figure_ord READ getfigure_ord WRITE setfigure_ord)
    T_DEFINE_PROPERTY(int, figure_ord)
    Q_PROPERTY(QString figure READ getfigure WRITE setfigure)
    T_DEFINE_PROPERTY(QString, figure)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};

#endif // SCHEDFIGUREOBJECT_H
