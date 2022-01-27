// Copyright (c) Microsoft. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for full license information.

#ifndef LOG_SINK_ETW_H
#define LOG_SINK_ETW_H

#include <stdio.h>

#include "windows.h"
#include "TraceLoggingProvider.h"
#include "evntrace.h"

const TraceLoggingHProvider* lazyRegisterEventProvider(void);

#define LOG_SINK_ETW_LOG(log_level, file, function, line, format, ...)             \
    {                                                                                           \
        char message[LOG_MAX_MESSAGE_LENGTH];                                                   \
        const TraceLoggingHProvider* tracelogging_handle = lazyRegisterEventProvider();         \
        (void)sprintf(message, format MU_IFCOMMALOGIC(MU_COUNT_ARG(__VA_ARGS__)) __VA_ARGS__);  \
        TraceLoggingWrite(*tracelogging_handle,                                                 \
            "LogError",                                                                         \
            TraceLoggingLevel(TRACE_LEVEL_ERROR),                                               \
            TraceLoggingString(message, "content"),                                             \
            TraceLoggingString(file, "file"),                                                   \
            TraceLoggingString(function, "func"),                                               \
            TraceLoggingInt32(line, "line")                                                     \
        );                                                                                      \
    }                                                                                           \

#define LOG_SINK_ETW_LOG_WITH_CONTEXT(log_level, log_context_definition, log_context, file, function, line, format, ...)\
    {                                                                                           \
        char message[LOG_MAX_MESSAGE_LENGTH];                                                   \
        const TraceLoggingHProvider* tracelogging_handle = lazyRegisterEventProvider();         \
        (void)sprintf(message, format MU_IFCOMMALOGIC(MU_COUNT_ARG(__VA_ARGS__)) __VA_ARGS__);  \
        TraceLoggingWrite(*tracelogging_handle,                                                 \
            "LogError",                                                                         \
            TraceLoggingLevel(TRACE_LEVEL_ERROR),                                               \
            TraceLoggingString(message, "content"),                                             \
            TraceLoggingString(file, "file"),                                                   \
            TraceLoggingString(function, "func"),                                               \
            TraceLoggingInt32(line, "line")                                                     \
        );                                                                                      \
    }                                                                                           \

#endif /* LOG_SINK_ETW_H */
