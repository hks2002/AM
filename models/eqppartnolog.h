#ifndef EQPPARTNOLOG_H
#define EQPPARTNOLOG_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class EqpPartNoLogObject;
class RefLogAction;
class EqpPartNo;


class T_MODEL_EXPORT EqpPartNoLog : public TAbstractModel
{
public:
    EqpPartNoLog();
    EqpPartNoLog(const EqpPartNoLog &other);
    EqpPartNoLog(const EqpPartNoLogObject &object);
    ~EqpPartNoLog();

    int partNoLogId() const;
    int partNoId() const;
    void setPartNoId(int partNoId);
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
    EqpPartNo eqpPartNoBypartNoId() const;
    EqpPartNoLog &operator=(const EqpPartNoLog &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static EqpPartNoLog create(int partNoId, const QString &logActionCd, const QString &userNote, const QString &systemNote, const QString &createdBy, const QString &updatedBy);
    static EqpPartNoLog create(const QVariantMap &values);
    static EqpPartNoLog get(int partNoLogId);
    static int count();
    static QList<EqpPartNoLog> getAll();

private:
    QSharedDataPointer<EqpPartNoLogObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const EqpPartNoLog &model);
    friend QDataStream &operator>>(QDataStream &ds, EqpPartNoLog &model);
};

Q_DECLARE_METATYPE(EqpPartNoLog)
Q_DECLARE_METATYPE(QList<EqpPartNoLog>)

#endif // EQPPARTNOLOG_H
