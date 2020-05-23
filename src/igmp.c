/*
 * Copyright 2019 Broadcom.  The term “Broadcom” refers to Broadcom Inc. and/or
 * its subsidiaries.

 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#include "l2mcd_data_struct.h"
#include "l2mcd_portdb.h"
#include "l2mcd_mld_port.h"
#include "l2mcd_mcast_co.h"
#include "l2mcd_mld_utils.h"

extern MCGRP_GLOBAL_CLASS    gMld, *pgMld;
extern MCGRP_GLOBAL_CLASS    gIgmp, *pgIgmp;
extern MCAST_GLOBAL_CLASS    gMulticast, *pgMulticast;
extern MCGRP_CLASS           Mld0, *pMld0;
extern MCGRP_CLASS           Igmp0, *pIgmp0;

extern L2MCD_AVL_TREE *mld_portdb_tree;
extern void mld_clear_mask(PORT_MASK *mask);
extern void mld_copy_mask(PORT_MASK *target, PORT_MASK *source);
extern MCGRP_CLASS          mld;
extern struct cli *gcli;

extern void mcgrp_vport_start_querier_process(MCGRP_CLASS * mcgrp, MCGRP_L3IF * mcgrp_vport);


/* Max bit/byte length of IPv6 address. */
#define IPV6_MAX_BYTELEN     16
#define IPV6_MAX_BITLEN      128
#define IPV6_ADDR_CMP(D,S)   memcmp ((D), (S), IPV6_MAX_BYTELEN)
#define IPV6_ADDR_SAME(D,S)  (memcmp ((D), (S), IPV6_MAX_BYTELEN) == 0)
#define IPV6_ADDR_COPY(D,S)  memcpy ((D), (S), IPV6_MAX_BYTELEN)
#define PRINT_SEC_OR_MS ((mcgrp_vport->LMQ_100ms_enabled == TRUE) ? "MilliSeconds" : "Seconds") 

extern MCAST_GLOBAL_CLASS			gMulticast; //, gMulticast6,*pgMulticast6;

// Forward declarations
UINT32 config_version_less_than_3_4();

unsigned short l3_get_port_from_bd_id(unsigned int bd_id)
{
    return (0);
}

int l3_get_port_from_ifindex(int ifindex)
{
    return (ifindex);
}

