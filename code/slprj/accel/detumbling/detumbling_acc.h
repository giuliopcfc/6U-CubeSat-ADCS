#ifndef RTW_HEADER_detumbling_acc_h_
#define RTW_HEADER_detumbling_acc_h_
#include <stddef.h>
#include <float.h>
#include <string.h>
#ifndef detumbling_acc_COMMON_INCLUDES_
#define detumbling_acc_COMMON_INCLUDES_
#include <stdlib.h>
#define S_FUNCTION_NAME simulink_only_sfcn 
#define S_FUNCTION_LEVEL 2
#define RTW_GENERATED_S_FUNCTION
#include "rtwtypes.h"
#include "simstruc.h"
#include "fixedpoint.h"
#endif
#include "detumbling_acc_types.h"
#include "multiword_types.h"
#include "mwmathutil.h"
#include "rt_defines.h"
#include "rt_nonfinite.h"
typedef struct { real_T B_15_0_0 ; real_T B_15_1_0 ; real_T B_15_2_0 ; real_T
B_15_4_0 [ 9 ] ; real_T B_15_7_0 [ 3 ] ; real_T B_15_8_0 [ 3 ] ; real_T
B_15_9_0 [ 3 ] ; real_T B_15_10_0 [ 3 ] ; real_T B_15_11_0 [ 3 ] ; real_T
B_15_12_0 [ 3 ] ; real_T B_15_13_0 [ 6 ] ; real_T B_15_14_0 ; real_T
B_15_17_0 [ 3 ] ; real_T B_15_26_0 ; real_T B_15_30_0 [ 3 ] ; real_T
B_15_31_0 [ 3 ] ; real_T B_15_41_0 [ 3 ] ; real_T B_15_42_0 [ 3 ] ; real_T
B_15_44_0 [ 3 ] ; real_T B_15_45_0 [ 3 ] ; real_T B_15_50_0 [ 3 ] ; real_T
B_15_0_0_m [ 3 ] ; real_T B_15_2_0_c ; real_T B_15_3_0 ; real_T B_15_4_0_k ;
real_T B_15_5_0 ; real_T B_15_6_0 ; real_T B_15_7_0_c [ 3 ] ; real_T
B_15_8_0_b ; real_T B_15_9_0_p [ 3 ] ; real_T B_15_11_0_c [ 9 ] ; real_T
B_15_12_0_f [ 3 ] ; real_T B_15_13_0_g ; real_T B_15_14_0_g ; real_T
B_15_15_0 [ 14 ] ; real_T B_15_16_0 [ 14 ] ; real_T B_15_17_0_m [ 42 ] ;
real_T B_15_18_0 [ 42 ] ; real_T B_15_19_0 [ 14 ] ; real_T B_15_20_0 [ 42 ] ;
real_T B_15_21_0 [ 42 ] ; real_T B_15_22_0 [ 14 ] ; real_T B_15_27_0 ; real_T
B_15_28_0 ; real_T B_15_29_0 ; real_T B_15_30_0_n ; real_T B_15_31_0_p ;
real_T B_15_34_0 [ 9 ] ; real_T B_15_36_0 [ 9 ] ; real_T B_15_37_0 ; real_T
B_15_38_0 ; real_T B_14_0_1 [ 6 ] ; real_T B_13_0_1 [ 3 ] ; real_T B_12_0_1 [
9 ] ; real_T B_11_0_1 [ 3 ] ; real_T B_11_0_2 [ 3 ] ; real_T B_11_0_3 [ 9 ] ;
real_T B_10_0_1 ; real_T B_9_0_1 [ 3 ] ; real_T B_8_0_1 [ 3 ] ; real_T
B_7_0_1 [ 3 ] ; real_T B_6_0_1 [ 3 ] ; real_T B_5_0_1 [ 3 ] ; real_T B_4_0_1
[ 3 ] ; real_T B_3_0_1 [ 9 ] ; real_T B_2_0_1 [ 9 ] ; real_T B_1_0_1 [ 3 ] ;
real_T B_1_0_2 ; real_T B_1_0_3 [ 3 ] ; real_T B_1_0_4 [ 3 ] ; real_T B_0_0_1
[ 3 ] ; real_T B_15_47_0 [ 3 ] ; boolean_T B_9_0_2 ; char_T pad_B_9_0_2 [ 7 ]
; } B_detumbling_T ; typedef struct { real_T NextOutput [ 3 ] ; real_T
NextOutput_o [ 3 ] ; real_T NextOutput_a [ 3 ] ; struct { real_T modelTStart
; } TransportDelay_RWORK ; struct { void * TUbufferPtrs [ 6 ] ; }
TransportDelay_PWORK ; void * IdealMC_PWORK ; void * MC_PWORK ; void *
ToWorkspace_PWORK ; void * ToWorkspace2_PWORK ; void * w_PWORK ; void *
D_PWORK ; void * MR_PWORK ; void * ToWorkspace_PWORK_f ; void * hR_PWORK ;
void * ToWorkspace_PWORK_c ; void * ToWorkspace_PWORK_b ; void *
GyroError_PWORK ; void * ToWorkspace_PWORK_m ; int32_T Observer_sysIdxToRun ;
int32_T MATLABFunction_sysIdxToRun ; int32_T MATLABFunction2_sysIdxToRun ;
int32_T MATLABFunction1_sysIdxToRun ; int32_T MATLABFunction_sysIdxToRun_j ;
int32_T SunPositionandEarthShadow_sysIdxToRun ; int32_T
MATLABFunction1_sysIdxToRun_p ; int32_T MATLABFunction_sysIdxToRun_j3 ;
int32_T GravityGradient_sysIdxToRun ; int32_T EarthsMagneticField_sysIdxToRun
; int32_T Drag_sysIdxToRun ; int32_T MATLABFunction1_sysIdxToRun_b ; int32_T
MATLABFunction_sysIdxToRun_d ; int32_T Control_sysIdxToRun ; int32_T
Actuators_sysIdxToRun ; uint32_T RandSeed [ 3 ] ; uint32_T RandSeed_d [ 3 ] ;
uint32_T RandSeed_i [ 3 ] ; struct { int_T Tail [ 3 ] ; int_T Head [ 3 ] ;
int_T Last [ 3 ] ; int_T CircularBufSize [ 3 ] ; int_T MaxNewBufSize ; }
TransportDelay_IWORK ; char_T pad_TransportDelay_IWORK [ 4 ] ; }
DW_detumbling_T ; typedef struct { real_T Integrator_CSTATE ; real_T
Integrator_CSTATE_d [ 9 ] ; real_T Integrator_CSTATE_l [ 6 ] ; real_T
Integrator_CSTATE_k ; real_T Integrator_CSTATE_g [ 3 ] ; real_T
Integrator_CSTATE_f [ 3 ] ; } X_detumbling_T ; typedef struct { real_T
Integrator_CSTATE ; real_T Integrator_CSTATE_d [ 9 ] ; real_T
Integrator_CSTATE_l [ 6 ] ; real_T Integrator_CSTATE_k ; real_T
Integrator_CSTATE_g [ 3 ] ; real_T Integrator_CSTATE_f [ 3 ] ; }
XDot_detumbling_T ; typedef struct { boolean_T Integrator_CSTATE ; boolean_T
Integrator_CSTATE_d [ 9 ] ; boolean_T Integrator_CSTATE_l [ 6 ] ; boolean_T
Integrator_CSTATE_k ; boolean_T Integrator_CSTATE_g [ 3 ] ; boolean_T
Integrator_CSTATE_f [ 3 ] ; } XDis_detumbling_T ; typedef struct { real_T
Integrator_CSTATE ; real_T Integrator_CSTATE_d [ 9 ] ; real_T
Integrator_CSTATE_l [ 6 ] ; real_T Integrator_CSTATE_k ; real_T
Integrator_CSTATE_g [ 3 ] ; real_T Integrator_CSTATE_f [ 3 ] ; }
CStateAbsTol_detumbling_T ; typedef struct { real_T Integrator_CSTATE ;
real_T Integrator_CSTATE_d [ 9 ] ; real_T Integrator_CSTATE_l [ 6 ] ; real_T
Integrator_CSTATE_k ; real_T Integrator_CSTATE_g [ 3 ] ; real_T
Integrator_CSTATE_f [ 3 ] ; } CXPtMin_detumbling_T ; typedef struct { real_T
Integrator_CSTATE ; real_T Integrator_CSTATE_d [ 9 ] ; real_T
Integrator_CSTATE_l [ 6 ] ; real_T Integrator_CSTATE_k ; real_T
Integrator_CSTATE_g [ 3 ] ; real_T Integrator_CSTATE_f [ 3 ] ; }
CXPtMax_detumbling_T ; struct P_detumbling_T_ { real_T P_0 ; real_T P_1 [ 9 ]
; real_T P_2 ; real_T P_3 [ 3 ] ; real_T P_4 [ 3 ] ; real_T P_5 [ 9 ] ;
real_T P_6 ; real_T P_7 [ 3 ] ; real_T P_8 [ 6 ] ; real_T P_9 ; real_T P_10 [
3 ] ; real_T P_11 ; real_T P_12 [ 3 ] ; real_T P_13 [ 3 ] ; real_T P_14 [ 3 ]
; real_T P_15 ; real_T P_16 [ 3 ] ; real_T P_17 [ 3 ] ; real_T P_18 [ 3 ] ;
real_T P_19 ; real_T P_20 ; real_T P_21 ; real_T P_22 ; real_T P_23 ; real_T
P_24 [ 3 ] ; real_T P_25 ; real_T P_26 [ 3 ] ; real_T P_27 [ 9 ] ; real_T
P_28 [ 3 ] ; real_T P_29 ; real_T P_30 ; real_T P_31 [ 14 ] ; real_T P_32 [
14 ] ; real_T P_33 [ 42 ] ; real_T P_34 [ 42 ] ; real_T P_35 [ 14 ] ; real_T
P_36 [ 42 ] ; real_T P_37 [ 42 ] ; real_T P_38 [ 14 ] ; real_T P_39 ; real_T
P_40 ; real_T P_41 ; real_T P_42 ; real_T P_43 ; real_T P_44 [ 9 ] ; real_T
P_45 [ 9 ] ; real_T P_46 ; real_T P_47 ; } ; extern P_detumbling_T
detumbling_rtDefaultP ;
#endif
