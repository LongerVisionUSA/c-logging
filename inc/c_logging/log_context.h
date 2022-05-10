// Copyright (c) Microsoft. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for full license information.

#ifndef LOG_CONTEXT_H
#define LOG_CONTEXT_H

#include "macro_utils/macro_utils.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

    typedef struct LOG_CONTEXT_TAG* LOG_CONTEXT_HANDLE;

    typedef struct LOG_CONTEXT_TAG
    {
        char* context_string;
    } LOG_CONTEXT;

#define EXPAND_STRINGIFY_LOG_CONTEXT_FIELD(field_name, field_PRI, ...) \
    chars_written = sprintf(pos, "%s=" field_PRI " ", field_name, __VA_ARGS__); \
    pos += (size_t)chars_written; \

#define STRINGIFY_LOG_CONTEXT_FIELD(field_desc) \
    MU_C2(EXPAND_STRINGIFY_, field_desc)

#define EXPAND_GET_LENGTH_LOG_CONTEXT_FIELD(field_name, field_PRI, ...) \
    chars_written_log_context_handle += snprintf(NULL, 0, "%s=" field_PRI " ", field_name, __VA_ARGS__); \

#define GET_LOG_CONTEXT_FIELD_LENGTH(field_desc) \
    MU_C2(EXPAND_GET_LENGTH_, field_desc)

#define LOG_CONTEXT_CREATE(log_context_handle, ...) \
    { \
        int chars_written_log_context_handle = 0; \
        MU_FOR_EACH_1(GET_LOG_CONTEXT_FIELD_LENGTH, __VA_ARGS__) \
        log_context_handle = malloc(sizeof(LOG_CONTEXT) + chars_written_log_context_handle + 1); \
        if (log_context_handle == NULL) \
        { \
            (void)printf("malloc(sizeof(LOG_CONTEXT) + %d + 1) failed", chars_written_log_context_handle); \
        } \
        else \
        { \
            log_context_handle->context_string = (void*)((LOG_CONTEXT*)(log_context_handle)+1); \
        { \
            char* pos = log_context_handle->context_string; \
            int chars_written = 0; \
            MU_FOR_EACH_1(STRINGIFY_LOG_CONTEXT_FIELD, __VA_ARGS__) \
        } \
        } \
    } \

#define LOG_CONTEXT_DESTROY(log_context_handle) \
    free(log_context_handle);

#define PRI_LOG_CONTEXT "s"
#define LOG_CONTEXT_VALUES(log_context_handle) (((log_context_handle) == NULL) ? "" : (log_context_handle)->context_string)

#ifdef __cplusplus
}   // extern "C"
#endif /* __cplusplus */

#endif /* LOG_CONTEXT_H */
