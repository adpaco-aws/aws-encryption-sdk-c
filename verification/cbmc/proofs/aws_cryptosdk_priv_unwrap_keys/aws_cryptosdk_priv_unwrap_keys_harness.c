/*
 * Copyright 2020 Amazon.com, Inc. or its affiliates. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License"). You may not
 * use
 * this file except in compliance with the License. A copy of the License is
 * located at
 *
 *     http://aws.amazon.com/apache2.0/
 *
 * or in the "license" file accompanying this file. This file is distributed on
 * an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express
 * or
 * implied. See the License for the specific language governing permissions and
 * limitations under the License.
 */

// #include <aws/cryptosdk/private/session_decrypt.h>
#include <aws/cryptosdk/private/session.h>
#include <make_common_data_structures.h>

void aws_cryptosdk_priv_unwrap_keys_harness() {
    /* Nondet input */
    struct aws_cryptosdk_session *session =
        session_setup(MAX_TABLE_SIZE, MAX_TRACE_LIST_ITEMS, MAX_EDK_LIST_ITEMS, MAX_BUFFER_SIZE, MAX_STRING_LEN);
    /* Assumptions */
    //__CPROVER_assume(session->header.edk_list.item_size == sizeof(struct aws_cryptosdk_edk));

    // __CPROVER_assume(aws_cryptosdk_commitment_policy_is_valid(session->commitment_policy));

    /* Save current state of the data structures */
    // struct aws_byte_buf *old_message_id = &session->header.message_id;
    // struct store_byte_from_buffer old_byte_from_message_id;
    // save_byte_from_array(session->header.message_id.buffer, session->header.message_id.len, &old_byte_from_message_id);

    // struct aws_byte_buf *old_alg_suite_data = &session->header.alg_suite_data;
    // struct store_byte_from_buffer old_byte_from_alg_suite_data;
    // save_byte_from_array(
    //     session->header.alg_suite_data.buffer, session->header.alg_suite_data.len, &old_byte_from_alg_suite_data);

    // struct aws_byte_buf *old_unencrypted_data_key = &materials->unencrypted_data_key;
    // struct store_byte_from_buffer old_byte_from_unencrypted_data_key;
    // save_byte_from_array(
    //     materials->unencrypted_data_key.buffer,
    //     materials->unencrypted_data_key.len,
    //     &old_byte_from_unencrypted_data_key);

    /* Operation under verification */
    aws_cryptosdk_priv_unwrap_keys(session);

    /* Postconditions */
    assert(aws_cryptosdk_session_is_valid(session));
}
