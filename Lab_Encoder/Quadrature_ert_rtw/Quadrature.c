/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Quadrature.c
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

#include "Quadrature.h"
#include "Quadrature_types.h"
#include "Quadrature_private.h"
#include "rtwtypes.h"
#include "stm_timer_ll.h"

/* Block signals (default storage) */
B_Quadrature_T Quadrature_B;

/* Block states (default storage) */
DW_Quadrature_T Quadrature_DW;

/* Real-time model */
static RT_MODEL_Quadrature_T Quadrature_M_;
RT_MODEL_Quadrature_T *const Quadrature_M = &Quadrature_M_;

/* Forward declaration for local functions */
static void Quadrature_SystemCore_setup(stm32cube_blocks_EncoderBlock_T *obj);
static void Quadrature_SystemCore_setup_g(stm32cube_blocks_EncoderBlock_T *obj);
static void Quadrature_SystemCore_setup_gr(stm32cube_blocks_EncoderBlock_T *obj);

/* System initialize for atomic system: */
void Quadrature_DigitalPortRead_Init(DW_DigitalPortRead_Quadrature_T *localDW)
{
  /* Start for MATLABSystem: '<S8>/Digital Port Read' */
  localDW->objisempty = true;
  localDW->obj.isInitialized = 1;
}

/* Output and update for atomic system: */
void Quadrature_DigitalPortRead(B_DigitalPortRead_Quadrature_T *localB)
{
  uint32_T pinReadLoc;

  /* MATLABSystem: '<S8>/Digital Port Read' */
  pinReadLoc = LL_GPIO_ReadInputPort(GPIOC);

  /* MATLABSystem: '<S8>/Digital Port Read' */
  localB->DigitalPortRead = ((pinReadLoc & 8192U) != 0U);
}

static void Quadrature_SystemCore_setup(stm32cube_blocks_EncoderBlock_T *obj)
{
  uint8_T ChannelInfo;
  TIM_Type_T b;
  boolean_T isSlaveModeTriggerEnabled;

  /* Start for MATLABSystem: '<Root>/Encoder' */
  obj->isInitialized = 1;
  b.PeripheralPtr = TIM3;
  b.isCenterAlignedMode = false;

  /* Start for MATLABSystem: '<Root>/Encoder' */
  b.repetitionCounter = 0U;
  obj->TimerHandle = Timer_Handle_Init(&b);
  enableTimerInterrupts(obj->TimerHandle, 0);
  ChannelInfo = ENABLE_CH;

  /* Start for MATLABSystem: '<Root>/Encoder' */
  enableTimerChannel1(obj->TimerHandle, ChannelInfo);
  enableTimerChannel2(obj->TimerHandle, ChannelInfo);
  isSlaveModeTriggerEnabled = isSlaveTriggerModeEnabled(obj->TimerHandle);
  if (!isSlaveModeTriggerEnabled) {
    /* Start for MATLABSystem: '<Root>/Encoder' */
    enableCounter(obj->TimerHandle, false);
  }

  obj->isSetupComplete = true;
}

static void Quadrature_SystemCore_setup_g(stm32cube_blocks_EncoderBlock_T *obj)
{
  uint8_T ChannelInfo;
  TIM_Type_T b;
  boolean_T isSlaveModeTriggerEnabled;

  /* Start for MATLABSystem: '<Root>/Encoder1' */
  obj->isInitialized = 1;
  b.PeripheralPtr = TIM4;
  b.isCenterAlignedMode = false;

  /* Start for MATLABSystem: '<Root>/Encoder1' */
  b.repetitionCounter = 0U;
  obj->TimerHandle = Timer_Handle_Init(&b);
  enableTimerInterrupts(obj->TimerHandle, 0);
  ChannelInfo = ENABLE_CH;

  /* Start for MATLABSystem: '<Root>/Encoder1' */
  enableTimerChannel1(obj->TimerHandle, ChannelInfo);
  enableTimerChannel2(obj->TimerHandle, ChannelInfo);
  isSlaveModeTriggerEnabled = isSlaveTriggerModeEnabled(obj->TimerHandle);
  if (!isSlaveModeTriggerEnabled) {
    /* Start for MATLABSystem: '<Root>/Encoder1' */
    enableCounter(obj->TimerHandle, false);
  }

  obj->isSetupComplete = true;
}

