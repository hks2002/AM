#include "datatypevalidator.h"

DataTypeValidator::DataTypeValidator() : TFormValidator()
{
    setRule("DataTypeCd", Tf::MaxLength, 16);
    setRule("DataTypeName", Tf::MaxLength, 64);
    setRule("EngUnitCd", Tf::MaxLength, 16);
}
