/*
 * Copyright (c) 2018 IOTA Stiftung
 * https://github.com/iotaledger/entangled
 *
 * Refer to the LICENSE file for licensing information
 */

#ifndef __CIRI_NODE_H__
#define __CIRI_NODE_H__

#include "common/errors.h"
#include "gossip/components/broadcaster.h"
#include "gossip/components/processor.h"
#include "gossip/components/receiver.h"
#include "gossip/components/requester.h"
#include "gossip/components/responder.h"

#ifdef __cplusplus
extern "C" {
#endif

// Forward declarations
typedef struct core_s core_t;
typedef struct concurrent_list_neighbor_t_s neighbors_list_t;

typedef struct node_s {
  bool running;
  core_t* core;
  broadcaster_state_t broadcaster;
  processor_state_t processor;
  receiver_state_t receiver;
  responder_state_t responder;
  requester_state_t* requester;
  neighbors_list_t* neighbors;
} node_t;

/**
 * Initializes a node
 *
 * @param node The node
 * @param core A core
 * @param tangle A tangle
 * @param transaction_requester A transaction requester
 *
 * @return a status code
 */
retcode_t node_init(node_t* const node, core_t* const core,
                    tangle_t* const tangle,
                    requester_state_t* const transaction_requester);

/**
 * Starts a node
 *
 * @param node The node
 *
 * @return a status code
 */
retcode_t node_start(node_t* const node);

/**
 * Stops a node
 *
 * @param node The node
 *
 * @return a status code
 */
retcode_t node_stop(node_t* const node);

/**
 * Destroys a node
 *
 * @param node The node
 *
 * @return a status code
 */
retcode_t node_destroy(node_t* const node);

#ifdef __cplusplus
}
#endif

#endif  // __CIRI_NODE_H__
