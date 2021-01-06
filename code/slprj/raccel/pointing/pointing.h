#ifndef RTW_HEADER_pointing_h_
#define RTW_HEADER_pointing_h_
#include <stddef.h>
#include <string.h>
#include "rtw_modelmap.h"
#ifndef pointing_COMMON_INCLUDES_
#define pointing_COMMON_INCLUDES_
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
#include "pointing_types.h"
#include "multiword_types.h"
#include "rtGetNaN.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"
#include "rt_defines.h"
#include "rtGetInf.h"
#define MODEL_NAME pointing
#define NSAMPLE_TIMES (3) 
#define NINPUTS (0)       
#define NOUTPUTS (0)     
#define NBLOCKIO (47) 
#define NUM_ZC_EVENTS (1) 
#ifndef NCSTATES
#define NCSTATES (30)   
#elif NCSTATES != 30
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
typedef struct { real_T fyfzf3djiy [ 3 ] ; } pp3ucak1we ; typedef struct {
real_T ekyf2ft5xv [ 3 ] ; } ol1ikflgm2 ; typedef struct { real_T gmfjxhcwab ;
} ep05ktrzpt ; typedef struct { real_T a4etz1spm4 [ 3 ] ; real_T edrpaasu4j [
3 ] ; real_T nmcsp5dcxo [ 9 ] ; } ew4humqmjw ; typedef struct { real_T
fws4iwogpu [ 9 ] ; } htahsp0knc ; typedef struct { real_T g540wbqcci [ 3 ] ;
} dwh41ujqlf ; typedef struct { real_T haaoe3krmo [ 9 ] ; real_T izl1q5sazi ;
real_T p51cv010io [ 3 ] ; real_T jpaphc4vt2 [ 3 ] ; real_T nxkkb43lmg [ 3 ] ;
real_T kj0hrlovtd [ 3 ] ; real_T jnakfltztn [ 3 ] ; real_T ehirxkx1np [ 3 ] ;
real_T k0b2i5iiue [ 9 ] ; real_T fonazkfutz [ 9 ] ; real_T n4mzmf5vo5 ;
real_T d4wo1qk3qg [ 3 ] ; real_T n4ileghqyp ; real_T p0sytp1tyb [ 3 ] ;
real_T dam0bfwzoj [ 3 ] ; real_T mk02jshpdk [ 3 ] ; real_T apuiamofe1 [ 3 ] ;
real_T lo3kkfxdkz [ 3 ] ; real_T hla54xlqcw [ 3 ] ; real_T dk2a4uugl1 [ 3 ] ;
real_T ex4pku1fge [ 3 ] ; real_T jx5wap4com [ 3 ] ; real_T ap5nsqw1en [ 3 ] ;
real_T fd3qlfq0pf [ 9 ] ; real_T mymck1p5dr [ 9 ] ; real_T gkxr4i513p ;
real_T d155gslfmi [ 9 ] ; real_T kokf4n2mhf [ 3 ] ; real_T gdcysdgjg5 [ 9 ] ;
real_T hpj2uj2i4a [ 3 ] ; boolean_T mkszl352m3 ; dwh41ujqlf eje25gfouo ;
htahsp0knc nzapizli54 ; ew4humqmjw hid2a3ighm ; ep05ktrzpt cz1perd2ej ;
ol1ikflgm2 arbgebpnzf ; pp3ucak1we mssjub5nr2 ; dwh41ujqlf gwhniowyem ;
htahsp0knc lb5tuw34lz ; ew4humqmjw ituo30pkvd ; ep05ktrzpt imixbcpj4x ;
ol1ikflgm2 eagdjb5elr ; pp3ucak1we lqknz2kefj ; } B ; typedef struct { real_T
n1mf5f1loj [ 3 ] ; real_T j4zaai5afv [ 8 ] ; real_T ofluvtqt5p [ 4 ] ; real_T
o221ifynn5 [ 8 ] ; real_T kqelrtffwz [ 3 ] ; real_T gubqowflu1 [ 3 ] ; struct
{ void * LoggedData ; } npodssysd1 ; struct { void * LoggedData ; }
lmb5hcu4yy ; struct { void * LoggedData ; } b2ohgjv3mg ; struct { void *
LoggedData ; } f5asnft4wp ; struct { void * LoggedData ; } emrji4re2y ;
uint32_T ewjz1wr2fe [ 3 ] ; uint32_T bnvhkeklee [ 8 ] ; uint32_T k10aogs3q2 [
4 ] ; uint32_T c5xg33ddc3 [ 8 ] ; uint32_T j05iyjbst5 [ 3 ] ; uint32_T
mgrhzfgfnu [ 3 ] ; int_T h5pffuqljc ; int_T mstj5paygm ; int8_T e4nx2k2d02 ;
int8_T mgkojscrve ; int8_T bt5mj1ckkg ; } DW ; typedef struct { real_T
ouapiys3qq [ 9 ] ; real_T kjairk4b1p ; real_T lutbl3ejqb [ 3 ] ; real_T
ht1cmxxnsq [ 3 ] ; real_T fnoi12dssm [ 9 ] ; real_T mnzw0suzs2 ; real_T
bqjsimdqqc ; real_T jc4nrgnm2y [ 3 ] ; } X ; typedef struct { real_T
ouapiys3qq [ 9 ] ; real_T kjairk4b1p ; real_T lutbl3ejqb [ 3 ] ; real_T
ht1cmxxnsq [ 3 ] ; real_T fnoi12dssm [ 9 ] ; real_T mnzw0suzs2 ; real_T
bqjsimdqqc ; real_T jc4nrgnm2y [ 3 ] ; } XDot ; typedef struct { boolean_T
ouapiys3qq [ 9 ] ; boolean_T kjairk4b1p ; boolean_T lutbl3ejqb [ 3 ] ;
boolean_T ht1cmxxnsq [ 3 ] ; boolean_T fnoi12dssm [ 9 ] ; boolean_T
mnzw0suzs2 ; boolean_T bqjsimdqqc ; boolean_T jc4nrgnm2y [ 3 ] ; } XDis ;
typedef struct { real_T ouapiys3qq [ 9 ] ; real_T kjairk4b1p ; real_T
lutbl3ejqb [ 3 ] ; real_T ht1cmxxnsq [ 3 ] ; real_T fnoi12dssm [ 9 ] ; real_T
mnzw0suzs2 ; real_T bqjsimdqqc ; real_T jc4nrgnm2y [ 3 ] ; } CStateAbsTol ;
typedef struct { real_T ouapiys3qq [ 9 ] ; real_T kjairk4b1p ; real_T
lutbl3ejqb [ 3 ] ; real_T ht1cmxxnsq [ 3 ] ; real_T fnoi12dssm [ 9 ] ; real_T
mnzw0suzs2 ; real_T bqjsimdqqc ; real_T jc4nrgnm2y [ 3 ] ; } CXPtMin ;
typedef struct { real_T ouapiys3qq [ 9 ] ; real_T kjairk4b1p ; real_T
lutbl3ejqb [ 3 ] ; real_T ht1cmxxnsq [ 3 ] ; real_T fnoi12dssm [ 9 ] ; real_T
mnzw0suzs2 ; real_T bqjsimdqqc ; real_T jc4nrgnm2y [ 3 ] ; } CXPtMax ;
typedef struct { ZCSigState dwuwbqsvq3 ; } PrevZCX ; typedef struct {
rtwCAPI_ModelMappingInfo mmi ; } DataMapInfo ; struct P_ {
struct_qSJ0rbcLQyL9m8alQXvOk data ; real_T RandomNumber1_Mean ; real_T
RandomNumber1_StdDev [ 3 ] ; real_T RandomNumber1_Seed [ 3 ] ; real_T
RandomNumber_Mean ; real_T RandomNumber_StdDev [ 8 ] ; real_T
RandomNumber_Seed [ 8 ] ; real_T RandomNumber1_Mean_bjj4nzkohe ; real_T
RandomNumber1_StdDev_pxu4l4yv2r [ 4 ] ; real_T RandomNumber1_Seed_cspndgusfq
[ 4 ] ; real_T UniformRandomNumber_Minimum ; real_T
UniformRandomNumber_Maximum ; real_T UniformRandomNumber_Seed [ 8 ] ; real_T
RandomNumber_Mean_jleeh3nxmy ; real_T RandomNumber_StdDev_fffkyslftj [ 3 ] ;
real_T RandomNumber_Seed_g3q3oeokt3 [ 3 ] ; real_T
RandomNumber1_Mean_dlj5kv1b54 ; real_T RandomNumber1_StdDev_lesrfxv0lg [ 3 ]
; real_T RandomNumber1_Seed_ow4kdudteh [ 3 ] ; } ; extern const char *
RT_MEMORY_ALLOCATION_ERROR ; extern B rtB ; extern X rtX ; extern DW rtDW ;
extern PrevZCX rtPrevZCX ; extern P rtP ; extern const
rtwCAPI_ModelMappingStaticInfo * pointing_GetCAPIStaticMap ( void ) ; extern
SimStruct * const rtS ; extern const int_T gblNumToFiles ; extern const int_T
gblNumFrFiles ; extern const int_T gblNumFrWksBlocks ; extern rtInportTUtable
* gblInportTUtables ; extern const char * gblInportFileName ; extern const
int_T gblNumRootInportBlks ; extern const int_T gblNumModelInputs ; extern
const int_T gblInportDataTypeIdx [ ] ; extern const int_T gblInportDims [ ] ;
extern const int_T gblInportComplex [ ] ; extern const int_T
gblInportInterpoFlag [ ] ; extern const int_T gblInportContinuous [ ] ;
extern const int_T gblParameterTuningTid ; extern DataMapInfo *
rt_dataMapInfoPtr ; extern rtwCAPI_ModelMappingInfo * rt_modelMapInfoPtr ;
void MdlOutputs ( int_T tid ) ; void MdlOutputsParameterSampleTime ( int_T
tid ) ; void MdlUpdate ( int_T tid ) ; void MdlTerminate ( void ) ; void
MdlInitializeSizes ( void ) ; void MdlInitializeSampleTimes ( void ) ;
SimStruct * raccel_register_model ( ssExecutionInfo * executionInfo ) ;
#endif
