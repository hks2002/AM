#include "workpackagebuildervalidator.h"

WorkpackageBuilderValidator::WorkpackageBuilderValidator() : TFormValidator()
{
    setRule("WorkpackageBuilderName", Tf::MaxLength, 64);
    setRule("WorkpackageTypeCd", Tf::MaxLength, 16);
    setRule("WorkpackageNameString", Tf::MaxLength, 256);
}
