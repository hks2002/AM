#include "refthresholdmodevalidator.h"

RefThresholdModeValidator::RefThresholdModeValidator() : TFormValidator()
{
    /* Rule will auto add Tf::isRequired,Disable it as required.*/

    //setRule("thresholdModeNameEn", Tf::Required, false);
    //setRule("thresholdModeNameZh", Tf::Required, false);
    //setRule("thresholdModeDesc", Tf::Required, false);

 
    setRule("thresholdModeNameEn", Tf::MaxLength, 64);
    setRule("thresholdModeNameZh", Tf::MaxLength, 64);

}