static void Quadrature_SystemCore_setup_gr(stm32cube_blocks_EncoderBlock_T *obj)
{
  uint8_T ChannelInfo;
  TIM_Type_T b;
  boolean_T isSlaveModeTriggerEnabled;

  /* Start for MATLABSystem: '<Root>/Encoder2' */
  obj->isInitialized = 1;
  b.PeripheralPtr = TIM8;
  b.isCenterAlignedMode = false;

  /* Start for MATLABSystem: '<Root>/Encoder2' */
  b.repetitionCounter = 0U;
  obj->TimerHandle = Timer_Handle_Init(&b);
  enableTimerInterrupts(obj->TimerHandle, 0);
  ChannelInfo = ENABLE_CH;

  /* Start for MATLABSystem: '<Root>/Encoder2' */
  enableTimerChannel1(obj->TimerHandle, ChannelInfo);
  enableTimerChannel2(obj->TimerHandle, ChannelInfo);
  isSlaveModeTriggerEnabled = isSlaveTriggerModeEnabled(obj->TimerHandle);
  if (!isSlaveModeTriggerEnabled) {
    /* Start for MATLABSystem: '<Root>/Encoder2' */
    enableCounter(obj->TimerHandle, false);
  }

  obj->isSetupComplete = true;
}

/* Model step function */
void Quadrature_step(void)
{
  real_T diff_count;
  uint32_T timerCounts;
  Quadrature_DigitalPortRead(&Quadrature_B.DigitalPortRead);

  /* MATLABSystem: '<Root>/Encoder' */
  timerCounts = getTimerCounterValueForG4(Quadrature_DW.obj_p.TimerHandle, false,
    NULL);

  /* MATLAB Function: '<Root>/MATLAB Function' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion'
   *  MATLABSystem: '<Root>/Encoder'
   */
  if (!Quadrature_DW.previousCount_not_empty_p) {
    Quadrature_DW.previousCount_o = timerCounts;
    Quadrature_DW.previousCount_not_empty_p = true;
  }

  diff_count = (real_T)timerCounts - Quadrature_DW.previousCount_o;
  Quadrature_B.velocity_h = diff_count / 24.0 / 0.01 * 60.0;
  if (diff_count > 32760.0) {
    Quadrature_DW.unwrappedPositionPrev_o += diff_count - 65520.0;
  } else if (diff_count < -32760.0) {
    Quadrature_DW.unwrappedPositionPrev_o += diff_count + 65520.0;
  } else {
    Quadrature_DW.unwrappedPositionPrev_o += diff_count;
  }

  if (Quadrature_B.DigitalPortRead.DigitalPortRead) {
    Quadrature_DW.unwrappedPositionPrev_o = 0.0;
    Quadrature_B.velocity_h = 0.0;
  }

  Quadrature_DW.previousCount_o = timerCounts;
  Quadrature_B.pulse_e = Quadrature_DW.unwrappedPositionPrev_o;

  /* End of MATLAB Function: '<Root>/MATLAB Function' */
  /* Gain: '<Root>/Gain' */
  Quadrature_B.X4_Position = 0.26179938779914941 * Quadrature_B.pulse_e;
  Quadrature_DigitalPortRead(&Quadrature_B.DigitalPortRead_l);

  /* MATLABSystem: '<Root>/Encoder1' */
  timerCounts = getTimerCounterValueForG4(Quadrature_DW.obj_n.TimerHandle, false,
    NULL);

  /* MATLAB Function: '<Root>/MATLAB Function1' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion1'
   *  MATLABSystem: '<Root>/Encoder1'
   */
  if (!Quadrature_DW.previousCount_not_empty_o) {
    Quadrature_DW.previousCount_i = timerCounts;
    Quadrature_DW.previousCount_not_empty_o = true;
  }

  diff_count = (real_T)timerCounts - Quadrature_DW.previousCount_i;
  Quadrature_B.velocity_d = diff_count / 24.0 / 0.01 * 60.0;
  if (diff_count > 32760.0) {
    Quadrature_DW.unwrappedPositionPrev_d += diff_count - 65520.0;
  } else if (diff_count < -32760.0) {
    Quadrature_DW.unwrappedPositionPrev_d += diff_count + 65520.0;
  } else {
    Quadrature_DW.unwrappedPositionPrev_d += diff_count;
  }

  if (Quadrature_B.DigitalPortRead_l.DigitalPortRead) {
    Quadrature_DW.unwrappedPositionPrev_d = 0.0;
    Quadrature_B.velocity_d = 0.0;
  }

  Quadrature_DW.previousCount_i = timerCounts;
  Quadrature_B.pulse_b = Quadrature_DW.unwrappedPositionPrev_d;

  /* End of MATLAB Function: '<Root>/MATLAB Function1' */
  /* Gain: '<Root>/Gain1' */
  Quadrature_B.X2_Position = 0.26179938779914941 * Quadrature_B.pulse_b;
  Quadrature_DigitalPortRead(&Quadrature_B.DigitalPortRead_h);

  /* MATLABSystem: '<Root>/Encoder2' */
  timerCounts = getTimerCounterValueForG4(Quadrature_DW.obj.TimerHandle, false,
    NULL);

  /* MATLAB Function: '<Root>/MATLAB Function2' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion2'
   *  MATLABSystem: '<Root>/Encoder2'
   */
  if (!Quadrature_DW.previousCount_not_empty) {
    Quadrature_DW.previousCount = timerCounts;
    Quadrature_DW.previousCount_not_empty = true;
  }

  diff_count = (real_T)timerCounts - Quadrature_DW.previousCount;
  Quadrature_B.velocity = diff_count / 24.0 / 0.01 * 60.0;
  if (diff_count > 32760.0) {
    Quadrature_DW.unwrappedPositionPrev += diff_count - 65520.0;
  } else if (diff_count < -32760.0) {
    Quadrature_DW.unwrappedPositionPrev += diff_count + 65520.0;
  } else {
    Quadrature_DW.unwrappedPositionPrev += diff_count;
  }

  if (Quadrature_B.DigitalPortRead_h.DigitalPortRead) {
    Quadrature_DW.unwrappedPositionPrev = 0.0;
    Quadrature_B.velocity = 0.0;
  }

  Quadrature_DW.previousCount = timerCounts;
  Quadrature_B.pulse = Quadrature_DW.unwrappedPositionPrev;

  /* End of MATLAB Function: '<Root>/MATLAB Function2' */
  /* Gain: '<Root>/Gain2' */
  Quadrature_B.X1_Position = 0.26179938779914941 * Quadrature_B.pulse;

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  Quadrature_M->Timing.taskTime0 =
    ((time_T)(++Quadrature_M->Timing.clockTick0)) *
    Quadrature_M->Timing.stepSize0;
}

