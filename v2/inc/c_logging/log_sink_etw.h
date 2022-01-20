// Copyright (c) Microsoft. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for full license information.

#ifndef LOG_SINK_ETW_H
#define LOG_SINK_ETW_H

#include "windows.h"
#include "TraceLoggingProvider.h"
#include "evntrace.h"

extern _tlg_EXTERN_C_CONST TraceLoggingHProvider g_my_component_provider;

#define LOG_SINK_ETW_LOG(format, file, function, line, ...) \
    TraceLoggingWrite(g_my_component_provider, \
        "LogError", \
        TraceLoggingLevel(TRACE_LEVEL_ERROR), \
        TraceLoggingString(message, "content"), \
        TraceLoggingString(file, "file"), \
        TraceLoggingString(func, "func"), \
        TraceLoggingInt32(line, "line")) \


#endif /* LOG_SINK_ETW_H */
