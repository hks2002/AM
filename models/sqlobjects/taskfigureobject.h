#ifndef TASKFIGUREOBJECT_H
#define TASKFIGUREOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT TaskFigureObject : public TSqlObject, public QSharedData
{
public:
    int task_id {0};
    int figure_ord {0};
    QString figure_desc;
    QString figure_note;
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        TaskId = 0,
        FigureOrd,
        FigureDesc,
        FigureNote,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

public slots:
    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<TaskId<<FigureOrd; }
    int autoValueIndex() const override { return -1; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList<<TaskId; }
    QString tableName() const override { return QLatin1String("task_figure"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int task_id READ gettask_id WRITE settask_id)
    T_DEFINE_PROPERTY(int, task_id)
    Q_PROPERTY(int figure_ord READ getfigure_ord WRITE setfigure_ord)
    T_DEFINE_PROPERTY(int, figure_ord)
    Q_PROPERTY(QString figure_desc READ getfigure_desc WRITE setfigure_desc)
    T_DEFINE_PROPERTY(QString, figure_desc)
    Q_PROPERTY(QString figure_note READ getfigure_note WRITE setfigure_note)
    T_DEFINE_PROPERTY(QString, figure_note)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};


#endif // TASKFIGUREOBJECT_H
