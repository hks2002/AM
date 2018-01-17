#include "refmesurtypevalidator.h"

RefMesurTypeValidator::RefMesurTypeValidator() : TFormValidator()
{
    /* Rule will auto add Tf::isRequired,Disable it as required.*/

    //setRule("mesurTypeNameEn", Tf::Required, false);
    //setRule("mesurTypeNameZh", Tf::Required, false);
    //setRule("mesurTypeDesc", Tf::Required, false);

 
    setRule("mesurTypeNameEn", Tf::MaxLength, 64);
    setRule("mesurTypeNameZh", Tf::MaxLength, 64);

}
