#ifndef SCHEDPART_H
#define SCHEDPART_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class SchedPartObject;
class RefPartStatus;
class RefReqAction;
class EqpAssmblBomPos;
class EqpPartNo;
class EqpAssmblBom;
class EqpAssmbl;
class SchedStask;


class T_MODEL_EXPORT SchedPart : public TAbstractModel
{
public:
    SchedPart();
    SchedPart(const SchedPart &other);
    SchedPart(const SchedPartObject &object);
    ~SchedPart();

    int schedPartId() const;
    int schedId() const;
    void setSchedId(int schedId);
    int assmblId() const;
    void setAssmblId(int assmblId);
    int assmblBomId() const;
    void setAssmblBomId(int assmblBomId);
    int partNoId() const;
    void setPartNoId(int partNoId);
    int assmblBomPosId() const;
    void setAssmblBomPosId(int assmblBomPosId);
    QString partNote() const;
    void setPartNote(const QString &partNote);
    int schedQt() const;
    void setSchedQt(int schedQt);
    QString reqActionCd() const;
    void setReqActionCd(const QString &reqActionCd);
    QString schedPartStatusCd() const;
    void setSchedPartStatusCd(const QString &schedPartStatusCd);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    RefPartStatus refPartStatusByschedPartStatusCd() const;
    RefReqAction refReqActionByreqActionCd() const;
    EqpAssmblBomPos eqpAssmblBomPosByassmblBomPosId() const;
    EqpPartNo eqpPartNoBypartNoId() const;
    EqpAssmblBom eqpAssmblBomByassmblBomId() const;
    EqpAssmbl eqpAssmblByassmblId() const;
    SchedStask schedStaskByschedId() const;
    SchedPart &operator=(const SchedPart &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static SchedPart create(int schedId, int assmblId, int assmblBomId, int partNoId, int assmblBomPosId, const QString &partNote, int schedQt, const QString &reqActionCd, const QString &schedPartStatusCd, const QString &createdBy, const QString &updatedBy);
    static SchedPart create(const QVariantMap &values);
    static SchedPart get(int schedPartId);
    static int count();
    static QList<SchedPart> getAll();

private:
    QSharedDataPointer<SchedPartObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const SchedPart &model);
    friend QDataStream &operator>>(QDataStream &ds, SchedPart &model);
};

Q_DECLARE_METATYPE(SchedPart)
Q_DECLARE_METATYPE(QList<SchedPart>)

#endif // SCHEDPART_H
