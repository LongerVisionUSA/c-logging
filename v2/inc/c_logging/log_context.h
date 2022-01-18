// Copyright (c) Microsoft. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for full license information.

#ifndef LOG_CONTEXT_H
#define LOG_CONTEXT_H

typedef struct LOG_CONTEXT_TAG
{
    int dummy;
} LOG_CONTEXT;

typedef struct LOG_CONTEXT_TAG* LOG_CONTEXT_HANDLE;

#define LOG_CONTEXT_DEFINE(log_context, ...) \
    LOG_CONTEXT log_context = { 0 };

#endif /* LOG_CONTEXT_H */
