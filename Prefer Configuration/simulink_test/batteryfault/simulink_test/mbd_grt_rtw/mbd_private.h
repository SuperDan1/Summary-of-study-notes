/*
 * mbd_private.h
 *
 * Code generation for model "mbd".
 *
 * Model version              : 1.2
 * Simulink Coder version : 8.13 (R2017b) 24-Jul-2017
 * C++ source code generated on : Sat Dec  7 14:56:59 2019
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_mbd_private_h_
#define RTW_HEADER_mbd_private_h_
#include "rtwtypes.h"
#include "builtin_typeid_types.h"
#include "multiword_types.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmSetTFinal
# define rtmSetTFinal(rtm, val)        ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               (&(rtm)->Timing.taskTime0)
#endif
#endif                                 /* RTW_HEADER_mbd_private_h_ */
