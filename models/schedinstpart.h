#ifndef SCHEDINSTPART_H
#define SCHEDINSTPART_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class SchedInstPartObject;
class UserApp;
class EqpPartNo;
class InvInv;
class SchedPart;


class T_MODEL_EXPORT SchedInstPart : public TAbstractModel
{
public:
    SchedInstPart();
    SchedInstPart(const SchedInstPart &other);
    SchedInstPart(const SchedInstPartObject &object);
    ~SchedInstPart();

    int schedPartId() const;
    void setSchedPartId(int schedPartId);
    int invNoId() const;
    void setInvNoId(int invNoId);
    int partNoId() const;
    void setPartNoId(int partNoId);
    QString serialNoOem() const;
    void setSerialNoOem(const QString &serialNoOem);
    int instQt() const;
    void setInstQt(int instQt);
    int instBy() const;
    void setInstBy(int instBy);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    UserApp userAppByinstBy() const;
    EqpPartNo eqpPartNoBypartNoId() const;
    InvInv invInvByinvNoId() const;
    SchedPart schedPartByschedPartId() const;
    SchedInstPart &operator=(const SchedInstPart &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static SchedInstPart create(int schedPartId, int invNoId, int partNoId, const QString &serialNoOem, int instQt, int instBy, const QString &createdBy, const QString &updatedBy);
    static SchedInstPart create(const QVariantMap &values);
    static SchedInstPart get(int schedPartId);
    static int count();
    static QList<SchedInstPart> getAll();

private:
    QSharedDataPointer<SchedInstPartObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const SchedInstPart &model);
    friend QDataStream &operator>>(QDataStream &ds, SchedInstPart &model);
};

Q_DECLARE_METATYPE(SchedInstPart)
Q_DECLARE_METATYPE(QList<SchedInstPart>)

#endif // SCHEDINSTPART_H
