#ifndef MAINTPRGMLOG_H
#define MAINTPRGMLOG_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class MaintPrgmLogObject;
class RefLogAction;
class MaintPrgm;


class T_MODEL_EXPORT MaintPrgmLog : public TAbstractModel
{
public:
    MaintPrgmLog();
    MaintPrgmLog(const MaintPrgmLog &other);
    MaintPrgmLog(const MaintPrgmLogObject &object);
    ~MaintPrgmLog();

    int maintPrgmLogId() const;
    int maintPrgmId() const;
    void setMaintPrgmId(int maintPrgmId);
    QString logActionCd() const;
    void setLogActionCd(const QString &logActionCd);
    QDateTime logDt() const;
    void setLogDt(const QDateTime &logDt);
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
    MaintPrgm maintPrgmBymaintPrgmId() const;
    MaintPrgmLog &operator=(const MaintPrgmLog &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static MaintPrgmLog create(int maintPrgmId, const QString &logActionCd, const QDateTime &logDt, const QString &userNote, const QString &systemNote, const QString &createdBy, const QString &updatedBy);
    static MaintPrgmLog create(const QVariantMap &values);
    static MaintPrgmLog get(int maintPrgmLogId);
    static int count();
    static QList<MaintPrgmLog> getAll();

private:
    QSharedDataPointer<MaintPrgmLogObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const MaintPrgmLog &model);
    friend QDataStream &operator>>(QDataStream &ds, MaintPrgmLog &model);
};

Q_DECLARE_METATYPE(MaintPrgmLog)
Q_DECLARE_METATYPE(QList<MaintPrgmLog>)

#endif // MAINTPRGMLOG_H
