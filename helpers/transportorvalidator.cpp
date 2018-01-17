#include "transportorvalidator.h"

TransportorValidator::TransportorValidator() : TFormValidator()
{
    /* Rule will auto add Tf::isRequired,Disable it as required.*/

    //setRule("transportorCd", Tf::Required, false);
    //setRule("transportorNameZh", Tf::Required, false);
    //setRule("transportorNameEn", Tf::Required, false);

 
    setRule("transportorCd", Tf::MaxLength, 16);
    setRule("transportorNameZh", Tf::MaxLength, 64);
    setRule("transportorNameEn", Tf::MaxLength, 64);

}
