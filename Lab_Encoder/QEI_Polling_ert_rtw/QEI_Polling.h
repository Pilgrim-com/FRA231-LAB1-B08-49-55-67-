/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: QEI_Polling.h
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

#ifndef QEI_Polling_h_
#define QEI_Polling_h_
#ifndef QEI_Polling_COMMON_INCLUDES_
#define QEI_Polling_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "math.h"
#include "main.h"
#endif                                 /* QEI_Polling_COMMON_INCLUDES_ */

#include "QEI_Polling_types.h"
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

/* Block signals for system '<S13>/Digital Port Read' */
typedef struct {
  boolean_T DigitalPortRead;           /* '<S13>/Digital Port Read' */
} B_DigitalPortRead_QEI_Polling_T;

/* Block states (default storage) for system '<S13>/Digital Port Read' */
typedef struct {
  stm32cube_blocks_DigitalPortR_T obj; /* '<S13>/Digital Port Read' */
  boolean_T objisempty;                /* '<S13>/Digital Port Read' */
} DW_DigitalPortRead_QEI_Pollin_T;

/* Block states (default storage) for system '<Root>/MATLAB Function' */
typedef struct {
  real_T previousCount;                /* '<Root>/MATLAB Function' */
  real_T unwrappedPositionPrev;        /* '<Root>/MATLAB Function' */
  int32_T sfEvent;                     /* '<Root>/MATLAB Function' */
  boolean_T doneDoubleBufferReInit;    /* '<Root>/MATLAB Function' */
  boolean_T previousCount_not_empty;   /* '<Root>/MATLAB Function' */
  boolean_T unwrappedPositionPrev_not_empty;/* '<Root>/MATLAB Function' */
} DW_MATLABFunction_QEI_Polling_T;

/* Block signals (default storage) */
typedef struct {
  real_T X4_Position_QEI;              /* '<Root>/Gain' */
  real_T X2_Position_QEI;              /* '<Root>/Gain1' */
  real_T X1_Position_QEI;              /* '<Root>/Gain2' */
  real_T DataTypeConversion3;          /* '<Root>/Data Type Conversion3' */
  real_T DataTypeConversion4;          /* '<Root>/Data Type Conversion4' */
  real_T X1_Position;                  /* '<Root>/Gain3' */
  real_T X2_Position;                  /* '<Root>/Gain4' */
  real_T X4_Position;                  /* '<Root>/Gain5' */
  real_T pulse;                        /* '<Root>/MATLAB Function5' */
  real_T velocity;                     /* '<Root>/MATLAB Function5' */
  real_T pulse_n;                      /* '<Root>/MATLAB Function4' */
  real_T velocity_n;                   /* '<Root>/MATLAB Function4' */
  real_T pulse_b;                      /* '<Root>/MATLAB Function3' */
  real_T velocity_f;                   /* '<Root>/MATLAB Function3' */
  real_T pulse_i;                      /* '<Root>/MATLAB Function2' */
  real_T velocity_b;                   /* '<Root>/MATLAB Function2' */
  real_T pulse_g;                      /* '<Root>/MATLAB Function1' */
  real_T velocity_n2;                  /* '<Root>/MATLAB Function1' */
  real_T pulse_h;                      /* '<Root>/MATLAB Function' */
  real_T velocity_k;                   /* '<Root>/MATLAB Function' */
  B_DigitalPortRead_QEI_Polling_T DigitalPortRead_m;/* '<S13>/Digital Port Read' */
  B_DigitalPortRead_QEI_Polling_T DigitalPortRead_e;/* '<S13>/Digital Port Read' */
  B_DigitalPortRead_QEI_Polling_T DigitalPortRead;/* '<S13>/Digital Port Read' */
} B_QEI_Polling_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  stm32cube_blocks_EncoderBlock_T obj; /* '<Root>/Encoder2' */
  stm32cube_blocks_EncoderBlock_T obj_c;/* '<Root>/Encoder1' */
  stm32cube_blocks_EncoderBlock_T obj_m;/* '<Root>/Encoder' */
  real_T lastA;                        /* '<Root>/MATLAB Function5' */
  real_T lastB;                        /* '<Root>/MATLAB Function5' */
  real_T count;                        /* '<Root>/MATLAB Function5' */
  real_T lastCount;                    /* '<Root>/MATLAB Function5' */
  real_T lastA_b;                      /* '<Root>/MATLAB Function4' */
  real_T count_d;                      /* '<Root>/MATLAB Function4' */
  real_T lastCount_j;                  /* '<Root>/MATLAB Function4' */
  real_T lastA_j;                      /* '<Root>/MATLAB Function3' */
  real_T count_h;                      /* '<Root>/MATLAB Function3' */
  real_T lastCount_h;                  /* '<Root>/MATLAB Function3' */
  real_T previousCount;                /* '<Root>/MATLAB Function2' */
  real_T unwrappedPositionPrev;        /* '<Root>/MATLAB Function2' */
  boolean_T lastA_not_empty;           /* '<Root>/MATLAB Function5' */
  boolean_T lastB_not_empty;           /* '<Root>/MATLAB Function5' */
  boolean_T count_not_empty;           /* '<Root>/MATLAB Function5' */
  boolean_T lastCount_not_empty;       /* '<Root>/MATLAB Function5' */
  boolean_T lastA_not_empty_c;         /* '<Root>/MATLAB Function4' */
  boolean_T count_not_empty_i;         /* '<Root>/MATLAB Function4' */
  boolean_T lastCount_not_empty_m;     /* '<Root>/MATLAB Function4' */
  boolean_T lastA_not_empty_a;         /* '<Root>/MATLAB Function3' */
  boolean_T count_not_empty_m;         /* '<Root>/MATLAB Function3' */
  boolean_T lastCount_not_empty_g;     /* '<Root>/MATLAB Function3' */
  boolean_T previousCount_not_empty;   /* '<Root>/MATLAB Function2' */
  DW_MATLABFunction_QEI_Polling_T sf_MATLABFunction1;/* '<Root>/MATLAB Function1' */
  DW_MATLABFunction_QEI_Polling_T sf_MATLABFunction;/* '<Root>/MATLAB Function' */
  DW_DigitalPortRead_QEI_Pollin_T DigitalPortRead_m;/* '<S13>/Digital Port Read' */
  DW_DigitalPortRead_QEI_Pollin_T DigitalPortRead_e;/* '<S13>/Digital Port Read' */
  DW_DigitalPortRead_QEI_Pollin_T DigitalPortRead;/* '<S13>/Digital Port Read' */
} DW_QEI_Polling_T;

