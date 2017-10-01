#ifndef REFLABOURSTAGE_H
#define REFLABOURSTAGE_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class RefLabourStageObject;


class T_MODEL_EXPORT RefLabourStage : public TAbstractModel
{
public:
    RefLabourStage();
    RefLabourStage(const RefLabourStage &other);
    RefLabourStage(const RefLabourStageObject &object);
    ~RefLabourStage();

    QString labourStageCd() const;
    void setLabourStageCd(const QString &labourStageCd);
    QString labourStageNameEn() const;
    void setLabourStageNameEn(const QString &labourStageNameEn);
    QString labourStageNameZh() const;
    void setLabourStageNameZh(const QString &labourStageNameZh);
    QString labourStageDesc() const;
    void setLabourStageDesc(const QString &labourStageDesc);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    RefLabourStage &operator=(const RefLabourStage &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static RefLabourStage create(const QString &labourStageCd, const QString &labourStageNameEn, const QString &labourStageNameZh, const QString &labourStageDesc, const QString &createdBy, const QString &updatedBy);
    static RefLabourStage create(const QVariantMap &values);
    static RefLabourStage get(const QString &labourStageCd);
    static int count();
    static QList<RefLabourStage> getAll();

private:
    QSharedDataPointer<RefLabourStageObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const RefLabourStage &model);
    friend QDataStream &operator>>(QDataStream &ds, RefLabourStage &model);
};

Q_DECLARE_METATYPE(RefLabourStage)
Q_DECLARE_METATYPE(QList<RefLabourStage>)

#endif // REFLABOURSTAGE_H
