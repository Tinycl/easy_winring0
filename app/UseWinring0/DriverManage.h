#pragma once
#include<Windows.h>
#include<tchar.h>
#include "DriverApi.h"


#ifdef __cplusplus    
extern "C" {          
#endif

//-----------------------------------------------------------------------------
// Use Driver Must Be Initialize
//-----------------------------------------------------------------------------
BOOL Initialize(LPCTSTR DriverPath);

//-----------------------------------------------------------------------------
// Must Remove Before Application leave
//-----------------------------------------------------------------------------
BOOL Deinitialize();

BOOL Open_Driver();
BOOL InstallDriver(LPCTSTR DriverId, LPCTSTR DriverPath);
BOOL RemoveDriver(LPCTSTR DriverId);
BOOL StartDriver(LPCTSTR DriverId);
BOOL StopDriver(LPCTSTR DriverId);

#ifdef __cplusplus
}
#endif

