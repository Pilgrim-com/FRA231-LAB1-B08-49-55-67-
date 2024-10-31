/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: QEI_Polling.c
 *
 * Code generated for Simulink model 'QEI_Polling'.
 *
 * Model version                  : 1.2
 * Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
 * C/C++ source code generated on : Fri Nov  1 00:02:00 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "QEI_Polling.h"
#include "rtwtypes.h"
#include "QEI_Polling_types.h"
#include "QEI_Polling_private.h"
#include "stm_timer_ll.h"

/* Named constants for MATLAB Function: '<Root>/MATLAB Function' */
#define QEI_Polling_CALL_EVENT         (-1)

/* Block signals (default storage) */
B_QEI_Polling_T QEI_Polling_B;

/* Block states (default storage) */
DW_QEI_Polling_T QEI_Polling_DW;

/* Real-time model */
static RT_MODEL_QEI_Polling_T QEI_Polling_M_;
RT_MODEL_QEI_Polling_T *const QEI_Polling_M = &QEI_Polling_M_;

/* Forward declaration for local functions */
static void QEI_Polling_SystemCore_setup(stm32cube_blocks_EncoderBlock_T *obj);
static void QEI_Polling_SystemCore_setup_k(stm32cube_blocks_EncoderBlock_T *obj);
static void QEI_Polling_SystemCore_setup_k0(stm32cube_blocks_EncoderBlock_T *obj);

/* System initialize for atomic system: */
void QEI_Pollin_DigitalPortRead_Init(DW_DigitalPortRead_QEI_Pollin_T *localDW)
{
  /* Start for MATLABSystem: '<S14>/Digital Port Read' */
  localDW->objisempty = true;
  localDW->obj.isInitialized = 1;
}

/* Output and update for atomic system: */
void QEI_Polling_DigitalPortRead(B_DigitalPortRead_QEI_Polling_T *localB)
{
  uint32_T pinReadLoc;

  /* MATLABSystem: '<S14>/Digital Port Read' */
  pinReadLoc = LL_GPIO_ReadInputPort(GPIOC);

  /* MATLABSystem: '<S14>/Digital Port Read' */
  localB->DigitalPortRead = ((pinReadLoc & 8192U) != 0U);
}

/*
 * System initialize for atomic system:
 *    '<Root>/MATLAB Function'
 *    '<Root>/MATLAB Function1'
 *    '<Root>/MATLAB Function2'
 */
void QEI_Polling_MATLABFunction_Init(DW_MATLABFunction_QEI_Polling_T *localDW)
{
  localDW->sfEvent = QEI_Polling_CALL_EVENT;
}

/*
 * Output and update for atomic system:
 *    '<Root>/MATLAB Function'
 *    '<Root>/MATLAB Function1'
 *    '<Root>/MATLAB Function2'
 */
void QEI_Polling_MATLABFunction(boolean_T rtu_blue_in, real_T rtu_count, real_T *
  rty_pulse, real_T *rty_velocity, DW_MATLABFunction_QEI_Polling_T *localDW)
{
  real_T diff_count;
  localDW->sfEvent = QEI_Polling_CALL_EVENT;
  if (!localDW->lastCount_not_empty) {
    localDW->lastCount = rtu_count;
    localDW->lastCount_not_empty = true;
    localDW->unwrappedPositionPrev_not_empty = true;
  }

  diff_count = rtu_count - localDW->lastCount;
  *rty_velocity = diff_count / 24.0 / 0.1 * 60.0;
  if (diff_count > 32760.0) {
    localDW->unwrappedPositionPrev += diff_count - 65520.0;
  } else if (diff_count < -32760.0) {
    localDW->unwrappedPositionPrev += diff_count + 65520.0;
  } else {
    localDW->unwrappedPositionPrev += diff_count;
  }

  if (rtu_blue_in) {
    localDW->unwrappedPositionPrev = 0.0;
    *rty_velocity = 0.0;
  }

  localDW->lastCount = rtu_count;
  *rty_pulse = localDW->unwrappedPositionPrev;
}

