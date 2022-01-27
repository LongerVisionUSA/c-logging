// Copyright (c) Microsoft. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for full license information.

#ifndef LOG_SINK_CONSOLE_H
#define LOG_SINK_CONSOLE_H

#define LOG_SINK_CONSOLE_LOG(log_level, file, function, line, format, ...)                                                                      \
{                                                                                                                                               \
    time_t t = time(NULL);                                                                                                                      \
    (void)printf("%s Time:%.24s File:%s Func:%s Line:%d\r\n", MU_ENUM_TO_STRING(LOG_LEVEL, log_level), ctime(&t), file, function, line);        \
    (void)printf(format MU_IFCOMMALOGIC(MU_COUNT_ARG(__VA_ARGS__)) __VA_ARGS__);                                                                \
    (void)printf("\r\n");                                                                                                                       \
}

#define LOG_SINK_CONSOLE_LOG_WITH_CONTEXT(log_level, log_context, file, function, line, format, ...)                                            \
{                                                                                                                                               \
    if (log_context != NULL)                                                                                                                    \
    {                                                                                                                                           \
        for (uint32_t the_i = 0; the_i < log_context->property_count; the_i++)                                                                  \
        {                                                                                                                                       \
            switch (log_context->properties[the_i].type)                                                                                        \
            {                                                                                                                                   \
            default:                                                                                                                            \
                break;                                                                                                                          \
            case LOG_PROPERTY_TYPE_ANSI_STRING:                                                                                                 \
                printf("%s=%s ", log_context->properties[0].name, (const char*)log_context->properties[the_i].value);                           \
                break;                                                                                                                          \
            }                                                                                                                                   \
        }                                                                                                                                       \
    }                                                                                                                                           \
    LOG_SINK_CONSOLE_LOG(log_level, file, function, line, format, __VA_ARGS__)                                                                  \
}

#endif /* LOG_SINK_CONSOLE_H */
