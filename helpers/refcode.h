#ifndef REFCODE_H
#define REFCODE_H
#include <QObject>

//Use QMetaEnum me = QMetaEnum::fromType<AM::xxx>()
//     me.keyToValue("PPP");
//to get enum value from String for Switch().

namespace AM
{

enum FileSaveCD {
    DATA = 0,
    PATH,
};
Q_ENUM(FileSaveCD)

enum ClaimToCD {
    VENDOR = 0,
    MANUFACTOR,
    TRANSPORTOR,
};
Q_ENUM(ClaimToCD)

enum AlertStatusCD {
    READED = 0,
    UNREADED,
};
Q_ENUM(AlertStatusCD)

enum AccountTypeCD {
    ADJPRICE = 0,
    ADJQTY,
    AP,
    CHGOWN,
    CONSIGN,
    EXPENSE,
    FIXASSET,
    GROUP,
    INVASSET,
    INVOICE,
    RTVCRED,
    SCRAP,
};
Q_ENUM(AccountTypeCD)

enum AdvsryTypeCD {
    INSTALL = 0,
    PURCHASE,
    PURCHASEINSTALL,
    INFO,
    COMPLETE,
};
Q_ENUM(AdvsryTypeCD)

enum AssmblClassCD {
    ACFT = 0,
    APU,
    COMHW,
    CHEM,
    ENG,
    TSE,
};
Q_ENUM(AssmblClassCD)

enum BomClassCD {
    ROOT = 0,
    SUBASSY,
    SYS,
    SER,
    TRK,
};
Q_ENUM(BomClassCD)

enum BorrowRateCD {
    IATA = 0,
};
Q_ENUM(BorrowRateCD)

enum CancelWhenCD {
    NO = 0,
    ONWING,
    ONPARENT,
    OFFWING,
    OFFPARENT,
};
Q_ENUM(CancelWhenCD)

enum CreateWhenCD {
    TASKACTV = 0,
    MANUAL,
    ONWING,
    ONPARENT,
    OFFWING,
    OFFPARENT,
};
Q_ENUM(CreateWhenCD)

enum CostLineItemTypeCD {
    LABOUR = 0,
    MATPAY,
    MATREC,
};
Q_ENUM(CostLineItemTypeCD)

enum EngUnitCD {
    HR = 0,
    CY,
    CT,
    DY,
    MO,
    YE,
};
Q_ENUM(EngUnitCD)

enum EventReasonCD {
    LXMAINT = 0,
    LXPREDRW,
    LXQUAR,
    LXSTKTRN,
    LXSTOCK,
    LXSTORGE,
    LXTURNIN,
    IXCMAINT,
    IXSMAINT,
    IXDEBIT,
    IXIR,
    IXLVL,
    IXPRESV,
    IXREP,
    IXREPAIR,
    IXRETURN,
    IXTR,
    BLKAI,
    BLKAR,
    BLKHM,
    BLKOOS,
    CFDESIGN,
    CFMAINT,
    CFUSE,
    LOANER,
    ONCOND,
    ROB,
    WARRANTY,
};
Q_ENUM(EventReasonCD)

enum EventStatusCD {
    QA = 0,
    COMEL,
    CCNORM,
    CCETOPS,
    CFCLOSE,
    CFACTV,
    CFPOSS,
    CFREJECT,
    CFCERT,
    CFNFF,
    CFDEFER,
    CFERR,
    IXINTR,
    IXCMPLT,
    IXCANCEL,
    IXPEND,
    ACTV,
    COMMIT,
    ASSIGN,
    UNASSIGN,
    INWORK,
    COMPLETE,
    CANCEL,
    ERROR,
    DELAY,
    PAUSE,
    FORECAST,
    INSPREQ,
    REJECT,
    EDIT,
    NA,
    TERMINATE,
    SETPLNDT,
    PREVENTEXE,
    ALLOWEXE,
    ILLOCK,
    ILUNLOCK,
    ACRFI,
    ACINSRV,
    ACREPREQ,
    ACQUAR,
    ACSCRAP,
    ACARCHIVE,
    ACINSPREQ,
    ACINREP,
    ACCONDEMN,
    IC,
    ICCR,
    CONORM,
    COAWR,
    COAOG,
    COINM,
    COOOS,
    COOPEN,
    UCCOMPLETE,
    UCERROR,
    URCOMPLETE,
    URERROR,
    URPEND,
    UCPEND,
    FGINST,
    FGRMVL,
    PEGEN,
    IPN,
    ISN,
    IMD,
    IMS,
    QCNEG,
    QCPOS,
    LXPEND,
    LXCANCEL,
    LXCMPLT,
    PROPEN,
    PRAVAIL,
    PRISSUED,
    PRPOREQ,
    PRONORDER,
    PRCANCEL,
    PRCOMPLETE,
    PRQUAR,
    PRINSPREQ,
    PRRESERVE,
    PRREMOTE,
    PRAASSIGNED,
    PRASTOLEN,
    PRAUNASSIGNED,
    POOPEN,
    POISSUED,
    PORECEIVED,
    POCLOSED,
    POCANCEL,
    POPARTIAL,
    POACKNOWLEDGED,
    BOCONVERTPO,
    EOCONVERTPO,
    POAUTH,
    ROCONVERTEO,
    BOCONVERTEO,
    POCONVERTEO,
    PIOPEN,
    PITOBEPAID,
    PICANCEL,
    PIPAID,
    TCOOUT,
    TCOIN,
    VNAPPROVED,
    VNWARNING,
    VNUNAPPRVD,
    BLACKOUT,
    RFQOPEN,
    RFQSENT,
    RFQCLOSED,
    RFQCANCEL,
    OCOWNERCHG,
    CAAUTHCHG,
    LDBUILD,
    LDACTV,
    LDOBSL,
    LDMOD,
    HRACTV,
    HRSPND,
    HRINVAL,
    HRUNSPND,
    CLOPEN,
    CLSUBMIT,
    CLCLOSE,
    CLCANCEL,
    UPDOPSRES,
};
Q_ENUM(EventStatusCD)

enum EventTypeCD {
    AC = 0,
    BLK,
    CA,
    CC,
    CF,
    CL,
    CO,
    DCC,
    EO,
    FG,
    FL,
    HR,
    IC,
    ICC,
    IL,
    IMD,
    IMS,
    IPN,
    ISN,
    IX,
    LD,
    LX,
    OC,
    PE,
    PI,
    PO,
    PR,
    PRA,
    QC,
    RFQ,
    TCO,
    TS,
    UC,
    UR,
    VN,
};
Q_ENUM(EventTypeCD)

enum FailDeferCD {
    CDL = 0,
    MEL_A,
    MEL_B,
    MEL_C,
    MEL_D,
    OTHER_180,
    OTHER_365,
};
Q_ENUM(FailDeferCD)

enum FailSevCD {
    AOG = 0,
    CDL,
    CDL_ND,
    MEL,
    MINOR,
    MINOR_ND,
    SRM,
    UNK,
};
Q_ENUM(FailSevCD)

enum FirstSchedFromCD {
    MANUFACTURE = 0,
    RECEIVE,
    EFFECTIVE,
    ONWING,
    ONPARENT,
    OFFWING,
    OFFPARENT,
};
Q_ENUM(FirstSchedFromCD)

enum FlightLegStatusCD {
    PLAN = 0,
    OUT,
    OFF,
    ON,
    IN,
    COMPLETE,
    DELAY,
    CANCEL,
    ERROR,
    EDIT,
    DIVERT,
    RETURN,
};
Q_ENUM(FlightLegStatusCD)

enum TradeTermsCD {
    EXW = 0,
    FCA,
    FAS,
    FOB,
    FOBLT,
    FOBUT,
    FOBS,
    FOBT,
    FOBST,
    CFR,
    CFRLT,
    CFRL,
    CFRET,
    CFREXH,
    CIF,
    CIFLT,
    CIFL,
    CIFUET,
    CIFESH,
    CPT,
    CIP,
    DAF,
    DES,
    DEQ,
    DDU,
    DDP,
};
Q_ENUM(TradeTermsCD)

enum HazmatDefCD {
    CLASS1 = 0,
    CLASS2,
    CLASS3,
    CLASS4,
    CLASS5,
    CLASS6,
    CLASS7,
    CLASS8,
    CLASS9,
};
Q_ENUM(HazmatDefCD)

enum InvClassCD {
    ACFT = 0,
    ASSY,
    BATCH,
    KIT,
    SER,
    SYS,
    TRK,
};
Q_ENUM(InvClassCD)

enum InvCondCD {
    ARCHIVE = 0,
    CONDEMN,
    INREP,
    INSPREQ,
    INSRV,
    QUAR,
    REPREQ,
    RFI,
    SCRAP,
};
Q_ENUM(InvCondCD)

enum LocTypeCD {
    AIRPORT = 0,
    ARCHIVE,
    BIN,
    BNCHSTK,
    CSGNPOOL,
    DOCK,
    HGR,
    INTRANS,
    LINE,
    OPS,
    OUTSRCE,
    PREDRAW,
    PREDRBIN,
    QUAR,
    RECEIVE,
    REPAIR,
    SCRAP,
    SHIPRCV,
    SHOP,
    SRVSTG,
    SRVSTORE,
    STORE,
    SYSTEM,
    TRACK,
    USSTG,
    USSTORE,
    VENDOR,
    AIRCRAFT,
    PRESERVE,
    RO,
    TEST,
    TOOL,
};
Q_ENUM(LocTypeCD)

enum LicenseStatusCD {
    ACTV = 0,
    BUILD,
    OBSOLETE,
};
Q_ENUM(LicenseStatusCD)

enum LabourRoleStatusCD {
    ACTV = 0,
    CANCEL,
    COMPLETE,
    PENDING,
};
Q_ENUM(LabourRoleStatusCD)

enum LabourRoleTypeCD {
    RII = 0,
    INSP,
    TECH,
};
Q_ENUM(LabourRoleTypeCD)

enum LabourStageCD {
    ACTV = 0,
    CANCEL,
    COMPLETE,
    INWORK,
};
Q_ENUM(LabourStageCD)

enum LogActionCD {
    PGADDPARTINCOMP = 0,
    PGADDTASKINCOMP,
    PGAPPR,
    PGASSN,
    PGEDIT,
    PGEDITPARTS,
    PGRMPARTINCOMP,
    PGRMTASKINCOMP,
    PGUNAPPR,
    PGUNASSN,
    INVCLASS,
    CSADDPOS,
    CSASSNPARM,
    CSPGCREATE,
    CSPGMOVE,
    CSCHGPARENT,
    CSCREATE,
    CSDELETE,
    CSEDIT,
    CSEDITPOS,
    CSRMVPOS,
    CSTRKTOSER,
    CSUNASSNPARM,
    MPLOCK,
    MPUNLOCK,
    OILSTATUS,
    PSAUP,
    PSAPPROVE,
    PSCREATE,
    PSEDIT,
    PSKITASSN,
    PSKITEDIT,
    PSKITUNASSN,
    PSMIGR,
    PSREJECT,
    PSTYPE,
    TDALLOWEXE,
    TDLOCK,
    TDPREVENTEXE,
    TDUNLOCK,
};
Q_ENUM(LogActionCD)

enum MaintPrgmStatusCD {
    ACTV = 0,
    BUILD,
    REVISION,
    SUPRSEDE,
};
Q_ENUM(MaintPrgmStatusCD)

enum MesurTypeCD {
    LENGTH = 0,
    MASS,
    AREA,
    VOLUME,
    VOLUME_FLUIDS,
    PRESSURE,
    TEMPERATURE,
    DENSITY,
    POWER,
    FREQUENCY,
    FORCE,
};
Q_ENUM(MesurTypeCD)

enum OwnerTypeCD {
    ORG = 0,
    VENDOR,
};
Q_ENUM(OwnerTypeCD)

enum OwnByCD {
    BORROW = 0,
    CSGNRCVD,
    CSGNRTRN,
    EXCHRCVD,
    EXCHRTRN,
    PURCHASE,
    LOCAL,
    OTHER,
};
Q_ENUM(OwnByCD)

enum PartProviderTypeCD {
    CUSTPAID = 0,
    CUSTPROV,
    MROPROV,
};
Q_ENUM(PartProviderTypeCD)

enum PartStatusCD {
    ACTV = 0,
    BUILD,
    OBSLT,
};
Q_ENUM(PartStatusCD)

enum PartTypeCD {
    ACFT = 0,
    ASSY,
    TRK,
    SER,
    BATCH,
    KIT,
};
Q_ENUM(PartTypeCD)

enum PartUseCD {
    AE = 0,
    TOOLS,
    CHEMIC,
    CONSUM,
    SHPCNT,
};
Q_ENUM(PartUseCD)

enum PoLineTypeCD {
    BORROW = 0,
    CONSIGN,
    CSGNXCHG,
    EXCHANGE,
    MISC,
    PURCHASE,
    REPAIR,
};
Q_ENUM(PoLineTypeCD)

enum PoTypeCD {
    BORROW = 0,
    CONSIGN,
    CSGNXCHG,
    EXCHANGE,
    PURCHASE,
    SERVICE,
    REPAIR,
};
Q_ENUM(PoTypeCD)

enum PriceTypeCD {
    CNFRMD = 0,
    QUOTE,
    WARRANTY,
};
Q_ENUM(PriceTypeCD)

enum ReceivePriorityCD {
    HI = 0,
    LOW,
};
Q_ENUM(ReceivePriorityCD)

enum ReceiveCondCD {
    NEW = 0,
    REP,
    UNK,
    INSP,
    MOD,
    OVHL,
    TEST,
};
Q_ENUM(ReceiveCondCD)

enum DocDispositionCD {
    READED = 0,
    NA,
    COMPLETE,
    NOACT,
    REQACT,
    OPEN,
    HOLD,
};
Q_ENUM(DocDispositionCD)

enum RemoveReasonCD {
    ACCESS = 0,
    IMSCHD,
    LOAN,
    MOD,
    ROB,
    STAGGER,
    TX_BNCH,
    TX_LIFE,
    TX_OVHL,
    XPOSED,
};
Q_ENUM(RemoveReasonCD)

enum ReqActionCD {
    INKIT = 0,
    NOREQ,
    REQ,
    ASREQ,
};
Q_ENUM(ReqActionCD)

enum ReqPriorityCD {
    AOG = 0,
    NORMAL,
    CRITICAL,
    DE_RATE,
    EXPEDITE,
};
Q_ENUM(ReqPriorityCD)

enum ReqTypeCD {
    ADHOC = 0,
    CSNSTOCK,
    STOCK,
    TASK,
};
Q_ENUM(ReqTypeCD)

enum ReschedFromCD {
    LASTDUE = 0,
    LASTEND,
    WPSTART,
    WPEND,
};
Q_ENUM(ReschedFromCD)

enum SchedPartStatusCD {
    ACTV = 0,
    CANCEL,
    COMPLETE,
};
Q_ENUM(SchedPartStatusCD)

enum SegmentStatusCD {
    CANCEL = 0,
    CMPLT,
    INTR,
    PEND,
    PLAN,
};
Q_ENUM(SegmentStatusCD)

enum ShipmentTypeCD {
    PURCHASE = 0,
    REPAIR,
    RTNVEN,
    RTNWAR,
    SENDREP,
    SENDXCHG,
    STKTRN,
};
Q_ENUM(ShipmentTypeCD)

enum StockLowActnCD {
    MANUAL = 0,
    POREQ,
    SHIPREQ,
};
Q_ENUM(StockLowActnCD)

enum TaskClassCD {
    REF = 0,
    AMP,
    DISCARD,
    MOD,
    OVHL,
    REPL,
    REQ,
    JIC,
    MPC,
    BLOCK,
    ADHOC,
    CORR,
    RO,
    CHECK,
};
Q_ENUM(TaskClassCD)

enum DocIssueByCD {
    MANUFACT = 0,
    OPER,
    REGBODY,
};
Q_ENUM(DocIssueByCD)

enum TaskDefStatusCD {
    ACTV = 0,
    BUILD,
    OBSOLETE,
    REVISION,
    SUPRSEDE,
};
Q_ENUM(TaskDefStatusCD)

enum TaskDepActionCD {
    COMPLETE = 0,
    CREATE,
    OPPRTNSTC,
    POSTCREATE,
};
Q_ENUM(TaskDepActionCD)

enum PaymentTermsCD {
    CON = 0,
    NET15,
    NET30,
    NET45,
    NET60,
    NET90,
    PLAN,
    PREPAID,
};
Q_ENUM(PaymentTermsCD)

enum ThresholdModeCD {
    ASSMLY = 0,
    FLEET,
};
Q_ENUM(ThresholdModeCD)

enum VendorTypeCD {
    BORROW = 0,
    POOL,
    PURCHASE,
    REPAIR,
    SERVICE,
};
Q_ENUM(VendorTypeCD)

enum VendorStatusCD {
    APPROVED = 0,
    UNAPPRVD,
    WARNING,
    EXPIRED,
};
Q_ENUM(VendorStatusCD)

enum WarrantyEvalStatusCD {
    CLAIM = 0,
    PENDING,
    REJECTED,
};
Q_ENUM(WarrantyEvalStatusCD)

enum WarrantyPriorityCD {
    HIGH = 0,
    LOW,
    MEDIUM,
};
Q_ENUM(WarrantyPriorityCD)

enum WarrantyStatusCD {
    ACTV = 0,
    BUILD,
    DEACTV,
};
Q_ENUM(WarrantyStatusCD)

enum WarrantySubtypeCD {
    AIRCRAFT = 0,
    ENGINE,
    APU,
    NONROUTINE,
    TRACKED,
    ROUTINE,
    SERIALIZED,
    BATCH,
};
Q_ENUM(WarrantySubtypeCD)

enum WarrantyTypeCD {
    ASSMLY = 0,
    COMPONENT,
    TASK,
};
Q_ENUM(WarrantyTypeCD)

enum WorkpackageTypeCD {
    SERVICE = 0,
    TURN,
    PREFLIGHT,
    AFTERFLIGHT,
    OVERHUAL,
    REPAIR,
    CHECK,
};
Q_ENUM(WorkpackageTypeCD)

enum XactionTypeCD {
    ADJPRICE = 0,
    ARCHIVE,
    CHGOWN,
    CLOSEPO,
    CRTINV,
    INSP,
    ISSUE,
    PAYINVC,
    QTYADJ,
    RTNVEN,
    SCRAP,
    TURNIN,
    UNARCH,
    UNDOINSP,
    UNDOISSUE,
};
Q_ENUM(XactionTypeCD)

enum XferTypeCD {
    ISSUE = 0,
    PUTAWAY,
    STKTRN,
    TURNIN,
};
Q_ENUM(XferTypeCD)
}

//Use QMetaEnum me = QMetaEnum::fromType<AM::xxx>()
//     me.keyToValue("PPP");
//to get enum value from String for Switch().
#endif // REFCODE_H
