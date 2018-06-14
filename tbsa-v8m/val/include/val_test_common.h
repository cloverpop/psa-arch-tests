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

#ifndef _VAL_TEST_COMMON_H_
#define _VAL_TEST_COMMON_H_

#include "val_interfaces.h"

/* Macro's */
#define TBSA_BASE_BASE                  0
#define TBSA_0_STR			"\n-------------------- Base Tests             --------------------"
#define TBSA_TRUSTED_BOOT_BASE          1
#define TBSA_1_STR			"\n-------------------- Trusted Boot Tests     --------------------"
#define TBSA_CRYPTO_BASE                2
#define TBSA_2_STR			"\n-------------------- Crypto Tests           --------------------"
#define TBSA_DEBUG_BASE                 3
#define TBSA_3_STR			"\n-------------------- Debug Tests            --------------------"
#define TBSA_DRAM_BASE                  4
#define TBSA_4_STR			"\n-------------------- DRAM Tests             --------------------"
#define TBSA_EIP_BASE                   5
#define TBSA_5_STR			"\n-------------------- EIP Tests              --------------------"
#define TBSA_ENTROPY_SOURCE_BASE        6
#define TBSA_6_STR			"\n-------------------- Entropy Source Tests   --------------------"
#define TBSA_FUSES_BASE                 7
#define TBSA_7_STR			"\n-------------------- Fuses Tests            --------------------"
#define TBSA_INFRASTRUCTURE_BASE        8
#define TBSA_8_STR			"\n-------------------- Infrastructure Tests   --------------------"
#define TBSA_INTERRUPTS_BASE            9
#define TBSA_9_STR			"\n-------------------- Interrupts Tests       --------------------"
#define TBSA_SECURE_RAM_BASE            10
#define TBSA_10_STR			"\n-------------------- Secure RAM Tests       --------------------"
#define TBSA_PERIPHERALS_BASE           11
#define TBSA_11_STR			"\n-------------------- Peripherals Tests      --------------------"
#define TBSA_SAMPLE_BASE                12
#define TBSA_12_STR			"\n-------------------- Sample Tests           --------------------"
#define TBSA_TRUSTED_TIMERS_BASE        13
#define TBSA_13_STR			"\n-------------------- Trusted Timers Tests   --------------------"
#define TBSA_VERSION_COUNTERS_BASE      14
#define TBSA_14_STR			"\n-------------------- Version Counters Tests --------------------"
#define TBSA_VOLATALITY_BASE            15
#define TBSA_15_STR			"\n-------------------- Volatality Tests       --------------------"

#define TBSA_MAX_TEST_PER_COMP          20
#define TBSA_GET_COMP_NUM(test_id)      ((test_id - (test_id % TBSA_MAX_TEST_PER_COMP)) / TBSA_MAX_TEST_PER_COMP)
#define TBSA_GET_TEST_NUM(test_id)      (test_id % TBSA_MAX_TEST_PER_COMP)
#define CREATE_TEST_ID(comp,num)        ((comp*TBSA_MAX_TEST_PER_COMP) + num)
#define CREATE_TEST_TITLE(title)        #title"\n"
#define CREATE_REF_TAG(tag)             #tag"\n"

#define TBSA_TEST_PUBLISH(test_id, title, tag, entry, payload, exit) \
        const tbsa_test_info_t __attribute__((section(".tbsa_info"))) tbsa_test_info = {test_id, {title}, {tag}, {entry, payload, exit}}

/* typedef's */

/* prototype's */
void   entry_hook   (tbsa_val_api_t *val_api);
void   test_payload (tbsa_val_api_t *val_api);
void   exit_hook    (tbsa_val_api_t *val_api);

uint32_t __tbsa_test_bss_start__;
uint32_t __tbsa_test_bss_end__;
uint32_t __tbsa_test_data_start_src__;
uint32_t __tbsa_test_data_start__;
uint32_t __tbsa_test_data_end__;

#endif /* _VAL_TEST_COMMON_H_ */