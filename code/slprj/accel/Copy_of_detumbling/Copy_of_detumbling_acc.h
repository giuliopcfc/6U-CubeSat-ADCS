#ifndef RTW_HEADER_Copy_of_detumbling_acc_h_
#define RTW_HEADER_Copy_of_detumbling_acc_h_
#include <stddef.h>
#include <float.h>
#include <string.h>
#ifndef Copy_of_detumbling_acc_COMMON_INCLUDES_
#define Copy_of_detumbling_acc_COMMON_INCLUDES_
#include <stdlib.h>
#define S_FUNCTION_NAME simulink_only_sfcn 
#define S_FUNCTION_LEVEL 2
#define RTW_GENERATED_S_FUNCTION
#include "rtwtypes.h"
#include "simstruc.h"
#include "fixedpoint.h"
#endif
#include "Copy_of_detumbling_acc_types.h"
#include "multiword_types.h"
#include "mwmathutil.h"
#include "rt_defines.h"
#include "rt_nonfinite.h"
typedef struct { real_T B_15_0_0 ; real_T B_15_1_0 ; real_T B_15_2_0 ; real_T
B_15_4_0 [ 9 ] ; real_T B_15_7_0 [ 3 ] ; real_T B_15_8_0 [ 3 ] ; real_T
B_15_9_0 [ 3 ] ; real_T B_15_10_0 ; real_T B_15_23_0 ; real_T B_15_26_0 [ 3 ]
; real_T B_15_27_0 [ 3 ] ; real_T B_15_0_0_m [ 3 ] ; real_T B_15_2_0_c ;
real_T B_15_3_0 ; real_T B_15_4_0_k ; real_T B_15_5_0 ; real_T B_15_6_0 ;
real_T B_15_7_0_c [ 3 ] ; real_T B_15_8_0_b ; real_T B_15_9_0_p [ 3 ] ;
real_T B_15_11_0 [ 9 ] ; real_T B_15_12_0 [ 3 ] ; real_T B_15_13_0 [ 14 ] ;
real_T B_15_14_0 [ 14 ] ; real_T B_15_15_0 [ 42 ] ; real_T B_15_16_0 [ 42 ] ;
real_T B_15_17_0 [ 14 ] ; real_T B_15_21_0 ; real_T B_15_22_0 ; real_T
B_15_23_0_c ; real_T B_15_24_0 ; real_T B_15_25_0 ; real_T B_15_28_0 [ 9 ] ;
real_T B_13_0_1 [ 3 ] ; real_T B_12_0_1 [ 3 ] ; real_T B_11_0_1 [ 9 ] ;
real_T B_10_0_1 [ 3 ] ; real_T B_10_0_2 [ 3 ] ; real_T B_10_0_3 [ 9 ] ;
real_T B_9_0_1 ; real_T B_8_0_1 [ 3 ] ; real_T B_7_0_1 [ 3 ] ; real_T B_6_0_1
[ 3 ] ; real_T B_5_0_1 [ 3 ] ; real_T B_4_0_1 [ 3 ] ; real_T B_4_0_2 [ 3 ] ;
real_T B_3_0_1 [ 9 ] ; real_T B_2_0_1 [ 9 ] ; real_T B_1_0_1 [ 3 ] ; real_T
B_1_0_2 ; real_T B_1_0_3 [ 3 ] ; real_T B_1_0_4 [ 3 ] ; real_T B_0_0_1 [ 3 ]
; boolean_T B_14_0_1 ; char_T pad_B_14_0_1 [ 7 ] ; } B_Copy_of_detumbling_T ;
typedef struct { struct { real_T modelTStart ; } TransportDelay_RWORK ;
struct { void * TUbufferPtrs [ 6 ] ; } TransportDelay_PWORK ; void *
IdealMC_PWORK ; void * MC_PWORK ; void * ToWorkspace_PWORK ; void *
ToWorkspace2_PWORK ; void * w_PWORK ; void * D_PWORK ; void * M_PWORK ; void
* ToWorkspace_PWORK_f ; void * hR_PWORK ; void * ToWorkspace_PWORK_c ;
int32_T MATLABFunction_sysIdxToRun ; int32_T MATLABFunction_sysIdxToRun_g ;
int32_T MATLABFunction3_sysIdxToRun ; int32_T MATLABFunction2_sysIdxToRun ;
int32_T MATLABFunction1_sysIdxToRun ; int32_T MATLABFunction_sysIdxToRun_j ;
int32_T SunPosition_sysIdxToRun ; int32_T MATLABFunction1_sysIdxToRun_p ;
int32_T MATLABFunction_sysIdxToRun_d ; int32_T GravityGradient_sysIdxToRun ;
int32_T EarthsMagneticField_sysIdxToRun ; int32_T
MATLABFunction1_sysIdxToRun_b ; int32_T MATLABFunction_sysIdxToRun_dt ;
int32_T Control_sysIdxToRun ; int32_T Actuators_sysIdxToRun ; struct { int_T
Tail [ 3 ] ; int_T Head [ 3 ] ; int_T Last [ 3 ] ; int_T CircularBufSize [ 3
] ; int_T MaxNewBufSize ; } TransportDelay_IWORK ; } DW_Copy_of_detumbling_T
; typedef struct { real_T Integrator_CSTATE ; real_T Integrator_CSTATE_d [ 9
] ; real_T Integrator_CSTATE_g [ 3 ] ; real_T Integrator_CSTATE_k ; }
X_Copy_of_detumbling_T ; typedef struct { real_T Integrator_CSTATE ; real_T
Integrator_CSTATE_d [ 9 ] ; real_T Integrator_CSTATE_g [ 3 ] ; real_T
Integrator_CSTATE_k ; } XDot_Copy_of_detumbling_T ; typedef struct {
boolean_T Integrator_CSTATE ; boolean_T Integrator_CSTATE_d [ 9 ] ; boolean_T
Integrator_CSTATE_g [ 3 ] ; boolean_T Integrator_CSTATE_k ; }
XDis_Copy_of_detumbling_T ; typedef struct { real_T Integrator_CSTATE ;
real_T Integrator_CSTATE_d [ 9 ] ; real_T Integrator_CSTATE_g [ 3 ] ; real_T
Integrator_CSTATE_k ; } CStateAbsTol_Copy_of_detumbling_T ; typedef struct {
real_T Integrator_CSTATE ; real_T Integrator_CSTATE_d [ 9 ] ; real_T
Integrator_CSTATE_g [ 3 ] ; real_T Integrator_CSTATE_k ; }
CXPtMin_Copy_of_detumbling_T ; typedef struct { real_T Integrator_CSTATE ;
real_T Integrator_CSTATE_d [ 9 ] ; real_T Integrator_CSTATE_g [ 3 ] ; real_T
Integrator_CSTATE_k ; } CXPtMax_Copy_of_detumbling_T ; struct
P_Copy_of_detumbling_T_ { real_T P_0 ; real_T P_1 [ 9 ] ; real_T P_2 ; real_T
P_3 [ 3 ] ; real_T P_4 [ 3 ] ; real_T P_5 ; real_T P_6 [ 3 ] ; real_T P_7 ;
real_T P_8 ; real_T P_9 ; real_T P_10 ; real_T P_11 ; real_T P_12 [ 3 ] ;
real_T P_13 ; real_T P_14 [ 3 ] ; real_T P_15 [ 9 ] ; real_T P_16 [ 3 ] ;
real_T P_17 [ 14 ] ; real_T P_18 [ 14 ] ; real_T P_19 [ 42 ] ; real_T P_20 [
42 ] ; real_T P_21 [ 14 ] ; real_T P_22 ; real_T P_23 ; real_T P_24 ; real_T
P_25 ; real_T P_26 ; real_T P_27 [ 9 ] ; } ; extern P_Copy_of_detumbling_T
Copy_of_detumbling_rtDefaultP ;
#endif
