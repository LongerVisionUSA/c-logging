// Copyright (c) Microsoft. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for full license information.

#ifndef LOG_CONTEXT_H
#define LOG_CONTEXT_H

#ifdef __cplusplus
#include <cstdint>
#include <cstdio>
#else
#include <stdint.h>
#include <stdio.h>
#endif

#include "macro_utils/macro_utils.h"

typedef struct LOG_CONTEXT_TAG
{
    char* context_string;
} LOG_CONTEXT;

typedef struct LOG_CONTEXT_TAG* LOG_CONTEXT_HANDLE;

LOG_CONTEXT_HANDLE log_context_create(LOG_CONTEXT_HANDLE parent_context, const char* context_string);
void log_context_destroy(LOG_CONTEXT_HANDLE log_context);

#define EXPAND_LOG_CONTEXT_FIELD(field_name, field_PRI, field_values) \
    chars_written = sprintf(pos, "%s=" field_PRI " ", field_name, field_values); \
    pos += (size_t)chars_written; \

#define STRINGIFY_LOG_CONTEXT_FIELD(field_desc) \
    MU_C2(EXPAND_, field_desc)

#define LOCAL_LOG_CONTEXT_DEFINE(log_context, parent_context, ...) \
    char MU_C2(log_string_, log_context)[LOG_MAX_MESSAGE_LENGTH]; \
    { \
        char* pos = MU_C2(log_string_, log_context); \
        int chars_written = 0; \
        MU_FOR_EACH_1(STRINGIFY_LOG_CONTEXT_FIELD, __VA_ARGS__) \
    } \
    LOG_CONTEXT log_context = { MU_C2(log_string_, log_context) };

#define EXPAND_GET_LENGTH_LOG_CONTEXT_FIELD(field_name, field_PRI, field_values) \
    chars_written = snprintf(NULL, 0, "%s=" field_PRI " ", field_name, field_values); \

#define GET_LOG_CONTEXT_FIELD_LENGTH(field_desc) \
    MU_C2(EXPAND_GET_LENGTH_, field_desc)

#define LOG_CONTEXT_CREATE(log_context_handle, parent_context, ...) \
    int MU_C2(chars_written_, log_context_handle); \
    { \
        int chars_written = 0; \
        MU_FOR_EACH_1(GET_LOG_CONTEXT_FIELD_LENGTH, __VA_ARGS__) \
        MU_C2(chars_written_, log_context_handle) = chars_written; \
    } \
    log_context_handle = malloc(sizeof(LOG_CONTEXT) + MU_C2(chars_written_, log_context_handle) + 1); \
    if (log_context_handle == NULL) \
    { \
        (void)printf("malloc(sizeof(LOG_CONTEXT) + %d + 1) failed", MU_C2(chars_written_, log_context_handle)); \
    } \
    else \
    { \
        log_context_handle->context_string = (void*)((LOG_CONTEXT*)(log_context_handle) + 1); \
        { \
            char* pos = log_context_handle->context_string; \
            int chars_written = 0; \
            MU_FOR_EACH_1(STRINGIFY_LOG_CONTEXT_FIELD, __VA_ARGS__) \
        } \
    } \

#define LOG_CONTEXT_DESTROY(log_context_handle) \
    free(log_context_handle);

#endif /* LOG_CONTEXT_H */
