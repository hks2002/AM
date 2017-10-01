#ifndef WORKTYPE_H
#define WORKTYPE_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class WorkTypeObject;


class T_MODEL_EXPORT WorkType : public TAbstractModel
{
public:
    WorkType();
    WorkType(const WorkType &other);
    WorkType(const WorkTypeObject &object);
    ~WorkType();

    int workTypeId() const;
    QString workTypeCd() const;
    void setWorkTypeCd(const QString &workTypeCd);
    QString workTypeNameZh() const;
    void setWorkTypeNameZh(const QString &workTypeNameZh);
    QString workTypeNameEn() const;
    void setWorkTypeNameEn(const QString &workTypeNameEn);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    WorkType &operator=(const WorkType &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static WorkType create(const QString &workTypeCd, const QString &workTypeNameZh, const QString &workTypeNameEn, const QString &createdBy, const QString &updatedBy);
    static WorkType create(const QVariantMap &values);
    static WorkType get(int workTypeId);
    static int count();
    static QList<WorkType> getAll();

private:
    QSharedDataPointer<WorkTypeObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const WorkType &model);
    friend QDataStream &operator>>(QDataStream &ds, WorkType &model);
};

Q_DECLARE_METATYPE(WorkType)
Q_DECLARE_METATYPE(QList<WorkType>)

#endif // WORKTYPE_H
