#ifndef FLIGHTLEGNOTE_H
#define FLIGHTLEGNOTE_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class FlightLegNoteObject;
class UserApp;
class FlightLeg;


class T_MODEL_EXPORT FlightLegNote : public TAbstractModel
{
public:
    FlightLegNote();
    FlightLegNote(const FlightLegNote &other);
    FlightLegNote(const FlightLegNoteObject &object);
    ~FlightLegNote();

    int legId() const;
    void setLegId(int legId);
    QDateTime noteDt() const;
    void setNoteDt(const QDateTime &noteDt);
    bool systemBool() const;
    void setSystemBool(bool systemBool);
    int noteBy() const;
    void setNoteBy(int noteBy);
    QString noteText() const;
    void setNoteText(const QString &noteText);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    UserApp userAppBynoteBy() const;
    FlightLeg flightLegBylegId() const;
    FlightLegNote &operator=(const FlightLegNote &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static FlightLegNote create(int legId, const QDateTime &noteDt, bool systemBool, int noteBy, const QString &noteText, const QString &createdBy, const QString &updatedBy);
    static FlightLegNote create(const QVariantMap &values);
    static FlightLegNote get(int legId);
    static int count();
    static QList<FlightLegNote> getAll();

private:
    QSharedDataPointer<FlightLegNoteObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const FlightLegNote &model);
    friend QDataStream &operator>>(QDataStream &ds, FlightLegNote &model);
};

Q_DECLARE_METATYPE(FlightLegNote)
Q_DECLARE_METATYPE(QList<FlightLegNote>)

#endif // FLIGHTLEGNOTE_H
