// Copyright (c) Microsoft. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for full license information.

#ifndef LOG_SINK_CONSOLE_H
#define LOG_SINK_CONSOLE_H

#define LOG_SINK_CONSOLE_LOG(level, file, func, line, format, ...) \
    { \
    time_t t = time(NULL); \
    (void)printf("Critical: Time:%.24s File:%s Func:%s Line:%d ", ctime(&t), file, func, line); \
    printf(format MU_IFCOMMALOGIC(MU_COUNT_ARG(__VA_ARGS__)) __VA_ARGS__); \
    printf("\r\n"); \
    }

#endif /* LOG_SINK_CONSOLE_H */
