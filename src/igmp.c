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

/*--------------------------------------------------------------------------------- **
 **                                                                                    **
 ** This is Multicast initialization function, it is called when IGMP/MLD is enabled.**
 ** The function allcates memory for  its data structure and start a periodic timer  **
 ** for sending IGMP/MLD Membership query messages. If igmp/mld is not enabled then  **
 ** the function does nothing.                                                     **
 **--------------------------------------------------------------------------------*/
//v4/v6 compliant
MCGRP_CLASS  *mcgrp_vrf_alloc (UINT32 afi, VRF_INDEX  vrf_index)
{
}


//v4/v6 compliant
void mcgrp_reset_default_values (MCGRP_CLASS *mcgrp)
{
    if (IS_IGMP_CLASS(mcgrp))
    {
        igmp_reset_default_values(mcgrp);
    }
    else { ;}//MLD
}


void mcgrp_set_max_group_address(UINT32 afi, VRF_INDEX vrf_index, UINT32 val)
{
}



/* **********************************************************
 *
 * This function allocates various data objects used by IGMP
 * The contents of this function were earlier executed by
 * pim_initialize_port_entry_memory()
 * Moved it here for the sake of consistency.
 *
 */
//v4/v6 compliant 
BOOLEAN mcgrp_alloc_init (MCGRP_CLASS *mcgrp)
{
}

// v4/v6 compliant
BOOL mcgrp_initialize (UINT32 afi, MCGRP_CLASS *mcgrp)
{
}


BOOLEAN mcgrp_initialize_port_db_array(UINT32 afi)
{
}

//v4/v6 compliant
MCGRP_L3IF *mcgrp_alloc_init_l3if_entry (MCGRP_CLASS   *mcgrp,
        UINT16         vir_port_id)
{

}


//Routines to handle events from interface manager
void mcgrp_vport_state_notify (MCGRP_CLASS  *mcgrp,
        UINT16        vir_port_id,
        //UINT16        phy_port_id, 
        UINT32        phy_port_id, 
        BOOLEAN       up)
{
    mld_vport_state_notify(vir_port_id, phy_port_id, up, mcgrp);
}

//v4/v6 compliant
    void
mcgrp_start_vir_port (MCGRP_CLASS *mcgrp, MCGRP_L3IF *mcgrp_vport)
{
}

// Updates the physical port-mask for all static groups that exist on tunnel interfaces
// with the current outgoing port for that tunnel
// The outgoing port is retrieved from the corresponding mcgrp_vport struct
//v4/v6 compliant
void mcgrp_update_staticGroup_tnnl_portmask (MCGRP_CLASS  *mcgrp, 
        MCGRP_L3IF   *mcgrp_vport)
{
}

void mcgrp_update_static_groups (MCGRP_CLASS         *mcgrp,
        MCGRP_L3IF          *mcgrp_vport,
        MCGRP_STATIC_ENTRY  *mcgrp_entry,
        UINT8                mcgrp_action,
        L2MCD_AVL_TREE      *port_tree,
        UINT32               target_port)
{
}



//v4/v6 compliant
void mcgrp_activate_static_groups (MCGRP_CLASS  *mcgrp, 
        UINT16        vir_port_id, 
        //UINT16        target_port)
        UINT32        target_port)
{
}



void mcgrp_start_phy_port (MCGRP_CLASS       *mcgrp, 
        MCGRP_L3IF        *mcgrp_vport, 
        MCGRP_PORT_ENTRY  *mcgrp_pport)
{

}

// Find a MCGRP_MBRSHP in the membership list anchored in MCGRP_ENTRY
//v4/v6 compliant
MCGRP_MBRSHP* mcgrp_find_mbrshp_entry (MCGRP_ENTRY  *grp_entry, 
        //    UINT16        phy_port_id)
    UINT32        phy_port_id)
{

}

