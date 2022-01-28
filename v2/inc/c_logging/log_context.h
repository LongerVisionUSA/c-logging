// Copyright (c) Microsoft. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for full license information.

#ifndef LOG_CONTEXT_H
#define LOG_CONTEXT_H

#ifdef __cplusplus
#include <cstdint>
#else
#include <stdint.h>
#endif

#include "macro_utils/macro_utils.h"

#include "c_logging/log_property_type.h"

typedef struct LOG_PROPERTY_TAG
{
    LOG_PROPERTY_TYPE type;
    const char* name;
    void* value;
} LOG_PROPERTY;

typedef struct LOG_CONTEXT_TAG
{
    struct LOG_CONTEXT_TAG* parent_context;
    uint32_t property_count;
    LOG_PROPERTY properties[];
} LOG_CONTEXT;

typedef struct LOG_CONTEXT_TAG* LOG_CONTEXT_HANDLE;

LOG_CONTEXT_HANDLE log_context_create(LOG_CONTEXT_HANDLE parent_context, uint32_t property_count, LOG_PROPERTY* properties);
void log_context_destroy(LOG_CONTEXT_HANDLE log_context);

#endif /* LOG_CONTEXT_H */
