#include "deptvalidator.h"

DeptValidator::DeptValidator() : TFormValidator()
{
    /* Rule will auto add Tf::isRequired,Disable it as required.*/

    //setRule("deptCd", Tf::Required, false);
    //setRule("deptNameZh", Tf::Required, false);
    //setRule("deptNameEn", Tf::Required, false);
    //setRule("deptDesc", Tf::Required, false);

 
    setRule("deptCd", Tf::MaxLength, 16);
    setRule("deptNameZh", Tf::MaxLength, 64);
    setRule("deptNameEn", Tf::MaxLength, 64);

}
