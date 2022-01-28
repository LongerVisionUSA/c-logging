// Copyright (c) Microsoft. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for full license information.

#ifndef LOG_PROPERTY_TYPE_H
#define LOG_PROPERTY_TYPE_H

typedef void (*LOG_PROPERTY_ASSIGN_FUNC)(void* dest, void* src);
typedef void (*LOG_PROPERTY_FREE_FUNC)(void* arg);
typedef void (*LOG_PROPERTY_TO_STRING_FUNC)(void* arg, char* str, size_t buffer_size);

typedef struct LOG_PROPERTY_TYPE_TAG
{
    LOG_PROPERTY_ASSIGN_FUNC assign_func;
    LOG_PROPERTY_FREE_FUNC free_func;
    LOG_PROPERTY_TO_STRING_FUNC to_string_func;
} LOG_PROPERTY_TYPE;

#endif /* LOG_PROPERTY_TYPE_H */
