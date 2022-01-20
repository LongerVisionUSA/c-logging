// Copyright (c) Microsoft. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for full license information.

#include <stdio.h>
#include <stdarg.h>

#include "windows.h"

#include "TraceLoggingProvider.h"
#include "evntrace.h"

#include "macro_utils/macro_utils.h"

#include "c_logging/logger.h"
#include "c_logging/log_sink_console.h"

TRACELOGGING_DEFINE_PROVIDER(
    g_my_component_provider,
    "block_storage_2",
    (0xDAD29F36, 0x0A48, 0x4DEF, 0x9D, 0x50, 0x8E, 0xF9, 0x03, 0x6B, 0x92, 0xB4));
/*DAD29F36-0A48-4DEF-9D50-8EF9036B92B4*/

static volatile LONG isETWLoggerRegistered = 0;

static void lazyRegisterEventProvider(void)
{
    /*lazily init the logger*/
    LONG state;
    while ((state = InterlockedCompareExchange(&isETWLoggerRegistered, 1, 0)) != 2) /*0 - not init, 1 - initializing, 2 - initialized*/
    {
        if (state == 0)
        {
            /* register the provider*/
            TLG_STATUS t = TraceLoggingRegister(g_my_component_provider);
            if (SUCCEEDED(t))
            {
                (void)InterlockedExchange(&isETWLoggerRegistered, 2);
                printf("block_storage_2 ETW provider was registered succesfully (self test). Executable file full path name = %s", _pgmptr); /*_pgmptr comes from https://docs.microsoft.com/en-us/windows/win32/api/libloaderapi/nf-libloaderapi-getmodulefilenamea */
            }
            else
            {
                (void)printf("block_storage_2 ETW provider was NOT registered.");
                (void)InterlockedExchange(&isETWLoggerRegistered, 0);
            }
        }
    }
}

void log_sink_etw_log(LOG_LEVEL log_level, LOG_CONTEXT_HANDLE log_context, const char* message, const char* file, const char* func, int line)
{
    (void)log_level;
    (void)log_context;
    TraceLoggingWrite(g_my_component_provider,
        "LogError",
        TraceLoggingLevel(TRACE_LEVEL_ERROR),
        TraceLoggingString(message, "content"),
        TraceLoggingString(file, "file"),
        TraceLoggingString(func, "func"),
        TraceLoggingInt32(line, "line")
    );
}

LOG_SINK etw_log_sink = { log_sink_etw_log };
