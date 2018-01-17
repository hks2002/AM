#include "refhazmatdefvalidator.h"

RefHazmatDefValidator::RefHazmatDefValidator() : TFormValidator()
{
    /* Rule will auto add Tf::isRequired,Disable it as required.*/

    //setRule("hazmatDefNameEn", Tf::Required, false);
    //setRule("hazmatDefNameZh", Tf::Required, false);
    //setRule("hazmatDefDesc", Tf::Required, false);

 
    setRule("hazmatDefNameEn", Tf::MaxLength, 64);
    setRule("hazmatDefNameZh", Tf::MaxLength, 64);

}
