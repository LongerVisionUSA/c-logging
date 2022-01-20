// Copyright (c) Microsoft. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for full license information.

#include <stdint.h>
#include <stdarg.h>
#include <stdio.h>

#include "c_logging/logger.h"
#include "c_logging/log_sink_console.h"
#include "c_logging/log_sink_etw.h"

static const LOG_SINK* log_sinks[] = { &console_log_sink, &etw_log_sink };
static uint32_t sink_count = 2;

void logger_log(LOG_LEVEL log_level, const char* format, ...)
{
    uint32_t i;
    va_list args;
    va_start(args, format);

    char message[LOG_MAX_MESSAGE_LENGTH];

    vsprintf(message, format, args);

    for (i = 0; i < sink_count; i++)
    {
        log_sinks[i]->log_sink_log(log_level, NULL, message, __FILE__, __FUNCTION__, __LINE__);
    }

    va_end(args);
}

void logger_log_with_context(LOG_LEVEL log_level, LOG_CONTEXT_HANDLE log_context, const char* format, ...)
{
    uint32_t i;
    va_list args;
    va_start(args, format);

    char message[LOG_MAX_MESSAGE_LENGTH];

    vsprintf(message, format, args);

    for (i = 0; i < sink_count; i++)
    {
        log_sinks[i]->log_sink_log(log_level, log_context, message, __FILE__, __FUNCTION__, __LINE__);
    }

    va_end(args);
}
