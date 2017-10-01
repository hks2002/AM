#include "warrantydefnattachmentvalidator.h"

WarrantyDefnAttachmentValidator::WarrantyDefnAttachmentValidator() : TFormValidator()
{
    setRule("FileSaveCd", Tf::MaxLength, 16);
    setRule("BlobFileName", Tf::MaxLength, 256);
    setRule("BlobFilePath", Tf::MaxLength, 256);
}
