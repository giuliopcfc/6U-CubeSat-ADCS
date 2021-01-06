#include "rtw_capi.h"
#ifdef HOST_CAPI_BUILD
#include "pointing_capi_host.h"
#define sizeof(s) ((size_t)(0xFFFF))
#undef rt_offsetof
#define rt_offsetof(s,el) ((uint16_T)(0xFFFF))
#define TARGET_CONST
#define TARGET_STRING(s) (s)    
#else
#include "builtin_typeid_types.h"
#include "pointing.h"
#include "pointing_capi.h"
#include "pointing_private.h"
#ifdef LIGHT_WEIGHT_CAPI
#define TARGET_CONST                  
#define TARGET_STRING(s)               (NULL)                    
#else
#define TARGET_CONST                   const
#define TARGET_STRING(s)               (s)
#endif
#endif
static const rtwCAPI_Signals rtBlockSignals [ ] = { { 0 , 1 , TARGET_STRING (
"pointing/ " ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 1 , 0 ,
TARGET_STRING ( "pointing/Add" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 }
, { 2 , 0 , TARGET_STRING ( "pointing/Attitude Determination/ABN from Gyro" )
, TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 0 } , { 3 , 0 , TARGET_STRING (
"pointing/Attitude Determination/ABN from Wabha's problem" ) , TARGET_STRING
( "" ) , 0 , 0 , 1 , 0 , 0 } , { 4 , 12 , TARGET_STRING (
"pointing/Attitude Determination/Integrate ABN" ) , TARGET_STRING ( "" ) , 0
, 0 , 1 , 0 , 0 } , { 5 , 14 , TARGET_STRING (
"pointing/Attitude Determination/Switch To Gyro" ) , TARGET_STRING ( "" ) , 0
, 1 , 2 , 0 , 0 } , { 6 , 15 , TARGET_STRING (
"pointing/Attitude Determination/Wabha's Problem" ) , TARGET_STRING ( "" ) ,
0 , 0 , 1 , 0 , 1 } , { 7 , 0 , TARGET_STRING (
"pointing/Attitude Determination/Integrator1" ) , TARGET_STRING ( "" ) , 0 ,
0 , 1 , 0 , 0 } , { 8 , 0 , TARGET_STRING (
"pointing/Attitude Determination/Merge" ) , TARGET_STRING ( "" ) , 0 , 0 , 1
, 0 , 0 } , { 9 , 0 , TARGET_STRING ( "pointing/Attitude Determination/Add2"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 10 , 17 , TARGET_STRING (
"pointing/Control and Actuators/Control Logic" ) , TARGET_STRING ( "" ) , 1 ,
0 , 2 , 0 , 0 } , { 11 , 0 , TARGET_STRING (
"pointing/Control and Actuators/Integrator" ) , TARGET_STRING ( "" ) , 0 , 0
, 2 , 0 , 0 } , { 12 , 18 , TARGET_STRING (
"pointing/Direct Cosine Matrix/MATLAB Function" ) , TARGET_STRING ( "" ) , 0
, 0 , 1 , 0 , 0 } , { 13 , 19 , TARGET_STRING (
"pointing/Direct Cosine Matrix/MATLAB Function1" ) , TARGET_STRING ( "" ) , 0
, 0 , 1 , 0 , 0 } , { 14 , 0 , TARGET_STRING (
"pointing/Direct Cosine Matrix/Integrator" ) , TARGET_STRING ( "" ) , 0 , 0 ,
1 , 0 , 0 } , { 15 , 22 , TARGET_STRING (
"pointing/Environment/Gravity Gradient" ) , TARGET_STRING ( "" ) , 0 , 0 , 0
, 0 , 0 } , { 16 , 24 , TARGET_STRING (
"pointing/Environment/MATLAB Function1" ) , TARGET_STRING ( "" ) , 0 , 0 , 0
, 0 , 0 } , { 17 , 0 , TARGET_STRING ( "pointing/Environment/Add" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 18 , 30 , TARGET_STRING (
"pointing/Euler Equations/MATLAB Function" ) , TARGET_STRING ( "" ) , 0 , 0 ,
0 , 0 , 0 } , { 19 , 0 , TARGET_STRING (
"pointing/Euler Equations/Integrator" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 ,
0 , 0 } , { 20 , 0 , TARGET_STRING ( "pointing/Sensors/Add3" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 21 , 0 , TARGET_STRING (
"pointing/Attitude Determination/ABN from Gyro/ABN" ) , TARGET_STRING ( "" )
, 0 , 0 , 1 , 0 , 0 } , { 22 , 0 , TARGET_STRING (
"pointing/Attitude Determination/ABN from Wabha's problem/estABN" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 0 } , { 23 , 4 , TARGET_STRING (
"pointing/Attitude Determination/Disturbances Estimation/Gravity Gradient" )
, TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 24 , 6 , TARGET_STRING (
"pointing/Attitude Determination/Disturbances Estimation/MATLAB Function1" )
, TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 25 , 0 , TARGET_STRING (
"pointing/Attitude Determination/Disturbances Estimation/Add" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 26 , 13 , TARGET_STRING (
"pointing/Attitude Determination/Observer/Observer" ) , TARGET_STRING ( "" )
, 0 , 0 , 0 , 0 , 0 } , { 27 , 0 , TARGET_STRING (
"pointing/Attitude Determination/Observer/Constant1" ) , TARGET_STRING ( "" )
, 0 , 0 , 0 , 0 , 2 } , { 28 , 0 , TARGET_STRING (
"pointing/Attitude Determination/Observer/Integrator" ) , TARGET_STRING ( ""
) , 0 , 0 , 0 , 0 , 0 } , { 29 , 26 , TARGET_STRING (
"pointing/Environment/Unperturbed Orbit/MATLAB Function" ) , TARGET_STRING (
"" ) , 0 , 0 , 2 , 0 , 0 } , { 30 , 27 , TARGET_STRING (
"pointing/Environment/Unperturbed Orbit/MATLAB Function1" ) , TARGET_STRING (
"" ) , 0 , 0 , 0 , 0 , 0 } , { 31 , 27 , TARGET_STRING (
"pointing/Environment/Unperturbed Orbit/MATLAB Function1" ) , TARGET_STRING (
"" ) , 1 , 0 , 0 , 0 , 0 } , { 32 , 27 , TARGET_STRING (
"pointing/Environment/Unperturbed Orbit/MATLAB Function1" ) , TARGET_STRING (
"" ) , 2 , 0 , 1 , 0 , 0 } , { 33 , 28 , TARGET_STRING (
"pointing/Environment/Unperturbed Orbit/MATLAB Function2" ) , TARGET_STRING (
"" ) , 0 , 0 , 1 , 0 , 0 } , { 34 , 29 , TARGET_STRING (
"pointing/Environment/Unperturbed Orbit/MATLAB Function3" ) , TARGET_STRING (
"" ) , 0 , 0 , 0 , 0 , 0 } , { 35 , 0 , TARGET_STRING (
"pointing/Environment/Unperturbed Orbit/Integrator" ) , TARGET_STRING ( "" )
, 0 , 0 , 2 , 0 , 0 } , { 36 , 0 , TARGET_STRING (
"pointing/Sensors/Gyroscope/Integrator" ) , TARGET_STRING ( "" ) , 0 , 0 , 0
, 0 , 0 } , { 37 , 0 , TARGET_STRING (
"pointing/Sensors/Gyroscope/Random Number" ) , TARGET_STRING ( "" ) , 0 , 0 ,
0 , 0 , 1 } , { 38 , 0 , TARGET_STRING (
"pointing/Sensors/Gyroscope/Random Number1" ) , TARGET_STRING ( "" ) , 0 , 0
, 0 , 0 , 1 } , { 39 , 0 , TARGET_STRING ( "pointing/Sensors/Gyroscope/Add" )
, TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 40 , 0 , TARGET_STRING (
"pointing/Sensors/Gyroscope/Zero-Order Hold" ) , TARGET_STRING ( "" ) , 0 , 0
, 0 , 0 , 1 } , { 41 , 0 , TARGET_STRING (
"pointing/Sensors/Magnetometer/Multiply" ) , TARGET_STRING ( "" ) , 0 , 0 , 0
, 0 , 1 } , { 42 , 0 , TARGET_STRING (
"pointing/Sensors/Magnetometer/Random Number1" ) , TARGET_STRING ( "" ) , 0 ,
0 , 0 , 0 , 1 } , { 43 , 0 , TARGET_STRING (
"pointing/Sensors/Magnetometer/Add" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0
, 0 } , { 44 , 8 , TARGET_STRING (
 "pointing/Attitude Determination/Disturbances Estimation/Unperturbed Orbit/MATLAB Function"
) , TARGET_STRING ( "" ) , 0 , 0 , 2 , 0 , 0 } , { 45 , 9 , TARGET_STRING (
 "pointing/Attitude Determination/Disturbances Estimation/Unperturbed Orbit/MATLAB Function1"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 46 , 9 , TARGET_STRING (
 "pointing/Attitude Determination/Disturbances Estimation/Unperturbed Orbit/MATLAB Function1"
) , TARGET_STRING ( "" ) , 1 , 0 , 0 , 0 , 0 } , { 47 , 9 , TARGET_STRING (
 "pointing/Attitude Determination/Disturbances Estimation/Unperturbed Orbit/MATLAB Function1"
) , TARGET_STRING ( "" ) , 2 , 0 , 1 , 0 , 0 } , { 48 , 10 , TARGET_STRING (
 "pointing/Attitude Determination/Disturbances Estimation/Unperturbed Orbit/MATLAB Function2"
) , TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 0 } , { 49 , 11 , TARGET_STRING (
 "pointing/Attitude Determination/Disturbances Estimation/Unperturbed Orbit/MATLAB Function3"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 50 , 0 , TARGET_STRING (
 "pointing/Attitude Determination/Disturbances Estimation/Unperturbed Orbit/Integrator"
) , TARGET_STRING ( "" ) , 0 , 0 , 2 , 0 , 0 } , { 0 , 0 , ( NULL ) , ( NULL
) , 0 , 0 , 0 , 0 , 0 } } ; static const rtwCAPI_BlockParameters
rtBlockParameters [ ] = { { 51 , TARGET_STRING (
"pointing/Sensors/Gyroscope/Random Number" ) , TARGET_STRING ( "Mean" ) , 0 ,
2 , 0 } , { 52 , TARGET_STRING ( "pointing/Sensors/Gyroscope/Random Number" )
, TARGET_STRING ( "StdDev" ) , 0 , 0 , 0 } , { 53 , TARGET_STRING (
"pointing/Sensors/Gyroscope/Random Number" ) , TARGET_STRING ( "Seed" ) , 0 ,
0 , 0 } , { 54 , TARGET_STRING ( "pointing/Sensors/Gyroscope/Random Number1"
) , TARGET_STRING ( "Mean" ) , 0 , 2 , 0 } , { 55 , TARGET_STRING (
"pointing/Sensors/Gyroscope/Random Number1" ) , TARGET_STRING ( "StdDev" ) ,
0 , 0 , 0 } , { 56 , TARGET_STRING (
"pointing/Sensors/Gyroscope/Random Number1" ) , TARGET_STRING ( "Seed" ) , 0
, 0 , 0 } , { 57 , TARGET_STRING (
"pointing/Sensors/Magnetometer/Random Number1" ) , TARGET_STRING ( "Mean" ) ,
0 , 2 , 0 } , { 58 , TARGET_STRING (
"pointing/Sensors/Magnetometer/Random Number1" ) , TARGET_STRING ( "StdDev" )
, 0 , 0 , 0 } , { 59 , TARGET_STRING (
"pointing/Sensors/Magnetometer/Random Number1" ) , TARGET_STRING ( "Seed" ) ,
0 , 0 , 0 } , { 60 , TARGET_STRING (
"pointing/Sensors/Star Sensor/Random Number" ) , TARGET_STRING ( "Mean" ) , 0
, 2 , 0 } , { 61 , TARGET_STRING (
"pointing/Sensors/Star Sensor/Random Number" ) , TARGET_STRING ( "StdDev" ) ,
0 , 3 , 0 } , { 62 , TARGET_STRING (
"pointing/Sensors/Star Sensor/Random Number" ) , TARGET_STRING ( "Seed" ) , 0
, 3 , 0 } , { 63 , TARGET_STRING (
"pointing/Sensors/Star Sensor/Random Number1" ) , TARGET_STRING ( "Mean" ) ,
0 , 2 , 0 } , { 64 , TARGET_STRING (
"pointing/Sensors/Star Sensor/Random Number1" ) , TARGET_STRING ( "StdDev" )
, 0 , 4 , 0 } , { 65 , TARGET_STRING (
"pointing/Sensors/Star Sensor/Random Number1" ) , TARGET_STRING ( "Seed" ) ,
0 , 4 , 0 } , { 66 , TARGET_STRING (
"pointing/Sensors/Star Sensor/Uniform Random Number" ) , TARGET_STRING (
"Minimum" ) , 0 , 2 , 0 } , { 67 , TARGET_STRING (
"pointing/Sensors/Star Sensor/Uniform Random Number" ) , TARGET_STRING (
"Maximum" ) , 0 , 2 , 0 } , { 68 , TARGET_STRING (
"pointing/Sensors/Star Sensor/Uniform Random Number" ) , TARGET_STRING (
"Seed" ) , 0 , 3 , 0 } , { 0 , ( NULL ) , ( NULL ) , 0 , 0 , 0 } } ; static
const rtwCAPI_Signals rtRootInputs [ ] = { { 0 , 0 , ( NULL ) , ( NULL ) , 0
, 0 , 0 , 0 , 0 } } ; static const rtwCAPI_Signals rtRootOutputs [ ] = { { 0
, 0 , ( NULL ) , ( NULL ) , 0 , 0 , 0 , 0 , 0 } } ; static const
rtwCAPI_ModelParameters rtModelParameters [ ] = { { 69 , TARGET_STRING (
"data" ) , 15 , 2 , 0 } , { 0 , ( NULL ) , 0 , 0 , 0 } } ;
#ifndef HOST_CAPI_BUILD
static void * rtDataAddrMap [ ] = { & rtB . hpj2uj2i4a [ 0 ] , & rtB .
d4wo1qk3qg [ 0 ] , & rtB . fonazkfutz [ 0 ] , & rtB . fonazkfutz [ 0 ] , &
rtB . gdcysdgjg5 [ 0 ] , & rtB . mkszl352m3 , & rtB . d155gslfmi [ 0 ] , &
rtB . k0b2i5iiue [ 0 ] , & rtB . fonazkfutz [ 0 ] , & rtB . dam0bfwzoj [ 0 ]
, & rtB . gkxr4i513p , & rtB . n4mzmf5vo5 , & rtB . mymck1p5dr [ 0 ] , & rtB
. fd3qlfq0pf [ 0 ] , & rtB . haaoe3krmo [ 0 ] , & rtB . mssjub5nr2 .
fyfzf3djiy [ 0 ] , & rtB . arbgebpnzf . ekyf2ft5xv [ 0 ] , & rtB . jpaphc4vt2
[ 0 ] , & rtB . ap5nsqw1en [ 0 ] , & rtB . p51cv010io [ 0 ] , & rtB .
dk2a4uugl1 [ 0 ] , & rtB . fonazkfutz [ 0 ] , & rtB . fonazkfutz [ 0 ] , &
rtB . lqknz2kefj . fyfzf3djiy [ 0 ] , & rtB . eagdjb5elr . ekyf2ft5xv [ 0 ] ,
& rtB . p0sytp1tyb [ 0 ] , & rtB . kokf4n2mhf [ 0 ] , & rtB . jx5wap4com [ 0
] , & rtB . ehirxkx1np [ 0 ] , & rtB . cz1perd2ej . gmfjxhcwab , & rtB .
hid2a3ighm . a4etz1spm4 [ 0 ] , & rtB . hid2a3ighm . edrpaasu4j [ 0 ] , & rtB
. hid2a3ighm . nmcsp5dcxo [ 0 ] , & rtB . nzapizli54 . fws4iwogpu [ 0 ] , &
rtB . eje25gfouo . g540wbqcci [ 0 ] , & rtB . izl1q5sazi , & rtB . apuiamofe1
[ 0 ] , & rtB . mk02jshpdk [ 0 ] , & rtB . ex4pku1fge [ 0 ] , & rtB .
lo3kkfxdkz [ 0 ] , & rtB . hla54xlqcw [ 0 ] , & rtB . jnakfltztn [ 0 ] , &
rtB . nxkkb43lmg [ 0 ] , & rtB . kj0hrlovtd [ 0 ] , & rtB . imixbcpj4x .
gmfjxhcwab , & rtB . ituo30pkvd . a4etz1spm4 [ 0 ] , & rtB . ituo30pkvd .
edrpaasu4j [ 0 ] , & rtB . ituo30pkvd . nmcsp5dcxo [ 0 ] , & rtB . lb5tuw34lz
. fws4iwogpu [ 0 ] , & rtB . gwhniowyem . g540wbqcci [ 0 ] , & rtB .
n4ileghqyp , & rtP . RandomNumber_Mean_jleeh3nxmy , & rtP .
RandomNumber_StdDev_fffkyslftj [ 0 ] , & rtP . RandomNumber_Seed_g3q3oeokt3 [
0 ] , & rtP . RandomNumber1_Mean_dlj5kv1b54 , & rtP .
RandomNumber1_StdDev_lesrfxv0lg [ 0 ] , & rtP . RandomNumber1_Seed_ow4kdudteh
[ 0 ] , & rtP . RandomNumber1_Mean , & rtP . RandomNumber1_StdDev [ 0 ] , &
rtP . RandomNumber1_Seed [ 0 ] , & rtP . RandomNumber_Mean , & rtP .
RandomNumber_StdDev [ 0 ] , & rtP . RandomNumber_Seed [ 0 ] , & rtP .
RandomNumber1_Mean_bjj4nzkohe , & rtP . RandomNumber1_StdDev_pxu4l4yv2r [ 0 ]
, & rtP . RandomNumber1_Seed_cspndgusfq [ 0 ] , & rtP .
UniformRandomNumber_Minimum , & rtP . UniformRandomNumber_Maximum , & rtP .
UniformRandomNumber_Seed [ 0 ] , & rtP . data , } ; static int32_T *
rtVarDimsAddrMap [ ] = { ( NULL ) } ;
#endif
static TARGET_CONST rtwCAPI_DataTypeMap rtDataTypeMap [ ] = { { "double" ,
"real_T" , 0 , 0 , sizeof ( real_T ) , SS_DOUBLE , 0 , 0 , 0 } , {
"unsigned char" , "boolean_T" , 0 , 0 , sizeof ( boolean_T ) , SS_BOOLEAN , 0
, 0 , 0 } , { "struct" , "struct_eUgGn14HOPD0Bpc0IaeuNC" , 5 , 1 , sizeof (
struct_eUgGn14HOPD0Bpc0IaeuNC ) , SS_STRUCT , 0 , 0 , 0 } , { "struct" ,
"struct_XG5FAMxlkIOXT4puaiHssC" , 1 , 6 , sizeof (
struct_XG5FAMxlkIOXT4puaiHssC ) , SS_STRUCT , 0 , 0 , 0 } , { "struct" ,
"struct_GxIgcCZnnZi2XW7MM4yafG" , 5 , 7 , sizeof (
struct_GxIgcCZnnZi2XW7MM4yafG ) , SS_STRUCT , 0 , 0 , 0 } , { "struct" ,
"struct_QSaaZsm8gSaKB28J0DSmBB" , 5 , 12 , sizeof (
struct_QSaaZsm8gSaKB28J0DSmBB ) , SS_STRUCT , 0 , 0 , 0 } , { "struct" ,
"struct_j2cokpCYy7yeoacgrc0a1F" , 6 , 17 , sizeof (
struct_j2cokpCYy7yeoacgrc0a1F ) , SS_STRUCT , 0 , 0 , 0 } , { "struct" ,
"struct_tg61sUabKUBlHZYg3O5FcE" , 7 , 23 , sizeof (
struct_tg61sUabKUBlHZYg3O5FcE ) , SS_STRUCT , 0 , 0 , 0 } , { "struct" ,
"struct_QAKcGoErQyD4l7LlU6FAlD" , 3 , 30 , sizeof (
struct_QAKcGoErQyD4l7LlU6FAlD ) , SS_STRUCT , 0 , 0 , 0 } , { "struct" ,
"struct_qa7Kh2PhCOGZmLGFMj6JFF" , 4 , 33 , sizeof (
struct_qa7Kh2PhCOGZmLGFMj6JFF ) , SS_STRUCT , 0 , 0 , 0 } , { "struct" ,
"struct_bEWva6r1fMCyu61B3VBRyF" , 1 , 37 , sizeof (
struct_bEWva6r1fMCyu61B3VBRyF ) , SS_STRUCT , 0 , 0 , 0 } , { "struct" ,
"struct_q9UZ4fke9ut1ZI2Sp6dFRB" , 6 , 38 , sizeof (
struct_q9UZ4fke9ut1ZI2Sp6dFRB ) , SS_STRUCT , 0 , 0 , 0 } , { "struct" ,
"struct_Vw9ymYRXawQBttOglnrOrH" , 4 , 44 , sizeof (
struct_Vw9ymYRXawQBttOglnrOrH ) , SS_STRUCT , 0 , 0 , 0 } , { "struct" ,
"struct_dPmzRL9GR4FaYTvmwD8SE" , 6 , 48 , sizeof (
struct_dPmzRL9GR4FaYTvmwD8SE ) , SS_STRUCT , 0 , 0 , 0 } , { "struct" ,
"struct_u3A3sSehJ9gf2qUJURV4fG" , 3 , 54 , sizeof (
struct_u3A3sSehJ9gf2qUJURV4fG ) , SS_STRUCT , 0 , 0 , 0 } , { "struct" ,
"struct_qSJ0rbcLQyL9m8alQXvOk" , 14 , 57 , sizeof (
struct_qSJ0rbcLQyL9m8alQXvOk ) , SS_STRUCT , 0 , 0 , 0 } } ;
#ifdef HOST_CAPI_BUILD
#undef sizeof
#endif
static TARGET_CONST rtwCAPI_ElementMap rtElementMap [ ] = { { ( NULL ) , 0 ,
0 , 0 , 0 } , { "mass" , rt_offsetof ( struct_eUgGn14HOPD0Bpc0IaeuNC , mass )
, 0 , 5 , 0 } , { "Ix" , rt_offsetof ( struct_eUgGn14HOPD0Bpc0IaeuNC , Ix ) ,
0 , 5 , 0 } , { "Iy" , rt_offsetof ( struct_eUgGn14HOPD0Bpc0IaeuNC , Iy ) , 0
, 5 , 0 } , { "Iz" , rt_offsetof ( struct_eUgGn14HOPD0Bpc0IaeuNC , Iz ) , 0 ,
5 , 0 } , { "inertiaMatrix" , rt_offsetof ( struct_eUgGn14HOPD0Bpc0IaeuNC ,
inertiaMatrix ) , 0 , 1 , 0 } , { "m" , rt_offsetof (
struct_XG5FAMxlkIOXT4puaiHssC , m ) , 0 , 6 , 0 } , { "NBMat" , rt_offsetof (
struct_GxIgcCZnnZi2XW7MM4yafG , NBMat ) , 0 , 7 , 0 } , { "aSurf" ,
rt_offsetof ( struct_GxIgcCZnnZi2XW7MM4yafG , aSurf ) , 0 , 8 , 0 } , {
"rSurf" , rt_offsetof ( struct_GxIgcCZnnZi2XW7MM4yafG , rSurf ) , 0 , 7 , 0 }
, { "rhoS" , rt_offsetof ( struct_GxIgcCZnnZi2XW7MM4yafG , rhoS ) , 0 , 8 , 0
} , { "rhoD" , rt_offsetof ( struct_GxIgcCZnnZi2XW7MM4yafG , rhoD ) , 0 , 8 ,
0 } , { "rSurf" , rt_offsetof ( struct_QSaaZsm8gSaKB28J0DSmBB , rSurf ) , 0 ,
7 , 0 } , { "aSurf" , rt_offsetof ( struct_QSaaZsm8gSaKB28J0DSmBB , aSurf ) ,
0 , 8 , 0 } , { "NBMat" , rt_offsetof ( struct_QSaaZsm8gSaKB28J0DSmBB , NBMat
) , 0 , 7 , 0 } , { "cd" , rt_offsetof ( struct_QSaaZsm8gSaKB28J0DSmBB , cd )
, 0 , 5 , 0 } , { "rho" , rt_offsetof ( struct_QSaaZsm8gSaKB28J0DSmBB , rho )
, 0 , 5 , 0 } , { "FOV" , rt_offsetof ( struct_j2cokpCYy7yeoacgrc0a1F , FOV )
, 0 , 5 , 0 } , { "ABS" , rt_offsetof ( struct_j2cokpCYy7yeoacgrc0a1F , ABS )
, 0 , 1 , 0 } , { "sampleTime" , rt_offsetof ( struct_j2cokpCYy7yeoacgrc0a1F
, sampleTime ) , 0 , 5 , 0 } , { "NStars" , rt_offsetof (
struct_j2cokpCYy7yeoacgrc0a1F , NStars ) , 0 , 5 , 0 } , { "sigmaCross" ,
rt_offsetof ( struct_j2cokpCYy7yeoacgrc0a1F , sigmaCross ) , 0 , 5 , 0 } , {
"sigmaRoll" , rt_offsetof ( struct_j2cokpCYy7yeoacgrc0a1F , sigmaRoll ) , 0 ,
5 , 0 } , { "sampleTime" , rt_offsetof ( struct_tg61sUabKUBlHZYg3O5FcE ,
sampleTime ) , 0 , 5 , 0 } , { "sigmaN" , rt_offsetof (
struct_tg61sUabKUBlHZYg3O5FcE , sigmaN ) , 0 , 5 , 0 } , { "sigmaB" ,
rt_offsetof ( struct_tg61sUabKUBlHZYg3O5FcE , sigmaB ) , 0 , 5 , 0 } , {
"alphaObs" , rt_offsetof ( struct_tg61sUabKUBlHZYg3O5FcE , alphaObs ) , 0 , 5
, 0 } , { "b0" , rt_offsetof ( struct_tg61sUabKUBlHZYg3O5FcE , b0 ) , 0 , 6 ,
0 } , { "kObsABN" , rt_offsetof ( struct_tg61sUabKUBlHZYg3O5FcE , kObsABN ) ,
0 , 5 , 0 } , { "wObs0" , rt_offsetof ( struct_tg61sUabKUBlHZYg3O5FcE , wObs0
) , 0 , 6 , 0 } , { "sigma" , rt_offsetof ( struct_QAKcGoErQyD4l7LlU6FAlD ,
sigma ) , 0 , 5 , 0 } , { "sampleTime" , rt_offsetof (
struct_QAKcGoErQyD4l7LlU6FAlD , sampleTime ) , 0 , 5 , 0 } , {
"nonOrthogonality" , rt_offsetof ( struct_QAKcGoErQyD4l7LlU6FAlD ,
nonOrthogonality ) , 0 , 1 , 0 } , { "axis" , rt_offsetof (
struct_qa7Kh2PhCOGZmLGFMj6JFF , axis ) , 0 , 6 , 0 } , { "hMax" , rt_offsetof
( struct_qa7Kh2PhCOGZmLGFMj6JFF , hMax ) , 0 , 5 , 0 } , { "MMax" ,
rt_offsetof ( struct_qa7Kh2PhCOGZmLGFMj6JFF , MMax ) , 0 , 5 , 0 } , { "h0" ,
rt_offsetof ( struct_qa7Kh2PhCOGZmLGFMj6JFF , h0 ) , 0 , 5 , 0 } , { "DMax" ,
rt_offsetof ( struct_bEWva6r1fMCyu61B3VBRyF , DMax ) , 0 , 6 , 0 } , {
"tDamping" , rt_offsetof ( struct_q9UZ4fke9ut1ZI2Sp6dFRB , tDamping ) , 0 , 5
, 0 } , { "kDamping" , rt_offsetof ( struct_q9UZ4fke9ut1ZI2Sp6dFRB , kDamping
) , 0 , 5 , 0 } , { "tProp" , rt_offsetof ( struct_q9UZ4fke9ut1ZI2Sp6dFRB ,
tProp ) , 0 , 5 , 0 } , { "kProp" , rt_offsetof (
struct_q9UZ4fke9ut1ZI2Sp6dFRB , kProp ) , 0 , 5 , 0 } , { "start" ,
rt_offsetof ( struct_q9UZ4fke9ut1ZI2Sp6dFRB , start ) , 0 , 5 , 0 } , {
"stop" , rt_offsetof ( struct_q9UZ4fke9ut1ZI2Sp6dFRB , stop ) , 0 , 5 , 0 } ,
{ "kWE" , rt_offsetof ( struct_Vw9ymYRXawQBttOglnrOrH , kWE ) , 0 , 5 , 0 } ,
{ "kAE" , rt_offsetof ( struct_Vw9ymYRXawQBttOglnrOrH , kAE ) , 0 , 5 , 0 } ,
{ "start" , rt_offsetof ( struct_Vw9ymYRXawQBttOglnrOrH , start ) , 0 , 5 , 0
} , { "stop" , rt_offsetof ( struct_Vw9ymYRXawQBttOglnrOrH , stop ) , 0 , 5 ,
0 } , { "a" , rt_offsetof ( struct_dPmzRL9GR4FaYTvmwD8SE , a ) , 0 , 5 , 0 }
, { "e" , rt_offsetof ( struct_dPmzRL9GR4FaYTvmwD8SE , e ) , 0 , 5 , 0 } , {
"i" , rt_offsetof ( struct_dPmzRL9GR4FaYTvmwD8SE , i ) , 0 , 5 , 0 } , { "OM"
, rt_offsetof ( struct_dPmzRL9GR4FaYTvmwD8SE , OM ) , 0 , 5 , 0 } , { "om" ,
rt_offsetof ( struct_dPmzRL9GR4FaYTvmwD8SE , om ) , 0 , 5 , 0 } , { "period"
, rt_offsetof ( struct_dPmzRL9GR4FaYTvmwD8SE , period ) , 0 , 5 , 0 } , { "w"
, rt_offsetof ( struct_u3A3sSehJ9gf2qUJURV4fG , w ) , 0 , 6 , 0 } , { "dcm" ,
rt_offsetof ( struct_u3A3sSehJ9gf2qUJURV4fG , dcm ) , 0 , 1 , 0 } , { "th" ,
rt_offsetof ( struct_u3A3sSehJ9gf2qUJURV4fG , th ) , 0 , 5 , 0 } , { "sc" ,
rt_offsetof ( struct_qSJ0rbcLQyL9m8alQXvOk , sc ) , 2 , 5 , 0 } , {
"magneticTorque" , rt_offsetof ( struct_qSJ0rbcLQyL9m8alQXvOk ,
magneticTorque ) , 3 , 5 , 0 } , { "SRP" , rt_offsetof (
struct_qSJ0rbcLQyL9m8alQXvOk , SRP ) , 4 , 5 , 0 } , { "drag" , rt_offsetof (
struct_qSJ0rbcLQyL9m8alQXvOk , drag ) , 5 , 5 , 0 } , { "starSensor" ,
rt_offsetof ( struct_qSJ0rbcLQyL9m8alQXvOk , starSensor ) , 6 , 5 , 0 } , {
"gyroscope" , rt_offsetof ( struct_qSJ0rbcLQyL9m8alQXvOk , gyroscope ) , 7 ,
5 , 0 } , { "magnetometer" , rt_offsetof ( struct_qSJ0rbcLQyL9m8alQXvOk ,
magnetometer ) , 8 , 5 , 0 } , { "reactionWheel" , rt_offsetof (
struct_qSJ0rbcLQyL9m8alQXvOk , reactionWheel ) , 9 , 5 , 0 } , {
"magnetorquer" , rt_offsetof ( struct_qSJ0rbcLQyL9m8alQXvOk , magnetorquer )
, 10 , 5 , 0 } , { "detumbling" , rt_offsetof ( struct_qSJ0rbcLQyL9m8alQXvOk
, detumbling ) , 11 , 5 , 0 } , { "slew" , rt_offsetof (
struct_qSJ0rbcLQyL9m8alQXvOk , slew ) , 12 , 5 , 0 } , { "pointing" ,
rt_offsetof ( struct_qSJ0rbcLQyL9m8alQXvOk , pointing ) , 12 , 5 , 0 } , {
"orbit" , rt_offsetof ( struct_qSJ0rbcLQyL9m8alQXvOk , orbit ) , 13 , 5 , 0 }
, { "ic" , rt_offsetof ( struct_qSJ0rbcLQyL9m8alQXvOk , ic ) , 14 , 5 , 0 } }
; static const rtwCAPI_DimensionMap rtDimensionMap [ ] = { { rtwCAPI_VECTOR ,
0 , 2 , 0 } , { rtwCAPI_MATRIX_COL_MAJOR , 2 , 2 , 0 } , { rtwCAPI_SCALAR , 4
, 2 , 0 } , { rtwCAPI_VECTOR , 6 , 2 , 0 } , { rtwCAPI_VECTOR , 8 , 2 , 0 } ,
{ rtwCAPI_MATRIX_COL_MAJOR , 4 , 2 , 0 } , { rtwCAPI_MATRIX_COL_MAJOR , 0 , 2
, 0 } , { rtwCAPI_MATRIX_COL_MAJOR , 10 , 2 , 0 } , {
rtwCAPI_MATRIX_COL_MAJOR , 12 , 2 , 0 } } ; static const uint_T
rtDimensionArray [ ] = { 3 , 1 , 3 , 3 , 1 , 1 , 8 , 1 , 4 , 1 , 3 , 14 , 14
, 1 } ; static const real_T rtcapiStoredFloats [ ] = { 0.0 , 1.0 } ; static
const rtwCAPI_FixPtMap rtFixPtMap [ ] = { { ( NULL ) , ( NULL ) ,
rtwCAPI_FIX_RESERVED , 0 , 0 , 0 } , } ; static const rtwCAPI_SampleTimeMap
rtSampleTimeMap [ ] = { { ( const void * ) & rtcapiStoredFloats [ 0 ] , (
const void * ) & rtcapiStoredFloats [ 0 ] , 0 , 0 } , { ( const void * ) &
rtcapiStoredFloats [ 1 ] , ( const void * ) & rtcapiStoredFloats [ 0 ] , 1 ,
0 } , { ( NULL ) , ( NULL ) , 2 , 0 } } ; static
rtwCAPI_ModelMappingStaticInfo mmiStatic = { { rtBlockSignals , 51 ,
rtRootInputs , 0 , rtRootOutputs , 0 } , { rtBlockParameters , 18 ,
rtModelParameters , 1 } , { ( NULL ) , 0 } , { rtDataTypeMap , rtDimensionMap
, rtFixPtMap , rtElementMap , rtSampleTimeMap , rtDimensionArray } , "float"
, { 469362051U , 2005292047U , 1163668803U , 920400502U } , ( NULL ) , 0 , 0
} ; const rtwCAPI_ModelMappingStaticInfo * pointing_GetCAPIStaticMap ( void )
{ return & mmiStatic ; }
#ifndef HOST_CAPI_BUILD
void pointing_InitializeDataMapInfo ( void ) { rtwCAPI_SetVersion ( ( *
rt_dataMapInfoPtr ) . mmi , 1 ) ; rtwCAPI_SetStaticMap ( ( *
rt_dataMapInfoPtr ) . mmi , & mmiStatic ) ; rtwCAPI_SetLoggingStaticMap ( ( *
rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ; rtwCAPI_SetDataAddressMap ( ( *
rt_dataMapInfoPtr ) . mmi , rtDataAddrMap ) ; rtwCAPI_SetVarDimsAddressMap (
( * rt_dataMapInfoPtr ) . mmi , rtVarDimsAddrMap ) ;
rtwCAPI_SetInstanceLoggingInfo ( ( * rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArray ( ( * rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArrayLen ( ( * rt_dataMapInfoPtr ) . mmi , 0 ) ; }
#else
#ifdef __cplusplus
extern "C" {
#endif
void pointing_host_InitializeDataMapInfo ( pointing_host_DataMapInfo_T *
dataMap , const char * path ) { rtwCAPI_SetVersion ( dataMap -> mmi , 1 ) ;
rtwCAPI_SetStaticMap ( dataMap -> mmi , & mmiStatic ) ;
rtwCAPI_SetDataAddressMap ( dataMap -> mmi , NULL ) ;
rtwCAPI_SetVarDimsAddressMap ( dataMap -> mmi , NULL ) ; rtwCAPI_SetPath (
dataMap -> mmi , path ) ; rtwCAPI_SetFullPath ( dataMap -> mmi , NULL ) ;
rtwCAPI_SetChildMMIArray ( dataMap -> mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArrayLen ( dataMap -> mmi , 0 ) ; }
#ifdef __cplusplus
}
#endif
#endif
