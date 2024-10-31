/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Quadrature_private.h
 *
 * Code generated for Simulink model 'Quadrature'.
 *
 * Model version                  : 1.0
 * Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
 * C/C++ source code generated on : Thu Oct 31 09:47:56 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef Quadrature_private_h_
#define Quadrature_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "Quadrature.h"
#include "Quadrature_types.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmSetTFinal
#define rtmSetTFinal(rtm, val)         ((rtm)->Timing.tFinal = (val))
#endif

extern void Quadrature_DigitalPortRead_Init(DW_DigitalPortRead_Quadrature_T
  *localDW);
extern void Quadrature_DigitalPortRead(B_DigitalPortRead_Quadrature_T *localB);

#endif                                 /* Quadrature_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
