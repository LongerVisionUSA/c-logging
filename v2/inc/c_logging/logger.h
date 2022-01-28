// Copyright (c) Microsoft. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for full license information.

#ifndef C_LOGGING_H
#define C_LOGGING_H

#include "macro_utils/macro_utils.h"

#include "c_logging/log_context.h"
#include "c_logging/log_property_types.h"

#define LOG_LEVEL_VALUES \
    LOG_LEVEL_CRITICAL, \
    LOG_LEVEL_ERROR, \
    LOG_LEVEL_WARNING, \
    LOG_LEVEL_INFO, \
    LOG_LEVEL_VERBOSE

MU_DEFINE_ENUM(LOG_LEVEL, LOG_LEVEL_VALUES);

#define LOG_MAX_MESSAGE_LENGTH 4096 /*in bytes - a message is not expected to exceed this size in bytes, if it does, only LOG_MAX_MESSAGE_LENGTH characters are retained*/

void logger_log(LOG_LEVEL log_level, const char* format, ...);
void logger_log_with_context(LOG_LEVEL log_level, LOG_CONTEXT_HANDLE log_context, const char* format, ...);

#endif /* C_LOGGING_H */