// Stopping IGMP/MLD operation on a port
// Clean up the port's membership in all groups on the interface
// Note that we clean up the port's membership in static groups too,
// since we will re-activate the membership when the port comes up
//v4/v6 compliant
void mcgrp_stop_phy_port (MCGRP_CLASS       *mcgrp, 
        MCGRP_L3IF        *mcgrp_vport, 
        MCGRP_PORT_ENTRY  *mcgrp_pport)
{
}

//v4/v6 compliant
void mcgrp_stop_vir_port (MCGRP_CLASS  *mcgrp, 
        MCGRP_L3IF   *mcgrp_vport)
{

}

//v4/v6 compliant
MCGRP_PORT_ENTRY* mcgrp_add_phy_port (MCGRP_CLASS  *mcgrp,
        MCGRP_L3IF   *mcgrp_vport,
        //UINT16        phy_port_id)
        UINT32        phy_port_id)
{

}


//v4/v6 compliant
MCGRP_PORT_ENTRY* mcgrp_find_phy_port_entry (MCGRP_CLASS  *mcgrp,
        MCGRP_L3IF   *mcgrp_vport,
        //UINT16        phy_port_id)
        UINT32        phy_port_id)
{

}

MCGRP_MBRSHP* mcgrp_find_first_mbrshp (MCGRP_ENTRY *mcgrp_grp)
{
}

MCGRP_MBRSHP* mcgrp_find_next_mbrshp (MCGRP_ENTRY   *mcgrp_grp,
        MCGRP_MBRSHP  *mcgrp_mbrshp)
{
}

// Find a MCGRP_SOURCE in the mode-specific source list anchored in MCGRP_MBRSHP
//v4/v6 compliant
MCGRP_SOURCE* mcgrp_find_source (MCGRP_MBRSHP      *mcgrp_mbrshp, 
        MADDR_ST          *src_addr, 
        MCGRP_FILTER_MODE  src_mode)
{
}


//v4/v6 compliant
MCGRP_ROUTER_ENTRY* mcgrp_find_rtr_port_entry (MCGRP_CLASS  *mcgrp,
        MCGRP_L3IF   *mcgrp_vport,
        UINT32        phy_port_id)
{
}

void mcgrp_delete_phy_port (MCGRP_CLASS       *mcgrp,
        MCGRP_L3IF        *mcgrp_vport,
        MCGRP_PORT_ENTRY  *mcgrp_pport)
{
}


// The physical port members of this virtual port may already.
// So, get the membership mask of this VE and create structures for its member ports
//v4/v6 compliant
void mcgrp_create_veport_members (MCGRP_CLASS  *mcgrp,
        MCGRP_L3IF   *mcgrp_vport)
{

}


// The virtual port just went down
// Destruct the physical port members of the virtual port
//v4/v6 compliant
void mcgrp_delete_veport_members (MCGRP_CLASS  *mcgrp,
        MCGRP_L3IF   *mcgrp_vport)
{

}


//v4/v6 compliant
void mcgrp_delete_veport (MCGRP_CLASS  *mcgrp,
        MCGRP_L3IF   *mcgrp_vport,
        UINT32       phy_port_id)
{

}

//v4/v6 compliant
void mcgrp_delete_staticGroup (MCGRP_CLASS         *mcgrp, 
        PORT_ID              port_id, 
        MCGRP_STATIC_ENTRY  *mcgrp_entry)
{
}

//v4/v6 compliant
void mcgrp_delete_static_groups_on_if (MCGRP_CLASS  *mcgrp,
        UINT16        vir_port_id, 
        //UINT16        target_port)
        UINT32        target_port)
{

}


// We have been called to delete an interface
//
// Delete all group entries on this port and then delete the port entry itself
//v4/v6 compliant
void mcgrp_delete_l3intf (MCGRP_CLASS  *mcgrp, 
        UINT16        vir_port_id)
{
    
}


