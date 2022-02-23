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
    logger_log(LOG_LEVEL_CRITICAL, NULL, "LogCritical: hello world!");
    logger_log(LOG_LEVEL_CRITICAL, NULL, "LogCritical: a more complicated hello with int=%d.", 42);
    logger_log(LOG_LEVEL_CRITICAL, NULL, "LogCritical: the most complicated hello with int=%d and a really big string that fits =%s.", 42, really_big_string_fits);
    logger_log(LOG_LEVEL_CRITICAL, NULL, "LogCritical: the most complicated hello with int=%d and a really big string that does not fit=%s.", 42, really_big_string_doesnt_fit);
    logger_log(LOG_LEVEL_CRITICAL, NULL, "LogCritical: does PRI_BOOL work? %" PRI_BOOL "", MU_BOOL_VALUE(true) /*answer is yes, it works*/);
    logger_log(LOG_LEVEL_CRITICAL, NULL, "LogCritical: does PRI_BOOL work with amazingly out of bounds value? %" PRI_BOOL "", MU_BOOL_VALUE(42));
    logger_log(LOG_LEVEL_CRITICAL, NULL, "LogCritical: does PRI_BOOL works with false? %" PRI_BOOL "", MU_BOOL_VALUE(false));

    /*LogError*/
    logger_log(LOG_LEVEL_ERROR, NULL, "LogError: hello world!");
    logger_log(LOG_LEVEL_ERROR, NULL, "LogError: a more complicated hello with int=%d.", 42);
    logger_log(LOG_LEVEL_ERROR, NULL, "LogError: the most complicated hello with int=%d and a really big string that fits =%s.", 42, really_big_string_fits);
    logger_log(LOG_LEVEL_ERROR, NULL, "LogError: the most complicated hello with int=%d and a really big string that does not fit=%s.", 42, really_big_string_doesnt_fit);
    logger_log(LOG_LEVEL_ERROR, NULL, "LogCritical: does PRI_BOOL work? %" PRI_BOOL "", MU_BOOL_VALUE(true) /*answer is yes, it works*/);
    logger_log(LOG_LEVEL_ERROR, NULL, "LogCritical: does PRI_BOOL work with amazingly out of bounds value? %" PRI_BOOL "", MU_BOOL_VALUE(42));
    logger_log(LOG_LEVEL_ERROR, NULL, "LogCritical: does PRI_BOOL works with false? %" PRI_BOOL "", MU_BOOL_VALUE(false));

