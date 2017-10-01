#ifndef TAGTAG_H
#define TAGTAG_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class TagTagObject;


class T_MODEL_EXPORT TagTag : public TAbstractModel
{
public:
    TagTag();
    TagTag(const TagTag &other);
    TagTag(const TagTagObject &object);
    ~TagTag();

    int tagId() const;
    QString tagCd() const;
    void setTagCd(const QString &tagCd);
    QString tagDesc() const;
    void setTagDesc(const QString &tagDesc);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    TagTag &operator=(const TagTag &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static TagTag create(const QString &tagCd, const QString &tagDesc, const QString &createdBy, const QString &updatedBy);
    static TagTag create(const QVariantMap &values);
    static TagTag get(int tagId);
    static int count();
    static QList<TagTag> getAll();

private:
    QSharedDataPointer<TagTagObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const TagTag &model);
    friend QDataStream &operator>>(QDataStream &ds, TagTag &model);
};

Q_DECLARE_METATYPE(TagTag)
Q_DECLARE_METATYPE(QList<TagTag>)

#endif // TAGTAG_H
