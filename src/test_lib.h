/*
 * Copyright (C) 2014-2016 Wilddog Technologies. All Rights Reserved. 
 *
 * FileName: list_lib.h
 *
 * Description: connection functions.
 *
 * History:
 * Version      Author          Date        Description
 *
 * 0.4.0        lsx       2015-07-6  Create file.
 *
 */

#ifndef _WILDDOG_TEST_LIB_H_
#define _WILDDOG_TEST_LIB_H_

#include "wilddog.h"
#include "test_config.h"
#ifdef __cplusplus
extern "C"
{
#endif

#ifdef WILDDOG_SELFTEST

typedef struct RAMTEST_T{
	u32 tree_num;
	u32 request_num;
	u32 d_sendfalt;
	u32 d_recverr;
	u32 d_node_ram;
	u32 d_x509_ram;
	u32 d_requestQeue_ram;
	u32 d_average_ram;
	u32 d_peak_ram;
	u32 d_packet_size;
	u32 d_protocol_size;
	u32 d_gethostbyname;

	u32 d_sys_ramusage;
	u32 d_mallocblks_init;		
	u32 d_stackblks_init;	
	u32 mallocblks;
	u32 stackblks;
	
}Ramtest_T;


#define NODE_INDEX_RAMTST	1
#define REQUESTCNT_RAMTST		1

/* ram test_api*/
extern void ramtest_init(u32 tree_num,u32 request_num);
extern void ramtest_titile_printf(void);
extern void ramtest_end_printf(void);
extern void ramtest_getAveragesize(void);
extern int ramtest_getLastStackSize(Ramtest_T *p);
extern int ramtest_getSysRamusage(Ramtest_T *p,u32 *p_uage);
extern void ramtest_caculate_nodeRam(void);
extern void ramtest_caculate_x509Ram(void);
extern void ramtest_caculate_requestQueueRam(void);
extern void ramtest_caculate_averageRam(void);
extern int ramtest_get_averageRam(void);
extern void ramtest_caculate_peakRam(void);
extern void ramtest_skipLastmalloc(void);
extern void ramtest_gethostbyname(void);
extern void ramtest_caculate_packetsize(unsigned short packetSize);
extern int ramtest_printfmallocState(void);
extern int ramtest(void);


extern void performtest_star_tm(void);
extern void performtest_tm_getDtlsHsk(void);
extern void performtest_tm_getDtlsHskVerify(void);
extern void performtest_tm_getAuthSend(void);
extern void performtest_tm_getAuthWait(void);
extern void performtest_tm_getAuthHandle(void);
extern void performtest_tm_getSend(void);
extern void performtest_tm_getDtlsSend(void);
extern void performtest_tm_getRecv_wait(void);
extern void performtest_tm_getRecvDtls(void);
extern void performtest_tm_getRecv(void);
extern int  performtest_all(void);


extern int test_buildtreeFunc(const char *p_userUrl);

#endif /* WILDDOG_SELFTEST*/
#ifdef __cplusplus
}
#endif

#endif /*_WILDDOG_TEST_LIB_H_*/

