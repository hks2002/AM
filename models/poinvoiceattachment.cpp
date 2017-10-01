#include <TreeFrogModel>
#include "poinvoiceattachment.h"
#include "poinvoiceattachmentobject.h"
#include "reffilesave.h"
#include "poinvoice.h"

PoInvoiceAttachment::PoInvoiceAttachment()
    : TAbstractModel(), d(new PoInvoiceAttachmentObject())
{
    d->po_invoice_attachment_id = 0;
    d->po_invoice_id = 0;
}

PoInvoiceAttachment::PoInvoiceAttachment(const PoInvoiceAttachment &other)
    : TAbstractModel(), d(new PoInvoiceAttachmentObject(*other.d))
{ }

PoInvoiceAttachment::PoInvoiceAttachment(const PoInvoiceAttachmentObject &object)
    : TAbstractModel(), d(new PoInvoiceAttachmentObject(object))
{ }

PoInvoiceAttachment::~PoInvoiceAttachment()
{
    // If the reference count becomes 0,
    // the shared data object 'PoInvoiceAttachmentObject' is deleted.
}

int PoInvoiceAttachment::poInvoiceAttachmentId() const
{
    return d->po_invoice_attachment_id;
}

int PoInvoiceAttachment::poInvoiceId() const
{
    return d->po_invoice_id;
}

void PoInvoiceAttachment::setPoInvoiceId(int poInvoiceId)
{
    d->po_invoice_id = poInvoiceId;
}

QString PoInvoiceAttachment::fileSaveCd() const
{
    return d->file_save_cd;
}

void PoInvoiceAttachment::setFileSaveCd(const QString &fileSaveCd)
{
    d->file_save_cd = fileSaveCd;
}

QByteArray PoInvoiceAttachment::blobData() const
{
    return d->blob_data;
}

void PoInvoiceAttachment::setBlobData(const QByteArray &blobData)
{
    d->blob_data = blobData;
}

QString PoInvoiceAttachment::blobFileName() const
{
    return d->blob_file_name;
}

void PoInvoiceAttachment::setBlobFileName(const QString &blobFileName)
{
    d->blob_file_name = blobFileName;
}

QString PoInvoiceAttachment::blobFilePath() const
{
    return d->blob_file_path;
}

void PoInvoiceAttachment::setBlobFilePath(const QString &blobFilePath)
{
    d->blob_file_path = blobFilePath;
}

QString PoInvoiceAttachment::blobNote() const
{
    return d->blob_note;
}

void PoInvoiceAttachment::setBlobNote(const QString &blobNote)
{
    d->blob_note = blobNote;
}

QDateTime PoInvoiceAttachment::createdAt() const
{
    return d->created_at;
}

QString PoInvoiceAttachment::createdBy() const
{
    return d->created_by;
}

void PoInvoiceAttachment::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime PoInvoiceAttachment::updatedAt() const
{
    return d->updated_at;
}

QString PoInvoiceAttachment::updatedBy() const
{
    return d->updated_by;
}

void PoInvoiceAttachment::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

RefFileSave PoInvoiceAttachment::refFileSaveByfileSaveCd() const
{
 return RefFileSave::get(d->file_save_cd);
}

PoInvoice PoInvoiceAttachment::poInvoiceBypoInvoiceId() const
{
 return PoInvoice::get(d->po_invoice_id);
}

PoInvoiceAttachment &PoInvoiceAttachment::operator=(const PoInvoiceAttachment &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

PoInvoiceAttachment PoInvoiceAttachment::create(int poInvoiceId, const QString &fileSaveCd, const QByteArray &blobData, const QString &blobFileName, const QString &blobFilePath, const QString &blobNote, const QString &createdBy, const QString &updatedBy)
{
    PoInvoiceAttachmentObject obj;
    obj.po_invoice_id = poInvoiceId;
    obj.file_save_cd = fileSaveCd;
    obj.blob_data = blobData;
    obj.blob_file_name = blobFileName;
    obj.blob_file_path = blobFilePath;
    obj.blob_note = blobNote;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return PoInvoiceAttachment();
    }
    return PoInvoiceAttachment(obj);
}

PoInvoiceAttachment PoInvoiceAttachment::create(const QVariantMap &values)
{
    PoInvoiceAttachment model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

PoInvoiceAttachment PoInvoiceAttachment::get(int poInvoiceAttachmentId)
{
    TSqlORMapper<PoInvoiceAttachmentObject> mapper;
    return PoInvoiceAttachment(mapper.findByPrimaryKey(poInvoiceAttachmentId));
}

int PoInvoiceAttachment::count()
{
    TSqlORMapper<PoInvoiceAttachmentObject> mapper;
    return mapper.findCount();
}

QList<PoInvoiceAttachment> PoInvoiceAttachment::getAll()
{
    return tfGetModelListByCriteria<PoInvoiceAttachment, PoInvoiceAttachmentObject>();
}

TModelObject *PoInvoiceAttachment::modelData()
{
    return d.data();
}

const TModelObject *PoInvoiceAttachment::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const PoInvoiceAttachment &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, PoInvoiceAttachment &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(PoInvoiceAttachment)
