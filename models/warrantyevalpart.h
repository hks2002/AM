#ifndef WARRANTYEVALPART_H
#define WARRANTYEVALPART_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class WarrantyEvalPartObject;
class SchedRmvdPart;
class WarrantyEvalTask;


class T_MODEL_EXPORT WarrantyEvalPart : public TAbstractModel
{
public:
    WarrantyEvalPart();
    WarrantyEvalPart(const WarrantyEvalPart &other);
    WarrantyEvalPart(const WarrantyEvalPartObject &object);
    ~WarrantyEvalPart();

    int warrantyEvalId() const;
    void setWarrantyEvalId(int warrantyEvalId);
    int schedId() const;
    void setSchedId(int schedId);
    int schedPartId() const;
    void setSchedPartId(int schedPartId);
    bool rtrnReqBool() const;
    void setRtrnReqBool(bool rtrnReqBool);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    SchedRmvdPart schedRmvdPartByschedPartId() const;
    WarrantyEvalTask warrantyEvalTaskBywarrantyEvalIdschedId() const;
    WarrantyEvalPart &operator=(const WarrantyEvalPart &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static WarrantyEvalPart create(int warrantyEvalId, int schedId, int schedPartId, bool rtrnReqBool, const QString &createdBy, const QString &updatedBy);
    static WarrantyEvalPart create(const QVariantMap &values);
    static WarrantyEvalPart get(int warrantyEvalId, int schedId, int schedPartId);
    static int count();
    static QList<WarrantyEvalPart> getAll();

private:
    QSharedDataPointer<WarrantyEvalPartObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const WarrantyEvalPart &model);
    friend QDataStream &operator>>(QDataStream &ds, WarrantyEvalPart &model);
};

Q_DECLARE_METATYPE(WarrantyEvalPart)
Q_DECLARE_METATYPE(QList<WarrantyEvalPart>)

#endif // WARRANTYEVALPART_H
