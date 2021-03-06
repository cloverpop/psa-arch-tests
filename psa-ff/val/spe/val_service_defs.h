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

#ifndef _VAL_PSA_SERVICE_H_
#define _VAL_PSA_SERVICE_H_

/***************** PSA Secure Function API *****************/

/* Note - This header file containts the declaration of PSA defined secure partition service API
   elements. Ideally, These elements must be defined in a header file <psa_service.h> by SPM
   implemented library and provided to clients operation in NSPE and SPE as per the specification.
   If this is available in the platform, the elements declared as part of this
   file can be overwritten by passing  --include <path_to_psa_service_h> to setup.sh script.
  */

#if 1
/* <psa_service.h>: Secure Partition API elements. Only accessible to Secure Partition */
#include "psa_service.h"

#else
#include "val/common/val.h"

#define PSA_POLL            0x00000000U
#define PSA_BLOCK           0x80000000U
#define PSA_DOORBELL        0x00000008U
#define PSA_IPC_CONNECT     1
#define PSA_IPC_CALL        2
#define PSA_IPC_DISCONNECT  3
#define PSA_MAX_IOVEC       4
#define PSA_ERR_NOMSG       (INT32_MIN + 3)

typedef uint32_t psa_signal_t;
typedef struct psa_msg_t psa_msg_t;

typedef struct psa_msg_t {
    uint32_t type;
    psa_handle_t handle;
    int32_t client_id;
    void *rhandle;
    size_t in_size[PSA_MAX_IOVEC];
    size_t out_size[PSA_MAX_IOVEC];
} psa_msg_t;


/* The implementation for following PSA service APIs should come from SPM */
psa_signal_t psa_wait_any(uint32_t timeout);
psa_signal_t psa_wait_interrupt(psa_signal_t signal_mask, uint32_t timeout);
void psa_set_rhandle(psa_handle_t msg_handle, void *rhandle);
psa_status_t psa_get(psa_signal_t signal, psa_msg_t *msg);
size_t psa_read(psa_handle_t msg_handle, uint32_t invec_idx,
                    void *buffer, size_t num_bytes);
size_t psa_skip(psa_handle_t msg_handle, uint32_t invec_idx,
                    size_t num_bytes);
void psa_write(psa_handle_t msg_handle, uint32_t outvec_idx,
                   const void *buffer, size_t num_bytes);
void psa_reply(psa_handle_t msg_handle, psa_status_t status);
void psa_notify(int32_t partition_id);
void psa_clear(psa_signal_t doorbell_signal);
void psa_eoi(psa_signal_t irq_signal);
#endif /* #if 1 */

/* struct of function pointers to uniqify  nspe and spe client interface for test */
typedef struct {
    uint32_t         (*framework_version)     (void);
    uint32_t         (*version)               (uint32_t sid);
    psa_handle_t     (*connect)               (uint32_t sid, uint32_t minor_version);
    psa_status_t     (*call)                  (psa_handle_t handle,
                                              const psa_invec *in_vec,
                                              size_t in_len,
                                              psa_outvec *out_vec,
                                              size_t out_len
                                              );
    psa_status_t     (*close)                 (psa_handle_t handle);
} psa_api_t;

typedef struct {
  val_status_t (*print)                    (print_verbosity_t verbosity,
                                            char *string, uint32_t data);
  val_status_t (*err_check_set)            (uint32_t checkpoint, val_status_t status);
  val_status_t (*execute_secure_test_func) (psa_handle_t *handle, test_info_t test_info,
                                            uint32_t sid);
  val_status_t (*get_secure_test_result)   (psa_handle_t *handle);
  val_status_t (*ipc_connect)              (uint32_t sid, uint32_t minor_version,
                                            psa_handle_t *handle );
  val_status_t (*ipc_call)                 (psa_handle_t handle, psa_invec *in_vec,
                                            size_t in_len,  psa_outvec *out_vec, size_t out_len);
  void         (*ipc_close)                (psa_handle_t handle);
  val_status_t (*set_boot_flag)            (boot_state_t state);
} val_api_t;
#endif
