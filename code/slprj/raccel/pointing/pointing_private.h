#ifndef RTW_HEADER_pointing_private_h_
#define RTW_HEADER_pointing_private_h_
#include "rtwtypes.h"
#include "builtin_typeid_types.h"
#include "multiword_types.h"
#include "pointing.h"
#if !defined(rt_VALIDATE_MEMORY)
#define rt_VALIDATE_MEMORY(S, ptr)   if(!(ptr)) {\
  ssSetErrorStatus(rtS, RT_MEMORY_ALLOCATION_ERROR);\
  }
#endif
#if !defined(rt_FREE)
#if !defined(_WIN32)
#define rt_FREE(ptr)   if((ptr) != (NULL)) {\
  free((ptr));\
  (ptr) = (NULL);\
  }
#else
#define rt_FREE(ptr)   if((ptr) != (NULL)) {\
  free((void *)(ptr));\
  (ptr) = (NULL);\
  }
#endif
#endif
extern real_T rt_urand_Upu32_Yd_f_pw_snf ( uint32_T * u ) ; extern real_T
rt_nrand_Upu32_Yd_f_pw_snf ( uint32_T * u ) ; extern void p54msx4qks ( const
real_T fmbos3wpbf [ 3 ] , const real_T cwh3a1nlhw [ 9 ] , const real_T
aekciksy5j [ 9 ] , const real_T ertdiuxk4e [ 9 ] , pp3ucak1we * localB ) ;
extern void hsoam3rxzy ( const real_T jpm2qz2iyl [ 3 ] , const real_T
nzopxhbv3c [ 3 ] , ol1ikflgm2 * localB ) ; extern void px30hprmrj ( real_T
d1lgk0ojoi , real_T cvv5hxqufx , real_T pgzxfpmemr , ep05ktrzpt * localB ) ;
extern void nvfofocjrz ( real_T g5qtnsmpla , real_T mecsxevckv , real_T
ekqpr202db , real_T pmpnhldz0v , real_T ct1sh4vbj1 , real_T hm0lqfsqit ,
ew4humqmjw * localB ) ; extern void hxg1cub2fg ( const real_T mrvmsj22di [ 9
] , real_T kjq0lyhqep , htahsp0knc * localB ) ; extern void mzxxcjchg3 (
const real_T ftpregj4gs [ 3 ] , const real_T gx4fl5ivda [ 3 ] , dwh41ujqlf *
localB ) ;
#if defined(MULTITASKING)
#error Models using the variable step solvers cannot define MULTITASKING
#endif
#endif
