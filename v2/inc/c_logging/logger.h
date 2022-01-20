// Copyright (c) Microsoft. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for full license information.

#ifndef C_LOGGING_H
#define C_LOGGING_H

#include "macro_utils/macro_utils.h"

#include "log_sink_etw.h"
#include "log_sink_console.h"

#define LOG_LEVEL_VALUES \
    LOG_LEVEL_CRITICAL, \
    LOG_LEVEL_ERROR, \
    LOG_LEVEL_WARNING, \
    LOG_LEVEL_INFO, \
    LOG_LEVEL_VERBOSE

MU_DEFINE_ENUM(LOG_LEVEL, LOG_LEVEL_VALUES);

#define LOG_CONTEXT_DEFINE(log_context, ...)

#define LOGGER_LOG(level, format, ...) \
    LOG_SINK_ETW_LOG(level, __FILE__, __FUNCTION__, __LINE__, format, __VA_ARGS__) \
    LOG_SINK_CONSOLE_LOG(level, __FILE__, __FUNCTION__, __LINE__, format, __VA_ARGS__)

#define LOGGER_LOG_WITH_CONTEXT(level, log_context, format, ...) \
    LOG_SINK_ETW_LOG(level, __FILE__, __FUNCTION__, __LINE__, format, __VA_ARGS__) \
    LOG_SINK_CONSOLE_LOG(level, __FILE__, __FUNCTION__, __LINE__, format, __VA_ARGS__)

#endif /* C_LOGGING_H */
