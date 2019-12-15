/*
 * mbd.cpp
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

#include "mbd.h"
#include "mbd_private.h"

/* Model step function */
void mbdModelClass::step()
{
  /* Outport: '<Root>/Out1' incorporates:
   *  Inport: '<Root>/In1'
   *  Inport: '<Root>/In2'
   *  Sum: '<Root>/Subtract'
   */
  mbd_Y.Out1 = mbd_U.In1 - mbd_U.In2;

  /* Matfile logging */
  rt_UpdateTXYLogVars((&mbd_M)->rtwLogInfo, (&(&mbd_M)->Timing.taskTime0));

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.2s, 0.0s] */
    if ((rtmGetTFinal((&mbd_M))!=-1) &&
        !((rtmGetTFinal((&mbd_M))-(&mbd_M)->Timing.taskTime0) > (&mbd_M)
          ->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(getRTM(), "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++(&mbd_M)->Timing.clockTick0)) {
    ++(&mbd_M)->Timing.clockTickH0;
  }

  (&mbd_M)->Timing.taskTime0 = (&mbd_M)->Timing.clockTick0 * (&mbd_M)
    ->Timing.stepSize0 + (&mbd_M)->Timing.clockTickH0 * (&mbd_M)
    ->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void mbdModelClass::initialize()
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)(&mbd_M), 0,
                sizeof(RT_MODEL_mbd_T));
  rtmSetTFinal(getRTM(), -1);
  (&mbd_M)->Timing.stepSize0 = 0.2;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = NULL;
    (&mbd_M)->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo((&mbd_M)->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs((&mbd_M)->rtwLogInfo, (NULL));
    rtliSetLogT((&mbd_M)->rtwLogInfo, "tout");
    rtliSetLogX((&mbd_M)->rtwLogInfo, "");
    rtliSetLogXFinal((&mbd_M)->rtwLogInfo, "");
    rtliSetLogVarNameModifier((&mbd_M)->rtwLogInfo, "rt_");
    rtliSetLogFormat((&mbd_M)->rtwLogInfo, 4);
    rtliSetLogMaxRows((&mbd_M)->rtwLogInfo, 0);
    rtliSetLogDecimation((&mbd_M)->rtwLogInfo, 1);
    rtliSetLogY((&mbd_M)->rtwLogInfo, "");
    rtliSetLogYSignalInfo((&mbd_M)->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs((&mbd_M)->rtwLogInfo, (NULL));
  }

  /* external inputs */
  (void)memset((void *)&mbd_U, 0, sizeof(ExtU_mbd_T));

  /* external outputs */
  mbd_Y.Out1 = 0.0;

  /* Matfile logging */
  rt_StartDataLoggingWithStartTime((&mbd_M)->rtwLogInfo, 0.0, rtmGetTFinal
    ((&mbd_M)), (&mbd_M)->Timing.stepSize0, (&rtmGetErrorStatus((&mbd_M))));
}

/* Model terminate function */
void mbdModelClass::terminate()
{
  /* (no terminate code required) */
}

/* Constructor */
mbdModelClass::mbdModelClass()
{
}

/* Destructor */
mbdModelClass::~mbdModelClass()
{
  /* Currently there is no destructor body generated.*/
}

/* Real-Time Model get method */
RT_MODEL_mbd_T * mbdModelClass::getRTM()
{
  return (&mbd_M);
}
