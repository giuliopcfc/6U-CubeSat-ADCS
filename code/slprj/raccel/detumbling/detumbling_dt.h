#include "ext_types.h"
static DataTypeInfo rtDataTypeInfoTable [ ] = { { "real_T" , 0 , 8 } , {
"real32_T" , 1 , 4 } , { "int8_T" , 2 , 1 } , { "uint8_T" , 3 , 1 } , {
"int16_T" , 4 , 2 } , { "uint16_T" , 5 , 2 } , { "int32_T" , 6 , 4 } , {
"uint32_T" , 7 , 4 } , { "boolean_T" , 8 , 1 } , { "fcn_call_T" , 9 , 0 } , {
"int_T" , 10 , 4 } , { "pointer_T" , 11 , 8 } , { "action_T" , 12 , 8 } , {
"timer_uint32_pair_T" , 13 , 8 } , { "struct_eUgGn14HOPD0Bpc0IaeuNC" , 14 ,
104 } , { "struct_XG5FAMxlkIOXT4puaiHssC" , 15 , 24 } , {
"struct_GxIgcCZnnZi2XW7MM4yafG" , 16 , 1008 } , {
"struct_EHtN1x5qWtYvB6pU0c2gGF" , 17 , 104 } , {
"struct_T6zddYes4JQpYlTi8Ruu5C" , 18 , 56 } , {
"struct_O1pciIi8r5tjT0E3G93D2E" , 19 , 16 } , {
"struct_qa7Kh2PhCOGZmLGFMj6JFF" , 20 , 48 } , {
"struct_Y0CsNP7FxxqcbNrarEmwu" , 21 , 8 } , { "struct_q9UZ4fke9ut1ZI2Sp6dFRB"
, 22 , 48 } , { "struct_Vw9ymYRXawQBttOglnrOrH" , 23 , 32 } , {
"struct_o9tEnzU2nL5brVUK178jXH" , 24 , 1312 } , {
"struct_13VjrurLAGGZCU8fJR8AlC" , 25 , 16 } , {
"struct_v5pqJBUYAGyDEHvqKQ1mIE" , 26 , 120 } , {
"struct_u3A3sSehJ9gf2qUJURV4fG" , 27 , 104 } , {
"struct_RjN6PJWIgZ1lo7o6ytzxsD" , 28 , 8 } , {
"struct_x623vNJbabtEp5rvCT4fWG" , 29 , 3008 } } ; static uint_T
rtDataTypeSizes [ ] = { sizeof ( real_T ) , sizeof ( real32_T ) , sizeof (
int8_T ) , sizeof ( uint8_T ) , sizeof ( int16_T ) , sizeof ( uint16_T ) ,
sizeof ( int32_T ) , sizeof ( uint32_T ) , sizeof ( boolean_T ) , sizeof (
fcn_call_T ) , sizeof ( int_T ) , sizeof ( pointer_T ) , sizeof ( action_T )
, 2 * sizeof ( uint32_T ) , sizeof ( struct_eUgGn14HOPD0Bpc0IaeuNC ) , sizeof
( struct_XG5FAMxlkIOXT4puaiHssC ) , sizeof ( struct_GxIgcCZnnZi2XW7MM4yafG )
, sizeof ( struct_EHtN1x5qWtYvB6pU0c2gGF ) , sizeof (
struct_T6zddYes4JQpYlTi8Ruu5C ) , sizeof ( struct_O1pciIi8r5tjT0E3G93D2E ) ,
sizeof ( struct_qa7Kh2PhCOGZmLGFMj6JFF ) , sizeof (
struct_Y0CsNP7FxxqcbNrarEmwu ) , sizeof ( struct_q9UZ4fke9ut1ZI2Sp6dFRB ) ,
sizeof ( struct_Vw9ymYRXawQBttOglnrOrH ) , sizeof (
struct_o9tEnzU2nL5brVUK178jXH ) , sizeof ( struct_13VjrurLAGGZCU8fJR8AlC ) ,
sizeof ( struct_v5pqJBUYAGyDEHvqKQ1mIE ) , sizeof (
struct_u3A3sSehJ9gf2qUJURV4fG ) , sizeof ( struct_RjN6PJWIgZ1lo7o6ytzxsD ) ,
sizeof ( int32_T ) } ; static const char_T * rtDataTypeNames [ ] = { "real_T"
, "real32_T" , "int8_T" , "uint8_T" , "int16_T" , "uint16_T" , "int32_T" ,
"uint32_T" , "boolean_T" , "fcn_call_T" , "int_T" , "pointer_T" , "action_T"
, "timer_uint32_pair_T" , "struct_eUgGn14HOPD0Bpc0IaeuNC" ,
"struct_XG5FAMxlkIOXT4puaiHssC" , "struct_GxIgcCZnnZi2XW7MM4yafG" ,
"struct_EHtN1x5qWtYvB6pU0c2gGF" , "struct_T6zddYes4JQpYlTi8Ruu5C" ,
"struct_O1pciIi8r5tjT0E3G93D2E" , "struct_qa7Kh2PhCOGZmLGFMj6JFF" ,
"struct_Y0CsNP7FxxqcbNrarEmwu" , "struct_q9UZ4fke9ut1ZI2Sp6dFRB" ,
"struct_Vw9ymYRXawQBttOglnrOrH" , "struct_o9tEnzU2nL5brVUK178jXH" ,
"struct_13VjrurLAGGZCU8fJR8AlC" , "struct_v5pqJBUYAGyDEHvqKQ1mIE" ,
"struct_u3A3sSehJ9gf2qUJURV4fG" , "struct_RjN6PJWIgZ1lo7o6ytzxsD" ,
"struct_x623vNJbabtEp5rvCT4fWG" } ; static DataTypeTransition rtBTransitions
[ ] = { { ( char_T * ) ( & rtB . ela1rhmmmi ) , 0 , 0 , 99 } , { ( char_T * )
( & rtB . b13up4rwa2 ) , 8 , 0 , 1 } , { ( char_T * ) ( & rtDW . a5tv4scxvv [
0 ] ) , 0 , 0 , 10 } , { ( char_T * ) ( & rtDW . ja1mjqygva . TUbufferPtrs [
0 ] ) , 11 , 0 , 11 } , { ( char_T * ) ( & rtDW . p3k2zi5joj [ 0 ] ) , 7 , 0
, 9 } , { ( char_T * ) ( & rtDW . hxmmr0vle1 . Tail [ 0 ] ) , 10 , 0 , 14 } ,
{ ( char_T * ) ( & rtDW . klnbyfrse2 ) , 8 , 0 , 2 } } ; static
DataTypeTransitionTable rtBTransTable = { 7U , rtBTransitions } ; static
DataTypeTransition rtPTransitions [ ] = { { ( char_T * ) ( & rtP .
Integrator_IC ) , 0 , 0 , 219 } } ; static DataTypeTransitionTable
rtPTransTable = { 1U , rtPTransitions } ;
