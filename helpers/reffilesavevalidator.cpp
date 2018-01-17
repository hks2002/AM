#include "reffilesavevalidator.h"

RefFileSaveValidator::RefFileSaveValidator() : TFormValidator()
{
    /* Rule will auto add Tf::isRequired,Disable it as required.*/

    //setRule("fileSaveNameZh", Tf::Required, false);
    //setRule("fileSaveNameEn", Tf::Required, false);
    //setRule("fileSaveDesc", Tf::Required, false);

 
    setRule("fileSaveNameZh", Tf::MaxLength, 64);
    setRule("fileSaveNameEn", Tf::MaxLength, 64);

}
