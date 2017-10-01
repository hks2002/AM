#ifndef SCHEDTOOL_H
#define SCHEDTOOL_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class SchedToolObject;
class UserApp;
class EqpPartNo;
class EqpAssmblBom;
class EqpAssmbl;
class SchedStask;


class T_MODEL_EXPORT SchedTool : public TAbstractModel
{
public:
    SchedTool();
    SchedTool(const SchedTool &other);
    SchedTool(const SchedToolObject &object);
    ~SchedTool();

    int schedToolId() const;
    int schedId() const;
    void setSchedId(int schedId);
    int assmblId() const;
    void setAssmblId(int assmblId);
    int assmblBomId() const;
    void setAssmblBomId(int assmblBomId);
    int partNoId() const;
    void setPartNoId(int partNoId);
    QString partNote() const;
    void setPartNote(const QString &partNote);
    int schedQt() const;
    void setSchedQt(int schedQt);
    QString schedUsetime() const;
    void setSchedUsetime(const QString &schedUsetime);
    QString actualUsetime() const;
    void setActualUsetime(const QString &actualUsetime);
    int checkOutToUser() const;
    void setCheckOutToUser(int checkOutToUser);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    UserApp userAppBycheckOutToUser() const;
    EqpPartNo eqpPartNoBypartNoId() const;
    EqpAssmblBom eqpAssmblBomByassmblBomId() const;
    EqpAssmbl eqpAssmblByassmblId() const;
    SchedStask schedStaskByschedId() const;
    SchedTool &operator=(const SchedTool &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static SchedTool create(int schedId, int assmblId, int assmblBomId, int partNoId, const QString &partNote, int schedQt, const QString &schedUsetime, const QString &actualUsetime, int checkOutToUser, const QString &createdBy, const QString &updatedBy);
    static SchedTool create(const QVariantMap &values);
    static SchedTool get(int schedToolId);
    static int count();
    static QList<SchedTool> getAll();

private:
    QSharedDataPointer<SchedToolObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const SchedTool &model);
    friend QDataStream &operator>>(QDataStream &ds, SchedTool &model);
};

Q_DECLARE_METATYPE(SchedTool)
Q_DECLARE_METATYPE(QList<SchedTool>)

#endif // SCHEDTOOL_H
