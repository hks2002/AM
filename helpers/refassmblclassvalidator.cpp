#include "refassmblclassvalidator.h"

RefAssmblClassValidator::RefAssmblClassValidator() : TFormValidator()
{
    /* Rule will auto add Tf::isRequired,Disable it as required.*/

    //setRule("assmblClassNameEn", Tf::Required, false);
    //setRule("assmblClassNameZh", Tf::Required, false);
    //setRule("assmblClassDesc", Tf::Required, false);

 
    setRule("assmblClassNameEn", Tf::MaxLength, 64);
    setRule("assmblClassNameZh", Tf::MaxLength, 64);

}
