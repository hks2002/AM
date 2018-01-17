#include "manufactattachmentvalidator.h"

ManufactAttachmentValidator::ManufactAttachmentValidator() : TFormValidator()
{
    /* Rule will auto add Tf::isRequired,Disable it as required.*/

    //setRule("manufactId", Tf::Required, false);
    //setRule("fileSaveCd", Tf::Required, false);
    //setRule("blobData", Tf::Required, false);
    //setRule("blobFileName", Tf::Required, false);
    //setRule("blobFilePath", Tf::Required, false);
    //setRule("blobNote", Tf::Required, false);

 
    setRule("fileSaveCd", Tf::MaxLength, 16);
    setRule("blobFileName", Tf::MaxLength, 256);
    setRule("blobFilePath", Tf::MaxLength, 256);

}
