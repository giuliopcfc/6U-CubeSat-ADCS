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
typedef struct { real_T B_29_0_0 ; real_T B_29_1_0 ; real_T B_29_2_0 ; real_T
B_29_4_0 [ 9 ] ; real_T B_29_7_0 [ 3 ] ; real_T B_29_8_0 [ 3 ] ; real_T
B_29_10_0 [ 3 ] ; real_T B_29_11_0 [ 3 ] ; real_T B_29_12_0 [ 3 ] ; real_T
B_29_13_0 [ 3 ] ; real_T B_29_14_0 [ 3 ] ; real_T B_29_15_0 [ 3 ] ; real_T
B_29_17_0 [ 3 ] ; real_T B_29_18_0 [ 3 ] ; real_T B_29_19_0 [ 3 ] ; real_T
B_29_20_0 ; real_T B_29_31_0 ; real_T B_29_35_0 [ 3 ] ; real_T B_29_36_0 [ 3
] ; real_T B_29_38_0 [ 8 ] ; real_T B_29_39_0 [ 4 ] ; real_T B_29_40_0 [ 8 ]
; real_T B_29_41_0 [ 9 ] ; real_T B_29_44_0 [ 9 ] ; real_T B_29_48_0 ; real_T
B_29_50_0 [ 9 ] ; real_T B_29_54_0 ; real_T B_29_58_0 [ 3 ] ; real_T
B_29_59_0 [ 3 ] ; real_T B_29_75_0 [ 3 ] ; real_T B_29_0_0_m ; real_T
B_29_1_0_c [ 9 ] ; real_T B_29_2_0_k [ 9 ] ; real_T B_29_3_0 [ 3 ] ; real_T
B_29_4_0_c ; real_T B_29_5_0 ; real_T B_29_6_0 [ 14 ] ; real_T B_29_7_0_b [
14 ] ; real_T B_29_8_0_p [ 42 ] ; real_T B_29_9_0 [ 42 ] ; real_T B_29_10_0_c
[ 14 ] ; real_T B_29_11_0_f [ 42 ] ; real_T B_29_12_0_g [ 42 ] ; real_T
B_29_13_0_g [ 14 ] ; real_T B_29_18_0_m ; real_T B_29_19_0_n ; real_T
B_29_20_0_p ; real_T B_29_21_0 ; real_T B_29_22_0 ; real_T B_29_25_0 [ 9 ] ;
real_T B_29_26_0 ; real_T B_29_29_0 [ 3 ] ; real_T B_29_31_0_l ; real_T
B_29_32_0 ; real_T B_29_33_0 ; real_T B_29_34_0 ; real_T B_29_35_0_j ; real_T
B_29_36_0_d [ 3 ] ; real_T B_29_37_0 ; real_T B_29_38_0_g [ 3 ] ; real_T
B_29_40_0_l [ 9 ] ; real_T B_29_41_0_d [ 3 ] ; real_T B_29_42_0 ; real_T
B_29_43_0 ; real_T B_29_44_0_d [ 14 ] ; real_T B_29_45_0 [ 14 ] ; real_T
B_29_46_0 [ 42 ] ; real_T B_29_47_0 [ 42 ] ; real_T B_29_48_0_l [ 14 ] ;
real_T B_29_49_0 [ 42 ] ; real_T B_29_50_0_o [ 42 ] ; real_T B_29_51_0 [ 14 ]
; real_T B_29_56_0 ; real_T B_29_57_0 ; real_T B_29_58_0_b ; real_T
B_29_59_0_n ; real_T B_29_60_0 ; real_T B_29_63_0 [ 9 ] ; real_T B_29_65_0 [
9 ] ; real_T B_29_66_0 ; real_T B_28_0_1 [ 12 ] ; real_T B_28_0_2 [ 12 ] ;
real_T B_27_0_1 [ 3 ] ; real_T B_26_0_1 [ 9 ] ; real_T B_25_0_1 [ 3 ] ;
real_T B_25_0_2 [ 3 ] ; real_T B_25_0_3 [ 9 ] ; real_T B_24_0_1 ; real_T
B_23_0_1 [ 3 ] ; real_T B_22_0_1 [ 3 ] ; real_T B_21_0_1 [ 3 ] ; real_T
B_20_0_1 [ 3 ] ; real_T B_19_0_1 [ 3 ] ; real_T B_18_0_1 [ 3 ] ; real_T
B_17_0_1 [ 9 ] ; real_T B_16_0_1 [ 9 ] ; real_T B_15_0_1 [ 3 ] ; real_T
B_15_0_2 ; real_T B_15_0_3 [ 3 ] ; real_T B_15_0_4 [ 3 ] ; real_T B_14_0_1 [
3 ] ; real_T B_13_0_1 [ 9 ] ; real_T B_11_0_1 [ 3 ] ; real_T B_10_0_1 [ 9 ] ;
real_T B_7_0_1 [ 9 ] ; real_T B_6_0_1 [ 3 ] ; real_T B_6_0_2 [ 3 ] ; real_T
B_6_0_3 [ 9 ] ; real_T B_5_0_1 ; real_T B_4_0_1 [ 3 ] ; real_T B_3_0_1 [ 3 ]
; real_T B_2_0_1 [ 3 ] ; real_T B_1_0_1 [ 3 ] ; real_T B_0_0_1 [ 3 ] ; real_T
B_29_72_0 [ 3 ] ; boolean_T B_23_0_2 ; boolean_T B_12_0_1 ; boolean_T B_4_0_2
; char_T pad_B_4_0_2 [ 5 ] ; } B_detumbling_T ; typedef struct { real_T
NextOutput [ 3 ] ; real_T NextOutput_o [ 3 ] ; real_T NextOutput_f [ 8 ] ;
real_T NextOutput_m [ 4 ] ; real_T UniformRandomNumber_NextOutput [ 8 ] ;
real_T NextOutput_a [ 3 ] ; struct { real_T modelTStart ; }
TransportDelay_RWORK ; struct { void * TUbufferPtrs [ 6 ] ; }
TransportDelay_PWORK ; void * IdealMC_PWORK ; void * MC_PWORK ; void *
ToWorkspace_PWORK ; void * ToWorkspace2_PWORK ; void * w_PWORK ; void *
ToWorkspace_PWORK_b ; void * D_PWORK ; void * MR_PWORK ; void *
ToWorkspace_PWORK_f ; void * hR_PWORK ; void * ToWorkspace_PWORK_c ; void *
GyroError_PWORK ; void * ToWorkspace_PWORK_m ; int32_T
MATLABFunction_sysIdxToRun ; int32_T MATLABFunction_sysIdxToRun_g ; int32_T
MATLABFunction2_sysIdxToRun ; int32_T MATLABFunction1_sysIdxToRun ; int32_T
MATLABFunction_sysIdxToRun_j ; int32_T SunPositionandEarthShadow_sysIdxToRun
; int32_T MATLABFunction1_sysIdxToRun_p ; int32_T
MATLABFunction_sysIdxToRun_j3 ; int32_T GravityGradient_sysIdxToRun ; int32_T
EarthsMagneticField_sysIdxToRun ; int32_T Drag_sysIdxToRun ; int32_T
MATLABFunction1_sysIdxToRun_b ; int32_T MATLABFunction_sysIdxToRun_d ;
int32_T Control_sysIdxToRun ; int32_T Actuators_sysIdxToRun ; int32_T
WabhasProblem_sysIdxToRun ; int32_T SwitchToGyro_sysIdxToRun ; int32_T
Observer_sysIdxToRun ; int32_T IntegrateABN_sysIdxToRun ; int32_T
ABNfromWabhasproblem_sysIdxToRun ; int32_T ABNfromGyro_sysIdxToRun ; int32_T
MATLABFunction2_sysIdxToRun_a ; int32_T MATLABFunction1_sysIdxToRun_a ;
int32_T MATLABFunction_sysIdxToRun_h ; int32_T
SunPositionandEarthShadow_sysIdxToRun_e ; int32_T
MATLABFunction1_sysIdxToRun_m ; int32_T MATLABFunction_sysIdxToRun_p ;
int32_T GravityGradient_sysIdxToRun_b ; int32_T Drag_sysIdxToRun_l ; uint32_T
RandSeed [ 3 ] ; uint32_T RandSeed_d [ 3 ] ; uint32_T RandSeed_a [ 8 ] ;
uint32_T RandSeed_i [ 4 ] ; uint32_T RandSeed_h [ 8 ] ; uint32_T RandSeed_i5
[ 3 ] ; struct { int_T Tail [ 3 ] ; int_T Head [ 3 ] ; int_T Last [ 3 ] ;
int_T CircularBufSize [ 3 ] ; int_T MaxNewBufSize ; } TransportDelay_IWORK ;
int_T Integrator_IWORK ; int_T Integrator1_IWORK ; int8_T If_ActiveSubsystem
; int8_T ABNfromWabhasproblem_SubsysRanBC ; int8_T ABNfromGyro_SubsysRanBC ;
char_T pad_ABNfromGyro_SubsysRanBC [ 1 ] ; } DW_detumbling_T ; typedef struct
{ real_T Integrator_CSTATE ; real_T Integrator_CSTATE_d [ 9 ] ; real_T
Integrator_CSTATE_g [ 3 ] ; real_T Integrator_CSTATE_f [ 3 ] ; real_T
Integrator_CSTATE_l [ 3 ] ; real_T Integrator_CSTATE_k ; real_T
Integrator1_CSTATE [ 9 ] ; real_T Integrator_CSTATE_j ; } X_detumbling_T ;
typedef struct { real_T Integrator_CSTATE ; real_T Integrator_CSTATE_d [ 9 ]
; real_T Integrator_CSTATE_g [ 3 ] ; real_T Integrator_CSTATE_f [ 3 ] ;
real_T Integrator_CSTATE_l [ 3 ] ; real_T Integrator_CSTATE_k ; real_T
Integrator1_CSTATE [ 9 ] ; real_T Integrator_CSTATE_j ; } XDot_detumbling_T ;
typedef struct { boolean_T Integrator_CSTATE ; boolean_T Integrator_CSTATE_d
[ 9 ] ; boolean_T Integrator_CSTATE_g [ 3 ] ; boolean_T Integrator_CSTATE_f [
3 ] ; boolean_T Integrator_CSTATE_l [ 3 ] ; boolean_T Integrator_CSTATE_k ;
boolean_T Integrator1_CSTATE [ 9 ] ; boolean_T Integrator_CSTATE_j ; }
XDis_detumbling_T ; typedef struct { real_T Integrator_CSTATE ; real_T
Integrator_CSTATE_d [ 9 ] ; real_T Integrator_CSTATE_g [ 3 ] ; real_T
Integrator_CSTATE_f [ 3 ] ; real_T Integrator_CSTATE_l [ 3 ] ; real_T
Integrator_CSTATE_k ; real_T Integrator1_CSTATE [ 9 ] ; real_T
Integrator_CSTATE_j ; } CStateAbsTol_detumbling_T ; typedef struct { real_T
Integrator_CSTATE ; real_T Integrator_CSTATE_d [ 9 ] ; real_T
Integrator_CSTATE_g [ 3 ] ; real_T Integrator_CSTATE_f [ 3 ] ; real_T
Integrator_CSTATE_l [ 3 ] ; real_T Integrator_CSTATE_k ; real_T
Integrator1_CSTATE [ 9 ] ; real_T Integrator_CSTATE_j ; }
CXPtMin_detumbling_T ; typedef struct { real_T Integrator_CSTATE ; real_T
Integrator_CSTATE_d [ 9 ] ; real_T Integrator_CSTATE_g [ 3 ] ; real_T
Integrator_CSTATE_f [ 3 ] ; real_T Integrator_CSTATE_l [ 3 ] ; real_T
Integrator_CSTATE_k ; real_T Integrator1_CSTATE [ 9 ] ; real_T
Integrator_CSTATE_j ; } CXPtMax_detumbling_T ; typedef struct { ZCSigState
Integrator1_Reset_ZCE ; } PrevZCX_detumbling_T ; struct P_detumbling_T_ {
real_T P_0 ; real_T P_1 [ 9 ] ; real_T P_2 ; real_T P_3 [ 3 ] ; real_T P_4 [
3 ] ; real_T P_5 [ 9 ] ; real_T P_6 ; real_T P_7 [ 3 ] ; real_T P_8 [ 3 ] ;
real_T P_9 ; real_T P_10 [ 3 ] ; real_T P_11 [ 3 ] ; real_T P_12 [ 3 ] ;
real_T P_13 ; real_T P_14 ; real_T P_15 [ 8 ] ; real_T P_16 [ 8 ] ; real_T
P_17 ; real_T P_18 [ 4 ] ; real_T P_19 [ 4 ] ; real_T P_20 ; real_T P_21 ;
real_T P_22 [ 8 ] ; real_T P_23 ; real_T P_24 ; real_T P_25 [ 3 ] ; real_T
P_26 [ 3 ] ; real_T P_27 ; real_T P_28 [ 9 ] ; real_T P_29 [ 9 ] ; real_T
P_30 [ 3 ] ; real_T P_31 ; real_T P_32 ; real_T P_33 [ 14 ] ; real_T P_34 [
14 ] ; real_T P_35 [ 42 ] ; real_T P_36 [ 42 ] ; real_T P_37 [ 14 ] ; real_T
P_38 [ 42 ] ; real_T P_39 [ 42 ] ; real_T P_40 [ 14 ] ; real_T P_41 ; real_T
P_42 ; real_T P_43 ; real_T P_44 ; real_T P_45 ; real_T P_46 [ 9 ] ; real_T
P_47 ; real_T P_48 [ 3 ] ; real_T P_49 ; real_T P_50 ; real_T P_51 ; real_T
P_52 ; real_T P_53 ; real_T P_54 [ 3 ] ; real_T P_55 ; real_T P_56 [ 3 ] ;
real_T P_57 [ 9 ] ; real_T P_58 [ 3 ] ; real_T P_59 ; real_T P_60 ; real_T
P_61 [ 14 ] ; real_T P_62 [ 14 ] ; real_T P_63 [ 42 ] ; real_T P_64 [ 42 ] ;
real_T P_65 [ 14 ] ; real_T P_66 [ 42 ] ; real_T P_67 [ 42 ] ; real_T P_68 [
14 ] ; real_T P_69 ; real_T P_70 ; real_T P_71 ; real_T P_72 ; real_T P_73 ;
real_T P_74 [ 9 ] ; real_T P_75 [ 9 ] ; real_T P_76 ; } ; extern
P_detumbling_T detumbling_rtDefaultP ;
#endif
