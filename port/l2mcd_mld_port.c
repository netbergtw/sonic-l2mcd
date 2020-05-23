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

#include "l2mcd_mld_port.h"
#include "l2mcd_portdb.h"
#include "l2mcd_dbsync.h"
#include <time.h>

L2MCD_AVL_TREE *mld_portdb_tree = &gMld.portdb_tree;
L2MCD_AVL_TREE *ve_mld_portdb_tree = &gMld.ve_portdb_tree;
L2MCD_AVL_TREE *l3_portdb_tree = &gMld.portdb_tree;
extern bool_t received_clear_grp_notify;
extern struct list *snooping_enabled_vlans[MCAST_AFI_MAX];

extern void mcgrp_pims_destroy_src_list(MCGRP_CLASS *mcgrp,
        MCGRP_MBRSHP *mcgrp_mbrshp);

char * mld_get_if_name_from_port(uint16_t port_id)
{
	return (portdb_get_ifname_from_portindex(port_id));
}

uint32_t pim_get_ifindex_from_port(int port)
{
    return (IP_IP_PORT(port).config.ifindex);

}

char *
mld_ntop(mcast_grp_addr_t * addr, char *str)
{
	MLD_LOG(MLD_LOGLEVEL9, addr->afi,"%s %d %d %d", __FUNCTION__, addr->afi, AF_INET, AF_INET6);
	if (MCAST_IPV4_AFI == addr->afi) {
        int tmp_addr = 0;
		tmp_addr = htonl(addr->ip.ipv4_addr);
		inet_ntop(AF_INET, ((struct in_addr *) &tmp_addr),
			  (char *) str, INET_ADDRSTRLEN);
		str[INET_ADDRSTRLEN] = '\0';
	} else if (MCAST_IPV6_AFI == addr->afi) {
		inet_ntop(AF_INET6, (struct in6_addr *) &addr->ip.ipv6_addr,
			  (char *) str, INET6_ADDRSTRLEN);
	}
	return str;
}
mld_vlan_node_t *mld_vlan_node_get(uint32_t vid)
{
	mld_vlan_node_t *vlan_node = NULL;
	vlan_node = mld_vdb_vlan_get(vid, MLD_VLAN);
	if (!vlan_node) 
	{
		return NULL;

    }
	return vlan_node;
}

void mld_protocol_port_state_notify(mld_vlan_node_t * vlan_node, UINT32 afi,
			       MCGRP_CLASS * mld, UINT32 port,
			       enum BOOLEAN state_up)
{
}
void mld_intialize_with_def_values(mld_cfg_param_t * param)
{
    param->cfg_query_interval_time = CU_DFLT_IGMP_QUERY_INTERVAL;
    param->max_response_time       = CU_DFLT_IGMP_RESPONSE_TIME;
    param->group_membership_time   = CU_DFLT_IGMP_GROUP_MEMBERSHIP_TIME;
    param->older_host_present_time = CU_DFLT_IGMP_OLDER_HOST_PRESENT_TIME;
    param->cfg_robustness_var      = IGMP_DFLT_ROBUSTNESS;
    param->LMQ_interval            = CU_DFLT_LLQI_IN_MSEC;      /* milli seconds */
    param->LMQ_count               = param->cfg_robustness_var;
	param->start_up_query_interval = ((param->cfg_query_interval_time)/4); //param->LMQ_interval; 
    param->start_up_query_count    = param->cfg_robustness_var;
}
