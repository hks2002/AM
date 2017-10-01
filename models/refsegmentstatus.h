#ifndef REFSEGMENTSTATUS_H
#define REFSEGMENTSTATUS_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class RefSegmentStatusObject;


class T_MODEL_EXPORT RefSegmentStatus : public TAbstractModel
{
public:
    RefSegmentStatus();
    RefSegmentStatus(const RefSegmentStatus &other);
    RefSegmentStatus(const RefSegmentStatusObject &object);
    ~RefSegmentStatus();

    QString segmentStatusCd() const;
    void setSegmentStatusCd(const QString &segmentStatusCd);
    QString segmentStatusNameEn() const;
    void setSegmentStatusNameEn(const QString &segmentStatusNameEn);
    QString segmentStatusNameZh() const;
    void setSegmentStatusNameZh(const QString &segmentStatusNameZh);
    QString segmentStatusDesc() const;
    void setSegmentStatusDesc(const QString &segmentStatusDesc);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    RefSegmentStatus &operator=(const RefSegmentStatus &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static RefSegmentStatus create(const QString &segmentStatusCd, const QString &segmentStatusNameEn, const QString &segmentStatusNameZh, const QString &segmentStatusDesc, const QString &createdBy, const QString &updatedBy);
    static RefSegmentStatus create(const QVariantMap &values);
    static RefSegmentStatus get(const QString &segmentStatusCd);
    static int count();
    static QList<RefSegmentStatus> getAll();

private:
    QSharedDataPointer<RefSegmentStatusObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const RefSegmentStatus &model);
    friend QDataStream &operator>>(QDataStream &ds, RefSegmentStatus &model);
};

Q_DECLARE_METATYPE(RefSegmentStatus)
Q_DECLARE_METATYPE(QList<RefSegmentStatus>)

#endif // REFSEGMENTSTATUS_H
