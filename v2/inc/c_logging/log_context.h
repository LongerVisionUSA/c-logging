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

#define LOG_PROPERTY_TYPE_VALUES \
    LOG_PROPERTY_TYPE_INT32, \
    LOG_PROPERTY_TYPE_ANSI_STRING

MU_DEFINE_ENUM(LOG_PROPERTY_TYPE, LOG_PROPERTY_TYPE_VALUES);

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

#define LOG_PASTE_PROPERTIES(name, value) \
    { LOG_PROPERTY_TYPE_ANSI_STRING, name, (void*)value }

#define LOG_CONTEXT_DEFINE(log_context, ...) \
    LOG_CONTEXT MU_C2(backing_struct_, log_context) = { NULL, MU_DIV2(MU_COUNT_ARG(__VA_ARGS__)), { MU_FOR_EACH_2(LOG_PASTE_PROPERTIES, __VA_ARGS__) } }; \
    LOG_CONTEXT_HANDLE log_context = &MU_C2(backing_struct_, log_context);

#define LOG_CONTEXT_DEFINE_WITH_PARENT(log_context, parent_context, ...) \
    LOG_CONTEXT MU_C2(backing_struct_, log_context) = { parent_context, MU_DIV2(MU_COUNT_ARG(__VA_ARGS__)), { MU_FOR_EACH_2(LOG_PASTE_PROPERTIES, __VA_ARGS__) } }; \
    LOG_CONTEXT_HANDLE log_context = &MU_C2(backing_struct_, log_context);

LOG_CONTEXT_HANDLE log_context_create(LOG_CONTEXT_HANDLE source_context, uint32_t property_count, LOG_PROPERTY* properties);
void log_context_destroy(LOG_CONTEXT_HANDLE log_context);

#endif /* LOG_CONTEXT_H */
