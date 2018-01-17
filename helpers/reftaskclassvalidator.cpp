#include "reftaskclassvalidator.h"

RefTaskClassValidator::RefTaskClassValidator() : TFormValidator()
{
    /* Rule will auto add Tf::isRequired,Disable it as required.*/

    //setRule("taskClassNameEn", Tf::Required, false);
    //setRule("taskClassNameZh", Tf::Required, false);
    //setRule("taskClassDesc", Tf::Required, false);

 
    setRule("taskClassNameEn", Tf::MaxLength, 64);
    setRule("taskClassNameZh", Tf::MaxLength, 64);

}
