#include "eqppartnocontrolvalidator.h"

EqpPartNoControlValidator::EqpPartNoControlValidator() : TFormValidator()
{
    setRule("ShelfLifeUnit", Tf::MaxLength, 16);
}
