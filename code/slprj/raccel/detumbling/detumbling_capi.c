#include "rtw_capi.h"
#ifdef HOST_CAPI_BUILD
#include "detumbling_capi_host.h"
#define sizeof(s) ((size_t)(0xFFFF))
#undef rt_offsetof
#define rt_offsetof(s,el) ((uint16_T)(0xFFFF))
#define TARGET_CONST
#define TARGET_STRING(s) (s)    
#else
#include "builtin_typeid_types.h"
#include "detumbling.h"
#include "detumbling_capi.h"
#include "detumbling_private.h"
#ifdef LIGHT_WEIGHT_CAPI
#define TARGET_CONST                  
#define TARGET_STRING(s)               (NULL)                    
#else
#define TARGET_CONST                   const
#define TARGET_STRING(s)               (s)
#endif
#endif
static const rtwCAPI_Signals rtBlockSignals [ ] = { { 0 , 0 , TARGET_STRING (
"detumbling/Add" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 1 , 1 ,
TARGET_STRING ( "detumbling/Control and Actuators/Actuators " ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 2 , 2 , TARGET_STRING (
"detumbling/Control and Actuators/Control " ) , TARGET_STRING ( "" ) , 1 , 0
, 1 , 0 , 0 } , { 3 , 2 , TARGET_STRING (
"detumbling/Control and Actuators/Control " ) , TARGET_STRING ( "" ) , 2 , 0
, 0 , 0 , 0 } , { 4 , 0 , TARGET_STRING (
"detumbling/Control and Actuators/Integrator" ) , TARGET_STRING ( "" ) , 0 ,
0 , 1 , 0 , 0 } , { 5 , 0 , TARGET_STRING (
"detumbling/Control and Actuators/Add" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 ,
0 , 0 } , { 6 , 0 , TARGET_STRING (
"detumbling/Control and Actuators/Transport Delay" ) , TARGET_STRING ( "" ) ,
0 , 0 , 0 , 0 , 0 } , { 7 , 3 , TARGET_STRING (
"detumbling/Direct Cosine Matrix/MATLAB Function" ) , TARGET_STRING ( "" ) ,
0 , 0 , 2 , 0 , 0 } , { 8 , 4 , TARGET_STRING (
"detumbling/Direct Cosine Matrix/MATLAB Function1" ) , TARGET_STRING ( "" ) ,
0 , 0 , 2 , 0 , 0 } , { 9 , 0 , TARGET_STRING (
"detumbling/Direct Cosine Matrix/Integrator" ) , TARGET_STRING ( "" ) , 0 , 0
, 2 , 0 , 0 } , { 10 , 0 , TARGET_STRING ( "detumbling/Environment/Add" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 11 , 14 , TARGET_STRING (
"detumbling/Euler Equations/MATLAB Function" ) , TARGET_STRING ( "" ) , 0 , 0
, 0 , 0 , 0 } , { 12 , 0 , TARGET_STRING (
"detumbling/Euler Equations/Integrator" ) , TARGET_STRING ( "" ) , 0 , 0 , 0
, 0 , 0 } , { 13 , 0 , TARGET_STRING ( "detumbling/Sensors/Add1" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 14 , 0 , TARGET_STRING (
"detumbling/Sensors/Add2" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , {
15 , 0 , TARGET_STRING ( "detumbling/Sensors/Add3" ) , TARGET_STRING ( "" ) ,
0 , 0 , 0 , 0 , 0 } , { 16 , 10 , TARGET_STRING (
"detumbling/Environment/Unperturbed Orbit/MATLAB Function" ) , TARGET_STRING
( "" ) , 0 , 0 , 1 , 0 , 0 } , { 17 , 0 , TARGET_STRING (
"detumbling/Environment/Unperturbed Orbit/Integrator" ) , TARGET_STRING ( ""
) , 0 , 0 , 1 , 0 , 0 } , { 18 , 0 , TARGET_STRING (
"detumbling/Sensors/Gyroscope/Clock" ) , TARGET_STRING ( "" ) , 0 , 0 , 1 , 0
, 0 } , { 19 , 0 , TARGET_STRING ( "detumbling/Sensors/Gyroscope/Integrator"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 20 , 0 , TARGET_STRING (
"detumbling/Sensors/Gyroscope/Product" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 ,
0 , 1 } , { 21 , 0 , TARGET_STRING (
"detumbling/Sensors/Gyroscope/Random Number" ) , TARGET_STRING ( "" ) , 0 , 0
, 0 , 0 , 2 } , { 22 , 0 , TARGET_STRING (
"detumbling/Sensors/Gyroscope/Random Number1" ) , TARGET_STRING ( "" ) , 0 ,
0 , 0 , 0 , 2 } , { 23 , 0 , TARGET_STRING (
"detumbling/Sensors/Gyroscope/Add" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 ,
0 } , { 24 , 0 , TARGET_STRING (
"detumbling/Sensors/Gyroscope/Zero-Order Hold" ) , TARGET_STRING ( "" ) , 0 ,
0 , 0 , 0 , 2 } , { 25 , 0 , TARGET_STRING (
"detumbling/Sensors/Magnetometer/Random Number1" ) , TARGET_STRING ( "" ) , 0
, 0 , 0 , 0 , 3 } , { 26 , 0 , TARGET_STRING (
"detumbling/Sensors/Magnetometer/Add" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 ,
0 , 0 } , { 27 , 0 , TARGET_STRING (
"detumbling/Sensors/Magnetometer/Zero-Order Hold" ) , TARGET_STRING ( "" ) ,
0 , 0 , 0 , 0 , 3 } , { 28 , 0 , TARGET_STRING (
"detumbling/Sensors/Observer/Clock" ) , TARGET_STRING ( "" ) , 0 , 0 , 1 , 0
, 0 } , { 29 , 0 , TARGET_STRING ( "detumbling/Sensors/Observer/Integrator" )
, TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 30 , 0 , TARGET_STRING (
"detumbling/Sensors/Observer/Product" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 ,
0 , 0 } , { 31 , 0 , TARGET_STRING (
"detumbling/Sensors/Observer/GreaterThan" ) , TARGET_STRING ( "" ) , 0 , 1 ,
1 , 0 , 1 } , { 0 , 0 , ( NULL ) , ( NULL ) , 0 , 0 , 0 , 0 , 0 } } ; static
const rtwCAPI_BlockParameters rtBlockParameters [ ] = { { 32 , TARGET_STRING
( "detumbling/Control and Actuators/Constant" ) , TARGET_STRING ( "Value" ) ,
0 , 1 , 0 } , { 33 , TARGET_STRING (
"detumbling/Control and Actuators/Constant1" ) , TARGET_STRING ( "Value" ) ,
0 , 1 , 0 } , { 34 , TARGET_STRING (
"detumbling/Control and Actuators/Constant2" ) , TARGET_STRING ( "Value" ) ,
0 , 1 , 0 } , { 35 , TARGET_STRING (
"detumbling/Control and Actuators/Constant3" ) , TARGET_STRING ( "Value" ) ,
0 , 1 , 0 } , { 36 , TARGET_STRING (
"detumbling/Control and Actuators/Constant4" ) , TARGET_STRING ( "Value" ) ,
0 , 1 , 0 } , { 37 , TARGET_STRING (
"detumbling/Control and Actuators/Constant5" ) , TARGET_STRING ( "Value" ) ,
0 , 0 , 0 } , { 38 , TARGET_STRING (
"detumbling/Control and Actuators/Constant6" ) , TARGET_STRING ( "Value" ) ,
0 , 1 , 0 } , { 39 , TARGET_STRING (
"detumbling/Control and Actuators/Constant7" ) , TARGET_STRING ( "Value" ) ,
0 , 1 , 0 } , { 40 , TARGET_STRING (
"detumbling/Control and Actuators/Constant9" ) , TARGET_STRING ( "Value" ) ,
0 , 0 , 0 } , { 41 , TARGET_STRING (
"detumbling/Control and Actuators/Integrator" ) , TARGET_STRING (
"InitialCondition" ) , 0 , 1 , 0 } , { 42 , TARGET_STRING (
"detumbling/Control and Actuators/Transport Delay" ) , TARGET_STRING (
"DelayTime" ) , 0 , 1 , 0 } , { 43 , TARGET_STRING (
"detumbling/Control and Actuators/Transport Delay" ) , TARGET_STRING (
"InitialOutput" ) , 0 , 0 , 0 } , { 44 , TARGET_STRING (
"detumbling/Direct Cosine Matrix/Integrator" ) , TARGET_STRING (
"InitialCondition" ) , 0 , 2 , 0 } , { 45 , TARGET_STRING (
"detumbling/Environment/Constant" ) , TARGET_STRING ( "Value" ) , 0 , 2 , 0 }
, { 46 , TARGET_STRING ( "detumbling/Environment/Constant1" ) , TARGET_STRING
( "Value" ) , 0 , 0 , 0 } , { 47 , TARGET_STRING (
"detumbling/Environment/Constant2" ) , TARGET_STRING ( "Value" ) , 0 , 3 , 0
} , { 48 , TARGET_STRING ( "detumbling/Environment/Constant3" ) ,
TARGET_STRING ( "Value" ) , 0 , 3 , 0 } , { 49 , TARGET_STRING (
"detumbling/Environment/Constant4" ) , TARGET_STRING ( "Value" ) , 0 , 4 , 0
} , { 50 , TARGET_STRING ( "detumbling/Environment/Constant5" ) ,
TARGET_STRING ( "Value" ) , 0 , 4 , 0 } , { 51 , TARGET_STRING (
"detumbling/Environment/Constant6" ) , TARGET_STRING ( "Value" ) , 0 , 3 , 0
} , { 52 , TARGET_STRING ( "detumbling/Euler Equations/Constant" ) ,
TARGET_STRING ( "Value" ) , 0 , 2 , 0 } , { 53 , TARGET_STRING (
"detumbling/Euler Equations/Integrator" ) , TARGET_STRING (
"InitialCondition" ) , 0 , 0 , 0 } , { 54 , TARGET_STRING (
"detumbling/Environment/Unperturbed Orbit/Constant" ) , TARGET_STRING (
"Value" ) , 0 , 1 , 0 } , { 55 , TARGET_STRING (
"detumbling/Environment/Unperturbed Orbit/Constant1" ) , TARGET_STRING (
"Value" ) , 0 , 1 , 0 } , { 56 , TARGET_STRING (
"detumbling/Environment/Unperturbed Orbit/Constant2" ) , TARGET_STRING (
"Value" ) , 0 , 1 , 0 } , { 57 , TARGET_STRING (
"detumbling/Environment/Unperturbed Orbit/Constant3" ) , TARGET_STRING (
"Value" ) , 0 , 1 , 0 } , { 58 , TARGET_STRING (
"detumbling/Environment/Unperturbed Orbit/Constant4" ) , TARGET_STRING (
"Value" ) , 0 , 1 , 0 } , { 59 , TARGET_STRING (
"detumbling/Environment/Unperturbed Orbit/Integrator" ) , TARGET_STRING (
"InitialCondition" ) , 0 , 1 , 0 } , { 60 , TARGET_STRING (
"detumbling/Sensors/Gyroscope/Constant" ) , TARGET_STRING ( "Value" ) , 0 , 1
, 0 } , { 61 , TARGET_STRING ( "detumbling/Sensors/Gyroscope/Integrator" ) ,
TARGET_STRING ( "InitialCondition" ) , 0 , 0 , 0 } , { 62 , TARGET_STRING (
"detumbling/Sensors/Gyroscope/Random Number" ) , TARGET_STRING ( "Mean" ) , 0
, 1 , 0 } , { 63 , TARGET_STRING (
"detumbling/Sensors/Gyroscope/Random Number" ) , TARGET_STRING ( "StdDev" ) ,
0 , 0 , 0 } , { 64 , TARGET_STRING (
"detumbling/Sensors/Gyroscope/Random Number" ) , TARGET_STRING ( "Seed" ) , 0
, 0 , 0 } , { 65 , TARGET_STRING (
"detumbling/Sensors/Gyroscope/Random Number1" ) , TARGET_STRING ( "Mean" ) ,
0 , 1 , 0 } , { 66 , TARGET_STRING (
"detumbling/Sensors/Gyroscope/Random Number1" ) , TARGET_STRING ( "StdDev" )
, 0 , 0 , 0 } , { 67 , TARGET_STRING (
"detumbling/Sensors/Gyroscope/Random Number1" ) , TARGET_STRING ( "Seed" ) ,
0 , 0 , 0 } , { 68 , TARGET_STRING (
"detumbling/Sensors/Magnetometer/Random Number1" ) , TARGET_STRING ( "Mean" )
, 0 , 1 , 0 } , { 69 , TARGET_STRING (
"detumbling/Sensors/Magnetometer/Random Number1" ) , TARGET_STRING ( "StdDev"
) , 0 , 0 , 0 } , { 70 , TARGET_STRING (
"detumbling/Sensors/Magnetometer/Random Number1" ) , TARGET_STRING ( "Seed" )
, 0 , 0 , 0 } , { 71 , TARGET_STRING ( "detumbling/Sensors/Observer/Constant"
) , TARGET_STRING ( "Value" ) , 0 , 2 , 0 } , { 72 , TARGET_STRING (
"detumbling/Sensors/Observer/Constant1" ) , TARGET_STRING ( "Value" ) , 0 , 1
, 0 } , { 73 , TARGET_STRING ( "detumbling/Sensors/Observer/Constant2" ) ,
TARGET_STRING ( "Value" ) , 0 , 1 , 0 } , { 0 , ( NULL ) , ( NULL ) , 0 , 0 ,
0 } } ; static const rtwCAPI_Signals rtRootInputs [ ] = { { 0 , 0 , ( NULL )
, ( NULL ) , 0 , 0 , 0 , 0 , 0 } } ; static const rtwCAPI_Signals
rtRootOutputs [ ] = { { 0 , 0 , ( NULL ) , ( NULL ) , 0 , 0 , 0 , 0 , 0 } } ;
static const rtwCAPI_ModelParameters rtModelParameters [ ] = { { 0 , ( NULL )
, 0 , 0 , 0 } } ;
#ifndef HOST_CAPI_BUILD
static void * rtDataAddrMap [ ] = { & rtB . ey2mmw0csp [ 0 ] , & rtB .
pldpuimngh [ 0 ] , & rtB . e4c42ch1lv , & rtB . nvcvw4zh5h [ 0 ] , & rtB .
h2dle1tjk3 , & rtB . c1dnkkzf2p [ 0 ] , & rtB . fh0tz1ct3t [ 0 ] , & rtB .
e1l1mwc2wk [ 0 ] , & rtB . p13uq5o22a [ 0 ] , & rtB . jbo3v4ajb3 [ 0 ] , &
rtB . cw2k3svoeb [ 0 ] , & rtB . farw3endkt [ 0 ] , & rtB . kl0s5rlxlx [ 0 ]
, & rtB . ptpgqwsog2 [ 0 ] , & rtB . bgsqzfr5vf [ 0 ] , & rtB . jd4glhy2th [
0 ] , & rtB . gnn2xcjhaq , & rtB . ela1rhmmmi , & rtB . cncjtrvy1r , & rtB .
d0bsyboket [ 0 ] , & rtB . bx5l1cxe42 [ 0 ] , & rtB . dlgknc2iej [ 0 ] , &
rtB . pxjxltf32i [ 0 ] , & rtB . lkneu0sjol [ 0 ] , & rtB . gcsyrgudhi [ 0 ]
, & rtB . ahdpwrjj5d [ 0 ] , & rtB . bqon2dgr5d [ 0 ] , & rtB . nrhgec3vav [
0 ] , & rtB . l1nazchf2g , & rtB . pkc5yfmw2v [ 0 ] , & rtB . fiyrbaaxb5 [ 0
] , & rtB . b13up4rwa2 , & rtP . Constant_Value , & rtP . Constant1_Value , &
rtP . Constant2_Value , & rtP . Constant3_Value , & rtP . Constant4_Value , &
rtP . Constant5_Value [ 0 ] , & rtP . Constant6_Value , & rtP .
Constant7_Value , & rtP . Constant9_Value [ 0 ] , & rtP .
Integrator_IC_lc2l1uvn30 , & rtP . TransportDelay_Delay , & rtP .
TransportDelay_InitOutput [ 0 ] , & rtP . Integrator_IC_ifj3pkofzc [ 0 ] , &
rtP . Constant_Value_nedwe54uwp [ 0 ] , & rtP . Constant1_Value_iuwa1a4rwo [
0 ] , & rtP . Constant2_Value_p0tf13dhms [ 0 ] , & rtP .
Constant3_Value_mitst2s14q [ 0 ] , & rtP . Constant4_Value_hr4vhts24r [ 0 ] ,
& rtP . Constant5_Value_oj3yslavn5 [ 0 ] , & rtP . Constant6_Value_bsw1z5ftyf
[ 0 ] , & rtP . Constant_Value_noh4pr4dj2 [ 0 ] , & rtP .
Integrator_IC_c5e44kpjcd [ 0 ] , & rtP . Constant_Value_kb0zyegq3x , & rtP .
Constant1_Value_lapgl51prt , & rtP . Constant2_Value_pn5msfmygz , & rtP .
Constant3_Value_lnlpkng3dr , & rtP . Constant4_Value_plq0xk0dqt , & rtP .
Integrator_IC , & rtP . Constant_Value_jedkd3oz4q , & rtP .
Integrator_IC_juij5hh4y1 [ 0 ] , & rtP . RandomNumber_Mean , & rtP .
RandomNumber_StdDev [ 0 ] , & rtP . RandomNumber_Seed [ 0 ] , & rtP .
RandomNumber1_Mean_pp0amcle2e , & rtP . RandomNumber1_StdDev_cudqkp3bpx [ 0 ]
, & rtP . RandomNumber1_Seed_gnd4ve32hq [ 0 ] , & rtP . RandomNumber1_Mean ,
& rtP . RandomNumber1_StdDev [ 0 ] , & rtP . RandomNumber1_Seed [ 0 ] , & rtP
. Constant_Value_m3i1kxbif4 [ 0 ] , & rtP . Constant1_Value_cw3pti1zff , &
rtP . Constant2_Value_jgk4nzciuj , } ; static int32_T * rtVarDimsAddrMap [ ]
= { ( NULL ) } ;
#endif
static TARGET_CONST rtwCAPI_DataTypeMap rtDataTypeMap [ ] = { { "double" ,
"real_T" , 0 , 0 , sizeof ( real_T ) , SS_DOUBLE , 0 , 0 , 0 } , {
"unsigned char" , "boolean_T" , 0 , 0 , sizeof ( boolean_T ) , SS_BOOLEAN , 0
, 0 , 0 } } ;
#ifdef HOST_CAPI_BUILD
#undef sizeof
#endif
static TARGET_CONST rtwCAPI_ElementMap rtElementMap [ ] = { { ( NULL ) , 0 ,
0 , 0 , 0 } , } ; static const rtwCAPI_DimensionMap rtDimensionMap [ ] = { {
rtwCAPI_VECTOR , 0 , 2 , 0 } , { rtwCAPI_SCALAR , 2 , 2 , 0 } , {
rtwCAPI_MATRIX_COL_MAJOR , 4 , 2 , 0 } , { rtwCAPI_VECTOR , 6 , 2 , 0 } , {
rtwCAPI_MATRIX_COL_MAJOR , 8 , 2 , 0 } } ; static const uint_T
rtDimensionArray [ ] = { 3 , 1 , 1 , 1 , 3 , 3 , 14 , 1 , 3 , 14 } ; static
const real_T rtcapiStoredFloats [ ] = { 0.0 , 1.0 , 0.01 , 0.1 } ; static
const rtwCAPI_FixPtMap rtFixPtMap [ ] = { { ( NULL ) , ( NULL ) ,
rtwCAPI_FIX_RESERVED , 0 , 0 , 0 } , } ; static const rtwCAPI_SampleTimeMap
rtSampleTimeMap [ ] = { { ( const void * ) & rtcapiStoredFloats [ 0 ] , (
const void * ) & rtcapiStoredFloats [ 0 ] , 0 , 0 } , { ( const void * ) &
rtcapiStoredFloats [ 0 ] , ( const void * ) & rtcapiStoredFloats [ 1 ] , 1 ,
0 } , { ( const void * ) & rtcapiStoredFloats [ 2 ] , ( const void * ) &
rtcapiStoredFloats [ 0 ] , 2 , 0 } , { ( const void * ) & rtcapiStoredFloats
[ 3 ] , ( const void * ) & rtcapiStoredFloats [ 0 ] , 3 , 0 } } ; static
rtwCAPI_ModelMappingStaticInfo mmiStatic = { { rtBlockSignals , 32 ,
rtRootInputs , 0 , rtRootOutputs , 0 } , { rtBlockParameters , 42 ,
rtModelParameters , 0 } , { ( NULL ) , 0 } , { rtDataTypeMap , rtDimensionMap
, rtFixPtMap , rtElementMap , rtSampleTimeMap , rtDimensionArray } , "float"
, { 2063736516U , 611031575U , 3190133955U , 305185540U } , ( NULL ) , 0 , 0
} ; const rtwCAPI_ModelMappingStaticInfo * detumbling_GetCAPIStaticMap ( void
) { return & mmiStatic ; }
#ifndef HOST_CAPI_BUILD
void detumbling_InitializeDataMapInfo ( void ) { rtwCAPI_SetVersion ( ( *
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
void detumbling_host_InitializeDataMapInfo ( detumbling_host_DataMapInfo_T *
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