//#ifdef _MSC_VER /*linux doesn't have LogLastError*/
//    /*LogLastError*/
//    LogLastError("LogLastError: hello world!");
//    LogLastError("LogLastError: a more complicated hello with int=%d.", 42);
//    LogLastError("LogLastError: the most complicated hello with int=%d and a really big string that fits =%s.", 42, really_big_string_fits);
//    LogLastError("LogLastError: the most complicated hello with int=%d and a really big string that does not fit=%s.", 42, really_big_string_doesnt_fit);
//#endif
    /*LogWarning*/
    logger_log(LOG_LEVEL_WARNING, NULL, "LogWarning: hello world!");
    logger_log(LOG_LEVEL_WARNING, NULL, "LogWarning: a more complicated hello with int=%d.", 42);
    logger_log(LOG_LEVEL_WARNING, NULL, "LogWarning: the most complicated hello with int=%d and a really big string that fits =%s.", 42, really_big_string_fits);
    logger_log(LOG_LEVEL_WARNING, NULL, "LogWarning: the most complicated hello with int=%d and a really big string that does not fit=%s.", 42, really_big_string_doesnt_fit);
    logger_log(LOG_LEVEL_WARNING, NULL, "LogCritical: does PRI_BOOL work? %" PRI_BOOL "", MU_BOOL_VALUE(true) /*answer is yes, it works*/);
    logger_log(LOG_LEVEL_WARNING, NULL, "LogCritical: does PRI_BOOL work with amazingly out of bounds value? %" PRI_BOOL "", MU_BOOL_VALUE(42));
    logger_log(LOG_LEVEL_WARNING, NULL, "LogCritical: does PRI_BOOL works with false? %" PRI_BOOL "", MU_BOOL_VALUE(false));

    /*LogInfo*/
    logger_log(LOG_LEVEL_INFO, NULL, "LogInfo: hello world!");
    logger_log(LOG_LEVEL_INFO, NULL, "LogInfo: a more complicated hello with int=%d.", 42);
    logger_log(LOG_LEVEL_INFO, NULL, "LogInfo: the most complicated hello with int=%d and a really big string that fits=%s.", 42, really_big_string_fits);
    logger_log(LOG_LEVEL_INFO, NULL, "LogInfo: the most complicated hello with int=%d and a really big string that does not fit=%s.", 42, really_big_string_doesnt_fit);
    logger_log(LOG_LEVEL_INFO, NULL, "LogCritical: does PRI_BOOL work? %" PRI_BOOL "", MU_BOOL_VALUE(true) /*answer is yes, it works*/);
    logger_log(LOG_LEVEL_INFO, NULL, "LogCritical: does PRI_BOOL work with amazingly out of bounds value? %" PRI_BOOL "", MU_BOOL_VALUE(42));
    logger_log(LOG_LEVEL_INFO, NULL, "LogCritical: does PRI_BOOL works with false? %" PRI_BOOL "", MU_BOOL_VALUE(false));

    /*LogVerbose*/
    logger_log(LOG_LEVEL_VERBOSE, NULL, "LogVerbose: hello world!");
    logger_log(LOG_LEVEL_VERBOSE, NULL, "LogVerbose: a more complicated hello with int=%d.", 42);
    logger_log(LOG_LEVEL_VERBOSE, NULL, "LogVerbose: the most complicated hello with int=%d and a really big string that fits =%s.", 42, really_big_string_fits);
    logger_log(LOG_LEVEL_VERBOSE, NULL, "LogVerbose: the most complicated hello with int=%d and a really big string that does not fit=%s.", 42, really_big_string_doesnt_fit);
    logger_log(LOG_LEVEL_VERBOSE, NULL, "LogCritical: does PRI_BOOL work? %" PRI_BOOL "", MU_BOOL_VALUE(true) /*answer is yes, it works*/);
    logger_log(LOG_LEVEL_VERBOSE, NULL, "LogCritical: does PRI_BOOL work with amazingly out of bounds value? %" PRI_BOOL "", MU_BOOL_VALUE(42));
    logger_log(LOG_LEVEL_VERBOSE, NULL, "LogCritical: does PRI_BOOL works with false? %" PRI_BOOL "", MU_BOOL_VALUE(false));

    char* prop_value = malloc(2);
    (void)strcpy(prop_value, "a");

    // local stack context
    LOCAL_LOG_CONTEXT_DEFINE(log_context, NULL, LOG_CONTEXT_FIELD("property_name", "%s", MU_P_OR_NULL(prop_value)));

    logger_log(LOG_LEVEL_ERROR, &log_context, "some_error with context");

    // allocate a context dynamically
    LOG_CONTEXT_HANDLE dynamically_allocated_log_context;
    LOG_CONTEXT_CREATE(dynamically_allocated_log_context, NULL, LOG_CONTEXT_FIELD("property_name", "%s", MU_P_OR_NULL(prop_value)));

    logger_log(LOG_LEVEL_ERROR, dynamically_allocated_log_context, "some_error with context");

    LOG_CONTEXT_DESTROY(dynamically_allocated_log_context);

    free(prop_value);

    // chained dynamically allocated context

    LOG_CONTEXT_HANDLE context_1;
    LOG_CONTEXT_CREATE(context_1, NULL, LOG_CONTEXT_FIELD("name", "%s", "haga"));

    LOG_CONTEXT_HANDLE context_2;
    LOG_CONTEXT_CREATE(context_2, context_1, LOG_CONTEXT_FIELD("last name", "%s", "uaga"), LOG_CONTEXT_FIELD("age", "%d", 42));

    logger_log(LOG_LEVEL_VERBOSE, context_1, "log context 1 data");
    logger_log(LOG_LEVEL_VERBOSE, context_2, "log context 2 data");

    LOG_CONTEXT_DESTROY(context_1);


    LOG_CONTEXT_DESTROY(context_2);
}
