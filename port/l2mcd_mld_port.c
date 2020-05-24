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


uint32_t pim_get_ifindex_from_port(int port)
{
    return (IP_IP_PORT(port).config.ifindex);

}

/* MLDS Set Query Interval */		
int 
mld_query_interval_set(uint32_t afi, uint32_t vid, uint32_t query_interval , uint8_t type)
{

}

/*MLD Snooping Query Max Response Time Set*/
int
mld_query_max_response_time_set(uint32_t afi, uint32_t vid, uint32_t qmrt, uint8_t type)
{

}

/*Last Member Query Interval value set*/
int
mld_lmqi_set(uint32_t afi, uint32_t vid, uint32_t lmqi, uint8_t type)
{
 
}

int mld_if_set_version_api(int vrf_index, uint32_t vid, int version, int afi,uint8_t type)
{

}

int
mld_snooping_mrouter_if_set_api(int vid, int iftype, char *ifname,
				int enable, uint8_t afi, uint8_t type)
{

}

/*MLD Static Group set function*/
int 
mld_static_group_source_set(uint32_t vid, char *ifname, int iftype,
			    mcast_grp_addr_t * gaddr, enum BOOLEAN insert_flag, BOOLEAN is_ve, uint8_t type)
{

}

/*MLD Static Group unset function*/
    int 
mld_static_group_source_unset(uint32_t vid, char *ifname, int iftype,
        mcast_grp_addr_t * gaddr,
        enum BOOLEAN insert_flag, BOOLEAN is_ve, uint8_t type) 
{
 
}

/*Unset MLD Snooping on an interface*/
int
mld_if_snoop_unset(uint32_t afi, uint32_t vid, int user_cfg, uint8_t type)
{

}

/*Set MLD Snooping on an interface*/
int
mld_if_snoop_set(uint32_t afi, uint16_t vid, int user_cfg, uint8_t type)
{

}

/* Wrapper function to handle add/delete port from VLAN event */
int
mld_map_port_vlan_state(uint32_t vlan_id, uint32_t ifindex, int add_port,
									uint32_t ip_family, uint8_t type, int lif_type, int lif_state)
{

}

/*Unset MLD Snooping Querier*/
int
mld_snoop_querier_unset(uint32_t afi, uint16_t vid, uint8_t type)
{

}

/*Set fastleave*/
int
mld_fastleave_set(uint32_t afi, uint32_t vid, uint8_t type)
{
 
}

/*Unset fastleave*/
int
mld_fastleave_unset(uint32_t afi, uint32_t vid, uint8_t type)
{

}

/*Set MLD Snooping Querier*/
int
mld_snoop_querier_set(uint32_t afi, uint16_t vid, uint8_t type)
{
 
}

char * mld_get_if_name_from_port(uint16_t port_id)
{
	return (portdb_get_ifname_from_portindex(port_id));
}

/*This Function returns mcgrp_vport(MCGRP_L3IF) corresponding to a vlan*/
MCGRP_L3IF * mld_get_l3if_from_vlanid(UINT32 afi, UINT32 vid, uint8_t type)
{

}

void mcast_set_address(mcast_grp_addr_t * gaddr, MADDR_ST * grp_addr)
{

}

mld_l3_if_type_t mld_get_l3if_type(ifindex_t ifIndex)
{

}

void mcgrp_vport_stop_querier_process(MCGRP_CLASS * mcgrp, MCGRP_L3IF * mcgrp_vport, bool_t from_snooping)
{

}

int mld_iterate_vlan_group_clear(mld_vid_t ivid, MADDR_ST * grp_addr_clr,
			     int clr_grp_flag, uint8_t vlan_type)
{

}

void mld_del_vlan_from_protocol(int vrfid, MCGRP_GLOBAL_CLASS * mcgrp_glb,
			   mld_vlan_node_t * vlan_node, int afi)
{

}

void mld_add_vlan_to_protocol(int vrfid, MCGRP_GLOBAL_CLASS * mcgrp_glb,
			 mld_vlan_node_t * vlan_node, mld_if_type_t mode,
			 uint8_t afi)
{

}

void mcgrp_vport_start_querier_process(MCGRP_CLASS * mcgrp, MCGRP_L3IF * mcgrp_vport)
{

}

int mld_pims_if_snoop_unset(uint32_t afi, uint16_t vid, BOOLEAN user_cfg, uint8_t type)
{

}
/*
 * This function returns true if the source is present in 
   include/exclude or pim snooping source list.
 */
BOOLEAN mld_snp_is_source_present_on_mbr_port(MCGRP_MBRSHP *grp_mbrshp,
						uint32_t src_addr, uint8_t afi)
{

}

BOOLEAN mld_is_snoop_mbrship_present(MCGRP_MBRSHP *mcgrp_mbrshp, 
				uint8_t *v1_mbr, uint8_t *v2_mbr, uint8_t *v3_mbr)
{

}

/*
 * This function searches for a given source on a give member port
 * (*include_flag) will be set if source found in INCLUDE list
 * (*exclude_flag) will be set if source found in ExCLUDE list
 */
