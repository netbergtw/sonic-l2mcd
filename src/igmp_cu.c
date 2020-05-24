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

#include "l2mcd_mcast_co.h"
#include <stdio.h>
#include "l2mcd_mld_utils.h"
#include "l2mcd_mld_port.h"

#define CU_DFLT_PIMS_PRUNE_WAIT_TIME            3
extern MCAST_GLOBAL_CLASS    gMulticast, *pgMulticast;

void igmp_reset_default_values(MCGRP_CLASS *igmp)
{
    igmp->cfg_query_interval_time = CU_DFLT_IGMP_QUERY_INTERVAL;
    igmp->query_interval_time     = CU_DFLT_IGMP_QUERY_INTERVAL;
    igmp->max_response_time       = CU_DFLT_IGMP_RESPONSE_TIME;
    igmp->group_membership_time   = CU_DFLT_IGMP_GROUP_MEMBERSHIP_TIME;
    igmp->older_host_present_time = CU_DFLT_IGMP_OLDER_HOST_PRESENT_TIME;
    igmp->robustness_var          = IGMP_DEFAULT_ROBUSTNESS_VARIABLE;
    igmp->cfg_robustness_var      = IGMP_DFLT_ROBUSTNESS;
    igmp->max_groups              = CU_DFLT_IGMP_MAX_GROUP_ADDRESS;
    igmp->pim_prune_wait_interval = CU_DFLT_PIMS_PRUNE_WAIT_TIME;
    igmp->LMQ_interval            = 1;      /* seconds */
    igmp->LMQ_count               = igmp->robustness_var;
    igmp->router_alert_check_disable = FALSE;

    igmp_set_global_version(igmp->vrf_index, IGMP_VERSION_NONE, TRUE /* force-replicate to all ports */);
}


void igmp_enable (VRF_INDEX  vrf_index,  UINT8   protocol)
{
    MCGRP_CLASS  *igmp=NULL;
    igmp = IGMP_GET_INSTANCE_FROM_VRFINDEX(vrf_index);
    if (igmp == NULL)
    {
        igmp = mcgrp_vrf_alloc(IP_IPV4_AFI, vrf_index);
        if (igmp == NULL)
        {
            L2MCD_LOG_NOTICE("%s:%d vrf allocate fail vrf %d ", __FUNCTION__, __LINE__, vrf_index);
            return;
        }
    }

    // If IGMP needs to be initialized, do so.
    if (igmp->first_time_init == FALSE)
    {
        // If initialization fails retain the first_time flag so that we can attempt again
        if (mcgrp_initialize(IP_IPV4_AFI, igmp))
            igmp->first_time_init = TRUE;
    }
    igmp->enabled |= TRUE;

    static int group_address_offset = M_AVLL_OFFSETOF(GROUP_ENTRY, group_address.ip.v4addr);
    igmp->group_tree= L2MCD_AVL_CREATE(l2mcd_avl_compare_u32, (void *) &group_address_offset, NULL);
    L2MCD_LOG_NOTICE("%s Completed vrf:%d protocol:%d igmp:%p group_tree:%p", __FUNCTION__,vrf_index, protocol, igmp, igmp->group_tree);
    return;
}


/* ================ VERSION ==================== */
// This is called to update a VE port's configuration as well as its member ports
// whenever a VE port's configuration changes either due to a change in the global
// or the VE port's version configuration.

void igmp_update_ve_member_ports (MCGRP_CLASS *igmp,
        MCGRP_L3IF  *igmp_vport,
        UINT8        version,
        BOOL         force)
{

}


// This function is invoked to process a change in IGMP's global version
// Changing the global version affects the version of all ports that are not explicitly
// configured. So, update the oper_version of all such ports.

void igmp_set_global_version (VRF_INDEX  vrf_index, 
        UINT32     version, 
        BOOL       force)
{

} /* igmp_set_global_version() */


// This function is invoked to process a change in an interface's (VE or otherwise) version
int igmp_set_if_igmp_version (VRF_INDEX  vrf_index, 
        UINT16     vport, 
        UINT8      version)
{
 
}