/* Model initialize function */
void Quadrature_initialize(void)
{
  /* Registration code */
  rtmSetTFinal(Quadrature_M, -1);
  Quadrature_M->Timing.stepSize0 = 0.1;

  /* External mode info */
  Quadrature_M->Sizes.checksums[0] = (2873266334U);
  Quadrature_M->Sizes.checksums[1] = (2068813300U);
  Quadrature_M->Sizes.checksums[2] = (151276724U);
  Quadrature_M->Sizes.checksums[3] = (425945982U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[10];
    Quadrature_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
    systemRan[6] = &rtAlwaysEnabled;
    systemRan[7] = &rtAlwaysEnabled;
    systemRan[8] = &rtAlwaysEnabled;
    systemRan[9] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(Quadrature_M->extModeInfo,
      &Quadrature_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(Quadrature_M->extModeInfo, Quadrature_M->Sizes.checksums);
    rteiSetTPtr(Quadrature_M->extModeInfo, rtmGetTPtr(Quadrature_M));
  }

  Quadrature_DigitalPortRead_Init(&Quadrature_DW.DigitalPortRead);

  /* Start for MATLABSystem: '<Root>/Encoder' */
  Quadrature_DW.obj_p.isInitialized = 0;
  Quadrature_DW.obj_p.matlabCodegenIsDeleted = false;
  Quadrature_SystemCore_setup(&Quadrature_DW.obj_p);
  Quadrature_DigitalPortRead_Init(&Quadrature_DW.DigitalPortRead_l);

  /* Start for MATLABSystem: '<Root>/Encoder1' */
  Quadrature_DW.obj_n.isInitialized = 0;
  Quadrature_DW.obj_n.matlabCodegenIsDeleted = false;
  Quadrature_SystemCore_setup_g(&Quadrature_DW.obj_n);
  Quadrature_DigitalPortRead_Init(&Quadrature_DW.DigitalPortRead_h);

  /* Start for MATLABSystem: '<Root>/Encoder2' */
  Quadrature_DW.obj.isInitialized = 0;
  Quadrature_DW.obj.matlabCodegenIsDeleted = false;
  Quadrature_SystemCore_setup_gr(&Quadrature_DW.obj);
}

/* Model terminate function */
void Quadrature_terminate(void)
{
  uint8_T ChannelInfo;

  /* Terminate for MATLABSystem: '<Root>/Encoder' */
  if (!Quadrature_DW.obj_p.matlabCodegenIsDeleted) {
    Quadrature_DW.obj_p.matlabCodegenIsDeleted = true;
    if ((Quadrature_DW.obj_p.isInitialized == 1) &&
        Quadrature_DW.obj_p.isSetupComplete) {
      disableCounter(Quadrature_DW.obj_p.TimerHandle);
      disableTimerInterrupts(Quadrature_DW.obj_p.TimerHandle, 0);
      ChannelInfo = ENABLE_CH;
      disableTimerChannel1(Quadrature_DW.obj_p.TimerHandle, ChannelInfo);
      disableTimerChannel2(Quadrature_DW.obj_p.TimerHandle, ChannelInfo);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Encoder' */
  /* Terminate for MATLABSystem: '<Root>/Encoder1' */
  if (!Quadrature_DW.obj_n.matlabCodegenIsDeleted) {
    Quadrature_DW.obj_n.matlabCodegenIsDeleted = true;
    if ((Quadrature_DW.obj_n.isInitialized == 1) &&
        Quadrature_DW.obj_n.isSetupComplete) {
      disableCounter(Quadrature_DW.obj_n.TimerHandle);
      disableTimerInterrupts(Quadrature_DW.obj_n.TimerHandle, 0);
      ChannelInfo = ENABLE_CH;
      disableTimerChannel1(Quadrature_DW.obj_n.TimerHandle, ChannelInfo);
      disableTimerChannel2(Quadrature_DW.obj_n.TimerHandle, ChannelInfo);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Encoder1' */
  /* Terminate for MATLABSystem: '<Root>/Encoder2' */
  if (!Quadrature_DW.obj.matlabCodegenIsDeleted) {
    Quadrature_DW.obj.matlabCodegenIsDeleted = true;
    if ((Quadrature_DW.obj.isInitialized == 1) &&
        Quadrature_DW.obj.isSetupComplete) {
      disableCounter(Quadrature_DW.obj.TimerHandle);
      disableTimerInterrupts(Quadrature_DW.obj.TimerHandle, 0);
      ChannelInfo = ENABLE_CH;
      disableTimerChannel1(Quadrature_DW.obj.TimerHandle, ChannelInfo);
      disableTimerChannel2(Quadrature_DW.obj.TimerHandle, ChannelInfo);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Encoder2' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
