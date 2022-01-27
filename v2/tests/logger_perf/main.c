// Copyright (c) Microsoft. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for full license information.

#include <string.h>
#include <stdio.h>
#include <inttypes.h>

#include "macro_utils/macro_utils.h"

#include "timer.h"

#include "c_logging/logger.h"
#include "c_logging/xlogging.h"

#define TEST_TIME 5000 // ms

#define PERF_TEST_LIST_VALUES \
    PERF_TEST_LOG_CRITICAL

MU_DEFINE_ENUM_WITHOUT_INVALID(PERF_TEST_LIST, PERF_TEST_LIST_VALUES);
MU_DEFINE_ENUM_STRINGS_WITHOUT_INVALID(PERF_TEST_LIST, PERF_TEST_LIST_VALUES);

typedef struct PERF_RESULT_TAG
{
    double time;
    uint64_t log_count;
} PERF_RESULT;

PERF_RESULT v1_results[MU_ENUM_VALUE_COUNT_WITHOUT_INVALID(PERF_TEST_LIST)];
PERF_RESULT v2_results[MU_ENUM_VALUE_COUNT_WITHOUT_INVALID(PERF_TEST_LIST)];
PERF_RESULT v2_results_context[MU_ENUM_VALUE_COUNT_WITHOUT_INVALID(PERF_TEST_LIST)];
PERF_RESULT v2_results_dynamic_context[MU_ENUM_VALUE_COUNT_WITHOUT_INVALID(PERF_TEST_LIST)];

/*not much in the way of testing, but "should not crash" */
int main(void)
{
    double start_time = timer_global_get_elapsed_us();
    uint64_t iterations = 0;

    /*LogCritical*/
    double current_time;
    while ((current_time = timer_global_get_elapsed_us()) - start_time < TEST_TIME * 1000)
    {
        uint32_t i;
        for (i = 0; i < 10000; i++)
        {
            logger_log(LOG_LEVEL_CRITICAL, "LogCritical: hello world!");
        }

        iterations += i;
    }

    v2_results[PERF_TEST_LOG_CRITICAL].log_count = iterations;
    v2_results[PERF_TEST_LOG_CRITICAL].time = current_time - start_time;

    // now have the test run with context
    start_time = timer_global_get_elapsed_us();
    iterations = 0;

    /*LogCritical (old way)*/
    current_time;
    while ((current_time = timer_global_get_elapsed_us()) - start_time < TEST_TIME * 1000)
    {
        uint32_t i;
        for (i = 0; i < 10000; i++)
        {
            const char* block_id = "pachoo";

            (void)block_id;

            LOG_CONTEXT_DEFINE(log_context,
                "block_id", block_id);

            logger_log_with_context(LOG_LEVEL_CRITICAL, log_context, "LogCritical: hello world!");
        }

        iterations += i;
    }

    v2_results_context[PERF_TEST_LOG_CRITICAL].log_count = iterations;
    v2_results_context[PERF_TEST_LOG_CRITICAL].time = current_time - start_time;

    // now have the test run with dynamically allocated context
    start_time = timer_global_get_elapsed_us();
    iterations = 0;

    /*LogCritical (old way)*/
    current_time;
    while ((current_time = timer_global_get_elapsed_us()) - start_time < TEST_TIME * 1000)
    {
        uint32_t i;
        for (i = 0; i < 10000; i++)
        {
            LOG_PROPERTY properties[] = { LOG_PROPERTY_TYPE_ANSI_STRING, "block_id", "pachoo" };
            LOG_CONTEXT_HANDLE log_context = log_context_create(NULL, 1, properties);

            logger_log_with_context(LOG_LEVEL_CRITICAL, log_context, "LogCritical: hello world!");

            log_context_destroy(log_context);
        }

        iterations += i;
    }

    v2_results_dynamic_context[PERF_TEST_LOG_CRITICAL].log_count = iterations;
    v2_results_dynamic_context[PERF_TEST_LOG_CRITICAL].time = current_time - start_time;

    // now have all the tests with the old logger

    start_time = timer_global_get_elapsed_us();
    iterations = 0;

    /*LogCritical (old way)*/
    current_time;
    while ((current_time = timer_global_get_elapsed_us()) - start_time < TEST_TIME * 1000)
    {
        uint32_t i;
        for (i = 0; i < 10000; i++)
        {
            LogCritical("LogCritical: hello world!");
        }

        iterations += i;
    }

    v1_results[PERF_TEST_LOG_CRITICAL].log_count = iterations;
    v1_results[PERF_TEST_LOG_CRITICAL].time = current_time - start_time;

    for (int i = 0; i < MU_ENUM_VALUE_COUNT_WITHOUT_INVALID(PERF_TEST_LIST); i++)
    {
        (void)printf("v1 %" PRI_MU_ENUM " %" PRIu64 " logs in %lf s (%" PRIu64 " us), %lf logs/us\r\n", MU_ENUM_VALUE(PERF_TEST_LIST, i), v1_results[i].log_count, v1_results[i].time / 1000000, (uint64_t)v1_results[i].time, (double)v1_results[i].log_count / (v1_results[i].time / 1000000));
        (void)printf("v2 %" PRI_MU_ENUM " %" PRIu64 " logs in %lf s (%" PRIu64 " us), %lf logs/us\r\n", MU_ENUM_VALUE(PERF_TEST_LIST, i), v2_results[i].log_count, v2_results[i].time / 1000000, (uint64_t)v2_results[i].time, (double)v2_results[i].log_count / (v2_results[i].time / 1000000));
        (void)printf("v2 with context %" PRI_MU_ENUM " %" PRIu64 " logs in %lf s (%" PRIu64 " us), %lf logs/us\r\n", MU_ENUM_VALUE(PERF_TEST_LIST, i), v2_results_context[i].log_count, v2_results_context[i].time / 1000000, (uint64_t)v2_results_context[i].time, (double)v2_results_context[i].log_count / (v2_results_context[i].time / 1000000));
        (void)printf("v2 with dynamic allocated context %" PRI_MU_ENUM " %" PRIu64 " logs in %lf s (%" PRIu64 " us), %lf logs/us\r\n", MU_ENUM_VALUE(PERF_TEST_LIST, i), v2_results_dynamic_context[i].log_count, v2_results_dynamic_context[i].time / 1000000, (uint64_t)v2_results_dynamic_context[i].time, (double)v2_results_dynamic_context[i].log_count / (v2_results_dynamic_context[i].time / 1000000));
    }
}