/* Real-time Model Data Structure */
struct tag_RTM_QEI_Polling_T {
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
extern B_QEI_Polling_T QEI_Polling_B;

/* Block states (default storage) */
extern DW_QEI_Polling_T QEI_Polling_DW;

/* Model entry point functions */
extern void QEI_Polling_initialize(void);
extern void QEI_Polling_step(void);
extern void QEI_Polling_terminate(void);

/* Real-time Model object */
extern RT_MODEL_QEI_Polling_T *const QEI_Polling_M;
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
 * '<Root>' : 'QEI_Polling'
 * '<S1>'   : 'QEI_Polling/Digital Port Read'
 * '<S2>'   : 'QEI_Polling/Digital Port Read1'
 * '<S3>'   : 'QEI_Polling/Digital Port Read2'
 * '<S4>'   : 'QEI_Polling/Digital Port Read3'
 * '<S5>'   : 'QEI_Polling/Digital Port Read4'
 * '<S6>'   : 'QEI_Polling/MATLAB Function'
 * '<S7>'   : 'QEI_Polling/MATLAB Function1'
 * '<S8>'   : 'QEI_Polling/MATLAB Function2'
 * '<S9>'   : 'QEI_Polling/MATLAB Function3'
 * '<S10>'  : 'QEI_Polling/MATLAB Function4'
 * '<S11>'  : 'QEI_Polling/MATLAB Function5'
 * '<S12>'  : 'QEI_Polling/Digital Port Read/ECSoC'
 * '<S13>'  : 'QEI_Polling/Digital Port Read/ECSoC/ECSimCodegen'
 * '<S14>'  : 'QEI_Polling/Digital Port Read1/ECSoC'
 * '<S15>'  : 'QEI_Polling/Digital Port Read1/ECSoC/ECSimCodegen'
 * '<S16>'  : 'QEI_Polling/Digital Port Read2/ECSoC'
 * '<S17>'  : 'QEI_Polling/Digital Port Read2/ECSoC/ECSimCodegen'
 * '<S18>'  : 'QEI_Polling/Digital Port Read3/ECSoC'
 * '<S19>'  : 'QEI_Polling/Digital Port Read3/ECSoC/ECSimCodegen'
 * '<S20>'  : 'QEI_Polling/Digital Port Read4/ECSoC'
 * '<S21>'  : 'QEI_Polling/Digital Port Read4/ECSoC/ECSimCodegen'
 */
#endif                                 /* QEI_Polling_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
