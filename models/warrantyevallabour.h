#ifndef WARRANTYEVALLABOUR_H
#define WARRANTYEVALLABOUR_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class WarrantyEvalLabourObject;
class SchedLabour;
class WarrantyEvalTask;


class T_MODEL_EXPORT WarrantyEvalLabour : public TAbstractModel
{
public:
    WarrantyEvalLabour();
    WarrantyEvalLabour(const WarrantyEvalLabour &other);
    WarrantyEvalLabour(const WarrantyEvalLabourObject &object);
    ~WarrantyEvalLabour();

    int warrantyEvalId() const;
    void setWarrantyEvalId(int warrantyEvalId);
    int schedId() const;
    void setSchedId(int schedId);
    int labourId() const;
    void setLabourId(int labourId);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    SchedLabour schedLabourBylabourId() const;
    WarrantyEvalTask warrantyEvalTaskBywarrantyEvalIdschedId() const;
    WarrantyEvalLabour &operator=(const WarrantyEvalLabour &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static WarrantyEvalLabour create(int warrantyEvalId, int schedId, int labourId, const QString &createdBy, const QString &updatedBy);
    static WarrantyEvalLabour create(const QVariantMap &values);
    static WarrantyEvalLabour get(int warrantyEvalId, int schedId, int labourId);
    static int count();
    static QList<WarrantyEvalLabour> getAll();

private:
    QSharedDataPointer<WarrantyEvalLabourObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const WarrantyEvalLabour &model);
    friend QDataStream &operator>>(QDataStream &ds, WarrantyEvalLabour &model);
};

Q_DECLARE_METATYPE(WarrantyEvalLabour)
Q_DECLARE_METATYPE(QList<WarrantyEvalLabour>)

#endif // WARRANTYEVALLABOUR_H
