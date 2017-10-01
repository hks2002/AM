#include <TreeFrogModel>
#include "workpackagebuilder.h"
#include "workpackagebuilderobject.h"
#include "eqppartno.h"
#include "eqpassmbl.h"
#include "tasktask.h"
#include "refworkpackagetype.h"

WorkpackageBuilder::WorkpackageBuilder()
    : TAbstractModel(), d(new WorkpackageBuilderObject())
{
    d->workpackage_builder_id = 0;
    d->task_id = 0;
    d->assmbl_id = 0;
    d->part_no_id = 0;
}

WorkpackageBuilder::WorkpackageBuilder(const WorkpackageBuilder &other)
    : TAbstractModel(), d(new WorkpackageBuilderObject(*other.d))
{ }

WorkpackageBuilder::WorkpackageBuilder(const WorkpackageBuilderObject &object)
    : TAbstractModel(), d(new WorkpackageBuilderObject(object))
{ }

WorkpackageBuilder::~WorkpackageBuilder()
{
    // If the reference count becomes 0,
    // the shared data object 'WorkpackageBuilderObject' is deleted.
}

int WorkpackageBuilder::workpackageBuilderId() const
{
    return d->workpackage_builder_id;
}

QString WorkpackageBuilder::workpackageBuilderName() const
{
    return d->workpackage_builder_name;
}

void WorkpackageBuilder::setWorkpackageBuilderName(const QString &workpackageBuilderName)
{
    d->workpackage_builder_name = workpackageBuilderName;
}

QString WorkpackageBuilder::workpackageTypeCd() const
{
    return d->workpackage_type_cd;
}

void WorkpackageBuilder::setWorkpackageTypeCd(const QString &workpackageTypeCd)
{
    d->workpackage_type_cd = workpackageTypeCd;
}

QString WorkpackageBuilder::workpackageNameString() const
{
    return d->workpackage_name_string;
}

void WorkpackageBuilder::setWorkpackageNameString(const QString &workpackageNameString)
{
    d->workpackage_name_string = workpackageNameString;
}

int WorkpackageBuilder::taskId() const
{
    return d->task_id;
}

void WorkpackageBuilder::setTaskId(int taskId)
{
    d->task_id = taskId;
}

int WorkpackageBuilder::assmblId() const
{
    return d->assmbl_id;
}

void WorkpackageBuilder::setAssmblId(int assmblId)
{
    d->assmbl_id = assmblId;
}

int WorkpackageBuilder::partNoId() const
{
    return d->part_no_id;
}

void WorkpackageBuilder::setPartNoId(int partNoId)
{
    d->part_no_id = partNoId;
}

QDateTime WorkpackageBuilder::createdAt() const
{
    return d->created_at;
}

QString WorkpackageBuilder::createdBy() const
{
    return d->created_by;
}

void WorkpackageBuilder::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime WorkpackageBuilder::updatedAt() const
{
    return d->updated_at;
}

QString WorkpackageBuilder::updatedBy() const
{
    return d->updated_by;
}

void WorkpackageBuilder::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

EqpPartNo WorkpackageBuilder::eqpPartNoBypartNoId() const
{
 return EqpPartNo::get(d->part_no_id);
}

EqpAssmbl WorkpackageBuilder::eqpAssmblByassmblId() const
{
 return EqpAssmbl::get(d->assmbl_id);
}

TaskTask WorkpackageBuilder::taskTaskBytaskId() const
{
 return TaskTask::get(d->task_id);
}

RefWorkpackageType WorkpackageBuilder::refWorkpackageTypeByworkpackageTypeCd() const
{
 return RefWorkpackageType::get(d->workpackage_type_cd);
}

WorkpackageBuilder &WorkpackageBuilder::operator=(const WorkpackageBuilder &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

WorkpackageBuilder WorkpackageBuilder::create(const QString &workpackageBuilderName, const QString &workpackageTypeCd, const QString &workpackageNameString, int taskId, int assmblId, int partNoId, const QString &createdBy, const QString &updatedBy)
{
    WorkpackageBuilderObject obj;
    obj.workpackage_builder_name = workpackageBuilderName;
    obj.workpackage_type_cd = workpackageTypeCd;
    obj.workpackage_name_string = workpackageNameString;
    obj.task_id = taskId;
    obj.assmbl_id = assmblId;
    obj.part_no_id = partNoId;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return WorkpackageBuilder();
    }
    return WorkpackageBuilder(obj);
}

WorkpackageBuilder WorkpackageBuilder::create(const QVariantMap &values)
{
    WorkpackageBuilder model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

WorkpackageBuilder WorkpackageBuilder::get(int workpackageBuilderId)
{
    TSqlORMapper<WorkpackageBuilderObject> mapper;
    return WorkpackageBuilder(mapper.findByPrimaryKey(workpackageBuilderId));
}

int WorkpackageBuilder::count()
{
    TSqlORMapper<WorkpackageBuilderObject> mapper;
    return mapper.findCount();
}

QList<WorkpackageBuilder> WorkpackageBuilder::getAll()
{
    return tfGetModelListByCriteria<WorkpackageBuilder, WorkpackageBuilderObject>();
}

TModelObject *WorkpackageBuilder::modelData()
{
    return d.data();
}

const TModelObject *WorkpackageBuilder::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const WorkpackageBuilder &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, WorkpackageBuilder &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(WorkpackageBuilder)
