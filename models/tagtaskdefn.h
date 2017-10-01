#ifndef TAGTASKDEFN_H
#define TAGTASKDEFN_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class TagTaskDefnObject;
class TaskDefn;
class TagTag;


class T_MODEL_EXPORT TagTaskDefn : public TAbstractModel
{
public:
    TagTaskDefn();
    TagTaskDefn(const TagTaskDefn &other);
    TagTaskDefn(const TagTaskDefnObject &object);
    ~TagTaskDefn();

    int tagId() const;
    void setTagId(int tagId);
    int taskDefnId() const;
    void setTaskDefnId(int taskDefnId);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    TaskDefn taskDefnBytaskDefnId() const;
    TagTag tagTagBytagId() const;
    TagTaskDefn &operator=(const TagTaskDefn &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static TagTaskDefn create(int tagId, int taskDefnId, const QString &createdBy, const QString &updatedBy);
    static TagTaskDefn create(const QVariantMap &values);
    static TagTaskDefn get(int tagId, int taskDefnId);
    static int count();
    static QList<TagTaskDefn> getAll();

private:
    QSharedDataPointer<TagTaskDefnObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const TagTaskDefn &model);
    friend QDataStream &operator>>(QDataStream &ds, TagTaskDefn &model);
};

Q_DECLARE_METATYPE(TagTaskDefn)
Q_DECLARE_METATYPE(QList<TagTaskDefn>)

#endif // TAGTASKDEFN_H
