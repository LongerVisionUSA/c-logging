// Copyright (c) Microsoft. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for full license information.

#include <stdlib.h>

#include "c_logging/log_context.h"

LOG_CONTEXT_HANDLE log_context_create(LOG_CONTEXT_HANDLE source_context, uint32_t property_count, LOG_PROPERTY* properties)
{
    LOG_CONTEXT_HANDLE result;

    (void)source_context;

    size_t needed_bytes = (property_count * sizeof(LOG_PROPERTY)) + sizeof(LOG_CONTEXT);
    if ((needed_bytes - sizeof(LOG_CONTEXT)) / sizeof(LOG_PROPERTY) != property_count)
    {
        result = NULL;
    }
    else
    {
        result = malloc(needed_bytes);
        if (result != NULL)
        {
            result->property_count = property_count;
            (void)memcpy(result->properties, properties, property_count * sizeof(LOG_PROPERTY));
        }
    }

    return result;
}

void log_context_destroy(LOG_CONTEXT_HANDLE log_context)
{
    free(log_context);
}
