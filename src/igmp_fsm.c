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

#include "l2mcd_mld_utils.h"
#include "l2mcd_mld_port.h"
#include "mld_vlan_db.h"
#include "l2mcd_portdb.h"

const static char mcgrp_action_label[][8] =
{
    "NONE",
    "IS_INCL",
    "IS_EXCL",
    "TO_INCL",
    "TO_EXCL",
    "ALW_NEW",
    "BLK_OLD"
};

/* =============================================================================================== */
/* =============================================================================================== */
/* =============================================================================================== */
extern MCAST_GLOBAL_CLASS    gMulticast, *pgMulticast;
extern int mld_grp_exists_on_local_vlan(mld_vid_t vid, mcast_grp_addr_t *ip_addr);
extern BOOLEAN mld_is_snoop_mbrship_present(MCGRP_MBRSHP *mcgrp_mbrshp, 
        uint8_t *v1_mbr, uint8_t *v2_mbr, uint8_t *v3_mbr);

void mcgrp_notify_vif_add (MCGRP_CLASS   *mcgrp,
        MADDR_ST      *group_address,
        MCGRP_L3IF    *mcgrp_vport,
        MCGRP_MBRSHP  *mcgrp_mbrshp,
        MCGRP_ENTRY   *mcgrp_entry,
        BOOL           sigchange)
{

}


void mcgrp_notify_vif_del(MCGRP_CLASS  *mcgrp, 
        MADDR_ST     *group_address,
        MCGRP_L3IF   *mcgrp_vport,
        MCGRP_ENTRY   *mcgrp_entry,
        BOOL          sigchange)
{

}


void mcgrp_notify_phy_port_del (MCGRP_CLASS  *mcgrp, 
        MADDR_ST     *group_address,
        MCGRP_L3IF   *mcgrp_vport,
        //    PORT_ID       phy_port_id,
        UINT32        phy_port_id,
        BOOL          sigchange)
{

}



// Add ALLOWED source-list
void mcgrp_notify_source_list_add_allowed (MCGRP_CLASS   *mcgrp,
        MADDR_ST      *group_address,
        MCGRP_L3IF    *mcgrp_vport,
        MCGRP_MBRSHP  *mcgrp_mbrshp,
        MCGRP_SOURCE  *src_list,
        BOOL           sigchange)
{

}

// Add BLOCKED source-list
void mcgrp_notify_source_list_add_blocked (MCGRP_CLASS   *mcgrp, 
        MADDR_ST      *group_address,
        MCGRP_L3IF    *mcgrp_vport,
        MCGRP_MBRSHP  *mcgrp_mbrshp,
        MCGRP_SOURCE  *src_list,
        BOOL           sigchange)
{

}


// Delete ALLOWED source-list
void mcgrp_notify_source_list_del_allowed (MCGRP_CLASS   *mcgrp, 
        MADDR_ST      *group_address,
        MCGRP_L3IF    *mcgrp_vport,
        MCGRP_MBRSHP  *mcgrp_mbrshp,
        MCGRP_SOURCE  *src_list,
        BOOL           sigchange)
{

}

// Delete BLOCKED source-list
void mcgrp_notify_source_list_del_blocked (MCGRP_CLASS   *mcgrp,
        MADDR_ST      *group_address,
        MCGRP_L3IF    *mcgrp_vport,
        MCGRP_MBRSHP  *mcgrp_mbrshp,
        MCGRP_SOURCE  *src_list,
        BOOL            sigchange)
{


}


// Delete ALLOWED source
void mcgrp_notify_source_del_allowed (MCGRP_CLASS   *mcgrp, 
        MADDR_ST      *group_address,
        MCGRP_L3IF    *mcgrp_vport,
        MCGRP_MBRSHP  *mcgrp_mbrshp,
        MADDR_ST      *source_addr,
        BOOL           sigchange)
{

}

