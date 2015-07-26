#include "StdAfx.h"
#include "utility.h"

#include <IPHlpApi.h>
#pragma comment(lib, "Iphlpapi.lib")

//namespace networkutility;

utility::utility(void)
{
}

utility::~utility(void)
{
}

BOOL  utility::getLocalAddress(char *sLocalIP, unsigned char  MacAddr[6])
{
	PIP_ADAPTER_INFO pAdapterInfo;
	PIP_ADAPTER_INFO pAdapter = NULL;
	DWORD dwRetVal = 0;
	DWORD ulOutBufLen;

	if (NULL == sLocalIP || NULL == MacAddr) {
		return FALSE;
	}
	pAdapterInfo = (IP_ADAPTER_INFO *) malloc( sizeof(IP_ADAPTER_INFO) );
	ulOutBufLen = sizeof(IP_ADAPTER_INFO);

	// Make an initial call to GetAdaptersInfo to get
	// the necessary size into the ulOutBufLen variable
	if (GetAdaptersInfo( pAdapterInfo, &ulOutBufLen) == ERROR_BUFFER_OVERFLOW) {
		free(pAdapterInfo);
		pAdapterInfo = (IP_ADAPTER_INFO *) malloc (ulOutBufLen); 
	}

	if ((dwRetVal = GetAdaptersInfo( pAdapterInfo, &ulOutBufLen)) == NO_ERROR) {
		//strcpy(sLocalIP, pAdapterInfo->IpAddressList.IpAddress.String);
		*(unsigned long*)sLocalIP =  inet_addr(pAdapterInfo->IpAddressList.IpAddress.String);
		memcpy(MacAddr, pAdapterInfo->Address, 6);
	}
	free(pAdapterInfo);
	if (NO_ERROR != dwRetVal)  {
		return FALSE;
	}
	return TRUE;
}
