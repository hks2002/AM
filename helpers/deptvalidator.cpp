#include "deptvalidator.h"

DeptValidator::DeptValidator() : TFormValidator()
{
    setRule("DeptCd", Tf::MaxLength, 16);
    setRule("DeptName", Tf::MaxLength, 64);
}
