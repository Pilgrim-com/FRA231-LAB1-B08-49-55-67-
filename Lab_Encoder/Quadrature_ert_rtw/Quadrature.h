/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Quadrature.h
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

#ifndef Quadrature_h_
#define Quadrature_h_
#ifndef Quadrature_COMMON_INCLUDES_
#define Quadrature_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "math.h"
#include "main.h"
#endif                                 /* Quadrature_COMMON_INCLUDES_ */

#include "Quadrature_types.h"
#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWExtModeInfo
#define rtmGetRTWExtModeInfo(rtm)      ((rtm)->extModeInfo)
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                (&(rtm)->Timing.taskTime0)
#endif

/* Block signals for system '<S8>/Digital Port Read' */
typedef struct {
  boolean_T DigitalPortRead;           /* '<S8>/Digital Port Read' */
} B_DigitalPortRead_Quadrature_T;

/* Block states (default storage) for system '<S8>/Digital Port Read' */
typedef struct {
  stm32cube_blocks_DigitalPortR_T obj; /* '<S8>/Digital Port Read' */
  boolean_T objisempty;                /* '<S8>/Digital Port Read' */
} DW_DigitalPortRead_Quadrature_T;

/* Block signals (default storage) */
typedef struct {
  real_T X4_Position;                  /* '<Root>/Gain' */
  real_T X2_Position;                  /* '<Root>/Gain1' */
  real_T X1_Position;                  /* '<Root>/Gain2' */
  real_T pulse;                        /* '<Root>/MATLAB Function2' */
  real_T velocity;                     /* '<Root>/MATLAB Function2' */
  real_T pulse_b;                      /* '<Root>/MATLAB Function1' */
  real_T velocity_d;                   /* '<Root>/MATLAB Function1' */
  real_T pulse_e;                      /* '<Root>/MATLAB Function' */
  real_T velocity_h;                   /* '<Root>/MATLAB Function' */
  B_DigitalPortRead_Quadrature_T DigitalPortRead_h;/* '<S8>/Digital Port Read' */
  B_DigitalPortRead_Quadrature_T DigitalPortRead_l;/* '<S8>/Digital Port Read' */
  B_DigitalPortRead_Quadrature_T DigitalPortRead;/* '<S8>/Digital Port Read' */
} B_Quadrature_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  stm32cube_blocks_EncoderBlock_T obj; /* '<Root>/Encoder2' */
  stm32cube_blocks_EncoderBlock_T obj_n;/* '<Root>/Encoder1' */
  stm32cube_blocks_EncoderBlock_T obj_p;/* '<Root>/Encoder' */
  real_T previousCount;                /* '<Root>/MATLAB Function2' */
  real_T unwrappedPositionPrev;        /* '<Root>/MATLAB Function2' */
  real_T previousCount_i;              /* '<Root>/MATLAB Function1' */
  real_T unwrappedPositionPrev_d;      /* '<Root>/MATLAB Function1' */
  real_T previousCount_o;              /* '<Root>/MATLAB Function' */
  real_T unwrappedPositionPrev_o;      /* '<Root>/MATLAB Function' */
  boolean_T previousCount_not_empty;   /* '<Root>/MATLAB Function2' */
  boolean_T previousCount_not_empty_o; /* '<Root>/MATLAB Function1' */
  boolean_T previousCount_not_empty_p; /* '<Root>/MATLAB Function' */
  DW_DigitalPortRead_Quadrature_T DigitalPortRead_h;/* '<S8>/Digital Port Read' */
  DW_DigitalPortRead_Quadrature_T DigitalPortRead_l;/* '<S8>/Digital Port Read' */
  DW_DigitalPortRead_Quadrature_T DigitalPortRead;/* '<S8>/Digital Port Read' */
} DW_Quadrature_T;

/* Real-time Model Data Structure */
struct tag_RTM_Quadrature_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T taskTime0;
    uint32_T clockTick0;
    time_T stepSize0;
    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block signals (default storage) */
extern B_Quadrature_T Quadrature_B;

/* Block states (default storage) */
extern DW_Quadrature_T Quadrature_DW;

/* Model entry point functions */
extern void Quadrature_initialize(void);
extern void Quadrature_step(void);
extern void Quadrature_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Quadrature_T *const Quadrature_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'Quadrature'
 * '<S1>'   : 'Quadrature/Digital Port Read'
 * '<S2>'   : 'Quadrature/Digital Port Read1'
 * '<S3>'   : 'Quadrature/Digital Port Read2'
 * '<S4>'   : 'Quadrature/MATLAB Function'
 * '<S5>'   : 'Quadrature/MATLAB Function1'
 * '<S6>'   : 'Quadrature/MATLAB Function2'
 * '<S7>'   : 'Quadrature/Digital Port Read/ECSoC'
 * '<S8>'   : 'Quadrature/Digital Port Read/ECSoC/ECSimCodegen'
 * '<S9>'   : 'Quadrature/Digital Port Read1/ECSoC'
 * '<S10>'  : 'Quadrature/Digital Port Read1/ECSoC/ECSimCodegen'
 * '<S11>'  : 'Quadrature/Digital Port Read2/ECSoC'
 * '<S12>'  : 'Quadrature/Digital Port Read2/ECSoC/ECSimCodegen'
 */
#endif                                 /* Quadrature_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