//v4/v6 compliant
MCGRP_L3IF* mcgrp_create_l3intf (MCGRP_CLASS  *mcgrp,
        UINT16        vir_port_id)
{
}


//v4/v6 compliant
void mcgrp_age_clnt_timers (MCGRP_CLASS   *mcgrp,
        L2MCD_AVL_TREE   *clnt_tree,
        MCGRP_CLIENT  *mcgrp_clnt) 
{
} /* mcgrp_age_clnt_timers() */


//v4/v6 compliant
UINT32 mcgrp_age_src_timers (MCGRP_CLASS     *mcgrp, 
        MCGRP_L3IF      *mcgrp_vport,
        MCGRP_ENTRY     *mcgrp_entry,
        MCGRP_MBRSHP    *mcgrp_mbrshp,
        UINT64           curr_time)
{
} /* mcgrp_age_src_timers() */

UINT32 mcgrp_age_src_lmq_timers (MCGRP_CLASS *mcgrp, 
        MCGRP_L3IF      *mcgrp_vport,
        MCGRP_ENTRY     *mcgrp_entry,
        MCGRP_MBRSHP    *mcgrp_mbrshp,
        UINT64           curr_time)
{
} /* mcgrp_age_src_lmq_timers() */

// This function ages a port's membership in a particular group
//v4/v6 compliant
    void
mcgrp_age_group_mbrshp (MCGRP_CLASS   *mcgrp,
        MCGRP_L3IF    *mcgrp_vport, 
        MCGRP_ENTRY   *mcgrp_entry,
        MCGRP_MBRSHP  *mcgrp_mbrshp) 
{
} /* mcgrp_age_group_mbrshp() */

// This function ages a port's membership in a particular group
//v4/v6 compliant
    void
mcgrp_age_group_mbrshp_and_lmq (MCGRP_CLASS   *mcgrp,
        MCGRP_L3IF    *mcgrp_vport, 
        MCGRP_ENTRY   *mcgrp_entry,
        MCGRP_MBRSHP  *mcgrp_mbrshp) 
{


} /* mcgrp_age_group_mbrshp() */


//v4/v6 compliant
void mcgrp_age_query_timers (MCGRP_CLASS       *mcgrp,
        MCGRP_L3IF  *mcgrp_vport)

{

} /* mcgrp_age_query_timers() */

BOOLEAN pim_enabled (UINT32 afi, UINT16 port)
{

}

// Find a MCGRP_ENTRY in group list for a given port
//v4/v6 compliant
MCGRP_ENTRY* mcgrp_find_group_address_entry (MCGRP_CLASS  *mcgrp, 
        UINT16        vir_port_id,
        MADDR_ST     *group_address)
{

}

/* update the forwarding entries and add/delete the physical port;
 * virtual interface is still up and runing 
 */
//v4/v6 compliant 
void mcgrp_mcast_change_vport_membership (MCGRP_CLASS  *mcgrp, 
        MADDR_ST     *source_address,
        MADDR_ST     *group_address,
        UINT16        router_port, 
        UINT32        phy_port,
        UINT32        mcgrp_op)
{

}



UINT8 mcgrp_val2code (UINT16 val)
{

}

/* *************************************************************
 *
 *  MCGRP_ENTRY list manipulation functions
 *
 * *************************************************************/

// Allocate and enlist a new MCGRP_ENTRY in the group list for a given port
//v4/v6 compliant
MCGRP_ENTRY* mcgrp_alloc_group_entry (MCGRP_CLASS  *mcgrp,
        MCGRP_L3IF   *mcgrp_l3if, 
        MADDR_ST     *group_address) 
{
}

//v4/v6 compliant
void mcgrp_free_group_entry (MCGRP_CLASS  *mcgrp, 
        MCGRP_ENTRY  *grp_entry)
{
}