static void QEI_Polling_SystemCore_setup(stm32cube_blocks_EncoderBlock_T *obj)
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

static void QEI_Polling_SystemCore_setup_k(stm32cube_blocks_EncoderBlock_T *obj)
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

static void QEI_Polling_SystemCore_setup_k0(stm32cube_blocks_EncoderBlock_T *obj)
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
void QEI_Polling_step(void)
{
  real_T B;
  real_T currentA;
  uint32_T timerCounts;
  QEI_Polling_DigitalPortRead(&QEI_Polling_B.DigitalPortRead);

  /* MATLABSystem: '<Root>/Encoder' */
  timerCounts = getTimerCounterValueForG4(QEI_Polling_DW.obj_m.TimerHandle,
    false, NULL);

  /* MATLAB Function: '<Root>/MATLAB Function' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion'
   *  MATLABSystem: '<Root>/Encoder'
   */
  QEI_Polling_MATLABFunction(QEI_Polling_B.DigitalPortRead.DigitalPortRead,
    (real_T)timerCounts, &QEI_Polling_B.pulse_h, &QEI_Polling_B.velocity_k,
    &QEI_Polling_DW.sf_MATLABFunction);

  /* Gain: '<Root>/Gain' */
  QEI_Polling_B.X4_Position_QEI = 0.26179938779914941 * QEI_Polling_B.pulse_h;
  QEI_Polling_DigitalPortRead(&QEI_Polling_B.DigitalPortRead_e);

  /* MATLABSystem: '<Root>/Encoder1' */
  timerCounts = getTimerCounterValueForG4(QEI_Polling_DW.obj_c.TimerHandle,
    false, NULL);

  /* MATLAB Function: '<Root>/MATLAB Function1' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion1'
   *  MATLABSystem: '<Root>/Encoder1'
   */
  QEI_Polling_MATLABFunction(QEI_Polling_B.DigitalPortRead_e.DigitalPortRead,
    (real_T)timerCounts, &QEI_Polling_B.pulse_g, &QEI_Polling_B.velocity_n2,
    &QEI_Polling_DW.sf_MATLABFunction1);

  /* Gain: '<Root>/Gain1' */
  QEI_Polling_B.X2_Position_QEI = 0.26179938779914941 * QEI_Polling_B.pulse_g;
  QEI_Polling_DigitalPortRead(&QEI_Polling_B.DigitalPortRead_m);

  /* MATLABSystem: '<Root>/Encoder2' */
  timerCounts = getTimerCounterValueForG4(QEI_Polling_DW.obj.TimerHandle, false,
    NULL);

  /* MATLAB Function: '<Root>/MATLAB Function2' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion2'
   *  MATLABSystem: '<Root>/Encoder2'
   */
  QEI_Polling_MATLABFunction(QEI_Polling_B.DigitalPortRead_m.DigitalPortRead,
    (real_T)timerCounts, &QEI_Polling_B.pulse_i, &QEI_Polling_B.velocity_b,
    &QEI_Polling_DW.sf_MATLABFunction2);

  /* Gain: '<Root>/Gain2' */
  QEI_Polling_B.X1_Position_QEI = 0.26179938779914941 * QEI_Polling_B.pulse_i;
  QEI_Polling_DigitalPortRead(&QEI_Polling_B.DigitalPortRead_ev);

  /* MATLABSystem: '<S20>/Digital Port Read' */
  timerCounts = LL_GPIO_ReadInputPort(GPIOB);

  /* DataTypeConversion: '<Root>/Data Type Conversion3' incorporates:
   *  MATLABSystem: '<S20>/Digital Port Read'
   * */
  QEI_Polling_B.DataTypeConversion3 = ((timerCounts & 32U) != 0U);

  /* MATLABSystem: '<S22>/Digital Port Read' */
  timerCounts = LL_GPIO_ReadInputPort(GPIOB);

  /* DataTypeConversion: '<Root>/Data Type Conversion4' incorporates:
   *  MATLABSystem: '<S22>/Digital Port Read'
   * */
  QEI_Polling_B.DataTypeConversion4 = ((timerCounts & 16U) != 0U);

  /* MATLAB Function: '<Root>/MATLAB Function3' */
  if ((!QEI_Polling_DW.lastA_not_empty_a) || (!QEI_Polling_DW.count_not_empty_m)
      || (!QEI_Polling_DW.lastCount_not_empty_g)) {
    QEI_Polling_DW.lastA_j = 0.0;
    QEI_Polling_DW.lastA_not_empty_a = true;
    QEI_Polling_DW.count_h = 0.0;
    QEI_Polling_DW.count_not_empty_m = true;
    QEI_Polling_DW.lastCount_h = 0.0;
    QEI_Polling_DW.lastCount_not_empty_g = true;
  }

  currentA = QEI_Polling_B.DataTypeConversion3;
  if (QEI_Polling_DW.lastA_j != QEI_Polling_B.DataTypeConversion3) {
    if ((QEI_Polling_B.DataTypeConversion4 == 1.0) &&
        (QEI_Polling_B.DataTypeConversion3 == 1.0)) {
      QEI_Polling_DW.count_h--;
    } else if ((QEI_Polling_B.DataTypeConversion4 == 0.0) &&
               (QEI_Polling_B.DataTypeConversion3 == 1.0)) {
      QEI_Polling_DW.count_h++;
    }
  }

  QEI_Polling_B.velocity_f = (QEI_Polling_DW.count_h -
    QEI_Polling_DW.lastCount_h) / 0.01 * 60.0;
  if (QEI_Polling_B.DigitalPortRead_ev.DigitalPortRead) {
    QEI_Polling_DW.count_h = 0.0;
    QEI_Polling_B.velocity_f = 0.0;
    currentA = 0.0;
  }

  QEI_Polling_DW.lastA_j = currentA;
  QEI_Polling_DW.lastCount_h = QEI_Polling_DW.count_h;
  QEI_Polling_B.pulse_b = QEI_Polling_DW.count_h;

  /* End of MATLAB Function: '<Root>/MATLAB Function3' */
  /* Gain: '<Root>/Gain3' */
  QEI_Polling_B.X1_Position = 0.26179938779914941 * QEI_Polling_B.pulse_b;

  /* MATLAB Function: '<Root>/MATLAB Function4' */
  if ((!QEI_Polling_DW.lastA_not_empty_c) || (!QEI_Polling_DW.count_not_empty_i)
      || (!QEI_Polling_DW.lastCount_not_empty_m)) {
    QEI_Polling_DW.lastA_b = 0.0;
    QEI_Polling_DW.lastA_not_empty_c = true;
    QEI_Polling_DW.count_d = 0.0;
    QEI_Polling_DW.count_not_empty_i = true;
    QEI_Polling_DW.lastCount_j = 0.0;
    QEI_Polling_DW.lastCount_not_empty_m = true;
  }

  currentA = QEI_Polling_B.DataTypeConversion3;
  if (QEI_Polling_DW.lastA_b != QEI_Polling_B.DataTypeConversion3) {
    if ((QEI_Polling_B.DataTypeConversion4 == 1.0) &&
        (QEI_Polling_B.DataTypeConversion3 == 1.0) && (QEI_Polling_DW.lastA_b ==
         0.0)) {
      QEI_Polling_DW.count_d--;
    } else if ((QEI_Polling_B.DataTypeConversion4 == 0.0) &&
               (QEI_Polling_B.DataTypeConversion3 == 1.0) &&
               (QEI_Polling_DW.lastA_b == 0.0)) {
      QEI_Polling_DW.count_d++;
    } else if ((QEI_Polling_B.DataTypeConversion4 == 1.0) &&
               (QEI_Polling_B.DataTypeConversion3 == 0.0) &&
               (QEI_Polling_DW.lastA_b == 1.0)) {
      QEI_Polling_DW.count_d++;
    } else if ((QEI_Polling_B.DataTypeConversion4 == 0.0) &&
               (QEI_Polling_B.DataTypeConversion3 == 0.0) &&
               (QEI_Polling_DW.lastA_b == 1.0)) {
      QEI_Polling_DW.count_d--;
    }
  }

  QEI_Polling_B.velocity_n = (QEI_Polling_DW.count_d -
    QEI_Polling_DW.lastCount_j) / 0.01 * 60.0;
  if (QEI_Polling_B.DigitalPortRead_ev.DigitalPortRead) {
    QEI_Polling_DW.count_d = 0.0;
    QEI_Polling_B.velocity_n = 0.0;
    currentA = 0.0;
  }

  QEI_Polling_DW.lastA_b = currentA;
  QEI_Polling_DW.lastCount_j = QEI_Polling_DW.count_d;
  QEI_Polling_B.pulse_n = QEI_Polling_DW.count_d;

  /* End of MATLAB Function: '<Root>/MATLAB Function4' */
  /* Gain: '<Root>/Gain4' */
  QEI_Polling_B.X2_Position = 0.26179938779914941 * QEI_Polling_B.pulse_n;

  /* MATLAB Function: '<Root>/MATLAB Function5' */
  currentA = QEI_Polling_B.DataTypeConversion3;
  B = QEI_Polling_B.DataTypeConversion4;
  if ((!QEI_Polling_DW.lastA_not_empty) || (!QEI_Polling_DW.lastB_not_empty) ||
      (!QEI_Polling_DW.count_not_empty) || (!QEI_Polling_DW.lastCount_not_empty))
  {
    QEI_Polling_DW.lastA = 0.0;
    QEI_Polling_DW.lastA_not_empty = true;
    QEI_Polling_DW.lastB = 0.0;
    QEI_Polling_DW.lastB_not_empty = true;
    QEI_Polling_DW.count = 0.0;
    QEI_Polling_DW.count_not_empty = true;
    QEI_Polling_DW.lastCount = 0.0;
    QEI_Polling_DW.lastCount_not_empty = true;
  }

  if ((QEI_Polling_DW.lastA == 0.0) && (QEI_Polling_DW.lastB == 0.0)) {
    if ((QEI_Polling_B.DataTypeConversion3 == 1.0) &&
        (QEI_Polling_B.DataTypeConversion4 == 0.0)) {
      QEI_Polling_DW.count++;
    } else if ((QEI_Polling_B.DataTypeConversion3 == 0.0) &&
               (QEI_Polling_B.DataTypeConversion4 == 1.0)) {
      QEI_Polling_DW.count--;
    }
  } else if ((QEI_Polling_DW.lastA == 1.0) && (QEI_Polling_DW.lastB == 0.0)) {
    if ((QEI_Polling_B.DataTypeConversion3 == 1.0) &&
        (QEI_Polling_B.DataTypeConversion4 == 1.0)) {
      QEI_Polling_DW.count++;
    } else if ((QEI_Polling_B.DataTypeConversion3 == 0.0) &&
               (QEI_Polling_B.DataTypeConversion4 == 0.0)) {
      QEI_Polling_DW.count--;
    }
  } else if ((QEI_Polling_DW.lastA == 1.0) && (QEI_Polling_DW.lastB == 1.0)) {
    if ((QEI_Polling_B.DataTypeConversion3 == 0.0) &&
        (QEI_Polling_B.DataTypeConversion4 == 1.0)) {
      QEI_Polling_DW.count++;
    } else if ((QEI_Polling_B.DataTypeConversion3 == 1.0) &&
               (QEI_Polling_B.DataTypeConversion4 == 0.0)) {
      QEI_Polling_DW.count--;
    }
  } else if ((QEI_Polling_DW.lastA == 0.0) && (QEI_Polling_DW.lastB == 1.0)) {
    if ((QEI_Polling_B.DataTypeConversion3 == 0.0) &&
        (QEI_Polling_B.DataTypeConversion4 == 0.0)) {
      QEI_Polling_DW.count++;
    } else if ((QEI_Polling_B.DataTypeConversion3 == 1.0) &&
               (QEI_Polling_B.DataTypeConversion4 == 1.0)) {
      QEI_Polling_DW.count--;
    }
  }

  QEI_Polling_B.velocity = (QEI_Polling_DW.count - QEI_Polling_DW.lastCount) /
    0.01 * 60.0;
  if (QEI_Polling_B.DigitalPortRead_ev.DigitalPortRead) {
    QEI_Polling_DW.count = 0.0;
    QEI_Polling_B.velocity = 0.0;
    currentA = 0.0;
    B = 0.0;
  }

  QEI_Polling_DW.lastA = currentA;
  QEI_Polling_DW.lastB = B;
  QEI_Polling_DW.lastCount = QEI_Polling_DW.count;
  QEI_Polling_B.pulse = QEI_Polling_DW.count;

  /* End of MATLAB Function: '<Root>/MATLAB Function5' */
  /* Gain: '<Root>/Gain5' */
  QEI_Polling_B.X4_Position = 0.26179938779914941 * QEI_Polling_B.pulse;

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  QEI_Polling_M->Timing.taskTime0 =
    ((time_T)(++QEI_Polling_M->Timing.clockTick0)) *
    QEI_Polling_M->Timing.stepSize0;
}

