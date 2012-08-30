

#ifndef _IMP_PEA_SYSTEM_H_
#define _IMP_PEA_SYSTEM_H_

#include "imp_algo_urp_param.h"
#include "imp_algo_type.h"
#include "imp_pea_common.h"
#include "imp_para.h"
#include "imp_pea_obj_recognition.h"
#include "imp_pea_bva.h"
#include "imp_pea_target.h"

#ifdef __cplusplus
extern "C"
{
#endif

#define FAST_RAM_NODE_NUM	16
#define SLOW_RAM_NODE_NUM	128 //128
#define FAST_RAM_MEM_SIZE	(1024 * 1)

#define PEA_TIME_LIMIT 3 * 24 * 3600 * 8

#if defined(_TIDSP)
#define SLOW_RAM_MEM_SIZE	(1024 * 1024 * 7)
#elif defined(IMP_ARM_PEA)

#define SLOW_RAM_MEM_SIZE	(1024 * 1024 * 30) //30
#else
#define SLOW_RAM_MEM_SIZE	(1024 * 1024 * 9)
#endif


#define IMP_ALGIF_VERSION	IMP_MAKE_VERSION( 'R', 'V', 0x31, 0 )


typedef enum impPEA_OPER_TYPE_E
{
	IMP_OPER_TYPE_GetVersion		= 0x0001,	
	IMP_OPER_TYPE_GetFuncode		= 0x0002,
	IMP_OPER_TYPE_GetMemReq		    = 0x0008,	
	IMP_OPER_TYPE_GetDmaReq		    = 0x0009,
	IMP_OPER_TYPE_CheckScene		= 0x000F,	
	IMP_OPER_TYPE_Initialize		= 0x0010,	
	IMP_OPER_TYPE_Terminate		    = 0x0011,	
	IMP_OPER_TYPE_InitIdmaChs	    = 0x0012,
	IMP_OPER_TYPE_ConfigParameter   = 0x0020,
	IMP_OPER_TYPE_GetParameter	    = 0x0021,
	IMP_OPER_TYPE_GetEnacode		= 0x0022,
	IMP_OPER_TYPE_Start			    = 0x0028,
	IMP_OPER_TYPE_Stop			    = 0x0029,	
	IMP_OPER_TYPE_ProcessImage	    = 0x0030,
	IMP_OPER_TYPE_GetResults		= 0x0034,	
	IMP_OPER_TYPE_DoSpecial		    = 0x1000	
} PEA_OPER_TYPE_E;


typedef struct impPEA_OPER_S
{
	IMP_U32	u32Type;					
	IMP_VOID	*pData;					     
} PEA_OPER_S;



typedef enum impTYPE_PTZ_CTRL_E
{
	IMP_CMD_TYPE_PTZCtrl			= 0x0001100		
}TYPE_PTZ_CTRL_E;

#define ALGO_MINOR_VERSION	0x0A

#define ALGO_VERSION_R_0_1_3	IMP_MAKE_VERSION( 'R', 0, 0x31, 0 )
#define ALGO_VERSION	ALGO_VERSION_R_0_1_3


typedef struct impPEA_SYSTEM_PARA_S
{
	IMP_S32 s32OutputDRegion;		
	IMP_S32 s32OutputAllTgts;		
	IMP_S32 s32OutputPredicted;		
	IMP_S32 s32PtzTgtEvts;		
	IMP_S32 s32ProcInterval;		
	IMP_S32 s32TrajectDist;		
	IMP_S32	s32FrmDura;				
} PEA_SYSTEM_PARA_S;


IMP_VOID IMP_PEA_ParseProcessorParaData(PEA_SYSTEM_PARA_S *stPara );


typedef struct
{
	GA_HARDWARE_RS_S	stHwRes;			
	INNER_PARA_S		*pstInnerPara;	
	PEA_SYSTEM_PARA_S	*pstSysPara;		
	PEA_RESULT_S		*pstResult;			
	IMP_MODULE_HANDLE	hObjRecg;		
	IMP_MODULE_HANDLE	hEvtAnls;	 	 
} PEA_MODULE;


#define IMP_PROCESSOR_OUTPUT 0
#define IMP_PROCESSOR_OUTPUT_DREGION 0
#define IMP_PROCESSOR_OUTPUT_ALLTGTS 1
#define IMP_PROCESSOR_OUTPUT_PREDICTED 0
#define IMP_PROCESSOR_PTZ_TGTEVTS 0
#define IMP_PROCESSOR_PROC_INTERVAL 0//120 what's it
#define IMP_PROCESSOR_TRAJECT_DIST 3//8
#define IMP_PROCESSOR_FRM_DURA 1 //20 //40 why is it 40, maybe 25, for the detect, same to imp_para.c:pstPara->stGlobal.s32TimeUnit


#define IMP_DETECTOR_PREPROCESS 0
#define IMP_DETECTOR_DO_SMOOTH 1
#define IMP_DETECTOR_BGMODEL_PERSONENTER 0
#define IMP_DETECTOR_PERSONENTER_FGRATIO_HISLEN 50
#define IMP_DETECTOR_PERSONENTER_RATIO_THRETH 10
#define IMP_DETECTOR_FG_EDGE_RATIO_THRETH 50
#define IMP_DETECTOR_ADD_WEIGHT 1
#define IMP_DETECTOR_SUB_WEIGHT 2
#define IMP_DETECTOR_INC_RATIO_THRETH 5
#define IMP_DETECTOR_LEAVE_TIME 20000
#define IMP_DETECTOR_ENTER_TIME 600000
#define IMP_DETECTOR_SIMPLE_BGMODEL 0
#define IMP_DETECTOR_SIMPLE_BGM_THETA_THLD 15
#define IMP_DETECTOR_SIMPLE_BGM_GRAD_THETA_THLD 5
#define IMP_DETECTOR_SIMPLE_BGM_FG_RATIO_THLD 5
#define IMP_DETECTOR_SIMPLE_BGM_FRM_FG_RATIO_THLD 5
#define IMP_DETECTOR_SIMPLE_BGM_FGRATIO_HISLEN_THLD 50
#define IMP_DETECTOR_SIMPLE_BGM_HISLEN_RATIO_THLD 80
#define IMP_DETECTOR_SIMPLE_BGM_INIT_TIME 2000
#define IMP_DETECTOR_REGION_LABEL 0
#define IMP_DETECTOR_TH_DRG_MIN_SIZE_WH 2
#define IMP_DETECTOR_TH_DRG_MIN_SIZE_PIXEL_INIT 4
#define IMP_DETECTOR_TH_DRG_MIN_SIZE_PIXEL_MAX 32
#define IMP_DETECTOR_TH_DRG_MIN_SIZE_PIXEL_STEP 4
#define IMP_DETECTOR_TH_DRG_MAX_SIZE_RATIO 1
#define IMP_DETECTOR_REGION_FILTER 0
#define IMP_DETECTOR_TH_DRG_FILL_RATIO 10
#define IMP_DETECTOR_TH_DRG_ASPECT_RATIO 8
#define IMP_DETECTOR_TH_DRG_MIN_SIZE_ACTUAL 10
#define IMP_DETECTOR_TH_DRG_MAX_SIZE_ACTUAL 100000000
#define IMP_DETECTOR_REGION_TYPE 0
#define IMP_DETECTOR_MOTION_IS_LEFT 0
#define IMP_DETECTOR_TH_RGTM_DIFG_RATIO 10
#define IMP_DETECTOR_TH_RGTM_WIDH_RATIO 50
#define IMP_DETECTOR_TH_RGTS_SIZE_MIN 30
#define IMP_DETECTOR_TH_RGTS_SIZE_MAX 10000
#define IMP_DETECTOR_TH_RGTS_EDGE_MIN 0
#define IMP_DETECTOR_TH_RGTS_EDGE_MAX 100
#define IMP_DETECTOR_TH_RGTS_WIDH_RATIO 100
#define IMP_DETECTOR_TH_RGTS_INBG_SIZE 100
#define IMP_DETECTOR_TH_RGTS_INBG_DIFF 0
#define IMP_DETECTOR_TH_RGTS_STRENGTH_RATIO_L 90
#define IMP_DETECTOR_TH_RGTS_SHAPE_RATIO_L 50
#define IMP_DETECTOR_TH_RGTS_EDGE_RATIO_L 30
#define IMP_DETECTOR_TH_RGTS_STRENGTH_RATIO_R 110
#define IMP_DETECTOR_TH_RGTS_SHAPE_RATIO_R 50
#define IMP_DETECTOR_TH_RGTS_EDGE_RATIO_R 30
#define IMP_DETECTOR_REGION_MERGE 0
#define IMP_DETECTOR_MERGE_REGION 1
#define IMP_DETECTOR_MERGE_INNER 0
#define IMP_DETECTOR_MERGE_NEIGHBOR 1
#define IMP_DETECTOR_NEIGHBOR_DIFF 1
#define IMP_DETECTOR_TH_NEIGHBOR_RATIO 60
#define IMP_DETECTOR_MERGE_PARALLEL 0
#define IMP_DETECTOR_TH_MERGE_PALELDIS 2
#define IMP_DETECTOR_FOREGROUND_SUPPRESS 0
#define IMP_DETECTOR_SUPPRESS_FOREGROUND 1
#define IMP_DETECTOR_SUPFG_MIN_AREA_PIXEL 1000
#define IMP_DETECTOR_SUPFG_MAX_AREA_PIXEL 100000
#define IMP_DETECTOR_SUPFG_LIGHT 2
#define IMP_DETECTOR_SUPFG_MIN_AREA_LIGHT 1000
#define IMP_DETECTOR_SUPFG_MAX_AREA_LIGHT 100000
#define IMP_DETECTOR_SUPFGLT_EDGE_SHAPE_RATIO 30
#define IMP_DETECTOR_SUPFGLT_EDGE_DIST_RATIO 10
#define IMP_DETECTOR_SUPFGLT_EDGE_LIKE_RATIO_FG 50
#define IMP_DETECTOR_SUPFGLT_EDGE_LIKE_RATIO_BG 60
#define IMP_DETECTOR_SUPFGLT_USE_DIFF 0
#define IMP_DETECTOR_SUPFG_PENUMBRA 2
#define IMP_DETECTOR_SUPFG_MIN_AREA_PENU 100
#define IMP_DETECTOR_SUPFG_MAX_AREA_PENU 20000
#define IMP_DETECTOR_SUPFG_DIFF_RATIO 2
#define IMP_DETECTOR_SUPFG_DIFF_MAX 32
#define IMP_DETECTOR_SUPFG_PENU_THRESHOLD 12
#define IMP_DETECTOR_MAG_THRETH 20
#define IMP_DETECTOR_MIN_MAG_DIFF_NUM 10
#define IMP_DETECTOR_MIN_MAG_DIFF_RATIO 1
#define IMP_DETECTOR_SHADOW_DETECT 0
#define IMP_DETECTOR_DETECT_SHADOW 2
#define IMP_DETECTOR_TH_SHAPE_HEIGHT_RATIO 30
#define IMP_DETECTOR_TH_SHADOW_NUM_RATIO 70
#define IMP_DETECTOR_TH_SHADOW_HEIGHT_RATIO 30
#define IMP_DETECTOR_TH_SHADOW_MIN_WIDTH 10
#define IMP_DETECTOR_TH_SHADOW_MIN_HEIGHT 10
#define IMP_DETECTOR_TH_SHADOW_MAX_AREA_PIXEL 10000
#define IMP_DETECTOR_TH_SHADOW_MERGE 2
#define IMP_DETECTOR_TH_SHADOW_DELETE 2
#define IMP_DETECTOR_HIGHREGION_DETECT 0
#define IMP_DETECTOR_DETECT_HIGHREGION 0
#define IMP_DETECTOR_DETECT_GLOBAL_CHANGE 2
#define IMP_DETECTOR_TH_HR_WH_RATIO 80
#define IMP_DETECTOR_TH_HR_AREA_RATIO 50
#define IMP_DETECTOR_DETECT_LIGHT_REGION 0
#define IMP_DETECTOR_DETECT_BRIGHT_REGION 2
#define IMP_DETECTOR_DETECT_DARK_REGION 2
#define IMP_DETECTOR_TH_HR_AREA_PIXEL_MIN 100
#define IMP_DETECTOR_TH_HR_AREA_PIXEL_MAX 10000
#define IMP_DETECTOR_TH_HR_LUMI_RATIO 98
#define IMP_DETECTOR_TH_HR_GRAD_MIN 8
#define IMP_DETECTOR_TH_HR_GRAD_RATIO 2
#define IMP_DETECTOR_TH_HR_EDGE_NUM_RATIO 10
#define IMP_DETECTOR_TH_HR_EDGE_WH_RATIO 50
#define IMP_DETECTOR_TH_HR_EDGE_LIKE 50
#define IMP_DETECTOR_OTHER 0
#define IMP_DETECTOR_CODEBOOK_BG_MODEL 0
#define IMP_DETECTOR_THRESHOLD_MAX 12
#define IMP_DETECTOR_THRESHOLD_MIN 4
#define IMP_DETECTOR_THRESHOLD_UDPM 10
#define IMP_DETECTOR_THRESHOLD_NOISE_RATIO 10
#define IMP_DETECTOR_THRESHOLD_UP2DW_RATIO 10
#define IMP_DETECTOR_UPDATE_SPEED_MAX 5
#define IMP_DETECTOR_LEARN_RATE 2
#define IMP_DETECTOR_TCATCH 3
#define IMP_DETECTOR_TADD 400
#define IMP_DETECTOR_VIDEO_ABNML_DETECTOR 0
#define IMP_DETECTOR_TH_BLOB_MAX_SIZE_H 2
#define IMP_DETECTOR_TH_BLOB_MIN_SIZE_W 30
#define IMP_DETECTOR_FRAME_COUNT_THRESHOLD 5
#define IMP_DETECTOR_VIDEO_LOST_LUMI_TH 5
#define IMP_DETECTOR_OCCLUSION_THRESHOLD 20
#define IMP_DETECTOR_FIRECE_LIGHT_THRESHOLD 200
#define IMP_DETECTOR_VIDEO_LOST_ONE_BLOCK_PIXEL_NUM_TH 170
#define IMP_DETECTOR_VIDEO_LOST_BLOCK_NUM_TH 316
#define IMP_DETECTOR_OCCLUSION_ONE_BLOCK_PIXEL_NUM_TH 170
#define IMP_DETECTOR_OCCLUSION_BLOCK_NUM_TH 80
#define IMP_DETECTOR_FIRECE_LIGHT_ONE_BLOCK_PIXEL_NUM_TH 170
#define IMP_DETECTOR_FIRECE_LIGHT_BLOCK_NUM_TH 80
#define IMP_DETECTOR_LIGHT_MUTATION_ONE_BLOCK_PIXEL_NUM_TH 128
#define IMP_DETECTOR_LIGHT_MUTATION_BLOCK_NUM_TH 198
#define IMP_DETECTOR_FIELD_SCRAMBLE_ONE_BLOCK_PIXEL_NUM_TH 16
#define IMP_DETECTOR_FIELD_SCRAMBLE_BLOCK_NUM_TH 66
#define IMP_DETECTOR_ABNORMAL_JUDGE_TH 10
#define IMP_TRACKER_REMOVE_DREGION 0
#define IMP_TRACKER_REMOVE_CALB_FAIL_DREGION 0
#define IMP_TRACKER_TARGET_MERGE 0
#define IMP_TRACKER_MERGE_DREGION 0
#define IMP_TRACKER_MERGE_TTARGET 0
#define IMP_TRACKER_TARGET_MOTION 0
#define IMP_TRACKER_TIME_CALCULATE_VELOCITY 1000
#define IMP_TRACKER_FRMCNT_CALCULATE_VELOCITY 4
#define IMP_TRACKER_TM_STATIC_VELO_MAX 20
#define IMP_TRACKER_TM_STATIC_TIME_MIN 0
#define IMP_TRACKER_TARGET_MATCH 0
#define IMP_TRACKER_TRAJECT_USE_BOTTOM 0
#define IMP_TRACKER_WET_STBALE_TGT 1
#define IMP_TRACKER_AREA_COEF_MIN 0.1
#define IMP_TRACKER_HIST_COEF_MIN 0.1
#define IMP_TRACKER_STATIC_MATCH_DIS_MAX 0
#define IMP_TRACKER_DIS_CRL_SIZE 1
#define IMP_TRACKER_MAX_DISTANCE_MOTION 200
#define IMP_TRACKER_MAX_DISTANCE_STATIC 30
#define IMP_TRACKER_DIST_WEIGHT 0.50
#define IMP_TRACKER_HISTO_WEIGHT 0.20
#define IMP_TRACKER_AREA_WEIGHT 0.30
#define IMP_TRACKER_PREDICT_TARGET_DIST_WET 0.20
#define IMP_TRACKER_PREDICT_TARGET_HIST_WET 0.50
#define IMP_TRACKER_PREDICT_TARGET_AREA_WET 0.30
#define IMP_TRACKER_DIRECTION_DISTANCE_LIMIT 1
#define IMP_TRACKER_MIN_MATCH_COEF_LOW 0.60
#define IMP_TRACKER_MIN_MATCH_COEF_HIGH 0.75
#define IMP_TRACKER_TARGET_DISAPPEAR 0
#define IMP_TRACKER_PROCESS_DISAPPEAR_TARGET 1
#define IMP_TRACKER_MAX_DIRECT_DIFF 45
#define IMP_TRACKER_USED_TRAJECT_LEN 20
#define IMP_TRACKER_TARGET_MULTI_HYP 0
#define IMP_TRACKER_DO_MULTI_HYP 0
#define IMP_TRACKER_MIN_MATCH_COEF_MULTI_HYP_TAG 0.80
#define IMP_TRACKER_MULTI_HYP_RANGE_RATIO 2
#define IMP_TRACKER_COLLISION_SPLIT 1
#define IMP_TRACKER_STABLE_COLLISION 0
#define IMP_TRACKER_MULTI_TGT_SPLIT 1
#define IMP_TRACKER_REFINED_TGT_DISPLAY 0
#define IMP_TRACKER_SPLIT_DEFAULT_FEATURE 1
#define IMP_TRACKER_CORRECT_COLLISION_TRAJECTORY 2
#define IMP_TRACKER_SMOOTH_TRAJECTORY 2
#define IMP_TRACKER_SMOOTH_TIME_WND 10
#define IMP_TRACKER_MOTION_MEANSHIFT 0
#define IMP_TRACKER_MMS_ITER_MAX 2
#define IMP_TRACKER_MMS_DELTA_B 0.1
#define IMP_TRACKER_MMS_FG_WEIGHT 200
#define IMP_TRACKER_MMS_START_LIFE 20
#define IMP_TRACKER_MMS_START_COEF 1.9
#define IMP_TRACKER_MMS_END_COEF 0.75
#define IMP_TRACKER_MMS_UPDATE_ALPHA 0.04
#define IMP_TRACKER_MMS_SEARCH_SIZE_ZOOM 1.5
#define IMP_TRACKER_TRAJECTORY_ANALYSIS 0
#define IMP_TRACKER_TRAJECTORY_SIZE_SMOOTH_ANALYSIS 1
#define IMP_TRACKER_TARGET_STABLE 0
#define IMP_TRACKER_STABLE_OCCLUSION_TIME 3000
#define IMP_TRACKER_STABLE_BORDER_WIDTH 8
#define IMP_TRACKER_STABLE_MIN_FRMCNT 8
#define IMP_TRACKER_STABLE_MIN_TIME 1000
#define IMP_TRACKER_STABLE_MAX_TIME 200000
#define IMP_TRACKER_STABLE_VALID_RATIO 50
#define IMP_TRACKER_STABLE_VALID_FRMCNT 8
#define IMP_TRACKER_STABLE_SHAPE_RATIO 2
#define IMP_TRACKER_STABLE_MIN_DISTANCE 5
#define IMP_TRACKER_STABLE_MAX_DISTANCE 20
#define IMP_TRACKER_STABLE_TREND_RATIO 0
#define IMP_TRACKER_STABLE_TREND_MOTION 0
#define IMP_TRACKER_STABLE_DIS_RATIO 2
#define IMP_TRACKER_STABLE_NON0_RATIO 10
#define IMP_TRACKER_TAT_OUTPUT_HIGH_LEVEL 0
#define IMP_TRACKER_STABLE_MIN_FRMCNT_HIGH_LEVEL 4
#define IMP_TRACKER_STABLE_MIN_TIME_HIGH_LEVEL 500
#define IMP_TRACKER_STABLE_VALID_FRMCNT_HIGH_LEVEL 4
#define IMP_TRACKER_STABLE_MIN_DISTANCE_HIGH_LEVEL 3
#define IMP_TRACKER_STABLE_DIS_RATIO_HIGH_LEVEL 0
#define IMP_TRACKER_MIN_MATCH_COEF_HIGH_LEVEL 0.5
#define IMP_TRACKER_TAT_OUTPUT_MID_LEVEL 0
#define IMP_TRACKER_STABLE_MIN_FRMCNT_MID_LEVEL 8
#define IMP_TRACKER_STABLE_MIN_TIME_MID_LEVEL 1000
#define IMP_TRACKER_STABLE_VALID_FRMCNT_MID_LEVEL 8
#define IMP_TRACKER_STABLE_MIN_DISTANCE_MID_LEVEL 5
#define IMP_TRACKER_STABLE_DIS_RATIO_MID_LEVEL 2
#define IMP_TRACKER_MIN_MATCH_COEF_MID_LEVEL 0.75
#define IMP_TRACKER_TAT_OUTPUT_LOW_LEVLE 0
#define IMP_TRACKER_STABLE_MIN_FRMCNT_LOW_LEVEL 10
#define IMP_TRACKER_STABLE_MIN_TIME_LOW_LEVEL 1250
#define IMP_TRACKER_STABLE_VALID_FRMCNT_LOW_LEVEL 10
#define IMP_TRACKER_STABLE_MIN_DISTANCE_LOW_LEVEL 8
#define IMP_TRACKER_STABLE_DIS_RATIO_LOW_LEVEL 2
#define IMP_TRACKER_MIN_MATCH_COEF_LOW_LEVEL 0.75
#define IMP_TRACKER_TARGET_UPDATE 0
#define IMP_TRACKER_AREA_UPDATE_RATE 0.2
#define IMP_TRACKER_SIZE_UPDATE_RATE 0.2
#define IMP_TRACKER_HIST_UPDATE_RATE 0.2
#define IMP_TRACKER_CHANGE_TRACKER 0
#define IMP_TRACKER_CHG_STABLE_OCCLUSION_TIME 2000
#define IMP_TRACKER_CHG_STABLE_MIN_FRMCNT 16 //for target stable judgement
#define IMP_TRACKER_CHG_STABLE_MIN_TIME 1000 //3000 maybe too long, for target stable judgement
#define IMP_TRACKER_PTZ_CONTROL 0
#define IMP_TRACKER_SAMPLE_LINE 2
#define IMP_TRACKER_ZOOM_ENABLE 1
#define IMP_TRACKER_PTZ_TRACKING_TIME 20000
#define IMP_TRACKER_PTZ_SLEEP_TIME 150
#define IMP_TRACKER_PTZ_STOP_TIME 150
#define IMP_TRACKER_PTZ_ZOOM_TIMES 15
#define IMP_TRACKER_PTZ_SPEED_FURTHEST 0.75
#define IMP_TRACKER_PTZ_SPEED_FURTHER 0.72
#define IMP_TRACKER_PTZ_SPEED_NEAR 0.68
#define IMP_TRACKER_PTZ_SPEED_NEAREST 0.62
#define IMP_TRACKER_PTZ_ZOOM_PERIOD_PERTIME 300
#define IMP_TRACKER_PTZ_CENTER_SIZE 35
#define IMP_TRACKER_MAX_TARGET_RECT_X 240
#define IMP_TRACKER_MAX_TARGET_RECT_Y 200
#define IMP_TRACKER_TEMPLATE_COLS 40
#define IMP_TRACKER_TEMPLATE_ROWS 40
#define IMP_TRACKER_TEMPLATE_OFFSET_X 4
#define IMP_TRACKER_TEMPLATE_OFFSET_Y 4
#define IMP_TRACKER_MAX_TRACKING_REGION_WIDTH 120
#define IMP_TRACKER_MAX_TRACKING_REGION_HEIGHT 120
#define IMP_TRACKER_MIN_TRACKING_REGION_WIDTH 60
#define IMP_TRACKER_MIN_TRACKING_REGION_HEIGHT 60
#define IMP_TRACKER_STEP_X 3
#define IMP_TRACKER_STEP_Y 3
#define IMP_TRACKER_MAG_THRESHOLD 25
#define IMP_TRACKER_TPL_CRL_COEF_THD_HIGH 0.8
#define IMP_TRACKER_TPL_CRL_COEF_THD_LOW 0.6
#define IMP_TRACKER_TPL_CRL_RATIO_THD_HIGH 0.85
#define IMP_TRACKER_TPL_CRL_RATIO_THD_LOW 0.75
#define IMP_TRACKER_OTHER 0
#define IMP_TRACKER_FRM_DURA 40
#define IMP_CLASSIFIER_WORK_MODE 0
#define IMP_CLASSIFIER_SVM_FUNC_TYPE 1
#define IMP_CLASSIFIER_CLASS_TYPE 1
#define IMP_CLASSIFIER_FEATC_TYPE 1
#define IMP_CLASSIFIER_FEATV_TYPE 2
#define IMP_CLASSIFIER_CLASSIFIER_ANIMAL 0
#define IMP_CLASSIFIER_USE_MOTION_CONSTRAIN 0
#define IMP_CLASSIFIER_USE_BORDER_CONSTRAIN 0
#define IMP_CLASSIFIER_INDOOR_CONTEXT 0
#define IMP_CLASSIFIER_TTYPES 0
#define IMP_CLASSIFIER_HUMAN_SIZE_MIN 1000
#define IMP_CLASSIFIER_HUMAN_SIZE_MAX 100000
#define IMP_CLASSIFIER_HUMAN_VELO_MIN 0
#define IMP_CLASSIFIER_HUMAN_VELO_MAX 1000
#define IMP_CLASSIFIER_VEHICLE_SIZE_MIN 10000
#define IMP_CLASSIFIER_VEHICLE_SIZE_MAX 1000000
#define IMP_CLASSIFIER_VEHICLE_VELO_MIN 0
#define IMP_CLASSIFIER_VEHICLE_VELO_MAX 10000
#define IMP_CLASSIFIER_SCORE 0
#define IMP_CLASSIFIER_EDGE_RATIO 12
#define IMP_CLASSIFIER_THRE_DENSNESS 80
#define IMP_CLASSIFIER_HTHRE_ECCENTRICITY 90
#define IMP_CLASSIFIER_LTHRE_ECCENTRICITY 30
#define IMP_CLASSIFIER_HTHRE_ORIENTATION 90
#define IMP_CLASSIFIER_LTHRE_ORIENTATION 55
#define IMP_CLASSIFIER_THRE_HORIZON_ORIENTATION 20
#define IMP_CLASSIFIER_THRE_AFFIRM_NUM 10
#define IMP_CLASSIFIER_THRE_EDGE_NUM 10
#define IMP_CLASSIFIER_HTHRE_UPDOWNRATIO 30
#define IMP_CLASSIFIER_LTHRE_UPDOWNRATIO 10
#define IMP_CLASSIFIER_MIN_CAR_RECTLENGHT 17
#define IMP_CLASSIFIER_H_TYPERATIO 80
#define IMP_CLASSIFIER_L_TYPERATIO 50
#define IMP_CLASSIFIER_THRE_VELOCITY 50
#define IMP_CLASSIFIER_AREA_RATIO 12
#define IMP_CLASSIFIER_EDGE_THRE 8
#define IMP_CLASSIFIER_THRE_VERTICAL_EDGE_RATIO 4
#define IMP_CLASSIFIER_HAVE_TYPE_RATIO 80
#define IMP_CLASSIFIER_TYPE_RATIO 70
#define IMP_CLASSIFIER_PROBABILITY 0
#define IMP_CLASSIFIER_MIN_CONFIDENCE 0.3
#define IMP_CLASSIFIER_SCORE_TRAJECT_LEN 10
#define IMP_CLASSIFIER_FRM_DURA 40
#define IMP_CLASSIFIER_INSECT_USING_AIR_INFO 0
#define IMP_CLASSIFIER_INSECT_USING_SPECIAL_PLANE 0
#define IMP_CLASSIFIER_INSECT_CLASS_ASSISTANT 0

#define IMP_CLASSIFIER_INSECT_THRE_PIX_NUM 500
#define IMP_CLASSIFIER_INSECT_OBJECT_USING_POINT 0
#define IMP_CLASSIFIER_INSECT_THRE_NUM_IN_AIR 3
#define IMP_CLASSIFIER_INSECT_THRE_NUM_IN_WALL 3
#define IMP_CLASSIFIER_INSECT_THRE_RESOLUTION_RATIO 2.0
#define IMP_CLASSIFIER_INSECT_MAXLENGHT_DEVIATION 0.2
#define IMP_ANALYST_ANALYST_TYPE 0
#define IMP_ANALYST_ANALYST_PARAMETER 0
#define IMP_ANALYST_STATIC 0
#define IMP_ANALYST_STATIC_GRAD_RADIUS 3
#define IMP_ANALYST_STATIC_STRENGTH_MIN 10
#define IMP_ANALYST_STATIC_STRENGTH_DIFF 10
#define IMP_ANALYST_TRGN_TRAJECT_LEN 16
#define IMP_ANALYST_TRGN_TRAJECT_RATIO 70
#define IMP_ANALYST_OBJECTREMOVED 0
#define IMP_ANALYST_OBJECTLEFT 0
#define IMP_ANALYST_NOPARKING 0
#define IMP_ANALYST_NOPARKING_USE_MTREND 0
#define IMP_ANALYST_PERIMETER 0
#define IMP_ANALYST_PERIMETER_USE_MTREND 1
#define IMP_ANALYST_PERIMETER_USE_BOTTOM 1
#define IMP_ANALYST_PERIMETER_RATIO 5
#define IMP_ANALYST_PERIMETER_DELICACY 1
#define IMP_ANALYST_PERIMETER_ANALYLEN 10
#define IMP_ANALYST_PERIMETER_VALID_RATIO 60
#define IMP_ANALYST_PERIMETER_INTRUSION_RATIO 10
#define IMP_ANALYST_PERIMETER_ENTER_RATIO 100
#define IMP_ANALYST_PERIMETER_EXIT_RATIO 10
#define IMP_ANALYST_PERIMETER_APPEAR_RATIO 10
#define IMP_ANALYST_PERIMETER_DISAPPEAR_RATIO 10
#define IMP_ANALYST_PERIMETER_DISAPPEAR_ALARM_TIME 100
#define IMP_ANALYST_PERIMETER_TOLERANCE 45
#define IMP_ANALYST_ABSNORMALVEL 0
#define IMP_ANALYST_ABSNORMALVEL_USE_MTREND 1
#define IMP_ANALYST_CONVERSE 0
#define IMP_ANALYST_CONVERSE_USE_MTREND 1
#define IMP_ANALYST_CONVERSE_ANALY_LEN 20
#define IMP_ANALYST_CONVERSE_THRE_DISTANCE 100
#define IMP_ANALYST_TRIPWIRE 0
#define IMP_ANALYST_TRIPWIRE_USE_MTREND 1
#define IMP_ANALYST_TRIPWIRE_USE_BOTTOM 0 //if use bottom as trajectory.
#define IMP_ANALYST_TRIPWIRE_USE_OBJECT_TREND 1
#define IMP_ANALYST_TRIPWIRE_ANALYST_LEN 8
#define IMP_ANALYST_TRIPWIRE_VALID_RATIO 80
#define IMP_ANALYST_TRIPWIRE_TOLERANCE_ANGLE 110
#define IMP_ANALYST_TRIPWIRE_AWAY_DISTANCE 3
#define IMP_ANALYST_TRIPWIRE_SEG_LEN 15
#define IMP_ANALYST_MTRIPWIRE 0
#define IMP_ANALYST_MTRIPWIRE_USE_MTREND1 0
#define IMP_ANALYST_MTRIPWIRE_USE_BOTTOM1 1
#define IMP_ANALYST_MTRIPWIRE_USE_OBJECT_TREND1 1
#define IMP_ANALYST_MTRIPWIRE_ANALYST_LEN1 8
#define IMP_ANALYST_MTRIPWIRE_VALID_RATIO1 80
#define IMP_ANALYST_MTRIPWIRE_TOLERANCE_ANGLE1 110
#define IMP_ANALYST_MTRIPWIRE_AWAY_DISTANCE1 3
#define IMP_ANALYST_MTRIPWIRE_SEG_LEN1 5
#define IMP_ANALYST_MTRIPWIRE_USE_MTREND2 1
#define IMP_ANALYST_MTRIPWIRE_USE_BOTTOM2 1
#define IMP_ANALYST_MTRIPWIRE_USE_OBJECT_TREND2 1
#define IMP_ANALYST_MTRIPWIRE_ANALYST_LEN2 8
#define IMP_ANALYST_MTRIPWIRE_VALID_RATIO2 80
#define IMP_ANALYST_MTRIPWIRE_TOLERANCE_ANGLE2 110
#define IMP_ANALYST_MTRIPWIRE_AWAY_DISTANCE2 3
#define IMP_ANALYST_MTRIPWIRE_SEG_LEN2 5
#define IMP_ANALYST_LOITER 0
#define IMP_ANALYST_LOITER_USE_MTREND 1
#define IMP_ANALYST_LOITER_CURVE2LINE_RATIO 0.600
#define IMP_ANALYST_LOITER_DEVIATION 25
#define IMP_ANALYST_LOITER_TIMETHRED 25
#define IMP_ANALYST_SLIPUP 0
#define IMP_ANALYST_SLIPUP_USE_MTREND 1
#define IMP_ANALYST_SLIPUP_STATIC_VELOCITY 15
#define IMP_ANALYST_MORPH_LEVEL 2
#define IMP_ANALYST_MIN_CONNECTIVITY 2
#define IMP_ANALYST_BG_UPDATE_TIME 20000
#define IMP_ANALYST_LEAVE_LIMIT 1
#define IMP_ANALYST_DO_SPCL_RG_PROCESS 1
#define IMP_ANALYST_SPCL_MIN_TIME 15000
#define IMP_ANALYST_OUTPUT_EVENT 0
#define IMP_ANALYST_INIT_EVENT_LIFE 1000
#define IMP_ANALYST_OTHER
#define IMP_ANALYST_FRM_DURA 1 //20 //the cost time of processing a frame, for the event analyze, same to imp_para.c:pstPara->stGlobal.s32TimeUnit
#define IMP_ANALYST_OBJECT_AREA_RATIO 120


#ifdef __cplusplus
}
#endif

#endif

