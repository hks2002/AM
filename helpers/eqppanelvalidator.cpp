#include "eqppanelvalidator.h"

EqpPanelValidator::EqpPanelValidator() : TFormValidator()
{
    setRule("PanelCd", Tf::MaxLength, 16);
    setRule("DescDesc", Tf::MaxLength, 256);
}
