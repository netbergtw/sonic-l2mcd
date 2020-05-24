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

#include "l2mcd_portdb.h"
#include "l2mcd_mld_utils.h"
#include "mld_vlan_db.h"
#include "l2mcd_dbsync.h"

extern L2MCD_AVL_TREE *mld_portdb_tree;
extern MCGRP_CLASS      mld;
extern MCGRP_CLASS      Mld0, *pMld0;
extern MCGRP_GLOBAL_CLASS   gMld, *pgMld;


/* This function is called when a physical port w/in a logical port (VE interface) changes state (UP/DN)
 * If UP, we allocate and initialize the necessary data structures
 * If DN, we drop the port's memberships in the various groups active on the system.
 */
void mld_vport_state_notify (UINT16   vir_port_id, 
        UINT32   phy_port_id, 
        BOOLEAN  up,
        MCGRP_CLASS *mld)
{
 
} /* mld_vport_state_notify */


int mldv2_src_compare (void *keya, 
        void *keyb)
{
    IPV6_ADDRESS *src_addr_a = (IPV6_ADDRESS *)(keya);
    IPV6_ADDRESS *src_addr_b = (IPV6_ADDRESS *)(keyb);

    if (IP6_ARE_ADDRESSES_SAME(src_addr_a->address, src_addr_b->address))
    {
        return 0;
    }

    return (IP6_IS_ADDRESS_LESS(src_addr_a->address, src_addr_b->address) ? -1 : 1);
}


void mldv2_src_assign (void *keya, void *keyb)
{
    MCGRP_SOURCE* to_src = (MCGRP_SOURCE*)((unsigned long)keya - 4); 
    mcast_set_ipv6_addr(&to_src->src_addr,(IPV6_ADDRESS *) keyb);
    to_src->src_timer = 0;
    to_src->retx_cnt  = 0;
    to_src->include_in_query = FALSE;
    static int to_src_clnt_addr_offset=M_AVLL_OFFSETOF(MCGRP_CLIENT, clnt_addr);
    to_src->clnt_tree= L2MCD_AVL_CREATE(mcgrp_addr_cmp_cb_param, (void *) &to_src_clnt_addr_offset, NULL);
    return;
}


MCGRP_CLASS *g_mld_destroy;

void mldv2_src_destroy(generic_pool_struct  *pool, void  *item)
{
    MCGRP_CLASS *mld = g_mld_destroy;

    if (item== NULL)
        return;

    mcgrp_free_source(mld, (MCGRP_SOURCE*) item);
}

SORTED_LINKLIST_KEYINFO mldv2_src_keyinfo =
{
    sizeof(IPV6_ADDRESS), /* Key size - size of IPv6 address */
    mldv2_src_compare,
    mldv2_src_assign,
    mldv2_src_destroy,  
    NULL,
    NULL
};


void dump_mcgrp_class (uint32_t afi)
{
     return;   
}

void mldv2_sorted_linklist_minus (MCGRP_CLASS              *mld,
        generic_pool_struct      *pool,
        SORTED_LINKLIST_KEYINFO  *key_info,
        SORTED_LINKLIST         **dest_p, 
        SORTED_LINKLIST          *src)
{
    g_mld_destroy = mld;
    sorted_linklist_minus(pool, key_info, dest_p, src);
}


void mldv2_sorted_linklist_keep_common (MCGRP_CLASS              *mld,
        generic_pool_struct      *pool,
        SORTED_LINKLIST_KEYINFO  *key_info,
        SORTED_LINKLIST         **dest_p, 
        SORTED_LINKLIST          *src)
{
    g_mld_destroy = mld;
    sorted_linklist_keep_common(pool, key_info, dest_p, src);
}


void mldv2_sorted_linklist_free_list (MCGRP_CLASS              *mld,
        generic_pool_struct      *pool,
        SORTED_LINKLIST_KEYINFO  *key_info,
        SORTED_LINKLIST          *src)
{
    g_mld_destroy = mld;
    sorted_linklist_free_list(pool, key_info, src);
}

