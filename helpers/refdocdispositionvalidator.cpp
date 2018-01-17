#include "refdocdispositionvalidator.h"

RefDocDispositionValidator::RefDocDispositionValidator() : TFormValidator()
{
    /* Rule will auto add Tf::isRequired,Disable it as required.*/

    //setRule("docDispositionNameEn", Tf::Required, false);
    //setRule("docDispositionNameZh", Tf::Required, false);
    //setRule("docDispositionDesc", Tf::Required, false);

 
    setRule("docDispositionNameEn", Tf::MaxLength, 64);
    setRule("docDispositionNameZh", Tf::MaxLength, 64);

}
