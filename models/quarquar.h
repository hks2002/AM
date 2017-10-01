#ifndef QUARQUAR_H
#define QUARQUAR_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class QuarQuarObject;
class Loc;
class InvInv;
class UserApp;


class T_MODEL_EXPORT QuarQuar : public TAbstractModel
{
public:
    QuarQuar();
    QuarQuar(const QuarQuar &other);
    QuarQuar(const QuarQuarObject &object);
    ~QuarQuar();

    int quarId() const;
    QString quarNote() const;
    void setQuarNote(const QString &quarNote);
    QDateTime quarDt() const;
    void setQuarDt(const QDateTime &quarDt);
    int userId() const;
    void setUserId(int userId);
    int invNoId() const;
    void setInvNoId(int invNoId);
    int locId() const;
    void setLocId(int locId);
    bool histBool() const;
    void setHistBool(bool histBool);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    Loc locBylocId() const;
    InvInv invInvByinvNoId() const;
    UserApp userAppByuserId() const;
    QuarQuar &operator=(const QuarQuar &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static QuarQuar create(const QString &quarNote, const QDateTime &quarDt, int userId, int invNoId, int locId, bool histBool, const QString &createdBy, const QString &updatedBy);
    static QuarQuar create(const QVariantMap &values);
    static QuarQuar get(int quarId);
    static int count();
    static QList<QuarQuar> getAll();

private:
    QSharedDataPointer<QuarQuarObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const QuarQuar &model);
    friend QDataStream &operator>>(QDataStream &ds, QuarQuar &model);
};

Q_DECLARE_METATYPE(QuarQuar)
Q_DECLARE_METATYPE(QList<QuarQuar>)

#endif // QUARQUAR_H
