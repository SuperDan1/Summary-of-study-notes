/*
 *  rtmodel.h:
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

#ifndef RTW_HEADER_rtmodel_h_
#define RTW_HEADER_rtmodel_h_

/*
 *  Includes the appropriate headers when we are using rtModel
 */
#include "mbd.h"
#define GRTINTERFACE                   0

/*
 * ROOT_IO_FORMAT: 0 (Individual arguments)
 * ROOT_IO_FORMAT: 1 (Structure reference)
 * ROOT_IO_FORMAT: 2 (Part of model data structure)
 */
# define ROOT_IO_FORMAT                2
#define MODEL_CLASSNAME                mbdModelClass
#define MODEL_STEPNAME                 step
#endif                                 /* RTW_HEADER_rtmodel_h_ */
