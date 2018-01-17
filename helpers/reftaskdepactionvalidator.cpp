#include "reftaskdepactionvalidator.h"

RefTaskDepActionValidator::RefTaskDepActionValidator() : TFormValidator()
{
    /* Rule will auto add Tf::isRequired,Disable it as required.*/

    //setRule("taskDepActionNameEn", Tf::Required, false);
    //setRule("taskDepActionNameZh", Tf::Required, false);
    //setRule("taskDepActionDesc", Tf::Required, false);

 
    setRule("taskDepActionNameEn", Tf::MaxLength, 64);
    setRule("taskDepActionNameZh", Tf::MaxLength, 64);

}
