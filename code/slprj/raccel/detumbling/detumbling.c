#include "rt_logging_mmi.h"
#include "detumbling_capi.h"
#include <math.h>
#include "detumbling.h"
#include "detumbling_private.h"
#include "detumbling_dt.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "slsa_sim_engine.h"
extern void * CreateDiagnosticAsVoidPtr_wrapper ( const char * id , int nargs
, ... ) ; RTWExtModeInfo * gblRTWExtModeInfo = NULL ; void
raccelForceExtModeShutdown ( boolean_T extModeStartPktReceived ) { if ( !
extModeStartPktReceived ) { boolean_T stopRequested = false ;
rtExtModeWaitForStartPkt ( gblRTWExtModeInfo , 4 , & stopRequested ) ; }
rtExtModeShutdown ( 4 ) ; }
#include "slsv_diagnostic_codegen_c_api.h"
const int_T gblNumToFiles = 0 ; const int_T gblNumFrFiles = 0 ; const int_T
gblNumFrWksBlocks = 0 ;
#ifdef RSIM_WITH_SOLVER_MULTITASKING
boolean_T gbl_raccel_isMultitasking = 1 ;
#else
boolean_T gbl_raccel_isMultitasking = 0 ;
#endif
boolean_T gbl_raccel_tid01eq = 0 ; int_T gbl_raccel_NumST = 5 ; const char_T
* gbl_raccel_Version = "10.2 (R2020b) 29-Jul-2020" ; void
raccel_setup_MMIStateLog ( SimStruct * S ) {
#ifdef UseMMIDataLogging
rt_FillStateSigInfoFromMMI ( ssGetRTWLogInfo ( S ) , & ssGetErrorStatus ( S )
) ;
#else
UNUSED_PARAMETER ( S ) ;
#endif
} static DataMapInfo rt_dataMapInfo ; DataMapInfo * rt_dataMapInfoPtr = &
rt_dataMapInfo ; rtwCAPI_ModelMappingInfo * rt_modelMapInfoPtr = & (
rt_dataMapInfo . mmi ) ; const int_T gblNumRootInportBlks = 0 ; const int_T
gblNumModelInputs = 0 ; extern const char * gblInportFileName ; extern
rtInportTUtable * gblInportTUtables ; const int_T gblInportDataTypeIdx [ ] =
{ - 1 } ; const int_T gblInportDims [ ] = { - 1 } ; const int_T
gblInportComplex [ ] = { - 1 } ; const int_T gblInportInterpoFlag [ ] = { - 1
} ; const int_T gblInportContinuous [ ] = { - 1 } ; int_T enableFcnCallFlag [
] = { 1 , 1 , 1 , 1 , 1 } ; const char * raccelLoadInputsAndAperiodicHitTimes
( SimStruct * S , const char * inportFileName , int * matFileFormat ) {
return rt_RAccelReadInportsMatFile ( S , inportFileName , matFileFormat ) ; }
B rtB ; X rtX ; DW rtDW ; PrevZCX rtPrevZCX ; static SimStruct model_S ;
SimStruct * const rtS = & model_S ; static real_T klnbmqkqbd ( const real_T x
[ 3 ] ) ; static void hyrpevmtnt ( const real_T A [ 9 ] , const real_T B_p [
3 ] , real_T Y [ 3 ] ) ;
#ifndef __RTW_UTFREE__  
extern void * utMalloc ( size_t ) ;
#endif
void * rt_TDelayCreateBuf ( int_T numBuffer , int_T bufSz , int_T elemSz ) {
return ( ( void * ) utMalloc ( numBuffer * bufSz * elemSz ) ) ; }
#ifndef __RTW_UTFREE__  
extern void * utMalloc ( size_t ) ; extern void utFree ( void * ) ;
#endif
boolean_T rt_TDelayUpdateTailOrGrowBuf ( int_T * bufSzPtr , int_T * tailPtr ,
int_T * headPtr , int_T * lastPtr , real_T tMinusDelay , real_T * * tBufPtr ,
real_T * * uBufPtr , real_T * * xBufPtr , boolean_T isfixedbuf , boolean_T
istransportdelay , int_T * maxNewBufSzPtr ) { int_T testIdx ; int_T tail = *
tailPtr ; int_T bufSz = * bufSzPtr ; real_T * tBuf = * tBufPtr ; real_T *
xBuf = ( NULL ) ; int_T numBuffer = 2 ; if ( istransportdelay ) { numBuffer =
3 ; xBuf = * xBufPtr ; } testIdx = ( tail < ( bufSz - 1 ) ) ? ( tail + 1 ) :
0 ; if ( ( tMinusDelay <= tBuf [ testIdx ] ) && ! isfixedbuf ) { int_T j ;
real_T * tempT ; real_T * tempU ; real_T * tempX = ( NULL ) ; real_T * uBuf =
* uBufPtr ; int_T newBufSz = bufSz + 1024 ; if ( newBufSz > * maxNewBufSzPtr
) { * maxNewBufSzPtr = newBufSz ; } tempU = ( real_T * ) utMalloc ( numBuffer
* newBufSz * sizeof ( real_T ) ) ; if ( tempU == ( NULL ) ) { return ( false
) ; } tempT = tempU + newBufSz ; if ( istransportdelay ) tempX = tempT +
newBufSz ; for ( j = tail ; j < bufSz ; j ++ ) { tempT [ j - tail ] = tBuf [
j ] ; tempU [ j - tail ] = uBuf [ j ] ; if ( istransportdelay ) tempX [ j -
tail ] = xBuf [ j ] ; } for ( j = 0 ; j < tail ; j ++ ) { tempT [ j + bufSz -
tail ] = tBuf [ j ] ; tempU [ j + bufSz - tail ] = uBuf [ j ] ; if (
istransportdelay ) tempX [ j + bufSz - tail ] = xBuf [ j ] ; } if ( * lastPtr
> tail ) { * lastPtr -= tail ; } else { * lastPtr += ( bufSz - tail ) ; } *
tailPtr = 0 ; * headPtr = bufSz ; utFree ( uBuf ) ; * bufSzPtr = newBufSz ; *
tBufPtr = tempT ; * uBufPtr = tempU ; if ( istransportdelay ) * xBufPtr =
tempX ; } else { * tailPtr = testIdx ; } return ( true ) ; } real_T
rt_TDelayInterpolate ( real_T tMinusDelay , real_T tStart , real_T * tBuf ,
real_T * uBuf , int_T bufSz , int_T * lastIdx , int_T oldestIdx , int_T
newIdx , real_T initOutput , boolean_T discrete , boolean_T
minorStepAndTAtLastMajorOutput ) { int_T i ; real_T yout , t1 , t2 , u1 , u2
; if ( ( newIdx == 0 ) && ( oldestIdx == 0 ) && ( tMinusDelay > tStart ) )
return initOutput ; if ( tMinusDelay <= tStart ) return initOutput ; if ( (
tMinusDelay <= tBuf [ oldestIdx ] ) ) { if ( discrete ) { return ( uBuf [
oldestIdx ] ) ; } else { int_T tempIdx = oldestIdx + 1 ; if ( oldestIdx ==
bufSz - 1 ) tempIdx = 0 ; t1 = tBuf [ oldestIdx ] ; t2 = tBuf [ tempIdx ] ;
u1 = uBuf [ oldestIdx ] ; u2 = uBuf [ tempIdx ] ; if ( t2 == t1 ) { if (
tMinusDelay >= t2 ) { yout = u2 ; } else { yout = u1 ; } } else { real_T f1 =
( t2 - tMinusDelay ) / ( t2 - t1 ) ; real_T f2 = 1.0 - f1 ; yout = f1 * u1 +
f2 * u2 ; } return yout ; } } if ( minorStepAndTAtLastMajorOutput ) { if (
newIdx != 0 ) { if ( * lastIdx == newIdx ) { ( * lastIdx ) -- ; } newIdx -- ;
} else { if ( * lastIdx == newIdx ) { * lastIdx = bufSz - 1 ; } newIdx =
bufSz - 1 ; } } i = * lastIdx ; if ( tBuf [ i ] < tMinusDelay ) { while (
tBuf [ i ] < tMinusDelay ) { if ( i == newIdx ) break ; i = ( i < ( bufSz - 1
) ) ? ( i + 1 ) : 0 ; } } else { while ( tBuf [ i ] >= tMinusDelay ) { i = (
i > 0 ) ? i - 1 : ( bufSz - 1 ) ; } i = ( i < ( bufSz - 1 ) ) ? ( i + 1 ) : 0
; } * lastIdx = i ; if ( discrete ) { double tempEps = ( DBL_EPSILON ) *
128.0 ; double localEps = tempEps * muDoubleScalarAbs ( tBuf [ i ] ) ; if (
tempEps > localEps ) { localEps = tempEps ; } localEps = localEps / 2.0 ; if
( tMinusDelay >= ( tBuf [ i ] - localEps ) ) { yout = uBuf [ i ] ; } else {
if ( i == 0 ) { yout = uBuf [ bufSz - 1 ] ; } else { yout = uBuf [ i - 1 ] ;
} } } else { if ( i == 0 ) { t1 = tBuf [ bufSz - 1 ] ; u1 = uBuf [ bufSz - 1
] ; } else { t1 = tBuf [ i - 1 ] ; u1 = uBuf [ i - 1 ] ; } t2 = tBuf [ i ] ;
u2 = uBuf [ i ] ; if ( t2 == t1 ) { if ( tMinusDelay >= t2 ) { yout = u2 ; }
else { yout = u1 ; } } else { real_T f1 = ( t2 - tMinusDelay ) / ( t2 - t1 )
; real_T f2 = 1.0 - f1 ; yout = f1 * u1 + f2 * u2 ; } } return ( yout ) ; }
#ifndef __RTW_UTFREE__  
extern void utFree ( void * ) ;
#endif
void rt_TDelayFreeBuf ( void * buf ) { utFree ( buf ) ; } real_T
rt_urand_Upu32_Yd_f_pw_snf ( uint32_T * u ) { uint32_T hi ; uint32_T lo ; lo
= * u % 127773U * 16807U ; hi = * u / 127773U * 2836U ; if ( lo < hi ) { * u
= 2147483647U - ( hi - lo ) ; } else { * u = lo - hi ; } return ( real_T ) *
u * 4.6566128752457969E-10 ; } real_T rt_nrand_Upu32_Yd_f_pw_snf ( uint32_T *
u ) { real_T si ; real_T sr ; real_T y ; do { sr = 2.0 *
rt_urand_Upu32_Yd_f_pw_snf ( u ) - 1.0 ; si = 2.0 *
rt_urand_Upu32_Yd_f_pw_snf ( u ) - 1.0 ; si = sr * sr + si * si ; } while (
si > 1.0 ) ; y = muDoubleScalarSqrt ( - 2.0 * muDoubleScalarLog ( si ) / si )
* sr ; return y ; } static real_T klnbmqkqbd ( const real_T x [ 3 ] ) {
real_T absxk ; real_T scale ; real_T t ; real_T y ; scale =
3.3121686421112381E-170 ; absxk = muDoubleScalarAbs ( x [ 0 ] ) ; if ( absxk
> 3.3121686421112381E-170 ) { y = 1.0 ; scale = absxk ; } else { t = absxk /
3.3121686421112381E-170 ; y = t * t ; } absxk = muDoubleScalarAbs ( x [ 1 ] )
; if ( absxk > scale ) { t = scale / absxk ; y = y * t * t + 1.0 ; scale =
absxk ; } else { t = absxk / scale ; y += t * t ; } absxk = muDoubleScalarAbs
( x [ 2 ] ) ; if ( absxk > scale ) { t = scale / absxk ; y = y * t * t + 1.0
; scale = absxk ; } else { t = absxk / scale ; y += t * t ; } return scale *
muDoubleScalarSqrt ( y ) ; } static void hyrpevmtnt ( const real_T A [ 9 ] ,
const real_T B_p [ 3 ] , real_T Y [ 3 ] ) { real_T b_A [ 9 ] ; real_T maxval
; real_T y ; int32_T r1 ; int32_T r2 ; int32_T r3 ; int32_T rtemp ; memcpy (
& b_A [ 0 ] , & A [ 0 ] , 9U * sizeof ( real_T ) ) ; r1 = 0 ; r2 = 1 ; r3 = 2
; maxval = muDoubleScalarAbs ( A [ 0 ] ) ; y = muDoubleScalarAbs ( A [ 1 ] )
; if ( y > muDoubleScalarAbs ( A [ 0 ] ) ) { maxval = y ; r1 = 1 ; r2 = 0 ; }
if ( muDoubleScalarAbs ( A [ 2 ] ) > maxval ) { r1 = 2 ; r2 = 1 ; r3 = 0 ; }
b_A [ r2 ] = A [ r2 ] / A [ r1 ] ; b_A [ r3 ] /= b_A [ r1 ] ; b_A [ r2 + 3 ]
-= b_A [ r1 + 3 ] * b_A [ r2 ] ; b_A [ r3 + 3 ] -= b_A [ r1 + 3 ] * b_A [ r3
] ; b_A [ r2 + 6 ] -= b_A [ r1 + 6 ] * b_A [ r2 ] ; b_A [ r3 + 6 ] -= b_A [
r1 + 6 ] * b_A [ r3 ] ; if ( muDoubleScalarAbs ( b_A [ r3 + 3 ] ) >
muDoubleScalarAbs ( b_A [ r2 + 3 ] ) ) { rtemp = r2 ; r2 = r3 ; r3 = rtemp ;
} b_A [ r3 + 3 ] /= b_A [ r2 + 3 ] ; b_A [ r3 + 6 ] -= b_A [ r3 + 3 ] * b_A [
r2 + 6 ] ; Y [ 1 ] = B_p [ r2 ] - B_p [ r1 ] * b_A [ r2 ] ; Y [ 2 ] = ( B_p [
r3 ] - B_p [ r1 ] * b_A [ r3 ] ) - b_A [ r3 + 3 ] * Y [ 1 ] ; Y [ 2 ] /= b_A
[ r3 + 6 ] ; Y [ 0 ] = B_p [ r1 ] - b_A [ r1 + 6 ] * Y [ 2 ] ; Y [ 1 ] -= b_A
[ r2 + 6 ] * Y [ 2 ] ; Y [ 1 ] /= b_A [ r2 + 3 ] ; Y [ 0 ] -= b_A [ r1 + 3 ]
* Y [ 1 ] ; Y [ 0 ] /= b_A [ r1 ] ; } void MdlInitialize ( void ) { real_T
tmp_p ; int32_T r ; int32_T t ; uint32_T tseed ; boolean_T tmp ; rtX .
mdmb5a1yml = rtP . Integrator_IC ; memcpy ( & rtX . l3lup5gvqh [ 0 ] , & rtP
. Integrator_IC_ifj3pkofzc [ 0 ] , 9U * sizeof ( real_T ) ) ; tmp_p =
muDoubleScalarFloor ( rtP . RandomNumber1_Seed [ 0 ] ) ; if (
muDoubleScalarIsNaN ( tmp_p ) || muDoubleScalarIsInf ( tmp_p ) ) { tmp_p =
0.0 ; } else { tmp_p = muDoubleScalarRem ( tmp_p , 4.294967296E+9 ) ; } tseed
= tmp_p < 0.0 ? ( uint32_T ) - ( int32_T ) ( uint32_T ) - tmp_p : ( uint32_T
) tmp_p ; r = ( int32_T ) ( tseed >> 16U ) ; t = ( int32_T ) ( tseed & 32768U
) ; tseed = ( ( ( ( tseed - ( ( uint32_T ) r << 16U ) ) + t ) << 16U ) + t )
+ r ; if ( tseed < 1U ) { tseed = 1144108930U ; } else { if ( tseed >
2147483646U ) { tseed = 2147483646U ; } } rtDW . p3k2zi5joj [ 0 ] = tseed ;
rtDW . a5tv4scxvv [ 0 ] = rt_nrand_Upu32_Yd_f_pw_snf ( & rtDW . p3k2zi5joj [
0 ] ) * rtP . RandomNumber1_StdDev [ 0 ] + rtP . RandomNumber1_Mean ; rtX .
k5ybcxiwei [ 0 ] = rtP . Integrator_IC_c5e44kpjcd [ 0 ] ; tmp_p =
muDoubleScalarFloor ( rtP . RandomNumber1_Seed [ 1 ] ) ; if (
muDoubleScalarIsNaN ( tmp_p ) || muDoubleScalarIsInf ( tmp_p ) ) { tmp_p =
0.0 ; } else { tmp_p = muDoubleScalarRem ( tmp_p , 4.294967296E+9 ) ; } tseed
= tmp_p < 0.0 ? ( uint32_T ) - ( int32_T ) ( uint32_T ) - tmp_p : ( uint32_T
) tmp_p ; r = ( int32_T ) ( tseed >> 16U ) ; t = ( int32_T ) ( tseed & 32768U
) ; tseed = ( ( ( ( tseed - ( ( uint32_T ) r << 16U ) ) + t ) << 16U ) + t )
+ r ; if ( tseed < 1U ) { tseed = 1144108930U ; } else { if ( tseed >
2147483646U ) { tseed = 2147483646U ; } } rtDW . p3k2zi5joj [ 1 ] = tseed ;
rtDW . a5tv4scxvv [ 1 ] = rt_nrand_Upu32_Yd_f_pw_snf ( & rtDW . p3k2zi5joj [
1 ] ) * rtP . RandomNumber1_StdDev [ 1 ] + rtP . RandomNumber1_Mean ; rtX .
k5ybcxiwei [ 1 ] = rtP . Integrator_IC_c5e44kpjcd [ 1 ] ; tmp_p =
muDoubleScalarFloor ( rtP . RandomNumber1_Seed [ 2 ] ) ; if (
muDoubleScalarIsNaN ( tmp_p ) || muDoubleScalarIsInf ( tmp_p ) ) { tmp_p =
0.0 ; } else { tmp_p = muDoubleScalarRem ( tmp_p , 4.294967296E+9 ) ; } tseed
= tmp_p < 0.0 ? ( uint32_T ) - ( int32_T ) ( uint32_T ) - tmp_p : ( uint32_T
) tmp_p ; r = ( int32_T ) ( tseed >> 16U ) ; t = ( int32_T ) ( tseed & 32768U
) ; tseed = ( ( ( ( tseed - ( ( uint32_T ) r << 16U ) ) + t ) << 16U ) + t )
+ r ; if ( tseed < 1U ) { tseed = 1144108930U ; } else { if ( tseed >
2147483646U ) { tseed = 2147483646U ; } } rtDW . p3k2zi5joj [ 2 ] = tseed ;
rtDW . a5tv4scxvv [ 2 ] = rt_nrand_Upu32_Yd_f_pw_snf ( & rtDW . p3k2zi5joj [
2 ] ) * rtP . RandomNumber1_StdDev [ 2 ] + rtP . RandomNumber1_Mean ; rtX .
k5ybcxiwei [ 2 ] = rtP . Integrator_IC_c5e44kpjcd [ 2 ] ; tmp_p =
muDoubleScalarFloor ( rtP . RandomNumber_Seed [ 0 ] ) ; if (
muDoubleScalarIsNaN ( tmp_p ) || muDoubleScalarIsInf ( tmp_p ) ) { tmp_p =
0.0 ; } else { tmp_p = muDoubleScalarRem ( tmp_p , 4.294967296E+9 ) ; } tseed
= tmp_p < 0.0 ? ( uint32_T ) - ( int32_T ) ( uint32_T ) - tmp_p : ( uint32_T
) tmp_p ; r = ( int32_T ) ( tseed >> 16U ) ; t = ( int32_T ) ( tseed & 32768U
) ; tseed = ( ( ( ( tseed - ( ( uint32_T ) r << 16U ) ) + t ) << 16U ) + t )
+ r ; if ( tseed < 1U ) { tseed = 1144108930U ; } else { if ( tseed >
2147483646U ) { tseed = 2147483646U ; } } rtDW . apy12dao0a [ 0 ] = tseed ;
rtDW . donz0qvylr [ 0 ] = rt_nrand_Upu32_Yd_f_pw_snf ( & rtDW . apy12dao0a [
0 ] ) * rtP . RandomNumber_StdDev [ 0 ] + rtP . RandomNumber_Mean ; rtX .
cmqklstge4 [ 0 ] = rtP . Integrator_IC_juij5hh4y1 [ 0 ] ; tmp_p =
muDoubleScalarFloor ( rtP . RandomNumber_Seed [ 1 ] ) ; if (
muDoubleScalarIsNaN ( tmp_p ) || muDoubleScalarIsInf ( tmp_p ) ) { tmp_p =
0.0 ; } else { tmp_p = muDoubleScalarRem ( tmp_p , 4.294967296E+9 ) ; } tseed
= tmp_p < 0.0 ? ( uint32_T ) - ( int32_T ) ( uint32_T ) - tmp_p : ( uint32_T
) tmp_p ; r = ( int32_T ) ( tseed >> 16U ) ; t = ( int32_T ) ( tseed & 32768U
) ; tseed = ( ( ( ( tseed - ( ( uint32_T ) r << 16U ) ) + t ) << 16U ) + t )
+ r ; if ( tseed < 1U ) { tseed = 1144108930U ; } else { if ( tseed >
2147483646U ) { tseed = 2147483646U ; } } rtDW . apy12dao0a [ 1 ] = tseed ;
rtDW . donz0qvylr [ 1 ] = rt_nrand_Upu32_Yd_f_pw_snf ( & rtDW . apy12dao0a [
1 ] ) * rtP . RandomNumber_StdDev [ 1 ] + rtP . RandomNumber_Mean ; rtX .
cmqklstge4 [ 1 ] = rtP . Integrator_IC_juij5hh4y1 [ 1 ] ; tmp_p =
muDoubleScalarFloor ( rtP . RandomNumber_Seed [ 2 ] ) ; if (
muDoubleScalarIsNaN ( tmp_p ) || muDoubleScalarIsInf ( tmp_p ) ) { tmp_p =
0.0 ; } else { tmp_p = muDoubleScalarRem ( tmp_p , 4.294967296E+9 ) ; } tseed
= tmp_p < 0.0 ? ( uint32_T ) - ( int32_T ) ( uint32_T ) - tmp_p : ( uint32_T
) tmp_p ; r = ( int32_T ) ( tseed >> 16U ) ; t = ( int32_T ) ( tseed & 32768U
) ; tseed = ( ( ( ( tseed - ( ( uint32_T ) r << 16U ) ) + t ) << 16U ) + t )
+ r ; if ( tseed < 1U ) { tseed = 1144108930U ; } else { if ( tseed >
2147483646U ) { tseed = 2147483646U ; } } rtDW . apy12dao0a [ 2 ] = tseed ;
rtDW . donz0qvylr [ 2 ] = rt_nrand_Upu32_Yd_f_pw_snf ( & rtDW . apy12dao0a [
2 ] ) * rtP . RandomNumber_StdDev [ 2 ] + rtP . RandomNumber_Mean ; rtX .
cmqklstge4 [ 2 ] = rtP . Integrator_IC_juij5hh4y1 [ 2 ] ; rtDW . m3xid4gzul =
1 ; if ( ssIsFirstInitCond ( rtS ) ) { rtX . kn4trkmxb3 [ 0 ] = 0.0 ; rtX .
kn4trkmxb3 [ 1 ] = 0.0 ; rtX . kn4trkmxb3 [ 2 ] = 0.0 ; tmp =
slIsRapidAcceleratorSimulating ( ) ; if ( tmp ) { tmp =
ssGetGlobalInitialStatesAvailable ( rtS ) ; rtDW . m3xid4gzul = ! tmp ; }
else { rtDW . m3xid4gzul = 1 ; } } rtX . kumxbfxbuz = rtP .
Integrator_IC_lc2l1uvn30 ; tmp_p = muDoubleScalarFloor ( rtP .
RandomNumber1_Seed_gnd4ve32hq [ 0 ] ) ; if ( muDoubleScalarIsNaN ( tmp_p ) ||
muDoubleScalarIsInf ( tmp_p ) ) { tmp_p = 0.0 ; } else { tmp_p =
muDoubleScalarRem ( tmp_p , 4.294967296E+9 ) ; } tseed = tmp_p < 0.0 ? (
uint32_T ) - ( int32_T ) ( uint32_T ) - tmp_p : ( uint32_T ) tmp_p ; r = (
int32_T ) ( tseed >> 16U ) ; t = ( int32_T ) ( tseed & 32768U ) ; tseed = ( (
( ( tseed - ( ( uint32_T ) r << 16U ) ) + t ) << 16U ) + t ) + r ; if ( tseed
< 1U ) { tseed = 1144108930U ; } else { if ( tseed > 2147483646U ) { tseed =
2147483646U ; } } rtDW . lfp1taz3l3 [ 0 ] = tseed ; rtDW . mdfoxg3mo4 [ 0 ] =
rt_nrand_Upu32_Yd_f_pw_snf ( & rtDW . lfp1taz3l3 [ 0 ] ) * rtP .
RandomNumber1_StdDev_cudqkp3bpx [ 0 ] + rtP . RandomNumber1_Mean_pp0amcle2e ;
tmp_p = muDoubleScalarFloor ( rtP . RandomNumber1_Seed_gnd4ve32hq [ 1 ] ) ;
if ( muDoubleScalarIsNaN ( tmp_p ) || muDoubleScalarIsInf ( tmp_p ) ) { tmp_p
= 0.0 ; } else { tmp_p = muDoubleScalarRem ( tmp_p , 4.294967296E+9 ) ; }
tseed = tmp_p < 0.0 ? ( uint32_T ) - ( int32_T ) ( uint32_T ) - tmp_p : (
uint32_T ) tmp_p ; r = ( int32_T ) ( tseed >> 16U ) ; t = ( int32_T ) ( tseed
& 32768U ) ; tseed = ( ( ( ( tseed - ( ( uint32_T ) r << 16U ) ) + t ) << 16U
) + t ) + r ; if ( tseed < 1U ) { tseed = 1144108930U ; } else { if ( tseed >
2147483646U ) { tseed = 2147483646U ; } } rtDW . lfp1taz3l3 [ 1 ] = tseed ;
rtDW . mdfoxg3mo4 [ 1 ] = rt_nrand_Upu32_Yd_f_pw_snf ( & rtDW . lfp1taz3l3 [
1 ] ) * rtP . RandomNumber1_StdDev_cudqkp3bpx [ 1 ] + rtP .
RandomNumber1_Mean_pp0amcle2e ; tmp_p = muDoubleScalarFloor ( rtP .
RandomNumber1_Seed_gnd4ve32hq [ 2 ] ) ; if ( muDoubleScalarIsNaN ( tmp_p ) ||
muDoubleScalarIsInf ( tmp_p ) ) { tmp_p = 0.0 ; } else { tmp_p =
muDoubleScalarRem ( tmp_p , 4.294967296E+9 ) ; } tseed = tmp_p < 0.0 ? (
uint32_T ) - ( int32_T ) ( uint32_T ) - tmp_p : ( uint32_T ) tmp_p ; r = (
int32_T ) ( tseed >> 16U ) ; t = ( int32_T ) ( tseed & 32768U ) ; tseed = ( (
( ( tseed - ( ( uint32_T ) r << 16U ) ) + t ) << 16U ) + t ) + r ; if ( tseed
< 1U ) { tseed = 1144108930U ; } else { if ( tseed > 2147483646U ) { tseed =
2147483646U ; } } rtDW . lfp1taz3l3 [ 2 ] = tseed ; rtDW . mdfoxg3mo4 [ 2 ] =
rt_nrand_Upu32_Yd_f_pw_snf ( & rtDW . lfp1taz3l3 [ 2 ] ) * rtP .
RandomNumber1_StdDev_cudqkp3bpx [ 2 ] + rtP . RandomNumber1_Mean_pp0amcle2e ;
} void MdlStart ( void ) { { bool externalInputIsInDatasetFormat = false ;
void * pISigstreamManager = rt_GetISigstreamManager ( rtS ) ;
rtwISigstreamManagerGetInputIsInDatasetFormat ( pISigstreamManager , &
externalInputIsInDatasetFormat ) ; if ( externalInputIsInDatasetFormat ) { }
} { { int_T i1 ; int_T * iw_Tail = & rtDW . hxmmr0vle1 . Tail [ 0 ] ; int_T *
iw_Head = & rtDW . hxmmr0vle1 . Head [ 0 ] ; int_T * iw_Last = & rtDW .
hxmmr0vle1 . Last [ 0 ] ; int_T * iw_CircularBufSize = & rtDW . hxmmr0vle1 .
CircularBufSize [ 0 ] ; void * * pw_TUbufferPtrs = & rtDW . ja1mjqygva .
TUbufferPtrs [ 0 ] ; const real_T * p_TransportDelay_InitOutput = rtP .
TransportDelay_InitOutput ; for ( i1 = 0 ; i1 < 3 ; i1 ++ ) { real_T *
pBuffer = ( real_T * ) rt_TDelayCreateBuf ( 2 , 1024 , sizeof ( real_T ) ) ;
if ( pBuffer == ( NULL ) ) { ssSetErrorStatus ( rtS ,
"tdelay memory allocation error" ) ; return ; } iw_Tail [ i1 ] = 0 ; iw_Head
[ i1 ] = 0 ; iw_Last [ i1 ] = 0 ; iw_CircularBufSize [ i1 ] = 1024 ; pBuffer
[ 0 ] = ( p_TransportDelay_InitOutput [ i1 ] ) ; pBuffer [ 1024 ] = ssGetT (
rtS ) ; pw_TUbufferPtrs [ i1 ] = ( void * ) & pBuffer [ 0 ] ; pw_TUbufferPtrs
[ i1 + 3 ] = ( void * ) & pBuffer [ 1024 ] ; ssCachePointer ( rtS , & (
pw_TUbufferPtrs [ i1 ] ) ) ; ssCachePointer ( rtS , & ( pw_TUbufferPtrs [ i1
+ 3 ] ) ) ; const char * pUbufkey =
"detumbling/Control and Actuators/Transport\nDelay_U" ; ssSaveRawMemory ( rtS
, pUbufkey , pw_TUbufferPtrs [ i1 ] , 1024 * sizeof ( real_T ) ) ; const char
* pTbufkey = "detumbling/Control and Actuators/Transport\nDelay_T" ;
ssSaveRawMemory ( rtS , pTbufkey , pw_TUbufferPtrs [ i1 + 3 ] , 1024 * sizeof
( real_T ) ) ; } } } MdlInitialize ( ) ; } void MdlOutputs ( int_T tid ) {
static const int8_T b [ 3 ] = { 0 , 0 , 1 } ; static const int8_T b_p [ 3 ] =
{ 1 , 0 , 0 } ; real_T pbgkcapnqv [ 9 ] ; real_T tmp [ 9 ] ; real_T tmp_e [ 9
] ; real_T tmp_p [ 9 ] ; real_T MC1 [ 3 ] ; real_T mVers [ 3 ] ; real_T
n23pvq3m54 [ 3 ] ; real_T pckqn2nbc0 [ 3 ] ; real_T rVers [ 3 ] ; real_T
ciha4r5bm0 ; real_T jbpu00hig5_idx_0 ; real_T jbpu00hig5_idx_1 ; real_T
mgszinnhzv ; real_T r ; real_T rVers_e ; real_T rVers_p ; int32_T r1 ;
int32_T r2 ; int32_T r3 ; int32_T rtemp ; boolean_T isxv4gzr5t ; ciha4r5bm0 =
ssGetT ( rtS ) ; mgszinnhzv = ssGetT ( rtS ) ; rtB . ela1rhmmmi = rtX .
mdmb5a1yml ; r = ( 1.0 - rtP . Constant1_Value_lapgl51prt * rtP .
Constant1_Value_lapgl51prt ) * rtP . Constant_Value_kb0zyegq3x / ( rtP .
Constant1_Value_lapgl51prt * muDoubleScalarCos ( rtB . ela1rhmmmi ) + 1.0 ) ;
tmp [ 0 ] = muDoubleScalarCos ( rtP . Constant4_Value_plq0xk0dqt ) ; tmp [ 3
] = muDoubleScalarSin ( rtP . Constant4_Value_plq0xk0dqt ) ; tmp [ 6 ] = 0.0
; tmp [ 1 ] = - muDoubleScalarSin ( rtP . Constant4_Value_plq0xk0dqt ) ; tmp
[ 4 ] = muDoubleScalarCos ( rtP . Constant4_Value_plq0xk0dqt ) ; tmp [ 7 ] =
0.0 ; tmp [ 2 ] = 0.0 ; pbgkcapnqv [ 0 ] = 1.0 ; tmp [ 5 ] = 0.0 ; pbgkcapnqv
[ 3 ] = 0.0 ; tmp [ 8 ] = 1.0 ; pbgkcapnqv [ 6 ] = 0.0 ; pbgkcapnqv [ 1 ] =
0.0 ; pbgkcapnqv [ 4 ] = muDoubleScalarCos ( rtP . Constant2_Value_pn5msfmygz
) ; pbgkcapnqv [ 7 ] = muDoubleScalarSin ( rtP . Constant2_Value_pn5msfmygz )
; pbgkcapnqv [ 2 ] = 0.0 ; pbgkcapnqv [ 5 ] = - muDoubleScalarSin ( rtP .
Constant2_Value_pn5msfmygz ) ; pbgkcapnqv [ 8 ] = muDoubleScalarCos ( rtP .
Constant2_Value_pn5msfmygz ) ; tmp_e [ 0 ] = muDoubleScalarCos ( rtP .
Constant3_Value_lnlpkng3dr ) ; tmp_e [ 3 ] = muDoubleScalarSin ( rtP .
Constant3_Value_lnlpkng3dr ) ; tmp_e [ 6 ] = 0.0 ; tmp_e [ 1 ] = -
muDoubleScalarSin ( rtP . Constant3_Value_lnlpkng3dr ) ; tmp_e [ 4 ] =
muDoubleScalarCos ( rtP . Constant3_Value_lnlpkng3dr ) ; tmp_e [ 7 ] = 0.0 ;
for ( r2 = 0 ; r2 < 3 ; r2 ++ ) { for ( r1 = 0 ; r1 < 3 ; r1 ++ ) { tmp_p [
r2 + 3 * r1 ] = 0.0 ; tmp_p [ r2 + 3 * r1 ] += pbgkcapnqv [ 3 * r1 ] * tmp [
r2 ] ; tmp_p [ r2 + 3 * r1 ] += pbgkcapnqv [ 3 * r1 + 1 ] * tmp [ r2 + 3 ] ;
tmp_p [ r2 + 3 * r1 ] += pbgkcapnqv [ 3 * r1 + 2 ] * tmp [ r2 + 6 ] ; } tmp_e
[ 3 * r2 + 2 ] = b [ r2 ] ; } rVers [ 0 ] = r * muDoubleScalarCos ( rtB .
ela1rhmmmi ) ; rVers [ 1 ] = r * muDoubleScalarSin ( rtB . ela1rhmmmi ) ;
rVers [ 2 ] = r * 0.0 ; for ( r2 = 0 ; r2 < 3 ; r2 ++ ) { pckqn2nbc0 [ r2 ] =
0.0 ; for ( r1 = 0 ; r1 < 3 ; r1 ++ ) { pbgkcapnqv [ r2 + 3 * r1 ] = 0.0 ;
pbgkcapnqv [ r2 + 3 * r1 ] += tmp_e [ 3 * r2 ] * tmp_p [ r1 ] ; pbgkcapnqv [
r2 + 3 * r1 ] += tmp_e [ 3 * r2 + 1 ] * tmp_p [ r1 + 3 ] ; pbgkcapnqv [ r2 +
3 * r1 ] += tmp_e [ 3 * r2 + 2 ] * tmp_p [ r1 + 6 ] ; pckqn2nbc0 [ r2 ] +=
pbgkcapnqv [ 3 * r1 + r2 ] * rVers [ r1 ] ; } } memcpy ( & rtB . jbo3v4ajb3 [
0 ] , & rtX . l3lup5gvqh [ 0 ] , 9U * sizeof ( real_T ) ) ; mVers [ 0 ] =
muDoubleScalarCos ( 7.2921148843226185E-5 * mgszinnhzv ) *
0.19936793441719716 ; mVers [ 1 ] = muDoubleScalarSin ( 7.2921148843226185E-5
* mgszinnhzv ) * 0.19936793441719716 ; mVers [ 2 ] = 0.97992470462082959 ;
rVers_e = klnbmqkqbd ( pckqn2nbc0 ) ; mgszinnhzv = 0.0 ; for ( r1 = 0 ; r1 <
3 ; r1 ++ ) { for ( r2 = 0 ; r2 < 3 ; r2 ++ ) { tmp [ r1 + 3 * r2 ] = 0.0 ;
tmp [ r1 + 3 * r2 ] += rtB . jbo3v4ajb3 [ r1 ] * rtB . jbo3v4ajb3 [ r2 ] ;
tmp [ r1 + 3 * r2 ] += rtB . jbo3v4ajb3 [ r1 + 3 ] * rtB . jbo3v4ajb3 [ r2 +
3 ] ; tmp [ r1 + 3 * r2 ] += rtB . jbo3v4ajb3 [ r1 + 6 ] * rtB . jbo3v4ajb3 [
r2 + 6 ] ; } for ( r2 = 0 ; r2 < 3 ; r2 ++ ) { rtB . p13uq5o22a [ r1 + 3 * r2
] = rtB . jbo3v4ajb3 [ 3 * r2 + r1 ] * 3.0 / 2.0 - ( ( rtB . jbo3v4ajb3 [ 3 *
r2 + 1 ] * tmp [ r1 + 3 ] + rtB . jbo3v4ajb3 [ 3 * r2 ] * tmp [ r1 ] ) + rtB
. jbo3v4ajb3 [ 3 * r2 + 2 ] * tmp [ r1 + 6 ] ) / 2.0 ; } rVers [ r1 ] =
pckqn2nbc0 [ r1 ] / rVers_e ; mgszinnhzv += mVers [ r1 ] * rVers [ r1 ] ; }
mgszinnhzv *= 3.0 ; r = 2.5859767437900247E+11 / muDoubleScalarPower (
klnbmqkqbd ( pckqn2nbc0 ) , 3.0 ) * 3.0115258673967919E-5 ; jbpu00hig5_idx_0
= ( mgszinnhzv * rVers [ 0 ] - mVers [ 0 ] ) * r ; jbpu00hig5_idx_1 = (
mgszinnhzv * rVers [ 1 ] - mVers [ 1 ] ) * r ; r *= mgszinnhzv * rVers [ 2 ]
- 0.97992470462082959 ; for ( r2 = 0 ; r2 < 3 ; r2 ++ ) { n23pvq3m54 [ r2 ] =
rtB . p13uq5o22a [ r2 + 6 ] * r + ( rtB . p13uq5o22a [ r2 + 3 ] *
jbpu00hig5_idx_1 + rtB . p13uq5o22a [ r2 ] * jbpu00hig5_idx_0 ) ; } if (
ssIsSampleHit ( rtS , 3 , 0 ) ) { rtB . ahdpwrjj5d [ 0 ] = rtDW . a5tv4scxvv
[ 0 ] ; rtB . ahdpwrjj5d [ 1 ] = rtDW . a5tv4scxvv [ 1 ] ; rtB . ahdpwrjj5d [
2 ] = rtDW . a5tv4scxvv [ 2 ] ; } rtB . bqon2dgr5d [ 0 ] = n23pvq3m54 [ 0 ] +
rtB . ahdpwrjj5d [ 0 ] ; rtB . bqon2dgr5d [ 1 ] = n23pvq3m54 [ 1 ] + rtB .
ahdpwrjj5d [ 1 ] ; rtB . bqon2dgr5d [ 2 ] = n23pvq3m54 [ 2 ] + rtB .
ahdpwrjj5d [ 2 ] ; if ( ssIsSampleHit ( rtS , 3 , 0 ) ) { rtB . nrhgec3vav [
0 ] = rtB . bqon2dgr5d [ 0 ] ; rtB . nrhgec3vav [ 1 ] = rtB . bqon2dgr5d [ 1
] ; rtB . nrhgec3vav [ 2 ] = rtB . bqon2dgr5d [ 2 ] ; } { real_T * * uBuffer
= ( real_T * * ) & rtDW . ja1mjqygva . TUbufferPtrs [ 0 ] ; real_T * *
tBuffer = ( real_T * * ) & rtDW . ja1mjqygva . TUbufferPtrs [ 3 ] ; real_T
simTime = ssGetT ( rtS ) ; real_T tMinusDelay ; { int_T i1 ; real_T * y0 = &
rtB . fh0tz1ct3t [ 0 ] ; const real_T * p_TransportDelay_InitOutput = rtP .
TransportDelay_InitOutput ; int_T * iw_Tail = & rtDW . hxmmr0vle1 . Tail [ 0
] ; int_T * iw_Head = & rtDW . hxmmr0vle1 . Head [ 0 ] ; int_T * iw_Last = &
rtDW . hxmmr0vle1 . Last [ 0 ] ; int_T * iw_CircularBufSize = & rtDW .
hxmmr0vle1 . CircularBufSize [ 0 ] ; for ( i1 = 0 ; i1 < 3 ; i1 ++ ) {
tMinusDelay = ( ( rtP . TransportDelay_Delay > 0.0 ) ? rtP .
TransportDelay_Delay : 0.0 ) ; tMinusDelay = simTime - tMinusDelay ; y0 [ i1
] = rt_TDelayInterpolate ( tMinusDelay , 0.0 , * tBuffer , * uBuffer ,
iw_CircularBufSize [ i1 ] , & iw_Last [ i1 ] , iw_Tail [ i1 ] , iw_Head [ i1
] , ( p_TransportDelay_InitOutput [ i1 ] ) , 1 , ( boolean_T ) (
ssIsMinorTimeStep ( rtS ) && ( ssGetTimeOfLastOutput ( rtS ) == ssGetT ( rtS
) ) ) ) ; tBuffer ++ ; uBuffer ++ ; } } } rtB . c1dnkkzf2p [ 0 ] = rtB .
nrhgec3vav [ 0 ] - rtB . fh0tz1ct3t [ 0 ] ; rtB . c1dnkkzf2p [ 1 ] = rtB .
nrhgec3vav [ 1 ] - rtB . fh0tz1ct3t [ 1 ] ; rtB . c1dnkkzf2p [ 2 ] = rtB .
nrhgec3vav [ 2 ] - rtB . fh0tz1ct3t [ 2 ] ; rtB . l1nazchf2g = ssGetT ( rtS )
; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { if ( ssIsMajorTimeStep ( rtS ) ) {
rtDW . klnbyfrse2 = ( rtB . l1nazchf2g > rtP . Constant1_Value_cw3pti1zff ) ;
} rtB . b13up4rwa2 = rtDW . klnbyfrse2 ; } rtB . kl0s5rlxlx [ 0 ] = rtX .
k5ybcxiwei [ 0 ] ; rtB . kl0s5rlxlx [ 1 ] = rtX . k5ybcxiwei [ 1 ] ; rtB .
kl0s5rlxlx [ 2 ] = rtX . k5ybcxiwei [ 2 ] ; if ( ssIsSampleHit ( rtS , 2 , 0
) ) { rtB . dlgknc2iej [ 0 ] = rtDW . donz0qvylr [ 0 ] ; rtB . dlgknc2iej [ 1
] = rtDW . donz0qvylr [ 1 ] ; rtB . dlgknc2iej [ 2 ] = rtDW . donz0qvylr [ 2
] ; } rtB . d0bsyboket [ 0 ] = rtX . cmqklstge4 [ 0 ] ; rtB . lkneu0sjol [ 0
] = ( rtB . dlgknc2iej [ 0 ] + rtB . d0bsyboket [ 0 ] ) + rtB . kl0s5rlxlx [
0 ] ; rtB . d0bsyboket [ 1 ] = rtX . cmqklstge4 [ 1 ] ; rtB . lkneu0sjol [ 1
] = ( rtB . dlgknc2iej [ 1 ] + rtB . d0bsyboket [ 1 ] ) + rtB . kl0s5rlxlx [
1 ] ; rtB . d0bsyboket [ 2 ] = rtX . cmqklstge4 [ 2 ] ; rtB . lkneu0sjol [ 2
] = ( rtB . dlgknc2iej [ 2 ] + rtB . d0bsyboket [ 2 ] ) + rtB . kl0s5rlxlx [
2 ] ; if ( ssIsSampleHit ( rtS , 2 , 0 ) ) { rtB . gcsyrgudhi [ 0 ] = rtB .
lkneu0sjol [ 0 ] ; rtB . gcsyrgudhi [ 1 ] = rtB . lkneu0sjol [ 1 ] ; rtB .
gcsyrgudhi [ 2 ] = rtB . lkneu0sjol [ 2 ] ; } if ( ssIsMajorTimeStep ( rtS )
) { isxv4gzr5t = ( rtB . b13up4rwa2 && ( rtPrevZCX . gqlxm0wffx != POS_ZCSIG
) ) ; rtPrevZCX . gqlxm0wffx = rtB . b13up4rwa2 ; if ( isxv4gzr5t || ( rtDW .
m3xid4gzul != 0 ) ) { rtX . kn4trkmxb3 [ 0 ] = rtB . gcsyrgudhi [ 0 ] ; rtX .
kn4trkmxb3 [ 1 ] = rtB . gcsyrgudhi [ 1 ] ; rtX . kn4trkmxb3 [ 2 ] = rtB .
gcsyrgudhi [ 2 ] ; ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; } rtB
. pkc5yfmw2v [ 0 ] = rtX . kn4trkmxb3 [ 0 ] ; rtB . pkc5yfmw2v [ 1 ] = rtX .
kn4trkmxb3 [ 1 ] ; rtB . pkc5yfmw2v [ 2 ] = rtX . kn4trkmxb3 [ 2 ] ; } else {
rtB . pkc5yfmw2v [ 0 ] = rtX . kn4trkmxb3 [ 0 ] ; rtB . pkc5yfmw2v [ 1 ] =
rtX . kn4trkmxb3 [ 1 ] ; rtB . pkc5yfmw2v [ 2 ] = rtX . kn4trkmxb3 [ 2 ] ; }
rtB . h2dle1tjk3 = rtX . kumxbfxbuz ; r = 0.0 ; jbpu00hig5_idx_0 = 0.0 ; rtB
. nvcvw4zh5h [ 0 ] = 0.0 ; mVers [ 0 ] = 0.0 ; jbpu00hig5_idx_1 = 0.0 ; rtB .
nvcvw4zh5h [ 1 ] = 0.0 ; mVers [ 1 ] = 0.0 ; mgszinnhzv = 0.0 ; rtB .
nvcvw4zh5h [ 2 ] = 0.0 ; mVers [ 2 ] = 0.0 ; if ( ( ciha4r5bm0 > 0.0 ) && (
ciha4r5bm0 < rtP . Constant2_Value ) ) { ciha4r5bm0 = - rtP . Constant1_Value
* rtB . c1dnkkzf2p [ 0 ] ; MC1 [ 0 ] = muDoubleScalarMax ( ciha4r5bm0 , - rtP
. Constant7_Value ) ; jbpu00hig5_idx_0 = ciha4r5bm0 ; ciha4r5bm0 = - rtP .
Constant1_Value * rtB . c1dnkkzf2p [ 1 ] ; MC1 [ 1 ] = muDoubleScalarMax (
ciha4r5bm0 , - rtP . Constant7_Value ) ; jbpu00hig5_idx_1 = ciha4r5bm0 ;
ciha4r5bm0 = - rtP . Constant1_Value * rtB . c1dnkkzf2p [ 2 ] ; rtB .
nvcvw4zh5h [ 0 ] = jbpu00hig5_idx_1 * rtB . nrhgec3vav [ 2 ] - ciha4r5bm0 *
rtB . nrhgec3vav [ 1 ] ; rtB . nvcvw4zh5h [ 1 ] = ciha4r5bm0 * rtB .
nrhgec3vav [ 0 ] - jbpu00hig5_idx_0 * rtB . nrhgec3vav [ 2 ] ; rtB .
nvcvw4zh5h [ 2 ] = jbpu00hig5_idx_0 * rtB . nrhgec3vav [ 1 ] -
jbpu00hig5_idx_1 * rtB . nrhgec3vav [ 0 ] ; jbpu00hig5_idx_0 =
muDoubleScalarMin ( MC1 [ 0 ] , rtP . Constant7_Value ) ; jbpu00hig5_idx_1 =
muDoubleScalarMin ( MC1 [ 1 ] , rtP . Constant7_Value ) ; mgszinnhzv =
muDoubleScalarMin ( muDoubleScalarMax ( ciha4r5bm0 , - rtP . Constant7_Value
) , rtP . Constant7_Value ) ; mVers [ 0 ] = jbpu00hig5_idx_1 * rtB .
nrhgec3vav [ 2 ] - mgszinnhzv * rtB . nrhgec3vav [ 1 ] ; mVers [ 1 ] =
mgszinnhzv * rtB . nrhgec3vav [ 0 ] - jbpu00hig5_idx_0 * rtB . nrhgec3vav [ 2
] ; mVers [ 2 ] = jbpu00hig5_idx_0 * rtB . nrhgec3vav [ 1 ] -
jbpu00hig5_idx_1 * rtB . nrhgec3vav [ 0 ] ; } else { if ( ( ciha4r5bm0 > rtP
. Constant2_Value ) && ( ciha4r5bm0 < rtP . Constant3_Value ) ) { rtB .
nvcvw4zh5h [ 0 ] = - rtP . Constant_Value * rtB . pkc5yfmw2v [ 0 ] ; rVers [
0 ] = rtP . Constant5_Value [ 0 ] * rtB . h2dle1tjk3 ; rtB . nvcvw4zh5h [ 1 ]
= - rtP . Constant_Value * rtB . pkc5yfmw2v [ 1 ] ; rVers [ 1 ] = rtP .
Constant5_Value [ 1 ] * rtB . h2dle1tjk3 ; rtB . nvcvw4zh5h [ 2 ] = - rtP .
Constant_Value * rtB . pkc5yfmw2v [ 2 ] ; rVers [ 2 ] = rtP . Constant5_Value
[ 2 ] * rtB . h2dle1tjk3 ; MC1 [ 0 ] = ( rtB . pkc5yfmw2v [ 1 ] * rVers [ 2 ]
- rtB . pkc5yfmw2v [ 2 ] * rVers [ 1 ] ) + rtB . nvcvw4zh5h [ 0 ] ; MC1 [ 1 ]
= ( rtB . pkc5yfmw2v [ 2 ] * rVers [ 0 ] - rtB . pkc5yfmw2v [ 0 ] * rVers [ 2
] ) + rtB . nvcvw4zh5h [ 1 ] ; MC1 [ 2 ] = ( rtB . pkc5yfmw2v [ 0 ] * rVers [
1 ] - rtB . pkc5yfmw2v [ 1 ] * rVers [ 0 ] ) + rtB . nvcvw4zh5h [ 2 ] ;
rVers_e = klnbmqkqbd ( rtB . nrhgec3vav ) ; r = rtB . nrhgec3vav [ 0 ] /
rVers_e ; ciha4r5bm0 = rtP . Constant5_Value [ 0 ] * r ; mVers [ 0 ] = r ; r
= rtB . nrhgec3vav [ 1 ] / rVers_e ; ciha4r5bm0 += rtP . Constant5_Value [ 1
] * r ; mVers [ 1 ] = r ; r = rtB . nrhgec3vav [ 2 ] / rVers_e ; ciha4r5bm0
+= rtP . Constant5_Value [ 2 ] * r ; if ( muDoubleScalarAbs ( ciha4r5bm0 ) <
1.0E-15 ) { ciha4r5bm0 = 1.0E-15 * muDoubleScalarSign ( ciha4r5bm0 ) ; } r =
- ( ( MC1 [ 0 ] * mVers [ 0 ] + MC1 [ 1 ] * mVers [ 1 ] ) + MC1 [ 2 ] * r ) /
ciha4r5bm0 ; if ( ( muDoubleScalarAbs ( rtB . h2dle1tjk3 ) > rtP .
Constant4_Value ) && ( r * rtB . h2dle1tjk3 > 0.0 ) ) { r = 0.0 ; } if (
muDoubleScalarAbs ( r ) > rtP . Constant6_Value ) { r = muDoubleScalarSign (
r ) * rtP . Constant6_Value ; } mgszinnhzv = klnbmqkqbd ( rtB . nrhgec3vav )
; mgszinnhzv *= mgszinnhzv ; MC1 [ 0 ] += r * rtP . Constant5_Value [ 0 ] ;
MC1 [ 1 ] += r * rtP . Constant5_Value [ 1 ] ; MC1 [ 2 ] += r * rtP .
Constant5_Value [ 2 ] ; jbpu00hig5_idx_0 = muDoubleScalarMin (
muDoubleScalarMax ( ( rtB . nrhgec3vav [ 1 ] * MC1 [ 2 ] - rtB . nrhgec3vav [
2 ] * MC1 [ 1 ] ) / mgszinnhzv , - rtP . Constant7_Value ) , rtP .
Constant7_Value ) ; rVers [ 0 ] = rtB . h2dle1tjk3 * rtP . Constant5_Value [
0 ] ; jbpu00hig5_idx_1 = muDoubleScalarMin ( muDoubleScalarMax ( ( rtB .
nrhgec3vav [ 2 ] * MC1 [ 0 ] - rtB . nrhgec3vav [ 0 ] * MC1 [ 2 ] ) /
mgszinnhzv , - rtP . Constant7_Value ) , rtP . Constant7_Value ) ; rVers [ 1
] = rtB . h2dle1tjk3 * rtP . Constant5_Value [ 1 ] ; mgszinnhzv =
muDoubleScalarMin ( muDoubleScalarMax ( ( rtB . nrhgec3vav [ 0 ] * MC1 [ 1 ]
- rtB . nrhgec3vav [ 1 ] * MC1 [ 0 ] ) / mgszinnhzv , - rtP . Constant7_Value
) , rtP . Constant7_Value ) ; rVers_e = rtB . h2dle1tjk3 * rtP .
Constant5_Value [ 2 ] ; mVers [ 0 ] = ( ( jbpu00hig5_idx_1 * rtB . nrhgec3vav
[ 2 ] - mgszinnhzv * rtB . nrhgec3vav [ 1 ] ) - r * rtP . Constant5_Value [ 0
] ) - ( rtB . pkc5yfmw2v [ 1 ] * rVers_e - rtB . pkc5yfmw2v [ 2 ] * rVers [ 1
] ) ; mVers [ 1 ] = ( ( mgszinnhzv * rtB . nrhgec3vav [ 0 ] -
jbpu00hig5_idx_0 * rtB . nrhgec3vav [ 2 ] ) - r * rtP . Constant5_Value [ 1 ]
) - ( rtB . pkc5yfmw2v [ 2 ] * rVers [ 0 ] - rtB . pkc5yfmw2v [ 0 ] * rVers_e
) ; mVers [ 2 ] = ( ( jbpu00hig5_idx_0 * rtB . nrhgec3vav [ 1 ] -
jbpu00hig5_idx_1 * rtB . nrhgec3vav [ 0 ] ) - r * rtP . Constant5_Value [ 2 ]
) - ( rtB . pkc5yfmw2v [ 0 ] * rVers [ 1 ] - rtB . pkc5yfmw2v [ 1 ] * rVers [
0 ] ) ; } } rtB . e4c42ch1lv = r ; rVers [ 0 ] = rtP . Constant9_Value [ 0 ]
* rtB . h2dle1tjk3 ; rVers [ 1 ] = rtP . Constant9_Value [ 1 ] * rtB .
h2dle1tjk3 ; rVers [ 2 ] = rtP . Constant9_Value [ 2 ] * rtB . h2dle1tjk3 ;
rtB . pldpuimngh [ 0 ] = ( - ( rtB . kl0s5rlxlx [ 1 ] * rVers [ 2 ] - rtB .
kl0s5rlxlx [ 2 ] * rVers [ 1 ] ) - rtP . Constant9_Value [ 0 ] * rtB .
e4c42ch1lv ) + ( jbpu00hig5_idx_1 * n23pvq3m54 [ 2 ] - mgszinnhzv *
n23pvq3m54 [ 1 ] ) ; rtB . pldpuimngh [ 1 ] = ( - ( rtB . kl0s5rlxlx [ 2 ] *
rVers [ 0 ] - rtB . kl0s5rlxlx [ 0 ] * rVers [ 2 ] ) - rtP . Constant9_Value
[ 1 ] * rtB . e4c42ch1lv ) + ( mgszinnhzv * n23pvq3m54 [ 0 ] -
jbpu00hig5_idx_0 * n23pvq3m54 [ 2 ] ) ; rtB . pldpuimngh [ 2 ] = ( - ( rtB .
kl0s5rlxlx [ 0 ] * rVers [ 1 ] - rtB . kl0s5rlxlx [ 1 ] * rVers [ 0 ] ) - rtP
. Constant9_Value [ 2 ] * rtB . e4c42ch1lv ) + ( jbpu00hig5_idx_0 *
n23pvq3m54 [ 1 ] - jbpu00hig5_idx_1 * n23pvq3m54 [ 0 ] ) ; mgszinnhzv =
3.3121686421112381E-170 ; r = muDoubleScalarAbs ( pckqn2nbc0 [ 0 ] ) ; if ( r
> 3.3121686421112381E-170 ) { ciha4r5bm0 = 1.0 ; mgszinnhzv = r ; } else {
jbpu00hig5_idx_0 = r / 3.3121686421112381E-170 ; ciha4r5bm0 =
jbpu00hig5_idx_0 * jbpu00hig5_idx_0 ; } r = muDoubleScalarAbs ( pckqn2nbc0 [
1 ] ) ; if ( r > mgszinnhzv ) { jbpu00hig5_idx_0 = mgszinnhzv / r ;
ciha4r5bm0 = ciha4r5bm0 * jbpu00hig5_idx_0 * jbpu00hig5_idx_0 + 1.0 ;
mgszinnhzv = r ; } else { jbpu00hig5_idx_0 = r / mgszinnhzv ; ciha4r5bm0 +=
jbpu00hig5_idx_0 * jbpu00hig5_idx_0 ; } r = muDoubleScalarAbs ( pckqn2nbc0 [
2 ] ) ; if ( r > mgszinnhzv ) { jbpu00hig5_idx_0 = mgszinnhzv / r ;
ciha4r5bm0 = ciha4r5bm0 * jbpu00hig5_idx_0 * jbpu00hig5_idx_0 + 1.0 ;
mgszinnhzv = r ; } else { jbpu00hig5_idx_0 = r / mgszinnhzv ; ciha4r5bm0 +=
jbpu00hig5_idx_0 * jbpu00hig5_idx_0 ; } ciha4r5bm0 = mgszinnhzv *
muDoubleScalarSqrt ( ciha4r5bm0 ) ; tmp [ 0 ] = muDoubleScalarCos ( rtB .
ela1rhmmmi ) ; tmp [ 3 ] = muDoubleScalarSin ( rtB . ela1rhmmmi ) ; tmp [ 6 ]
= 0.0 ; tmp [ 1 ] = - muDoubleScalarSin ( rtB . ela1rhmmmi ) ; tmp [ 4 ] =
muDoubleScalarCos ( rtB . ela1rhmmmi ) ; tmp [ 7 ] = 0.0 ; tmp [ 2 ] = 0.0 ;
tmp [ 5 ] = 0.0 ; tmp [ 8 ] = 1.0 ; for ( r2 = 0 ; r2 < 3 ; r2 ++ ) { for (
r1 = 0 ; r1 < 3 ; r1 ++ ) { tmp_p [ r2 + 3 * r1 ] = 0.0 ; tmp_p [ r2 + 3 * r1
] += tmp [ r1 ] * pbgkcapnqv [ r2 ] ; tmp_p [ r2 + 3 * r1 ] += tmp [ r1 + 3 ]
* pbgkcapnqv [ r2 + 3 ] ; tmp_p [ r2 + 3 * r1 ] += tmp [ r1 + 6 ] *
pbgkcapnqv [ r2 + 6 ] ; } } ciha4r5bm0 = 1.1958E+6 / muDoubleScalarPower (
ciha4r5bm0 , 3.0 ) ; mgszinnhzv = ssGetT ( rtS ) ; rVers [ 0 ] =
muDoubleScalarCos ( 1.9923849908611065E-7 * mgszinnhzv ) * 1.496E+8 ; rVers [
1 ] = muDoubleScalarSin ( 1.9923849908611065E-7 * mgszinnhzv ) *
0.91740769935748834 * 1.496E+8 ; rVers [ 2 ] = muDoubleScalarSin (
1.9923849908611065E-7 * mgszinnhzv ) * 0.39794863130761032 * 1.496E+8 ;
jbpu00hig5_idx_1 = 0.0 ; mgszinnhzv = 3.3121686421112381E-170 ; for ( r1 = 0
; r1 < 3 ; r1 ++ ) { pckqn2nbc0 [ r1 ] = 0.0 ; for ( r2 = 0 ; r2 < 3 ; r2 ++
) { tmp [ r1 + 3 * r2 ] = 0.0 ; tmp [ r1 + 3 * r2 ] += tmp_p [ 3 * r2 ] * rtB
. p13uq5o22a [ r1 ] ; tmp [ r1 + 3 * r2 ] += tmp_p [ 3 * r2 + 1 ] * rtB .
p13uq5o22a [ r1 + 3 ] ; tmp [ r1 + 3 * r2 ] += tmp_p [ 3 * r2 + 2 ] * rtB .
p13uq5o22a [ r1 + 6 ] ; pckqn2nbc0 [ r1 ] += tmp [ 3 * r2 + r1 ] * ( real_T )
b_p [ r2 ] ; } r = muDoubleScalarAbs ( rVers [ r1 ] ) ; if ( r > mgszinnhzv )
{ jbpu00hig5_idx_0 = mgszinnhzv / r ; jbpu00hig5_idx_1 = jbpu00hig5_idx_1 *
jbpu00hig5_idx_0 * jbpu00hig5_idx_0 + 1.0 ; mgszinnhzv = r ; } else {
jbpu00hig5_idx_0 = r / mgszinnhzv ; jbpu00hig5_idx_1 += jbpu00hig5_idx_0 *
jbpu00hig5_idx_0 ; } } jbpu00hig5_idx_1 = mgszinnhzv * muDoubleScalarSqrt (
jbpu00hig5_idx_1 ) ; rVers [ 0 ] /= jbpu00hig5_idx_1 ; rVers [ 1 ] /=
jbpu00hig5_idx_1 ; rVers_e = rVers [ 2 ] / jbpu00hig5_idx_1 ; for ( r2 = 0 ;
r2 < 3 ; r2 ++ ) { MC1 [ r2 ] = rtB . p13uq5o22a [ r2 + 6 ] * rVers_e + ( rtB
. p13uq5o22a [ r2 + 3 ] * rVers [ 1 ] + rtB . p13uq5o22a [ r2 ] * rVers [ 0 ]
) ; } rVers [ 0 ] = 0.0 ; rVers [ 1 ] = 0.0 ; rVers [ 2 ] = 0.0 ; for ( r2 =
0 ; r2 < 14 ; r2 ++ ) { r = ( rtP . Constant4_Value_hr4vhts24r [ 3 * r2 + 1 ]
* MC1 [ 1 ] + rtP . Constant4_Value_hr4vhts24r [ 3 * r2 ] * MC1 [ 0 ] ) + rtP
. Constant4_Value_hr4vhts24r [ 3 * r2 + 2 ] * MC1 [ 2 ] ; if ( r > 0.0 ) {
mgszinnhzv = 2.0 * rtP . Constant2_Value_p0tf13dhms [ r2 ] * r +
0.66666666666666663 * rtP . Constant3_Value_mitst2s14q [ r2 ] ; r *= -
6.938E-6 * rtP . Constant6_Value_bsw1z5ftyf [ r2 ] ; rVers_e = 1.0 - rtP .
Constant2_Value_p0tf13dhms [ r2 ] ; jbpu00hig5_idx_0 = ( rtP .
Constant4_Value_hr4vhts24r [ 3 * r2 ] * mgszinnhzv + rVers_e * MC1 [ 0 ] ) *
r ; jbpu00hig5_idx_1 = ( rtP . Constant4_Value_hr4vhts24r [ 3 * r2 + 1 ] *
mgszinnhzv + rVers_e * MC1 [ 1 ] ) * r ; mgszinnhzv = ( rtP .
Constant4_Value_hr4vhts24r [ 3 * r2 + 2 ] * mgszinnhzv + rVers_e * MC1 [ 2 ]
) * r ; rVers_e = rVers [ 0 ] ; r = rVers [ 1 ] ; rVers_p = rVers [ 2 ] ;
rVers [ 0 ] = ( rtP . Constant5_Value_oj3yslavn5 [ 3 * r2 + 1 ] * mgszinnhzv
- rtP . Constant5_Value_oj3yslavn5 [ 3 * r2 + 2 ] * jbpu00hig5_idx_1 ) +
rVers_e ; rVers [ 1 ] = ( rtP . Constant5_Value_oj3yslavn5 [ 3 * r2 + 2 ] *
jbpu00hig5_idx_0 - rtP . Constant5_Value_oj3yslavn5 [ 3 * r2 ] * mgszinnhzv )
+ r ; rVers [ 2 ] = ( rtP . Constant5_Value_oj3yslavn5 [ 3 * r2 ] *
jbpu00hig5_idx_1 - rtP . Constant5_Value_oj3yslavn5 [ 3 * r2 + 1 ] *
jbpu00hig5_idx_0 ) + rVers_p ; } } MC1 [ 0 ] = ( rtP .
Constant_Value_nedwe54uwp [ 8 ] - rtP . Constant_Value_nedwe54uwp [ 4 ] ) *
pckqn2nbc0 [ 2 ] * pckqn2nbc0 [ 1 ] * ciha4r5bm0 ; MC1 [ 1 ] = ( rtP .
Constant_Value_nedwe54uwp [ 0 ] - rtP . Constant_Value_nedwe54uwp [ 8 ] ) *
pckqn2nbc0 [ 0 ] * pckqn2nbc0 [ 2 ] * ciha4r5bm0 ; MC1 [ 2 ] = ( rtP .
Constant_Value_nedwe54uwp [ 4 ] - rtP . Constant_Value_nedwe54uwp [ 0 ] ) *
pckqn2nbc0 [ 1 ] * pckqn2nbc0 [ 0 ] * ciha4r5bm0 ; pckqn2nbc0 [ 0 ] = rtP .
Constant1_Value_iuwa1a4rwo [ 1 ] * n23pvq3m54 [ 2 ] - rtP .
Constant1_Value_iuwa1a4rwo [ 2 ] * n23pvq3m54 [ 1 ] ; pckqn2nbc0 [ 1 ] = rtP
. Constant1_Value_iuwa1a4rwo [ 2 ] * n23pvq3m54 [ 0 ] - rtP .
Constant1_Value_iuwa1a4rwo [ 0 ] * n23pvq3m54 [ 2 ] ; pckqn2nbc0 [ 2 ] = rtP
. Constant1_Value_iuwa1a4rwo [ 0 ] * n23pvq3m54 [ 1 ] - rtP .
Constant1_Value_iuwa1a4rwo [ 1 ] * n23pvq3m54 [ 0 ] ; tmp [ 0 ] = - 0.0 ; tmp
[ 3 ] = rtB . kl0s5rlxlx [ 2 ] ; tmp [ 6 ] = - rtB . kl0s5rlxlx [ 1 ] ; tmp [
1 ] = - rtB . kl0s5rlxlx [ 2 ] ; tmp [ 4 ] = - 0.0 ; tmp [ 7 ] = rtB .
kl0s5rlxlx [ 0 ] ; tmp [ 2 ] = rtB . kl0s5rlxlx [ 1 ] ; tmp [ 5 ] = - rtB .
kl0s5rlxlx [ 0 ] ; tmp [ 8 ] = - 0.0 ; mgszinnhzv = rtP .
Constant1_Value_lapgl51prt * muDoubleScalarCos ( rtB . ela1rhmmmi ) + 1.0 ;
rtB . gnn2xcjhaq = muDoubleScalarSqrt ( 398600.0 / muDoubleScalarPower ( rtP
. Constant_Value_kb0zyegq3x , 3.0 ) ) * ( mgszinnhzv * mgszinnhzv ) /
muDoubleScalarPower ( 1.0 - rtP . Constant1_Value_lapgl51prt * rtP .
Constant1_Value_lapgl51prt , 1.5 ) ; for ( r1 = 0 ; r1 < 3 ; r1 ++ ) { rtB .
cw2k3svoeb [ r1 ] = ( MC1 [ r1 ] + pckqn2nbc0 [ r1 ] ) + rVers [ r1 ] ; rtB .
ey2mmw0csp [ r1 ] = rtB . cw2k3svoeb [ r1 ] + rtB . pldpuimngh [ r1 ] ; rVers
[ r1 ] = 0.0 ; for ( r2 = 0 ; r2 < 3 ; r2 ++ ) { rtB . e1l1mwc2wk [ r1 + 3 *
r2 ] = 0.0 ; rtB . e1l1mwc2wk [ r1 + 3 * r2 ] += rtB . p13uq5o22a [ 3 * r2 ]
* tmp [ r1 ] ; rtB . e1l1mwc2wk [ r1 + 3 * r2 ] += rtB . p13uq5o22a [ 3 * r2
+ 1 ] * tmp [ r1 + 3 ] ; rtB . e1l1mwc2wk [ r1 + 3 * r2 ] += rtB . p13uq5o22a
[ 3 * r2 + 2 ] * tmp [ r1 + 6 ] ; rVers [ r1 ] += rtP .
Constant_Value_noh4pr4dj2 [ 3 * r2 + r1 ] * rtB . kl0s5rlxlx [ r2 ] ; } }
n23pvq3m54 [ 0 ] = ( rVers [ 1 ] * rtB . kl0s5rlxlx [ 2 ] - rVers [ 2 ] * rtB
. kl0s5rlxlx [ 1 ] ) + rtB . ey2mmw0csp [ 0 ] ; n23pvq3m54 [ 1 ] = ( rVers [
2 ] * rtB . kl0s5rlxlx [ 0 ] - rVers [ 0 ] * rtB . kl0s5rlxlx [ 2 ] ) + rtB .
ey2mmw0csp [ 1 ] ; n23pvq3m54 [ 2 ] = ( rVers [ 0 ] * rtB . kl0s5rlxlx [ 1 ]
- rVers [ 1 ] * rtB . kl0s5rlxlx [ 0 ] ) + rtB . ey2mmw0csp [ 2 ] ; memcpy (
& pbgkcapnqv [ 0 ] , & rtP . Constant_Value_noh4pr4dj2 [ 0 ] , 9U * sizeof (
real_T ) ) ; r1 = 0 ; r2 = 1 ; r3 = 2 ; ciha4r5bm0 = muDoubleScalarAbs ( rtP
. Constant_Value_noh4pr4dj2 [ 0 ] ) ; mgszinnhzv = muDoubleScalarAbs ( rtP .
Constant_Value_noh4pr4dj2 [ 1 ] ) ; if ( mgszinnhzv > muDoubleScalarAbs ( rtP
. Constant_Value_noh4pr4dj2 [ 0 ] ) ) { ciha4r5bm0 = mgszinnhzv ; r1 = 1 ; r2
= 0 ; } if ( muDoubleScalarAbs ( rtP . Constant_Value_noh4pr4dj2 [ 2 ] ) >
ciha4r5bm0 ) { r1 = 2 ; r2 = 1 ; r3 = 0 ; } pbgkcapnqv [ r2 ] = rtP .
Constant_Value_noh4pr4dj2 [ r2 ] / rtP . Constant_Value_noh4pr4dj2 [ r1 ] ;
pbgkcapnqv [ r3 ] /= pbgkcapnqv [ r1 ] ; pbgkcapnqv [ r2 + 3 ] -= pbgkcapnqv
[ r1 + 3 ] * pbgkcapnqv [ r2 ] ; pbgkcapnqv [ r3 + 3 ] -= pbgkcapnqv [ r1 + 3
] * pbgkcapnqv [ r3 ] ; pbgkcapnqv [ r2 + 6 ] -= pbgkcapnqv [ r1 + 6 ] *
pbgkcapnqv [ r2 ] ; pbgkcapnqv [ r3 + 6 ] -= pbgkcapnqv [ r1 + 6 ] *
pbgkcapnqv [ r3 ] ; if ( muDoubleScalarAbs ( pbgkcapnqv [ r3 + 3 ] ) >
muDoubleScalarAbs ( pbgkcapnqv [ r2 + 3 ] ) ) { rtemp = r2 ; r2 = r3 ; r3 =
rtemp ; } pbgkcapnqv [ r3 + 3 ] /= pbgkcapnqv [ r2 + 3 ] ; pbgkcapnqv [ r3 +
6 ] -= pbgkcapnqv [ r3 + 3 ] * pbgkcapnqv [ r2 + 6 ] ; rtB . farw3endkt [ 1 ]
= n23pvq3m54 [ r2 ] - n23pvq3m54 [ r1 ] * pbgkcapnqv [ r2 ] ; rtB .
farw3endkt [ 2 ] = ( n23pvq3m54 [ r3 ] - n23pvq3m54 [ r1 ] * pbgkcapnqv [ r3
] ) - pbgkcapnqv [ r3 + 3 ] * rtB . farw3endkt [ 1 ] ; rtB . farw3endkt [ 2 ]
/= pbgkcapnqv [ r3 + 6 ] ; rtB . farw3endkt [ 0 ] = n23pvq3m54 [ r1 ] -
pbgkcapnqv [ r1 + 6 ] * rtB . farw3endkt [ 2 ] ; rtB . farw3endkt [ 1 ] -=
pbgkcapnqv [ r2 + 6 ] * rtB . farw3endkt [ 2 ] ; rtB . farw3endkt [ 1 ] /=
pbgkcapnqv [ r2 + 3 ] ; rtB . farw3endkt [ 0 ] -= pbgkcapnqv [ r1 + 3 ] * rtB
. farw3endkt [ 1 ] ; rtB . farw3endkt [ 0 ] /= pbgkcapnqv [ r1 ] ; rtB .
jd4glhy2th [ 0 ] = rtB . kl0s5rlxlx [ 0 ] - rtB . gcsyrgudhi [ 0 ] ; rtB .
jd4glhy2th [ 1 ] = rtB . kl0s5rlxlx [ 1 ] - rtB . gcsyrgudhi [ 1 ] ; rtB .
jd4glhy2th [ 2 ] = rtB . kl0s5rlxlx [ 2 ] - rtB . gcsyrgudhi [ 2 ] ; rtB .
bgsqzfr5vf [ 0 ] = rtB . kl0s5rlxlx [ 0 ] - rtB . pkc5yfmw2v [ 0 ] ; rtB .
bgsqzfr5vf [ 1 ] = rtB . kl0s5rlxlx [ 1 ] - rtB . pkc5yfmw2v [ 1 ] ; rtB .
bgsqzfr5vf [ 2 ] = rtB . kl0s5rlxlx [ 2 ] - rtB . pkc5yfmw2v [ 2 ] ; rtB .
ptpgqwsog2 [ 0 ] = mVers [ 0 ] + rtB . cw2k3svoeb [ 0 ] ; rtB . ptpgqwsog2 [
1 ] = mVers [ 1 ] + rtB . cw2k3svoeb [ 1 ] ; rtB . ptpgqwsog2 [ 2 ] = mVers [
2 ] + rtB . cw2k3svoeb [ 2 ] ; rtB . cncjtrvy1r = ssGetT ( rtS ) ; if (
ssIsSampleHit ( rtS , 2 , 0 ) ) { rtB . pxjxltf32i [ 0 ] = rtDW . mdfoxg3mo4
[ 0 ] ; rtB . pxjxltf32i [ 1 ] = rtDW . mdfoxg3mo4 [ 1 ] ; rtB . pxjxltf32i [
2 ] = rtDW . mdfoxg3mo4 [ 2 ] ; } if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { if (
ssIsMajorTimeStep ( rtS ) ) { rtDW . bhvnvcv2we = ( rtB . cncjtrvy1r > rtP .
Constant_Value_jedkd3oz4q ) ; } isxv4gzr5t = rtDW . bhvnvcv2we ; rtB .
bx5l1cxe42 [ 0 ] = rtB . pxjxltf32i [ 0 ] * ( real_T ) isxv4gzr5t ; rtB .
bx5l1cxe42 [ 1 ] = rtB . pxjxltf32i [ 1 ] * ( real_T ) isxv4gzr5t ; rtB .
bx5l1cxe42 [ 2 ] = rtB . pxjxltf32i [ 2 ] * ( real_T ) isxv4gzr5t ; } for (
r2 = 0 ; r2 < 3 ; r2 ++ ) { rVers [ r2 ] = rtP . Constant_Value_m3i1kxbif4 [
r2 + 6 ] * rtB . pkc5yfmw2v [ 2 ] + ( rtP . Constant_Value_m3i1kxbif4 [ r2 +
3 ] * rtB . pkc5yfmw2v [ 1 ] + rtP . Constant_Value_m3i1kxbif4 [ r2 ] * rtB .
pkc5yfmw2v [ 0 ] ) ; } mVers [ 0 ] = rVers [ 1 ] * rtB . pkc5yfmw2v [ 2 ] -
rVers [ 2 ] * rtB . pkc5yfmw2v [ 1 ] ; mVers [ 1 ] = rVers [ 2 ] * rtB .
pkc5yfmw2v [ 0 ] - rVers [ 0 ] * rtB . pkc5yfmw2v [ 2 ] ; mVers [ 2 ] = rVers
[ 0 ] * rtB . pkc5yfmw2v [ 1 ] - rVers [ 1 ] * rtB . pkc5yfmw2v [ 0 ] ;
hyrpevmtnt ( rtP . Constant_Value_m3i1kxbif4 , mVers , pckqn2nbc0 ) ;
hyrpevmtnt ( rtP . Constant_Value_m3i1kxbif4 , rtB . ptpgqwsog2 , mVers ) ;
rtB . fiyrbaaxb5 [ 0 ] = ( ( pckqn2nbc0 [ 0 ] + mVers [ 0 ] ) - ( rtB .
pkc5yfmw2v [ 0 ] - rtB . gcsyrgudhi [ 0 ] ) * rtP .
Constant2_Value_jgk4nzciuj ) * ( real_T ) rtB . b13up4rwa2 ; rtB . fiyrbaaxb5
[ 1 ] = ( ( pckqn2nbc0 [ 1 ] + mVers [ 1 ] ) - ( rtB . pkc5yfmw2v [ 1 ] - rtB
. gcsyrgudhi [ 1 ] ) * rtP . Constant2_Value_jgk4nzciuj ) * ( real_T ) rtB .
b13up4rwa2 ; rtB . fiyrbaaxb5 [ 2 ] = ( ( pckqn2nbc0 [ 2 ] + mVers [ 2 ] ) -
( rtB . pkc5yfmw2v [ 2 ] - rtB . gcsyrgudhi [ 2 ] ) * rtP .
Constant2_Value_jgk4nzciuj ) * ( real_T ) rtB . b13up4rwa2 ; UNUSED_PARAMETER
( tid ) ; } void MdlOutputsTID4 ( int_T tid ) { UNUSED_PARAMETER ( tid ) ; }
void MdlUpdate ( int_T tid ) { if ( ssIsSampleHit ( rtS , 3 , 0 ) ) { rtDW .
a5tv4scxvv [ 0 ] = rt_nrand_Upu32_Yd_f_pw_snf ( & rtDW . p3k2zi5joj [ 0 ] ) *
rtP . RandomNumber1_StdDev [ 0 ] + rtP . RandomNumber1_Mean ; rtDW .
a5tv4scxvv [ 1 ] = rt_nrand_Upu32_Yd_f_pw_snf ( & rtDW . p3k2zi5joj [ 1 ] ) *
rtP . RandomNumber1_StdDev [ 1 ] + rtP . RandomNumber1_Mean ; rtDW .
a5tv4scxvv [ 2 ] = rt_nrand_Upu32_Yd_f_pw_snf ( & rtDW . p3k2zi5joj [ 2 ] ) *
rtP . RandomNumber1_StdDev [ 2 ] + rtP . RandomNumber1_Mean ; } { real_T * *
uBuffer = ( real_T * * ) & rtDW . ja1mjqygva . TUbufferPtrs [ 0 ] ; real_T *
* tBuffer = ( real_T * * ) & rtDW . ja1mjqygva . TUbufferPtrs [ 3 ] ; real_T
simTime = ssGetT ( rtS ) ; rtDW . hxmmr0vle1 . Head [ 0 ] = ( ( rtDW .
hxmmr0vle1 . Head [ 0 ] < ( rtDW . hxmmr0vle1 . CircularBufSize [ 0 ] - 1 ) )
? ( rtDW . hxmmr0vle1 . Head [ 0 ] + 1 ) : 0 ) ; if ( rtDW . hxmmr0vle1 .
Head [ 0 ] == rtDW . hxmmr0vle1 . Tail [ 0 ] ) { if ( !
rt_TDelayUpdateTailOrGrowBuf ( & rtDW . hxmmr0vle1 . CircularBufSize [ 0 ] ,
& rtDW . hxmmr0vle1 . Tail [ 0 ] , & rtDW . hxmmr0vle1 . Head [ 0 ] , & rtDW
. hxmmr0vle1 . Last [ 0 ] , simTime - rtP . TransportDelay_Delay , tBuffer ,
uBuffer , ( NULL ) , ( boolean_T ) 0 , false , & rtDW . hxmmr0vle1 .
MaxNewBufSize ) ) { ssSetErrorStatus ( rtS , "tdelay memory allocation error"
) ; return ; } } ( * tBuffer ++ ) [ rtDW . hxmmr0vle1 . Head [ 0 ] ] =
simTime ; ( * uBuffer ++ ) [ rtDW . hxmmr0vle1 . Head [ 0 ] ] = rtB .
nrhgec3vav [ 0 ] ; rtDW . hxmmr0vle1 . Head [ 1 ] = ( ( rtDW . hxmmr0vle1 .
Head [ 1 ] < ( rtDW . hxmmr0vle1 . CircularBufSize [ 1 ] - 1 ) ) ? ( rtDW .
hxmmr0vle1 . Head [ 1 ] + 1 ) : 0 ) ; if ( rtDW . hxmmr0vle1 . Head [ 1 ] ==
rtDW . hxmmr0vle1 . Tail [ 1 ] ) { if ( ! rt_TDelayUpdateTailOrGrowBuf ( &
rtDW . hxmmr0vle1 . CircularBufSize [ 1 ] , & rtDW . hxmmr0vle1 . Tail [ 1 ]
, & rtDW . hxmmr0vle1 . Head [ 1 ] , & rtDW . hxmmr0vle1 . Last [ 1 ] ,
simTime - rtP . TransportDelay_Delay , tBuffer , uBuffer , ( NULL ) , (
boolean_T ) 0 , false , & rtDW . hxmmr0vle1 . MaxNewBufSize ) ) {
ssSetErrorStatus ( rtS , "tdelay memory allocation error" ) ; return ; } } (
* tBuffer ++ ) [ rtDW . hxmmr0vle1 . Head [ 1 ] ] = simTime ; ( * uBuffer ++
) [ rtDW . hxmmr0vle1 . Head [ 1 ] ] = rtB . nrhgec3vav [ 1 ] ; rtDW .
hxmmr0vle1 . Head [ 2 ] = ( ( rtDW . hxmmr0vle1 . Head [ 2 ] < ( rtDW .
hxmmr0vle1 . CircularBufSize [ 2 ] - 1 ) ) ? ( rtDW . hxmmr0vle1 . Head [ 2 ]
+ 1 ) : 0 ) ; if ( rtDW . hxmmr0vle1 . Head [ 2 ] == rtDW . hxmmr0vle1 . Tail
[ 2 ] ) { if ( ! rt_TDelayUpdateTailOrGrowBuf ( & rtDW . hxmmr0vle1 .
CircularBufSize [ 2 ] , & rtDW . hxmmr0vle1 . Tail [ 2 ] , & rtDW .
hxmmr0vle1 . Head [ 2 ] , & rtDW . hxmmr0vle1 . Last [ 2 ] , simTime - rtP .
TransportDelay_Delay , tBuffer , uBuffer , ( NULL ) , ( boolean_T ) 0 , false
, & rtDW . hxmmr0vle1 . MaxNewBufSize ) ) { ssSetErrorStatus ( rtS ,
"tdelay memory allocation error" ) ; return ; } } ( * tBuffer ) [ rtDW .
hxmmr0vle1 . Head [ 2 ] ] = simTime ; ( * uBuffer ) [ rtDW . hxmmr0vle1 .
Head [ 2 ] ] = rtB . nrhgec3vav [ 2 ] ; } if ( ssIsSampleHit ( rtS , 2 , 0 )
) { rtDW . donz0qvylr [ 0 ] = rt_nrand_Upu32_Yd_f_pw_snf ( & rtDW .
apy12dao0a [ 0 ] ) * rtP . RandomNumber_StdDev [ 0 ] + rtP .
RandomNumber_Mean ; rtDW . donz0qvylr [ 1 ] = rt_nrand_Upu32_Yd_f_pw_snf ( &
rtDW . apy12dao0a [ 1 ] ) * rtP . RandomNumber_StdDev [ 1 ] + rtP .
RandomNumber_Mean ; rtDW . donz0qvylr [ 2 ] = rt_nrand_Upu32_Yd_f_pw_snf ( &
rtDW . apy12dao0a [ 2 ] ) * rtP . RandomNumber_StdDev [ 2 ] + rtP .
RandomNumber_Mean ; rtDW . mdfoxg3mo4 [ 0 ] = rt_nrand_Upu32_Yd_f_pw_snf ( &
rtDW . lfp1taz3l3 [ 0 ] ) * rtP . RandomNumber1_StdDev_cudqkp3bpx [ 0 ] + rtP
. RandomNumber1_Mean_pp0amcle2e ; rtDW . mdfoxg3mo4 [ 1 ] =
rt_nrand_Upu32_Yd_f_pw_snf ( & rtDW . lfp1taz3l3 [ 1 ] ) * rtP .
RandomNumber1_StdDev_cudqkp3bpx [ 1 ] + rtP . RandomNumber1_Mean_pp0amcle2e ;
rtDW . mdfoxg3mo4 [ 2 ] = rt_nrand_Upu32_Yd_f_pw_snf ( & rtDW . lfp1taz3l3 [
2 ] ) * rtP . RandomNumber1_StdDev_cudqkp3bpx [ 2 ] + rtP .
RandomNumber1_Mean_pp0amcle2e ; } rtDW . m3xid4gzul = 0 ; UNUSED_PARAMETER (
tid ) ; } void MdlUpdateTID4 ( int_T tid ) { UNUSED_PARAMETER ( tid ) ; }
void MdlDerivatives ( void ) { XDot * _rtXdot ; _rtXdot = ( ( XDot * )
ssGetdX ( rtS ) ) ; _rtXdot -> mdmb5a1yml = rtB . gnn2xcjhaq ; memcpy ( &
_rtXdot -> l3lup5gvqh [ 0 ] , & rtB . e1l1mwc2wk [ 0 ] , 9U * sizeof ( real_T
) ) ; _rtXdot -> k5ybcxiwei [ 0 ] = rtB . farw3endkt [ 0 ] ; _rtXdot ->
cmqklstge4 [ 0 ] = rtB . bx5l1cxe42 [ 0 ] ; _rtXdot -> kn4trkmxb3 [ 0 ] = rtB
. fiyrbaaxb5 [ 0 ] ; _rtXdot -> k5ybcxiwei [ 1 ] = rtB . farw3endkt [ 1 ] ;
_rtXdot -> cmqklstge4 [ 1 ] = rtB . bx5l1cxe42 [ 1 ] ; _rtXdot -> kn4trkmxb3
[ 1 ] = rtB . fiyrbaaxb5 [ 1 ] ; _rtXdot -> k5ybcxiwei [ 2 ] = rtB .
farw3endkt [ 2 ] ; _rtXdot -> cmqklstge4 [ 2 ] = rtB . bx5l1cxe42 [ 2 ] ;
_rtXdot -> kn4trkmxb3 [ 2 ] = rtB . fiyrbaaxb5 [ 2 ] ; _rtXdot -> kumxbfxbuz
= rtB . e4c42ch1lv ; } void MdlProjection ( void ) { } void MdlZeroCrossings
( void ) { ZCV * _rtZCSV ; _rtZCSV = ( ( ZCV * ) ssGetSolverZcSignalVector (
rtS ) ) ; _rtZCSV -> eke5pk2rn0 = rtB . l1nazchf2g - rtP .
Constant1_Value_cw3pti1zff ; _rtZCSV -> pfbcqp3wuq = rtB . cncjtrvy1r - rtP .
Constant_Value_jedkd3oz4q ; } void MdlTerminate ( void ) { { int_T i1 ; void
* * pw_TUbufferPtrs = & rtDW . ja1mjqygva . TUbufferPtrs [ 0 ] ; for ( i1 = 0
; i1 < 3 ; i1 ++ ) { rt_TDelayFreeBuf ( pw_TUbufferPtrs [ i1 ] ) ; } } } void
MdlInitializeSizes ( void ) { ssSetNumContStates ( rtS , 20 ) ;
ssSetNumPeriodicContStates ( rtS , 0 ) ; ssSetNumY ( rtS , 0 ) ; ssSetNumU (
rtS , 0 ) ; ssSetDirectFeedThrough ( rtS , 0 ) ; ssSetNumSampleTimes ( rtS ,
4 ) ; ssSetNumBlocks ( rtS , 91 ) ; ssSetNumBlockIO ( rtS , 32 ) ;
ssSetNumBlockParams ( rtS , 219 ) ; } void MdlInitializeSampleTimes ( void )
{ ssSetSampleTime ( rtS , 0 , 0.0 ) ; ssSetSampleTime ( rtS , 1 , 0.0 ) ;
ssSetSampleTime ( rtS , 2 , 0.01 ) ; ssSetSampleTime ( rtS , 3 , 0.1 ) ;
ssSetOffsetTime ( rtS , 0 , 0.0 ) ; ssSetOffsetTime ( rtS , 1 , 1.0 ) ;
ssSetOffsetTime ( rtS , 2 , 0.0 ) ; ssSetOffsetTime ( rtS , 3 , 0.0 ) ; }
void raccel_set_checksum ( ) { ssSetChecksumVal ( rtS , 0 , 2063736516U ) ;
ssSetChecksumVal ( rtS , 1 , 611031575U ) ; ssSetChecksumVal ( rtS , 2 ,
3190133955U ) ; ssSetChecksumVal ( rtS , 3 , 305185540U ) ; }
#if defined(_MSC_VER)
#pragma optimize( "", off )
#endif
SimStruct * raccel_register_model ( ssExecutionInfo * executionInfo ) {
static struct _ssMdlInfo mdlInfo ; ( void ) memset ( ( char * ) rtS , 0 ,
sizeof ( SimStruct ) ) ; ( void ) memset ( ( char * ) & mdlInfo , 0 , sizeof
( struct _ssMdlInfo ) ) ; ssSetMdlInfoPtr ( rtS , & mdlInfo ) ;
ssSetExecutionInfo ( rtS , executionInfo ) ; { static time_T mdlPeriod [
NSAMPLE_TIMES ] ; static time_T mdlOffset [ NSAMPLE_TIMES ] ; static time_T
mdlTaskTimes [ NSAMPLE_TIMES ] ; static int_T mdlTsMap [ NSAMPLE_TIMES ] ;
static int_T mdlSampleHits [ NSAMPLE_TIMES ] ; static boolean_T
mdlTNextWasAdjustedPtr [ NSAMPLE_TIMES ] ; static int_T mdlPerTaskSampleHits
[ NSAMPLE_TIMES * NSAMPLE_TIMES ] ; static time_T mdlTimeOfNextSampleHit [
NSAMPLE_TIMES ] ; { int_T i ; for ( i = 0 ; i < NSAMPLE_TIMES ; i ++ ) {
mdlPeriod [ i ] = 0.0 ; mdlOffset [ i ] = 0.0 ; mdlTaskTimes [ i ] = 0.0 ;
mdlTsMap [ i ] = i ; mdlSampleHits [ i ] = 1 ; } } ssSetSampleTimePtr ( rtS ,
& mdlPeriod [ 0 ] ) ; ssSetOffsetTimePtr ( rtS , & mdlOffset [ 0 ] ) ;
ssSetSampleTimeTaskIDPtr ( rtS , & mdlTsMap [ 0 ] ) ; ssSetTPtr ( rtS , &
mdlTaskTimes [ 0 ] ) ; ssSetSampleHitPtr ( rtS , & mdlSampleHits [ 0 ] ) ;
ssSetTNextWasAdjustedPtr ( rtS , & mdlTNextWasAdjustedPtr [ 0 ] ) ;
ssSetPerTaskSampleHitsPtr ( rtS , & mdlPerTaskSampleHits [ 0 ] ) ;
ssSetTimeOfNextSampleHitPtr ( rtS , & mdlTimeOfNextSampleHit [ 0 ] ) ; }
ssSetSolverMode ( rtS , SOLVER_MODE_SINGLETASKING ) ; { ssSetBlockIO ( rtS ,
( ( void * ) & rtB ) ) ; ssSetWorkSizeInBytes ( rtS , sizeof ( rtB ) ,
"BlockIO" ) ; ( void ) memset ( ( ( void * ) & rtB ) , 0 , sizeof ( B ) ) ; }
{ real_T * x = ( real_T * ) & rtX ; ssSetContStates ( rtS , x ) ; ( void )
memset ( ( void * ) x , 0 , sizeof ( X ) ) ; } { void * dwork = ( void * ) &
rtDW ; ssSetRootDWork ( rtS , dwork ) ; ssSetWorkSizeInBytes ( rtS , sizeof (
rtDW ) , "DWork" ) ; ( void ) memset ( dwork , 0 , sizeof ( DW ) ) ; } {
static DataTypeTransInfo dtInfo ; ( void ) memset ( ( char_T * ) & dtInfo , 0
, sizeof ( dtInfo ) ) ; ssSetModelMappingInfo ( rtS , & dtInfo ) ; dtInfo .
numDataTypes = 30 ; dtInfo . dataTypeSizes = & rtDataTypeSizes [ 0 ] ; dtInfo
. dataTypeNames = & rtDataTypeNames [ 0 ] ; dtInfo . BTransTable = &
rtBTransTable ; dtInfo . PTransTable = & rtPTransTable ; dtInfo .
dataTypeInfoTable = rtDataTypeInfoTable ; } detumbling_InitializeDataMapInfo
( ) ; ssSetIsRapidAcceleratorActive ( rtS , true ) ; ssSetRootSS ( rtS , rtS
) ; ssSetVersion ( rtS , SIMSTRUCT_VERSION_LEVEL2 ) ; ssSetModelName ( rtS ,
"detumbling" ) ; ssSetPath ( rtS , "detumbling" ) ; ssSetTStart ( rtS , 0.0 )
; ssSetTFinal ( rtS , 21000.0 ) ; { static RTWLogInfo rt_DataLoggingInfo ;
rt_DataLoggingInfo . loggingInterval = NULL ; ssSetRTWLogInfo ( rtS , &
rt_DataLoggingInfo ) ; } { { static int_T rt_LoggedStateWidths [ ] = { 1 , 9
, 3 , 3 , 3 , 1 } ; static int_T rt_LoggedStateNumDimensions [ ] = { 1 , 1 ,
1 , 1 , 1 , 1 } ; static int_T rt_LoggedStateDimensions [ ] = { 1 , 9 , 3 , 3
, 3 , 1 } ; static boolean_T rt_LoggedStateIsVarDims [ ] = { 0 , 0 , 0 , 0 ,
0 , 0 } ; static BuiltInDTypeId rt_LoggedStateDataTypeIds [ ] = { SS_DOUBLE ,
SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE } ; static int_T
rt_LoggedStateComplexSignals [ ] = { 0 , 0 , 0 , 0 , 0 , 0 } ; static
RTWPreprocessingFcnPtr rt_LoggingStatePreprocessingFcnPtrs [ ] = { ( NULL ) ,
( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) } ; static const char_T
* rt_LoggedStateLabels [ ] = { "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" ,
"CSTATE" , "CSTATE" } ; static const char_T * rt_LoggedStateBlockNames [ ] =
{ "detumbling/Environment/Unperturbed Orbit/Integrator" ,
"detumbling/Direct Cosine Matrix/Integrator" ,
"detumbling/Euler Equations/Integrator" ,
"detumbling/Sensors/Gyroscope/Integrator" ,
"detumbling/Sensors/Observer/Integrator" ,
"detumbling/Control and Actuators/Integrator" } ; static const char_T *
rt_LoggedStateNames [ ] = { "" , "" , "" , "" , "" , "" } ; static boolean_T
rt_LoggedStateCrossMdlRef [ ] = { 0 , 0 , 0 , 0 , 0 , 0 } ; static
RTWLogDataTypeConvert rt_RTWLogDataTypeConvert [ ] = { { 0 , SS_DOUBLE ,
SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0
, 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 ,
0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 ,
SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE ,
SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } } ; static RTWLogSignalInfo
rt_LoggedStateSignalInfo = { 6 , rt_LoggedStateWidths ,
rt_LoggedStateNumDimensions , rt_LoggedStateDimensions ,
rt_LoggedStateIsVarDims , ( NULL ) , ( NULL ) , rt_LoggedStateDataTypeIds ,
rt_LoggedStateComplexSignals , ( NULL ) , rt_LoggingStatePreprocessingFcnPtrs
, { rt_LoggedStateLabels } , ( NULL ) , ( NULL ) , ( NULL ) , {
rt_LoggedStateBlockNames } , { rt_LoggedStateNames } ,
rt_LoggedStateCrossMdlRef , rt_RTWLogDataTypeConvert } ; static void *
rt_LoggedStateSignalPtrs [ 6 ] ; rtliSetLogXSignalPtrs ( ssGetRTWLogInfo (
rtS ) , ( LogSignalPtrsType ) rt_LoggedStateSignalPtrs ) ;
rtliSetLogXSignalInfo ( ssGetRTWLogInfo ( rtS ) , & rt_LoggedStateSignalInfo
) ; rt_LoggedStateSignalPtrs [ 0 ] = ( void * ) & rtX . mdmb5a1yml ;
rt_LoggedStateSignalPtrs [ 1 ] = ( void * ) & rtX . l3lup5gvqh [ 0 ] ;
rt_LoggedStateSignalPtrs [ 2 ] = ( void * ) & rtX . k5ybcxiwei [ 0 ] ;
rt_LoggedStateSignalPtrs [ 3 ] = ( void * ) & rtX . cmqklstge4 [ 0 ] ;
rt_LoggedStateSignalPtrs [ 4 ] = ( void * ) & rtX . kn4trkmxb3 [ 0 ] ;
rt_LoggedStateSignalPtrs [ 5 ] = ( void * ) & rtX . kumxbfxbuz ; }
rtliSetLogT ( ssGetRTWLogInfo ( rtS ) , "tout" ) ; rtliSetLogX (
ssGetRTWLogInfo ( rtS ) , "" ) ; rtliSetLogXFinal ( ssGetRTWLogInfo ( rtS ) ,
"" ) ; rtliSetLogVarNameModifier ( ssGetRTWLogInfo ( rtS ) , "none" ) ;
rtliSetLogFormat ( ssGetRTWLogInfo ( rtS ) , 4 ) ; rtliSetLogMaxRows (
ssGetRTWLogInfo ( rtS ) , 0 ) ; rtliSetLogDecimation ( ssGetRTWLogInfo ( rtS
) , 1 ) ; rtliSetLogY ( ssGetRTWLogInfo ( rtS ) , "" ) ;
rtliSetLogYSignalInfo ( ssGetRTWLogInfo ( rtS ) , ( NULL ) ) ;
rtliSetLogYSignalPtrs ( ssGetRTWLogInfo ( rtS ) , ( NULL ) ) ; } { static
struct _ssStatesInfo2 statesInfo2 ; ssSetStatesInfo2 ( rtS , & statesInfo2 )
; } { static ssPeriodicStatesInfo periodicStatesInfo ;
ssSetPeriodicStatesInfo ( rtS , & periodicStatesInfo ) ; } { static
ssJacobianPerturbationBounds jacobianPerturbationBounds ;
ssSetJacobianPerturbationBounds ( rtS , & jacobianPerturbationBounds ) ; } {
static ssSolverInfo slvrInfo ; static boolean_T contStatesDisabled [ 20 ] ;
static real_T absTol [ 20 ] = { 1.0E-8 , 1.0E-8 , 1.0E-8 , 1.0E-8 , 1.0E-8 ,
1.0E-8 , 1.0E-8 , 1.0E-8 , 1.0E-8 , 1.0E-8 , 1.0E-8 , 1.0E-8 , 1.0E-8 ,
1.0E-8 , 1.0E-8 , 1.0E-8 , 1.0E-8 , 1.0E-8 , 1.0E-8 , 1.0E-8 } ; static
uint8_T absTolControl [ 20 ] = { 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U ,
0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U } ; static real_T
contStateJacPerturbBoundMinVec [ 20 ] ; static real_T
contStateJacPerturbBoundMaxVec [ 20 ] ; static uint8_T zcAttributes [ 3 ] = {
( ZC_EVENT_ALL ) , ( 0xc0 | ZC_EVENT_ALL_UP ) , ( ZC_EVENT_ALL ) } ; static
ssNonContDerivSigInfo nonContDerivSigInfo [ 4 ] = { { 3 * sizeof ( real_T ) ,
( char * ) ( & rtB . bx5l1cxe42 [ 0 ] ) , ( NULL ) } , { 3 * sizeof ( real_T
) , ( char * ) ( & rtB . gcsyrgudhi [ 0 ] ) , ( NULL ) } , { 1 * sizeof (
boolean_T ) , ( char * ) ( & rtB . b13up4rwa2 ) , ( NULL ) } , { 3 * sizeof (
real_T ) , ( char * ) ( & rtB . nrhgec3vav [ 0 ] ) , ( NULL ) } } ; { int i ;
for ( i = 0 ; i < 20 ; ++ i ) { contStateJacPerturbBoundMinVec [ i ] = 0 ;
contStateJacPerturbBoundMaxVec [ i ] = rtGetInf ( ) ; } } ssSetSolverRelTol (
rtS , 1.0E-8 ) ; ssSetStepSize ( rtS , 0.0 ) ; ssSetMinStepSize ( rtS , 0.0 )
; ssSetMaxNumMinSteps ( rtS , - 1 ) ; ssSetMinStepViolatedError ( rtS , 0 ) ;
ssSetMaxStepSize ( rtS , 0.01 ) ; ssSetSolverMaxOrder ( rtS , 5 ) ;
ssSetSolverRefineFactor ( rtS , 1 ) ; ssSetOutputTimes ( rtS , ( NULL ) ) ;
ssSetNumOutputTimes ( rtS , 0 ) ; ssSetOutputTimesOnly ( rtS , 0 ) ;
ssSetOutputTimesIndex ( rtS , 0 ) ; ssSetZCCacheNeedsReset ( rtS , 0 ) ;
ssSetDerivCacheNeedsReset ( rtS , 0 ) ; ssSetNumNonContDerivSigInfos ( rtS ,
4 ) ; ssSetNonContDerivSigInfos ( rtS , nonContDerivSigInfo ) ;
ssSetSolverInfo ( rtS , & slvrInfo ) ; ssSetSolverName ( rtS , "ode15s" ) ;
ssSetVariableStepSolver ( rtS , 1 ) ; ssSetSolverConsistencyChecking ( rtS ,
0 ) ; ssSetSolverAdaptiveZcDetection ( rtS , 0 ) ;
ssSetSolverRobustResetMethod ( rtS , 0 ) ; ssSetAbsTolVector ( rtS , absTol )
; ssSetAbsTolControlVector ( rtS , absTolControl ) ;
ssSetSolverAbsTol_Obsolete ( rtS , absTol ) ;
ssSetSolverAbsTolControl_Obsolete ( rtS , absTolControl ) ;
ssSetJacobianPerturbationBoundsMinVec ( rtS , contStateJacPerturbBoundMinVec
) ; ssSetJacobianPerturbationBoundsMaxVec ( rtS ,
contStateJacPerturbBoundMaxVec ) ; ssSetSolverStateProjection ( rtS , 0 ) ;
ssSetSolverMassMatrixType ( rtS , ( ssMatrixType ) 0 ) ;
ssSetSolverMassMatrixNzMax ( rtS , 0 ) ; ssSetModelOutputs ( rtS , MdlOutputs
) ; ssSetModelLogData ( rtS , rt_UpdateTXYLogVars ) ;
ssSetModelLogDataIfInInterval ( rtS , rt_UpdateTXXFYLogVars ) ;
ssSetModelUpdate ( rtS , MdlUpdate ) ; ssSetModelDerivatives ( rtS ,
MdlDerivatives ) ; ssSetSolverZcSignalAttrib ( rtS , zcAttributes ) ;
ssSetSolverNumZcSignals ( rtS , 3 ) ; ssSetModelZeroCrossings ( rtS ,
MdlZeroCrossings ) ; ssSetSolverConsecutiveZCsStepRelTol ( rtS ,
2.8421709430404007E-13 ) ; ssSetSolverMaxConsecutiveZCs ( rtS , 1000 ) ;
ssSetSolverConsecutiveZCsError ( rtS , 2 ) ; ssSetSolverMaskedZcDiagnostic (
rtS , 1 ) ; ssSetSolverIgnoredZcDiagnostic ( rtS , 1 ) ;
ssSetSolverMaxConsecutiveMinStep ( rtS , 1 ) ;
ssSetSolverShapePreserveControl ( rtS , 2 ) ; ssSetTNextTid ( rtS , INT_MIN )
; ssSetTNext ( rtS , rtMinusInf ) ; ssSetSolverNeedsReset ( rtS ) ;
ssSetNumNonsampledZCs ( rtS , 2 ) ; ssSetContStateDisabled ( rtS ,
contStatesDisabled ) ; ssSetSolverMaxConsecutiveMinStep ( rtS , 1 ) ; } {
ZCSigState * zc = ( ZCSigState * ) & rtPrevZCX ; ssSetPrevZCSigState ( rtS ,
zc ) ; ssSetWorkSizeInBytes ( rtS , sizeof ( rtPrevZCX ) , "PrevZCSigState" )
; } { rtPrevZCX . gqlxm0wffx = UNINITIALIZED_ZCSIG ; } ssSetChecksumVal ( rtS
, 0 , 2063736516U ) ; ssSetChecksumVal ( rtS , 1 , 611031575U ) ;
ssSetChecksumVal ( rtS , 2 , 3190133955U ) ; ssSetChecksumVal ( rtS , 3 ,
305185540U ) ; { static const sysRanDType rtAlwaysEnabled =
SUBSYS_RAN_BC_ENABLE ; static RTWExtModeInfo rt_ExtModeInfo ; static const
sysRanDType * systemRan [ 16 ] ; gblRTWExtModeInfo = & rt_ExtModeInfo ;
ssSetRTWExtModeInfo ( rtS , & rt_ExtModeInfo ) ;
rteiSetSubSystemActiveVectorAddresses ( & rt_ExtModeInfo , systemRan ) ;
systemRan [ 0 ] = & rtAlwaysEnabled ; systemRan [ 1 ] = & rtAlwaysEnabled ;
systemRan [ 2 ] = & rtAlwaysEnabled ; systemRan [ 3 ] = & rtAlwaysEnabled ;
systemRan [ 4 ] = & rtAlwaysEnabled ; systemRan [ 5 ] = & rtAlwaysEnabled ;
systemRan [ 6 ] = & rtAlwaysEnabled ; systemRan [ 7 ] = & rtAlwaysEnabled ;
systemRan [ 8 ] = & rtAlwaysEnabled ; systemRan [ 9 ] = & rtAlwaysEnabled ;
systemRan [ 10 ] = & rtAlwaysEnabled ; systemRan [ 11 ] = & rtAlwaysEnabled ;
systemRan [ 12 ] = & rtAlwaysEnabled ; systemRan [ 13 ] = & rtAlwaysEnabled ;
systemRan [ 14 ] = & rtAlwaysEnabled ; systemRan [ 15 ] = & rtAlwaysEnabled ;
rteiSetModelMappingInfoPtr ( ssGetRTWExtModeInfo ( rtS ) , &
ssGetModelMappingInfo ( rtS ) ) ; rteiSetChecksumsPtr ( ssGetRTWExtModeInfo (
rtS ) , ssGetChecksums ( rtS ) ) ; rteiSetTPtr ( ssGetRTWExtModeInfo ( rtS )
, ssGetTPtr ( rtS ) ) ; } return rtS ; }
#if defined(_MSC_VER)
#pragma optimize( "", on )
#endif
const int_T gblParameterTuningTid = 4 ; void MdlOutputsParameterSampleTime (
int_T tid ) { MdlOutputsTID4 ( tid ) ; }
