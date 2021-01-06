#ifndef RTW_HEADER_detumbling_h_
#define RTW_HEADER_detumbling_h_
#include <stddef.h>
#include <float.h>
#include <string.h>
#include "rtw_modelmap.h"
#ifndef detumbling_COMMON_INCLUDES_
#define detumbling_COMMON_INCLUDES_
#include <stdlib.h>
#include "rtwtypes.h"
#include "sigstream_rtw.h"
#include "simtarget/slSimTgtSigstreamRTW.h"
#include "simtarget/slSimTgtSlioCoreRTW.h"
#include "simtarget/slSimTgtSlioClientsRTW.h"
#include "simtarget/slSimTgtSlioSdiRTW.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "raccel.h"
#include "slsv_diagnostic_codegen_c_api.h"
#include "rt_logging.h"
#include "dt_info.h"
#include "ext_work.h"
#endif
#include "detumbling_types.h"
#include "multiword_types.h"
#include "mwmathutil.h"
#include "rt_defines.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"
#define MODEL_NAME detumbling
#define NSAMPLE_TIMES (5) 
#define NINPUTS (0)       
#define NOUTPUTS (0)     
#define NBLOCKIO (32) 
#define NUM_ZC_EVENTS (1) 
#ifndef NCSTATES
#define NCSTATES (20)   
#elif NCSTATES != 20
#error Invalid specification of NCSTATES defined in compiler command
#endif
#ifndef rtmGetDataMapInfo
#define rtmGetDataMapInfo(rtm) (*rt_dataMapInfoPtr)
#endif
#ifndef rtmSetDataMapInfo
#define rtmSetDataMapInfo(rtm, val) (rt_dataMapInfoPtr = &val)
#endif
#ifndef IN_RACCEL_MAIN
#endif
typedef struct { real_T ela1rhmmmi ; real_T jbo3v4ajb3 [ 9 ] ; real_T
ahdpwrjj5d [ 3 ] ; real_T bqon2dgr5d [ 3 ] ; real_T nrhgec3vav [ 3 ] ; real_T
fh0tz1ct3t [ 3 ] ; real_T c1dnkkzf2p [ 3 ] ; real_T l1nazchf2g ; real_T
kl0s5rlxlx [ 3 ] ; real_T dlgknc2iej [ 3 ] ; real_T d0bsyboket [ 3 ] ; real_T
lkneu0sjol [ 3 ] ; real_T gcsyrgudhi [ 3 ] ; real_T pkc5yfmw2v [ 3 ] ; real_T
h2dle1tjk3 ; real_T cw2k3svoeb [ 3 ] ; real_T ey2mmw0csp [ 3 ] ; real_T
jd4glhy2th [ 3 ] ; real_T bgsqzfr5vf [ 3 ] ; real_T ptpgqwsog2 [ 3 ] ; real_T
cncjtrvy1r ; real_T pxjxltf32i [ 3 ] ; real_T bx5l1cxe42 [ 3 ] ; real_T
fiyrbaaxb5 [ 3 ] ; real_T farw3endkt [ 3 ] ; real_T gnn2xcjhaq ; real_T
p13uq5o22a [ 9 ] ; real_T e1l1mwc2wk [ 9 ] ; real_T e4c42ch1lv ; real_T
nvcvw4zh5h [ 3 ] ; real_T pldpuimngh [ 3 ] ; boolean_T b13up4rwa2 ; } B ;
typedef struct { real_T a5tv4scxvv [ 3 ] ; real_T donz0qvylr [ 3 ] ; real_T
mdfoxg3mo4 [ 3 ] ; struct { real_T modelTStart ; } eqrezujrj5 ; struct { void
* TUbufferPtrs [ 6 ] ; } ja1mjqygva ; struct { void * LoggedData ; }
gt4jdlhghh ; struct { void * LoggedData ; } azun1jdpk2 ; struct { void *
LoggedData ; } isg0e1befe ; struct { void * LoggedData ; } fwhm2dya5u ;
struct { void * LoggedData ; } j04ekmbaka ; uint32_T p3k2zi5joj [ 3 ] ;
uint32_T apy12dao0a [ 3 ] ; uint32_T lfp1taz3l3 [ 3 ] ; struct { int_T Tail [
3 ] ; int_T Head [ 3 ] ; int_T Last [ 3 ] ; int_T CircularBufSize [ 3 ] ;
int_T MaxNewBufSize ; } hxmmr0vle1 ; int_T m3xid4gzul ; boolean_T klnbyfrse2
; boolean_T bhvnvcv2we ; } DW ; typedef struct { real_T mdmb5a1yml ; real_T
l3lup5gvqh [ 9 ] ; real_T k5ybcxiwei [ 3 ] ; real_T cmqklstge4 [ 3 ] ; real_T
kn4trkmxb3 [ 3 ] ; real_T kumxbfxbuz ; } X ; typedef struct { real_T
mdmb5a1yml ; real_T l3lup5gvqh [ 9 ] ; real_T k5ybcxiwei [ 3 ] ; real_T
cmqklstge4 [ 3 ] ; real_T kn4trkmxb3 [ 3 ] ; real_T kumxbfxbuz ; } XDot ;
typedef struct { boolean_T mdmb5a1yml ; boolean_T l3lup5gvqh [ 9 ] ;
boolean_T k5ybcxiwei [ 3 ] ; boolean_T cmqklstge4 [ 3 ] ; boolean_T
kn4trkmxb3 [ 3 ] ; boolean_T kumxbfxbuz ; } XDis ; typedef struct { real_T
mdmb5a1yml ; real_T l3lup5gvqh [ 9 ] ; real_T k5ybcxiwei [ 3 ] ; real_T
cmqklstge4 [ 3 ] ; real_T kn4trkmxb3 [ 3 ] ; real_T kumxbfxbuz ; }
CStateAbsTol ; typedef struct { real_T mdmb5a1yml ; real_T l3lup5gvqh [ 9 ] ;
real_T k5ybcxiwei [ 3 ] ; real_T cmqklstge4 [ 3 ] ; real_T kn4trkmxb3 [ 3 ] ;
real_T kumxbfxbuz ; } CXPtMin ; typedef struct { real_T mdmb5a1yml ; real_T
l3lup5gvqh [ 9 ] ; real_T k5ybcxiwei [ 3 ] ; real_T cmqklstge4 [ 3 ] ; real_T
kn4trkmxb3 [ 3 ] ; real_T kumxbfxbuz ; } CXPtMax ; typedef struct { real_T
eke5pk2rn0 ; real_T gz0w1vkufw ; real_T pfbcqp3wuq ; } ZCV ; typedef struct {
ZCSigState gqlxm0wffx ; } PrevZCX ; typedef struct { rtwCAPI_ModelMappingInfo
mmi ; } DataMapInfo ; struct P_ { real_T Integrator_IC ; real_T
Integrator_IC_ifj3pkofzc [ 9 ] ; real_T RandomNumber1_Mean ; real_T
RandomNumber1_StdDev [ 3 ] ; real_T RandomNumber1_Seed [ 3 ] ; real_T
TransportDelay_Delay ; real_T TransportDelay_InitOutput [ 3 ] ; real_T
Integrator_IC_c5e44kpjcd [ 3 ] ; real_T RandomNumber_Mean ; real_T
RandomNumber_StdDev [ 3 ] ; real_T RandomNumber_Seed [ 3 ] ; real_T
Integrator_IC_juij5hh4y1 [ 3 ] ; real_T Integrator_IC_lc2l1uvn30 ; real_T
RandomNumber1_Mean_pp0amcle2e ; real_T RandomNumber1_StdDev_cudqkp3bpx [ 3 ]
; real_T RandomNumber1_Seed_gnd4ve32hq [ 3 ] ; real_T Constant9_Value [ 3 ] ;
real_T Constant_Value ; real_T Constant1_Value ; real_T Constant2_Value ;
real_T Constant3_Value ; real_T Constant4_Value ; real_T Constant5_Value [ 3
] ; real_T Constant6_Value ; real_T Constant7_Value ; real_T
Constant_Value_nedwe54uwp [ 9 ] ; real_T Constant1_Value_iuwa1a4rwo [ 3 ] ;
real_T Constant2_Value_p0tf13dhms [ 14 ] ; real_T Constant3_Value_mitst2s14q
[ 14 ] ; real_T Constant4_Value_hr4vhts24r [ 42 ] ; real_T
Constant5_Value_oj3yslavn5 [ 42 ] ; real_T Constant6_Value_bsw1z5ftyf [ 14 ]
; real_T Constant_Value_kb0zyegq3x ; real_T Constant1_Value_lapgl51prt ;
real_T Constant2_Value_pn5msfmygz ; real_T Constant3_Value_lnlpkng3dr ;
real_T Constant4_Value_plq0xk0dqt ; real_T Constant_Value_noh4pr4dj2 [ 9 ] ;
real_T Constant_Value_jedkd3oz4q ; real_T Constant_Value_m3i1kxbif4 [ 9 ] ;
real_T Constant1_Value_cw3pti1zff ; real_T Constant2_Value_jgk4nzciuj ; } ;
extern const char * RT_MEMORY_ALLOCATION_ERROR ; extern B rtB ; extern X rtX
; extern DW rtDW ; extern PrevZCX rtPrevZCX ; extern P rtP ; extern const
rtwCAPI_ModelMappingStaticInfo * detumbling_GetCAPIStaticMap ( void ) ;
extern SimStruct * const rtS ; extern const int_T gblNumToFiles ; extern
const int_T gblNumFrFiles ; extern const int_T gblNumFrWksBlocks ; extern
rtInportTUtable * gblInportTUtables ; extern const char * gblInportFileName ;
extern const int_T gblNumRootInportBlks ; extern const int_T
gblNumModelInputs ; extern const int_T gblInportDataTypeIdx [ ] ; extern
const int_T gblInportDims [ ] ; extern const int_T gblInportComplex [ ] ;
extern const int_T gblInportInterpoFlag [ ] ; extern const int_T
gblInportContinuous [ ] ; extern const int_T gblParameterTuningTid ; extern
DataMapInfo * rt_dataMapInfoPtr ; extern rtwCAPI_ModelMappingInfo *
rt_modelMapInfoPtr ; void MdlOutputs ( int_T tid ) ; void
MdlOutputsParameterSampleTime ( int_T tid ) ; void MdlUpdate ( int_T tid ) ;
void MdlTerminate ( void ) ; void MdlInitializeSizes ( void ) ; void
MdlInitializeSampleTimes ( void ) ; SimStruct * raccel_register_model (
ssExecutionInfo * executionInfo ) ;
#endif