// Given a pointer to a GROUP_ENTRY, destroys all the members in the group
//v4/v6 compliant
void mcgrp_destroy_grp_mbrshp_list (MCGRP_CLASS  *mcgrp, 
        MCGRP_ENTRY  *mcgrp_entry)
{

}

// Find and delete (delink + free) a MCGRP_ENTRY from the list 
// anchored in a port's group list
void mcgrp_destroy_group_addr (MCGRP_CLASS  *mcgrp,
        MCGRP_L3IF   *vport, 
        MCGRP_ENTRY  *del_group)
{

}

/* *************************************************************
 *
 *  MCGRP_MBRSHP list manipulation functions
 *
 * *************************************************************/

// Allocate and enlist a new MCGRP_MBRSHP in the membership list anchored in MCGRP_ENTRY
//v4/v6 compliant
MCGRP_MBRSHP* mcgrp_alloc_add_mbrshp_entry (MCGRP_CLASS  *mcgrp, 
        MCGRP_ENTRY  *grp_entry, 
        MCGRP_L3IF   *mcgrp_vport, 
        UINT32        phy_port_id,
        BOOLEAN       is_static, 
        UINT8         version)
{

}



// Find a MCGRP_MBRSHP in the membership list anchored in MCGRP_ENTRY
//v4/v6 compliant
MCGRP_MBRSHP* mcgrp_find_mbrshp_entry_for_grpaddr (MCGRP_CLASS  *mcgrp, 
        MADDR_ST     *group_address, 
        UINT16        vir_port_id, 
        UINT32        phy_port_id)
{

}




//v4/v6 compliant
void mcgrp_free_mbrshp_entry (MCGRP_CLASS   *mcgrp, 
        MCGRP_MBRSHP  *mcgrp_mbrshp)
{
    if (mcgrp_mbrshp)
    {
        free(mcgrp_mbrshp);
    }
}

/* Clear commands */
void mcgrp_pims_destroy_src_list(MCGRP_CLASS *mcgrp,
        MCGRP_MBRSHP *mcgrp_mbrshp)
{

}

// Given a MCGRP_MBRSHP entry, deletes all sources (both INCL and EXCL lists)
// hanging off of it
//v4/v6 compliant
void mcgrp_destroy_source_list (MCGRP_CLASS   *mcgrp, 
        MCGRP_MBRSHP  *mcgrp_mbrshp)
{

}

// Find and delete (delink + free) an MCGRP_MGRSHP_ENTRY from the membership list
// anchored in a MCGRP_ENTRY
//v4/v6 compliant
void mcgrp_destroy_mbrshp_entry (MCGRP_CLASS  *mcgrp, 
        MCGRP_ENTRY  *grp_entry, 
        MCGRP_MBRSHP *mcgrp_mbrshp)
{

}


BOOL mcgrp_src_list_empty ( MCGRP_MBRSHP      *mcgrp_mbrsh,
        MCGRP_FILTER_MODE  src_mode,
        UINT8 version)
{

}


// Find and delink an MCGRP_SOURCE from the mode-specific source list
// anchored in a MCGRP_MBRSHP
//v4/v6 compliant
MCGRP_SOURCE* mcgrp_delist_source (MCGRP_MBRSHP      *mcgrp_mbrshp, 
        MADDR_ST          *src_addr, 
        MCGRP_FILTER_MODE  src_mode)
{

}


//v4/v6 compliant
void mcgrp_handle_intf_ver_change (MCGRP_CLASS  *mcgrp, 
        MCGRP_L3IF   *mcgrp_vport)
{

}


//Common routine to send in a query at startup
//v4/v6 compliant
void mcgrp_start_query_process (MCGRP_CLASS       *mcgrp, 
        MCGRP_PORT_ENTRY  *mcgrp_pport, 
        UINT16             vir_port_id,
        UINT32             phy_port_id)
{

}

