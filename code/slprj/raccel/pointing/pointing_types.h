#ifndef RTW_HEADER_pointing_types_h_
#define RTW_HEADER_pointing_types_h_
#include "rtwtypes.h"
#include "builtin_typeid_types.h"
#include "multiword_types.h"
#ifndef DEFINED_TYPEDEF_FOR_struct_eUgGn14HOPD0Bpc0IaeuNC_
#define DEFINED_TYPEDEF_FOR_struct_eUgGn14HOPD0Bpc0IaeuNC_
typedef struct { real_T mass ; real_T Ix ; real_T Iy ; real_T Iz ; real_T
inertiaMatrix [ 9 ] ; } struct_eUgGn14HOPD0Bpc0IaeuNC ;
#endif
#ifndef DEFINED_TYPEDEF_FOR_struct_XG5FAMxlkIOXT4puaiHssC_
#define DEFINED_TYPEDEF_FOR_struct_XG5FAMxlkIOXT4puaiHssC_
typedef struct { real_T m [ 3 ] ; } struct_XG5FAMxlkIOXT4puaiHssC ;
#endif
#ifndef DEFINED_TYPEDEF_FOR_struct_GxIgcCZnnZi2XW7MM4yafG_
#define DEFINED_TYPEDEF_FOR_struct_GxIgcCZnnZi2XW7MM4yafG_
typedef struct { real_T NBMat [ 42 ] ; real_T aSurf [ 14 ] ; real_T rSurf [
42 ] ; real_T rhoS [ 14 ] ; real_T rhoD [ 14 ] ; }
struct_GxIgcCZnnZi2XW7MM4yafG ;
#endif
#ifndef DEFINED_TYPEDEF_FOR_struct_QSaaZsm8gSaKB28J0DSmBB_
#define DEFINED_TYPEDEF_FOR_struct_QSaaZsm8gSaKB28J0DSmBB_
typedef struct { real_T rSurf [ 42 ] ; real_T aSurf [ 14 ] ; real_T NBMat [
42 ] ; real_T cd ; real_T rho ; } struct_QSaaZsm8gSaKB28J0DSmBB ;
#endif
#ifndef DEFINED_TYPEDEF_FOR_struct_j2cokpCYy7yeoacgrc0a1F_
#define DEFINED_TYPEDEF_FOR_struct_j2cokpCYy7yeoacgrc0a1F_
typedef struct { real_T FOV ; real_T ABS [ 9 ] ; real_T sampleTime ; real_T
NStars ; real_T sigmaCross ; real_T sigmaRoll ; }
struct_j2cokpCYy7yeoacgrc0a1F ;
#endif
#ifndef DEFINED_TYPEDEF_FOR_struct_tg61sUabKUBlHZYg3O5FcE_
#define DEFINED_TYPEDEF_FOR_struct_tg61sUabKUBlHZYg3O5FcE_
typedef struct { real_T sampleTime ; real_T sigmaN ; real_T sigmaB ; real_T
alphaObs ; real_T b0 [ 3 ] ; real_T kObsABN ; real_T wObs0 [ 3 ] ; }
struct_tg61sUabKUBlHZYg3O5FcE ;
#endif
#ifndef DEFINED_TYPEDEF_FOR_struct_QAKcGoErQyD4l7LlU6FAlD_
#define DEFINED_TYPEDEF_FOR_struct_QAKcGoErQyD4l7LlU6FAlD_
typedef struct { real_T sigma ; real_T sampleTime ; real_T nonOrthogonality [
9 ] ; } struct_QAKcGoErQyD4l7LlU6FAlD ;
#endif
#ifndef DEFINED_TYPEDEF_FOR_struct_qa7Kh2PhCOGZmLGFMj6JFF_
#define DEFINED_TYPEDEF_FOR_struct_qa7Kh2PhCOGZmLGFMj6JFF_
typedef struct { real_T axis [ 3 ] ; real_T hMax ; real_T MMax ; real_T h0 ;
} struct_qa7Kh2PhCOGZmLGFMj6JFF ;
#endif
#ifndef DEFINED_TYPEDEF_FOR_struct_bEWva6r1fMCyu61B3VBRyF_
#define DEFINED_TYPEDEF_FOR_struct_bEWva6r1fMCyu61B3VBRyF_
typedef struct { real_T DMax [ 3 ] ; } struct_bEWva6r1fMCyu61B3VBRyF ;
#endif
#ifndef DEFINED_TYPEDEF_FOR_struct_q9UZ4fke9ut1ZI2Sp6dFRB_
#define DEFINED_TYPEDEF_FOR_struct_q9UZ4fke9ut1ZI2Sp6dFRB_
typedef struct { real_T tDamping ; real_T kDamping ; real_T tProp ; real_T
kProp ; real_T start ; real_T stop ; } struct_q9UZ4fke9ut1ZI2Sp6dFRB ;
#endif
#ifndef DEFINED_TYPEDEF_FOR_struct_Vw9ymYRXawQBttOglnrOrH_
#define DEFINED_TYPEDEF_FOR_struct_Vw9ymYRXawQBttOglnrOrH_
typedef struct { real_T kWE ; real_T kAE ; real_T start ; real_T stop ; }
struct_Vw9ymYRXawQBttOglnrOrH ;
#endif
#ifndef DEFINED_TYPEDEF_FOR_struct_dPmzRL9GR4FaYTvmwD8SE_
#define DEFINED_TYPEDEF_FOR_struct_dPmzRL9GR4FaYTvmwD8SE_
typedef struct { real_T a ; real_T e ; real_T i ; real_T OM ; real_T om ;
real_T period ; } struct_dPmzRL9GR4FaYTvmwD8SE ;
#endif
#ifndef DEFINED_TYPEDEF_FOR_struct_u3A3sSehJ9gf2qUJURV4fG_
#define DEFINED_TYPEDEF_FOR_struct_u3A3sSehJ9gf2qUJURV4fG_
typedef struct { real_T w [ 3 ] ; real_T dcm [ 9 ] ; real_T th ; }
struct_u3A3sSehJ9gf2qUJURV4fG ;
#endif
#ifndef DEFINED_TYPEDEF_FOR_struct_qSJ0rbcLQyL9m8alQXvOk_
#define DEFINED_TYPEDEF_FOR_struct_qSJ0rbcLQyL9m8alQXvOk_
typedef struct { struct_eUgGn14HOPD0Bpc0IaeuNC sc ;
struct_XG5FAMxlkIOXT4puaiHssC magneticTorque ; struct_GxIgcCZnnZi2XW7MM4yafG
SRP ; struct_QSaaZsm8gSaKB28J0DSmBB drag ; struct_j2cokpCYy7yeoacgrc0a1F
starSensor ; struct_tg61sUabKUBlHZYg3O5FcE gyroscope ;
struct_QAKcGoErQyD4l7LlU6FAlD magnetometer ; struct_qa7Kh2PhCOGZmLGFMj6JFF
reactionWheel ; struct_bEWva6r1fMCyu61B3VBRyF magnetorquer ;
struct_q9UZ4fke9ut1ZI2Sp6dFRB detumbling ; struct_Vw9ymYRXawQBttOglnrOrH slew
; struct_Vw9ymYRXawQBttOglnrOrH pointing ; struct_dPmzRL9GR4FaYTvmwD8SE orbit
; struct_u3A3sSehJ9gf2qUJURV4fG ic ; } struct_qSJ0rbcLQyL9m8alQXvOk ;
#endif
typedef struct P_ P ;
#endif
