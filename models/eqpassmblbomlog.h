#ifndef EQPASSMBLBOMLOG_H
#define EQPASSMBLBOMLOG_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class EqpAssmblBomLogObject;
class RefLogAction;
class EqpAssmblBom;
class EqpAssmbl;


class T_MODEL_EXPORT EqpAssmblBomLog : public TAbstractModel
{
public:
    EqpAssmblBomLog();
    EqpAssmblBomLog(const EqpAssmblBomLog &other);
    EqpAssmblBomLog(const EqpAssmblBomLogObject &object);
    ~EqpAssmblBomLog();

    int assmblBomLogId() const;
    int assmblId() const;
    void setAssmblId(int assmblId);
    int assmblBomId() const;
    void setAssmblBomId(int assmblBomId);
    QString logActionCd() const;
    void setLogActionCd(const QString &logActionCd);
    QString userNote() const;
    void setUserNote(const QString &userNote);
    QString systemNote() const;
    void setSystemNote(const QString &systemNote);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    RefLogAction refLogActionBylogActionCd() const;
    EqpAssmblBom eqpAssmblBomByassmblBomId() const;
    EqpAssmbl eqpAssmblByassmblId() const;
    EqpAssmblBomLog &operator=(const EqpAssmblBomLog &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static EqpAssmblBomLog create(int assmblId, int assmblBomId, const QString &logActionCd, const QString &userNote, const QString &systemNote, const QString &createdBy, const QString &updatedBy);
    static EqpAssmblBomLog create(const QVariantMap &values);
    static EqpAssmblBomLog get(int assmblBomLogId);
    static int count();
    static QList<EqpAssmblBomLog> getAll();

private:
    QSharedDataPointer<EqpAssmblBomLogObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const EqpAssmblBomLog &model);
    friend QDataStream &operator>>(QDataStream &ds, EqpAssmblBomLog &model);
};

Q_DECLARE_METATYPE(EqpAssmblBomLog)
Q_DECLARE_METATYPE(QList<EqpAssmblBomLog>)

#endif // EQPASSMBLBOMLOG_H
