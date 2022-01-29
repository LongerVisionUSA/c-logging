// Copyright (c) Microsoft. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for full license information.

#include <stdlib.h>

#include "c_logging/log_context.h"

LOG_CONTEXT_HANDLE log_context_create(LOG_CONTEXT_HANDLE parent_context, const char* context_string)
{
    LOG_CONTEXT_HANDLE result = NULL;

    (void)parent_context;
    (void)context_string;

    return result;
}

void log_context_destroy(LOG_CONTEXT_HANDLE log_context)
{
    free(log_context);
}
