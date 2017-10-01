#ifndef WARRANTYEVAL_H
#define WARRANTYEVAL_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class WarrantyEvalObject;
class UserApp;
class RefWarrantyEvalStatus;
class WarrantyInit;


class T_MODEL_EXPORT WarrantyEval : public TAbstractModel
{
public:
    WarrantyEval();
    WarrantyEval(const WarrantyEval &other);
    WarrantyEval(const WarrantyEvalObject &object);
    ~WarrantyEval();

    int warrantyEvalId() const;
    int warrantyInitId() const;
    void setWarrantyInitId(int warrantyInitId);
    QString warrantyEvalStatusCd() const;
    void setWarrantyEvalStatusCd(const QString &warrantyEvalStatusCd);
    int rejectBy() const;
    void setRejectBy(int rejectBy);
    QDateTime rejectDt() const;
    void setRejectDt(const QDateTime &rejectDt);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    UserApp userAppByrejectBy() const;
    RefWarrantyEvalStatus refWarrantyEvalStatusBywarrantyEvalStatusCd() const;
    WarrantyInit warrantyInitBywarrantyInitId() const;
    WarrantyEval &operator=(const WarrantyEval &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static WarrantyEval create(int warrantyInitId, const QString &warrantyEvalStatusCd, int rejectBy, const QDateTime &rejectDt, const QString &createdBy, const QString &updatedBy);
    static WarrantyEval create(const QVariantMap &values);
    static WarrantyEval get(int warrantyEvalId);
    static int count();
    static QList<WarrantyEval> getAll();

private:
    QSharedDataPointer<WarrantyEvalObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const WarrantyEval &model);
    friend QDataStream &operator>>(QDataStream &ds, WarrantyEval &model);
};

Q_DECLARE_METATYPE(WarrantyEval)
Q_DECLARE_METATYPE(QList<WarrantyEval>)

#endif // WARRANTYEVAL_H
