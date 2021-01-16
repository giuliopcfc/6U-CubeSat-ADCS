#include <math.h>
#include "Copy_of_detumbling_acc.h"
#include "Copy_of_detumbling_acc_private.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include <stdio.h>
#include "slexec_vm_simstruct_bridge.h"
#include "slexec_vm_zc_functions.h"
#include "slexec_vm_lookup_functions.h"
#include "slsv_diagnostic_codegen_c_api.h"
#include "simtarget/slSimTgtMdlrefSfcnBridge.h"
#define CodeFormat S-Function
#define AccDefine1 Accelerator_S-Function
#include "simtarget/slAccSfcnBridge.h"
#ifndef __RTW_UTFREE__  
extern void * utMalloc ( size_t ) ; extern void utFree ( void * ) ;
#endif
boolean_T Copy_of_detumbling_acc_rt_TDelayUpdateTailOrGrowBuf ( int_T *
bufSzPtr , int_T * tailPtr , int_T * headPtr , int_T * lastPtr , real_T
tMinusDelay , real_T * * tBufPtr , real_T * * uBufPtr , real_T * * xBufPtr ,
boolean_T isfixedbuf , boolean_T istransportdelay , int_T * maxNewBufSzPtr )
{ int_T testIdx ; int_T tail = * tailPtr ; int_T bufSz = * bufSzPtr ; real_T
* tBuf = * tBufPtr ; real_T * xBuf = ( NULL ) ; int_T numBuffer = 2 ; if (
istransportdelay ) { numBuffer = 3 ; xBuf = * xBufPtr ; } testIdx = ( tail <
( bufSz - 1 ) ) ? ( tail + 1 ) : 0 ; if ( ( tMinusDelay <= tBuf [ testIdx ] )
&& ! isfixedbuf ) { int_T j ; real_T * tempT ; real_T * tempU ; real_T *
tempX = ( NULL ) ; real_T * uBuf = * uBufPtr ; int_T newBufSz = bufSz + 1024
; if ( newBufSz > * maxNewBufSzPtr ) { * maxNewBufSzPtr = newBufSz ; } tempU
= ( real_T * ) utMalloc ( numBuffer * newBufSz * sizeof ( real_T ) ) ; if (
tempU == ( NULL ) ) { return ( false ) ; } tempT = tempU + newBufSz ; if (
istransportdelay ) tempX = tempT + newBufSz ; for ( j = tail ; j < bufSz ; j
++ ) { tempT [ j - tail ] = tBuf [ j ] ; tempU [ j - tail ] = uBuf [ j ] ; if
( istransportdelay ) tempX [ j - tail ] = xBuf [ j ] ; } for ( j = 0 ; j <
tail ; j ++ ) { tempT [ j + bufSz - tail ] = tBuf [ j ] ; tempU [ j + bufSz -
tail ] = uBuf [ j ] ; if ( istransportdelay ) tempX [ j + bufSz - tail ] =
xBuf [ j ] ; } if ( * lastPtr > tail ) { * lastPtr -= tail ; } else { *
lastPtr += ( bufSz - tail ) ; } * tailPtr = 0 ; * headPtr = bufSz ; utFree (
uBuf ) ; * bufSzPtr = newBufSz ; * tBufPtr = tempT ; * uBufPtr = tempU ; if (
istransportdelay ) * xBufPtr = tempX ; } else { * tailPtr = testIdx ; }
return ( true ) ; } real_T Copy_of_detumbling_acc_rt_TDelayInterpolate (
real_T tMinusDelay , real_T tStart , real_T * tBuf , real_T * uBuf , int_T
bufSz , int_T * lastIdx , int_T oldestIdx , int_T newIdx , real_T initOutput
, boolean_T discrete , boolean_T minorStepAndTAtLastMajorOutput ) { int_T i ;
real_T yout , t1 , t2 , u1 , u2 ; if ( ( newIdx == 0 ) && ( oldestIdx == 0 )
&& ( tMinusDelay > tStart ) ) return initOutput ; if ( tMinusDelay <= tStart
) return initOutput ; if ( ( tMinusDelay <= tBuf [ oldestIdx ] ) ) { if (
discrete ) { return ( uBuf [ oldestIdx ] ) ; } else { int_T tempIdx =
oldestIdx + 1 ; if ( oldestIdx == bufSz - 1 ) tempIdx = 0 ; t1 = tBuf [
oldestIdx ] ; t2 = tBuf [ tempIdx ] ; u1 = uBuf [ oldestIdx ] ; u2 = uBuf [
tempIdx ] ; if ( t2 == t1 ) { if ( tMinusDelay >= t2 ) { yout = u2 ; } else {
yout = u1 ; } } else { real_T f1 = ( t2 - tMinusDelay ) / ( t2 - t1 ) ;
real_T f2 = 1.0 - f1 ; yout = f1 * u1 + f2 * u2 ; } return yout ; } } if (
minorStepAndTAtLastMajorOutput ) { if ( newIdx != 0 ) { if ( * lastIdx ==
newIdx ) { ( * lastIdx ) -- ; } newIdx -- ; } else { if ( * lastIdx == newIdx
) { * lastIdx = bufSz - 1 ; } newIdx = bufSz - 1 ; } } i = * lastIdx ; if (
tBuf [ i ] < tMinusDelay ) { while ( tBuf [ i ] < tMinusDelay ) { if ( i ==
newIdx ) break ; i = ( i < ( bufSz - 1 ) ) ? ( i + 1 ) : 0 ; } } else { while
( tBuf [ i ] >= tMinusDelay ) { i = ( i > 0 ) ? i - 1 : ( bufSz - 1 ) ; } i =
( i < ( bufSz - 1 ) ) ? ( i + 1 ) : 0 ; } * lastIdx = i ; if ( discrete ) {
double tempEps = ( DBL_EPSILON ) * 128.0 ; double localEps = tempEps *
muDoubleScalarAbs ( tBuf [ i ] ) ; if ( tempEps > localEps ) { localEps =
tempEps ; } localEps = localEps / 2.0 ; if ( tMinusDelay >= ( tBuf [ i ] -
localEps ) ) { yout = uBuf [ i ] ; } else { if ( i == 0 ) { yout = uBuf [
bufSz - 1 ] ; } else { yout = uBuf [ i - 1 ] ; } } } else { if ( i == 0 ) {
t1 = tBuf [ bufSz - 1 ] ; u1 = uBuf [ bufSz - 1 ] ; } else { t1 = tBuf [ i -
1 ] ; u1 = uBuf [ i - 1 ] ; } t2 = tBuf [ i ] ; u2 = uBuf [ i ] ; if ( t2 ==
t1 ) { if ( tMinusDelay >= t2 ) { yout = u2 ; } else { yout = u1 ; } } else {
real_T f1 = ( t2 - tMinusDelay ) / ( t2 - t1 ) ; real_T f2 = 1.0 - f1 ; yout
= f1 * u1 + f2 * u2 ; } } return ( yout ) ; } void rt_ssGetBlockPath (
SimStruct * S , int_T sysIdx , int_T blkIdx , char_T * * path ) {
_ssGetBlockPath ( S , sysIdx , blkIdx , path ) ; } void rt_ssSet_slErrMsg (
SimStruct * S , void * diag ) { if ( ! _ssIsErrorStatusAslErrMsg ( S ) ) {
_ssSet_slErrMsg ( S , diag ) ; } else { _ssDiscardDiagnostic ( S , diag ) ; }
} void rt_ssReportDiagnosticAsWarning ( SimStruct * S , void * diag ) {
_ssReportDiagnosticAsWarning ( S , diag ) ; } real_T
rt_urand_Upu32_Yd_f_pw_snf ( uint32_T * u ) { uint32_T hi ; uint32_T lo ; lo
= * u % 127773U * 16807U ; hi = * u / 127773U * 2836U ; if ( lo < hi ) { * u
= 2147483647U - ( hi - lo ) ; } else { * u = lo - hi ; } return ( real_T ) *
u * 4.6566128752457969E-10 ; } real_T rt_nrand_Upu32_Yd_f_pw_snf ( uint32_T *
u ) { real_T si ; real_T sr ; real_T y ; do { sr = 2.0 *
rt_urand_Upu32_Yd_f_pw_snf ( u ) - 1.0 ; si = 2.0 *
rt_urand_Upu32_Yd_f_pw_snf ( u ) - 1.0 ; si = sr * sr + si * si ; } while (
si > 1.0 ) ; y = muDoubleScalarSqrt ( - 2.0 * muDoubleScalarLog ( si ) / si )
* sr ; return y ; } static void mdlOutputs ( SimStruct * S , int_T tid ) {
B_Copy_of_detumbling_T * _rtB ; DW_Copy_of_detumbling_T * _rtDW ;
P_Copy_of_detumbling_T * _rtP ; X_Copy_of_detumbling_T * _rtX ; int32_T i ;
_rtDW = ( ( DW_Copy_of_detumbling_T * ) ssGetRootDWork ( S ) ) ; _rtX = ( (
X_Copy_of_detumbling_T * ) ssGetContStates ( S ) ) ; _rtP = ( (
P_Copy_of_detumbling_T * ) ssGetModelRtp ( S ) ) ; _rtB = ( (
B_Copy_of_detumbling_T * ) _ssGetModelBlockIO ( S ) ) ; _rtB -> B_15_0_0 =
ssGetT ( S ) ; _rtB -> B_15_1_0 = ssGetT ( S ) ; _rtB -> B_15_2_0 = _rtX ->
Integrator_CSTATE ; ssCallAccelRunBlock ( S , 11 , 0 , SS_CALL_MDL_OUTPUTS )
; memcpy ( & _rtB -> B_15_4_0 [ 0 ] , & _rtX -> Integrator_CSTATE_d [ 0 ] ,
9U * sizeof ( real_T ) ) ; ssCallAccelRunBlock ( S , 3 , 0 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 5 , 0 , SS_CALL_MDL_OUTPUTS
) ; i = ssIsSampleHit ( S , 2 , 0 ) ; if ( i != 0 ) { _rtB -> B_15_7_0 [ 0 ]
= _rtDW -> NextOutput [ 0 ] ; _rtB -> B_15_7_0 [ 1 ] = _rtDW -> NextOutput [
1 ] ; _rtB -> B_15_7_0 [ 2 ] = _rtDW -> NextOutput [ 2 ] ; } _rtB -> B_15_8_0
[ 0 ] = _rtB -> B_5_0_1 [ 0 ] + _rtB -> B_15_7_0 [ 0 ] ; _rtB -> B_15_8_0 [ 1
] = _rtB -> B_5_0_1 [ 1 ] + _rtB -> B_15_7_0 [ 1 ] ; _rtB -> B_15_8_0 [ 2 ] =
_rtB -> B_5_0_1 [ 2 ] + _rtB -> B_15_7_0 [ 2 ] ; i = ssIsSampleHit ( S , 2 ,
0 ) ; if ( i != 0 ) { _rtB -> B_15_9_0 [ 0 ] = _rtB -> B_15_8_0 [ 0 ] ; _rtB
-> B_15_9_0 [ 1 ] = _rtB -> B_15_8_0 [ 1 ] ; _rtB -> B_15_9_0 [ 2 ] = _rtB ->
B_15_8_0 [ 2 ] ; for ( i = 0 ; i < 3 ; i ++ ) { _rtB -> B_15_10_0 [ i ] = 0.0
; _rtB -> B_15_10_0 [ i ] += _rtP -> P_5 [ i ] * _rtB -> B_15_9_0 [ 0 ] ;
_rtB -> B_15_10_0 [ i ] += _rtP -> P_5 [ i + 3 ] * _rtB -> B_15_9_0 [ 1 ] ;
_rtB -> B_15_10_0 [ i ] += _rtP -> P_5 [ i + 6 ] * _rtB -> B_15_9_0 [ 2 ] ; }
} { real_T * * uBuffer = ( real_T * * ) & _rtDW -> TransportDelay_PWORK .
TUbufferPtrs [ 0 ] ; real_T * * tBuffer = ( real_T * * ) & _rtDW ->
TransportDelay_PWORK . TUbufferPtrs [ 3 ] ; real_T simTime = ssGetT ( S ) ;
real_T tMinusDelay ; { int_T i1 ; real_T * y0 = & _rtB -> B_15_11_0 [ 0 ] ;
const real_T * p_P_7 = _rtP -> P_7 ; int_T * iw_Tail = & _rtDW ->
TransportDelay_IWORK . Tail [ 0 ] ; int_T * iw_Head = & _rtDW ->
TransportDelay_IWORK . Head [ 0 ] ; int_T * iw_Last = & _rtDW ->
TransportDelay_IWORK . Last [ 0 ] ; int_T * iw_CircularBufSize = & _rtDW ->
TransportDelay_IWORK . CircularBufSize [ 0 ] ; for ( i1 = 0 ; i1 < 3 ; i1 ++
) { tMinusDelay = ( ( _rtP -> P_6 > 0.0 ) ? _rtP -> P_6 : 0.0 ) ; tMinusDelay
= simTime - tMinusDelay ; y0 [ i1 ] =
Copy_of_detumbling_acc_rt_TDelayInterpolate ( tMinusDelay , 0.0 , * tBuffer ,
* uBuffer , iw_CircularBufSize [ i1 ] , & iw_Last [ i1 ] , iw_Tail [ i1 ] ,
iw_Head [ i1 ] , p_P_7 [ i1 ] , 1 , ( boolean_T ) ( ssIsMinorTimeStep ( S )
&& ( ssGetTimeOfLastOutput ( S ) == ssGetT ( S ) ) ) ) ; tBuffer ++ ; uBuffer
++ ; } } } _rtB -> B_15_12_0 [ 0 ] = _rtB -> B_15_10_0 [ 0 ] - _rtB ->
B_15_11_0 [ 0 ] ; _rtB -> B_15_12_0 [ 1 ] = _rtB -> B_15_10_0 [ 1 ] - _rtB ->
B_15_11_0 [ 1 ] ; _rtB -> B_15_12_0 [ 2 ] = _rtB -> B_15_10_0 [ 2 ] - _rtB ->
B_15_11_0 [ 2 ] ; for ( i = 0 ; i < 6 ; i ++ ) { _rtB -> B_15_13_0 [ i ] =
_rtX -> Integrator_CSTATE_l [ i ] ; } _rtB -> B_15_14_0 = _rtX ->
Integrator_CSTATE_k ; ssCallAccelRunBlock ( S , 1 , 0 , SS_CALL_MDL_OUTPUTS )
; ssCallAccelRunBlock ( S , 15 , 16 , SS_CALL_MDL_OUTPUTS ) ; _rtB ->
B_15_17_0 [ 0 ] = _rtX -> Integrator_CSTATE_g [ 0 ] ; _rtB -> B_15_17_0 [ 1 ]
= _rtX -> Integrator_CSTATE_g [ 1 ] ; _rtB -> B_15_17_0 [ 2 ] = _rtX ->
Integrator_CSTATE_g [ 2 ] ; ssCallAccelRunBlock ( S , 0 , 0 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 15 , 19 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 15 , 20 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 15 , 21 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 15 , 22 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 12 , 0 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 6 , 0 , SS_CALL_MDL_OUTPUTS
) ; ssCallAccelRunBlock ( S , 8 , 0 , SS_CALL_MDL_OUTPUTS ) ; _rtB ->
B_15_26_0 = ssGetT ( S ) ; ssCallAccelRunBlock ( S , 9 , 0 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 7 , 0 , SS_CALL_MDL_OUTPUTS
) ; ssCallAccelRunBlock ( S , 4 , 0 , SS_CALL_MDL_OUTPUTS ) ; _rtB ->
B_15_30_0 [ 0 ] = ( ( _rtB -> B_6_0_1 [ 0 ] + _rtB -> B_8_0_1 [ 0 ] ) + _rtB
-> B_7_0_1 [ 0 ] ) + _rtB -> B_4_0_1 [ 0 ] ; _rtB -> B_15_31_0 [ 0 ] = _rtB
-> B_15_30_0 [ 0 ] + _rtB -> B_0_0_1 [ 0 ] ; _rtB -> B_15_30_0 [ 1 ] = ( (
_rtB -> B_6_0_1 [ 1 ] + _rtB -> B_8_0_1 [ 1 ] ) + _rtB -> B_7_0_1 [ 1 ] ) +
_rtB -> B_4_0_1 [ 1 ] ; _rtB -> B_15_31_0 [ 1 ] = _rtB -> B_15_30_0 [ 1 ] +
_rtB -> B_0_0_1 [ 1 ] ; _rtB -> B_15_30_0 [ 2 ] = ( ( _rtB -> B_6_0_1 [ 2 ] +
_rtB -> B_8_0_1 [ 2 ] ) + _rtB -> B_7_0_1 [ 2 ] ) + _rtB -> B_4_0_1 [ 2 ] ;
_rtB -> B_15_31_0 [ 2 ] = _rtB -> B_15_30_0 [ 2 ] + _rtB -> B_0_0_1 [ 2 ] ;
ssCallAccelRunBlock ( S , 15 , 32 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 15 , 33 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 15 , 34 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 15 , 35 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 2 , 0 , SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock
( S , 15 , 37 , SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 10 , 0 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 13 , 0 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 15 , 40 ,
SS_CALL_MDL_OUTPUTS ) ; i = ssIsSampleHit ( S , 1 , 0 ) ; if ( i != 0 ) {
_rtB -> B_15_41_0 [ 0 ] = _rtDW -> NextOutput_o [ 0 ] ; _rtB -> B_15_41_0 [ 1
] = _rtDW -> NextOutput_o [ 1 ] ; _rtB -> B_15_41_0 [ 2 ] = _rtDW ->
NextOutput_o [ 2 ] ; } _rtB -> B_15_42_0 [ 0 ] = _rtX -> Integrator_CSTATE_f
[ 0 ] ; _rtB -> B_15_44_0 [ 0 ] = ( _rtB -> B_15_41_0 [ 0 ] + _rtB ->
B_15_42_0 [ 0 ] ) + _rtB -> B_15_17_0 [ 0 ] ; _rtB -> B_15_42_0 [ 1 ] = _rtX
-> Integrator_CSTATE_f [ 1 ] ; _rtB -> B_15_44_0 [ 1 ] = ( _rtB -> B_15_41_0
[ 1 ] + _rtB -> B_15_42_0 [ 1 ] ) + _rtB -> B_15_17_0 [ 1 ] ; _rtB ->
B_15_42_0 [ 2 ] = _rtX -> Integrator_CSTATE_f [ 2 ] ; _rtB -> B_15_44_0 [ 2 ]
= ( _rtB -> B_15_41_0 [ 2 ] + _rtB -> B_15_42_0 [ 2 ] ) + _rtB -> B_15_17_0 [
2 ] ; i = ssIsSampleHit ( S , 1 , 0 ) ; if ( i != 0 ) { _rtB -> B_15_45_0 [ 0
] = _rtB -> B_15_44_0 [ 0 ] ; _rtB -> B_15_45_0 [ 1 ] = _rtB -> B_15_44_0 [ 1
] ; _rtB -> B_15_45_0 [ 2 ] = _rtB -> B_15_44_0 [ 2 ] ; } ssCallAccelRunBlock
( S , 14 , 0 , SS_CALL_MDL_OUTPUTS ) ; _rtB -> B_15_47_0 [ 0 ] = _rtB ->
B_15_17_0 [ 0 ] - _rtB -> B_15_45_0 [ 0 ] ; _rtB -> B_15_47_0 [ 1 ] = _rtB ->
B_15_17_0 [ 1 ] - _rtB -> B_15_45_0 [ 1 ] ; _rtB -> B_15_47_0 [ 2 ] = _rtB ->
B_15_17_0 [ 2 ] - _rtB -> B_15_45_0 [ 2 ] ; ssCallAccelRunBlock ( S , 15 , 48
, SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 15 , 49 ,
SS_CALL_MDL_OUTPUTS ) ; i = ssIsSampleHit ( S , 1 , 0 ) ; if ( i != 0 ) {
_rtB -> B_15_50_0 [ 0 ] = _rtDW -> NextOutput_a [ 0 ] ; _rtB -> B_15_50_0 [ 1
] = _rtDW -> NextOutput_a [ 1 ] ; _rtB -> B_15_50_0 [ 2 ] = _rtDW ->
NextOutput_a [ 2 ] ; } UNUSED_PARAMETER ( tid ) ; } static void
mdlOutputsTID3 ( SimStruct * S , int_T tid ) { B_Copy_of_detumbling_T * _rtB
; P_Copy_of_detumbling_T * _rtP ; _rtP = ( ( P_Copy_of_detumbling_T * )
ssGetModelRtp ( S ) ) ; _rtB = ( ( B_Copy_of_detumbling_T * )
_ssGetModelBlockIO ( S ) ) ; _rtB -> B_15_2_0_c = _rtP -> P_19 ; _rtB ->
B_15_3_0 = _rtP -> P_20 ; _rtB -> B_15_4_0_k = _rtP -> P_21 ; _rtB ->
B_15_5_0 = _rtP -> P_22 ; _rtB -> B_15_6_0 = _rtP -> P_23 ; _rtB ->
B_15_8_0_b = _rtP -> P_25 ; _rtB -> B_15_0_0_m [ 0 ] = _rtP -> P_18 [ 0 ] ;
_rtB -> B_15_7_0_c [ 0 ] = _rtP -> P_24 [ 0 ] ; _rtB -> B_15_9_0_p [ 0 ] =
_rtP -> P_26 [ 0 ] ; _rtB -> B_15_0_0_m [ 1 ] = _rtP -> P_18 [ 1 ] ; _rtB ->
B_15_7_0_c [ 1 ] = _rtP -> P_24 [ 1 ] ; _rtB -> B_15_9_0_p [ 1 ] = _rtP ->
P_26 [ 1 ] ; _rtB -> B_15_0_0_m [ 2 ] = _rtP -> P_18 [ 2 ] ; _rtB ->
B_15_7_0_c [ 2 ] = _rtP -> P_24 [ 2 ] ; _rtB -> B_15_9_0_p [ 2 ] = _rtP ->
P_26 [ 2 ] ; memcpy ( & _rtB -> B_15_11_0_c [ 0 ] , & _rtP -> P_27 [ 0 ] , 9U
* sizeof ( real_T ) ) ; _rtB -> B_15_12_0_f [ 0 ] = _rtP -> P_28 [ 0 ] ; _rtB
-> B_15_12_0_f [ 1 ] = _rtP -> P_28 [ 1 ] ; _rtB -> B_15_12_0_f [ 2 ] = _rtP
-> P_28 [ 2 ] ; _rtB -> B_15_13_0_g = _rtP -> P_29 ; _rtB -> B_15_14_0_g =
_rtP -> P_30 ; memcpy ( & _rtB -> B_15_15_0 [ 0 ] , & _rtP -> P_31 [ 0 ] ,
14U * sizeof ( real_T ) ) ; memcpy ( & _rtB -> B_15_16_0 [ 0 ] , & _rtP ->
P_32 [ 0 ] , 14U * sizeof ( real_T ) ) ; memcpy ( & _rtB -> B_15_17_0_m [ 0 ]
, & _rtP -> P_33 [ 0 ] , 42U * sizeof ( real_T ) ) ; memcpy ( & _rtB ->
B_15_18_0 [ 0 ] , & _rtP -> P_34 [ 0 ] , 42U * sizeof ( real_T ) ) ; memcpy (
& _rtB -> B_15_19_0 [ 0 ] , & _rtP -> P_35 [ 0 ] , 14U * sizeof ( real_T ) )
; memcpy ( & _rtB -> B_15_20_0 [ 0 ] , & _rtP -> P_36 [ 0 ] , 42U * sizeof (
real_T ) ) ; memcpy ( & _rtB -> B_15_21_0 [ 0 ] , & _rtP -> P_37 [ 0 ] , 42U
* sizeof ( real_T ) ) ; memcpy ( & _rtB -> B_15_22_0 [ 0 ] , & _rtP -> P_38 [
0 ] , 14U * sizeof ( real_T ) ) ; _rtB -> B_15_27_0 = _rtP -> P_39 ; _rtB ->
B_15_28_0 = _rtP -> P_40 ; _rtB -> B_15_29_0 = _rtP -> P_41 ; _rtB ->
B_15_30_0_n = _rtP -> P_42 ; _rtB -> B_15_31_0_p = _rtP -> P_43 ; memcpy ( &
_rtB -> B_15_34_0 [ 0 ] , & _rtP -> P_44 [ 0 ] , 9U * sizeof ( real_T ) ) ;
memcpy ( & _rtB -> B_15_36_0 [ 0 ] , & _rtP -> P_45 [ 0 ] , 9U * sizeof (
real_T ) ) ; _rtB -> B_15_37_0 = _rtP -> P_46 ; _rtB -> B_15_38_0 = _rtP ->
P_47 ; UNUSED_PARAMETER ( tid ) ; }
#define MDL_UPDATE
static void mdlUpdate ( SimStruct * S , int_T tid ) { B_Copy_of_detumbling_T
* _rtB ; DW_Copy_of_detumbling_T * _rtDW ; P_Copy_of_detumbling_T * _rtP ;
int32_T isHit ; _rtDW = ( ( DW_Copy_of_detumbling_T * ) ssGetRootDWork ( S )
) ; _rtP = ( ( P_Copy_of_detumbling_T * ) ssGetModelRtp ( S ) ) ; _rtB = ( (
B_Copy_of_detumbling_T * ) _ssGetModelBlockIO ( S ) ) ; isHit = ssIsSampleHit
( S , 2 , 0 ) ; if ( isHit != 0 ) { _rtDW -> NextOutput [ 0 ] =
rt_nrand_Upu32_Yd_f_pw_snf ( & _rtDW -> RandSeed [ 0 ] ) * _rtP -> P_3 [ 0 ]
+ _rtP -> P_2 ; _rtDW -> NextOutput [ 1 ] = rt_nrand_Upu32_Yd_f_pw_snf ( &
_rtDW -> RandSeed [ 1 ] ) * _rtP -> P_3 [ 1 ] + _rtP -> P_2 ; _rtDW ->
NextOutput [ 2 ] = rt_nrand_Upu32_Yd_f_pw_snf ( & _rtDW -> RandSeed [ 2 ] ) *
_rtP -> P_3 [ 2 ] + _rtP -> P_2 ; } { real_T * * uBuffer = ( real_T * * ) &
_rtDW -> TransportDelay_PWORK . TUbufferPtrs [ 0 ] ; real_T * * tBuffer = (
real_T * * ) & _rtDW -> TransportDelay_PWORK . TUbufferPtrs [ 3 ] ; real_T
simTime = ssGetT ( S ) ; _rtDW -> TransportDelay_IWORK . Head [ 0 ] = ( (
_rtDW -> TransportDelay_IWORK . Head [ 0 ] < ( _rtDW -> TransportDelay_IWORK
. CircularBufSize [ 0 ] - 1 ) ) ? ( _rtDW -> TransportDelay_IWORK . Head [ 0
] + 1 ) : 0 ) ; if ( _rtDW -> TransportDelay_IWORK . Head [ 0 ] == _rtDW ->
TransportDelay_IWORK . Tail [ 0 ] ) { if ( !
Copy_of_detumbling_acc_rt_TDelayUpdateTailOrGrowBuf ( & _rtDW ->
TransportDelay_IWORK . CircularBufSize [ 0 ] , & _rtDW ->
TransportDelay_IWORK . Tail [ 0 ] , & _rtDW -> TransportDelay_IWORK . Head [
0 ] , & _rtDW -> TransportDelay_IWORK . Last [ 0 ] , simTime - _rtP -> P_6 ,
tBuffer , uBuffer , ( NULL ) , ( boolean_T ) 0 , false , & _rtDW ->
TransportDelay_IWORK . MaxNewBufSize ) ) { ssSetErrorStatus ( S ,
"tdelay memory allocation error" ) ; return ; } } ( * tBuffer ++ ) [ _rtDW ->
TransportDelay_IWORK . Head [ 0 ] ] = simTime ; ( * uBuffer ++ ) [ _rtDW ->
TransportDelay_IWORK . Head [ 0 ] ] = _rtB -> B_15_10_0 [ 0 ] ; _rtDW ->
TransportDelay_IWORK . Head [ 1 ] = ( ( _rtDW -> TransportDelay_IWORK . Head
[ 1 ] < ( _rtDW -> TransportDelay_IWORK . CircularBufSize [ 1 ] - 1 ) ) ? (
_rtDW -> TransportDelay_IWORK . Head [ 1 ] + 1 ) : 0 ) ; if ( _rtDW ->
TransportDelay_IWORK . Head [ 1 ] == _rtDW -> TransportDelay_IWORK . Tail [ 1
] ) { if ( ! Copy_of_detumbling_acc_rt_TDelayUpdateTailOrGrowBuf ( & _rtDW ->
TransportDelay_IWORK . CircularBufSize [ 1 ] , & _rtDW ->
TransportDelay_IWORK . Tail [ 1 ] , & _rtDW -> TransportDelay_IWORK . Head [
1 ] , & _rtDW -> TransportDelay_IWORK . Last [ 1 ] , simTime - _rtP -> P_6 ,
tBuffer , uBuffer , ( NULL ) , ( boolean_T ) 0 , false , & _rtDW ->
TransportDelay_IWORK . MaxNewBufSize ) ) { ssSetErrorStatus ( S ,
"tdelay memory allocation error" ) ; return ; } } ( * tBuffer ++ ) [ _rtDW ->
TransportDelay_IWORK . Head [ 1 ] ] = simTime ; ( * uBuffer ++ ) [ _rtDW ->
TransportDelay_IWORK . Head [ 1 ] ] = _rtB -> B_15_10_0 [ 1 ] ; _rtDW ->
TransportDelay_IWORK . Head [ 2 ] = ( ( _rtDW -> TransportDelay_IWORK . Head
[ 2 ] < ( _rtDW -> TransportDelay_IWORK . CircularBufSize [ 2 ] - 1 ) ) ? (
_rtDW -> TransportDelay_IWORK . Head [ 2 ] + 1 ) : 0 ) ; if ( _rtDW ->
TransportDelay_IWORK . Head [ 2 ] == _rtDW -> TransportDelay_IWORK . Tail [ 2
] ) { if ( ! Copy_of_detumbling_acc_rt_TDelayUpdateTailOrGrowBuf ( & _rtDW ->
TransportDelay_IWORK . CircularBufSize [ 2 ] , & _rtDW ->
TransportDelay_IWORK . Tail [ 2 ] , & _rtDW -> TransportDelay_IWORK . Head [
2 ] , & _rtDW -> TransportDelay_IWORK . Last [ 2 ] , simTime - _rtP -> P_6 ,
tBuffer , uBuffer , ( NULL ) , ( boolean_T ) 0 , false , & _rtDW ->
TransportDelay_IWORK . MaxNewBufSize ) ) { ssSetErrorStatus ( S ,
"tdelay memory allocation error" ) ; return ; } } ( * tBuffer ) [ _rtDW ->
TransportDelay_IWORK . Head [ 2 ] ] = simTime ; ( * uBuffer ) [ _rtDW ->
TransportDelay_IWORK . Head [ 2 ] ] = _rtB -> B_15_10_0 [ 2 ] ; } isHit =
ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { _rtDW -> NextOutput_o [ 0 ]
= rt_nrand_Upu32_Yd_f_pw_snf ( & _rtDW -> RandSeed_d [ 0 ] ) * _rtP -> P_12 [
0 ] + _rtP -> P_11 ; _rtDW -> NextOutput_a [ 0 ] = rt_nrand_Upu32_Yd_f_pw_snf
( & _rtDW -> RandSeed_i [ 0 ] ) * _rtP -> P_16 [ 0 ] + _rtP -> P_15 ; _rtDW
-> NextOutput_o [ 1 ] = rt_nrand_Upu32_Yd_f_pw_snf ( & _rtDW -> RandSeed_d [
1 ] ) * _rtP -> P_12 [ 1 ] + _rtP -> P_11 ; _rtDW -> NextOutput_a [ 1 ] =
rt_nrand_Upu32_Yd_f_pw_snf ( & _rtDW -> RandSeed_i [ 1 ] ) * _rtP -> P_16 [ 1
] + _rtP -> P_15 ; _rtDW -> NextOutput_o [ 2 ] = rt_nrand_Upu32_Yd_f_pw_snf (
& _rtDW -> RandSeed_d [ 2 ] ) * _rtP -> P_12 [ 2 ] + _rtP -> P_11 ; _rtDW ->
NextOutput_a [ 2 ] = rt_nrand_Upu32_Yd_f_pw_snf ( & _rtDW -> RandSeed_i [ 2 ]
) * _rtP -> P_16 [ 2 ] + _rtP -> P_15 ; } UNUSED_PARAMETER ( tid ) ; }
#define MDL_UPDATE
static void mdlUpdateTID3 ( SimStruct * S , int_T tid ) { UNUSED_PARAMETER (
tid ) ; }
#define MDL_DERIVATIVES
static void mdlDerivatives ( SimStruct * S ) { B_Copy_of_detumbling_T * _rtB
; XDot_Copy_of_detumbling_T * _rtXdot ; int32_T i ; _rtXdot = ( (
XDot_Copy_of_detumbling_T * ) ssGetdX ( S ) ) ; _rtB = ( (
B_Copy_of_detumbling_T * ) _ssGetModelBlockIO ( S ) ) ; _rtXdot ->
Integrator_CSTATE = _rtB -> B_10_0_1 ; memcpy ( & _rtXdot ->
Integrator_CSTATE_d [ 0 ] , & _rtB -> B_2_0_1 [ 0 ] , 9U * sizeof ( real_T )
) ; for ( i = 0 ; i < 6 ; i ++ ) { _rtXdot -> Integrator_CSTATE_l [ i ] =
_rtB -> B_14_0_1 [ i ] ; } _rtXdot -> Integrator_CSTATE_k = _rtB -> B_1_0_2 ;
_rtXdot -> Integrator_CSTATE_g [ 0 ] = _rtB -> B_13_0_1 [ 0 ] ; _rtXdot ->
Integrator_CSTATE_f [ 0 ] = _rtB -> B_15_50_0 [ 0 ] ; _rtXdot ->
Integrator_CSTATE_g [ 1 ] = _rtB -> B_13_0_1 [ 1 ] ; _rtXdot ->
Integrator_CSTATE_f [ 1 ] = _rtB -> B_15_50_0 [ 1 ] ; _rtXdot ->
Integrator_CSTATE_g [ 2 ] = _rtB -> B_13_0_1 [ 2 ] ; _rtXdot ->
Integrator_CSTATE_f [ 2 ] = _rtB -> B_15_50_0 [ 2 ] ; } static void
mdlInitializeSizes ( SimStruct * S ) { ssSetChecksumVal ( S , 0 , 3061770534U
) ; ssSetChecksumVal ( S , 1 , 3656410586U ) ; ssSetChecksumVal ( S , 2 ,
630449480U ) ; ssSetChecksumVal ( S , 3 , 1134252862U ) ; { mxArray *
slVerStructMat = NULL ; mxArray * slStrMat = mxCreateString ( "simulink" ) ;
char slVerChar [ 10 ] ; int status = mexCallMATLAB ( 1 , & slVerStructMat , 1
, & slStrMat , "ver" ) ; if ( status == 0 ) { mxArray * slVerMat = mxGetField
( slVerStructMat , 0 , "Version" ) ; if ( slVerMat == NULL ) { status = 1 ; }
else { status = mxGetString ( slVerMat , slVerChar , 10 ) ; } }
mxDestroyArray ( slStrMat ) ; mxDestroyArray ( slVerStructMat ) ; if ( (
status == 1 ) || ( strcmp ( slVerChar , "10.2" ) != 0 ) ) { return ; } }
ssSetOptions ( S , SS_OPTION_EXCEPTION_FREE_CODE ) ; if ( ssGetSizeofDWork (
S ) != sizeof ( DW_Copy_of_detumbling_T ) ) { ssSetErrorStatus ( S ,
"Unexpected error: Internal DWork sizes do "
"not match for accelerator mex file." ) ; } if ( ssGetSizeofGlobalBlockIO ( S
) != sizeof ( B_Copy_of_detumbling_T ) ) { ssSetErrorStatus ( S ,
"Unexpected error: Internal BlockIO sizes do "
"not match for accelerator mex file." ) ; } { int ssSizeofParams ;
ssGetSizeofParams ( S , & ssSizeofParams ) ; if ( ssSizeofParams != sizeof (
P_Copy_of_detumbling_T ) ) { static char msg [ 256 ] ; sprintf ( msg ,
"Unexpected error: Internal Parameters sizes do "
"not match for accelerator mex file." ) ; } } _ssSetModelRtp ( S , ( real_T *
) & Copy_of_detumbling_rtDefaultP ) ; rt_InitInfAndNaN ( sizeof ( real_T ) )
; } static void mdlInitializeSampleTimes ( SimStruct * S ) { { SimStruct *
childS ; SysOutputFcn * callSysFcns ; childS = ssGetSFunction ( S , 0 ) ;
callSysFcns = ssGetCallSystemOutputFcnList ( childS ) ; callSysFcns [ 3 + 0 ]
= ( SysOutputFcn ) ( NULL ) ; childS = ssGetSFunction ( S , 1 ) ; callSysFcns
= ssGetCallSystemOutputFcnList ( childS ) ; callSysFcns [ 3 + 0 ] = (
SysOutputFcn ) ( NULL ) ; childS = ssGetSFunction ( S , 2 ) ; callSysFcns =
ssGetCallSystemOutputFcnList ( childS ) ; callSysFcns [ 3 + 0 ] = (
SysOutputFcn ) ( NULL ) ; childS = ssGetSFunction ( S , 3 ) ; callSysFcns =
ssGetCallSystemOutputFcnList ( childS ) ; callSysFcns [ 3 + 0 ] = (
SysOutputFcn ) ( NULL ) ; childS = ssGetSFunction ( S , 4 ) ; callSysFcns =
ssGetCallSystemOutputFcnList ( childS ) ; callSysFcns [ 3 + 0 ] = (
SysOutputFcn ) ( NULL ) ; childS = ssGetSFunction ( S , 5 ) ; callSysFcns =
ssGetCallSystemOutputFcnList ( childS ) ; callSysFcns [ 3 + 0 ] = (
SysOutputFcn ) ( NULL ) ; childS = ssGetSFunction ( S , 6 ) ; callSysFcns =
ssGetCallSystemOutputFcnList ( childS ) ; callSysFcns [ 3 + 0 ] = (
SysOutputFcn ) ( NULL ) ; childS = ssGetSFunction ( S , 7 ) ; callSysFcns =
ssGetCallSystemOutputFcnList ( childS ) ; callSysFcns [ 3 + 0 ] = (
SysOutputFcn ) ( NULL ) ; childS = ssGetSFunction ( S , 8 ) ; callSysFcns =
ssGetCallSystemOutputFcnList ( childS ) ; callSysFcns [ 3 + 0 ] = (
SysOutputFcn ) ( NULL ) ; childS = ssGetSFunction ( S , 9 ) ; callSysFcns =
ssGetCallSystemOutputFcnList ( childS ) ; callSysFcns [ 3 + 0 ] = (
SysOutputFcn ) ( NULL ) ; childS = ssGetSFunction ( S , 10 ) ; callSysFcns =
ssGetCallSystemOutputFcnList ( childS ) ; callSysFcns [ 3 + 0 ] = (
SysOutputFcn ) ( NULL ) ; childS = ssGetSFunction ( S , 11 ) ; callSysFcns =
ssGetCallSystemOutputFcnList ( childS ) ; callSysFcns [ 3 + 0 ] = (
SysOutputFcn ) ( NULL ) ; childS = ssGetSFunction ( S , 12 ) ; callSysFcns =
ssGetCallSystemOutputFcnList ( childS ) ; callSysFcns [ 3 + 0 ] = (
SysOutputFcn ) ( NULL ) ; childS = ssGetSFunction ( S , 13 ) ; callSysFcns =
ssGetCallSystemOutputFcnList ( childS ) ; callSysFcns [ 3 + 0 ] = (
SysOutputFcn ) ( NULL ) ; childS = ssGetSFunction ( S , 14 ) ; callSysFcns =
ssGetCallSystemOutputFcnList ( childS ) ; callSysFcns [ 3 + 0 ] = (
SysOutputFcn ) ( NULL ) ; } slAccRegPrmChangeFcn ( S , mdlOutputsTID3 ) ; }
static void mdlTerminate ( SimStruct * S ) { }
#include "simulink.c"
