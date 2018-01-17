#include "refsegmentstatusvalidator.h"

RefSegmentStatusValidator::RefSegmentStatusValidator() : TFormValidator()
{
    /* Rule will auto add Tf::isRequired,Disable it as required.*/

    //setRule("segmentStatusNameEn", Tf::Required, false);
    //setRule("segmentStatusNameZh", Tf::Required, false);
    //setRule("segmentStatusDesc", Tf::Required, false);

 
    setRule("segmentStatusNameEn", Tf::MaxLength, 64);
    setRule("segmentStatusNameZh", Tf::MaxLength, 64);

}
