



#define MAXIMUM_FRAMEWORK_TESTS 				30

#define DEBUG_UART_PORT						5
#define GCOV_UART_PORT						4

#define Test00A_MON_Init					1
#define Test00A_MON_Tick					2
#define Test00A_MON_GetUsageData				3
#define Test00A_MON_GetIdleCPUUsageData				4
#define Test00A_MON_GetMaximumStackUsage			5
#define Test00A_MON_GetQueuedItemsCount				6
#define Test00A_MON_IndicateInterfaceActivated			7
#define Test00A_MON_IndicateInterfaceDeactivated		8
#define Test00A_MON_FreezeInterfaceActivationLogging		9
#define Test00A_MON_UnfreezeInterfaceActivationLogging		10
#define Test00A_MON_ClearInterfaceActivationLog			11
#define Test00A_MON_SporadicExactStackSize			12
#define Test00A_MON_CyclicExactStackSize                        13
#define Test00A_MON_DEFAULT_UNKNOWN_ERROR			14


#define TestProt_Zero_Parameters				30
#define TestProt_FiveIN_Parameters				31
#define TestProt_FiveOUT_Parameters				32

#define TestUnProt_Zero_Parameters                              40
#define TestUnProt_FiveIN_Parameters                            41
#define TestUnProt_FiveOUT_Parameters                           42

#define TesTest00A_MON_SPORADIC_GetQueuedItemsCount		50

#define ActLog_ClearInterfaceActivationLog			60
#define ActLog_UnFreezeActivationLog				61

#define TestHAL_Initialisation					70
#define TestHAL_Hal_GetElapsedTimeInNs				71
#define TestHAL_Hal_SleepNs					72
#define TestHAL_Hal_SemaphoreCreate				73
#define TestHAL_Hal_SemaphoreObtain				74
#define TestHAL_Hal_SemaphoreRelease				75
#define TestHAL_Hal_GetResetReason                              76
#define TestHAL_Hal_IdleTask					77

#define TestCOMMS10_SR11_Communication_Test			80
#define TestCOMMS10_SR12_Communication_Test 			81
#define TestCOMMS10_SR13_Communication_Test                     82
#define TestCOMMS10_SR14_Communication_Test                     83
#define TestCOMMS10_SR15_Communication_Test                     84
#define TestCOMMS10_SR16_Communication_Test                     85
#define TestCOMMS10_SR17_Communication_Test                     86
#define TestCOMMS10_SR18_Communication_Test                     87
#define TestCOMMS10_SR19_Communication_Test                     88
#define TestCOMMS10_SR20_Communication_Test                     89

#define TestCOMMS09_SR01_Communications_Test			90
#define TestCOMMS09_SR02_Communications_Test                    91
#define TestCOMMS09_SR03_Communications_Test                    92
#define TestCOMMS09_SR04_Communications_Test                    93
#define TestCOMMS09_SR05_Communications_Test                    94
#define TestCOMMS09_SR06_Communications_Test                    95
#define TestCOMMS09_SR07_Communications_Test                    96
#define TestCOMMS09_SR08_Communications_Test                    97
#define TestCOMMS09_SR09_Communications_Test                    98
#define TestCOMMS09_SR10_Communications_Test                    99



#define TestACNCoverstion_TestACN01				100
#define TestACNCoverstion_TestACN02                             101
#define TestACNCoverstion_TestACN03                             102
#define TestACNCoverstion_TestACN04                             103
#define TestACNCoverstion_TestACN05                             104

#define Test_ActivationLog_Clear				120
#define Test_ActivationLog_Unfreeze				121
#define Test_Activate_Interfaces				122
#define Test_DeActivate_Interface				124
#define Test_ReadActivation_Log_Entry				125
#define Test_Activity_Log_TimeStamp				126

#define Test_SAMRH71_CORE_extract_main_oscillator_frequency	140
#define Test_SAMRH71_CORE_SamRH71Core_GetMainClockFrequency	141
#define Test_SAMRH71_CORE_SamRH71Core_GenerateNewSemaphoreName	142
#define Test_SAMRH71_CORE_SamRH71Core_GenerateNewTaskName       143

#define Test_CYCLIC_TIME_RESOLUTION_TOO_HIGH			150
#define Test_CYCLIC_TIME_RESOLUTION_TOO_LOW			151

#define Test_Passed						500

// --------------------------------------------------------------
// -- Function prototypes used furing the Taste Test Framework --
// --------------------------------------------------------------

//void MBEP_Taste_Test_Report_To_Uart( char *Test_ID,
//                                     char *Test_Result
//                                     char *Test_Reason );

#define PRINT_RESULTS						0
 
