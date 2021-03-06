/** @file
 * Copyright (c) 2018, Arm Limited or its affiliates. All rights reserved.
 * SPDX-License-Identifier : Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *  http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
**/
#ifndef _TEST003_CLIENT_TESTS_H_
#define _TEST003_CLIENT_TESTS_H_

#ifdef NONSECURE_TEST_BUILD
#include "val.h"
#else
#include "val/common/val_client_defs.h"
#endif

extern val_api_t *val;
extern psa_api_t *psa;

extern client_test_t test_i003_client_tests_list[];

int32_t client_test_psa_set_rhandle(security_t);
int32_t client_test_call_read_and_skip(security_t);
int32_t client_test_call_and_write(security_t);
int32_t client_test_zero_length_invec(security_t);
int32_t client_test_zero_length_outvec(security_t);
int32_t client_test_overlapping_vectors(security_t);
#endif
