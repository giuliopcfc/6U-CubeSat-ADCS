#include "rt_logging_mmi.h"
#include "pointing_capi.h"
#include <math.h>
#include "pointing.h"
#include "pointing_private.h"
#include "pointing_dt.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "slsa_sim_engine.h"
extern void * CreateDiagnosticAsVoidPtr_wrapper ( const char * id , int nargs
, ... ) ; RTWExtModeInfo * gblRTWExtModeInfo = NULL ; void
raccelForceExtModeShutdown ( boolean_T extModeStartPktReceived ) { if ( !
extModeStartPktReceived ) { boolean_T stopRequested = false ;
rtExtModeWaitForStartPkt ( gblRTWExtModeInfo , 2 , & stopRequested ) ; }
rtExtModeShutdown ( 2 ) ; }
#include "slsv_diagnostic_codegen_c_api.h"
const int_T gblNumToFiles = 0 ; const int_T gblNumFrFiles = 0 ; const int_T
gblNumFrWksBlocks = 0 ;
#ifdef RSIM_WITH_SOLVER_MULTITASKING
boolean_T gbl_raccel_isMultitasking = 1 ;
#else
boolean_T gbl_raccel_isMultitasking = 0 ;
#endif
boolean_T gbl_raccel_tid01eq = 0 ; int_T gbl_raccel_NumST = 3 ; const char_T
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
] = { 1 , 1 , 1 } ; const char * raccelLoadInputsAndAperiodicHitTimes (
SimStruct * S , const char * inportFileName , int * matFileFormat ) { return
rt_RAccelReadInportsMatFile ( S , inportFileName , matFileFormat ) ; } B rtB
; X rtX ; DW rtDW ; PrevZCX rtPrevZCX ; static SimStruct model_S ; SimStruct
* const rtS = & model_S ; static real_T ldsrcb4o0t ( const real_T x [ 3 ] ) ;
static real_T pke5l1lpzc ( const real_T x [ 3 ] ) ; static real_T lkdukp33cm
( int32_T n , const real_T x [ 9 ] , int32_T ix0 ) ; static void lzwbonwaxs (
int32_T n , real_T a , real_T x [ 9 ] , int32_T ix0 ) ; static real_T
lkdukp33cmh ( const real_T x [ 3 ] , int32_T ix0 ) ; static void lzwbonwaxsl
( real_T a , real_T x [ 3 ] , int32_T ix0 ) ; static void iar1b2uyw3no (
int32_T n , real_T a , const real_T x [ 3 ] , int32_T ix0 , real_T y [ 9 ] ,
int32_T iy0 ) ; static void iar1b2uyw3n ( int32_T n , real_T a , const real_T
x [ 9 ] , int32_T ix0 , real_T y [ 3 ] , int32_T iy0 ) ; static real_T
cip4gtzcun ( int32_T n , const real_T x [ 9 ] , int32_T ix0 , const real_T y
[ 9 ] , int32_T iy0 ) ; static void iar1b2uyw3 ( int32_T n , real_T a ,
int32_T ix0 , real_T y [ 9 ] , int32_T iy0 ) ; static void lzwbonwaxslr (
real_T a , real_T x [ 9 ] , int32_T ix0 ) ; static void ox0rgyqacd ( real_T x
[ 9 ] , int32_T ix0 , int32_T iy0 ) ; static void kw0pupmsbg ( real_T * a ,
real_T * b , real_T * c , real_T * s ) ; static void godcwr1fhb ( real_T x [
9 ] , int32_T ix0 , int32_T iy0 , real_T c , real_T s ) ; static void
o4vts0g5zg ( const real_T A [ 9 ] , real_T U [ 9 ] , real_T s [ 3 ] , real_T
V [ 9 ] ) ; static real_T kdmv5ezpwv ( const real_T x [ 9 ] ) ; static void
brfsyu5ndt ( const real_T A [ 9 ] , const real_T B_p [ 3 ] , real_T Y [ 3 ] )
; void p54msx4qks ( const real_T fmbos3wpbf [ 3 ] , const real_T cwh3a1nlhw [
9 ] , const real_T aekciksy5j [ 9 ] , const real_T ertdiuxk4e [ 9 ] ,
pp3ucak1we * localB ) { static const int8_T b [ 3 ] = { 1 , 0 , 0 } ; real_T
aekciksy5j_p [ 9 ] ; real_T c [ 3 ] ; real_T R ; real_T absxk ; real_T scale
; real_T t ; int32_T i ; int32_T i_p ; scale = 3.3121686421112381E-170 ;
absxk = muDoubleScalarAbs ( fmbos3wpbf [ 0 ] ) ; if ( absxk >
3.3121686421112381E-170 ) { R = 1.0 ; scale = absxk ; } else { t = absxk /
3.3121686421112381E-170 ; R = t * t ; } absxk = muDoubleScalarAbs (
fmbos3wpbf [ 1 ] ) ; if ( absxk > scale ) { t = scale / absxk ; R = R * t * t
+ 1.0 ; scale = absxk ; } else { t = absxk / scale ; R += t * t ; } absxk =
muDoubleScalarAbs ( fmbos3wpbf [ 2 ] ) ; if ( absxk > scale ) { t = scale /
absxk ; R = R * t * t + 1.0 ; scale = absxk ; } else { t = absxk / scale ; R
+= t * t ; } R = scale * muDoubleScalarSqrt ( R ) ; for ( i = 0 ; i < 3 ; i
++ ) { c [ i ] = 0.0 ; for ( i_p = 0 ; i_p < 3 ; i_p ++ ) { aekciksy5j_p [ i
+ 3 * i_p ] = 0.0 ; aekciksy5j_p [ i + 3 * i_p ] += aekciksy5j [ i ] *
ertdiuxk4e [ i_p ] ; aekciksy5j_p [ i + 3 * i_p ] += aekciksy5j [ i + 3 ] *
ertdiuxk4e [ i_p + 3 ] ; aekciksy5j_p [ i + 3 * i_p ] += aekciksy5j [ i + 6 ]
* ertdiuxk4e [ i_p + 6 ] ; c [ i ] += aekciksy5j_p [ 3 * i_p + i ] * ( real_T
) b [ i_p ] ; } } R = 1.1958E+6 / muDoubleScalarPower ( R , 3.0 ) ; localB ->
fyfzf3djiy [ 0 ] = ( cwh3a1nlhw [ 8 ] - cwh3a1nlhw [ 4 ] ) * c [ 2 ] * c [ 1
] * R ; localB -> fyfzf3djiy [ 1 ] = ( cwh3a1nlhw [ 0 ] - cwh3a1nlhw [ 8 ] )
* c [ 0 ] * c [ 2 ] * R ; localB -> fyfzf3djiy [ 2 ] = ( cwh3a1nlhw [ 4 ] -
cwh3a1nlhw [ 0 ] ) * c [ 1 ] * c [ 0 ] * R ; } void hsoam3rxzy ( const real_T
jpm2qz2iyl [ 3 ] , const real_T nzopxhbv3c [ 3 ] , ol1ikflgm2 * localB ) {
localB -> ekyf2ft5xv [ 0 ] = nzopxhbv3c [ 1 ] * jpm2qz2iyl [ 2 ] - nzopxhbv3c
[ 2 ] * jpm2qz2iyl [ 1 ] ; localB -> ekyf2ft5xv [ 1 ] = nzopxhbv3c [ 2 ] *
jpm2qz2iyl [ 0 ] - nzopxhbv3c [ 0 ] * jpm2qz2iyl [ 2 ] ; localB -> ekyf2ft5xv
[ 2 ] = nzopxhbv3c [ 0 ] * jpm2qz2iyl [ 1 ] - nzopxhbv3c [ 1 ] * jpm2qz2iyl [
0 ] ; } void px30hprmrj ( real_T d1lgk0ojoi , real_T cvv5hxqufx , real_T
pgzxfpmemr , ep05ktrzpt * localB ) { real_T a ; a = pgzxfpmemr *
muDoubleScalarCos ( d1lgk0ojoi ) + 1.0 ; localB -> gmfjxhcwab =
muDoubleScalarSqrt ( 398600.0 / muDoubleScalarPower ( cvv5hxqufx , 3.0 ) ) *
( a * a ) / muDoubleScalarPower ( 1.0 - pgzxfpmemr * pgzxfpmemr , 1.5 ) ; }
void nvfofocjrz ( real_T g5qtnsmpla , real_T mecsxevckv , real_T ekqpr202db ,
real_T pmpnhldz0v , real_T ct1sh4vbj1 , real_T hm0lqfsqit , ew4humqmjw *
localB ) { static const int8_T b [ 3 ] = { 0 , 0 , 1 } ; real_T c [ 9 ] ;
real_T tmp [ 9 ] ; real_T tmp_e [ 9 ] ; real_T tmp_p [ 9 ] ; real_T p_p [ 3 ]
; real_T r_p [ 3 ] ; real_T p ; real_T r ; int32_T i ; int32_T i_p ; p = (
1.0 - mecsxevckv * mecsxevckv ) * g5qtnsmpla ; r = p / ( mecsxevckv *
muDoubleScalarCos ( hm0lqfsqit ) + 1.0 ) ; p = muDoubleScalarSqrt ( 398600.0
/ p ) ; tmp [ 0 ] = muDoubleScalarCos ( ct1sh4vbj1 ) ; tmp [ 3 ] =
muDoubleScalarSin ( ct1sh4vbj1 ) ; tmp [ 6 ] = 0.0 ; tmp [ 1 ] = -
muDoubleScalarSin ( ct1sh4vbj1 ) ; tmp [ 4 ] = muDoubleScalarCos ( ct1sh4vbj1
) ; tmp [ 7 ] = 0.0 ; tmp [ 2 ] = 0.0 ; c [ 0 ] = 1.0 ; tmp [ 5 ] = 0.0 ; c [
3 ] = 0.0 ; tmp [ 8 ] = 1.0 ; c [ 6 ] = 0.0 ; c [ 1 ] = 0.0 ; c [ 4 ] =
muDoubleScalarCos ( ekqpr202db ) ; c [ 7 ] = muDoubleScalarSin ( ekqpr202db )
; c [ 2 ] = 0.0 ; c [ 5 ] = - muDoubleScalarSin ( ekqpr202db ) ; c [ 8 ] =
muDoubleScalarCos ( ekqpr202db ) ; tmp_e [ 0 ] = muDoubleScalarCos (
pmpnhldz0v ) ; tmp_e [ 3 ] = muDoubleScalarSin ( pmpnhldz0v ) ; tmp_e [ 6 ] =
0.0 ; tmp_e [ 1 ] = - muDoubleScalarSin ( pmpnhldz0v ) ; tmp_e [ 4 ] =
muDoubleScalarCos ( pmpnhldz0v ) ; tmp_e [ 7 ] = 0.0 ; for ( i = 0 ; i < 3 ;
i ++ ) { for ( i_p = 0 ; i_p < 3 ; i_p ++ ) { tmp_p [ i + 3 * i_p ] = 0.0 ;
tmp_p [ i + 3 * i_p ] += c [ 3 * i_p ] * tmp [ i ] ; tmp_p [ i + 3 * i_p ] +=
c [ 3 * i_p + 1 ] * tmp [ i + 3 ] ; tmp_p [ i + 3 * i_p ] += c [ 3 * i_p + 2
] * tmp [ i + 6 ] ; } tmp_e [ 3 * i + 2 ] = b [ i ] ; } r_p [ 0 ] = r *
muDoubleScalarCos ( hm0lqfsqit ) ; r_p [ 1 ] = r * muDoubleScalarSin (
hm0lqfsqit ) ; r_p [ 2 ] = r * 0.0 ; p_p [ 0 ] = p * - muDoubleScalarSin (
hm0lqfsqit ) ; p_p [ 1 ] = ( mecsxevckv + muDoubleScalarCos ( hm0lqfsqit ) )
* p ; p_p [ 2 ] = p * 0.0 ; for ( i = 0 ; i < 3 ; i ++ ) { localB ->
a4etz1spm4 [ i ] = 0.0 ; localB -> edrpaasu4j [ i ] = 0.0 ; for ( i_p = 0 ;
i_p < 3 ; i_p ++ ) { localB -> nmcsp5dcxo [ i + 3 * i_p ] = 0.0 ; localB ->
nmcsp5dcxo [ i + 3 * i_p ] += tmp_e [ 3 * i ] * tmp_p [ i_p ] ; localB ->
nmcsp5dcxo [ i + 3 * i_p ] += tmp_e [ 3 * i + 1 ] * tmp_p [ i_p + 3 ] ;
localB -> nmcsp5dcxo [ i + 3 * i_p ] += tmp_e [ 3 * i + 2 ] * tmp_p [ i_p + 6
] ; localB -> a4etz1spm4 [ i ] += localB -> nmcsp5dcxo [ 3 * i_p + i ] * r_p
[ i_p ] ; localB -> edrpaasu4j [ i ] += localB -> nmcsp5dcxo [ 3 * i_p + i ]
* p_p [ i_p ] ; } } } void hxg1cub2fg ( const real_T mrvmsj22di [ 9 ] ,
real_T kjq0lyhqep , htahsp0knc * localB ) { real_T tmp [ 9 ] ; int32_T i ;
int32_T i_p ; tmp [ 0 ] = muDoubleScalarCos ( kjq0lyhqep ) ; tmp [ 3 ] =
muDoubleScalarSin ( kjq0lyhqep ) ; tmp [ 6 ] = 0.0 ; tmp [ 1 ] = -
muDoubleScalarSin ( kjq0lyhqep ) ; tmp [ 4 ] = muDoubleScalarCos ( kjq0lyhqep
) ; tmp [ 7 ] = 0.0 ; tmp [ 2 ] = 0.0 ; tmp [ 5 ] = 0.0 ; tmp [ 8 ] = 1.0 ;
for ( i = 0 ; i < 3 ; i ++ ) { for ( i_p = 0 ; i_p < 3 ; i_p ++ ) { localB ->
fws4iwogpu [ i + 3 * i_p ] = 0.0 ; localB -> fws4iwogpu [ i + 3 * i_p ] +=
tmp [ i ] * mrvmsj22di [ i_p ] ; localB -> fws4iwogpu [ i + 3 * i_p ] += tmp
[ i + 3 ] * mrvmsj22di [ i_p + 3 ] ; localB -> fws4iwogpu [ i + 3 * i_p ] +=
tmp [ i + 6 ] * mrvmsj22di [ i_p + 6 ] ; } } } static real_T ldsrcb4o0t (
const real_T x [ 3 ] ) { real_T absxk ; real_T scale ; real_T t ; real_T y ;
scale = 3.3121686421112381E-170 ; absxk = muDoubleScalarAbs ( x [ 0 ] ) ; if
( absxk > 3.3121686421112381E-170 ) { y = 1.0 ; scale = absxk ; } else { t =
absxk / 3.3121686421112381E-170 ; y = t * t ; } absxk = muDoubleScalarAbs ( x
[ 1 ] ) ; if ( absxk > scale ) { t = scale / absxk ; y = y * t * t + 1.0 ;
scale = absxk ; } else { t = absxk / scale ; y += t * t ; } absxk =
muDoubleScalarAbs ( x [ 2 ] ) ; if ( absxk > scale ) { t = scale / absxk ; y
= y * t * t + 1.0 ; scale = absxk ; } else { t = absxk / scale ; y += t * t ;
} return scale * muDoubleScalarSqrt ( y ) ; } void mzxxcjchg3 ( const real_T
ftpregj4gs [ 3 ] , const real_T gx4fl5ivda [ 3 ] , dwh41ujqlf * localB ) {
real_T h [ 3 ] ; real_T n ; real_T tmp ; n = muDoubleScalarSqrt ( 398600.0 /
muDoubleScalarPower ( ldsrcb4o0t ( ftpregj4gs ) , 3.0 ) ) ; h [ 0 ] =
ftpregj4gs [ 1 ] * gx4fl5ivda [ 2 ] - ftpregj4gs [ 2 ] * gx4fl5ivda [ 1 ] ; h
[ 1 ] = ftpregj4gs [ 2 ] * gx4fl5ivda [ 0 ] - ftpregj4gs [ 0 ] * gx4fl5ivda [
2 ] ; h [ 2 ] = ftpregj4gs [ 0 ] * gx4fl5ivda [ 1 ] - ftpregj4gs [ 1 ] *
gx4fl5ivda [ 0 ] ; tmp = ldsrcb4o0t ( h ) ; localB -> g540wbqcci [ 0 ] = h [
0 ] / tmp * n ; localB -> g540wbqcci [ 1 ] = h [ 1 ] / tmp * n ; localB ->
g540wbqcci [ 2 ] = h [ 2 ] / tmp * n ; } real_T rt_urand_Upu32_Yd_f_pw_snf (
uint32_T * u ) { uint32_T hi ; uint32_T lo ; lo = * u % 127773U * 16807U ; hi
= * u / 127773U * 2836U ; if ( lo < hi ) { * u = 2147483647U - ( hi - lo ) ;
} else { * u = lo - hi ; } return ( real_T ) * u * 4.6566128752457969E-10 ; }
real_T rt_nrand_Upu32_Yd_f_pw_snf ( uint32_T * u ) { real_T si ; real_T sr ;
real_T y ; do { sr = 2.0 * rt_urand_Upu32_Yd_f_pw_snf ( u ) - 1.0 ; si = 2.0
* rt_urand_Upu32_Yd_f_pw_snf ( u ) - 1.0 ; si = sr * sr + si * si ; } while (
si > 1.0 ) ; y = muDoubleScalarSqrt ( - 2.0 * muDoubleScalarLog ( si ) / si )
* sr ; return y ; } static real_T pke5l1lpzc ( const real_T x [ 3 ] ) {
real_T absxk ; real_T scale ; real_T t ; real_T y ; scale =
3.3121686421112381E-170 ; absxk = muDoubleScalarAbs ( x [ 0 ] ) ; if ( absxk
> 3.3121686421112381E-170 ) { y = 1.0 ; scale = absxk ; } else { t = absxk /
3.3121686421112381E-170 ; y = t * t ; } absxk = muDoubleScalarAbs ( x [ 1 ] )
; if ( absxk > scale ) { t = scale / absxk ; y = y * t * t + 1.0 ; scale =
absxk ; } else { t = absxk / scale ; y += t * t ; } absxk = muDoubleScalarAbs
( x [ 2 ] ) ; if ( absxk > scale ) { t = scale / absxk ; y = y * t * t + 1.0
; scale = absxk ; } else { t = absxk / scale ; y += t * t ; } return scale *
muDoubleScalarSqrt ( y ) ; } static real_T lkdukp33cm ( int32_T n , const
real_T x [ 9 ] , int32_T ix0 ) { real_T absxk ; real_T scale ; real_T t ;
real_T y ; int32_T k ; int32_T kend ; y = 0.0 ; scale =
3.3121686421112381E-170 ; kend = ( ix0 + n ) - 1 ; for ( k = ix0 ; k <= kend
; k ++ ) { absxk = muDoubleScalarAbs ( x [ k - 1 ] ) ; if ( absxk > scale ) {
t = scale / absxk ; y = y * t * t + 1.0 ; scale = absxk ; } else { t = absxk
/ scale ; y += t * t ; } } return scale * muDoubleScalarSqrt ( y ) ; } static
void lzwbonwaxs ( int32_T n , real_T a , real_T x [ 9 ] , int32_T ix0 ) {
int32_T b ; int32_T k ; b = ( ix0 + n ) - 1 ; for ( k = ix0 ; k <= b ; k ++ )
{ x [ k - 1 ] *= a ; } } static real_T lkdukp33cmh ( const real_T x [ 3 ] ,
int32_T ix0 ) { real_T absxk ; real_T scale ; real_T t ; real_T y ; int32_T k
; y = 0.0 ; scale = 3.3121686421112381E-170 ; for ( k = ix0 ; k <= ix0 + 1 ;
k ++ ) { absxk = muDoubleScalarAbs ( x [ k - 1 ] ) ; if ( absxk > scale ) { t
= scale / absxk ; y = y * t * t + 1.0 ; scale = absxk ; } else { t = absxk /
scale ; y += t * t ; } } return scale * muDoubleScalarSqrt ( y ) ; } static
void lzwbonwaxsl ( real_T a , real_T x [ 3 ] , int32_T ix0 ) { int32_T k ;
for ( k = ix0 ; k <= ix0 + 1 ; k ++ ) { x [ k - 1 ] *= a ; } } static void
iar1b2uyw3no ( int32_T n , real_T a , const real_T x [ 3 ] , int32_T ix0 ,
real_T y [ 9 ] , int32_T iy0 ) { int32_T ix ; int32_T iy ; int32_T k ; if ( !
( a == 0.0 ) ) { ix = ix0 - 1 ; iy = iy0 - 1 ; for ( k = 0 ; k < n ; k ++ ) {
y [ iy ] += a * x [ ix ] ; ix ++ ; iy ++ ; } } } static void iar1b2uyw3n (
int32_T n , real_T a , const real_T x [ 9 ] , int32_T ix0 , real_T y [ 3 ] ,
int32_T iy0 ) { int32_T ix ; int32_T iy ; int32_T k ; if ( ! ( a == 0.0 ) ) {
ix = ix0 - 1 ; iy = iy0 - 1 ; for ( k = 0 ; k < n ; k ++ ) { y [ iy ] += a *
x [ ix ] ; ix ++ ; iy ++ ; } } } static real_T cip4gtzcun ( int32_T n , const
real_T x [ 9 ] , int32_T ix0 , const real_T y [ 9 ] , int32_T iy0 ) { real_T
d ; int32_T ix ; int32_T iy ; int32_T k ; d = 0.0 ; ix = ix0 ; iy = iy0 ; for
( k = 0 ; k < n ; k ++ ) { d += x [ ix - 1 ] * y [ iy - 1 ] ; ix ++ ; iy ++ ;
} return d ; } static void iar1b2uyw3 ( int32_T n , real_T a , int32_T ix0 ,
real_T y [ 9 ] , int32_T iy0 ) { int32_T ix ; int32_T iy ; int32_T k ; if ( !
( a == 0.0 ) ) { ix = ix0 - 1 ; iy = iy0 - 1 ; for ( k = 0 ; k < n ; k ++ ) {
y [ iy ] += a * y [ ix ] ; ix ++ ; iy ++ ; } } } static void lzwbonwaxslr (
real_T a , real_T x [ 9 ] , int32_T ix0 ) { int32_T k ; for ( k = ix0 ; k <=
ix0 + 2 ; k ++ ) { x [ k - 1 ] *= a ; } } static void ox0rgyqacd ( real_T x [
9 ] , int32_T ix0 , int32_T iy0 ) { real_T temp ; temp = x [ ix0 - 1 ] ; x [
ix0 - 1 ] = x [ iy0 - 1 ] ; x [ iy0 - 1 ] = temp ; temp = x [ ix0 ] ; x [ ix0
] = x [ iy0 ] ; x [ iy0 ] = temp ; temp = x [ ix0 + 1 ] ; x [ ix0 + 1 ] = x [
iy0 + 1 ] ; x [ iy0 + 1 ] = temp ; } static void kw0pupmsbg ( real_T * a ,
real_T * b , real_T * c , real_T * s ) { real_T absa ; real_T absb ; real_T
ads ; real_T bds ; real_T roe ; real_T scale ; roe = * b ; absa =
muDoubleScalarAbs ( * a ) ; absb = muDoubleScalarAbs ( * b ) ; if ( absa >
absb ) { roe = * a ; } scale = absa + absb ; if ( scale == 0.0 ) { * s = 0.0
; * c = 1.0 ; * b = 0.0 ; } else { ads = absa / scale ; bds = absb / scale ;
scale *= muDoubleScalarSqrt ( ads * ads + bds * bds ) ; if ( roe < 0.0 ) {
scale = - scale ; } * c = * a / scale ; * s = * b / scale ; if ( absa > absb
) { * b = * s ; } else if ( * c != 0.0 ) { * b = 1.0 / * c ; } else { * b =
1.0 ; } } * a = scale ; } static void godcwr1fhb ( real_T x [ 9 ] , int32_T
ix0 , int32_T iy0 , real_T c , real_T s ) { real_T temp ; temp = x [ ix0 - 1
] * c + x [ iy0 - 1 ] * s ; x [ iy0 - 1 ] = x [ iy0 - 1 ] * c - x [ ix0 - 1 ]
* s ; x [ ix0 - 1 ] = temp ; temp = x [ ix0 ] * c + x [ iy0 ] * s ; x [ iy0 ]
= x [ iy0 ] * c - x [ ix0 ] * s ; x [ ix0 ] = temp ; temp = x [ ix0 + 1 ] * c
+ x [ iy0 + 1 ] * s ; x [ iy0 + 1 ] = x [ iy0 + 1 ] * c - x [ ix0 + 1 ] * s ;
x [ ix0 + 1 ] = temp ; } static void o4vts0g5zg ( const real_T A [ 9 ] ,
real_T U [ 9 ] , real_T s [ 3 ] , real_T V [ 9 ] ) { real_T b_A [ 9 ] ;
real_T b_s [ 3 ] ; real_T e [ 3 ] ; real_T work [ 3 ] ; real_T emm1 ; real_T
nrm ; real_T rt ; real_T shift ; real_T smm1 ; real_T sqds ; real_T ztest ;
int32_T d ; int32_T exitg1 ; int32_T k_ii ; int32_T kase ; int32_T m ;
int32_T qjj ; int32_T qq ; boolean_T apply_transform ; boolean_T exitg2 ; e [
0 ] = 0.0 ; work [ 0 ] = 0.0 ; e [ 1 ] = 0.0 ; work [ 1 ] = 0.0 ; e [ 2 ] =
0.0 ; work [ 2 ] = 0.0 ; for ( qq = 0 ; qq < 9 ; qq ++ ) { b_A [ qq ] = A [
qq ] ; U [ qq ] = 0.0 ; V [ qq ] = 0.0 ; } qq = 0 ; apply_transform = false ;
nrm = lkdukp33cm ( 3 , b_A , 1 ) ; if ( nrm > 0.0 ) { apply_transform = true
; if ( b_A [ 0 ] < 0.0 ) { b_s [ 0 ] = - nrm ; } else { b_s [ 0 ] = nrm ; }
if ( muDoubleScalarAbs ( b_s [ 0 ] ) >= 1.0020841800044864E-292 ) {
lzwbonwaxs ( 3 , 1.0 / b_s [ 0 ] , b_A , 1 ) ; } else { for ( qjj = 0 ; qjj <
3 ; qjj ++ ) { b_A [ qjj ] /= b_s [ 0 ] ; } } b_A [ 0 ] ++ ; b_s [ 0 ] = -
b_s [ 0 ] ; } else { b_s [ 0 ] = 0.0 ; } for ( d = 1 ; d + 1 < 4 ; d ++ ) {
qjj = 3 * d ; if ( apply_transform ) { iar1b2uyw3 ( 3 , - ( cip4gtzcun ( 3 ,
b_A , 1 , b_A , qjj + 1 ) / b_A [ 0 ] ) , 1 , b_A , qjj + 1 ) ; } e [ d ] =
b_A [ qjj ] ; } while ( qq + 1 < 4 ) { U [ qq ] = b_A [ qq ] ; qq ++ ; } nrm
= lkdukp33cmh ( e , 2 ) ; if ( nrm == 0.0 ) { e [ 0 ] = 0.0 ; } else { if ( e
[ 1 ] < 0.0 ) { nrm = - nrm ; } e [ 0 ] = nrm ; if ( muDoubleScalarAbs ( nrm
) >= 1.0020841800044864E-292 ) { lzwbonwaxsl ( 1.0 / nrm , e , 2 ) ; } else {
for ( qq = 1 ; qq < 3 ; qq ++ ) { e [ qq ] /= nrm ; } } e [ 1 ] ++ ; e [ 0 ]
= - e [ 0 ] ; for ( qq = 2 ; qq < 4 ; qq ++ ) { work [ qq - 1 ] = 0.0 ; } for
( qq = 1 ; qq + 1 < 4 ; qq ++ ) { iar1b2uyw3n ( 2 , e [ qq ] , b_A , 3 * qq +
2 , work , 2 ) ; } for ( qq = 1 ; qq + 1 < 4 ; qq ++ ) { iar1b2uyw3no ( 2 , -
e [ qq ] / e [ 1 ] , work , 2 , b_A , 3 * qq + 2 ) ; } } for ( qq = 1 ; qq +
1 < 4 ; qq ++ ) { V [ qq ] = e [ qq ] ; } apply_transform = false ; nrm =
lkdukp33cm ( 2 , b_A , 5 ) ; if ( nrm > 0.0 ) { apply_transform = true ; if (
b_A [ 4 ] < 0.0 ) { b_s [ 1 ] = - nrm ; } else { b_s [ 1 ] = nrm ; } if (
muDoubleScalarAbs ( b_s [ 1 ] ) >= 1.0020841800044864E-292 ) { lzwbonwaxs ( 2
, 1.0 / b_s [ 1 ] , b_A , 5 ) ; } else { for ( qjj = 4 ; qjj < 6 ; qjj ++ ) {
b_A [ qjj ] /= b_s [ 1 ] ; } } b_A [ 4 ] ++ ; b_s [ 1 ] = - b_s [ 1 ] ; }
else { b_s [ 1 ] = 0.0 ; } for ( d = 2 ; d + 1 < 4 ; d ++ ) { qjj = 3 * d + 1
; if ( apply_transform ) { iar1b2uyw3 ( 2 , - ( cip4gtzcun ( 2 , b_A , 5 ,
b_A , qjj + 1 ) / b_A [ 4 ] ) , 5 , b_A , qjj + 1 ) ; } e [ d ] = b_A [ qjj ]
; } for ( qq = 1 ; qq + 1 < 4 ; qq ++ ) { U [ qq + 3 ] = b_A [ qq + 3 ] ; } m
= 1 ; b_s [ 2 ] = b_A [ 8 ] ; U [ 6 ] = 0.0 ; U [ 7 ] = 0.0 ; U [ 8 ] = 1.0 ;
for ( d = 1 ; d >= 0 ; d -- ) { qq = 3 * d + d ; if ( b_s [ d ] != 0.0 ) {
for ( kase = d + 1 ; kase + 1 < 4 ; kase ++ ) { qjj = ( 3 * kase + d ) + 1 ;
iar1b2uyw3 ( 3 - d , - ( cip4gtzcun ( 3 - d , U , qq + 1 , U , qjj ) / U [ qq
] ) , qq + 1 , U , qjj ) ; } for ( qjj = d ; qjj + 1 < 4 ; qjj ++ ) { U [ qjj
+ 3 * d ] = - U [ 3 * d + qjj ] ; } U [ qq ] ++ ; if ( 0 <= d - 1 ) { U [ 3 *
d ] = 0.0 ; } } else { U [ 3 * d ] = 0.0 ; U [ 3 * d + 1 ] = 0.0 ; U [ 3 * d
+ 2 ] = 0.0 ; U [ qq ] = 1.0 ; } } for ( qq = 2 ; qq >= 0 ; qq -- ) { if ( (
qq + 1 <= 1 ) && ( e [ 0 ] != 0.0 ) ) { iar1b2uyw3 ( 2 , - ( cip4gtzcun ( 2 ,
V , 2 , V , 5 ) / V [ 1 ] ) , 2 , V , 5 ) ; iar1b2uyw3 ( 2 , - ( cip4gtzcun (
2 , V , 2 , V , 8 ) / V [ 1 ] ) , 2 , V , 8 ) ; } V [ 3 * qq ] = 0.0 ; V [ 3
* qq + 1 ] = 0.0 ; V [ 3 * qq + 2 ] = 0.0 ; V [ qq + 3 * qq ] = 1.0 ; } ztest
= e [ 0 ] ; if ( b_s [ 0 ] != 0.0 ) { rt = muDoubleScalarAbs ( b_s [ 0 ] ) ;
nrm = b_s [ 0 ] / rt ; b_s [ 0 ] = rt ; ztest = e [ 0 ] / nrm ; lzwbonwaxslr
( nrm , U , 1 ) ; } if ( ztest != 0.0 ) { rt = muDoubleScalarAbs ( ztest ) ;
nrm = rt / ztest ; ztest = rt ; b_s [ 1 ] *= nrm ; lzwbonwaxslr ( nrm , V , 4
) ; } e [ 0 ] = ztest ; ztest = b_A [ 7 ] ; if ( b_s [ 1 ] != 0.0 ) { rt =
muDoubleScalarAbs ( b_s [ 1 ] ) ; nrm = b_s [ 1 ] / rt ; b_s [ 1 ] = rt ;
ztest = b_A [ 7 ] / nrm ; lzwbonwaxslr ( nrm , U , 4 ) ; } if ( ztest != 0.0
) { rt = muDoubleScalarAbs ( ztest ) ; nrm = rt / ztest ; ztest = rt ; b_s [
2 ] = b_A [ 8 ] * nrm ; lzwbonwaxslr ( nrm , V , 7 ) ; } e [ 1 ] = ztest ; if
( b_s [ 2 ] != 0.0 ) { rt = muDoubleScalarAbs ( b_s [ 2 ] ) ; nrm = b_s [ 2 ]
/ rt ; b_s [ 2 ] = rt ; lzwbonwaxslr ( nrm , U , 7 ) ; } e [ 2 ] = 0.0 ; qq =
0 ; nrm = muDoubleScalarMax ( muDoubleScalarMax ( muDoubleScalarMax ( b_s [ 0
] , e [ 0 ] ) , muDoubleScalarMax ( b_s [ 1 ] , ztest ) ) , muDoubleScalarMax
( b_s [ 2 ] , 0.0 ) ) ; while ( ( m + 2 > 0 ) && ( qq < 75 ) ) { kase = m + 1
; do { exitg1 = 0 ; d = kase ; if ( kase == 0 ) { exitg1 = 1 ; } else { rt =
muDoubleScalarAbs ( e [ kase - 1 ] ) ; if ( ( rt <= ( muDoubleScalarAbs ( b_s
[ kase - 1 ] ) + muDoubleScalarAbs ( b_s [ kase ] ) ) *
2.2204460492503131E-16 ) || ( ( rt <= 1.0020841800044864E-292 ) || ( ( qq >
20 ) && ( rt <= 2.2204460492503131E-16 * nrm ) ) ) ) { e [ kase - 1 ] = 0.0 ;
exitg1 = 1 ; } else { kase -- ; } } } while ( exitg1 == 0 ) ; if ( m + 1 ==
kase ) { kase = 4 ; } else { qjj = m + 2 ; k_ii = m + 2 ; exitg2 = false ;
while ( ( ! exitg2 ) && ( k_ii >= kase ) ) { qjj = k_ii ; if ( k_ii == kase )
{ exitg2 = true ; } else { rt = 0.0 ; if ( k_ii < m + 2 ) { rt =
muDoubleScalarAbs ( e [ k_ii - 1 ] ) ; } if ( k_ii > kase + 1 ) { rt +=
muDoubleScalarAbs ( e [ k_ii - 2 ] ) ; } ztest = muDoubleScalarAbs ( b_s [
k_ii - 1 ] ) ; if ( ( ztest <= 2.2204460492503131E-16 * rt ) || ( ztest <=
1.0020841800044864E-292 ) ) { b_s [ k_ii - 1 ] = 0.0 ; exitg2 = true ; } else
{ k_ii -- ; } } } if ( qjj == kase ) { kase = 3 ; } else if ( m + 2 == qjj )
{ kase = 1 ; } else { kase = 2 ; d = qjj ; } } switch ( kase ) { case 1 : rt
= e [ m ] ; e [ m ] = 0.0 ; for ( qjj = m ; qjj + 1 >= d + 1 ; qjj -- ) {
kw0pupmsbg ( & b_s [ qjj ] , & rt , & ztest , & sqds ) ; if ( qjj + 1 > d + 1
) { rt = - sqds * e [ 0 ] ; e [ 0 ] *= ztest ; } godcwr1fhb ( V , 3 * qjj + 1
, 3 * ( m + 1 ) + 1 , ztest , sqds ) ; } break ; case 2 : rt = e [ d - 1 ] ;
e [ d - 1 ] = 0.0 ; for ( qjj = d ; qjj < m + 2 ; qjj ++ ) { kw0pupmsbg ( &
b_s [ qjj ] , & rt , & ztest , & sqds ) ; rt = - sqds * e [ qjj ] ; e [ qjj ]
*= ztest ; godcwr1fhb ( U , 3 * qjj + 1 , 3 * ( d - 1 ) + 1 , ztest , sqds )
; } break ; case 3 : ztest = muDoubleScalarMax ( muDoubleScalarMax (
muDoubleScalarMax ( muDoubleScalarMax ( muDoubleScalarAbs ( b_s [ m + 1 ] ) ,
muDoubleScalarAbs ( b_s [ m ] ) ) , muDoubleScalarAbs ( e [ m ] ) ) ,
muDoubleScalarAbs ( b_s [ d ] ) ) , muDoubleScalarAbs ( e [ d ] ) ) ; rt =
b_s [ m + 1 ] / ztest ; smm1 = b_s [ m ] / ztest ; emm1 = e [ m ] / ztest ;
sqds = b_s [ d ] / ztest ; smm1 = ( ( smm1 + rt ) * ( smm1 - rt ) + emm1 *
emm1 ) / 2.0 ; emm1 *= rt ; emm1 *= emm1 ; if ( ( smm1 != 0.0 ) || ( emm1 !=
0.0 ) ) { shift = muDoubleScalarSqrt ( smm1 * smm1 + emm1 ) ; if ( smm1 < 0.0
) { shift = - shift ; } shift = emm1 / ( smm1 + shift ) ; } else { shift =
0.0 ; } rt = ( sqds + rt ) * ( sqds - rt ) + shift ; ztest = e [ d ] / ztest
* sqds ; for ( qjj = d + 1 ; qjj <= m + 1 ; qjj ++ ) { kw0pupmsbg ( & rt , &
ztest , & sqds , & smm1 ) ; if ( qjj > d + 1 ) { e [ 0 ] = rt ; } rt = b_s [
qjj - 1 ] * sqds + e [ qjj - 1 ] * smm1 ; e [ qjj - 1 ] = e [ qjj - 1 ] *
sqds - b_s [ qjj - 1 ] * smm1 ; ztest = smm1 * b_s [ qjj ] ; b_s [ qjj ] *=
sqds ; godcwr1fhb ( V , 3 * ( qjj - 1 ) + 1 , 3 * qjj + 1 , sqds , smm1 ) ;
kw0pupmsbg ( & rt , & ztest , & sqds , & smm1 ) ; b_s [ qjj - 1 ] = rt ; rt =
e [ qjj - 1 ] * sqds + smm1 * b_s [ qjj ] ; b_s [ qjj ] = e [ qjj - 1 ] * -
smm1 + sqds * b_s [ qjj ] ; ztest = smm1 * e [ qjj ] ; e [ qjj ] *= sqds ;
godcwr1fhb ( U , 3 * ( qjj - 1 ) + 1 , 3 * qjj + 1 , sqds , smm1 ) ; } e [ m
] = rt ; qq ++ ; break ; default : if ( b_s [ d ] < 0.0 ) { b_s [ d ] = - b_s
[ d ] ; lzwbonwaxslr ( - 1.0 , V , 3 * d + 1 ) ; } qq = d + 1 ; while ( ( d +
1 < 3 ) && ( b_s [ d ] < b_s [ qq ] ) ) { rt = b_s [ d ] ; b_s [ d ] = b_s [
qq ] ; b_s [ qq ] = rt ; ox0rgyqacd ( V , 3 * d + 1 , 3 * ( d + 1 ) + 1 ) ;
ox0rgyqacd ( U , 3 * d + 1 , 3 * ( d + 1 ) + 1 ) ; d = qq ; qq ++ ; } qq = 0
; m -- ; break ; } } s [ 0 ] = b_s [ 0 ] ; s [ 1 ] = b_s [ 1 ] ; s [ 2 ] =
b_s [ 2 ] ; } static real_T kdmv5ezpwv ( const real_T x [ 9 ] ) { real_T A [
9 ] ; real_T b_y ; real_T smax ; real_T y ; int32_T c ; int32_T c_ix ;
int32_T c_k ; int32_T d ; int32_T ijA ; int32_T ix ; int32_T iy ; int32_T j ;
int8_T ipiv [ 3 ] ; boolean_T isodd ; memcpy ( & A [ 0 ] , & x [ 0 ] , 9U *
sizeof ( real_T ) ) ; ipiv [ 0 ] = 1 ; ipiv [ 1 ] = 2 ; for ( j = 0 ; j < 2 ;
j ++ ) { c = j << 2 ; iy = 0 ; ix = c ; smax = muDoubleScalarAbs ( A [ c ] )
; for ( c_k = 2 ; c_k <= 3 - j ; c_k ++ ) { ix ++ ; b_y = muDoubleScalarAbs (
A [ ix ] ) ; if ( b_y > smax ) { iy = c_k - 1 ; smax = b_y ; } } if ( A [ c +
iy ] != 0.0 ) { if ( iy != 0 ) { ipiv [ j ] = ( int8_T ) ( ( j + iy ) + 1 ) ;
iy += j ; smax = A [ j ] ; A [ j ] = A [ iy ] ; A [ iy ] = smax ; iy += 3 ;
smax = A [ j + 3 ] ; A [ j + 3 ] = A [ iy ] ; A [ iy ] = smax ; iy += 3 ;
smax = A [ j + 6 ] ; A [ j + 6 ] = A [ iy ] ; A [ iy ] = smax ; } iy = ( c -
j ) + 3 ; for ( ix = c + 1 ; ix < iy ; ix ++ ) { A [ ix ] /= A [ c ] ; } } iy
= c ; ix = c + 3 ; for ( c_k = 0 ; c_k <= 1 - j ; c_k ++ ) { smax = A [ ix ]
; if ( A [ ix ] != 0.0 ) { c_ix = c + 1 ; d = ( iy - j ) + 6 ; for ( ijA = iy
+ 4 ; ijA < d ; ijA ++ ) { A [ ijA ] += A [ c_ix ] * - smax ; c_ix ++ ; } }
ix += 3 ; iy += 3 ; } } isodd = ( ipiv [ 0 ] > 1 ) ; y = A [ 0 ] * A [ 4 ] *
A [ 8 ] ; if ( ipiv [ 1 ] > 2 ) { isodd = ! isodd ; } if ( isodd ) { y = - y
; } return y ; } static void brfsyu5ndt ( const real_T A [ 9 ] , const real_T
B_p [ 3 ] , real_T Y [ 3 ] ) { real_T b_A [ 9 ] ; real_T maxval ; real_T y ;
int32_T r1 ; int32_T r2 ; int32_T r3 ; int32_T rtemp ; memcpy ( & b_A [ 0 ] ,
& A [ 0 ] , 9U * sizeof ( real_T ) ) ; r1 = 0 ; r2 = 1 ; r3 = 2 ; maxval =
muDoubleScalarAbs ( A [ 0 ] ) ; y = muDoubleScalarAbs ( A [ 1 ] ) ; if ( y >
muDoubleScalarAbs ( A [ 0 ] ) ) { maxval = y ; r1 = 1 ; r2 = 0 ; } if (
muDoubleScalarAbs ( A [ 2 ] ) > maxval ) { r1 = 2 ; r2 = 1 ; r3 = 0 ; } b_A [
r2 ] = A [ r2 ] / A [ r1 ] ; b_A [ r3 ] /= b_A [ r1 ] ; b_A [ r2 + 3 ] -= b_A
[ r1 + 3 ] * b_A [ r2 ] ; b_A [ r3 + 3 ] -= b_A [ r1 + 3 ] * b_A [ r3 ] ; b_A
[ r2 + 6 ] -= b_A [ r1 + 6 ] * b_A [ r2 ] ; b_A [ r3 + 6 ] -= b_A [ r1 + 6 ]
* b_A [ r3 ] ; if ( muDoubleScalarAbs ( b_A [ r3 + 3 ] ) > muDoubleScalarAbs
( b_A [ r2 + 3 ] ) ) { rtemp = r2 ; r2 = r3 ; r3 = rtemp ; } b_A [ r3 + 3 ]
/= b_A [ r2 + 3 ] ; b_A [ r3 + 6 ] -= b_A [ r3 + 3 ] * b_A [ r2 + 6 ] ; Y [ 1
] = B_p [ r2 ] - B_p [ r1 ] * b_A [ r2 ] ; Y [ 2 ] = ( B_p [ r3 ] - B_p [ r1
] * b_A [ r3 ] ) - b_A [ r3 + 3 ] * Y [ 1 ] ; Y [ 2 ] /= b_A [ r3 + 6 ] ; Y [
0 ] = B_p [ r1 ] - b_A [ r1 + 6 ] * Y [ 2 ] ; Y [ 1 ] -= b_A [ r2 + 6 ] * Y [
2 ] ; Y [ 1 ] /= b_A [ r2 + 3 ] ; Y [ 0 ] -= b_A [ r1 + 3 ] * Y [ 1 ] ; Y [ 0
] /= b_A [ r1 ] ; } void MdlInitialize ( void ) { real_T tmp_p ; int32_T iU ;
int32_T r ; int32_T t ; uint32_T tseed ; boolean_T tmp ; memcpy ( & rtX .
ouapiys3qq [ 0 ] , & rtP . data . ic . dcm [ 0 ] , 9U * sizeof ( real_T ) ) ;
rtX . kjairk4b1p = rtP . data . ic . th ; rtX . lutbl3ejqb [ 0 ] = rtP . data
. ic . w [ 0 ] ; tmp_p = muDoubleScalarFloor ( rtP . RandomNumber1_Seed [ 0 ]
) ; if ( muDoubleScalarIsNaN ( tmp_p ) || muDoubleScalarIsInf ( tmp_p ) ) {
tmp_p = 0.0 ; } else { tmp_p = muDoubleScalarRem ( tmp_p , 4.294967296E+9 ) ;
} tseed = tmp_p < 0.0 ? ( uint32_T ) - ( int32_T ) ( uint32_T ) - tmp_p : (
uint32_T ) tmp_p ; r = ( int32_T ) ( tseed >> 16U ) ; t = ( int32_T ) ( tseed
& 32768U ) ; tseed = ( ( ( ( tseed - ( ( uint32_T ) r << 16U ) ) + t ) << 16U
) + t ) + r ; if ( tseed < 1U ) { tseed = 1144108930U ; } else { if ( tseed >
2147483646U ) { tseed = 2147483646U ; } } rtDW . ewjz1wr2fe [ 0 ] = tseed ;
rtDW . n1mf5f1loj [ 0 ] = rt_nrand_Upu32_Yd_f_pw_snf ( & rtDW . ewjz1wr2fe [
0 ] ) * rtP . RandomNumber1_StdDev [ 0 ] + rtP . RandomNumber1_Mean ; rtX .
lutbl3ejqb [ 1 ] = rtP . data . ic . w [ 1 ] ; tmp_p = muDoubleScalarFloor (
rtP . RandomNumber1_Seed [ 1 ] ) ; if ( muDoubleScalarIsNaN ( tmp_p ) ||
muDoubleScalarIsInf ( tmp_p ) ) { tmp_p = 0.0 ; } else { tmp_p =
muDoubleScalarRem ( tmp_p , 4.294967296E+9 ) ; } tseed = tmp_p < 0.0 ? (
uint32_T ) - ( int32_T ) ( uint32_T ) - tmp_p : ( uint32_T ) tmp_p ; r = (
int32_T ) ( tseed >> 16U ) ; t = ( int32_T ) ( tseed & 32768U ) ; tseed = ( (
( ( tseed - ( ( uint32_T ) r << 16U ) ) + t ) << 16U ) + t ) + r ; if ( tseed
< 1U ) { tseed = 1144108930U ; } else { if ( tseed > 2147483646U ) { tseed =
2147483646U ; } } rtDW . ewjz1wr2fe [ 1 ] = tseed ; rtDW . n1mf5f1loj [ 1 ] =
rt_nrand_Upu32_Yd_f_pw_snf ( & rtDW . ewjz1wr2fe [ 1 ] ) * rtP .
RandomNumber1_StdDev [ 1 ] + rtP . RandomNumber1_Mean ; rtX . lutbl3ejqb [ 2
] = rtP . data . ic . w [ 2 ] ; tmp_p = muDoubleScalarFloor ( rtP .
RandomNumber1_Seed [ 2 ] ) ; if ( muDoubleScalarIsNaN ( tmp_p ) ||
muDoubleScalarIsInf ( tmp_p ) ) { tmp_p = 0.0 ; } else { tmp_p =
muDoubleScalarRem ( tmp_p , 4.294967296E+9 ) ; } tseed = tmp_p < 0.0 ? (
uint32_T ) - ( int32_T ) ( uint32_T ) - tmp_p : ( uint32_T ) tmp_p ; r = (
int32_T ) ( tseed >> 16U ) ; t = ( int32_T ) ( tseed & 32768U ) ; tseed = ( (
( ( tseed - ( ( uint32_T ) r << 16U ) ) + t ) << 16U ) + t ) + r ; if ( tseed
< 1U ) { tseed = 1144108930U ; } else { if ( tseed > 2147483646U ) { tseed =
2147483646U ; } } rtDW . ewjz1wr2fe [ 2 ] = tseed ; rtDW . n1mf5f1loj [ 2 ] =
rt_nrand_Upu32_Yd_f_pw_snf ( & rtDW . ewjz1wr2fe [ 2 ] ) * rtP .
RandomNumber1_StdDev [ 2 ] + rtP . RandomNumber1_Mean ; rtDW . h5pffuqljc = 1
; if ( ssIsFirstInitCond ( rtS ) ) { rtX . ht1cmxxnsq [ 0 ] =
8.8267181427637242E-7 ; rtX . ht1cmxxnsq [ 1 ] = 2.3671125085662905E-5 ; rtX
. ht1cmxxnsq [ 2 ] = 0.0010705063173763645 ; tmp =
slIsRapidAcceleratorSimulating ( ) ; if ( tmp ) { tmp =
ssGetGlobalInitialStatesAvailable ( rtS ) ; rtDW . h5pffuqljc = ! tmp ; }
else { rtDW . h5pffuqljc = 1 ; } } for ( iU = 0 ; iU < 8 ; iU ++ ) { tmp_p =
muDoubleScalarFloor ( rtP . RandomNumber_Seed [ iU ] ) ; if (
muDoubleScalarIsNaN ( tmp_p ) || muDoubleScalarIsInf ( tmp_p ) ) { tmp_p =
0.0 ; } else { tmp_p = muDoubleScalarRem ( tmp_p , 4.294967296E+9 ) ; } tseed
= tmp_p < 0.0 ? ( uint32_T ) - ( int32_T ) ( uint32_T ) - tmp_p : ( uint32_T
) tmp_p ; r = ( int32_T ) ( tseed >> 16U ) ; t = ( int32_T ) ( tseed & 32768U
) ; tseed = ( ( ( ( tseed - ( ( uint32_T ) r << 16U ) ) + t ) << 16U ) + t )
+ r ; if ( tseed < 1U ) { tseed = 1144108930U ; } else { if ( tseed >
2147483646U ) { tseed = 2147483646U ; } } rtDW . bnvhkeklee [ iU ] = tseed ;
rtDW . j4zaai5afv [ iU ] = rt_nrand_Upu32_Yd_f_pw_snf ( & rtDW . bnvhkeklee [
iU ] ) * rtP . RandomNumber_StdDev [ iU ] + rtP . RandomNumber_Mean ; } tmp_p
= muDoubleScalarFloor ( rtP . RandomNumber1_Seed_cspndgusfq [ 0 ] ) ; if (
muDoubleScalarIsNaN ( tmp_p ) || muDoubleScalarIsInf ( tmp_p ) ) { tmp_p =
0.0 ; } else { tmp_p = muDoubleScalarRem ( tmp_p , 4.294967296E+9 ) ; } tseed
= tmp_p < 0.0 ? ( uint32_T ) - ( int32_T ) ( uint32_T ) - tmp_p : ( uint32_T
) tmp_p ; r = ( int32_T ) ( tseed >> 16U ) ; t = ( int32_T ) ( tseed & 32768U
) ; tseed = ( ( ( ( tseed - ( ( uint32_T ) r << 16U ) ) + t ) << 16U ) + t )
+ r ; if ( tseed < 1U ) { tseed = 1144108930U ; } else { if ( tseed >
2147483646U ) { tseed = 2147483646U ; } } rtDW . k10aogs3q2 [ 0 ] = tseed ;
rtDW . ofluvtqt5p [ 0 ] = rt_nrand_Upu32_Yd_f_pw_snf ( & rtDW . k10aogs3q2 [
0 ] ) * rtP . RandomNumber1_StdDev_pxu4l4yv2r [ 0 ] + rtP .
RandomNumber1_Mean_bjj4nzkohe ; tmp_p = muDoubleScalarFloor ( rtP .
RandomNumber1_Seed_cspndgusfq [ 1 ] ) ; if ( muDoubleScalarIsNaN ( tmp_p ) ||
muDoubleScalarIsInf ( tmp_p ) ) { tmp_p = 0.0 ; } else { tmp_p =
muDoubleScalarRem ( tmp_p , 4.294967296E+9 ) ; } tseed = tmp_p < 0.0 ? (
uint32_T ) - ( int32_T ) ( uint32_T ) - tmp_p : ( uint32_T ) tmp_p ; r = (
int32_T ) ( tseed >> 16U ) ; t = ( int32_T ) ( tseed & 32768U ) ; tseed = ( (
( ( tseed - ( ( uint32_T ) r << 16U ) ) + t ) << 16U ) + t ) + r ; if ( tseed
< 1U ) { tseed = 1144108930U ; } else { if ( tseed > 2147483646U ) { tseed =
2147483646U ; } } rtDW . k10aogs3q2 [ 1 ] = tseed ; rtDW . ofluvtqt5p [ 1 ] =
rt_nrand_Upu32_Yd_f_pw_snf ( & rtDW . k10aogs3q2 [ 1 ] ) * rtP .
RandomNumber1_StdDev_pxu4l4yv2r [ 1 ] + rtP . RandomNumber1_Mean_bjj4nzkohe ;
tmp_p = muDoubleScalarFloor ( rtP . RandomNumber1_Seed_cspndgusfq [ 2 ] ) ;
if ( muDoubleScalarIsNaN ( tmp_p ) || muDoubleScalarIsInf ( tmp_p ) ) { tmp_p
= 0.0 ; } else { tmp_p = muDoubleScalarRem ( tmp_p , 4.294967296E+9 ) ; }
tseed = tmp_p < 0.0 ? ( uint32_T ) - ( int32_T ) ( uint32_T ) - tmp_p : (
uint32_T ) tmp_p ; r = ( int32_T ) ( tseed >> 16U ) ; t = ( int32_T ) ( tseed
& 32768U ) ; tseed = ( ( ( ( tseed - ( ( uint32_T ) r << 16U ) ) + t ) << 16U
) + t ) + r ; if ( tseed < 1U ) { tseed = 1144108930U ; } else { if ( tseed >
2147483646U ) { tseed = 2147483646U ; } } rtDW . k10aogs3q2 [ 2 ] = tseed ;
rtDW . ofluvtqt5p [ 2 ] = rt_nrand_Upu32_Yd_f_pw_snf ( & rtDW . k10aogs3q2 [
2 ] ) * rtP . RandomNumber1_StdDev_pxu4l4yv2r [ 2 ] + rtP .
RandomNumber1_Mean_bjj4nzkohe ; tmp_p = muDoubleScalarFloor ( rtP .
RandomNumber1_Seed_cspndgusfq [ 3 ] ) ; if ( muDoubleScalarIsNaN ( tmp_p ) ||
muDoubleScalarIsInf ( tmp_p ) ) { tmp_p = 0.0 ; } else { tmp_p =
muDoubleScalarRem ( tmp_p , 4.294967296E+9 ) ; } tseed = tmp_p < 0.0 ? (
uint32_T ) - ( int32_T ) ( uint32_T ) - tmp_p : ( uint32_T ) tmp_p ; r = (
int32_T ) ( tseed >> 16U ) ; t = ( int32_T ) ( tseed & 32768U ) ; tseed = ( (
( ( tseed - ( ( uint32_T ) r << 16U ) ) + t ) << 16U ) + t ) + r ; if ( tseed
< 1U ) { tseed = 1144108930U ; } else { if ( tseed > 2147483646U ) { tseed =
2147483646U ; } } rtDW . k10aogs3q2 [ 3 ] = tseed ; rtDW . ofluvtqt5p [ 3 ] =
rt_nrand_Upu32_Yd_f_pw_snf ( & rtDW . k10aogs3q2 [ 3 ] ) * rtP .
RandomNumber1_StdDev_pxu4l4yv2r [ 3 ] + rtP . RandomNumber1_Mean_bjj4nzkohe ;
for ( iU = 0 ; iU < 8 ; iU ++ ) { tmp_p = muDoubleScalarFloor ( rtP .
UniformRandomNumber_Seed [ iU ] ) ; if ( muDoubleScalarIsNaN ( tmp_p ) ||
muDoubleScalarIsInf ( tmp_p ) ) { tmp_p = 0.0 ; } else { tmp_p =
muDoubleScalarRem ( tmp_p , 4.294967296E+9 ) ; } tseed = tmp_p < 0.0 ? (
uint32_T ) - ( int32_T ) ( uint32_T ) - tmp_p : ( uint32_T ) tmp_p ; r = (
int32_T ) ( tseed >> 16U ) ; t = ( int32_T ) ( tseed & 32768U ) ; tseed = ( (
( ( tseed - ( ( uint32_T ) r << 16U ) ) + t ) << 16U ) + t ) + r ; if ( tseed
< 1U ) { tseed = 1144108930U ; } else { if ( tseed > 2147483646U ) { tseed =
2147483646U ; } } rtDW . c5xg33ddc3 [ iU ] = tseed ; rtDW . o221ifynn5 [ iU ]
= ( rtP . UniformRandomNumber_Maximum - rtP . UniformRandomNumber_Minimum ) *
rt_urand_Upu32_Yd_f_pw_snf ( & rtDW . c5xg33ddc3 [ iU ] ) + rtP .
UniformRandomNumber_Minimum ; } rtDW . mstj5paygm = 1 ; if (
ssIsFirstInitCond ( rtS ) ) { memset ( & rtX . fnoi12dssm [ 0 ] , 0 , 9U *
sizeof ( real_T ) ) ; tmp = slIsRapidAcceleratorSimulating ( ) ; if ( tmp ) {
tmp = ssGetGlobalInitialStatesAvailable ( rtS ) ; rtDW . mstj5paygm = ! tmp ;
} else { rtDW . mstj5paygm = 1 ; } } rtX . mnzw0suzs2 = rtP . data .
reactionWheel . h0 ; rtX . bqjsimdqqc = rtP . data . ic . th ; tmp_p =
muDoubleScalarFloor ( rtP . RandomNumber_Seed_g3q3oeokt3 [ 0 ] ) ; if (
muDoubleScalarIsNaN ( tmp_p ) || muDoubleScalarIsInf ( tmp_p ) ) { tmp_p =
0.0 ; } else { tmp_p = muDoubleScalarRem ( tmp_p , 4.294967296E+9 ) ; } tseed
= tmp_p < 0.0 ? ( uint32_T ) - ( int32_T ) ( uint32_T ) - tmp_p : ( uint32_T
) tmp_p ; r = ( int32_T ) ( tseed >> 16U ) ; t = ( int32_T ) ( tseed & 32768U
) ; tseed = ( ( ( ( tseed - ( ( uint32_T ) r << 16U ) ) + t ) << 16U ) + t )
+ r ; if ( tseed < 1U ) { tseed = 1144108930U ; } else { if ( tseed >
2147483646U ) { tseed = 2147483646U ; } } rtDW . j05iyjbst5 [ 0 ] = tseed ;
rtDW . kqelrtffwz [ 0 ] = rt_nrand_Upu32_Yd_f_pw_snf ( & rtDW . j05iyjbst5 [
0 ] ) * rtP . RandomNumber_StdDev_fffkyslftj [ 0 ] + rtP .
RandomNumber_Mean_jleeh3nxmy ; rtX . jc4nrgnm2y [ 0 ] = rtP . data .
gyroscope . b0 [ 0 ] ; tmp_p = muDoubleScalarFloor ( rtP .
RandomNumber_Seed_g3q3oeokt3 [ 1 ] ) ; if ( muDoubleScalarIsNaN ( tmp_p ) ||
muDoubleScalarIsInf ( tmp_p ) ) { tmp_p = 0.0 ; } else { tmp_p =
muDoubleScalarRem ( tmp_p , 4.294967296E+9 ) ; } tseed = tmp_p < 0.0 ? (
uint32_T ) - ( int32_T ) ( uint32_T ) - tmp_p : ( uint32_T ) tmp_p ; r = (
int32_T ) ( tseed >> 16U ) ; t = ( int32_T ) ( tseed & 32768U ) ; tseed = ( (
( ( tseed - ( ( uint32_T ) r << 16U ) ) + t ) << 16U ) + t ) + r ; if ( tseed
< 1U ) { tseed = 1144108930U ; } else { if ( tseed > 2147483646U ) { tseed =
2147483646U ; } } rtDW . j05iyjbst5 [ 1 ] = tseed ; rtDW . kqelrtffwz [ 1 ] =
rt_nrand_Upu32_Yd_f_pw_snf ( & rtDW . j05iyjbst5 [ 1 ] ) * rtP .
RandomNumber_StdDev_fffkyslftj [ 1 ] + rtP . RandomNumber_Mean_jleeh3nxmy ;
rtX . jc4nrgnm2y [ 1 ] = rtP . data . gyroscope . b0 [ 1 ] ; tmp_p =
muDoubleScalarFloor ( rtP . RandomNumber_Seed_g3q3oeokt3 [ 2 ] ) ; if (
muDoubleScalarIsNaN ( tmp_p ) || muDoubleScalarIsInf ( tmp_p ) ) { tmp_p =
0.0 ; } else { tmp_p = muDoubleScalarRem ( tmp_p , 4.294967296E+9 ) ; } tseed
= tmp_p < 0.0 ? ( uint32_T ) - ( int32_T ) ( uint32_T ) - tmp_p : ( uint32_T
) tmp_p ; r = ( int32_T ) ( tseed >> 16U ) ; t = ( int32_T ) ( tseed & 32768U
) ; tseed = ( ( ( ( tseed - ( ( uint32_T ) r << 16U ) ) + t ) << 16U ) + t )
+ r ; if ( tseed < 1U ) { tseed = 1144108930U ; } else { if ( tseed >
2147483646U ) { tseed = 2147483646U ; } } rtDW . j05iyjbst5 [ 2 ] = tseed ;
rtDW . kqelrtffwz [ 2 ] = rt_nrand_Upu32_Yd_f_pw_snf ( & rtDW . j05iyjbst5 [
2 ] ) * rtP . RandomNumber_StdDev_fffkyslftj [ 2 ] + rtP .
RandomNumber_Mean_jleeh3nxmy ; rtX . jc4nrgnm2y [ 2 ] = rtP . data .
gyroscope . b0 [ 2 ] ; tmp_p = muDoubleScalarFloor ( rtP .
RandomNumber1_Seed_ow4kdudteh [ 0 ] ) ; if ( muDoubleScalarIsNaN ( tmp_p ) ||
muDoubleScalarIsInf ( tmp_p ) ) { tmp_p = 0.0 ; } else { tmp_p =
muDoubleScalarRem ( tmp_p , 4.294967296E+9 ) ; } tseed = tmp_p < 0.0 ? (
uint32_T ) - ( int32_T ) ( uint32_T ) - tmp_p : ( uint32_T ) tmp_p ; r = (
int32_T ) ( tseed >> 16U ) ; t = ( int32_T ) ( tseed & 32768U ) ; tseed = ( (
( ( tseed - ( ( uint32_T ) r << 16U ) ) + t ) << 16U ) + t ) + r ; if ( tseed
< 1U ) { tseed = 1144108930U ; } else { if ( tseed > 2147483646U ) { tseed =
2147483646U ; } } rtDW . mgrhzfgfnu [ 0 ] = tseed ; rtDW . gubqowflu1 [ 0 ] =
rt_nrand_Upu32_Yd_f_pw_snf ( & rtDW . mgrhzfgfnu [ 0 ] ) * rtP .
RandomNumber1_StdDev_lesrfxv0lg [ 0 ] + rtP . RandomNumber1_Mean_dlj5kv1b54 ;
tmp_p = muDoubleScalarFloor ( rtP . RandomNumber1_Seed_ow4kdudteh [ 1 ] ) ;
if ( muDoubleScalarIsNaN ( tmp_p ) || muDoubleScalarIsInf ( tmp_p ) ) { tmp_p
= 0.0 ; } else { tmp_p = muDoubleScalarRem ( tmp_p , 4.294967296E+9 ) ; }
tseed = tmp_p < 0.0 ? ( uint32_T ) - ( int32_T ) ( uint32_T ) - tmp_p : (
uint32_T ) tmp_p ; r = ( int32_T ) ( tseed >> 16U ) ; t = ( int32_T ) ( tseed
& 32768U ) ; tseed = ( ( ( ( tseed - ( ( uint32_T ) r << 16U ) ) + t ) << 16U
) + t ) + r ; if ( tseed < 1U ) { tseed = 1144108930U ; } else { if ( tseed >
2147483646U ) { tseed = 2147483646U ; } } rtDW . mgrhzfgfnu [ 1 ] = tseed ;
rtDW . gubqowflu1 [ 1 ] = rt_nrand_Upu32_Yd_f_pw_snf ( & rtDW . mgrhzfgfnu [
1 ] ) * rtP . RandomNumber1_StdDev_lesrfxv0lg [ 1 ] + rtP .
RandomNumber1_Mean_dlj5kv1b54 ; tmp_p = muDoubleScalarFloor ( rtP .
RandomNumber1_Seed_ow4kdudteh [ 2 ] ) ; if ( muDoubleScalarIsNaN ( tmp_p ) ||
muDoubleScalarIsInf ( tmp_p ) ) { tmp_p = 0.0 ; } else { tmp_p =
muDoubleScalarRem ( tmp_p , 4.294967296E+9 ) ; } tseed = tmp_p < 0.0 ? (
uint32_T ) - ( int32_T ) ( uint32_T ) - tmp_p : ( uint32_T ) tmp_p ; r = (
int32_T ) ( tseed >> 16U ) ; t = ( int32_T ) ( tseed & 32768U ) ; tseed = ( (
( ( tseed - ( ( uint32_T ) r << 16U ) ) + t ) << 16U ) + t ) + r ; if ( tseed
< 1U ) { tseed = 1144108930U ; } else { if ( tseed > 2147483646U ) { tseed =
2147483646U ; } } rtDW . mgrhzfgfnu [ 2 ] = tseed ; rtDW . gubqowflu1 [ 2 ] =
rt_nrand_Upu32_Yd_f_pw_snf ( & rtDW . mgrhzfgfnu [ 2 ] ) * rtP .
RandomNumber1_StdDev_lesrfxv0lg [ 2 ] + rtP . RandomNumber1_Mean_dlj5kv1b54 ;
} void MdlStart ( void ) { { bool externalInputIsInDatasetFormat = false ;
void * pISigstreamManager = rt_GetISigstreamManager ( rtS ) ;
rtwISigstreamManagerGetInputIsInDatasetFormat ( pISigstreamManager , &
externalInputIsInDatasetFormat ) ; if ( externalInputIsInDatasetFormat ) { }
} rtB . jx5wap4com [ 0 ] = rtP . data . gyroscope . wObs0 [ 0 ] ; rtB .
jx5wap4com [ 1 ] = rtP . data . gyroscope . wObs0 [ 1 ] ; rtB . jx5wap4com [
2 ] = rtP . data . gyroscope . wObs0 [ 2 ] ;
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ;
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; rtDW . e4nx2k2d02 = - 1
; MdlInitialize ( ) ; } void MdlOutputs ( int_T tid ) { real_T boled1btc5 [ 3
] ; real_T hft4t5xobc [ 12 ] ; real_T jknin2l2mv [ 12 ] ; real_T ABL [ 9 ] ;
real_T U [ 9 ] ; real_T U_p [ 9 ] ; real_T V [ 9 ] ; real_T lu5esjsqx5 [ 4 ]
; real_T g0tgocacx1 [ 3 ] ; real_T m2cindee24 [ 3 ] ; real_T mVers [ 3 ] ;
real_T mfyhp04vud [ 3 ] ; real_T rSun [ 3 ] ; real_T tmp [ 3 ] ; real_T tmp_p
[ 3 ] ; real_T vRel [ 3 ] ; real_T Ki ; real_T absxk ; real_T bh5qcdfxpv ;
real_T gyptrdgv1o ; real_T kjselhlkqt ; real_T kjselhlkqt_idx_2 ; real_T t ;
real_T theta ; real_T * bxthjijgs5_p ; real_T * fctff10v4w_p ; int32_T r1 ;
int32_T r2 ; int32_T r3 ; int32_T rtemp ; int8_T rtAction ; int8_T
rtPrevAction ; boolean_T p ; srClearBC ( rtDW . bt5mj1ckkg ) ; srClearBC (
rtDW . mgkojscrve ) ; memcpy ( & rtB . haaoe3krmo [ 0 ] , & rtX . ouapiys3qq
[ 0 ] , 9U * sizeof ( real_T ) ) ; for ( r3 = 0 ; r3 < 3 ; r3 ++ ) { for ( r2
= 0 ; r2 < 3 ; r2 ++ ) { U [ r3 + 3 * r2 ] = 0.0 ; U [ r3 + 3 * r2 ] += rtB .
haaoe3krmo [ r3 ] * rtB . haaoe3krmo [ r2 ] ; U [ r3 + 3 * r2 ] += rtB .
haaoe3krmo [ r3 + 3 ] * rtB . haaoe3krmo [ r2 + 3 ] ; U [ r3 + 3 * r2 ] +=
rtB . haaoe3krmo [ r3 + 6 ] * rtB . haaoe3krmo [ r2 + 6 ] ; } for ( r2 = 0 ;
r2 < 3 ; r2 ++ ) { rtB . fd3qlfq0pf [ r3 + 3 * r2 ] = rtB . haaoe3krmo [ 3 *
r2 + r3 ] * 3.0 / 2.0 - ( ( rtB . haaoe3krmo [ 3 * r2 + 1 ] * U [ r3 + 3 ] +
rtB . haaoe3krmo [ 3 * r2 ] * U [ r3 ] ) + rtB . haaoe3krmo [ 3 * r2 + 2 ] *
U [ r3 + 6 ] ) / 2.0 ; } } rtB . izl1q5sazi = rtX . kjairk4b1p ; nvfofocjrz (
rtP . data . orbit . a , rtP . data . orbit . e , rtP . data . orbit . i ,
rtP . data . orbit . OM , rtP . data . orbit . om , rtB . izl1q5sazi , & rtB
. hid2a3ighm ) ; hxg1cub2fg ( rtB . hid2a3ighm . nmcsp5dcxo , rtB .
izl1q5sazi , & rtB . nzapizli54 ) ; for ( r3 = 0 ; r3 < 3 ; r3 ++ ) { for (
r2 = 0 ; r2 < 3 ; r2 ++ ) { ABL [ r3 + 3 * r2 ] = 0.0 ; ABL [ r3 + 3 * r2 ]
+= rtB . fd3qlfq0pf [ r3 ] * rtB . nzapizli54 . fws4iwogpu [ r2 ] ; ABL [ r3
+ 3 * r2 ] += rtB . fd3qlfq0pf [ r3 + 3 ] * rtB . nzapizli54 . fws4iwogpu [
r2 + 3 ] ; ABL [ r3 + 3 * r2 ] += rtB . fd3qlfq0pf [ r3 + 6 ] * rtB .
nzapizli54 . fws4iwogpu [ r2 + 6 ] ; } } rtB . hpj2uj2i4a [ 0 ] = ABL [ 0 ] ;
rtB . hpj2uj2i4a [ 0 ] = 57.295779513082323 * muDoubleScalarAcos ( rtB .
hpj2uj2i4a [ 0 ] ) ; rtB . hpj2uj2i4a [ 1 ] = ABL [ 4 ] ; rtB . hpj2uj2i4a [
1 ] = 57.295779513082323 * muDoubleScalarAcos ( rtB . hpj2uj2i4a [ 1 ] ) ;
rtB . hpj2uj2i4a [ 2 ] = ABL [ 8 ] ; rtB . hpj2uj2i4a [ 2 ] =
57.295779513082323 * muDoubleScalarAcos ( rtB . hpj2uj2i4a [ 2 ] ) ; rtB .
p51cv010io [ 0 ] = rtX . lutbl3ejqb [ 0 ] ; rtB . p51cv010io [ 1 ] = rtX .
lutbl3ejqb [ 1 ] ; rtB . p51cv010io [ 2 ] = rtX . lutbl3ejqb [ 2 ] ;
p54msx4qks ( rtB . hid2a3ighm . a4etz1spm4 , rtP . data . sc . inertiaMatrix
, rtB . fd3qlfq0pf , rtB . nzapizli54 . fws4iwogpu , & rtB . mssjub5nr2 ) ;
bh5qcdfxpv = ssGetT ( rtS ) ; mVers [ 0 ] = muDoubleScalarCos (
7.2921148843226185E-5 * bh5qcdfxpv ) * 0.19936793441719716 ; mVers [ 1 ] =
muDoubleScalarSin ( 7.2921148843226185E-5 * bh5qcdfxpv ) *
0.19936793441719716 ; absxk = pke5l1lpzc ( rtB . hid2a3ighm . a4etz1spm4 ) ;
mfyhp04vud [ 0 ] = rtB . hid2a3ighm . a4etz1spm4 [ 0 ] / absxk ; mfyhp04vud [
1 ] = rtB . hid2a3ighm . a4etz1spm4 [ 1 ] / absxk ; mfyhp04vud [ 2 ] = rtB .
hid2a3ighm . a4etz1spm4 [ 2 ] / absxk ; theta = ( ( mVers [ 0 ] * mfyhp04vud
[ 0 ] + mVers [ 1 ] * mfyhp04vud [ 1 ] ) + 0.97992470462082959 * mfyhp04vud [
2 ] ) * 3.0 ; Ki = 2.5859767437900247E+11 / muDoubleScalarPower ( pke5l1lpzc
( rtB . hid2a3ighm . a4etz1spm4 ) , 3.0 ) * 3.0115258673967919E-5 ;
mfyhp04vud [ 0 ] = ( theta * mfyhp04vud [ 0 ] - mVers [ 0 ] ) * Ki ;
mfyhp04vud [ 1 ] = ( theta * mfyhp04vud [ 1 ] - mVers [ 1 ] ) * Ki ;
gyptrdgv1o = ( theta * mfyhp04vud [ 2 ] - 0.97992470462082959 ) * Ki ;
mfyhp04vud [ 2 ] = gyptrdgv1o ; for ( r3 = 0 ; r3 < 3 ; r3 ++ ) { boled1btc5
[ r3 ] = 0.0 ; boled1btc5 [ r3 ] += rtB . fd3qlfq0pf [ r3 ] * mfyhp04vud [ 0
] ; boled1btc5 [ r3 ] += rtB . fd3qlfq0pf [ r3 + 3 ] * mfyhp04vud [ 1 ] ;
boled1btc5 [ r3 ] += rtB . fd3qlfq0pf [ r3 + 6 ] * gyptrdgv1o ; } hsoam3rxzy
( boled1btc5 , rtP . data . magneticTorque . m , & rtB . arbgebpnzf ) ;
bh5qcdfxpv = ssGetT ( rtS ) ; rSun [ 0 ] = muDoubleScalarCos (
1.9923849908611065E-7 * bh5qcdfxpv ) * 1.496E+8 ; rSun [ 1 ] =
muDoubleScalarSin ( 1.9923849908611065E-7 * bh5qcdfxpv ) *
0.91740769935748834 * 1.496E+8 ; rSun [ 2 ] = muDoubleScalarSin (
1.9923849908611065E-7 * bh5qcdfxpv ) * 0.39794863130761032 * 1.496E+8 ; absxk
= pke5l1lpzc ( rSun ) ; for ( r3 = 0 ; r3 < 3 ; r3 ++ ) { mVers [ r3 ] = ( (
rtB . fd3qlfq0pf [ r3 + 3 ] * rSun [ 1 ] + rtB . fd3qlfq0pf [ r3 ] * rSun [ 0
] ) + rtB . fd3qlfq0pf [ r3 + 6 ] * rSun [ 2 ] ) / absxk ; } g0tgocacx1 [ 0 ]
= 0.0 ; g0tgocacx1 [ 1 ] = 0.0 ; g0tgocacx1 [ 2 ] = 0.0 ; if ( ! (
muDoubleScalarAcos ( ( ( rSun [ 0 ] * rtB . hid2a3ighm . a4etz1spm4 [ 0 ] +
rSun [ 1 ] * rtB . hid2a3ighm . a4etz1spm4 [ 1 ] ) + rSun [ 2 ] * rtB .
hid2a3ighm . a4etz1spm4 [ 2 ] ) / pke5l1lpzc ( rSun ) / pke5l1lpzc ( rtB .
hid2a3ighm . a4etz1spm4 ) ) > muDoubleScalarAcos ( 6378.0 / pke5l1lpzc ( rtB
. hid2a3ighm . a4etz1spm4 ) ) + muDoubleScalarAcos ( 6378.0 / pke5l1lpzc (
rSun ) ) ) ) { for ( r2 = 0 ; r2 < 14 ; r2 ++ ) { Ki = ( rtP . data . SRP .
NBMat [ 3 * r2 + 1 ] * mVers [ 1 ] + rtP . data . SRP . NBMat [ 3 * r2 ] *
mVers [ 0 ] ) + rtP . data . SRP . NBMat [ 3 * r2 + 2 ] * mVers [ 2 ] ; if (
Ki > 0.0 ) { theta = 2.0 * rtP . data . SRP . rhoS [ r2 ] * Ki +
0.66666666666666663 * rtP . data . SRP . rhoD [ r2 ] ; Ki *= - 6.938E-6 * rtP
. data . SRP . aSurf [ r2 ] ; absxk = 1.0 - rtP . data . SRP . rhoS [ r2 ] ;
rSun [ 0 ] = ( rtP . data . SRP . NBMat [ 3 * r2 ] * theta + absxk * mVers [
0 ] ) * Ki ; rSun [ 1 ] = ( rtP . data . SRP . NBMat [ 3 * r2 + 1 ] * theta +
absxk * mVers [ 1 ] ) * Ki ; rSun [ 2 ] = ( rtP . data . SRP . NBMat [ 3 * r2
+ 2 ] * theta + absxk * mVers [ 2 ] ) * Ki ; kjselhlkqt = g0tgocacx1 [ 0 ] ;
bh5qcdfxpv = g0tgocacx1 [ 1 ] ; absxk = g0tgocacx1 [ 2 ] ; g0tgocacx1 [ 0 ] =
( rtP . data . SRP . rSurf [ 3 * r2 + 1 ] * rSun [ 2 ] - rtP . data . SRP .
rSurf [ 3 * r2 + 2 ] * rSun [ 1 ] ) + kjselhlkqt ; g0tgocacx1 [ 1 ] = ( rtP .
data . SRP . rSurf [ 3 * r2 + 2 ] * rSun [ 0 ] - rtP . data . SRP . rSurf [ 3
* r2 ] * rSun [ 2 ] ) + bh5qcdfxpv ; g0tgocacx1 [ 2 ] = ( rtP . data . SRP .
rSurf [ 3 * r2 ] * rSun [ 1 ] - rtP . data . SRP . rSurf [ 3 * r2 + 1 ] *
rSun [ 0 ] ) + absxk ; } } } kjselhlkqt = rtB . hid2a3ighm . a4etz1spm4 [ 0 ]
* 1000.0 * 7.2921E-5 + rtB . hid2a3ighm . edrpaasu4j [ 0 ] * 1000.0 ;
bh5qcdfxpv = rtB . hid2a3ighm . edrpaasu4j [ 1 ] * 1000.0 - rtB . hid2a3ighm
. a4etz1spm4 [ 1 ] * 1000.0 * 7.2921E-5 ; absxk = rtB . hid2a3ighm .
edrpaasu4j [ 2 ] * 1000.0 ; for ( r2 = 0 ; r2 < 3 ; r2 ++ ) { m2cindee24 [ r2
] = 0.0 ; vRel [ r2 ] = rtB . fd3qlfq0pf [ r2 + 6 ] * absxk + ( rtB .
fd3qlfq0pf [ r2 + 3 ] * bh5qcdfxpv + rtB . fd3qlfq0pf [ r2 ] * kjselhlkqt ) ;
} absxk = pke5l1lpzc ( vRel ) ; for ( r2 = 0 ; r2 < 14 ; r2 ++ ) { Ki = ( rtP
. data . drag . NBMat [ 3 * r2 + 1 ] * ( vRel [ 1 ] / absxk ) + vRel [ 0 ] /
absxk * rtP . data . drag . NBMat [ 3 * r2 ] ) + rtP . data . drag . NBMat [
3 * r2 + 2 ] * ( vRel [ 2 ] / absxk ) ; if ( Ki > 0.0 ) { theta = - 0.5 * rtP
. data . drag . rho * rtP . data . drag . cd * pke5l1lpzc ( vRel ) ; rSun [ 0
] = theta * vRel [ 0 ] * rtP . data . drag . aSurf [ r2 ] * Ki ; rSun [ 1 ] =
theta * vRel [ 1 ] * rtP . data . drag . aSurf [ r2 ] * Ki ; rSun [ 2 ] =
theta * vRel [ 2 ] * rtP . data . drag . aSurf [ r2 ] * Ki ; theta =
m2cindee24 [ 0 ] ; Ki = m2cindee24 [ 1 ] ; t = m2cindee24 [ 2 ] ; m2cindee24
[ 0 ] = ( rtP . data . drag . rSurf [ 3 * r2 + 1 ] * rSun [ 2 ] - rtP . data
. drag . rSurf [ 3 * r2 + 2 ] * rSun [ 1 ] ) + theta ; m2cindee24 [ 1 ] = (
rtP . data . drag . rSurf [ 3 * r2 + 2 ] * rSun [ 0 ] - rtP . data . drag .
rSurf [ 3 * r2 ] * rSun [ 2 ] ) + Ki ; m2cindee24 [ 2 ] = ( rtP . data . drag
. rSurf [ 3 * r2 ] * rSun [ 1 ] - rtP . data . drag . rSurf [ 3 * r2 + 1 ] *
rSun [ 0 ] ) + t ; } } rtB . jpaphc4vt2 [ 0 ] = ( ( rtB . mssjub5nr2 .
fyfzf3djiy [ 0 ] + rtB . arbgebpnzf . ekyf2ft5xv [ 0 ] ) + g0tgocacx1 [ 0 ] )
+ m2cindee24 [ 0 ] ; rtB . jpaphc4vt2 [ 1 ] = ( ( rtB . mssjub5nr2 .
fyfzf3djiy [ 1 ] + rtB . arbgebpnzf . ekyf2ft5xv [ 1 ] ) + g0tgocacx1 [ 1 ] )
+ m2cindee24 [ 1 ] ; rtB . jpaphc4vt2 [ 2 ] = ( ( rtB . mssjub5nr2 .
fyfzf3djiy [ 2 ] + rtB . arbgebpnzf . ekyf2ft5xv [ 2 ] ) + g0tgocacx1 [ 2 ] )
+ m2cindee24 [ 2 ] ; mzxxcjchg3 ( rtB . hid2a3ighm . a4etz1spm4 , rtB .
hid2a3ighm . edrpaasu4j , & rtB . eje25gfouo ) ; if ( ssIsSampleHit ( rtS , 1
, 0 ) ) { rtB . nxkkb43lmg [ 0 ] = rtDW . n1mf5f1loj [ 0 ] ; rtB . nxkkb43lmg
[ 1 ] = rtDW . n1mf5f1loj [ 1 ] ; rtB . nxkkb43lmg [ 2 ] = rtDW . n1mf5f1loj
[ 2 ] ; } rtB . kj0hrlovtd [ 0 ] = boled1btc5 [ 0 ] + rtB . nxkkb43lmg [ 0 ]
; rtB . kj0hrlovtd [ 1 ] = boled1btc5 [ 1 ] + rtB . nxkkb43lmg [ 1 ] ; rtB .
kj0hrlovtd [ 2 ] = boled1btc5 [ 2 ] + rtB . nxkkb43lmg [ 2 ] ; if (
ssIsSampleHit ( rtS , 1 , 0 ) ) { for ( r3 = 0 ; r3 < 3 ; r3 ++ ) { rtB .
jnakfltztn [ r3 ] = 0.0 ; rtB . jnakfltztn [ r3 ] += rtP . data .
magnetometer . nonOrthogonality [ r3 ] * rtB . kj0hrlovtd [ 0 ] ; rtB .
jnakfltztn [ r3 ] += rtP . data . magnetometer . nonOrthogonality [ r3 + 3 ]
* rtB . kj0hrlovtd [ 1 ] ; rtB . jnakfltztn [ r3 ] += rtP . data .
magnetometer . nonOrthogonality [ r3 + 6 ] * rtB . kj0hrlovtd [ 2 ] ; } } if
( ssIsMajorTimeStep ( rtS ) ) { if ( rtDW . h5pffuqljc != 0 ) { rtX .
ht1cmxxnsq [ 0 ] = rtB . jx5wap4com [ 0 ] ; rtX . ht1cmxxnsq [ 1 ] = rtB .
jx5wap4com [ 1 ] ; rtX . ht1cmxxnsq [ 2 ] = rtB . jx5wap4com [ 2 ] ; } rtB .
ehirxkx1np [ 0 ] = rtX . ht1cmxxnsq [ 0 ] ; rtB . ehirxkx1np [ 1 ] = rtX .
ht1cmxxnsq [ 1 ] ; rtB . ehirxkx1np [ 2 ] = rtX . ht1cmxxnsq [ 2 ] ; } else {
rtB . ehirxkx1np [ 0 ] = rtX . ht1cmxxnsq [ 0 ] ; rtB . ehirxkx1np [ 1 ] =
rtX . ht1cmxxnsq [ 1 ] ; rtB . ehirxkx1np [ 2 ] = rtX . ht1cmxxnsq [ 2 ] ; }
for ( r3 = 0 ; r3 < 3 ; r3 ++ ) { tmp [ r3 ] = rtP . data . starSensor . ABS
[ 3 * r3 + 2 ] * mVers [ 2 ] + ( rtP . data . starSensor . ABS [ 3 * r3 + 1 ]
* mVers [ 1 ] + rtP . data . starSensor . ABS [ 3 * r3 ] * mVers [ 0 ] ) ; }
rtB . mkszl352m3 = ( muDoubleScalarAcos ( tmp [ 2 ] ) < rtP . data .
starSensor . FOV / 2.0 ) ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { lu5esjsqx5
[ 0 ] = rtDW . ofluvtqt5p [ 0 ] ; lu5esjsqx5 [ 1 ] = rtDW . ofluvtqt5p [ 1 ]
; lu5esjsqx5 [ 2 ] = rtDW . ofluvtqt5p [ 2 ] ; lu5esjsqx5 [ 3 ] = rtDW .
ofluvtqt5p [ 3 ] ; fctff10v4w_p = & rtDW . j4zaai5afv [ 0 ] ; bxthjijgs5_p =
& rtDW . o221ifynn5 [ 0 ] ; for ( r3 = 0 ; r3 < 3 ; r3 ++ ) { for ( r2 = 0 ;
r2 < 3 ; r2 ++ ) { ABL [ r3 + 3 * r2 ] = 0.0 ; ABL [ r3 + 3 * r2 ] += rtB .
fd3qlfq0pf [ 3 * r3 ] * rtP . data . starSensor . ABS [ 3 * r2 ] ; ABL [ r3 +
3 * r2 ] += rtB . fd3qlfq0pf [ 3 * r3 + 1 ] * rtP . data . starSensor . ABS [
3 * r2 + 1 ] ; ABL [ r3 + 3 * r2 ] += rtB . fd3qlfq0pf [ 3 * r3 + 2 ] * rtP .
data . starSensor . ABS [ 3 * r2 + 2 ] ; } } for ( r2 = 0 ; r2 < 4 ; r2 ++ )
{ kjselhlkqt = lu5esjsqx5 [ r2 ] ; theta = bxthjijgs5_p [ ( ( r2 + 1 ) << 1 )
- 2 ] * rtP . data . starSensor . FOV / 2.0 ; bh5qcdfxpv = bxthjijgs5_p [ ( (
r2 + 1 ) << 1 ) - 1 ] * 3.1415926535897931 / 2.0 ; mVers [ 0 ] =
muDoubleScalarSin ( bh5qcdfxpv ) * muDoubleScalarCos ( theta ) ; mVers [ 1 ]
= muDoubleScalarSin ( bh5qcdfxpv ) * muDoubleScalarSin ( theta ) ; mVers [ 2
] = muDoubleScalarCos ( bh5qcdfxpv ) ; bh5qcdfxpv = fctff10v4w_p [ ( ( r2 + 1
) << 1 ) - 2 ] ; theta = fctff10v4w_p [ ( ( r2 + 1 ) << 1 ) - 1 ] ; U [ 0 ] =
muDoubleScalarCos ( kjselhlkqt ) * muDoubleScalarCos ( theta ) ; U [ 3 ] =
muDoubleScalarCos ( kjselhlkqt ) * muDoubleScalarSin ( bh5qcdfxpv ) *
muDoubleScalarSin ( theta ) + muDoubleScalarCos ( bh5qcdfxpv ) *
muDoubleScalarSin ( kjselhlkqt ) ; U [ 6 ] = muDoubleScalarSin ( bh5qcdfxpv )
* muDoubleScalarSin ( kjselhlkqt ) - muDoubleScalarCos ( bh5qcdfxpv ) *
muDoubleScalarCos ( kjselhlkqt ) * muDoubleScalarSin ( theta ) ; U [ 1 ] = -
muDoubleScalarCos ( theta ) * muDoubleScalarSin ( kjselhlkqt ) ; U [ 4 ] =
muDoubleScalarCos ( bh5qcdfxpv ) * muDoubleScalarCos ( kjselhlkqt ) -
muDoubleScalarSin ( bh5qcdfxpv ) * muDoubleScalarSin ( kjselhlkqt ) *
muDoubleScalarSin ( theta ) ; U [ 7 ] = muDoubleScalarCos ( bh5qcdfxpv ) *
muDoubleScalarSin ( kjselhlkqt ) * muDoubleScalarSin ( theta ) +
muDoubleScalarCos ( kjselhlkqt ) * muDoubleScalarSin ( bh5qcdfxpv ) ; U [ 2 ]
= muDoubleScalarSin ( theta ) ; U [ 5 ] = - muDoubleScalarCos ( theta ) *
muDoubleScalarSin ( bh5qcdfxpv ) ; U [ 8 ] = muDoubleScalarCos ( bh5qcdfxpv )
* muDoubleScalarCos ( theta ) ; for ( r3 = 0 ; r3 < 3 ; r3 ++ ) { tmp [ r3 ]
= U [ r3 + 6 ] * mVers [ 2 ] + ( U [ r3 + 3 ] * mVers [ 1 ] + U [ r3 ] *
mVers [ 0 ] ) ; } for ( r3 = 0 ; r3 < 3 ; r3 ++ ) { hft4t5xobc [ r3 + 3 * r2
] = 0.0 ; jknin2l2mv [ r3 + 3 * r2 ] = 0.0 ; hft4t5xobc [ r3 + 3 * r2 ] +=
rtP . data . starSensor . ABS [ r3 ] * tmp [ 0 ] ; jknin2l2mv [ r3 + 3 * r2 ]
+= ABL [ r3 ] * mVers [ 0 ] ; hft4t5xobc [ r3 + 3 * r2 ] += rtP . data .
starSensor . ABS [ r3 + 3 ] * tmp [ 1 ] ; jknin2l2mv [ r3 + 3 * r2 ] += ABL [
r3 + 3 ] * mVers [ 1 ] ; hft4t5xobc [ r3 + 3 * r2 ] += rtP . data .
starSensor . ABS [ r3 + 6 ] * tmp [ 2 ] ; jknin2l2mv [ r3 + 3 * r2 ] += ABL [
r3 + 6 ] * mVers [ 2 ] ; } } memset ( & ABL [ 0 ] , 0 , 9U * sizeof ( real_T
) ) ; for ( r1 = 0 ; r1 < 4 ; r1 ++ ) { for ( r3 = 0 ; r3 < 3 ; r3 ++ ) { ABL
[ 3 * r3 ] += hft4t5xobc [ 3 * r1 ] * 0.25 * jknin2l2mv [ 3 * r1 + r3 ] ; ABL
[ 3 * r3 + 1 ] += hft4t5xobc [ 3 * r1 + 1 ] * 0.25 * jknin2l2mv [ 3 * r1 + r3
] ; ABL [ 3 * r3 + 2 ] += hft4t5xobc [ 3 * r1 + 2 ] * 0.25 * jknin2l2mv [ 3 *
r1 + r3 ] ; } } p = true ; for ( r1 = 0 ; r1 < 9 ; r1 ++ ) { kjselhlkqt = ABL
[ r1 ] ; if ( p && ( ( ! muDoubleScalarIsInf ( kjselhlkqt ) ) && ( !
muDoubleScalarIsNaN ( kjselhlkqt ) ) ) ) { } else { p = false ; } } if ( p )
{ o4vts0g5zg ( ABL , U , mVers , V ) ; } else { for ( r3 = 0 ; r3 < 9 ; r3 ++
) { U [ r3 ] = ( rtNaN ) ; V [ r3 ] = ( rtNaN ) ; } } memset ( & ABL [ 0 ] ,
0 , 9U * sizeof ( real_T ) ) ; ABL [ 0 ] = 1.0 ; ABL [ 4 ] = 1.0 ; ABL [ 8 ]
= kdmv5ezpwv ( U ) * kdmv5ezpwv ( V ) ; for ( r3 = 0 ; r3 < 3 ; r3 ++ ) { for
( r2 = 0 ; r2 < 3 ; r2 ++ ) { U_p [ r3 + 3 * r2 ] = 0.0 ; U_p [ r3 + 3 * r2 ]
+= ABL [ 3 * r2 ] * U [ r3 ] ; U_p [ r3 + 3 * r2 ] += ABL [ 3 * r2 + 1 ] * U
[ r3 + 3 ] ; U_p [ r3 + 3 * r2 ] += ABL [ 3 * r2 + 2 ] * U [ r3 + 6 ] ; } for
( r2 = 0 ; r2 < 3 ; r2 ++ ) { rtB . d155gslfmi [ r3 + 3 * r2 ] = 0.0 ; rtB .
d155gslfmi [ r3 + 3 * r2 ] += U_p [ r3 ] * V [ r2 ] ; rtB . d155gslfmi [ r3 +
3 * r2 ] += U_p [ r3 + 3 ] * V [ r2 + 3 ] ; rtB . d155gslfmi [ r3 + 3 * r2 ]
+= U_p [ r3 + 6 ] * V [ r2 + 6 ] ; } } } if ( ssIsMajorTimeStep ( rtS ) ) { p
= ( ( ( rtPrevZCX . dwuwbqsvq3 == POS_ZCSIG ) != ( int32_T ) rtB . mkszl352m3
) && ( rtPrevZCX . dwuwbqsvq3 != UNINITIALIZED_ZCSIG ) ) ; rtPrevZCX .
dwuwbqsvq3 = rtB . mkszl352m3 ; if ( p || ( rtDW . mstj5paygm != 0 ) ) {
memcpy ( & rtX . fnoi12dssm [ 0 ] , & rtB . d155gslfmi [ 0 ] , 9U * sizeof (
real_T ) ) ; ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; } memcpy (
& rtB . k0b2i5iiue [ 0 ] , & rtX . fnoi12dssm [ 0 ] , 9U * sizeof ( real_T )
) ; } else { memcpy ( & rtB . k0b2i5iiue [ 0 ] , & rtX . fnoi12dssm [ 0 ] ,
9U * sizeof ( real_T ) ) ; } rtPrevAction = rtDW . e4nx2k2d02 ; if (
ssIsMajorTimeStep ( rtS ) ) { rtAction = ( int8_T ) ! rtB . mkszl352m3 ; rtDW
. e4nx2k2d02 = rtAction ; } else { rtAction = rtDW . e4nx2k2d02 ; } if (
rtPrevAction != rtAction ) { switch ( rtPrevAction ) { case 0 :
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; break ; case 1 :
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; break ; } } switch (
rtAction ) { case 0 : if ( rtAction != rtPrevAction ) { if ( ssGetTaskTime (
rtS , 0 ) != ssGetTStart ( rtS ) ) {
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; } } memcpy ( & rtB .
fonazkfutz [ 0 ] , & rtB . k0b2i5iiue [ 0 ] , 9U * sizeof ( real_T ) ) ; if (
ssIsMajorTimeStep ( rtS ) ) { srUpdateBC ( rtDW . bt5mj1ckkg ) ; } break ;
case 1 : if ( rtAction != rtPrevAction ) { if ( ssGetTaskTime ( rtS , 0 ) !=
ssGetTStart ( rtS ) ) { ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ;
} } memcpy ( & rtB . fonazkfutz [ 0 ] , & rtB . d155gslfmi [ 0 ] , 9U *
sizeof ( real_T ) ) ; if ( ssIsMajorTimeStep ( rtS ) ) { srUpdateBC ( rtDW .
mgkojscrve ) ; } break ; } rtB . n4mzmf5vo5 = rtX . mnzw0suzs2 ; for ( r3 = 0
; r3 < 3 ; r3 ++ ) { m2cindee24 [ r3 ] = rtB . nzapizli54 . fws4iwogpu [ r3 +
6 ] * rtB . eje25gfouo . g540wbqcci [ 2 ] + ( rtB . nzapizli54 . fws4iwogpu [
r3 + 3 ] * rtB . eje25gfouo . g540wbqcci [ 1 ] + rtB . nzapizli54 .
fws4iwogpu [ r3 ] * rtB . eje25gfouo . g540wbqcci [ 0 ] ) ; } for ( r3 = 0 ;
r3 < 3 ; r3 ++ ) { for ( r2 = 0 ; r2 < 3 ; r2 ++ ) { ABL [ r3 + 3 * r2 ] =
0.0 ; ABL [ r3 + 3 * r2 ] += rtB . fonazkfutz [ r3 ] * rtB . nzapizli54 .
fws4iwogpu [ r2 ] ; ABL [ r3 + 3 * r2 ] += rtB . fonazkfutz [ r3 + 3 ] * rtB
. nzapizli54 . fws4iwogpu [ r2 + 3 ] ; ABL [ r3 + 3 * r2 ] += rtB .
fonazkfutz [ r3 + 6 ] * rtB . nzapizli54 . fws4iwogpu [ r2 + 6 ] ; } } for (
r3 = 0 ; r3 < 3 ; r3 ++ ) { kjselhlkqt = ABL [ r3 ] ; absxk = kjselhlkqt *
m2cindee24 [ 0 ] ; theta = kjselhlkqt * m2cindee24 [ 0 ] ; kjselhlkqt = ABL [
r3 + 3 ] ; absxk += kjselhlkqt * m2cindee24 [ 1 ] ; theta += kjselhlkqt *
m2cindee24 [ 1 ] ; kjselhlkqt = ABL [ r3 + 6 ] ; absxk += kjselhlkqt *
m2cindee24 [ 2 ] ; theta += kjselhlkqt * m2cindee24 [ 2 ] ; g0tgocacx1 [ r3 ]
= rtB . ehirxkx1np [ r3 ] - absxk ; mVers [ r3 ] = rtP . data . sc .
inertiaMatrix [ r3 + 6 ] * rtB . ehirxkx1np [ 2 ] + ( rtP . data . sc .
inertiaMatrix [ r3 + 3 ] * rtB . ehirxkx1np [ 1 ] + rtP . data . sc .
inertiaMatrix [ r3 ] * rtB . ehirxkx1np [ 0 ] ) ; rSun [ r3 ] = theta ; } tmp
[ 0 ] = ( ABL [ 7 ] - ABL [ 5 ] ) * rtP . data . pointing . kAE ; tmp [ 1 ] =
( ABL [ 2 ] - ABL [ 6 ] ) * rtP . data . pointing . kAE ; tmp [ 2 ] = ( ABL [
3 ] - ABL [ 1 ] ) * rtP . data . pointing . kAE ; tmp_p [ 0 ] = rtB .
ehirxkx1np [ 1 ] * mVers [ 2 ] - rtB . ehirxkx1np [ 2 ] * mVers [ 1 ] ; tmp_p
[ 1 ] = rtB . ehirxkx1np [ 2 ] * mVers [ 0 ] - rtB . ehirxkx1np [ 0 ] * mVers
[ 2 ] ; tmp_p [ 2 ] = rtB . ehirxkx1np [ 0 ] * mVers [ 1 ] - rtB . ehirxkx1np
[ 1 ] * mVers [ 0 ] ; kjselhlkqt = g0tgocacx1 [ 1 ] * rSun [ 2 ] - g0tgocacx1
[ 2 ] * rSun [ 1 ] ; bh5qcdfxpv = g0tgocacx1 [ 2 ] * rSun [ 0 ] - g0tgocacx1
[ 0 ] * rSun [ 2 ] ; kjselhlkqt_idx_2 = g0tgocacx1 [ 0 ] * rSun [ 1 ] -
g0tgocacx1 [ 1 ] * rSun [ 0 ] ; theta = 0.0 ; Ki = 3.3121686421112381E-170 ;
for ( r1 = 0 ; r1 < 3 ; r1 ++ ) { m2cindee24 [ r1 ] = ( ( - rtP . data .
pointing . kWE * g0tgocacx1 [ r1 ] - tmp [ r1 ] ) + tmp_p [ r1 ] ) - ( ( rtP
. data . sc . inertiaMatrix [ r1 + 3 ] * bh5qcdfxpv + rtP . data . sc .
inertiaMatrix [ r1 ] * kjselhlkqt ) + rtP . data . sc . inertiaMatrix [ r1 +
6 ] * kjselhlkqt_idx_2 ) ; mVers [ r1 ] = rtP . data . reactionWheel . axis [
r1 ] * rtB . n4mzmf5vo5 ; absxk = muDoubleScalarAbs ( rtB . jnakfltztn [ r1 ]
) ; if ( absxk > Ki ) { t = Ki / absxk ; theta = theta * t * t + 1.0 ; Ki =
absxk ; } else { t = absxk / Ki ; theta += t * t ; } } vRel [ 0 ] = ( rtB .
ehirxkx1np [ 1 ] * mVers [ 2 ] - rtB . ehirxkx1np [ 2 ] * mVers [ 1 ] ) +
m2cindee24 [ 0 ] ; vRel [ 1 ] = ( rtB . ehirxkx1np [ 2 ] * mVers [ 0 ] - rtB
. ehirxkx1np [ 0 ] * mVers [ 2 ] ) + m2cindee24 [ 1 ] ; vRel [ 2 ] = ( rtB .
ehirxkx1np [ 0 ] * mVers [ 1 ] - rtB . ehirxkx1np [ 1 ] * mVers [ 0 ] ) +
m2cindee24 [ 2 ] ; theta = Ki * muDoubleScalarSqrt ( theta ) ; bh5qcdfxpv =
theta * theta ; g0tgocacx1 [ 0 ] = muDoubleScalarMin ( muDoubleScalarMax ( (
rtB . jnakfltztn [ 1 ] * vRel [ 2 ] - rtB . jnakfltztn [ 2 ] * vRel [ 1 ] ) /
bh5qcdfxpv , - rtP . data . magnetorquer . DMax [ 0 ] ) , rtP . data .
magnetorquer . DMax [ 0 ] ) ; g0tgocacx1 [ 1 ] = muDoubleScalarMin (
muDoubleScalarMax ( ( rtB . jnakfltztn [ 2 ] * vRel [ 0 ] - rtB . jnakfltztn
[ 0 ] * vRel [ 2 ] ) / bh5qcdfxpv , - rtP . data . magnetorquer . DMax [ 1 ]
) , rtP . data . magnetorquer . DMax [ 1 ] ) ; kjselhlkqt = muDoubleScalarMin
( muDoubleScalarMax ( ( rtB . jnakfltztn [ 0 ] * vRel [ 1 ] - rtB .
jnakfltztn [ 1 ] * vRel [ 0 ] ) / bh5qcdfxpv , - rtP . data . magnetorquer .
DMax [ 2 ] ) , rtP . data . magnetorquer . DMax [ 2 ] ) ; theta = ( ( vRel [
0 ] - ( g0tgocacx1 [ 1 ] * rtB . jnakfltztn [ 2 ] - kjselhlkqt * rtB .
jnakfltztn [ 1 ] ) ) * rtP . data . reactionWheel . axis [ 0 ] + ( vRel [ 1 ]
- ( kjselhlkqt * rtB . jnakfltztn [ 0 ] - g0tgocacx1 [ 0 ] * rtB . jnakfltztn
[ 2 ] ) ) * rtP . data . reactionWheel . axis [ 1 ] ) + ( vRel [ 2 ] - (
g0tgocacx1 [ 0 ] * rtB . jnakfltztn [ 1 ] - g0tgocacx1 [ 1 ] * rtB .
jnakfltztn [ 0 ] ) ) * rtP . data . reactionWheel . axis [ 2 ] ; bh5qcdfxpv =
- theta ; if ( ( muDoubleScalarAbs ( rtB . n4mzmf5vo5 ) > rtP . data .
reactionWheel . hMax ) && ( - theta * rtB . n4mzmf5vo5 > 0.0 ) ) { bh5qcdfxpv
= 0.0 ; } if ( muDoubleScalarAbs ( bh5qcdfxpv ) > rtP . data . reactionWheel
. MMax ) { bh5qcdfxpv = muDoubleScalarSign ( bh5qcdfxpv ) * rtP . data .
reactionWheel . MMax ; } rtB . gkxr4i513p = bh5qcdfxpv ; mVers [ 0 ] = rtB .
n4mzmf5vo5 * rtP . data . reactionWheel . axis [ 0 ] ; rSun [ 0 ] = rtP .
data . reactionWheel . axis [ 0 ] * rtB . n4mzmf5vo5 ; mVers [ 1 ] = rtB .
n4mzmf5vo5 * rtP . data . reactionWheel . axis [ 1 ] ; rSun [ 1 ] = rtP .
data . reactionWheel . axis [ 1 ] * rtB . n4mzmf5vo5 ; mVers [ 2 ] = rtB .
n4mzmf5vo5 * rtP . data . reactionWheel . axis [ 2 ] ; rSun [ 2 ] = rtP .
data . reactionWheel . axis [ 2 ] * rtB . n4mzmf5vo5 ; rtB . d4wo1qk3qg [ 0 ]
= ( ( - ( rtB . p51cv010io [ 1 ] * rSun [ 2 ] - rtB . p51cv010io [ 2 ] * rSun
[ 1 ] ) - rtP . data . reactionWheel . axis [ 0 ] * rtB . gkxr4i513p ) + (
g0tgocacx1 [ 1 ] * boled1btc5 [ 2 ] - kjselhlkqt * boled1btc5 [ 1 ] ) ) + rtB
. jpaphc4vt2 [ 0 ] ; rtB . d4wo1qk3qg [ 1 ] = ( ( - ( rtB . p51cv010io [ 2 ]
* rSun [ 0 ] - rtB . p51cv010io [ 0 ] * rSun [ 2 ] ) - rtP . data .
reactionWheel . axis [ 1 ] * rtB . gkxr4i513p ) + ( kjselhlkqt * boled1btc5 [
0 ] - g0tgocacx1 [ 0 ] * boled1btc5 [ 2 ] ) ) + rtB . jpaphc4vt2 [ 1 ] ; rtB
. d4wo1qk3qg [ 2 ] = ( ( - ( rtB . p51cv010io [ 0 ] * rSun [ 1 ] - rtB .
p51cv010io [ 1 ] * rSun [ 0 ] ) - rtP . data . reactionWheel . axis [ 2 ] *
rtB . gkxr4i513p ) + ( g0tgocacx1 [ 0 ] * boled1btc5 [ 1 ] - g0tgocacx1 [ 1 ]
* boled1btc5 [ 0 ] ) ) + rtB . jpaphc4vt2 [ 2 ] ; rtB . n4ileghqyp = rtX .
bqjsimdqqc ; nvfofocjrz ( rtP . data . orbit . a , rtP . data . orbit . e ,
rtP . data . orbit . i , rtP . data . orbit . OM , rtP . data . orbit . om ,
rtB . n4ileghqyp , & rtB . ituo30pkvd ) ; hxg1cub2fg ( rtB . ituo30pkvd .
nmcsp5dcxo , rtB . n4ileghqyp , & rtB . lb5tuw34lz ) ; p54msx4qks ( rtB .
ituo30pkvd . a4etz1spm4 , rtP . data . sc . inertiaMatrix , rtB . fonazkfutz
, rtB . lb5tuw34lz . fws4iwogpu , & rtB . lqknz2kefj ) ; if ( ssIsSampleHit (
rtS , 1 , 0 ) ) { hsoam3rxzy ( rtB . jnakfltztn , rtP . data . magneticTorque
. m , & rtB . eagdjb5elr ) ; } theta = ssGetT ( rtS ) ; rSun [ 0 ] =
muDoubleScalarCos ( 1.9923849908611065E-7 * theta ) * 1.496E+8 ; rSun [ 1 ] =
muDoubleScalarSin ( 1.9923849908611065E-7 * theta ) * 0.91740769935748834 *
1.496E+8 ; rSun [ 2 ] = muDoubleScalarSin ( 1.9923849908611065E-7 * theta ) *
0.39794863130761032 * 1.496E+8 ; Ki = 3.3121686421112381E-170 ; absxk =
muDoubleScalarAbs ( rSun [ 0 ] ) ; if ( absxk > 3.3121686421112381E-170 ) {
theta = 1.0 ; Ki = absxk ; } else { t = absxk / 3.3121686421112381E-170 ;
theta = t * t ; } absxk = muDoubleScalarAbs ( rSun [ 1 ] ) ; if ( absxk > Ki
) { t = Ki / absxk ; theta = theta * t * t + 1.0 ; Ki = absxk ; } else { t =
absxk / Ki ; theta += t * t ; } absxk = muDoubleScalarAbs ( rSun [ 2 ] ) ; if
( absxk > Ki ) { t = Ki / absxk ; theta = theta * t * t + 1.0 ; Ki = absxk ;
} else { t = absxk / Ki ; theta += t * t ; } theta = Ki * muDoubleScalarSqrt
( theta ) ; rSun [ 0 ] /= theta ; rSun [ 1 ] /= theta ; theta = rSun [ 2 ] /
theta ; for ( r2 = 0 ; r2 < 3 ; r2 ++ ) { m2cindee24 [ r2 ] = 0.0 ; vRel [ r2
] = rtB . fonazkfutz [ r2 + 6 ] * theta + ( rtB . fonazkfutz [ r2 + 3 ] *
rSun [ 1 ] + rtB . fonazkfutz [ r2 ] * rSun [ 0 ] ) ; } for ( r2 = 0 ; r2 <
14 ; r2 ++ ) { Ki = ( rtP . data . SRP . NBMat [ 3 * r2 + 1 ] * vRel [ 1 ] +
rtP . data . SRP . NBMat [ 3 * r2 ] * vRel [ 0 ] ) + rtP . data . SRP . NBMat
[ 3 * r2 + 2 ] * vRel [ 2 ] ; if ( Ki > 0.0 ) { theta = 2.0 * rtP . data .
SRP . rhoS [ r2 ] * Ki + 0.66666666666666663 * rtP . data . SRP . rhoD [ r2 ]
; Ki *= - 6.938E-6 * rtP . data . SRP . aSurf [ r2 ] ; absxk = 1.0 - rtP .
data . SRP . rhoS [ r2 ] ; rSun [ 0 ] = ( rtP . data . SRP . NBMat [ 3 * r2 ]
* theta + absxk * vRel [ 0 ] ) * Ki ; rSun [ 1 ] = ( rtP . data . SRP . NBMat
[ 3 * r2 + 1 ] * theta + absxk * vRel [ 1 ] ) * Ki ; rSun [ 2 ] = ( rtP .
data . SRP . NBMat [ 3 * r2 + 2 ] * theta + absxk * vRel [ 2 ] ) * Ki ; theta
= m2cindee24 [ 0 ] ; Ki = m2cindee24 [ 1 ] ; t = m2cindee24 [ 2 ] ;
m2cindee24 [ 0 ] = ( rtP . data . SRP . rSurf [ 3 * r2 + 1 ] * rSun [ 2 ] -
rtP . data . SRP . rSurf [ 3 * r2 + 2 ] * rSun [ 1 ] ) + theta ; m2cindee24 [
1 ] = ( rtP . data . SRP . rSurf [ 3 * r2 + 2 ] * rSun [ 0 ] - rtP . data .
SRP . rSurf [ 3 * r2 ] * rSun [ 2 ] ) + Ki ; m2cindee24 [ 2 ] = ( rtP . data
. SRP . rSurf [ 3 * r2 ] * rSun [ 1 ] - rtP . data . SRP . rSurf [ 3 * r2 + 1
] * rSun [ 0 ] ) + t ; } } rtB . p0sytp1tyb [ 0 ] = ( rtB . lqknz2kefj .
fyfzf3djiy [ 0 ] + rtB . eagdjb5elr . ekyf2ft5xv [ 0 ] ) + m2cindee24 [ 0 ] ;
rtB . p0sytp1tyb [ 1 ] = ( rtB . lqknz2kefj . fyfzf3djiy [ 1 ] + rtB .
eagdjb5elr . ekyf2ft5xv [ 1 ] ) + m2cindee24 [ 1 ] ; rtB . p0sytp1tyb [ 2 ] =
( rtB . lqknz2kefj . fyfzf3djiy [ 2 ] + rtB . eagdjb5elr . ekyf2ft5xv [ 2 ] )
+ m2cindee24 [ 2 ] ; rtB . dam0bfwzoj [ 0 ] = ( ( ( g0tgocacx1 [ 1 ] * rtB .
jnakfltztn [ 2 ] - kjselhlkqt * rtB . jnakfltztn [ 1 ] ) - bh5qcdfxpv * rtP .
data . reactionWheel . axis [ 0 ] ) - ( rtB . ehirxkx1np [ 1 ] * mVers [ 2 ]
- rtB . ehirxkx1np [ 2 ] * mVers [ 1 ] ) ) + rtB . p0sytp1tyb [ 0 ] ; rtB .
dam0bfwzoj [ 1 ] = ( ( ( kjselhlkqt * rtB . jnakfltztn [ 0 ] - g0tgocacx1 [ 0
] * rtB . jnakfltztn [ 2 ] ) - bh5qcdfxpv * rtP . data . reactionWheel . axis
[ 1 ] ) - ( rtB . ehirxkx1np [ 2 ] * mVers [ 0 ] - rtB . ehirxkx1np [ 0 ] *
mVers [ 2 ] ) ) + rtB . p0sytp1tyb [ 1 ] ; rtB . dam0bfwzoj [ 2 ] = ( ( (
g0tgocacx1 [ 0 ] * rtB . jnakfltztn [ 1 ] - g0tgocacx1 [ 1 ] * rtB .
jnakfltztn [ 0 ] ) - bh5qcdfxpv * rtP . data . reactionWheel . axis [ 2 ] ) -
( rtB . ehirxkx1np [ 0 ] * mVers [ 1 ] - rtB . ehirxkx1np [ 1 ] * mVers [ 0 ]
) ) + rtB . p0sytp1tyb [ 2 ] ; px30hprmrj ( rtB . n4ileghqyp , rtP . data .
orbit . a , rtP . data . orbit . e , & rtB . imixbcpj4x ) ; mzxxcjchg3 ( rtB
. ituo30pkvd . a4etz1spm4 , rtB . ituo30pkvd . edrpaasu4j , & rtB .
gwhniowyem ) ; for ( r3 = 0 ; r3 < 3 ; r3 ++ ) { mVers [ r3 ] = rtB .
k0b2i5iiue [ r3 + 6 ] * gyptrdgv1o + ( rtB . k0b2i5iiue [ r3 + 3 ] *
mfyhp04vud [ 1 ] + rtB . k0b2i5iiue [ r3 ] * mfyhp04vud [ 0 ] ) ; } absxk =
pke5l1lpzc ( rtB . jnakfltztn ) ; gyptrdgv1o = pke5l1lpzc ( mfyhp04vud ) ;
rSun [ 0 ] = ( rtB . jnakfltztn [ 1 ] * mVers [ 2 ] - rtB . jnakfltztn [ 2 ]
* mVers [ 1 ] ) * rtP . data . gyroscope . kObsABN / absxk / gyptrdgv1o + rtB
. ehirxkx1np [ 0 ] ; rSun [ 1 ] = ( rtB . jnakfltztn [ 2 ] * mVers [ 0 ] -
rtB . jnakfltztn [ 0 ] * mVers [ 2 ] ) * rtP . data . gyroscope . kObsABN /
absxk / gyptrdgv1o + rtB . ehirxkx1np [ 1 ] ; rSun [ 2 ] = ( rtB . jnakfltztn
[ 0 ] * mVers [ 1 ] - rtB . jnakfltztn [ 1 ] * mVers [ 0 ] ) * rtP . data .
gyroscope . kObsABN / absxk / gyptrdgv1o + rtB . ehirxkx1np [ 2 ] ; U [ 0 ] =
- 0.0 ; U [ 3 ] = rSun [ 2 ] ; U [ 6 ] = - rSun [ 1 ] ; U [ 1 ] = - rSun [ 2
] ; U [ 4 ] = - 0.0 ; U [ 7 ] = rSun [ 0 ] ; U [ 2 ] = rSun [ 1 ] ; U [ 5 ] =
- rSun [ 0 ] ; U [ 8 ] = - 0.0 ; for ( r3 = 0 ; r3 < 3 ; r3 ++ ) { for ( r2 =
0 ; r2 < 3 ; r2 ++ ) { rtB . gdcysdgjg5 [ r2 + 3 * r3 ] = 0.0 ; rtB .
gdcysdgjg5 [ r2 + 3 * r3 ] += rtB . k0b2i5iiue [ 3 * r3 ] * U [ r2 ] ; rtB .
gdcysdgjg5 [ r2 + 3 * r3 ] += rtB . k0b2i5iiue [ 3 * r3 + 1 ] * U [ r2 + 3 ]
; rtB . gdcysdgjg5 [ r2 + 3 * r3 ] += rtB . k0b2i5iiue [ 3 * r3 + 2 ] * U [
r2 + 6 ] ; } } if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { rtB . mk02jshpdk [ 0 ]
= rtDW . kqelrtffwz [ 0 ] ; rtB . mk02jshpdk [ 1 ] = rtDW . kqelrtffwz [ 1 ]
; rtB . mk02jshpdk [ 2 ] = rtDW . kqelrtffwz [ 2 ] ; } rtB . apuiamofe1 [ 0 ]
= rtX . jc4nrgnm2y [ 0 ] ; rtB . lo3kkfxdkz [ 0 ] = ( rtB . mk02jshpdk [ 0 ]
+ rtB . apuiamofe1 [ 0 ] ) + rtB . p51cv010io [ 0 ] ; rtB . apuiamofe1 [ 1 ]
= rtX . jc4nrgnm2y [ 1 ] ; rtB . lo3kkfxdkz [ 1 ] = ( rtB . mk02jshpdk [ 1 ]
+ rtB . apuiamofe1 [ 1 ] ) + rtB . p51cv010io [ 1 ] ; rtB . apuiamofe1 [ 2 ]
= rtX . jc4nrgnm2y [ 2 ] ; rtB . lo3kkfxdkz [ 2 ] = ( rtB . mk02jshpdk [ 2 ]
+ rtB . apuiamofe1 [ 2 ] ) + rtB . p51cv010io [ 2 ] ; if ( ssIsSampleHit (
rtS , 1 , 0 ) ) { rtB . hla54xlqcw [ 0 ] = rtB . lo3kkfxdkz [ 0 ] ; rtB .
hla54xlqcw [ 1 ] = rtB . lo3kkfxdkz [ 1 ] ; rtB . hla54xlqcw [ 2 ] = rtB .
lo3kkfxdkz [ 2 ] ; } for ( r3 = 0 ; r3 < 3 ; r3 ++ ) { mVers [ r3 ] = rtP .
data . sc . inertiaMatrix [ r3 + 6 ] * rtB . ehirxkx1np [ 2 ] + ( rtP . data
. sc . inertiaMatrix [ r3 + 3 ] * rtB . ehirxkx1np [ 1 ] + rtP . data . sc .
inertiaMatrix [ r3 ] * rtB . ehirxkx1np [ 0 ] ) ; } rSun [ 0 ] = mVers [ 1 ]
* rtB . ehirxkx1np [ 2 ] - mVers [ 2 ] * rtB . ehirxkx1np [ 1 ] ; rSun [ 1 ]
= mVers [ 2 ] * rtB . ehirxkx1np [ 0 ] - mVers [ 0 ] * rtB . ehirxkx1np [ 2 ]
; rSun [ 2 ] = mVers [ 0 ] * rtB . ehirxkx1np [ 1 ] - mVers [ 1 ] * rtB .
ehirxkx1np [ 0 ] ; brfsyu5ndt ( rtP . data . sc . inertiaMatrix , rSun , rtB
. kokf4n2mhf ) ; brfsyu5ndt ( rtP . data . sc . inertiaMatrix , rtB .
dam0bfwzoj , tmp ) ; rtB . kokf4n2mhf [ 0 ] = ( rtB . kokf4n2mhf [ 0 ] + tmp
[ 0 ] ) - ( rtB . ehirxkx1np [ 0 ] - rtB . hla54xlqcw [ 0 ] ) * rtP . data .
gyroscope . alphaObs ; rtB . kokf4n2mhf [ 1 ] = ( rtB . kokf4n2mhf [ 1 ] +
tmp [ 1 ] ) - ( rtB . ehirxkx1np [ 1 ] - rtB . hla54xlqcw [ 1 ] ) * rtP .
data . gyroscope . alphaObs ; rtB . kokf4n2mhf [ 2 ] = ( rtB . kokf4n2mhf [ 2
] + tmp [ 2 ] ) - ( rtB . ehirxkx1np [ 2 ] - rtB . hla54xlqcw [ 2 ] ) * rtP .
data . gyroscope . alphaObs ; U [ 0 ] = - 0.0 ; U [ 3 ] = rtB . p51cv010io [
2 ] ; U [ 6 ] = - rtB . p51cv010io [ 1 ] ; U [ 1 ] = - rtB . p51cv010io [ 2 ]
; U [ 4 ] = - 0.0 ; U [ 7 ] = rtB . p51cv010io [ 0 ] ; U [ 2 ] = rtB .
p51cv010io [ 1 ] ; U [ 5 ] = - rtB . p51cv010io [ 0 ] ; U [ 8 ] = - 0.0 ; for
( r3 = 0 ; r3 < 3 ; r3 ++ ) { for ( r2 = 0 ; r2 < 3 ; r2 ++ ) { rtB .
mymck1p5dr [ r2 + 3 * r3 ] = 0.0 ; rtB . mymck1p5dr [ r2 + 3 * r3 ] += rtB .
fd3qlfq0pf [ 3 * r3 ] * U [ r2 ] ; rtB . mymck1p5dr [ r2 + 3 * r3 ] += rtB .
fd3qlfq0pf [ 3 * r3 + 1 ] * U [ r2 + 3 ] ; rtB . mymck1p5dr [ r2 + 3 * r3 ]
+= rtB . fd3qlfq0pf [ 3 * r3 + 2 ] * U [ r2 + 6 ] ; } } px30hprmrj ( rtB .
izl1q5sazi , rtP . data . orbit . a , rtP . data . orbit . e , & rtB .
cz1perd2ej ) ; for ( r3 = 0 ; r3 < 3 ; r3 ++ ) { mVers [ r3 ] = rtP . data .
sc . inertiaMatrix [ r3 + 6 ] * rtB . p51cv010io [ 2 ] + ( rtP . data . sc .
inertiaMatrix [ r3 + 3 ] * rtB . p51cv010io [ 1 ] + rtP . data . sc .
inertiaMatrix [ r3 ] * rtB . p51cv010io [ 0 ] ) ; } mfyhp04vud [ 0 ] = (
mVers [ 1 ] * rtB . p51cv010io [ 2 ] - mVers [ 2 ] * rtB . p51cv010io [ 1 ] )
+ rtB . d4wo1qk3qg [ 0 ] ; mfyhp04vud [ 1 ] = ( mVers [ 2 ] * rtB .
p51cv010io [ 0 ] - mVers [ 0 ] * rtB . p51cv010io [ 2 ] ) + rtB . d4wo1qk3qg
[ 1 ] ; mfyhp04vud [ 2 ] = ( mVers [ 0 ] * rtB . p51cv010io [ 1 ] - mVers [ 1
] * rtB . p51cv010io [ 0 ] ) + rtB . d4wo1qk3qg [ 2 ] ; memcpy ( & ABL [ 0 ]
, & rtP . data . sc . inertiaMatrix [ 0 ] , 9U * sizeof ( real_T ) ) ; r1 = 0
; r2 = 1 ; r3 = 2 ; bh5qcdfxpv = muDoubleScalarAbs ( rtP . data . sc .
inertiaMatrix [ 0 ] ) ; theta = muDoubleScalarAbs ( rtP . data . sc .
inertiaMatrix [ 1 ] ) ; if ( theta > muDoubleScalarAbs ( rtP . data . sc .
inertiaMatrix [ 0 ] ) ) { bh5qcdfxpv = theta ; r1 = 1 ; r2 = 0 ; } if (
muDoubleScalarAbs ( rtP . data . sc . inertiaMatrix [ 2 ] ) > bh5qcdfxpv ) {
r1 = 2 ; r2 = 1 ; r3 = 0 ; } ABL [ r2 ] = rtP . data . sc . inertiaMatrix [
r2 ] / rtP . data . sc . inertiaMatrix [ r1 ] ; ABL [ r3 ] /= ABL [ r1 ] ;
ABL [ r2 + 3 ] -= ABL [ r1 + 3 ] * ABL [ r2 ] ; ABL [ r3 + 3 ] -= ABL [ r1 +
3 ] * ABL [ r3 ] ; ABL [ r2 + 6 ] -= ABL [ r1 + 6 ] * ABL [ r2 ] ; ABL [ r3 +
6 ] -= ABL [ r1 + 6 ] * ABL [ r3 ] ; if ( muDoubleScalarAbs ( ABL [ r3 + 3 ]
) > muDoubleScalarAbs ( ABL [ r2 + 3 ] ) ) { rtemp = r2 ; r2 = r3 ; r3 =
rtemp ; } ABL [ r3 + 3 ] /= ABL [ r2 + 3 ] ; ABL [ r3 + 6 ] -= ABL [ r3 + 3 ]
* ABL [ r2 + 6 ] ; rtB . ap5nsqw1en [ 1 ] = mfyhp04vud [ r2 ] - mfyhp04vud [
r1 ] * ABL [ r2 ] ; rtB . ap5nsqw1en [ 2 ] = ( mfyhp04vud [ r3 ] - mfyhp04vud
[ r1 ] * ABL [ r3 ] ) - ABL [ r3 + 3 ] * rtB . ap5nsqw1en [ 1 ] ; rtB .
ap5nsqw1en [ 2 ] /= ABL [ r3 + 6 ] ; rtB . ap5nsqw1en [ 0 ] = mfyhp04vud [ r1
] - ABL [ r1 + 6 ] * rtB . ap5nsqw1en [ 2 ] ; rtB . ap5nsqw1en [ 1 ] -= ABL [
r2 + 6 ] * rtB . ap5nsqw1en [ 2 ] ; rtB . ap5nsqw1en [ 1 ] /= ABL [ r2 + 3 ]
; rtB . ap5nsqw1en [ 0 ] -= ABL [ r1 + 3 ] * rtB . ap5nsqw1en [ 1 ] ; rtB .
ap5nsqw1en [ 0 ] /= ABL [ r1 ] ; rtB . dk2a4uugl1 [ 0 ] = rtB . p51cv010io [
0 ] - rtB . hla54xlqcw [ 0 ] ; rtB . dk2a4uugl1 [ 1 ] = rtB . p51cv010io [ 1
] - rtB . hla54xlqcw [ 1 ] ; rtB . dk2a4uugl1 [ 2 ] = rtB . p51cv010io [ 2 ]
- rtB . hla54xlqcw [ 2 ] ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { rtB .
ex4pku1fge [ 0 ] = rtDW . gubqowflu1 [ 0 ] ; rtB . ex4pku1fge [ 1 ] = rtDW .
gubqowflu1 [ 1 ] ; rtB . ex4pku1fge [ 2 ] = rtDW . gubqowflu1 [ 2 ] ; }
UNUSED_PARAMETER ( tid ) ; } void MdlOutputsTID2 ( int_T tid ) { rtB .
jx5wap4com [ 0 ] = rtP . data . gyroscope . wObs0 [ 0 ] ; rtB . jx5wap4com [
1 ] = rtP . data . gyroscope . wObs0 [ 1 ] ; rtB . jx5wap4com [ 2 ] = rtP .
data . gyroscope . wObs0 [ 2 ] ; UNUSED_PARAMETER ( tid ) ; } void MdlUpdate
( int_T tid ) { int32_T iU ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { rtDW .
n1mf5f1loj [ 0 ] = rt_nrand_Upu32_Yd_f_pw_snf ( & rtDW . ewjz1wr2fe [ 0 ] ) *
rtP . RandomNumber1_StdDev [ 0 ] + rtP . RandomNumber1_Mean ; rtDW .
n1mf5f1loj [ 1 ] = rt_nrand_Upu32_Yd_f_pw_snf ( & rtDW . ewjz1wr2fe [ 1 ] ) *
rtP . RandomNumber1_StdDev [ 1 ] + rtP . RandomNumber1_Mean ; rtDW .
n1mf5f1loj [ 2 ] = rt_nrand_Upu32_Yd_f_pw_snf ( & rtDW . ewjz1wr2fe [ 2 ] ) *
rtP . RandomNumber1_StdDev [ 2 ] + rtP . RandomNumber1_Mean ; rtDW .
ofluvtqt5p [ 0 ] = rt_nrand_Upu32_Yd_f_pw_snf ( & rtDW . k10aogs3q2 [ 0 ] ) *
rtP . RandomNumber1_StdDev_pxu4l4yv2r [ 0 ] + rtP .
RandomNumber1_Mean_bjj4nzkohe ; rtDW . ofluvtqt5p [ 1 ] =
rt_nrand_Upu32_Yd_f_pw_snf ( & rtDW . k10aogs3q2 [ 1 ] ) * rtP .
RandomNumber1_StdDev_pxu4l4yv2r [ 1 ] + rtP . RandomNumber1_Mean_bjj4nzkohe ;
rtDW . ofluvtqt5p [ 2 ] = rt_nrand_Upu32_Yd_f_pw_snf ( & rtDW . k10aogs3q2 [
2 ] ) * rtP . RandomNumber1_StdDev_pxu4l4yv2r [ 2 ] + rtP .
RandomNumber1_Mean_bjj4nzkohe ; rtDW . ofluvtqt5p [ 3 ] =
rt_nrand_Upu32_Yd_f_pw_snf ( & rtDW . k10aogs3q2 [ 3 ] ) * rtP .
RandomNumber1_StdDev_pxu4l4yv2r [ 3 ] + rtP . RandomNumber1_Mean_bjj4nzkohe ;
for ( iU = 0 ; iU < 8 ; iU ++ ) { rtDW . j4zaai5afv [ iU ] =
rt_nrand_Upu32_Yd_f_pw_snf ( & rtDW . bnvhkeklee [ iU ] ) * rtP .
RandomNumber_StdDev [ iU ] + rtP . RandomNumber_Mean ; rtDW . o221ifynn5 [ iU
] = ( rtP . UniformRandomNumber_Maximum - rtP . UniformRandomNumber_Minimum )
* rt_urand_Upu32_Yd_f_pw_snf ( & rtDW . c5xg33ddc3 [ iU ] ) + rtP .
UniformRandomNumber_Minimum ; } } rtDW . h5pffuqljc = 0 ; rtDW . mstj5paygm =
0 ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { rtDW . kqelrtffwz [ 0 ] =
rt_nrand_Upu32_Yd_f_pw_snf ( & rtDW . j05iyjbst5 [ 0 ] ) * rtP .
RandomNumber_StdDev_fffkyslftj [ 0 ] + rtP . RandomNumber_Mean_jleeh3nxmy ;
rtDW . gubqowflu1 [ 0 ] = rt_nrand_Upu32_Yd_f_pw_snf ( & rtDW . mgrhzfgfnu [
0 ] ) * rtP . RandomNumber1_StdDev_lesrfxv0lg [ 0 ] + rtP .
RandomNumber1_Mean_dlj5kv1b54 ; rtDW . kqelrtffwz [ 1 ] =
rt_nrand_Upu32_Yd_f_pw_snf ( & rtDW . j05iyjbst5 [ 1 ] ) * rtP .
RandomNumber_StdDev_fffkyslftj [ 1 ] + rtP . RandomNumber_Mean_jleeh3nxmy ;
rtDW . gubqowflu1 [ 1 ] = rt_nrand_Upu32_Yd_f_pw_snf ( & rtDW . mgrhzfgfnu [
1 ] ) * rtP . RandomNumber1_StdDev_lesrfxv0lg [ 1 ] + rtP .
RandomNumber1_Mean_dlj5kv1b54 ; rtDW . kqelrtffwz [ 2 ] =
rt_nrand_Upu32_Yd_f_pw_snf ( & rtDW . j05iyjbst5 [ 2 ] ) * rtP .
RandomNumber_StdDev_fffkyslftj [ 2 ] + rtP . RandomNumber_Mean_jleeh3nxmy ;
rtDW . gubqowflu1 [ 2 ] = rt_nrand_Upu32_Yd_f_pw_snf ( & rtDW . mgrhzfgfnu [
2 ] ) * rtP . RandomNumber1_StdDev_lesrfxv0lg [ 2 ] + rtP .
RandomNumber1_Mean_dlj5kv1b54 ; } UNUSED_PARAMETER ( tid ) ; } void
MdlUpdateTID2 ( int_T tid ) { UNUSED_PARAMETER ( tid ) ; } void
MdlDerivatives ( void ) { XDot * _rtXdot ; _rtXdot = ( ( XDot * ) ssGetdX (
rtS ) ) ; _rtXdot -> kjairk4b1p = rtB . cz1perd2ej . gmfjxhcwab ; _rtXdot ->
lutbl3ejqb [ 0 ] = rtB . ap5nsqw1en [ 0 ] ; _rtXdot -> ht1cmxxnsq [ 0 ] = rtB
. kokf4n2mhf [ 0 ] ; _rtXdot -> lutbl3ejqb [ 1 ] = rtB . ap5nsqw1en [ 1 ] ;
_rtXdot -> ht1cmxxnsq [ 1 ] = rtB . kokf4n2mhf [ 1 ] ; _rtXdot -> lutbl3ejqb
[ 2 ] = rtB . ap5nsqw1en [ 2 ] ; _rtXdot -> ht1cmxxnsq [ 2 ] = rtB .
kokf4n2mhf [ 2 ] ; memcpy ( & _rtXdot -> ouapiys3qq [ 0 ] , & rtB .
mymck1p5dr [ 0 ] , 9U * sizeof ( real_T ) ) ; memcpy ( & _rtXdot ->
fnoi12dssm [ 0 ] , & rtB . gdcysdgjg5 [ 0 ] , 9U * sizeof ( real_T ) ) ;
_rtXdot -> mnzw0suzs2 = rtB . gkxr4i513p ; _rtXdot -> bqjsimdqqc = rtB .
imixbcpj4x . gmfjxhcwab ; _rtXdot -> jc4nrgnm2y [ 0 ] = rtB . ex4pku1fge [ 0
] ; _rtXdot -> jc4nrgnm2y [ 1 ] = rtB . ex4pku1fge [ 1 ] ; _rtXdot ->
jc4nrgnm2y [ 2 ] = rtB . ex4pku1fge [ 2 ] ; } void MdlProjection ( void ) { }
void MdlTerminate ( void ) { } void MdlInitializeSizes ( void ) {
ssSetNumContStates ( rtS , 30 ) ; ssSetNumPeriodicContStates ( rtS , 0 ) ;
ssSetNumY ( rtS , 0 ) ; ssSetNumU ( rtS , 0 ) ; ssSetDirectFeedThrough ( rtS
, 0 ) ; ssSetNumSampleTimes ( rtS , 2 ) ; ssSetNumBlocks ( rtS , 138 ) ;
ssSetNumBlockIO ( rtS , 47 ) ; ssSetNumBlockParams ( rtS , 58 ) ; } void
MdlInitializeSampleTimes ( void ) { ssSetSampleTime ( rtS , 0 , 0.0 ) ;
ssSetSampleTime ( rtS , 1 , 1.0 ) ; ssSetOffsetTime ( rtS , 0 , 0.0 ) ;
ssSetOffsetTime ( rtS , 1 , 0.0 ) ; } void raccel_set_checksum ( ) {
ssSetChecksumVal ( rtS , 0 , 469362051U ) ; ssSetChecksumVal ( rtS , 1 ,
2005292047U ) ; ssSetChecksumVal ( rtS , 2 , 1163668803U ) ; ssSetChecksumVal
( rtS , 3 , 920400502U ) ; }
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
numDataTypes = 28 ; dtInfo . dataTypeSizes = & rtDataTypeSizes [ 0 ] ; dtInfo
. dataTypeNames = & rtDataTypeNames [ 0 ] ; dtInfo . BTransTable = &
rtBTransTable ; dtInfo . PTransTable = & rtPTransTable ; dtInfo .
dataTypeInfoTable = rtDataTypeInfoTable ; } pointing_InitializeDataMapInfo (
) ; ssSetIsRapidAcceleratorActive ( rtS , true ) ; ssSetRootSS ( rtS , rtS )
; ssSetVersion ( rtS , SIMSTRUCT_VERSION_LEVEL2 ) ; ssSetModelName ( rtS ,
"pointing" ) ; ssSetPath ( rtS , "pointing" ) ; ssSetTStart ( rtS , 9000.0 )
; ssSetTFinal ( rtS , 15000.0 ) ; { static RTWLogInfo rt_DataLoggingInfo ;
rt_DataLoggingInfo . loggingInterval = NULL ; ssSetRTWLogInfo ( rtS , &
rt_DataLoggingInfo ) ; } { { static int_T rt_LoggedStateWidths [ ] = { 9 , 1
, 3 , 3 , 9 , 1 , 1 , 3 } ; static int_T rt_LoggedStateNumDimensions [ ] = {
1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 } ; static int_T rt_LoggedStateDimensions [ ] =
{ 9 , 1 , 3 , 3 , 9 , 1 , 1 , 3 } ; static boolean_T rt_LoggedStateIsVarDims
[ ] = { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ; static BuiltInDTypeId
rt_LoggedStateDataTypeIds [ ] = { SS_DOUBLE , SS_DOUBLE , SS_DOUBLE ,
SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE } ; static int_T
rt_LoggedStateComplexSignals [ ] = { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ; static
RTWPreprocessingFcnPtr rt_LoggingStatePreprocessingFcnPtrs [ ] = { ( NULL ) ,
( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) }
; static const char_T * rt_LoggedStateLabels [ ] = { "CSTATE" , "CSTATE" ,
"CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" } ; static
const char_T * rt_LoggedStateBlockNames [ ] = {
"pointing/Direct Cosine Matrix/Integrator" ,
"pointing/Environment/Unperturbed Orbit/Integrator" ,
"pointing/Euler Equations/Integrator" ,
"pointing/Attitude Determination/Observer/Integrator" ,
"pointing/Attitude Determination/Integrator1" ,
"pointing/Control and Actuators/Integrator" ,
 "pointing/Attitude Determination/Disturbances Estimation/Unperturbed Orbit/Integrator"
, "pointing/Sensors/Gyroscope/Integrator" } ; static const char_T *
rt_LoggedStateNames [ ] = { "" , "" , "" , "" , "" , "" , "" , "" } ; static
boolean_T rt_LoggedStateCrossMdlRef [ ] = { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ;
static RTWLogDataTypeConvert rt_RTWLogDataTypeConvert [ ] = { { 0 , SS_DOUBLE
, SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 ,
0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 ,
0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 ,
SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE ,
SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0
, 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 ,
0.0 } } ; static RTWLogSignalInfo rt_LoggedStateSignalInfo = { 8 ,
rt_LoggedStateWidths , rt_LoggedStateNumDimensions , rt_LoggedStateDimensions
, rt_LoggedStateIsVarDims , ( NULL ) , ( NULL ) , rt_LoggedStateDataTypeIds ,
rt_LoggedStateComplexSignals , ( NULL ) , rt_LoggingStatePreprocessingFcnPtrs
, { rt_LoggedStateLabels } , ( NULL ) , ( NULL ) , ( NULL ) , {
rt_LoggedStateBlockNames } , { rt_LoggedStateNames } ,
rt_LoggedStateCrossMdlRef , rt_RTWLogDataTypeConvert } ; static void *
rt_LoggedStateSignalPtrs [ 8 ] ; rtliSetLogXSignalPtrs ( ssGetRTWLogInfo (
rtS ) , ( LogSignalPtrsType ) rt_LoggedStateSignalPtrs ) ;
rtliSetLogXSignalInfo ( ssGetRTWLogInfo ( rtS ) , & rt_LoggedStateSignalInfo
) ; rt_LoggedStateSignalPtrs [ 0 ] = ( void * ) & rtX . ouapiys3qq [ 0 ] ;
rt_LoggedStateSignalPtrs [ 1 ] = ( void * ) & rtX . kjairk4b1p ;
rt_LoggedStateSignalPtrs [ 2 ] = ( void * ) & rtX . lutbl3ejqb [ 0 ] ;
rt_LoggedStateSignalPtrs [ 3 ] = ( void * ) & rtX . ht1cmxxnsq [ 0 ] ;
rt_LoggedStateSignalPtrs [ 4 ] = ( void * ) & rtX . fnoi12dssm [ 0 ] ;
rt_LoggedStateSignalPtrs [ 5 ] = ( void * ) & rtX . mnzw0suzs2 ;
rt_LoggedStateSignalPtrs [ 6 ] = ( void * ) & rtX . bqjsimdqqc ;
rt_LoggedStateSignalPtrs [ 7 ] = ( void * ) & rtX . jc4nrgnm2y [ 0 ] ; }
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
static ssSolverInfo slvrInfo ; static boolean_T contStatesDisabled [ 30 ] ;
static real_T absTol [ 30 ] = { 1.0E-8 , 1.0E-8 , 1.0E-8 , 1.0E-8 , 1.0E-8 ,
1.0E-8 , 1.0E-8 , 1.0E-8 , 1.0E-8 , 1.0E-8 , 1.0E-8 , 1.0E-8 , 1.0E-8 ,
1.0E-8 , 1.0E-8 , 1.0E-8 , 1.0E-8 , 1.0E-8 , 1.0E-8 , 1.0E-8 , 1.0E-8 ,
1.0E-8 , 1.0E-8 , 1.0E-8 , 1.0E-8 , 1.0E-8 , 1.0E-8 , 1.0E-8 , 1.0E-8 ,
1.0E-8 } ; static uint8_T absTolControl [ 30 ] = { 0U , 0U , 0U , 0U , 0U ,
0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U
, 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U } ; static real_T
contStateJacPerturbBoundMinVec [ 30 ] ; static real_T
contStateJacPerturbBoundMaxVec [ 30 ] ; static ssNonContDerivSigInfo
nonContDerivSigInfo [ 5 ] = { { 3 * sizeof ( real_T ) , ( char * ) ( & rtB .
ex4pku1fge [ 0 ] ) , ( NULL ) } , { 3 * sizeof ( real_T ) , ( char * ) ( &
rtB . hla54xlqcw [ 0 ] ) , ( NULL ) } , { 3 * sizeof ( real_T ) , ( char * )
( & rtB . jnakfltztn [ 0 ] ) , ( NULL ) } , { 9 * sizeof ( real_T ) , ( char
* ) ( & rtB . d155gslfmi [ 0 ] ) , ( NULL ) } , { 3 * sizeof ( real_T ) , (
char * ) ( & rtB . eagdjb5elr . ekyf2ft5xv [ 0 ] ) , ( NULL ) } } ; { int i ;
for ( i = 0 ; i < 30 ; ++ i ) { contStateJacPerturbBoundMinVec [ i ] = 0 ;
contStateJacPerturbBoundMaxVec [ i ] = rtGetInf ( ) ; } } ssSetSolverRelTol (
rtS , 1.0E-8 ) ; ssSetStepSize ( rtS , 0.0 ) ; ssSetMinStepSize ( rtS , 0.0 )
; ssSetMaxNumMinSteps ( rtS , - 1 ) ; ssSetMinStepViolatedError ( rtS , 0 ) ;
ssSetMaxStepSize ( rtS , 1.0 ) ; ssSetSolverMaxOrder ( rtS , 5 ) ;
ssSetSolverRefineFactor ( rtS , 1 ) ; ssSetOutputTimes ( rtS , ( NULL ) ) ;
ssSetNumOutputTimes ( rtS , 0 ) ; ssSetOutputTimesOnly ( rtS , 0 ) ;
ssSetOutputTimesIndex ( rtS , 0 ) ; ssSetZCCacheNeedsReset ( rtS , 0 ) ;
ssSetDerivCacheNeedsReset ( rtS , 0 ) ; ssSetNumNonContDerivSigInfos ( rtS ,
5 ) ; ssSetNonContDerivSigInfos ( rtS , nonContDerivSigInfo ) ;
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
MdlDerivatives ) ; ssSetSolverMaxConsecutiveMinStep ( rtS , 1 ) ;
ssSetSolverShapePreserveControl ( rtS , 2 ) ; ssSetTNextTid ( rtS , INT_MIN )
; ssSetTNext ( rtS , rtMinusInf ) ; ssSetSolverNeedsReset ( rtS ) ;
ssSetNumNonsampledZCs ( rtS , 0 ) ; ssSetContStateDisabled ( rtS ,
contStatesDisabled ) ; ssSetSolverMaxConsecutiveMinStep ( rtS , 1 ) ; } {
ZCSigState * zc = ( ZCSigState * ) & rtPrevZCX ; ssSetPrevZCSigState ( rtS ,
zc ) ; ssSetWorkSizeInBytes ( rtS , sizeof ( rtPrevZCX ) , "PrevZCSigState" )
; } { rtPrevZCX . dwuwbqsvq3 = UNINITIALIZED_ZCSIG ; } ssSetChecksumVal ( rtS
, 0 , 469362051U ) ; ssSetChecksumVal ( rtS , 1 , 2005292047U ) ;
ssSetChecksumVal ( rtS , 2 , 1163668803U ) ; ssSetChecksumVal ( rtS , 3 ,
920400502U ) ; { static const sysRanDType rtAlwaysEnabled =
SUBSYS_RAN_BC_ENABLE ; static RTWExtModeInfo rt_ExtModeInfo ; static const
sysRanDType * systemRan [ 32 ] ; gblRTWExtModeInfo = & rt_ExtModeInfo ;
ssSetRTWExtModeInfo ( rtS , & rt_ExtModeInfo ) ;
rteiSetSubSystemActiveVectorAddresses ( & rt_ExtModeInfo , systemRan ) ;
systemRan [ 0 ] = & rtAlwaysEnabled ; systemRan [ 1 ] = & rtAlwaysEnabled ;
systemRan [ 2 ] = ( sysRanDType * ) & rtDW . bt5mj1ckkg ; systemRan [ 3 ] = (
sysRanDType * ) & rtDW . mgkojscrve ; systemRan [ 4 ] = & rtAlwaysEnabled ;
systemRan [ 5 ] = & rtAlwaysEnabled ; systemRan [ 6 ] = & rtAlwaysEnabled ;
systemRan [ 7 ] = & rtAlwaysEnabled ; systemRan [ 8 ] = & rtAlwaysEnabled ;
systemRan [ 9 ] = & rtAlwaysEnabled ; systemRan [ 10 ] = & rtAlwaysEnabled ;
systemRan [ 11 ] = & rtAlwaysEnabled ; systemRan [ 12 ] = & rtAlwaysEnabled ;
systemRan [ 13 ] = & rtAlwaysEnabled ; systemRan [ 14 ] = & rtAlwaysEnabled ;
systemRan [ 15 ] = & rtAlwaysEnabled ; systemRan [ 16 ] = & rtAlwaysEnabled ;
systemRan [ 17 ] = & rtAlwaysEnabled ; systemRan [ 18 ] = & rtAlwaysEnabled ;
systemRan [ 19 ] = & rtAlwaysEnabled ; systemRan [ 20 ] = & rtAlwaysEnabled ;
systemRan [ 21 ] = & rtAlwaysEnabled ; systemRan [ 22 ] = & rtAlwaysEnabled ;
systemRan [ 23 ] = & rtAlwaysEnabled ; systemRan [ 24 ] = & rtAlwaysEnabled ;
systemRan [ 25 ] = & rtAlwaysEnabled ; systemRan [ 26 ] = & rtAlwaysEnabled ;
systemRan [ 27 ] = & rtAlwaysEnabled ; systemRan [ 28 ] = & rtAlwaysEnabled ;
systemRan [ 29 ] = & rtAlwaysEnabled ; systemRan [ 30 ] = & rtAlwaysEnabled ;
systemRan [ 31 ] = & rtAlwaysEnabled ; rteiSetModelMappingInfoPtr (
ssGetRTWExtModeInfo ( rtS ) , & ssGetModelMappingInfo ( rtS ) ) ;
rteiSetChecksumsPtr ( ssGetRTWExtModeInfo ( rtS ) , ssGetChecksums ( rtS ) )
; rteiSetTPtr ( ssGetRTWExtModeInfo ( rtS ) , ssGetTPtr ( rtS ) ) ; } return
rtS ; }
#if defined(_MSC_VER)
#pragma optimize( "", on )
#endif
const int_T gblParameterTuningTid = 2 ; void MdlOutputsParameterSampleTime (
int_T tid ) { MdlOutputsTID2 ( tid ) ; }
