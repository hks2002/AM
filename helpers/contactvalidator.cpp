#include "contactvalidator.h"

ContactValidator::ContactValidator() : TFormValidator()
{
    setRule("AddressEmail", Tf::MaxLength, 64);
    setRule("ContactName", Tf::MaxLength, 16);
    setRule("JobTitle", Tf::MaxLength, 16);
    setRule("FaxPh", Tf::MaxLength, 16);
    setRule("PhonePh", Tf::MaxLength, 16);
}