void mcgrp_notify_source_add_blocked (MCGRP_CLASS   *mcgrp, 
        MADDR_ST      *group_address,
        MCGRP_L3IF    *mcgrp_vport,
        MCGRP_MBRSHP  *mcgrp_mbrshp,
        MADDR_ST      *src_addr,
        BOOL           sigchange)
{

}

void mcgrp_transition_to_INCL (MCGRP_CLASS   *mcgrp, 
        MCGRP_L3IF    *mcgrp_vport, 
        MCGRP_MBRSHP  *mcgrp_mbrshp,
        MCGRP_ENTRY   *mcgrp_entry)
{
 
}

typedef struct s_UPDATE_SRC_PARAM
{
    UINT16  time;
    UINT16  retx_cnt;
    MADDR_ST  clnt_ip_addr;
    MCGRP_CLASS *mcgrp;
} UPDATE_SRC_PARAM;

// Update a source's client list with the supplied client address
UINT32 mcgrp_update_src_with_client (void    *node, 
        unsigned long   para)
{

}

static UINT32 mcgrp_mark_srcs_for_query_callback (void *node, ULONG param)
{

}

void mcgrp_mark_srcs_for_query (MCGRP_CLASS     *mcgrp,
        MCGRP_MBRSHP    *mcgrp_mbrshp, 
        SORTED_LINKLIST *reference_list,
        MADDR_ST        *clnt_ip_addr)
{

}

static UINT32 mcgrp_update_age_for_srcs_callback (void* node, unsigned long param)
{

}


void mcgrp_update_age_for_srcs (MCGRP_CLASS     *mcgrp, 
        MCGRP_MBRSHP    *mcgrp_mbrshp,
        SORTED_LINKLIST *reference_list,
        MADDR_ST        *clnt_ip_addr, 
        UINT16           time, 
        UINT8            retx_cnt)
{


}

static UINT32 mcgrp_update_uptime_for_srcs_callback (void* node, ULONG param)
{

}

void mcgrp_update_uptime_for_srcs (MCGRP_CLASS     *mcgrp, 
        MCGRP_MBRSHP    *mcgrp_mbrshp,
        SORTED_LINKLIST *reference_list,
        MADDR_ST        *clnt_ip_addr, 
        UINT16           time, 
        UINT8            retx_cnt)
{
 

}

MCGRP_MBRSHP*mcgrp_update_group_address_table (MCGRP_CLASS  *mcgrp,
        UINT16        vir_port_id, 
        UINT32        phy_port_id, 
        MADDR_ST     *group_address, 
        MADDR_ST     *clnt_src_ip, 
        UINT8         action,
        UINT8         version,
        UINT16        num_srcs,
        void         *src_array)
{


}

/* *************************************************************
 *
 *  MCGRP_CLIENT list manipulation functions
 *
 * *************************************************************/

// Allocate and enlist a new MCGRP_CLIENT in the membership list anchored in IGMP_GROUP_ENTRY
MCGRP_CLIENT* mcgrp_alloc_client (MCGRP_CLASS  *mcgrp, 
        L2MCD_AVL_TREE  *clnt_tree, 
        MADDR_ST     *clnt_addr)
{
    return NULL;
}


// If the specified client exists, reset its age
// If not found, create an entry and enlist it in the tracking list
void mcgrp_add_update_client (MCGRP_CLASS  *mcgrp, 
        L2MCD_AVL_TREE  *clnt_tree,
        MADDR_ST     *clnt_addr)
{

}

void mcgrp_update_age_for_clnts (MCGRP_CLASS  *mcgrp,
        L2MCD_AVL_TREE  *clnt_tree, 
        MADDR_ST     *clnt_ip_addr,
        UINT16        time)
{
}


// Given an MCGRP_MBRSHP entry, deletes all tracking clients hanging off of it
void mcgrp_destroy_tracking_list (MCGRP_CLASS  *mcgrp,
        L2MCD_AVL_TREE  *clnt_tree)
{

}


