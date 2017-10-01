#include "eqppartnovalidator.h"

EqpPartNoValidator::EqpPartNoValidator() : TFormValidator()
{
    setRule("PartNoOem", Tf::MaxLength, 64);
    setRule("PartNoName", Tf::MaxLength, 64);
    setRule("ModelName", Tf::MaxLength, 16);
    setRule("PartStatusCd", Tf::MaxLength, 16);
    setRule("InvClassCd", Tf::MaxLength, 16);
    setRule("PartUseCd", Tf::MaxLength, 16);
    setRule("PartTypeCd", Tf::MaxLength, 16);
}