/* Model initialize function */
void QEI_Polling_initialize(void)
{
  /* Registration code */
  rtmSetTFinal(QEI_Polling_M, -1);
  QEI_Polling_M->Timing.stepSize0 = 0.01;

  /* External mode info */
  QEI_Polling_M->Sizes.checksums[0] = (2901570582U);
  QEI_Polling_M->Sizes.checksums[1] = (2352101743U);
  QEI_Polling_M->Sizes.checksums[2] = (2327280988U);
  QEI_Polling_M->Sizes.checksums[3] = (1073209407U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[16];
    QEI_Polling_M->extModeInfo = (&rt_ExtModeInfo);
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
    systemRan[10] = &rtAlwaysEnabled;
    systemRan[11] = &rtAlwaysEnabled;
    systemRan[12] = &rtAlwaysEnabled;
    systemRan[13] = &rtAlwaysEnabled;
    systemRan[14] = &rtAlwaysEnabled;
    systemRan[15] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(QEI_Polling_M->extModeInfo,
      &QEI_Polling_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(QEI_Polling_M->extModeInfo,
                        QEI_Polling_M->Sizes.checksums);
    rteiSetTPtr(QEI_Polling_M->extModeInfo, rtmGetTPtr(QEI_Polling_M));
  }

  /* SystemInitialize for MATLAB Function: '<Root>/MATLAB Function' */
  QEI_Polling_MATLABFunction_Init(&QEI_Polling_DW.sf_MATLABFunction);

  /* SystemInitialize for MATLAB Function: '<Root>/MATLAB Function1' */
  QEI_Polling_MATLABFunction_Init(&QEI_Polling_DW.sf_MATLABFunction1);

  /* SystemInitialize for MATLAB Function: '<Root>/MATLAB Function2' */
  QEI_Polling_MATLABFunction_Init(&QEI_Polling_DW.sf_MATLABFunction2);
  QEI_Pollin_DigitalPortRead_Init(&QEI_Polling_DW.DigitalPortRead);

  /* Start for MATLABSystem: '<Root>/Encoder' */
  QEI_Polling_DW.obj_m.isInitialized = 0;
  QEI_Polling_DW.obj_m.matlabCodegenIsDeleted = false;
  QEI_Polling_SystemCore_setup(&QEI_Polling_DW.obj_m);
  QEI_Pollin_DigitalPortRead_Init(&QEI_Polling_DW.DigitalPortRead_e);

  /* Start for MATLABSystem: '<Root>/Encoder1' */
  QEI_Polling_DW.obj_c.isInitialized = 0;
  QEI_Polling_DW.obj_c.matlabCodegenIsDeleted = false;
  QEI_Polling_SystemCore_setup_k(&QEI_Polling_DW.obj_c);
  QEI_Pollin_DigitalPortRead_Init(&QEI_Polling_DW.DigitalPortRead_m);

  /* Start for MATLABSystem: '<Root>/Encoder2' */
  QEI_Polling_DW.obj.isInitialized = 0;
  QEI_Polling_DW.obj.matlabCodegenIsDeleted = false;
  QEI_Polling_SystemCore_setup_k0(&QEI_Polling_DW.obj);
  QEI_Pollin_DigitalPortRead_Init(&QEI_Polling_DW.DigitalPortRead_ev);
}

/* Model terminate function */
void QEI_Polling_terminate(void)
{
  uint8_T ChannelInfo;

  /* Terminate for MATLABSystem: '<Root>/Encoder' */
  if (!QEI_Polling_DW.obj_m.matlabCodegenIsDeleted) {
    QEI_Polling_DW.obj_m.matlabCodegenIsDeleted = true;
    if ((QEI_Polling_DW.obj_m.isInitialized == 1) &&
        QEI_Polling_DW.obj_m.isSetupComplete) {
      disableCounter(QEI_Polling_DW.obj_m.TimerHandle);
      disableTimerInterrupts(QEI_Polling_DW.obj_m.TimerHandle, 0);
      ChannelInfo = ENABLE_CH;
      disableTimerChannel1(QEI_Polling_DW.obj_m.TimerHandle, ChannelInfo);
      disableTimerChannel2(QEI_Polling_DW.obj_m.TimerHandle, ChannelInfo);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Encoder' */
  /* Terminate for MATLABSystem: '<Root>/Encoder1' */
  if (!QEI_Polling_DW.obj_c.matlabCodegenIsDeleted) {
    QEI_Polling_DW.obj_c.matlabCodegenIsDeleted = true;
    if ((QEI_Polling_DW.obj_c.isInitialized == 1) &&
        QEI_Polling_DW.obj_c.isSetupComplete) {
      disableCounter(QEI_Polling_DW.obj_c.TimerHandle);
      disableTimerInterrupts(QEI_Polling_DW.obj_c.TimerHandle, 0);
      ChannelInfo = ENABLE_CH;
      disableTimerChannel1(QEI_Polling_DW.obj_c.TimerHandle, ChannelInfo);
      disableTimerChannel2(QEI_Polling_DW.obj_c.TimerHandle, ChannelInfo);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Encoder1' */
  /* Terminate for MATLABSystem: '<Root>/Encoder2' */
  if (!QEI_Polling_DW.obj.matlabCodegenIsDeleted) {
    QEI_Polling_DW.obj.matlabCodegenIsDeleted = true;
    if ((QEI_Polling_DW.obj.isInitialized == 1) &&
        QEI_Polling_DW.obj.isSetupComplete) {
      disableCounter(QEI_Polling_DW.obj.TimerHandle);
      disableTimerInterrupts(QEI_Polling_DW.obj.TimerHandle, 0);
      ChannelInfo = ENABLE_CH;
      disableTimerChannel1(QEI_Polling_DW.obj.TimerHandle, ChannelInfo);
      disableTimerChannel2(QEI_Polling_DW.obj.TimerHandle, ChannelInfo);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Encoder2' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
