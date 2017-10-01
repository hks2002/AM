#ifndef POLINEDOC_H
#define POLINEDOC_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class PoLineDocObject;
class RegBodyDoc;
class PoLine;


class T_MODEL_EXPORT PoLineDoc : public TAbstractModel
{
public:
    PoLineDoc();
    PoLineDoc(const PoLineDoc &other);
    PoLineDoc(const PoLineDocObject &object);
    ~PoLineDoc();

    int poLineId() const;
    void setPoLineId(int poLineId);
    int regBodyDocId() const;
    void setRegBodyDocId(int regBodyDocId);
    bool receivedDocBool() const;
    void setReceivedDocBool(bool receivedDocBool);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    RegBodyDoc regBodyDocByregBodyDocId() const;
    PoLine poLineBypoLineId() const;
    PoLineDoc &operator=(const PoLineDoc &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static PoLineDoc create(int poLineId, int regBodyDocId, bool receivedDocBool, const QString &createdBy, const QString &updatedBy);
    static PoLineDoc create(const QVariantMap &values);
    static PoLineDoc get(int poLineId, int regBodyDocId);
    static int count();
    static QList<PoLineDoc> getAll();

private:
    QSharedDataPointer<PoLineDocObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const PoLineDoc &model);
    friend QDataStream &operator>>(QDataStream &ds, PoLineDoc &model);
};

Q_DECLARE_METATYPE(PoLineDoc)
Q_DECLARE_METATYPE(QList<PoLineDoc>)

#endif // POLINEDOC_H