BOOLEAN mld_snp_is_igmpv3_source_present_on_mbr_port(MCGRP_MBRSHP *grp_mbrshp,
						uint32_t src_addr, uint8_t afi, 
						uint8_t *include_flag, uint8_t *exclude_flag)
{

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

void mld_map_vlan_state(uint32_t ip_family, uint32_t gvid, int add,
						uint32_t flags, uint16_t ivid, char *vlan_name,uint8_t type)
{

}

/* Wrapper function to handle port add/del event */
int
mld_map_port_add_del(int vrfid, ifindex_t ifindex, int add, char *name, uint8_t type)
{

}

time_t mld_get_current_monotime(void)
{
}

int mld_proto_lmqi_set(uint32_t afi, uint32_t vid, uint32_t lmqi, uint8_t type)
{

}

int mld_proto_snooping_mrouter_if_set_api(mld_vlan_node_t * vlan_node,
				      int vrf_id, uint32_t port,
				      int enable, int afi)
{
}

void mcast_set_ip_addr(MADDR_ST * grp_addr, mcast_grp_addr_t * gaddr)
{

}

// This funcion is invoked when there is a configuration change with
// regards to a port's membership in a multicast group.
// v4/v6 compliant
void
mcgrp_notify_l2_staticGroup_change(UINT32 afi,
                                      VRF_INDEX      vrf_index,
				   MADDR_ST * group_addr,
                                      PORT_ID        vir_port_id,
                                      //PORT_ID        phy_port_id,
                                      UINT32         phy_port_id,
                                      enum BOOLEAN   insert_flag)
{
 
}
 
void mld_protocol_port_state_notify(mld_vlan_node_t * vlan_node, UINT32 afi,
			       MCGRP_CLASS * mld, UINT32 port,
			       enum BOOLEAN state_up)
{

}

void mld_static_grp_deconfig_port(mld_vlan_node_t * vlan_node, uint32_t ifindex,
			     UINT32 port, uint8_t afi)
{
	return;
}

int mld_vlan_clear_group(uint32_t ifindex, MADDR_ST * grp_addr_clr,
		     int clr_grp_flag, uint8_t vlan_type)
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

void mcgrp_delete_l2_staticGroup_if(MCGRP_CLASS * mcgrp, MCGRP_L3IF * mcgrp_vport)
{

}

int mld_map_set_if_mld_mode(int ip_family, ifindex_t ifindex, int enable,
														VRF_INDEX vrf_index ,uint8_t type)
{

}

/*
 * Retrive IP address from ve_portdb_tree
 */
uint32_t
ve_mld_portdb_get_port_lowest_ipv4_addr_from_list(uint32_t port_num)
{

}

uint32_t mld_portdb_get_port_lowest_ipv4_addr_from_list(uint32_t port_num)
{

}

/* clears total cache/ vlan specific/ grp specific cache */
int pims_clear_snoop_cache(int afi, mld_vid_t vlan_id, MADDR_ST *grp_addr_clr,uint8_t type)
{
}

void pims_clear_statistics(int afi, mld_vid_t vlan_id, uint8_t type)
{

}

void mcgrp_delete_router_port(MCGRP_CLASS * mcgrp,
			 MCGRP_L3IF * mcgrp_vport, UINT32 phy_port_id)
{
 
}

MCGRP_ROUTER_ENTRY *
mcgrp_add_router_port(MCGRP_CLASS * mcgrp,
		      MCGRP_L3IF * mcgrp_vport,
              UINT32        phy_port_id,
		      BOOLEAN is_static, UINT16 type, UINT16 time, BOOLEAN is_mclag_remote)
{

}

//v4/v6 compliant
MCGRP_STATIC_ENTRY * mcgrp_add_l2_staticGroup(MCGRP_CLASS * mcgrp,
			 PORT_ID port_id, MADDR_ST * group_addr)
{

}

int mld_sg_porttree_addport(L2MCD_AVL_TREE *port_tree, uint32_t port)
{

}

void mcgrp_update_l2_static_group(MCGRP_CLASS * mcgrp, MCGRP_L3IF * mcgrp_vport,
			     MCGRP_STATIC_ENTRY * mcgrp_entry, UINT8 mcgrp_action, UINT32 target_port)
{

}

//v4/v6 compliant
MCGRP_STATIC_ENTRY * mcgrp_find_l2_staticGroup(MCGRP_CLASS * mcgrp,
			  PORT_ID port_id, MADDR_ST * group_addr)
{
    return NULL;
}

int mld_sg_port_cmp_cb (void *keya,void *keyb)
{
	return (*(UINT32 *)keya - *(UINT32 *) keyb);
}
void mld_static_grp_replay_confg(mld_vlan_node_t * vlan_node, int afi,
			    MCGRP_CLASS * mld, uint32_t phy_port)
{

}

int _mld_clear_group(MCGRP_CLASS * mcgrp, MCGRP_L3IF * mcgrp_vport,
		 MADDR_ST * grp_addr_clr, int clr_grp_flag)
{

}

// This function is called periodically to refresh the static group memberships
// //v4/v6 compliant
void mcgrp_refresh_l2_static_group(MCGRP_CLASS * mcgrp,
			      MCGRP_STATIC_ENTRY * mcgrp_entry)
{

}

void mld_sg_delete_porttree(L2MCD_AVL_TREE *port_tree)
{

}

/* Wrapper function to handle setting interface PIM mode CLI event */
void mld_cu_set_if_mld_mode(int ip_family, UINT16 port, int enable,
							VRF_INDEX vrf_index, ifindex_t ifindex, uint8_t type)
{

}

int mld_port_exist_in_port_db(uint16_t port_num)
{

}


void mcgrp_reset_mld_stats(MCGRP_CLASS * mld, ifindex_t ifindex,uint8_t vlan_type)
{

}

void mld_del_vlan(int vrfid, mld_vlan_node_t * vlan_node)
{
	mld_vdb_vlan_del(mld_vlan_get_db(), vlan_node->gvid,vlan_node->type);
}

/* Can Clear all groups of a vlan or a single group as well */
int pims_clear_group(int afi, mld_vid_t vlan_id,
					MADDR_ST *grp_addr_clr, int grp_filter, uint8_t type )
{

}					

//v4/v6 compliant
MCGRP_ROUTER_ENTRY * mcgrp_find_router_port_entry(MCGRP_L3IF * mcgrp_vport, UINT32 phy_port_id)
{
}

int mld_sg_porttree_delport(L2MCD_AVL_TREE *port_tree, uint32_t port)
{

}

//v4/v6 compliant
void mcgrp_delete_l2_staticGroup(MCGRP_CLASS * mcgrp,
			    PORT_ID port_id, MCGRP_STATIC_ENTRY * mcgrp_entry)
{

}

void mcgrp_start_igmp_querier(MCGRP_CLASS * mcgrp,
		                      MCGRP_L3IF * mcgrp_vport, uint8_t afi, BOOLEAN flag)
{
}

void mld_snoop_clear_on_version_change(uint32_t vid, int afi, uint8_t type)
{
}

int mld_proto_query_interval_set(uint32_t afi, uint32_t vid, mld_vid_t gvid,
			     uint32_t query_interval, uint8_t type)
{

}

int mld_proto_query_max_response_time_set(uint32_t afi, uint32_t vid, uint32_t qmrt, uint8_t type)
{

}

int mld_proto_fastleave_set(uint32_t afi, uint32_t vid, uint8_t type)
{

}

int mld_proto_snoop_querier_set(uint32_t afi, uint16_t vid, uint8_t type)
{

}

void mcgrp_start_stop_snooping_querier_api(MCGRP_CLASS * mcgrp,
				      MCGRP_L3IF * mcgrp_vport, uint8_t afi, BOOLEAN flag)
{

}

void mld_replay_config(mld_vlan_node_t * vlan_node, int afi, MCGRP_CLASS * mld)
{


}

int mld_proto_strtup_query_count_set(uint32_t afi, uint16_t vid,
				 uint32_t startup_qc, uint8_t type)
{

}

int mld_proto_startup_query_interval_set(uint32_t afi, uint16_t vid,
				     uint32_t startup_qi, uint8_t type)
{

}

int mld_proto_robustness_var_set(uint32_t afi, uint32_t vid, uint32_t rv, uint8_t type)
{

}

int mld_proto_lmqc_set(uint32_t afi, uint32_t vid, uint32_t lmqc, uint8_t type)
{

}

enum BOOLEAN mld_is_member2(PORT_MASK *mask, int port)
{
}

void mld_clear_mask(PORT_MASK *mask)
{
}

enum BOOLEAN mld_is_member_tree(L2MCD_AVL_TREE *port_tree, uint32_t port)
{
	if(M_AVLL_FIND(*port_tree, &port))	
		return TRUE;
	return FALSE; 
}

void mcgrp_delete_all_router_ports(MCGRP_CLASS * mcgrp, MCGRP_L3IF * mcgrp_vport)
{
}

//v4/v6 compliant
void mcgrp_activate_l2_static_groups(MCGRP_CLASS * mcgrp,
				//UINT16 vir_port_id, UINT16 target_port)
				UINT16 vir_port_id, UINT32 target_port)
{

}

BOOLEAN mld_l2_staticGroup_exists_on_port(mcast_grp_addr_t * group_addr,
				  PORT_ID port_id, UINT32 phy_port)
{

}

BOOLEAN mcast_validate_igmp_packet(IGMP_MESSAGE * sptr_igmp_message,
			   UINT16 igmp_pkt_size, BOOLEAN dbg_enabled)
{

}


void mld_process_pimv2_query(MCGRP_CLASS * mld, MADDR_ST * src,
			PIM_V2_HDR * pim_v2_hdr,
			MCGRP_L3IF * mcgrp_vport, MCGRP_PORT_ENTRY * mcgrp_port)
{
 
}

void igmp_process_pimv2_packet(char *sptr_ip6_hdr,  UINT16 vir_port_id, UINT32 phy_port_id)
{

}
