// Copyright (c) Microsoft. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for full license information.

#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#include "macro_utils/macro_utils.h"

#include "c_logging/logger.h"

#define LOG_SIZE_REGULAR 1024

/*not much in the way of testing, but "should not crash" */
int main(void)
{
    char really_big_string_fits[LOG_SIZE_REGULAR / 2]; /*expecting the string on the screen, even when it is big*/
    (void)memset(really_big_string_fits, '3', sizeof(really_big_string_fits));
    really_big_string_fits[sizeof(really_big_string_fits) - 1] = '\0';

    char really_big_string_doesnt_fit[LOG_SIZE_REGULAR]; /*if the size of this array is greater than LOG_SIZE_REGULAR than it will not get printed as all memory is statically allocated and cannot grow*/
    (void)memset(really_big_string_doesnt_fit, 'M', sizeof(really_big_string_doesnt_fit));
    really_big_string_doesnt_fit[sizeof(really_big_string_doesnt_fit) - 1] = '\0';

    /*LogCritical*/
    logger_log(LOG_LEVEL_CRITICAL, "LogCritical: hello world!");
    logger_log(LOG_LEVEL_CRITICAL, "LogCritical: a more complicated hello with int=%d.", 42);
    logger_log(LOG_LEVEL_CRITICAL, "LogCritical: the most complicated hello with int=%d and a really big string that fits =%s.", 42, really_big_string_fits);
    logger_log(LOG_LEVEL_CRITICAL, "LogCritical: the most complicated hello with int=%d and a really big string that does not fit=%s.", 42, really_big_string_doesnt_fit);
    logger_log(LOG_LEVEL_CRITICAL, "LogCritical: does PRI_BOOL work? %" PRI_BOOL "", MU_BOOL_VALUE(true) /*answer is yes, it works*/);
    logger_log(LOG_LEVEL_CRITICAL, "LogCritical: does PRI_BOOL work with amazingly out of bounds value? %" PRI_BOOL "", MU_BOOL_VALUE(42));
    logger_log(LOG_LEVEL_CRITICAL, "LogCritical: does PRI_BOOL works with false? %" PRI_BOOL "", MU_BOOL_VALUE(false));

    /*LogError*/
    logger_log(LOG_LEVEL_ERROR, "LogError: hello world!");
    logger_log(LOG_LEVEL_ERROR, "LogError: a more complicated hello with int=%d.", 42);
    logger_log(LOG_LEVEL_ERROR, "LogError: the most complicated hello with int=%d and a really big string that fits =%s.", 42, really_big_string_fits);
    logger_log(LOG_LEVEL_ERROR, "LogError: the most complicated hello with int=%d and a really big string that does not fit=%s.", 42, really_big_string_doesnt_fit);
    logger_log(LOG_LEVEL_ERROR, "LogCritical: does PRI_BOOL work? %" PRI_BOOL "", MU_BOOL_VALUE(true) /*answer is yes, it works*/);
    logger_log(LOG_LEVEL_ERROR, "LogCritical: does PRI_BOOL work with amazingly out of bounds value? %" PRI_BOOL "", MU_BOOL_VALUE(42));
    logger_log(LOG_LEVEL_ERROR, "LogCritical: does PRI_BOOL works with false? %" PRI_BOOL "", MU_BOOL_VALUE(false));

//#ifdef _MSC_VER /*linux doesn't have LogLastError*/
//    /*LogLastError*/
//    LogLastError("LogLastError: hello world!");
//    LogLastError("LogLastError: a more complicated hello with int=%d.", 42);
//    LogLastError("LogLastError: the most complicated hello with int=%d and a really big string that fits =%s.", 42, really_big_string_fits);
//    LogLastError("LogLastError: the most complicated hello with int=%d and a really big string that does not fit=%s.", 42, really_big_string_doesnt_fit);
//#endif
    /*LogWarning*/
    logger_log(LOG_LEVEL_WARNING, "LogWarning: hello world!");
    logger_log(LOG_LEVEL_WARNING, "LogWarning: a more complicated hello with int=%d.", 42);
    logger_log(LOG_LEVEL_WARNING, "LogWarning: the most complicated hello with int=%d and a really big string that fits =%s.", 42, really_big_string_fits);
    logger_log(LOG_LEVEL_WARNING, "LogWarning: the most complicated hello with int=%d and a really big string that does not fit=%s.", 42, really_big_string_doesnt_fit);
    logger_log(LOG_LEVEL_WARNING, "LogCritical: does PRI_BOOL work? %" PRI_BOOL "", MU_BOOL_VALUE(true) /*answer is yes, it works*/);
    logger_log(LOG_LEVEL_WARNING, "LogCritical: does PRI_BOOL work with amazingly out of bounds value? %" PRI_BOOL "", MU_BOOL_VALUE(42));
    logger_log(LOG_LEVEL_WARNING, "LogCritical: does PRI_BOOL works with false? %" PRI_BOOL "", MU_BOOL_VALUE(false));

    /*LogInfo*/
    logger_log(LOG_LEVEL_INFO, "LogInfo: hello world!");
    logger_log(LOG_LEVEL_INFO, "LogInfo: a more complicated hello with int=%d.", 42);
    logger_log(LOG_LEVEL_INFO, "LogInfo: the most complicated hello with int=%d and a really big string that fits=%s.", 42, really_big_string_fits);
    logger_log(LOG_LEVEL_INFO, "LogInfo: the most complicated hello with int=%d and a really big string that does not fit=%s.", 42, really_big_string_doesnt_fit);
    logger_log(LOG_LEVEL_INFO, "LogCritical: does PRI_BOOL work? %" PRI_BOOL "", MU_BOOL_VALUE(true) /*answer is yes, it works*/);
    logger_log(LOG_LEVEL_INFO, "LogCritical: does PRI_BOOL work with amazingly out of bounds value? %" PRI_BOOL "", MU_BOOL_VALUE(42));
    logger_log(LOG_LEVEL_INFO, "LogCritical: does PRI_BOOL works with false? %" PRI_BOOL "", MU_BOOL_VALUE(false));

    /*LogVerbose*/
    logger_log(LOG_LEVEL_VERBOSE, "LogVerbose: hello world!");
    logger_log(LOG_LEVEL_VERBOSE, "LogVerbose: a more complicated hello with int=%d.", 42);
    logger_log(LOG_LEVEL_VERBOSE, "LogVerbose: the most complicated hello with int=%d and a really big string that fits =%s.", 42, really_big_string_fits);
    logger_log(LOG_LEVEL_VERBOSE, "LogVerbose: the most complicated hello with int=%d and a really big string that does not fit=%s.", 42, really_big_string_doesnt_fit);
    logger_log(LOG_LEVEL_VERBOSE, "LogCritical: does PRI_BOOL work? %" PRI_BOOL "", MU_BOOL_VALUE(true) /*answer is yes, it works*/);
    logger_log(LOG_LEVEL_VERBOSE, "LogCritical: does PRI_BOOL work with amazingly out of bounds value? %" PRI_BOOL "", MU_BOOL_VALUE(42));
    logger_log(LOG_LEVEL_VERBOSE, "LogCritical: does PRI_BOOL works with false? %" PRI_BOOL "", MU_BOOL_VALUE(false));

    char* prop_value = malloc(2);
    (void)strcpy(prop_value, "a");

    LOG_PROPERTY log_properties[] = { LOG_PROPERTY_TYPE_ANSI_STRING, "property_name", (void*)prop_value };
    LOG_CONTEXT_HANDLE allocated_log_context = log_context_create(NULL, MU_COUNT_ARRAY_ITEMS(log_properties), log_properties);

    free(prop_value);

    logger_log_with_context(LOG_LEVEL_ERROR, allocated_log_context, "some_error with context");

    log_context_destroy(allocated_log_context);
}
