#include "invinvvalidator.h"

InvInvValidator::InvInvValidator() : TFormValidator()
{
    setRule("InvClassCd", Tf::MaxLength, 16);
    setRule("ConfigPosDesc", Tf::MaxLength, 64);
    setRule("SerialNoOem", Tf::MaxLength, 64);
    setRule("BatchNoOem", Tf::MaxLength, 64);
    setRule("IcnNoDesc", Tf::MaxLength, 64);
    setRule("ApplEffCd", Tf::MaxLength, 64);
    setRule("InvNoDesc", Tf::MaxLength, 256);
    setRule("LotOemTag", Tf::MaxLength, 64);
    setRule("ModStatusNote", Tf::MaxLength, 64);
    setRule("BarcodeDesc", Tf::MaxLength, 256);
    setRule("InvCondCd", Tf::MaxLength, 16);
    setRule("ReceiveCondCd", Tf::MaxLength, 16);
    setRule("OrigAssmblCd", Tf::MaxLength, 16);
    setRule("OwnByCd", Tf::MaxLength, 16);
    setRule("ReleaseNumber", Tf::MaxLength, 64);
}
