#include "refshipmenttypevalidator.h"

RefShipmentTypeValidator::RefShipmentTypeValidator() : TFormValidator()
{
    /* Rule will auto add Tf::isRequired,Disable it as required.*/

    //setRule("shipmentTypeNameEn", Tf::Required, false);
    //setRule("shipmentTypeNameZh", Tf::Required, false);
    //setRule("shipmentTypeDesc", Tf::Required, false);

 
    setRule("shipmentTypeNameEn", Tf::MaxLength, 64);
    setRule("shipmentTypeNameZh", Tf::MaxLength, 64);

}
