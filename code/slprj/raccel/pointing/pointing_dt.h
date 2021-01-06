#include "ext_types.h"
static DataTypeInfo rtDataTypeInfoTable [ ] = { { "real_T" , 0 , 8 } , {
"real32_T" , 1 , 4 } , { "int8_T" , 2 , 1 } , { "uint8_T" , 3 , 1 } , {
"int16_T" , 4 , 2 } , { "uint16_T" , 5 , 2 } , { "int32_T" , 6 , 4 } , {
"uint32_T" , 7 , 4 } , { "boolean_T" , 8 , 1 } , { "fcn_call_T" , 9 , 0 } , {
"int_T" , 10 , 4 } , { "pointer_T" , 11 , 8 } , { "action_T" , 12 , 8 } , {
"timer_uint32_pair_T" , 13 , 8 } , { "struct_eUgGn14HOPD0Bpc0IaeuNC" , 14 ,
104 } , { "struct_XG5FAMxlkIOXT4puaiHssC" , 15 , 24 } , {
"struct_GxIgcCZnnZi2XW7MM4yafG" , 16 , 1008 } , {
"struct_QSaaZsm8gSaKB28J0DSmBB" , 17 , 800 } , {
"struct_j2cokpCYy7yeoacgrc0a1F" , 18 , 112 } , {
"struct_tg61sUabKUBlHZYg3O5FcE" , 19 , 88 } , {
"struct_QAKcGoErQyD4l7LlU6FAlD" , 20 , 88 } , {
"struct_qa7Kh2PhCOGZmLGFMj6JFF" , 21 , 48 } , {
"struct_bEWva6r1fMCyu61B3VBRyF" , 22 , 24 } , {
"struct_q9UZ4fke9ut1ZI2Sp6dFRB" , 23 , 48 } , {
"struct_Vw9ymYRXawQBttOglnrOrH" , 24 , 32 } , {
"struct_dPmzRL9GR4FaYTvmwD8SE" , 25 , 48 } , {
"struct_u3A3sSehJ9gf2qUJURV4fG" , 26 , 104 } , {
"struct_qSJ0rbcLQyL9m8alQXvOk" , 27 , 2560 } } ; static uint_T
rtDataTypeSizes [ ] = { sizeof ( real_T ) , sizeof ( real32_T ) , sizeof (
int8_T ) , sizeof ( uint8_T ) , sizeof ( int16_T ) , sizeof ( uint16_T ) ,
sizeof ( int32_T ) , sizeof ( uint32_T ) , sizeof ( boolean_T ) , sizeof (
fcn_call_T ) , sizeof ( int_T ) , sizeof ( pointer_T ) , sizeof ( action_T )
, 2 * sizeof ( uint32_T ) , sizeof ( struct_eUgGn14HOPD0Bpc0IaeuNC ) , sizeof
( struct_XG5FAMxlkIOXT4puaiHssC ) , sizeof ( struct_GxIgcCZnnZi2XW7MM4yafG )
, sizeof ( struct_QSaaZsm8gSaKB28J0DSmBB ) , sizeof (
struct_j2cokpCYy7yeoacgrc0a1F ) , sizeof ( struct_tg61sUabKUBlHZYg3O5FcE ) ,
sizeof ( struct_QAKcGoErQyD4l7LlU6FAlD ) , sizeof (
struct_qa7Kh2PhCOGZmLGFMj6JFF ) , sizeof ( struct_bEWva6r1fMCyu61B3VBRyF ) ,
sizeof ( struct_q9UZ4fke9ut1ZI2Sp6dFRB ) , sizeof (
struct_Vw9ymYRXawQBttOglnrOrH ) , sizeof ( struct_dPmzRL9GR4FaYTvmwD8SE ) ,
sizeof ( struct_u3A3sSehJ9gf2qUJURV4fG ) , sizeof (
struct_qSJ0rbcLQyL9m8alQXvOk ) } ; static const char_T * rtDataTypeNames [ ]
= { "real_T" , "real32_T" , "int8_T" , "uint8_T" , "int16_T" , "uint16_T" ,
"int32_T" , "uint32_T" , "boolean_T" , "fcn_call_T" , "int_T" , "pointer_T" ,
"action_T" , "timer_uint32_pair_T" , "struct_eUgGn14HOPD0Bpc0IaeuNC" ,
"struct_XG5FAMxlkIOXT4puaiHssC" , "struct_GxIgcCZnnZi2XW7MM4yafG" ,
"struct_QSaaZsm8gSaKB28J0DSmBB" , "struct_j2cokpCYy7yeoacgrc0a1F" ,
"struct_tg61sUabKUBlHZYg3O5FcE" , "struct_QAKcGoErQyD4l7LlU6FAlD" ,
"struct_qa7Kh2PhCOGZmLGFMj6JFF" , "struct_bEWva6r1fMCyu61B3VBRyF" ,
"struct_q9UZ4fke9ut1ZI2Sp6dFRB" , "struct_Vw9ymYRXawQBttOglnrOrH" ,
"struct_dPmzRL9GR4FaYTvmwD8SE" , "struct_u3A3sSehJ9gf2qUJURV4fG" ,
"struct_qSJ0rbcLQyL9m8alQXvOk" } ; static DataTypeTransition rtBTransitions [
] = { { ( char_T * ) ( & rtB . haaoe3krmo [ 0 ] ) , 0 , 0 , 124 } , { (
char_T * ) ( & rtB . mkszl352m3 ) , 8 , 0 , 1 } , { ( char_T * ) ( & rtB .
eje25gfouo . g540wbqcci [ 0 ] ) , 0 , 0 , 3 } , { ( char_T * ) ( & rtB .
nzapizli54 . fws4iwogpu [ 0 ] ) , 0 , 0 , 9 } , { ( char_T * ) ( & rtB .
hid2a3ighm . a4etz1spm4 [ 0 ] ) , 0 , 0 , 15 } , { ( char_T * ) ( & rtB .
cz1perd2ej . gmfjxhcwab ) , 0 , 0 , 1 } , { ( char_T * ) ( & rtB . arbgebpnzf
. ekyf2ft5xv [ 0 ] ) , 0 , 0 , 3 } , { ( char_T * ) ( & rtB . mssjub5nr2 .
fyfzf3djiy [ 0 ] ) , 0 , 0 , 3 } , { ( char_T * ) ( & rtB . gwhniowyem .
g540wbqcci [ 0 ] ) , 0 , 0 , 3 } , { ( char_T * ) ( & rtB . lb5tuw34lz .
fws4iwogpu [ 0 ] ) , 0 , 0 , 9 } , { ( char_T * ) ( & rtB . ituo30pkvd .
a4etz1spm4 [ 0 ] ) , 0 , 0 , 15 } , { ( char_T * ) ( & rtB . imixbcpj4x .
gmfjxhcwab ) , 0 , 0 , 1 } , { ( char_T * ) ( & rtB . eagdjb5elr . ekyf2ft5xv
[ 0 ] ) , 0 , 0 , 3 } , { ( char_T * ) ( & rtB . lqknz2kefj . fyfzf3djiy [ 0
] ) , 0 , 0 , 3 } , { ( char_T * ) ( & rtDW . n1mf5f1loj [ 0 ] ) , 0 , 0 , 29
} , { ( char_T * ) ( & rtDW . npodssysd1 . LoggedData ) , 11 , 0 , 5 } , { (
char_T * ) ( & rtDW . ewjz1wr2fe [ 0 ] ) , 7 , 0 , 29 } , { ( char_T * ) ( &
rtDW . h5pffuqljc ) , 10 , 0 , 2 } , { ( char_T * ) ( & rtDW . e4nx2k2d02 ) ,
2 , 0 , 3 } } ; static DataTypeTransitionTable rtBTransTable = { 19U ,
rtBTransitions } ; static DataTypeTransition rtPTransitions [ ] = { { (
char_T * ) ( & rtP . data ) , 27 , 0 , 1 } , { ( char_T * ) ( & rtP .
RandomNumber1_Mean ) , 0 , 0 , 57 } } ; static DataTypeTransitionTable
rtPTransTable = { 2U , rtPTransitions } ;
