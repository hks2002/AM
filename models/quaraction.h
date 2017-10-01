#ifndef QUARACTION_H
#define QUARACTION_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class QuarActionObject;
class UserApp;
class QuarQuar;


class T_MODEL_EXPORT QuarAction : public TAbstractModel
{
public:
    QuarAction();
    QuarAction(const QuarAction &other);
    QuarAction(const QuarActionObject &object);
    ~QuarAction();

    int quarActionId() const;
    int quarId() const;
    void setQuarId(int quarId);
    QString actionDesc() const;
    void setActionDesc(const QString &actionDesc);
    QString actionNote() const;
    void setActionNote(const QString &actionNote);
    bool quarActionOpenBool() const;
    void setQuarActionOpenBool(bool quarActionOpenBool);
    QString discrepancyDesc() const;
    void setDiscrepancyDesc(const QString &discrepancyDesc);
    int quarActionSeq() const;
    void setQuarActionSeq(int quarActionSeq);
    int userId() const;
    void setUserId(int userId);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    UserApp userAppByuserId() const;
    QuarQuar quarQuarByquarId() const;
    QuarAction &operator=(const QuarAction &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static QuarAction create(int quarId, const QString &actionDesc, const QString &actionNote, bool quarActionOpenBool, const QString &discrepancyDesc, int quarActionSeq, int userId, const QString &createdBy, const QString &updatedBy);
    static QuarAction create(const QVariantMap &values);
    static QuarAction get(int quarActionId);
    static int count();
    static QList<QuarAction> getAll();

private:
    QSharedDataPointer<QuarActionObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const QuarAction &model);
    friend QDataStream &operator>>(QDataStream &ds, QuarAction &model);
};

Q_DECLARE_METATYPE(QuarAction)
Q_DECLARE_METATYPE(QList<QuarAction>)

#endif // QUARACTION_H
