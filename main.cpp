//
//  main.cpp
//  precisetime
//
//  Created by Joe Snider on 8/4/21.
//

#if __cplusplus
extern "C" {
#endif
#include <mach/mach_time.h>
#if __cplusplus
}
#endif

#define DllExport __attribute__(( visibility("default") ))

extern "C"
{
    DllExport long GetSystemTimePreciseAsFileTime() {
        mach_timebase_info_data_t sTimebaseInfo;
        mach_timebase_info(&sTimebaseInfo);
        return mach_continuous_time() * sTimebaseInfo.numer / sTimebaseInfo.denom;
    }
}
