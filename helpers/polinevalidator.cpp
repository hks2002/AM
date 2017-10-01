#include "polinevalidator.h"

PoLineValidator::PoLineValidator() : TFormValidator()
{
    setRule("LineDesc", Tf::MaxLength, 256);
    setRule("PoLineTypeCd", Tf::MaxLength, 16);
    setRule("PriceTypeCd", Tf::MaxLength, 16);
    setRule("NoteToVendor", Tf::MaxLength, 256);
    setRule("NoteToReceiver", Tf::MaxLength, 256);
}
