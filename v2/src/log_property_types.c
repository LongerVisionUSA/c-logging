// Copyright (c) Microsoft. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for full license information.

#include <stdlib.h>
#include <string.h>

#include "c_logging/log_property_type.h"
#include "c_logging/log_property_types.h"

static void log_property_type_ansi_string_assign(void* dest, void* src)
{
    size_t str_len = strlen(src);
    *(char**)dest = malloc(str_len + 1);
    (void)strcpy(*(char**)dest, src);
}

static void log_property_type_ansi_string_free(void* value)
{
    free(value);
}

static void log_property_type_ansi_string_to_string(void* value, char* str, size_t buffer_size)
{
    (void)buffer_size;
    strcpy(str, value);
}

const LOG_PROPERTY_TYPE LOG_PROPERTY_TYPE_ANSI_STRING = 
{
    log_property_type_ansi_string_assign,
    log_property_type_ansi_string_free,
    log_property_type_ansi_string_to_string
};

