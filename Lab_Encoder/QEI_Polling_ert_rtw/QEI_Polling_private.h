/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: QEI_Polling_private.h
 *
 * Code generated for Simulink model 'QEI_Polling'.
 *
 * Model version                  : 1.1
 * Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
 * C/C++ source code generated on : Thu Oct 31 21:34:32 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef QEI_Polling_private_h_
#define QEI_Polling_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "QEI_Polling.h"
#include "QEI_Polling_types.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmSetTFinal
#define rtmSetTFinal(rtm, val)         ((rtm)->Timing.tFinal = (val))
#endif

extern void QEI_Pollin_DigitalPortRead_Init(DW_DigitalPortRead_QEI_Pollin_T
  *localDW);
extern void QEI_Polling_DigitalPortRead(B_DigitalPortRead_QEI_Polling_T *localB);
extern void QEI_Polling_MATLABFunction_Init(DW_MATLABFunction_QEI_Polling_T
  *localDW);
extern void QEI_Polling_MATLABFunction(boolean_T rtu_blue_in, real_T rtu_count,
  real_T *rty_pulse, real_T *rty_velocity, DW_MATLABFunction_QEI_Polling_T
  *localDW);

#endif                                 /* QEI_Polling_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
