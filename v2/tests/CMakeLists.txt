#Copyright (c) Microsoft. All rights reserved.
#Licensed under the MIT license. See LICENSE file in the project root for full license information.

#unit tests
if(${run_unittests})
endif()

if(${run_int_tests})
   add_subdirectory(logger_int)
endif()

if(${run_perf_tests})
   add_subdirectory(logger_perf)
endif()