// This function is called periodically to refresh the static group memberships
//v4/v6 compliant
void mcgrp_refresh_static_group (MCGRP_CLASS         *mcgrp, 
        MCGRP_STATIC_ENTRY  *mcgrp_entry)
{

}
//v4/v6 compliant
BOOLEAN mcgrp_send_group_source_query (MCGRP_CLASS        *mcgrp, 
        MCGRP_MBRSHP       *mcgrp_mbrshp,
        UINT16              vir_port_id,
        UINT32              phy_port_id,
        MADDR_ST           *group_address,
        SORTED_LINKLIST   **p_src_list,
        BOOLEAN             was_excl,
        MADDR_ST           *clnt_ip_addr,
        enum BOOLEAN        is_retx)
{

}

// This function is invoked to signal change in state of an IP interface
//v4/v6 compliant
void mcgrp_port_state_notify (UINT32        afi, 
        VRF_INDEX     vrf_index, 
        UINT16        port_id, 
        enum BOOLEAN  up)
{

}


//v4 only
int igmpv3_src_compare (void *keya, 
        void *keyb)
{
    UINT32 src_addr_a = ((MADDR_ST*) keya)->ip.v4addr;
    UINT32 src_addr_b = ((MADDR_ST*) keyb)->ip.v4addr;
    return (int) (src_addr_a - src_addr_b);
}


//v4 only
void igmpv3_src_assign (void *keya, 
        void *keyb)
{

}


//v4 only
MCGRP_CLASS *g_igmp_destroy;

void igmpv3_src_destroy (generic_pool_struct  *pool, 
        void                 *item)
{

}


//v4 only
SORTED_LINKLIST_KEYINFO igmpv3_src_keyinfo =
{
    4, /* Key size - size of IPv4 address */
    igmpv3_src_compare,
    igmpv3_src_assign,
    igmpv3_src_destroy, 
    NULL,
    NULL
};


// Find and delete (delink + free) an MCGRP_CLIENT from the list of sources
// anchored in a MCGRP_MBRSHP
//v4 only
void igmpv3_destroy_client (MCGRP_CLASS   *mcgrp,
        L2MCD_AVL_TREE   *clnt_tree, 
        UINT32         clnt_addr)
{

}

int mcgrp_port_id_cmp_cb (void *keya,
        void *keyb)
{
    return (*(UINT32 *)keya - *(UINT32 *) keyb);
}


//v4 only
void igmpv3_sorted_linklist_minus (MCGRP_CLASS              *igmp,
        generic_pool_struct      *pool,
        SORTED_LINKLIST_KEYINFO  *key_info,
        SORTED_LINKLIST         **dest_p, 
        SORTED_LINKLIST          *src)
{
    g_igmp_destroy = igmp;
    sorted_linklist_minus(pool, key_info, dest_p, src);
}


//v4 only
void igmpv3_sorted_linklist_keep_common (MCGRP_CLASS              *igmp,
        generic_pool_struct      *pool,
        SORTED_LINKLIST_KEYINFO  *key_info,
        SORTED_LINKLIST         **dest_p, 
        SORTED_LINKLIST          *src)
{
    g_igmp_destroy = igmp;
    sorted_linklist_keep_common(pool, key_info, dest_p, src);
}


//v4 only
void igmpv3_sorted_linklist_free_list (MCGRP_CLASS              *igmp,
        generic_pool_struct      *pool,
        SORTED_LINKLIST_KEYINFO  *key_info,
        SORTED_LINKLIST          *src)
{
    g_igmp_destroy = igmp;
    sorted_linklist_free_list(pool, key_info, src);
}


//v4 only
int igmpv3_encode_src_list (IGMPV3_MESSAGE  *igmpv3_msg, 
        MCGRP_SOURCE    *p_src,
        BOOLEAN          all_srcs,
        BOOLEAN          is_retx)
{

}

void mcgrp_process_wte_event (void *wte_param)
{

}

enum BOOLEAN
is_physical_or_lag_port(int port)
{
	return TRUE;
}

