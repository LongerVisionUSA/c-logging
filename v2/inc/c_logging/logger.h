// Copyright (c) Microsoft. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for full license information.

#ifndef C_LOGGING_H
#define C_LOGGING_H

#include "macro_utils/macro_utils.h"

#include "log_sink_etw.h"

#define LOGGER_LOG(format, ...) \
    LOG_SINK_ETW_LOG(format, __FILE__, __FUNCTION__, __LINE__, __VA_ARGS__)

#endif /* C_LOGGING_H */
