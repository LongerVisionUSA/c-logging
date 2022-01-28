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
        for (uint32_t i = 0; i < log_context->property_count; i++)
        {
            char temp_str[LOG_MAX_MESSAGE_LENGTH];
            log_context->properties[i].type.to_string_func(log_context->properties[i].value, temp_str, LOG_MAX_MESSAGE_LENGTH);
            (void)printf("%s=%s ", log_context->properties[0].name, temp_str);
        }
    }
    printf("%s Time:%.24s File:%s Func:%s Line:%d %s\r\n", MU_ENUM_TO_STRING(LOG_LEVEL, log_level), ctime(&t), file, func, line, message);
}

LOG_SINK console_log_sink = { log_sink_console_log };
