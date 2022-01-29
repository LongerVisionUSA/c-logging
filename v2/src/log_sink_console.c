// Copyright (c) Microsoft. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for full license information.

#include <stdio.h>
#include <stdarg.h>

#include "macro_utils/macro_utils.h"

#include "c_logging/logger.h"
#include "c_logging/log_sink_console.h"

MU_DEFINE_ENUM_STRINGS_WITHOUT_INVALID(LOG_LEVEL, LOG_LEVEL_VALUES);

void log_sink_console_log(LOG_LEVEL log_level, LOG_CONTEXT_HANDLE log_context, const char* message, const char* file, const char* func, int line)
{
    time_t t = time(NULL);

    if (log_context != NULL)
    {
        (void)printf("%s", log_context->context_string);
    }
    printf("%s Time:%.24s File:%s Func:%s Line:%d %s\r\n", MU_ENUM_TO_STRING(LOG_LEVEL, log_level), ctime(&t), file, func, line, message);
}

LOG_SINK console_log_sink = { log_sink_console_log };
